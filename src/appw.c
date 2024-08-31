#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "appw.h"
#include "raylib.h"

static const char *template_path;

void set_template_path(const char *path) { template_path = path; }

const char *get_template_path() { return template_path; }

unsigned char *libc_readfile(const char *path, int *size) {
  FILE *f = fopen(path, "rb");
  if (f == NULL)
    return NULL;
  fseek(f, 0, SEEK_END);
  *size = ftell(f);
  fseek(f, 0, SEEK_SET);
  unsigned char *data = (unsigned char *)malloc(*size + 1);
  *size = fread(data, 1, *size, f);
  data[*size] = '\0';
  fclose(f);
  return data;
}

static bool cl_load_asset(int argc, py_Ref argv) {
  PY_CHECK_ARGC(1);
  PY_CHECK_ARG_TYPE(0, tp_str);
  const char *path = py_tostr(argv);
  int size;
  unsigned char *data = platform_load_asset(path, &size);
  if (data == NULL)
    return py_exception(tp_IOError, "failed to load: %s", path);
  // TODO: unnecessary copy but safe
  unsigned char *data1 = py_newbytes(py_retval(), size);
  memcpy(data1, data, size);
  free(data);
  return true;
}

static bool cl_load_text_asset(int argc, py_Ref argv) {
  PY_CHECK_ARGC(1);
  PY_CHECK_ARG_TYPE(0, tp_str);
  const char *path = py_tostr(argv);
  int size;
  unsigned char *data = platform_load_asset(path, &size);
  if (data == NULL)
    return py_exception(tp_IOError, "failed to load: %s", path);
  py_newstrn(py_retval(), (const char *)data, size);
  free(data);
  return true;
}

static bool cl_list_assets(int argc, py_Ref argv) {
  PY_CHECK_ARGC(1);
  PY_CHECK_ARG_TYPE(0, tp_str);
  py_newlist(py_retval());
  return true;
}

static bool cl_fast_apply(int argc, py_Ref argv) {
  if (argc < 2)
    return TypeError("expected at least 2 arguments");
  py_Ref _0 = py_arg(0); // function
  py_Ref _1 = py_arg(1); // list

  int length;
  py_TValue *data;
  if (py_istype(_1, tp_list)) {
    length = py_list_len(_1);
    data = py_list_data(_1);
  } else if (py_istype(_1, tp_tuple)) {
    length = py_tuple_len(_1);
    data = py_tuple_data(_1);
  } else {
    return TypeError("expected list or tuple, got '%t'", py_typeof(_1));
  }

  for (int i = 0; i < length; i++) {
    py_push(_0);
    py_pushnil();
    py_push(py_offset(data, i));
    for (int j = 2; j < argc; j++)
      py_push(py_arg(j));
    if (!py_vectorcall(argc - 1, 0))
      return false;
  }
  py_newnone(py_retval());
  return true;
}

void py__add_module__ct() {
  py_GlobalRef mod = py_newmodule("_carrotlib");

  // #if PK_IS_DESKTOP_PLATFORM == 1
  //     int desktop_screen_width, desktop_screen_height;
  //     platform_desktop_screen_size(desktop_screen_width,
  //     desktop_screen_height); mod->attr().set("DESKTOP_SCREEN_WIDTH",
  //     VAR(desktop_screen_width)); mod->attr().set("DESKTOP_SCREEN_HEIGHT",
  //     VAR(desktop_screen_height));
  // #else
  //     mod->attr().set("DESKTOP_SCREEN_WIDTH", VAR(0));
  //     mod->attr().set("DESKTOP_SCREEN_HEIGHT", VAR(0));
  // #endif

  py_bindfunc(mod, "load_asset", cl_load_asset);
  py_bindfunc(mod, "load_text_asset", cl_load_text_asset);
  py_bindfunc(mod, "list_assets", cl_list_assets);

  py_bindfunc(mod, "fast_apply", cl_fast_apply);

  // vm->bind(mod, "get_caches_directory() -> str",
  //     [](VM* vm, ArgsView args){
  //         return VAR(platform_caches_directory());
  //     });

  // vm->bind(mod, "get_documents_directory() -> str",
  //     [](VM* vm, ArgsView args){
  //         return VAR(platform_documents_directory());
  //     });

#if defined(GRAPHICS_API_OPENGL_33)
  py_setdict(mod, py_name("GRAPHICS_API_OPENGL_33"), py_True);
#else
  py_setdict(mod, py_name("GRAPHICS_API_OPENGL_33"), py_False);
#endif
#if defined(GRAPHICS_API_OPENGL_ES2)
  py_setdict(mod, py_name("GRAPHICS_API_OPENGL_ES2"), py_True);
#else
  py_setdict(mod, py_name("GRAPHICS_API_OPENGL_ES2"), py_False);
#endif
#if defined(GRAPHICS_API_OPENGL_ES3)
  py_setdict(mod, py_name("GRAPHICS_API_OPENGL_ES3"), py_True);
#else
  py_setdict(mod, py_name("GRAPHICS_API_OPENGL_ES3"), py_False);
#endif
}
