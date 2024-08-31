#include "appw.h"
#include "raylib.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

void py__add_module_box2d();
void py__add_module_raylib();
void py__add_module__ct();

// lifecycle functions
PK_EXPORT void ios_ready();
PK_EXPORT void ios_update();
PK_EXPORT void ios_destroy();

// cached objects
#define cl_game() py_r0()

static struct{
    py_Name on_ready;
    py_Name on_update;
    py_Name on_destroy;
    py_Name _hot_reload_requested;
} cached;

static void cl_print(const char* s){
    platform_log_info("%s", s);
}

static char* cl_importfile(const char* path){
    int size;
    char* data = (char*)platform_load_asset(path, &size);
    assert(!data || (strlen(data) == size));
    return data;
}

void ios_ready(){
    platform_init();
    py_initialize();

    py_callbacks()->print = cl_print;
    py_callbacks()->importfile = cl_importfile;

    SetLoadFileDataCallback(platform_load_asset);
    SetLoadFileTextCallback(cl_importfile);

    // py__add_module_box2d();
    py__add_module_raylib();
    py__add_module__ct();

    char* entry_file_string = cl_importfile("main.py");
    if(!entry_file_string) {
        platform_log_error("%s\n", "Error: failed to load main.py");
        exit(1);
    }

    bool ok = py_exec(entry_file_string, "main.py", EXEC_MODE, NULL);
    free(entry_file_string);
    if(!ok){
        char* msg = py_formatexc();
        platform_log_error("%s\n", msg);
        free(msg);
        exit(1);
    }

    // Find a class derived from cl.Game
    py_ItemRef MyGame = py_getglobal(py_name("MyGame"));
    if(!MyGame) {
        platform_log_error("%s\n", "Error: failed to find `MyGame` class");
        exit(1);
    }

    // Create an instance of `MyGame`
    if(!py_call(MyGame, 0, NULL)){
        char* msg = py_formatexc();
        platform_log_error("%s\n%s\n", msg, "Error: failed to create `MyGame` instance");
        exit(1);
    }
    py_assign(cl_game(), py_retval());

    // Setup cached objects
    cached.on_ready = py_name("on_ready");
    cached.on_update = py_name("on_update");
    cached.on_destroy = py_name("on_destroy");
    cached._hot_reload_requested = py_name("_hot_reload_requested");

    // Call `on_ready` method
    py_push(cl_game());
    ok = py_pushmethod(cached.on_ready);
    assert(ok);
    if(!py_vectorcall(0, 0)){
        char* msg = py_formatexc();
        platform_log_error("%s\n", msg);
        free(msg);
        exit(1);
    }
}

void ios_update(){
    // Call `on_update` method
    py_push(cl_game());
    bool ok = py_pushmethod(cached.on_update);
    assert(ok);
    if(!py_vectorcall(0, 0)){
        char* msg = py_formatexc();
        platform_log_error("%s\n", msg);
        free(msg);
        exit(1);
    }
}

void ios_destroy(){
    if(py_isnil(cl_game())) return;

    // Call `on_destroy` method
    py_push(cl_game());
    bool ok = py_pushmethod(cached.on_destroy);
    assert(ok);
    if(!py_vectorcall(0, 0)){
        char* msg = py_formatexc();
        platform_log_error("%s\n", msg);
        free(msg);
        exit(1);
    }

    py_finalize();
}

// not iOS
#if PK_SYS_PLATFORM != 2
int main(int argc, char** argv){
#if PK_IS_DESKTOP_PLATFORM == 1
    if(argc > 1){
        if(argc != 2){
            platform_log_error("%s\n", "Usage: Game.exe [template_dir]");
            exit(1);
        }
        set_template_path(argv[1]);
    }
#endif

    ios_ready();
    if(py_isnil(cl_game())) return 1;
    while(!WindowShouldClose()){
        py_ItemRef h = py_getdict(cl_game(), cached._hot_reload_requested);
        assert(h && py_isbool(h));
        if(py_tobool(h)){
            py_resetvm();
            memset(&cached, 0, sizeof(cached));
            return main(argc, argv);
        }
        ios_update();
    }
    ios_destroy();
    return 0;
}
#endif