#include "pocketpy.h"
#include "string.h"
#include "box2d/box2d.h"

#define ADD_ENUM(name) py_newint(py_emplacedict(mod, py_name(#name)), name)

static bool struct__address__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    void* ud = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)ud);
    return true;
}


static bool b2Version__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2Version));
    return true;
}
static bool b2Version__init__(int argc, py_Ref argv) {
    b2Version* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2Version));
    } else if(argc == 1 + 3) {
        if(!py_checkint(py_arg(1))) return false;
        self->major = py_toint(py_arg(1));
        if(!py_checkint(py_arg(2))) return false;
        self->minor = py_toint(py_arg(2));
        if(!py_checkint(py_arg(3))) return false;
        self->revision = py_toint(py_arg(3));
    } else {
        return TypeError("expected 1 or 4 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2Version__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Version* self = py_touserdata(argv);
    b2Version* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2Version));
    *res = *self;
    return true;
}
static bool b2Version__get_major(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Version* self = py_touserdata(argv);
    py_newint(py_retval(), self->major);
    return true;
}
static bool b2Version__set_major(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Version* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->major = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2Version__get_minor(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Version* self = py_touserdata(argv);
    py_newint(py_retval(), self->minor);
    return true;
}
static bool b2Version__set_minor(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Version* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->minor = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2Version__get_revision(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Version* self = py_touserdata(argv);
    py_newint(py_retval(), self->revision);
    return true;
}
static bool b2Version__set_revision(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Version* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->revision = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2Version(py_GlobalRef mod) {
    py_Type type = py_newtype("b2Version", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2Version__new__);
    py_bindmagic(type, __init__, b2Version__init__);
    py_bindmethod(type, "copy", b2Version__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "major", b2Version__get_major, b2Version__set_major);
    py_bindproperty(type, "minor", b2Version__get_minor, b2Version__set_minor);
    py_bindproperty(type, "revision", b2Version__get_revision, b2Version__set_revision);
    return type;
}
static py_Type tp_user_b2Version;
static bool b2Vec2__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2Vec2));
    return true;
}
static bool b2Vec2__init__(int argc, py_Ref argv) {
    b2Vec2* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2Vec2));
    } else if(argc == 1 + 2) {
        if(!py_castfloat32(py_arg(1), &self->x)) return false;
        if(!py_castfloat32(py_arg(2), &self->y)) return false;
    } else {
        return TypeError("expected 1 or 3 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2Vec2__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Vec2* self = py_touserdata(argv);
    b2Vec2* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2Vec2));
    *res = *self;
    return true;
}
static bool b2Vec2__get_x(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Vec2* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->x);
    return true;
}
static bool b2Vec2__set_x(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Vec2* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->x)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2Vec2__get_y(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Vec2* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->y);
    return true;
}
static bool b2Vec2__set_y(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Vec2* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->y)) return false;
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2Vec2(py_GlobalRef mod) {
    py_Type type = py_newtype("b2Vec2", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2Vec2__new__);
    py_bindmagic(type, __init__, b2Vec2__init__);
    py_bindmethod(type, "copy", b2Vec2__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "x", b2Vec2__get_x, b2Vec2__set_x);
    py_bindproperty(type, "y", b2Vec2__get_y, b2Vec2__set_y);
    return type;
}
static py_Type tp_user_b2Vec2;
static bool b2Rot__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2Rot));
    return true;
}
static bool b2Rot__init__(int argc, py_Ref argv) {
    b2Rot* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2Rot));
    } else if(argc == 1 + 2) {
        if(!py_castfloat32(py_arg(1), &self->c)) return false;
        if(!py_castfloat32(py_arg(2), &self->s)) return false;
    } else {
        return TypeError("expected 1 or 3 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2Rot__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Rot* self = py_touserdata(argv);
    b2Rot* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2Rot));
    *res = *self;
    return true;
}
static bool b2Rot__get_c(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Rot* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->c);
    return true;
}
static bool b2Rot__set_c(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Rot* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->c)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2Rot__get_s(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Rot* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->s);
    return true;
}
static bool b2Rot__set_s(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Rot* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->s)) return false;
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2Rot(py_GlobalRef mod) {
    py_Type type = py_newtype("b2Rot", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2Rot__new__);
    py_bindmagic(type, __init__, b2Rot__init__);
    py_bindmethod(type, "copy", b2Rot__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "c", b2Rot__get_c, b2Rot__set_c);
    py_bindproperty(type, "s", b2Rot__get_s, b2Rot__set_s);
    return type;
}
static py_Type tp_user_b2Rot;
static bool b2Transform__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2Transform));
    return true;
}
static bool b2Transform__init__(int argc, py_Ref argv) {
    b2Transform* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2Transform));
    } else if(argc == 1 + 2) {
        do {
            if(!py_checktype(py_arg(1), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(1));
            self->p = *(b2Vec2*)(&tmp);
        } while(0);
        do {
            if(!py_checktype(py_arg(2), tp_user_b2Rot)) return false;
            self->q = *(b2Rot*)py_touserdata(py_arg(2));
        } while(0);
    } else {
        return TypeError("expected 1 or 3 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2Transform__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Transform* self = py_touserdata(argv);
    b2Transform* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2Transform));
    *res = *self;
    return true;
}
static bool b2Transform__get_p(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Transform* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->p));
    return true;
}
static bool b2Transform__set_p(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Transform* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->p = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2Transform__get_q(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Transform* self = py_touserdata(argv);
    do {
        b2Rot* ud = py_newobject(py_retval(), tp_user_b2Rot, 0, sizeof(b2Rot));
        *ud = self->q;
    } while(0);
    return true;
}
static bool b2Transform__set_q(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Transform* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2Rot)) return false;
        self->q = *(b2Rot*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2Transform(py_GlobalRef mod) {
    py_Type type = py_newtype("b2Transform", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2Transform__new__);
    py_bindmagic(type, __init__, b2Transform__init__);
    py_bindmethod(type, "copy", b2Transform__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "p", b2Transform__get_p, b2Transform__set_p);
    py_bindproperty(type, "q", b2Transform__get_q, b2Transform__set_q);
    return type;
}
static py_Type tp_user_b2Transform;
static bool b2Mat22__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2Mat22));
    return true;
}
static bool b2Mat22__init__(int argc, py_Ref argv) {
    b2Mat22* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2Mat22));
    } else if(argc == 1 + 2) {
        do {
            if(!py_checktype(py_arg(1), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(1));
            self->cx = *(b2Vec2*)(&tmp);
        } while(0);
        do {
            if(!py_checktype(py_arg(2), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(2));
            self->cy = *(b2Vec2*)(&tmp);
        } while(0);
    } else {
        return TypeError("expected 1 or 3 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2Mat22__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Mat22* self = py_touserdata(argv);
    b2Mat22* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2Mat22));
    *res = *self;
    return true;
}
static bool b2Mat22__get_cx(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Mat22* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->cx));
    return true;
}
static bool b2Mat22__set_cx(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Mat22* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->cx = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2Mat22__get_cy(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Mat22* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->cy));
    return true;
}
static bool b2Mat22__set_cy(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Mat22* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->cy = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2Mat22(py_GlobalRef mod) {
    py_Type type = py_newtype("b2Mat22", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2Mat22__new__);
    py_bindmagic(type, __init__, b2Mat22__init__);
    py_bindmethod(type, "copy", b2Mat22__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "cx", b2Mat22__get_cx, b2Mat22__set_cx);
    py_bindproperty(type, "cy", b2Mat22__get_cy, b2Mat22__set_cy);
    return type;
}
static py_Type tp_user_b2Mat22;
static bool b2AABB__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2AABB));
    return true;
}
static bool b2AABB__init__(int argc, py_Ref argv) {
    b2AABB* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2AABB));
    } else if(argc == 1 + 2) {
        do {
            if(!py_checktype(py_arg(1), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(1));
            self->lowerBound = *(b2Vec2*)(&tmp);
        } while(0);
        do {
            if(!py_checktype(py_arg(2), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(2));
            self->upperBound = *(b2Vec2*)(&tmp);
        } while(0);
    } else {
        return TypeError("expected 1 or 3 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2AABB__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2AABB* self = py_touserdata(argv);
    b2AABB* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2AABB));
    *res = *self;
    return true;
}
static bool b2AABB__get_lowerBound(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2AABB* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->lowerBound));
    return true;
}
static bool b2AABB__set_lowerBound(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2AABB* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->lowerBound = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2AABB__get_upperBound(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2AABB* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->upperBound));
    return true;
}
static bool b2AABB__set_upperBound(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2AABB* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->upperBound = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2AABB(py_GlobalRef mod) {
    py_Type type = py_newtype("b2AABB", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2AABB__new__);
    py_bindmagic(type, __init__, b2AABB__init__);
    py_bindmethod(type, "copy", b2AABB__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "lowerBound", b2AABB__get_lowerBound, b2AABB__set_lowerBound);
    py_bindproperty(type, "upperBound", b2AABB__get_upperBound, b2AABB__set_upperBound);
    return type;
}
static py_Type tp_user_b2AABB;
static bool b2RayCastInput__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2RayCastInput));
    return true;
}
static bool b2RayCastInput__init__(int argc, py_Ref argv) {
    b2RayCastInput* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2RayCastInput));
    } else if(argc == 1 + 3) {
        do {
            if(!py_checktype(py_arg(1), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(1));
            self->origin = *(b2Vec2*)(&tmp);
        } while(0);
        do {
            if(!py_checktype(py_arg(2), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(2));
            self->translation = *(b2Vec2*)(&tmp);
        } while(0);
        if(!py_castfloat32(py_arg(3), &self->maxFraction)) return false;
    } else {
        return TypeError("expected 1 or 4 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2RayCastInput__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2RayCastInput* self = py_touserdata(argv);
    b2RayCastInput* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2RayCastInput));
    *res = *self;
    return true;
}
static bool b2RayCastInput__get_origin(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2RayCastInput* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->origin));
    return true;
}
static bool b2RayCastInput__set_origin(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2RayCastInput* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->origin = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2RayCastInput__get_translation(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2RayCastInput* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->translation));
    return true;
}
static bool b2RayCastInput__set_translation(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2RayCastInput* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->translation = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2RayCastInput__get_maxFraction(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2RayCastInput* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->maxFraction);
    return true;
}
static bool b2RayCastInput__set_maxFraction(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2RayCastInput* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->maxFraction)) return false;
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2RayCastInput(py_GlobalRef mod) {
    py_Type type = py_newtype("b2RayCastInput", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2RayCastInput__new__);
    py_bindmagic(type, __init__, b2RayCastInput__init__);
    py_bindmethod(type, "copy", b2RayCastInput__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "origin", b2RayCastInput__get_origin, b2RayCastInput__set_origin);
    py_bindproperty(type, "translation", b2RayCastInput__get_translation, b2RayCastInput__set_translation);
    py_bindproperty(type, "maxFraction", b2RayCastInput__get_maxFraction, b2RayCastInput__set_maxFraction);
    return type;
}
static py_Type tp_user_b2RayCastInput;
static bool b2ShapeCastInput__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2ShapeCastInput));
    return true;
}
static bool b2ShapeCastInput__init__(int argc, py_Ref argv) {
    b2ShapeCastInput* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2ShapeCastInput));
    } else if(argc == 1 + 5) {
        // _0 points is read-only
        if(!py_checkint(py_arg(2))) return false;
        self->count = py_toint(py_arg(2));
        if(!py_castfloat32(py_arg(3), &self->radius)) return false;
        do {
            if(!py_checktype(py_arg(4), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(4));
            self->translation = *(b2Vec2*)(&tmp);
        } while(0);
        if(!py_castfloat32(py_arg(5), &self->maxFraction)) return false;
    } else {
        return TypeError("expected 1 or 6 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2ShapeCastInput__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ShapeCastInput* self = py_touserdata(argv);
    b2ShapeCastInput* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2ShapeCastInput));
    *res = *self;
    return true;
}
static bool b2ShapeCastInput__get_points(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ShapeCastInput* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->points);
    return true;
}
static bool b2ShapeCastInput__get_count(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ShapeCastInput* self = py_touserdata(argv);
    py_newint(py_retval(), self->count);
    return true;
}
static bool b2ShapeCastInput__set_count(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ShapeCastInput* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->count = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2ShapeCastInput__get_radius(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ShapeCastInput* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->radius);
    return true;
}
static bool b2ShapeCastInput__set_radius(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ShapeCastInput* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->radius)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2ShapeCastInput__get_translation(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ShapeCastInput* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->translation));
    return true;
}
static bool b2ShapeCastInput__set_translation(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ShapeCastInput* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->translation = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2ShapeCastInput__get_maxFraction(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ShapeCastInput* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->maxFraction);
    return true;
}
static bool b2ShapeCastInput__set_maxFraction(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ShapeCastInput* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->maxFraction)) return false;
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2ShapeCastInput(py_GlobalRef mod) {
    py_Type type = py_newtype("b2ShapeCastInput", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2ShapeCastInput__new__);
    py_bindmagic(type, __init__, b2ShapeCastInput__init__);
    py_bindmethod(type, "copy", b2ShapeCastInput__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "points", b2ShapeCastInput__get_points, NULL);
    py_bindproperty(type, "count", b2ShapeCastInput__get_count, b2ShapeCastInput__set_count);
    py_bindproperty(type, "radius", b2ShapeCastInput__get_radius, b2ShapeCastInput__set_radius);
    py_bindproperty(type, "translation", b2ShapeCastInput__get_translation, b2ShapeCastInput__set_translation);
    py_bindproperty(type, "maxFraction", b2ShapeCastInput__get_maxFraction, b2ShapeCastInput__set_maxFraction);
    return type;
}
static py_Type tp_user_b2ShapeCastInput;
static bool b2CastOutput__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2CastOutput));
    return true;
}
static bool b2CastOutput__init__(int argc, py_Ref argv) {
    b2CastOutput* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2CastOutput));
    } else if(argc == 1 + 5) {
        do {
            if(!py_checktype(py_arg(1), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(1));
            self->normal = *(b2Vec2*)(&tmp);
        } while(0);
        do {
            if(!py_checktype(py_arg(2), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(2));
            self->point = *(b2Vec2*)(&tmp);
        } while(0);
        if(!py_castfloat32(py_arg(3), &self->fraction)) return false;
        if(!py_checkint(py_arg(4))) return false;
        self->iterations = py_toint(py_arg(4));
        if(!py_checkbool(py_arg(5))) return false;
        self->hit = py_tobool(py_arg(5));
    } else {
        return TypeError("expected 1 or 6 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2CastOutput__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2CastOutput* self = py_touserdata(argv);
    b2CastOutput* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2CastOutput));
    *res = *self;
    return true;
}
static bool b2CastOutput__get_normal(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2CastOutput* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->normal));
    return true;
}
static bool b2CastOutput__set_normal(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2CastOutput* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->normal = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2CastOutput__get_point(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2CastOutput* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->point));
    return true;
}
static bool b2CastOutput__set_point(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2CastOutput* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->point = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2CastOutput__get_fraction(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2CastOutput* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->fraction);
    return true;
}
static bool b2CastOutput__set_fraction(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2CastOutput* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->fraction)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2CastOutput__get_iterations(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2CastOutput* self = py_touserdata(argv);
    py_newint(py_retval(), self->iterations);
    return true;
}
static bool b2CastOutput__set_iterations(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2CastOutput* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->iterations = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2CastOutput__get_hit(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2CastOutput* self = py_touserdata(argv);
    py_newbool(py_retval(), self->hit);
    return true;
}
static bool b2CastOutput__set_hit(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2CastOutput* self = py_touserdata(argv);
    if(!py_checkbool(py_arg(1))) return false;
    self->hit = py_tobool(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2CastOutput(py_GlobalRef mod) {
    py_Type type = py_newtype("b2CastOutput", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2CastOutput__new__);
    py_bindmagic(type, __init__, b2CastOutput__init__);
    py_bindmethod(type, "copy", b2CastOutput__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "normal", b2CastOutput__get_normal, b2CastOutput__set_normal);
    py_bindproperty(type, "point", b2CastOutput__get_point, b2CastOutput__set_point);
    py_bindproperty(type, "fraction", b2CastOutput__get_fraction, b2CastOutput__set_fraction);
    py_bindproperty(type, "iterations", b2CastOutput__get_iterations, b2CastOutput__set_iterations);
    py_bindproperty(type, "hit", b2CastOutput__get_hit, b2CastOutput__set_hit);
    return type;
}
static py_Type tp_user_b2CastOutput;
static bool b2MassData__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2MassData));
    return true;
}
static bool b2MassData__init__(int argc, py_Ref argv) {
    b2MassData* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2MassData));
    } else if(argc == 1 + 3) {
        if(!py_castfloat32(py_arg(1), &self->mass)) return false;
        do {
            if(!py_checktype(py_arg(2), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(2));
            self->center = *(b2Vec2*)(&tmp);
        } while(0);
        if(!py_castfloat32(py_arg(3), &self->rotationalInertia)) return false;
    } else {
        return TypeError("expected 1 or 4 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2MassData__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2MassData* self = py_touserdata(argv);
    b2MassData* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2MassData));
    *res = *self;
    return true;
}
static bool b2MassData__get_mass(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2MassData* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->mass);
    return true;
}
static bool b2MassData__set_mass(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2MassData* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->mass)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2MassData__get_center(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2MassData* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->center));
    return true;
}
static bool b2MassData__set_center(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2MassData* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->center = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2MassData__get_rotationalInertia(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2MassData* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->rotationalInertia);
    return true;
}
static bool b2MassData__set_rotationalInertia(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2MassData* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->rotationalInertia)) return false;
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2MassData(py_GlobalRef mod) {
    py_Type type = py_newtype("b2MassData", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2MassData__new__);
    py_bindmagic(type, __init__, b2MassData__init__);
    py_bindmethod(type, "copy", b2MassData__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "mass", b2MassData__get_mass, b2MassData__set_mass);
    py_bindproperty(type, "center", b2MassData__get_center, b2MassData__set_center);
    py_bindproperty(type, "rotationalInertia", b2MassData__get_rotationalInertia, b2MassData__set_rotationalInertia);
    return type;
}
static py_Type tp_user_b2MassData;
static bool b2Circle__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2Circle));
    return true;
}
static bool b2Circle__init__(int argc, py_Ref argv) {
    b2Circle* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2Circle));
    } else if(argc == 1 + 2) {
        do {
            if(!py_checktype(py_arg(1), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(1));
            self->center = *(b2Vec2*)(&tmp);
        } while(0);
        if(!py_castfloat32(py_arg(2), &self->radius)) return false;
    } else {
        return TypeError("expected 1 or 3 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2Circle__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Circle* self = py_touserdata(argv);
    b2Circle* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2Circle));
    *res = *self;
    return true;
}
static bool b2Circle__get_center(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Circle* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->center));
    return true;
}
static bool b2Circle__set_center(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Circle* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->center = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2Circle__get_radius(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Circle* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->radius);
    return true;
}
static bool b2Circle__set_radius(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Circle* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->radius)) return false;
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2Circle(py_GlobalRef mod) {
    py_Type type = py_newtype("b2Circle", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2Circle__new__);
    py_bindmagic(type, __init__, b2Circle__init__);
    py_bindmethod(type, "copy", b2Circle__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "center", b2Circle__get_center, b2Circle__set_center);
    py_bindproperty(type, "radius", b2Circle__get_radius, b2Circle__set_radius);
    return type;
}
static py_Type tp_user_b2Circle;
static bool b2Capsule__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2Capsule));
    return true;
}
static bool b2Capsule__init__(int argc, py_Ref argv) {
    b2Capsule* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2Capsule));
    } else if(argc == 1 + 3) {
        do {
            if(!py_checktype(py_arg(1), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(1));
            self->center1 = *(b2Vec2*)(&tmp);
        } while(0);
        do {
            if(!py_checktype(py_arg(2), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(2));
            self->center2 = *(b2Vec2*)(&tmp);
        } while(0);
        if(!py_castfloat32(py_arg(3), &self->radius)) return false;
    } else {
        return TypeError("expected 1 or 4 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2Capsule__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Capsule* self = py_touserdata(argv);
    b2Capsule* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2Capsule));
    *res = *self;
    return true;
}
static bool b2Capsule__get_center1(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Capsule* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->center1));
    return true;
}
static bool b2Capsule__set_center1(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Capsule* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->center1 = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2Capsule__get_center2(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Capsule* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->center2));
    return true;
}
static bool b2Capsule__set_center2(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Capsule* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->center2 = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2Capsule__get_radius(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Capsule* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->radius);
    return true;
}
static bool b2Capsule__set_radius(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Capsule* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->radius)) return false;
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2Capsule(py_GlobalRef mod) {
    py_Type type = py_newtype("b2Capsule", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2Capsule__new__);
    py_bindmagic(type, __init__, b2Capsule__init__);
    py_bindmethod(type, "copy", b2Capsule__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "center1", b2Capsule__get_center1, b2Capsule__set_center1);
    py_bindproperty(type, "center2", b2Capsule__get_center2, b2Capsule__set_center2);
    py_bindproperty(type, "radius", b2Capsule__get_radius, b2Capsule__set_radius);
    return type;
}
static py_Type tp_user_b2Capsule;
static bool b2Polygon__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2Polygon));
    return true;
}
static bool b2Polygon__init__(int argc, py_Ref argv) {
    b2Polygon* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2Polygon));
    } else if(argc == 1 + 5) {
        // _0 vertices is read-only
        // _1 normals is read-only
        do {
            if(!py_checktype(py_arg(3), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(3));
            self->centroid = *(b2Vec2*)(&tmp);
        } while(0);
        if(!py_castfloat32(py_arg(4), &self->radius)) return false;
        if(!py_checkint(py_arg(5))) return false;
        self->count = py_toint(py_arg(5));
    } else {
        return TypeError("expected 1 or 6 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2Polygon__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Polygon* self = py_touserdata(argv);
    b2Polygon* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2Polygon));
    *res = *self;
    return true;
}
static bool b2Polygon__get_vertices(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Polygon* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->vertices);
    return true;
}
static bool b2Polygon__get_normals(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Polygon* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->normals);
    return true;
}
static bool b2Polygon__get_centroid(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Polygon* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->centroid));
    return true;
}
static bool b2Polygon__set_centroid(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Polygon* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->centroid = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2Polygon__get_radius(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Polygon* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->radius);
    return true;
}
static bool b2Polygon__set_radius(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Polygon* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->radius)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2Polygon__get_count(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Polygon* self = py_touserdata(argv);
    py_newint(py_retval(), self->count);
    return true;
}
static bool b2Polygon__set_count(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Polygon* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->count = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2Polygon(py_GlobalRef mod) {
    py_Type type = py_newtype("b2Polygon", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2Polygon__new__);
    py_bindmagic(type, __init__, b2Polygon__init__);
    py_bindmethod(type, "copy", b2Polygon__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "vertices", b2Polygon__get_vertices, NULL);
    py_bindproperty(type, "normals", b2Polygon__get_normals, NULL);
    py_bindproperty(type, "centroid", b2Polygon__get_centroid, b2Polygon__set_centroid);
    py_bindproperty(type, "radius", b2Polygon__get_radius, b2Polygon__set_radius);
    py_bindproperty(type, "count", b2Polygon__get_count, b2Polygon__set_count);
    return type;
}
static py_Type tp_user_b2Polygon;
static bool b2Segment__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2Segment));
    return true;
}
static bool b2Segment__init__(int argc, py_Ref argv) {
    b2Segment* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2Segment));
    } else if(argc == 1 + 2) {
        do {
            if(!py_checktype(py_arg(1), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(1));
            self->point1 = *(b2Vec2*)(&tmp);
        } while(0);
        do {
            if(!py_checktype(py_arg(2), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(2));
            self->point2 = *(b2Vec2*)(&tmp);
        } while(0);
    } else {
        return TypeError("expected 1 or 3 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2Segment__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Segment* self = py_touserdata(argv);
    b2Segment* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2Segment));
    *res = *self;
    return true;
}
static bool b2Segment__get_point1(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Segment* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->point1));
    return true;
}
static bool b2Segment__set_point1(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Segment* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->point1 = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2Segment__get_point2(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Segment* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->point2));
    return true;
}
static bool b2Segment__set_point2(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Segment* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->point2 = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2Segment(py_GlobalRef mod) {
    py_Type type = py_newtype("b2Segment", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2Segment__new__);
    py_bindmagic(type, __init__, b2Segment__init__);
    py_bindmethod(type, "copy", b2Segment__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "point1", b2Segment__get_point1, b2Segment__set_point1);
    py_bindproperty(type, "point2", b2Segment__get_point2, b2Segment__set_point2);
    return type;
}
static py_Type tp_user_b2Segment;
static bool b2SmoothSegment__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2SmoothSegment));
    return true;
}
static bool b2SmoothSegment__init__(int argc, py_Ref argv) {
    b2SmoothSegment* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2SmoothSegment));
    } else if(argc == 1 + 4) {
        do {
            if(!py_checktype(py_arg(1), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(1));
            self->ghost1 = *(b2Vec2*)(&tmp);
        } while(0);
        do {
            if(!py_checktype(py_arg(2), tp_user_b2Segment)) return false;
            self->segment = *(b2Segment*)py_touserdata(py_arg(2));
        } while(0);
        do {
            if(!py_checktype(py_arg(3), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(3));
            self->ghost2 = *(b2Vec2*)(&tmp);
        } while(0);
        if(!py_checkint(py_arg(4))) return false;
        self->chainId = py_toint(py_arg(4));
    } else {
        return TypeError("expected 1 or 5 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2SmoothSegment__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2SmoothSegment* self = py_touserdata(argv);
    b2SmoothSegment* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2SmoothSegment));
    *res = *self;
    return true;
}
static bool b2SmoothSegment__get_ghost1(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2SmoothSegment* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->ghost1));
    return true;
}
static bool b2SmoothSegment__set_ghost1(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2SmoothSegment* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->ghost1 = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2SmoothSegment__get_segment(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2SmoothSegment* self = py_touserdata(argv);
    do {
        b2Segment* ud = py_newobject(py_retval(), tp_user_b2Segment, 0, sizeof(b2Segment));
        *ud = self->segment;
    } while(0);
    return true;
}
static bool b2SmoothSegment__set_segment(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2SmoothSegment* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2Segment)) return false;
        self->segment = *(b2Segment*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2SmoothSegment__get_ghost2(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2SmoothSegment* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->ghost2));
    return true;
}
static bool b2SmoothSegment__set_ghost2(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2SmoothSegment* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->ghost2 = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2SmoothSegment__get_chainId(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2SmoothSegment* self = py_touserdata(argv);
    py_newint(py_retval(), self->chainId);
    return true;
}
static bool b2SmoothSegment__set_chainId(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2SmoothSegment* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->chainId = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2SmoothSegment(py_GlobalRef mod) {
    py_Type type = py_newtype("b2SmoothSegment", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2SmoothSegment__new__);
    py_bindmagic(type, __init__, b2SmoothSegment__init__);
    py_bindmethod(type, "copy", b2SmoothSegment__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "ghost1", b2SmoothSegment__get_ghost1, b2SmoothSegment__set_ghost1);
    py_bindproperty(type, "segment", b2SmoothSegment__get_segment, b2SmoothSegment__set_segment);
    py_bindproperty(type, "ghost2", b2SmoothSegment__get_ghost2, b2SmoothSegment__set_ghost2);
    py_bindproperty(type, "chainId", b2SmoothSegment__get_chainId, b2SmoothSegment__set_chainId);
    return type;
}
static py_Type tp_user_b2SmoothSegment;
static bool b2Hull__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2Hull));
    return true;
}
static bool b2Hull__init__(int argc, py_Ref argv) {
    b2Hull* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2Hull));
    } else if(argc == 1 + 2) {
        // _0 points is read-only
        if(!py_checkint(py_arg(2))) return false;
        self->count = py_toint(py_arg(2));
    } else {
        return TypeError("expected 1 or 3 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2Hull__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Hull* self = py_touserdata(argv);
    b2Hull* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2Hull));
    *res = *self;
    return true;
}
static bool b2Hull__get_points(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Hull* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->points);
    return true;
}
static bool b2Hull__get_count(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Hull* self = py_touserdata(argv);
    py_newint(py_retval(), self->count);
    return true;
}
static bool b2Hull__set_count(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Hull* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->count = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2Hull(py_GlobalRef mod) {
    py_Type type = py_newtype("b2Hull", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2Hull__new__);
    py_bindmagic(type, __init__, b2Hull__init__);
    py_bindmethod(type, "copy", b2Hull__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "points", b2Hull__get_points, NULL);
    py_bindproperty(type, "count", b2Hull__get_count, b2Hull__set_count);
    return type;
}
static py_Type tp_user_b2Hull;
static bool b2SegmentDistanceResult__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2SegmentDistanceResult));
    return true;
}
static bool b2SegmentDistanceResult__init__(int argc, py_Ref argv) {
    b2SegmentDistanceResult* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2SegmentDistanceResult));
    } else if(argc == 1 + 5) {
        do {
            if(!py_checktype(py_arg(1), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(1));
            self->closest1 = *(b2Vec2*)(&tmp);
        } while(0);
        do {
            if(!py_checktype(py_arg(2), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(2));
            self->closest2 = *(b2Vec2*)(&tmp);
        } while(0);
        if(!py_castfloat32(py_arg(3), &self->fraction1)) return false;
        if(!py_castfloat32(py_arg(4), &self->fraction2)) return false;
        if(!py_castfloat32(py_arg(5), &self->distanceSquared)) return false;
    } else {
        return TypeError("expected 1 or 6 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2SegmentDistanceResult__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2SegmentDistanceResult* self = py_touserdata(argv);
    b2SegmentDistanceResult* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2SegmentDistanceResult));
    *res = *self;
    return true;
}
static bool b2SegmentDistanceResult__get_closest1(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2SegmentDistanceResult* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->closest1));
    return true;
}
static bool b2SegmentDistanceResult__set_closest1(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2SegmentDistanceResult* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->closest1 = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2SegmentDistanceResult__get_closest2(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2SegmentDistanceResult* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->closest2));
    return true;
}
static bool b2SegmentDistanceResult__set_closest2(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2SegmentDistanceResult* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->closest2 = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2SegmentDistanceResult__get_fraction1(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2SegmentDistanceResult* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->fraction1);
    return true;
}
static bool b2SegmentDistanceResult__set_fraction1(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2SegmentDistanceResult* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->fraction1)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2SegmentDistanceResult__get_fraction2(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2SegmentDistanceResult* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->fraction2);
    return true;
}
static bool b2SegmentDistanceResult__set_fraction2(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2SegmentDistanceResult* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->fraction2)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2SegmentDistanceResult__get_distanceSquared(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2SegmentDistanceResult* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->distanceSquared);
    return true;
}
static bool b2SegmentDistanceResult__set_distanceSquared(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2SegmentDistanceResult* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->distanceSquared)) return false;
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2SegmentDistanceResult(py_GlobalRef mod) {
    py_Type type = py_newtype("b2SegmentDistanceResult", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2SegmentDistanceResult__new__);
    py_bindmagic(type, __init__, b2SegmentDistanceResult__init__);
    py_bindmethod(type, "copy", b2SegmentDistanceResult__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "closest1", b2SegmentDistanceResult__get_closest1, b2SegmentDistanceResult__set_closest1);
    py_bindproperty(type, "closest2", b2SegmentDistanceResult__get_closest2, b2SegmentDistanceResult__set_closest2);
    py_bindproperty(type, "fraction1", b2SegmentDistanceResult__get_fraction1, b2SegmentDistanceResult__set_fraction1);
    py_bindproperty(type, "fraction2", b2SegmentDistanceResult__get_fraction2, b2SegmentDistanceResult__set_fraction2);
    py_bindproperty(type, "distanceSquared", b2SegmentDistanceResult__get_distanceSquared, b2SegmentDistanceResult__set_distanceSquared);
    return type;
}
static py_Type tp_user_b2SegmentDistanceResult;
static bool b2DistanceProxy__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2DistanceProxy));
    return true;
}
static bool b2DistanceProxy__init__(int argc, py_Ref argv) {
    b2DistanceProxy* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2DistanceProxy));
    } else if(argc == 1 + 3) {
        // _0 points is read-only
        if(!py_checkint(py_arg(2))) return false;
        self->count = py_toint(py_arg(2));
        if(!py_castfloat32(py_arg(3), &self->radius)) return false;
    } else {
        return TypeError("expected 1 or 4 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2DistanceProxy__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DistanceProxy* self = py_touserdata(argv);
    b2DistanceProxy* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2DistanceProxy));
    *res = *self;
    return true;
}
static bool b2DistanceProxy__get_points(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DistanceProxy* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->points);
    return true;
}
static bool b2DistanceProxy__get_count(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DistanceProxy* self = py_touserdata(argv);
    py_newint(py_retval(), self->count);
    return true;
}
static bool b2DistanceProxy__set_count(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2DistanceProxy* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->count = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2DistanceProxy__get_radius(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DistanceProxy* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->radius);
    return true;
}
static bool b2DistanceProxy__set_radius(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2DistanceProxy* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->radius)) return false;
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2DistanceProxy(py_GlobalRef mod) {
    py_Type type = py_newtype("b2DistanceProxy", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2DistanceProxy__new__);
    py_bindmagic(type, __init__, b2DistanceProxy__init__);
    py_bindmethod(type, "copy", b2DistanceProxy__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "points", b2DistanceProxy__get_points, NULL);
    py_bindproperty(type, "count", b2DistanceProxy__get_count, b2DistanceProxy__set_count);
    py_bindproperty(type, "radius", b2DistanceProxy__get_radius, b2DistanceProxy__set_radius);
    return type;
}
static py_Type tp_user_b2DistanceProxy;
static bool b2DistanceCache__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2DistanceCache));
    return true;
}
static bool b2DistanceCache__init__(int argc, py_Ref argv) {
    b2DistanceCache* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2DistanceCache));
    } else if(argc == 1 + 3) {
        if(!py_checkint(py_arg(1))) return false;
        self->count = py_toint(py_arg(1));
        // _1 indexA is read-only
        // _2 indexB is read-only
    } else {
        return TypeError("expected 1 or 4 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2DistanceCache__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DistanceCache* self = py_touserdata(argv);
    b2DistanceCache* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2DistanceCache));
    *res = *self;
    return true;
}
static bool b2DistanceCache__get_count(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DistanceCache* self = py_touserdata(argv);
    py_newint(py_retval(), self->count);
    return true;
}
static bool b2DistanceCache__set_count(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2DistanceCache* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->count = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2DistanceCache__get_indexA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DistanceCache* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->indexA);
    return true;
}
static bool b2DistanceCache__get_indexB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DistanceCache* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->indexB);
    return true;
}
static py_Type register__b2DistanceCache(py_GlobalRef mod) {
    py_Type type = py_newtype("b2DistanceCache", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2DistanceCache__new__);
    py_bindmagic(type, __init__, b2DistanceCache__init__);
    py_bindmethod(type, "copy", b2DistanceCache__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "count", b2DistanceCache__get_count, b2DistanceCache__set_count);
    py_bindproperty(type, "indexA", b2DistanceCache__get_indexA, NULL);
    py_bindproperty(type, "indexB", b2DistanceCache__get_indexB, NULL);
    return type;
}
static py_Type tp_user_b2DistanceCache;
static bool b2DistanceInput__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2DistanceInput));
    return true;
}
static bool b2DistanceInput__init__(int argc, py_Ref argv) {
    b2DistanceInput* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2DistanceInput));
    } else if(argc == 1 + 5) {
        do {
            if(!py_checktype(py_arg(1), tp_user_b2DistanceProxy)) return false;
            self->proxyA = *(b2DistanceProxy*)py_touserdata(py_arg(1));
        } while(0);
        do {
            if(!py_checktype(py_arg(2), tp_user_b2DistanceProxy)) return false;
            self->proxyB = *(b2DistanceProxy*)py_touserdata(py_arg(2));
        } while(0);
        do {
            if(!py_checktype(py_arg(3), tp_user_b2Transform)) return false;
            self->transformA = *(b2Transform*)py_touserdata(py_arg(3));
        } while(0);
        do {
            if(!py_checktype(py_arg(4), tp_user_b2Transform)) return false;
            self->transformB = *(b2Transform*)py_touserdata(py_arg(4));
        } while(0);
        if(!py_checkbool(py_arg(5))) return false;
        self->useRadii = py_tobool(py_arg(5));
    } else {
        return TypeError("expected 1 or 6 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2DistanceInput__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DistanceInput* self = py_touserdata(argv);
    b2DistanceInput* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2DistanceInput));
    *res = *self;
    return true;
}
static bool b2DistanceInput__get_proxyA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DistanceInput* self = py_touserdata(argv);
    do {
        b2DistanceProxy* ud = py_newobject(py_retval(), tp_user_b2DistanceProxy, 0, sizeof(b2DistanceProxy));
        *ud = self->proxyA;
    } while(0);
    return true;
}
static bool b2DistanceInput__set_proxyA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2DistanceInput* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2DistanceProxy)) return false;
        self->proxyA = *(b2DistanceProxy*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2DistanceInput__get_proxyB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DistanceInput* self = py_touserdata(argv);
    do {
        b2DistanceProxy* ud = py_newobject(py_retval(), tp_user_b2DistanceProxy, 0, sizeof(b2DistanceProxy));
        *ud = self->proxyB;
    } while(0);
    return true;
}
static bool b2DistanceInput__set_proxyB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2DistanceInput* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2DistanceProxy)) return false;
        self->proxyB = *(b2DistanceProxy*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2DistanceInput__get_transformA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DistanceInput* self = py_touserdata(argv);
    do {
        b2Transform* ud = py_newobject(py_retval(), tp_user_b2Transform, 0, sizeof(b2Transform));
        *ud = self->transformA;
    } while(0);
    return true;
}
static bool b2DistanceInput__set_transformA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2DistanceInput* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2Transform)) return false;
        self->transformA = *(b2Transform*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2DistanceInput__get_transformB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DistanceInput* self = py_touserdata(argv);
    do {
        b2Transform* ud = py_newobject(py_retval(), tp_user_b2Transform, 0, sizeof(b2Transform));
        *ud = self->transformB;
    } while(0);
    return true;
}
static bool b2DistanceInput__set_transformB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2DistanceInput* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2Transform)) return false;
        self->transformB = *(b2Transform*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2DistanceInput__get_useRadii(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DistanceInput* self = py_touserdata(argv);
    py_newbool(py_retval(), self->useRadii);
    return true;
}
static bool b2DistanceInput__set_useRadii(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2DistanceInput* self = py_touserdata(argv);
    if(!py_checkbool(py_arg(1))) return false;
    self->useRadii = py_tobool(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2DistanceInput(py_GlobalRef mod) {
    py_Type type = py_newtype("b2DistanceInput", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2DistanceInput__new__);
    py_bindmagic(type, __init__, b2DistanceInput__init__);
    py_bindmethod(type, "copy", b2DistanceInput__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "proxyA", b2DistanceInput__get_proxyA, b2DistanceInput__set_proxyA);
    py_bindproperty(type, "proxyB", b2DistanceInput__get_proxyB, b2DistanceInput__set_proxyB);
    py_bindproperty(type, "transformA", b2DistanceInput__get_transformA, b2DistanceInput__set_transformA);
    py_bindproperty(type, "transformB", b2DistanceInput__get_transformB, b2DistanceInput__set_transformB);
    py_bindproperty(type, "useRadii", b2DistanceInput__get_useRadii, b2DistanceInput__set_useRadii);
    return type;
}
static py_Type tp_user_b2DistanceInput;
static bool b2DistanceOutput__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2DistanceOutput));
    return true;
}
static bool b2DistanceOutput__init__(int argc, py_Ref argv) {
    b2DistanceOutput* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2DistanceOutput));
    } else if(argc == 1 + 5) {
        do {
            if(!py_checktype(py_arg(1), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(1));
            self->pointA = *(b2Vec2*)(&tmp);
        } while(0);
        do {
            if(!py_checktype(py_arg(2), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(2));
            self->pointB = *(b2Vec2*)(&tmp);
        } while(0);
        if(!py_castfloat32(py_arg(3), &self->distance)) return false;
        if(!py_checkint(py_arg(4))) return false;
        self->iterations = py_toint(py_arg(4));
        if(!py_checkint(py_arg(5))) return false;
        self->simplexCount = py_toint(py_arg(5));
    } else {
        return TypeError("expected 1 or 6 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2DistanceOutput__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DistanceOutput* self = py_touserdata(argv);
    b2DistanceOutput* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2DistanceOutput));
    *res = *self;
    return true;
}
static bool b2DistanceOutput__get_pointA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DistanceOutput* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->pointA));
    return true;
}
static bool b2DistanceOutput__set_pointA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2DistanceOutput* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->pointA = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2DistanceOutput__get_pointB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DistanceOutput* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->pointB));
    return true;
}
static bool b2DistanceOutput__set_pointB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2DistanceOutput* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->pointB = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2DistanceOutput__get_distance(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DistanceOutput* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->distance);
    return true;
}
static bool b2DistanceOutput__set_distance(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2DistanceOutput* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->distance)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2DistanceOutput__get_iterations(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DistanceOutput* self = py_touserdata(argv);
    py_newint(py_retval(), self->iterations);
    return true;
}
static bool b2DistanceOutput__set_iterations(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2DistanceOutput* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->iterations = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2DistanceOutput__get_simplexCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DistanceOutput* self = py_touserdata(argv);
    py_newint(py_retval(), self->simplexCount);
    return true;
}
static bool b2DistanceOutput__set_simplexCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2DistanceOutput* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->simplexCount = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2DistanceOutput(py_GlobalRef mod) {
    py_Type type = py_newtype("b2DistanceOutput", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2DistanceOutput__new__);
    py_bindmagic(type, __init__, b2DistanceOutput__init__);
    py_bindmethod(type, "copy", b2DistanceOutput__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "pointA", b2DistanceOutput__get_pointA, b2DistanceOutput__set_pointA);
    py_bindproperty(type, "pointB", b2DistanceOutput__get_pointB, b2DistanceOutput__set_pointB);
    py_bindproperty(type, "distance", b2DistanceOutput__get_distance, b2DistanceOutput__set_distance);
    py_bindproperty(type, "iterations", b2DistanceOutput__get_iterations, b2DistanceOutput__set_iterations);
    py_bindproperty(type, "simplexCount", b2DistanceOutput__get_simplexCount, b2DistanceOutput__set_simplexCount);
    return type;
}
static py_Type tp_user_b2DistanceOutput;
static bool b2SimplexVertex__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2SimplexVertex));
    return true;
}
static bool b2SimplexVertex__init__(int argc, py_Ref argv) {
    b2SimplexVertex* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2SimplexVertex));
    } else if(argc == 1 + 6) {
        do {
            if(!py_checktype(py_arg(1), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(1));
            self->wA = *(b2Vec2*)(&tmp);
        } while(0);
        do {
            if(!py_checktype(py_arg(2), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(2));
            self->wB = *(b2Vec2*)(&tmp);
        } while(0);
        do {
            if(!py_checktype(py_arg(3), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(3));
            self->w = *(b2Vec2*)(&tmp);
        } while(0);
        if(!py_castfloat32(py_arg(4), &self->a)) return false;
        if(!py_checkint(py_arg(5))) return false;
        self->indexA = py_toint(py_arg(5));
        if(!py_checkint(py_arg(6))) return false;
        self->indexB = py_toint(py_arg(6));
    } else {
        return TypeError("expected 1 or 7 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2SimplexVertex__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2SimplexVertex* self = py_touserdata(argv);
    b2SimplexVertex* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2SimplexVertex));
    *res = *self;
    return true;
}
static bool b2SimplexVertex__get_wA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2SimplexVertex* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->wA));
    return true;
}
static bool b2SimplexVertex__set_wA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2SimplexVertex* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->wA = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2SimplexVertex__get_wB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2SimplexVertex* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->wB));
    return true;
}
static bool b2SimplexVertex__set_wB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2SimplexVertex* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->wB = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2SimplexVertex__get_w(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2SimplexVertex* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->w));
    return true;
}
static bool b2SimplexVertex__set_w(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2SimplexVertex* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->w = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2SimplexVertex__get_a(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2SimplexVertex* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->a);
    return true;
}
static bool b2SimplexVertex__set_a(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2SimplexVertex* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->a)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2SimplexVertex__get_indexA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2SimplexVertex* self = py_touserdata(argv);
    py_newint(py_retval(), self->indexA);
    return true;
}
static bool b2SimplexVertex__set_indexA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2SimplexVertex* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->indexA = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2SimplexVertex__get_indexB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2SimplexVertex* self = py_touserdata(argv);
    py_newint(py_retval(), self->indexB);
    return true;
}
static bool b2SimplexVertex__set_indexB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2SimplexVertex* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->indexB = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2SimplexVertex(py_GlobalRef mod) {
    py_Type type = py_newtype("b2SimplexVertex", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2SimplexVertex__new__);
    py_bindmagic(type, __init__, b2SimplexVertex__init__);
    py_bindmethod(type, "copy", b2SimplexVertex__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "wA", b2SimplexVertex__get_wA, b2SimplexVertex__set_wA);
    py_bindproperty(type, "wB", b2SimplexVertex__get_wB, b2SimplexVertex__set_wB);
    py_bindproperty(type, "w", b2SimplexVertex__get_w, b2SimplexVertex__set_w);
    py_bindproperty(type, "a", b2SimplexVertex__get_a, b2SimplexVertex__set_a);
    py_bindproperty(type, "indexA", b2SimplexVertex__get_indexA, b2SimplexVertex__set_indexA);
    py_bindproperty(type, "indexB", b2SimplexVertex__get_indexB, b2SimplexVertex__set_indexB);
    return type;
}
static py_Type tp_user_b2SimplexVertex;
static bool b2Simplex__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2Simplex));
    return true;
}
static bool b2Simplex__init__(int argc, py_Ref argv) {
    b2Simplex* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2Simplex));
    } else if(argc == 1 + 4) {
        do {
            if(!py_checktype(py_arg(1), tp_user_b2SimplexVertex)) return false;
            self->v1 = *(b2SimplexVertex*)py_touserdata(py_arg(1));
        } while(0);
        do {
            if(!py_checktype(py_arg(2), tp_user_b2SimplexVertex)) return false;
            self->v2 = *(b2SimplexVertex*)py_touserdata(py_arg(2));
        } while(0);
        do {
            if(!py_checktype(py_arg(3), tp_user_b2SimplexVertex)) return false;
            self->v3 = *(b2SimplexVertex*)py_touserdata(py_arg(3));
        } while(0);
        if(!py_checkint(py_arg(4))) return false;
        self->count = py_toint(py_arg(4));
    } else {
        return TypeError("expected 1 or 5 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2Simplex__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Simplex* self = py_touserdata(argv);
    b2Simplex* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2Simplex));
    *res = *self;
    return true;
}
static bool b2Simplex__get_v1(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Simplex* self = py_touserdata(argv);
    do {
        b2SimplexVertex* ud = py_newobject(py_retval(), tp_user_b2SimplexVertex, 0, sizeof(b2SimplexVertex));
        *ud = self->v1;
    } while(0);
    return true;
}
static bool b2Simplex__set_v1(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Simplex* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2SimplexVertex)) return false;
        self->v1 = *(b2SimplexVertex*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2Simplex__get_v2(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Simplex* self = py_touserdata(argv);
    do {
        b2SimplexVertex* ud = py_newobject(py_retval(), tp_user_b2SimplexVertex, 0, sizeof(b2SimplexVertex));
        *ud = self->v2;
    } while(0);
    return true;
}
static bool b2Simplex__set_v2(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Simplex* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2SimplexVertex)) return false;
        self->v2 = *(b2SimplexVertex*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2Simplex__get_v3(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Simplex* self = py_touserdata(argv);
    do {
        b2SimplexVertex* ud = py_newobject(py_retval(), tp_user_b2SimplexVertex, 0, sizeof(b2SimplexVertex));
        *ud = self->v3;
    } while(0);
    return true;
}
static bool b2Simplex__set_v3(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Simplex* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2SimplexVertex)) return false;
        self->v3 = *(b2SimplexVertex*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2Simplex__get_count(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Simplex* self = py_touserdata(argv);
    py_newint(py_retval(), self->count);
    return true;
}
static bool b2Simplex__set_count(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Simplex* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->count = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2Simplex(py_GlobalRef mod) {
    py_Type type = py_newtype("b2Simplex", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2Simplex__new__);
    py_bindmagic(type, __init__, b2Simplex__init__);
    py_bindmethod(type, "copy", b2Simplex__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "v1", b2Simplex__get_v1, b2Simplex__set_v1);
    py_bindproperty(type, "v2", b2Simplex__get_v2, b2Simplex__set_v2);
    py_bindproperty(type, "v3", b2Simplex__get_v3, b2Simplex__set_v3);
    py_bindproperty(type, "count", b2Simplex__get_count, b2Simplex__set_count);
    return type;
}
static py_Type tp_user_b2Simplex;
static bool b2ShapeCastPairInput__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2ShapeCastPairInput));
    return true;
}
static bool b2ShapeCastPairInput__init__(int argc, py_Ref argv) {
    b2ShapeCastPairInput* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2ShapeCastPairInput));
    } else if(argc == 1 + 6) {
        do {
            if(!py_checktype(py_arg(1), tp_user_b2DistanceProxy)) return false;
            self->proxyA = *(b2DistanceProxy*)py_touserdata(py_arg(1));
        } while(0);
        do {
            if(!py_checktype(py_arg(2), tp_user_b2DistanceProxy)) return false;
            self->proxyB = *(b2DistanceProxy*)py_touserdata(py_arg(2));
        } while(0);
        do {
            if(!py_checktype(py_arg(3), tp_user_b2Transform)) return false;
            self->transformA = *(b2Transform*)py_touserdata(py_arg(3));
        } while(0);
        do {
            if(!py_checktype(py_arg(4), tp_user_b2Transform)) return false;
            self->transformB = *(b2Transform*)py_touserdata(py_arg(4));
        } while(0);
        do {
            if(!py_checktype(py_arg(5), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(5));
            self->translationB = *(b2Vec2*)(&tmp);
        } while(0);
        if(!py_castfloat32(py_arg(6), &self->maxFraction)) return false;
    } else {
        return TypeError("expected 1 or 7 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2ShapeCastPairInput__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ShapeCastPairInput* self = py_touserdata(argv);
    b2ShapeCastPairInput* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2ShapeCastPairInput));
    *res = *self;
    return true;
}
static bool b2ShapeCastPairInput__get_proxyA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ShapeCastPairInput* self = py_touserdata(argv);
    do {
        b2DistanceProxy* ud = py_newobject(py_retval(), tp_user_b2DistanceProxy, 0, sizeof(b2DistanceProxy));
        *ud = self->proxyA;
    } while(0);
    return true;
}
static bool b2ShapeCastPairInput__set_proxyA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ShapeCastPairInput* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2DistanceProxy)) return false;
        self->proxyA = *(b2DistanceProxy*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2ShapeCastPairInput__get_proxyB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ShapeCastPairInput* self = py_touserdata(argv);
    do {
        b2DistanceProxy* ud = py_newobject(py_retval(), tp_user_b2DistanceProxy, 0, sizeof(b2DistanceProxy));
        *ud = self->proxyB;
    } while(0);
    return true;
}
static bool b2ShapeCastPairInput__set_proxyB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ShapeCastPairInput* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2DistanceProxy)) return false;
        self->proxyB = *(b2DistanceProxy*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2ShapeCastPairInput__get_transformA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ShapeCastPairInput* self = py_touserdata(argv);
    do {
        b2Transform* ud = py_newobject(py_retval(), tp_user_b2Transform, 0, sizeof(b2Transform));
        *ud = self->transformA;
    } while(0);
    return true;
}
static bool b2ShapeCastPairInput__set_transformA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ShapeCastPairInput* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2Transform)) return false;
        self->transformA = *(b2Transform*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2ShapeCastPairInput__get_transformB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ShapeCastPairInput* self = py_touserdata(argv);
    do {
        b2Transform* ud = py_newobject(py_retval(), tp_user_b2Transform, 0, sizeof(b2Transform));
        *ud = self->transformB;
    } while(0);
    return true;
}
static bool b2ShapeCastPairInput__set_transformB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ShapeCastPairInput* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2Transform)) return false;
        self->transformB = *(b2Transform*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2ShapeCastPairInput__get_translationB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ShapeCastPairInput* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->translationB));
    return true;
}
static bool b2ShapeCastPairInput__set_translationB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ShapeCastPairInput* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->translationB = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2ShapeCastPairInput__get_maxFraction(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ShapeCastPairInput* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->maxFraction);
    return true;
}
static bool b2ShapeCastPairInput__set_maxFraction(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ShapeCastPairInput* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->maxFraction)) return false;
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2ShapeCastPairInput(py_GlobalRef mod) {
    py_Type type = py_newtype("b2ShapeCastPairInput", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2ShapeCastPairInput__new__);
    py_bindmagic(type, __init__, b2ShapeCastPairInput__init__);
    py_bindmethod(type, "copy", b2ShapeCastPairInput__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "proxyA", b2ShapeCastPairInput__get_proxyA, b2ShapeCastPairInput__set_proxyA);
    py_bindproperty(type, "proxyB", b2ShapeCastPairInput__get_proxyB, b2ShapeCastPairInput__set_proxyB);
    py_bindproperty(type, "transformA", b2ShapeCastPairInput__get_transformA, b2ShapeCastPairInput__set_transformA);
    py_bindproperty(type, "transformB", b2ShapeCastPairInput__get_transformB, b2ShapeCastPairInput__set_transformB);
    py_bindproperty(type, "translationB", b2ShapeCastPairInput__get_translationB, b2ShapeCastPairInput__set_translationB);
    py_bindproperty(type, "maxFraction", b2ShapeCastPairInput__get_maxFraction, b2ShapeCastPairInput__set_maxFraction);
    return type;
}
static py_Type tp_user_b2ShapeCastPairInput;
static bool b2Sweep__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2Sweep));
    return true;
}
static bool b2Sweep__init__(int argc, py_Ref argv) {
    b2Sweep* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2Sweep));
    } else if(argc == 1 + 5) {
        do {
            if(!py_checktype(py_arg(1), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(1));
            self->localCenter = *(b2Vec2*)(&tmp);
        } while(0);
        do {
            if(!py_checktype(py_arg(2), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(2));
            self->c1 = *(b2Vec2*)(&tmp);
        } while(0);
        do {
            if(!py_checktype(py_arg(3), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(3));
            self->c2 = *(b2Vec2*)(&tmp);
        } while(0);
        do {
            if(!py_checktype(py_arg(4), tp_user_b2Rot)) return false;
            self->q1 = *(b2Rot*)py_touserdata(py_arg(4));
        } while(0);
        do {
            if(!py_checktype(py_arg(5), tp_user_b2Rot)) return false;
            self->q2 = *(b2Rot*)py_touserdata(py_arg(5));
        } while(0);
    } else {
        return TypeError("expected 1 or 6 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2Sweep__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Sweep* self = py_touserdata(argv);
    b2Sweep* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2Sweep));
    *res = *self;
    return true;
}
static bool b2Sweep__get_localCenter(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Sweep* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->localCenter));
    return true;
}
static bool b2Sweep__set_localCenter(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Sweep* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->localCenter = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2Sweep__get_c1(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Sweep* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->c1));
    return true;
}
static bool b2Sweep__set_c1(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Sweep* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->c1 = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2Sweep__get_c2(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Sweep* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->c2));
    return true;
}
static bool b2Sweep__set_c2(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Sweep* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->c2 = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2Sweep__get_q1(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Sweep* self = py_touserdata(argv);
    do {
        b2Rot* ud = py_newobject(py_retval(), tp_user_b2Rot, 0, sizeof(b2Rot));
        *ud = self->q1;
    } while(0);
    return true;
}
static bool b2Sweep__set_q1(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Sweep* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2Rot)) return false;
        self->q1 = *(b2Rot*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2Sweep__get_q2(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Sweep* self = py_touserdata(argv);
    do {
        b2Rot* ud = py_newobject(py_retval(), tp_user_b2Rot, 0, sizeof(b2Rot));
        *ud = self->q2;
    } while(0);
    return true;
}
static bool b2Sweep__set_q2(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Sweep* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2Rot)) return false;
        self->q2 = *(b2Rot*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2Sweep(py_GlobalRef mod) {
    py_Type type = py_newtype("b2Sweep", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2Sweep__new__);
    py_bindmagic(type, __init__, b2Sweep__init__);
    py_bindmethod(type, "copy", b2Sweep__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "localCenter", b2Sweep__get_localCenter, b2Sweep__set_localCenter);
    py_bindproperty(type, "c1", b2Sweep__get_c1, b2Sweep__set_c1);
    py_bindproperty(type, "c2", b2Sweep__get_c2, b2Sweep__set_c2);
    py_bindproperty(type, "q1", b2Sweep__get_q1, b2Sweep__set_q1);
    py_bindproperty(type, "q2", b2Sweep__get_q2, b2Sweep__set_q2);
    return type;
}
static py_Type tp_user_b2Sweep;
static bool b2TOIInput__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2TOIInput));
    return true;
}
static bool b2TOIInput__init__(int argc, py_Ref argv) {
    b2TOIInput* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2TOIInput));
    } else if(argc == 1 + 5) {
        do {
            if(!py_checktype(py_arg(1), tp_user_b2DistanceProxy)) return false;
            self->proxyA = *(b2DistanceProxy*)py_touserdata(py_arg(1));
        } while(0);
        do {
            if(!py_checktype(py_arg(2), tp_user_b2DistanceProxy)) return false;
            self->proxyB = *(b2DistanceProxy*)py_touserdata(py_arg(2));
        } while(0);
        do {
            if(!py_checktype(py_arg(3), tp_user_b2Sweep)) return false;
            self->sweepA = *(b2Sweep*)py_touserdata(py_arg(3));
        } while(0);
        do {
            if(!py_checktype(py_arg(4), tp_user_b2Sweep)) return false;
            self->sweepB = *(b2Sweep*)py_touserdata(py_arg(4));
        } while(0);
        if(!py_castfloat32(py_arg(5), &self->tMax)) return false;
    } else {
        return TypeError("expected 1 or 6 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2TOIInput__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2TOIInput* self = py_touserdata(argv);
    b2TOIInput* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2TOIInput));
    *res = *self;
    return true;
}
static bool b2TOIInput__get_proxyA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2TOIInput* self = py_touserdata(argv);
    do {
        b2DistanceProxy* ud = py_newobject(py_retval(), tp_user_b2DistanceProxy, 0, sizeof(b2DistanceProxy));
        *ud = self->proxyA;
    } while(0);
    return true;
}
static bool b2TOIInput__set_proxyA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2TOIInput* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2DistanceProxy)) return false;
        self->proxyA = *(b2DistanceProxy*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2TOIInput__get_proxyB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2TOIInput* self = py_touserdata(argv);
    do {
        b2DistanceProxy* ud = py_newobject(py_retval(), tp_user_b2DistanceProxy, 0, sizeof(b2DistanceProxy));
        *ud = self->proxyB;
    } while(0);
    return true;
}
static bool b2TOIInput__set_proxyB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2TOIInput* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2DistanceProxy)) return false;
        self->proxyB = *(b2DistanceProxy*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2TOIInput__get_sweepA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2TOIInput* self = py_touserdata(argv);
    do {
        b2Sweep* ud = py_newobject(py_retval(), tp_user_b2Sweep, 0, sizeof(b2Sweep));
        *ud = self->sweepA;
    } while(0);
    return true;
}
static bool b2TOIInput__set_sweepA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2TOIInput* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2Sweep)) return false;
        self->sweepA = *(b2Sweep*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2TOIInput__get_sweepB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2TOIInput* self = py_touserdata(argv);
    do {
        b2Sweep* ud = py_newobject(py_retval(), tp_user_b2Sweep, 0, sizeof(b2Sweep));
        *ud = self->sweepB;
    } while(0);
    return true;
}
static bool b2TOIInput__set_sweepB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2TOIInput* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2Sweep)) return false;
        self->sweepB = *(b2Sweep*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2TOIInput__get_tMax(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2TOIInput* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->tMax);
    return true;
}
static bool b2TOIInput__set_tMax(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2TOIInput* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->tMax)) return false;
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2TOIInput(py_GlobalRef mod) {
    py_Type type = py_newtype("b2TOIInput", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2TOIInput__new__);
    py_bindmagic(type, __init__, b2TOIInput__init__);
    py_bindmethod(type, "copy", b2TOIInput__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "proxyA", b2TOIInput__get_proxyA, b2TOIInput__set_proxyA);
    py_bindproperty(type, "proxyB", b2TOIInput__get_proxyB, b2TOIInput__set_proxyB);
    py_bindproperty(type, "sweepA", b2TOIInput__get_sweepA, b2TOIInput__set_sweepA);
    py_bindproperty(type, "sweepB", b2TOIInput__get_sweepB, b2TOIInput__set_sweepB);
    py_bindproperty(type, "tMax", b2TOIInput__get_tMax, b2TOIInput__set_tMax);
    return type;
}
static py_Type tp_user_b2TOIInput;
static bool b2TOIOutput__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2TOIOutput));
    return true;
}
static bool b2TOIOutput__init__(int argc, py_Ref argv) {
    b2TOIOutput* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2TOIOutput));
    } else if(argc == 1 + 2) {
        if(!py_checkint(py_arg(1))) return false;
        self->state = (b2TOIState)py_toint(py_arg(1));
        if(!py_castfloat32(py_arg(2), &self->t)) return false;
    } else {
        return TypeError("expected 1 or 3 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2TOIOutput__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2TOIOutput* self = py_touserdata(argv);
    b2TOIOutput* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2TOIOutput));
    *res = *self;
    return true;
}
static bool b2TOIOutput__get_state(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2TOIOutput* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->state);
    return true;
}
static bool b2TOIOutput__set_state(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2TOIOutput* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->state = (b2TOIState)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2TOIOutput__get_t(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2TOIOutput* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->t);
    return true;
}
static bool b2TOIOutput__set_t(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2TOIOutput* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->t)) return false;
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2TOIOutput(py_GlobalRef mod) {
    py_Type type = py_newtype("b2TOIOutput", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2TOIOutput__new__);
    py_bindmagic(type, __init__, b2TOIOutput__init__);
    py_bindmethod(type, "copy", b2TOIOutput__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "state", b2TOIOutput__get_state, b2TOIOutput__set_state);
    py_bindproperty(type, "t", b2TOIOutput__get_t, b2TOIOutput__set_t);
    return type;
}
static py_Type tp_user_b2TOIOutput;
static bool b2ManifoldPoint__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2ManifoldPoint));
    return true;
}
static bool b2ManifoldPoint__init__(int argc, py_Ref argv) {
    b2ManifoldPoint* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2ManifoldPoint));
    } else if(argc == 1 + 10) {
        do {
            if(!py_checktype(py_arg(1), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(1));
            self->point = *(b2Vec2*)(&tmp);
        } while(0);
        do {
            if(!py_checktype(py_arg(2), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(2));
            self->anchorA = *(b2Vec2*)(&tmp);
        } while(0);
        do {
            if(!py_checktype(py_arg(3), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(3));
            self->anchorB = *(b2Vec2*)(&tmp);
        } while(0);
        if(!py_castfloat32(py_arg(4), &self->separation)) return false;
        if(!py_castfloat32(py_arg(5), &self->normalImpulse)) return false;
        if(!py_castfloat32(py_arg(6), &self->tangentImpulse)) return false;
        if(!py_castfloat32(py_arg(7), &self->maxNormalImpulse)) return false;
        if(!py_castfloat32(py_arg(8), &self->normalVelocity)) return false;
        if(!py_checkint(py_arg(9))) return false;
        self->id = py_toint(py_arg(9));
        if(!py_checkbool(py_arg(10))) return false;
        self->persisted = py_tobool(py_arg(10));
    } else {
        return TypeError("expected 1 or 11 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2ManifoldPoint__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ManifoldPoint* self = py_touserdata(argv);
    b2ManifoldPoint* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2ManifoldPoint));
    *res = *self;
    return true;
}
static bool b2ManifoldPoint__get_point(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ManifoldPoint* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->point));
    return true;
}
static bool b2ManifoldPoint__set_point(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ManifoldPoint* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->point = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2ManifoldPoint__get_anchorA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ManifoldPoint* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->anchorA));
    return true;
}
static bool b2ManifoldPoint__set_anchorA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ManifoldPoint* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->anchorA = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2ManifoldPoint__get_anchorB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ManifoldPoint* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->anchorB));
    return true;
}
static bool b2ManifoldPoint__set_anchorB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ManifoldPoint* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->anchorB = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2ManifoldPoint__get_separation(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ManifoldPoint* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->separation);
    return true;
}
static bool b2ManifoldPoint__set_separation(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ManifoldPoint* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->separation)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2ManifoldPoint__get_normalImpulse(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ManifoldPoint* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->normalImpulse);
    return true;
}
static bool b2ManifoldPoint__set_normalImpulse(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ManifoldPoint* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->normalImpulse)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2ManifoldPoint__get_tangentImpulse(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ManifoldPoint* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->tangentImpulse);
    return true;
}
static bool b2ManifoldPoint__set_tangentImpulse(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ManifoldPoint* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->tangentImpulse)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2ManifoldPoint__get_maxNormalImpulse(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ManifoldPoint* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->maxNormalImpulse);
    return true;
}
static bool b2ManifoldPoint__set_maxNormalImpulse(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ManifoldPoint* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->maxNormalImpulse)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2ManifoldPoint__get_normalVelocity(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ManifoldPoint* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->normalVelocity);
    return true;
}
static bool b2ManifoldPoint__set_normalVelocity(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ManifoldPoint* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->normalVelocity)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2ManifoldPoint__get_id(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ManifoldPoint* self = py_touserdata(argv);
    py_newint(py_retval(), self->id);
    return true;
}
static bool b2ManifoldPoint__set_id(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ManifoldPoint* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->id = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2ManifoldPoint__get_persisted(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ManifoldPoint* self = py_touserdata(argv);
    py_newbool(py_retval(), self->persisted);
    return true;
}
static bool b2ManifoldPoint__set_persisted(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ManifoldPoint* self = py_touserdata(argv);
    if(!py_checkbool(py_arg(1))) return false;
    self->persisted = py_tobool(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2ManifoldPoint(py_GlobalRef mod) {
    py_Type type = py_newtype("b2ManifoldPoint", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2ManifoldPoint__new__);
    py_bindmagic(type, __init__, b2ManifoldPoint__init__);
    py_bindmethod(type, "copy", b2ManifoldPoint__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "point", b2ManifoldPoint__get_point, b2ManifoldPoint__set_point);
    py_bindproperty(type, "anchorA", b2ManifoldPoint__get_anchorA, b2ManifoldPoint__set_anchorA);
    py_bindproperty(type, "anchorB", b2ManifoldPoint__get_anchorB, b2ManifoldPoint__set_anchorB);
    py_bindproperty(type, "separation", b2ManifoldPoint__get_separation, b2ManifoldPoint__set_separation);
    py_bindproperty(type, "normalImpulse", b2ManifoldPoint__get_normalImpulse, b2ManifoldPoint__set_normalImpulse);
    py_bindproperty(type, "tangentImpulse", b2ManifoldPoint__get_tangentImpulse, b2ManifoldPoint__set_tangentImpulse);
    py_bindproperty(type, "maxNormalImpulse", b2ManifoldPoint__get_maxNormalImpulse, b2ManifoldPoint__set_maxNormalImpulse);
    py_bindproperty(type, "normalVelocity", b2ManifoldPoint__get_normalVelocity, b2ManifoldPoint__set_normalVelocity);
    py_bindproperty(type, "id", b2ManifoldPoint__get_id, b2ManifoldPoint__set_id);
    py_bindproperty(type, "persisted", b2ManifoldPoint__get_persisted, b2ManifoldPoint__set_persisted);
    return type;
}
static py_Type tp_user_b2ManifoldPoint;
static bool b2Manifold__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2Manifold));
    return true;
}
static bool b2Manifold__init__(int argc, py_Ref argv) {
    b2Manifold* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2Manifold));
    } else if(argc == 1 + 3) {
        // _0 points is read-only
        do {
            if(!py_checktype(py_arg(2), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(2));
            self->normal = *(b2Vec2*)(&tmp);
        } while(0);
        if(!py_checkint(py_arg(3))) return false;
        self->pointCount = py_toint(py_arg(3));
    } else {
        return TypeError("expected 1 or 4 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2Manifold__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Manifold* self = py_touserdata(argv);
    b2Manifold* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2Manifold));
    *res = *self;
    return true;
}
static bool b2Manifold__get_points(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Manifold* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->points);
    return true;
}
static bool b2Manifold__get_normal(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Manifold* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->normal));
    return true;
}
static bool b2Manifold__set_normal(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Manifold* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->normal = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2Manifold__get_pointCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Manifold* self = py_touserdata(argv);
    py_newint(py_retval(), self->pointCount);
    return true;
}
static bool b2Manifold__set_pointCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Manifold* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->pointCount = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2Manifold(py_GlobalRef mod) {
    py_Type type = py_newtype("b2Manifold", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2Manifold__new__);
    py_bindmagic(type, __init__, b2Manifold__init__);
    py_bindmethod(type, "copy", b2Manifold__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "points", b2Manifold__get_points, NULL);
    py_bindproperty(type, "normal", b2Manifold__get_normal, b2Manifold__set_normal);
    py_bindproperty(type, "pointCount", b2Manifold__get_pointCount, b2Manifold__set_pointCount);
    return type;
}
static py_Type tp_user_b2Manifold;
static bool b2TreeNode__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2TreeNode));
    return true;
}
static bool b2TreeNode__init__(int argc, py_Ref argv) {
    b2TreeNode* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2TreeNode));
    } else if(argc == 1 + 8) {
        do {
            if(!py_checktype(py_arg(1), tp_user_b2AABB)) return false;
            self->aabb = *(b2AABB*)py_touserdata(py_arg(1));
        } while(0);
        if(!py_checkint(py_arg(2))) return false;
        self->categoryBits = py_toint(py_arg(2));
        if(!py_checkint(py_arg(3))) return false;
        self->child1 = py_toint(py_arg(3));
        if(!py_checkint(py_arg(4))) return false;
        self->child2 = py_toint(py_arg(4));
        if(!py_checkint(py_arg(5))) return false;
        self->userData = py_toint(py_arg(5));
        if(!py_checkint(py_arg(6))) return false;
        self->height = py_toint(py_arg(6));
        if(!py_checkbool(py_arg(7))) return false;
        self->enlarged = py_tobool(py_arg(7));
        // _7 pad is read-only
    } else {
        return TypeError("expected 1 or 9 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2TreeNode__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2TreeNode* self = py_touserdata(argv);
    b2TreeNode* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2TreeNode));
    *res = *self;
    return true;
}
static bool b2TreeNode__get_aabb(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2TreeNode* self = py_touserdata(argv);
    do {
        b2AABB* ud = py_newobject(py_retval(), tp_user_b2AABB, 0, sizeof(b2AABB));
        *ud = self->aabb;
    } while(0);
    return true;
}
static bool b2TreeNode__set_aabb(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2TreeNode* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2AABB)) return false;
        self->aabb = *(b2AABB*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2TreeNode__get_categoryBits(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2TreeNode* self = py_touserdata(argv);
    py_newint(py_retval(), self->categoryBits);
    return true;
}
static bool b2TreeNode__set_categoryBits(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2TreeNode* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->categoryBits = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2TreeNode__get_child1(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2TreeNode* self = py_touserdata(argv);
    py_newint(py_retval(), self->child1);
    return true;
}
static bool b2TreeNode__set_child1(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2TreeNode* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->child1 = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2TreeNode__get_child2(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2TreeNode* self = py_touserdata(argv);
    py_newint(py_retval(), self->child2);
    return true;
}
static bool b2TreeNode__set_child2(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2TreeNode* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->child2 = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2TreeNode__get_userData(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2TreeNode* self = py_touserdata(argv);
    py_newint(py_retval(), self->userData);
    return true;
}
static bool b2TreeNode__set_userData(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2TreeNode* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->userData = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2TreeNode__get_height(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2TreeNode* self = py_touserdata(argv);
    py_newint(py_retval(), self->height);
    return true;
}
static bool b2TreeNode__set_height(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2TreeNode* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->height = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2TreeNode__get_enlarged(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2TreeNode* self = py_touserdata(argv);
    py_newbool(py_retval(), self->enlarged);
    return true;
}
static bool b2TreeNode__set_enlarged(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2TreeNode* self = py_touserdata(argv);
    if(!py_checkbool(py_arg(1))) return false;
    self->enlarged = py_tobool(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2TreeNode__get_pad(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2TreeNode* self = py_touserdata(argv);
    py_newstr(py_retval(), self->pad);
    return true;
}
static py_Type register__b2TreeNode(py_GlobalRef mod) {
    py_Type type = py_newtype("b2TreeNode", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2TreeNode__new__);
    py_bindmagic(type, __init__, b2TreeNode__init__);
    py_bindmethod(type, "copy", b2TreeNode__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "aabb", b2TreeNode__get_aabb, b2TreeNode__set_aabb);
    py_bindproperty(type, "categoryBits", b2TreeNode__get_categoryBits, b2TreeNode__set_categoryBits);
    py_bindproperty(type, "child1", b2TreeNode__get_child1, b2TreeNode__set_child1);
    py_bindproperty(type, "child2", b2TreeNode__get_child2, b2TreeNode__set_child2);
    py_bindproperty(type, "userData", b2TreeNode__get_userData, b2TreeNode__set_userData);
    py_bindproperty(type, "height", b2TreeNode__get_height, b2TreeNode__set_height);
    py_bindproperty(type, "enlarged", b2TreeNode__get_enlarged, b2TreeNode__set_enlarged);
    py_bindproperty(type, "pad", b2TreeNode__get_pad, NULL);
    return type;
}
static py_Type tp_user_b2TreeNode;
static bool b2DynamicTree__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2DynamicTree));
    return true;
}
static bool b2DynamicTree__init__(int argc, py_Ref argv) {
    b2DynamicTree* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2DynamicTree));
    } else if(argc == 1 + 11) {
        if(!py_checkint(py_arg(1))) return false;
        self->nodes = (b2TreeNode*)py_toint(py_arg(1));
        if(!py_checkint(py_arg(2))) return false;
        self->root = py_toint(py_arg(2));
        if(!py_checkint(py_arg(3))) return false;
        self->nodeCount = py_toint(py_arg(3));
        if(!py_checkint(py_arg(4))) return false;
        self->nodeCapacity = py_toint(py_arg(4));
        if(!py_checkint(py_arg(5))) return false;
        self->freeList = py_toint(py_arg(5));
        if(!py_checkint(py_arg(6))) return false;
        self->proxyCount = py_toint(py_arg(6));
        if(!py_checkint(py_arg(7))) return false;
        self->leafIndices = (int*)py_toint(py_arg(7));
        if(!py_checkint(py_arg(8))) return false;
        self->leafBoxes = (b2AABB*)py_toint(py_arg(8));
        if(!py_checkint(py_arg(9))) return false;
        self->leafCenters = (b2Vec2*)py_toint(py_arg(9));
        if(!py_checkint(py_arg(10))) return false;
        self->binIndices = (int*)py_toint(py_arg(10));
        if(!py_checkint(py_arg(11))) return false;
        self->rebuildCapacity = py_toint(py_arg(11));
    } else {
        return TypeError("expected 1 or 12 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2DynamicTree__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DynamicTree* self = py_touserdata(argv);
    b2DynamicTree* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2DynamicTree));
    *res = *self;
    return true;
}
static bool b2DynamicTree__get_nodes(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DynamicTree* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->nodes);
    return true;
}
static bool b2DynamicTree__set_nodes(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2DynamicTree* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->nodes = (b2TreeNode*)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2DynamicTree__get_root(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DynamicTree* self = py_touserdata(argv);
    py_newint(py_retval(), self->root);
    return true;
}
static bool b2DynamicTree__set_root(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2DynamicTree* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->root = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2DynamicTree__get_nodeCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DynamicTree* self = py_touserdata(argv);
    py_newint(py_retval(), self->nodeCount);
    return true;
}
static bool b2DynamicTree__set_nodeCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2DynamicTree* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->nodeCount = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2DynamicTree__get_nodeCapacity(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DynamicTree* self = py_touserdata(argv);
    py_newint(py_retval(), self->nodeCapacity);
    return true;
}
static bool b2DynamicTree__set_nodeCapacity(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2DynamicTree* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->nodeCapacity = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2DynamicTree__get_freeList(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DynamicTree* self = py_touserdata(argv);
    py_newint(py_retval(), self->freeList);
    return true;
}
static bool b2DynamicTree__set_freeList(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2DynamicTree* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->freeList = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2DynamicTree__get_proxyCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DynamicTree* self = py_touserdata(argv);
    py_newint(py_retval(), self->proxyCount);
    return true;
}
static bool b2DynamicTree__set_proxyCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2DynamicTree* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->proxyCount = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2DynamicTree__get_leafIndices(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DynamicTree* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->leafIndices);
    return true;
}
static bool b2DynamicTree__set_leafIndices(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2DynamicTree* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->leafIndices = (int*)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2DynamicTree__get_leafBoxes(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DynamicTree* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->leafBoxes);
    return true;
}
static bool b2DynamicTree__set_leafBoxes(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2DynamicTree* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->leafBoxes = (b2AABB*)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2DynamicTree__get_leafCenters(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DynamicTree* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->leafCenters);
    return true;
}
static bool b2DynamicTree__set_leafCenters(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2DynamicTree* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->leafCenters = (b2Vec2*)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2DynamicTree__get_binIndices(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DynamicTree* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->binIndices);
    return true;
}
static bool b2DynamicTree__set_binIndices(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2DynamicTree* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->binIndices = (int*)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2DynamicTree__get_rebuildCapacity(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DynamicTree* self = py_touserdata(argv);
    py_newint(py_retval(), self->rebuildCapacity);
    return true;
}
static bool b2DynamicTree__set_rebuildCapacity(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2DynamicTree* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->rebuildCapacity = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2DynamicTree(py_GlobalRef mod) {
    py_Type type = py_newtype("b2DynamicTree", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2DynamicTree__new__);
    py_bindmagic(type, __init__, b2DynamicTree__init__);
    py_bindmethod(type, "copy", b2DynamicTree__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "nodes", b2DynamicTree__get_nodes, b2DynamicTree__set_nodes);
    py_bindproperty(type, "root", b2DynamicTree__get_root, b2DynamicTree__set_root);
    py_bindproperty(type, "nodeCount", b2DynamicTree__get_nodeCount, b2DynamicTree__set_nodeCount);
    py_bindproperty(type, "nodeCapacity", b2DynamicTree__get_nodeCapacity, b2DynamicTree__set_nodeCapacity);
    py_bindproperty(type, "freeList", b2DynamicTree__get_freeList, b2DynamicTree__set_freeList);
    py_bindproperty(type, "proxyCount", b2DynamicTree__get_proxyCount, b2DynamicTree__set_proxyCount);
    py_bindproperty(type, "leafIndices", b2DynamicTree__get_leafIndices, b2DynamicTree__set_leafIndices);
    py_bindproperty(type, "leafBoxes", b2DynamicTree__get_leafBoxes, b2DynamicTree__set_leafBoxes);
    py_bindproperty(type, "leafCenters", b2DynamicTree__get_leafCenters, b2DynamicTree__set_leafCenters);
    py_bindproperty(type, "binIndices", b2DynamicTree__get_binIndices, b2DynamicTree__set_binIndices);
    py_bindproperty(type, "rebuildCapacity", b2DynamicTree__get_rebuildCapacity, b2DynamicTree__set_rebuildCapacity);
    return type;
}
static py_Type tp_user_b2DynamicTree;
static bool b2WorldId__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2WorldId));
    return true;
}
static bool b2WorldId__init__(int argc, py_Ref argv) {
    b2WorldId* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2WorldId));
    } else if(argc == 1 + 2) {
        if(!py_checkint(py_arg(1))) return false;
        self->index1 = py_toint(py_arg(1));
        if(!py_checkint(py_arg(2))) return false;
        self->revision = py_toint(py_arg(2));
    } else {
        return TypeError("expected 1 or 3 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2WorldId__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WorldId* self = py_touserdata(argv);
    b2WorldId* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2WorldId));
    *res = *self;
    return true;
}
static bool b2WorldId__get_index1(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WorldId* self = py_touserdata(argv);
    py_newint(py_retval(), self->index1);
    return true;
}
static bool b2WorldId__set_index1(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WorldId* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->index1 = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2WorldId__get_revision(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WorldId* self = py_touserdata(argv);
    py_newint(py_retval(), self->revision);
    return true;
}
static bool b2WorldId__set_revision(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WorldId* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->revision = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2WorldId(py_GlobalRef mod) {
    py_Type type = py_newtype("b2WorldId", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2WorldId__new__);
    py_bindmagic(type, __init__, b2WorldId__init__);
    py_bindmethod(type, "copy", b2WorldId__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "index1", b2WorldId__get_index1, b2WorldId__set_index1);
    py_bindproperty(type, "revision", b2WorldId__get_revision, b2WorldId__set_revision);
    return type;
}
static py_Type tp_user_b2WorldId;
static bool b2BodyId__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2BodyId));
    return true;
}
static bool b2BodyId__init__(int argc, py_Ref argv) {
    b2BodyId* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2BodyId));
    } else if(argc == 1 + 3) {
        if(!py_checkint(py_arg(1))) return false;
        self->index1 = py_toint(py_arg(1));
        if(!py_checkint(py_arg(2))) return false;
        self->world0 = py_toint(py_arg(2));
        if(!py_checkint(py_arg(3))) return false;
        self->revision = py_toint(py_arg(3));
    } else {
        return TypeError("expected 1 or 4 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2BodyId__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2BodyId* self = py_touserdata(argv);
    b2BodyId* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2BodyId));
    *res = *self;
    return true;
}
static bool b2BodyId__get_index1(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2BodyId* self = py_touserdata(argv);
    py_newint(py_retval(), self->index1);
    return true;
}
static bool b2BodyId__set_index1(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2BodyId* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->index1 = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2BodyId__get_world0(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2BodyId* self = py_touserdata(argv);
    py_newint(py_retval(), self->world0);
    return true;
}
static bool b2BodyId__set_world0(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2BodyId* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->world0 = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2BodyId__get_revision(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2BodyId* self = py_touserdata(argv);
    py_newint(py_retval(), self->revision);
    return true;
}
static bool b2BodyId__set_revision(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2BodyId* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->revision = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2BodyId(py_GlobalRef mod) {
    py_Type type = py_newtype("b2BodyId", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2BodyId__new__);
    py_bindmagic(type, __init__, b2BodyId__init__);
    py_bindmethod(type, "copy", b2BodyId__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "index1", b2BodyId__get_index1, b2BodyId__set_index1);
    py_bindproperty(type, "world0", b2BodyId__get_world0, b2BodyId__set_world0);
    py_bindproperty(type, "revision", b2BodyId__get_revision, b2BodyId__set_revision);
    return type;
}
static py_Type tp_user_b2BodyId;
static bool b2ShapeId__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2ShapeId));
    return true;
}
static bool b2ShapeId__init__(int argc, py_Ref argv) {
    b2ShapeId* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2ShapeId));
    } else if(argc == 1 + 3) {
        if(!py_checkint(py_arg(1))) return false;
        self->index1 = py_toint(py_arg(1));
        if(!py_checkint(py_arg(2))) return false;
        self->world0 = py_toint(py_arg(2));
        if(!py_checkint(py_arg(3))) return false;
        self->revision = py_toint(py_arg(3));
    } else {
        return TypeError("expected 1 or 4 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2ShapeId__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ShapeId* self = py_touserdata(argv);
    b2ShapeId* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2ShapeId));
    *res = *self;
    return true;
}
static bool b2ShapeId__get_index1(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ShapeId* self = py_touserdata(argv);
    py_newint(py_retval(), self->index1);
    return true;
}
static bool b2ShapeId__set_index1(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ShapeId* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->index1 = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2ShapeId__get_world0(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ShapeId* self = py_touserdata(argv);
    py_newint(py_retval(), self->world0);
    return true;
}
static bool b2ShapeId__set_world0(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ShapeId* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->world0 = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2ShapeId__get_revision(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ShapeId* self = py_touserdata(argv);
    py_newint(py_retval(), self->revision);
    return true;
}
static bool b2ShapeId__set_revision(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ShapeId* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->revision = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2ShapeId(py_GlobalRef mod) {
    py_Type type = py_newtype("b2ShapeId", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2ShapeId__new__);
    py_bindmagic(type, __init__, b2ShapeId__init__);
    py_bindmethod(type, "copy", b2ShapeId__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "index1", b2ShapeId__get_index1, b2ShapeId__set_index1);
    py_bindproperty(type, "world0", b2ShapeId__get_world0, b2ShapeId__set_world0);
    py_bindproperty(type, "revision", b2ShapeId__get_revision, b2ShapeId__set_revision);
    return type;
}
static py_Type tp_user_b2ShapeId;
static bool b2JointId__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2JointId));
    return true;
}
static bool b2JointId__init__(int argc, py_Ref argv) {
    b2JointId* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2JointId));
    } else if(argc == 1 + 3) {
        if(!py_checkint(py_arg(1))) return false;
        self->index1 = py_toint(py_arg(1));
        if(!py_checkint(py_arg(2))) return false;
        self->world0 = py_toint(py_arg(2));
        if(!py_checkint(py_arg(3))) return false;
        self->revision = py_toint(py_arg(3));
    } else {
        return TypeError("expected 1 or 4 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2JointId__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2JointId* self = py_touserdata(argv);
    b2JointId* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2JointId));
    *res = *self;
    return true;
}
static bool b2JointId__get_index1(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2JointId* self = py_touserdata(argv);
    py_newint(py_retval(), self->index1);
    return true;
}
static bool b2JointId__set_index1(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2JointId* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->index1 = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2JointId__get_world0(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2JointId* self = py_touserdata(argv);
    py_newint(py_retval(), self->world0);
    return true;
}
static bool b2JointId__set_world0(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2JointId* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->world0 = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2JointId__get_revision(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2JointId* self = py_touserdata(argv);
    py_newint(py_retval(), self->revision);
    return true;
}
static bool b2JointId__set_revision(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2JointId* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->revision = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2JointId(py_GlobalRef mod) {
    py_Type type = py_newtype("b2JointId", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2JointId__new__);
    py_bindmagic(type, __init__, b2JointId__init__);
    py_bindmethod(type, "copy", b2JointId__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "index1", b2JointId__get_index1, b2JointId__set_index1);
    py_bindproperty(type, "world0", b2JointId__get_world0, b2JointId__set_world0);
    py_bindproperty(type, "revision", b2JointId__get_revision, b2JointId__set_revision);
    return type;
}
static py_Type tp_user_b2JointId;
static bool b2ChainId__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2ChainId));
    return true;
}
static bool b2ChainId__init__(int argc, py_Ref argv) {
    b2ChainId* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2ChainId));
    } else if(argc == 1 + 3) {
        if(!py_checkint(py_arg(1))) return false;
        self->index1 = py_toint(py_arg(1));
        if(!py_checkint(py_arg(2))) return false;
        self->world0 = py_toint(py_arg(2));
        if(!py_checkint(py_arg(3))) return false;
        self->revision = py_toint(py_arg(3));
    } else {
        return TypeError("expected 1 or 4 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2ChainId__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ChainId* self = py_touserdata(argv);
    b2ChainId* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2ChainId));
    *res = *self;
    return true;
}
static bool b2ChainId__get_index1(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ChainId* self = py_touserdata(argv);
    py_newint(py_retval(), self->index1);
    return true;
}
static bool b2ChainId__set_index1(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ChainId* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->index1 = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2ChainId__get_world0(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ChainId* self = py_touserdata(argv);
    py_newint(py_retval(), self->world0);
    return true;
}
static bool b2ChainId__set_world0(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ChainId* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->world0 = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2ChainId__get_revision(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ChainId* self = py_touserdata(argv);
    py_newint(py_retval(), self->revision);
    return true;
}
static bool b2ChainId__set_revision(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ChainId* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->revision = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2ChainId(py_GlobalRef mod) {
    py_Type type = py_newtype("b2ChainId", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2ChainId__new__);
    py_bindmagic(type, __init__, b2ChainId__init__);
    py_bindmethod(type, "copy", b2ChainId__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "index1", b2ChainId__get_index1, b2ChainId__set_index1);
    py_bindproperty(type, "world0", b2ChainId__get_world0, b2ChainId__set_world0);
    py_bindproperty(type, "revision", b2ChainId__get_revision, b2ChainId__set_revision);
    return type;
}
static py_Type tp_user_b2ChainId;
static bool b2RayResult__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2RayResult));
    return true;
}
static bool b2RayResult__init__(int argc, py_Ref argv) {
    b2RayResult* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2RayResult));
    } else if(argc == 1 + 5) {
        do {
            if(!py_checktype(py_arg(1), tp_user_b2ShapeId)) return false;
            self->shapeId = *(b2ShapeId*)py_touserdata(py_arg(1));
        } while(0);
        do {
            if(!py_checktype(py_arg(2), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(2));
            self->point = *(b2Vec2*)(&tmp);
        } while(0);
        do {
            if(!py_checktype(py_arg(3), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(3));
            self->normal = *(b2Vec2*)(&tmp);
        } while(0);
        if(!py_castfloat32(py_arg(4), &self->fraction)) return false;
        if(!py_checkbool(py_arg(5))) return false;
        self->hit = py_tobool(py_arg(5));
    } else {
        return TypeError("expected 1 or 6 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2RayResult__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2RayResult* self = py_touserdata(argv);
    b2RayResult* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2RayResult));
    *res = *self;
    return true;
}
static bool b2RayResult__get_shapeId(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2RayResult* self = py_touserdata(argv);
    do {
        b2ShapeId* ud = py_newobject(py_retval(), tp_user_b2ShapeId, 0, sizeof(b2ShapeId));
        *ud = self->shapeId;
    } while(0);
    return true;
}
static bool b2RayResult__set_shapeId(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2RayResult* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2ShapeId)) return false;
        self->shapeId = *(b2ShapeId*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2RayResult__get_point(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2RayResult* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->point));
    return true;
}
static bool b2RayResult__set_point(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2RayResult* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->point = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2RayResult__get_normal(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2RayResult* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->normal));
    return true;
}
static bool b2RayResult__set_normal(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2RayResult* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->normal = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2RayResult__get_fraction(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2RayResult* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->fraction);
    return true;
}
static bool b2RayResult__set_fraction(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2RayResult* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->fraction)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2RayResult__get_hit(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2RayResult* self = py_touserdata(argv);
    py_newbool(py_retval(), self->hit);
    return true;
}
static bool b2RayResult__set_hit(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2RayResult* self = py_touserdata(argv);
    if(!py_checkbool(py_arg(1))) return false;
    self->hit = py_tobool(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2RayResult(py_GlobalRef mod) {
    py_Type type = py_newtype("b2RayResult", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2RayResult__new__);
    py_bindmagic(type, __init__, b2RayResult__init__);
    py_bindmethod(type, "copy", b2RayResult__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "shapeId", b2RayResult__get_shapeId, b2RayResult__set_shapeId);
    py_bindproperty(type, "point", b2RayResult__get_point, b2RayResult__set_point);
    py_bindproperty(type, "normal", b2RayResult__get_normal, b2RayResult__set_normal);
    py_bindproperty(type, "fraction", b2RayResult__get_fraction, b2RayResult__set_fraction);
    py_bindproperty(type, "hit", b2RayResult__get_hit, b2RayResult__set_hit);
    return type;
}
static py_Type tp_user_b2RayResult;
static bool b2WorldDef__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2WorldDef));
    return true;
}
static bool b2WorldDef__init__(int argc, py_Ref argv) {
    b2WorldDef* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2WorldDef));
    } else if(argc == 1 + 16) {
        do {
            if(!py_checktype(py_arg(1), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(1));
            self->gravity = *(b2Vec2*)(&tmp);
        } while(0);
        if(!py_castfloat32(py_arg(2), &self->restitutionThreshold)) return false;
        if(!py_castfloat32(py_arg(3), &self->contactPushoutVelocity)) return false;
        if(!py_castfloat32(py_arg(4), &self->hitEventThreshold)) return false;
        if(!py_castfloat32(py_arg(5), &self->contactHertz)) return false;
        if(!py_castfloat32(py_arg(6), &self->contactDampingRatio)) return false;
        if(!py_castfloat32(py_arg(7), &self->jointHertz)) return false;
        if(!py_castfloat32(py_arg(8), &self->jointDampingRatio)) return false;
        if(!py_castfloat32(py_arg(9), &self->maximumLinearVelocity)) return false;
        if(!py_checkbool(py_arg(10))) return false;
        self->enableSleep = py_tobool(py_arg(10));
        if(!py_checkbool(py_arg(11))) return false;
        self->enableContinuous = py_tobool(py_arg(11));
        if(!py_checkint(py_arg(12))) return false;
        self->workerCount = py_toint(py_arg(12));
        if(!py_checkint(py_arg(13))) return false;
        self->enqueueTask = (b2EnqueueTaskCallback*)py_toint(py_arg(13));
        if(!py_checkint(py_arg(14))) return false;
        self->finishTask = (b2FinishTaskCallback*)py_toint(py_arg(14));
        if(!py_checkint(py_arg(15))) return false;
        self->userTaskContext = (void*)py_toint(py_arg(15));
        if(!py_checkint(py_arg(16))) return false;
        self->internalValue = py_toint(py_arg(16));
    } else {
        return TypeError("expected 1 or 17 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2WorldDef__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WorldDef* self = py_touserdata(argv);
    b2WorldDef* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2WorldDef));
    *res = *self;
    return true;
}
static bool b2WorldDef__get_gravity(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WorldDef* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->gravity));
    return true;
}
static bool b2WorldDef__set_gravity(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WorldDef* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->gravity = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2WorldDef__get_restitutionThreshold(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WorldDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->restitutionThreshold);
    return true;
}
static bool b2WorldDef__set_restitutionThreshold(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WorldDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->restitutionThreshold)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2WorldDef__get_contactPushoutVelocity(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WorldDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->contactPushoutVelocity);
    return true;
}
static bool b2WorldDef__set_contactPushoutVelocity(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WorldDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->contactPushoutVelocity)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2WorldDef__get_hitEventThreshold(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WorldDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->hitEventThreshold);
    return true;
}
static bool b2WorldDef__set_hitEventThreshold(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WorldDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->hitEventThreshold)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2WorldDef__get_contactHertz(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WorldDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->contactHertz);
    return true;
}
static bool b2WorldDef__set_contactHertz(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WorldDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->contactHertz)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2WorldDef__get_contactDampingRatio(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WorldDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->contactDampingRatio);
    return true;
}
static bool b2WorldDef__set_contactDampingRatio(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WorldDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->contactDampingRatio)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2WorldDef__get_jointHertz(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WorldDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->jointHertz);
    return true;
}
static bool b2WorldDef__set_jointHertz(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WorldDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->jointHertz)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2WorldDef__get_jointDampingRatio(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WorldDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->jointDampingRatio);
    return true;
}
static bool b2WorldDef__set_jointDampingRatio(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WorldDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->jointDampingRatio)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2WorldDef__get_maximumLinearVelocity(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WorldDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->maximumLinearVelocity);
    return true;
}
static bool b2WorldDef__set_maximumLinearVelocity(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WorldDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->maximumLinearVelocity)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2WorldDef__get_enableSleep(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WorldDef* self = py_touserdata(argv);
    py_newbool(py_retval(), self->enableSleep);
    return true;
}
static bool b2WorldDef__set_enableSleep(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WorldDef* self = py_touserdata(argv);
    if(!py_checkbool(py_arg(1))) return false;
    self->enableSleep = py_tobool(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2WorldDef__get_enableContinuous(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WorldDef* self = py_touserdata(argv);
    py_newbool(py_retval(), self->enableContinuous);
    return true;
}
static bool b2WorldDef__set_enableContinuous(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WorldDef* self = py_touserdata(argv);
    if(!py_checkbool(py_arg(1))) return false;
    self->enableContinuous = py_tobool(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2WorldDef__get_workerCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WorldDef* self = py_touserdata(argv);
    py_newint(py_retval(), self->workerCount);
    return true;
}
static bool b2WorldDef__set_workerCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WorldDef* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->workerCount = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2WorldDef__get_enqueueTask(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WorldDef* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->enqueueTask);
    return true;
}
static bool b2WorldDef__set_enqueueTask(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WorldDef* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->enqueueTask = (b2EnqueueTaskCallback*)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2WorldDef__get_finishTask(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WorldDef* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->finishTask);
    return true;
}
static bool b2WorldDef__set_finishTask(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WorldDef* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->finishTask = (b2FinishTaskCallback*)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2WorldDef__get_userTaskContext(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WorldDef* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->userTaskContext);
    return true;
}
static bool b2WorldDef__set_userTaskContext(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WorldDef* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->userTaskContext = (void*)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2WorldDef__get_internalValue(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WorldDef* self = py_touserdata(argv);
    py_newint(py_retval(), self->internalValue);
    return true;
}
static bool b2WorldDef__set_internalValue(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WorldDef* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->internalValue = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2WorldDef(py_GlobalRef mod) {
    py_Type type = py_newtype("b2WorldDef", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2WorldDef__new__);
    py_bindmagic(type, __init__, b2WorldDef__init__);
    py_bindmethod(type, "copy", b2WorldDef__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "gravity", b2WorldDef__get_gravity, b2WorldDef__set_gravity);
    py_bindproperty(type, "restitutionThreshold", b2WorldDef__get_restitutionThreshold, b2WorldDef__set_restitutionThreshold);
    py_bindproperty(type, "contactPushoutVelocity", b2WorldDef__get_contactPushoutVelocity, b2WorldDef__set_contactPushoutVelocity);
    py_bindproperty(type, "hitEventThreshold", b2WorldDef__get_hitEventThreshold, b2WorldDef__set_hitEventThreshold);
    py_bindproperty(type, "contactHertz", b2WorldDef__get_contactHertz, b2WorldDef__set_contactHertz);
    py_bindproperty(type, "contactDampingRatio", b2WorldDef__get_contactDampingRatio, b2WorldDef__set_contactDampingRatio);
    py_bindproperty(type, "jointHertz", b2WorldDef__get_jointHertz, b2WorldDef__set_jointHertz);
    py_bindproperty(type, "jointDampingRatio", b2WorldDef__get_jointDampingRatio, b2WorldDef__set_jointDampingRatio);
    py_bindproperty(type, "maximumLinearVelocity", b2WorldDef__get_maximumLinearVelocity, b2WorldDef__set_maximumLinearVelocity);
    py_bindproperty(type, "enableSleep", b2WorldDef__get_enableSleep, b2WorldDef__set_enableSleep);
    py_bindproperty(type, "enableContinuous", b2WorldDef__get_enableContinuous, b2WorldDef__set_enableContinuous);
    py_bindproperty(type, "workerCount", b2WorldDef__get_workerCount, b2WorldDef__set_workerCount);
    py_bindproperty(type, "enqueueTask", b2WorldDef__get_enqueueTask, b2WorldDef__set_enqueueTask);
    py_bindproperty(type, "finishTask", b2WorldDef__get_finishTask, b2WorldDef__set_finishTask);
    py_bindproperty(type, "userTaskContext", b2WorldDef__get_userTaskContext, b2WorldDef__set_userTaskContext);
    py_bindproperty(type, "internalValue", b2WorldDef__get_internalValue, b2WorldDef__set_internalValue);
    return type;
}
static py_Type tp_user_b2WorldDef;
static bool b2BodyDef__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2BodyDef));
    return true;
}
static bool b2BodyDef__init__(int argc, py_Ref argv) {
    b2BodyDef* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2BodyDef));
    } else if(argc == 1 + 18) {
        if(!py_checkint(py_arg(1))) return false;
        self->type = (b2BodyType)py_toint(py_arg(1));
        do {
            if(!py_checktype(py_arg(2), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(2));
            self->position = *(b2Vec2*)(&tmp);
        } while(0);
        do {
            if(!py_checktype(py_arg(3), tp_user_b2Rot)) return false;
            self->rotation = *(b2Rot*)py_touserdata(py_arg(3));
        } while(0);
        do {
            if(!py_checktype(py_arg(4), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(4));
            self->linearVelocity = *(b2Vec2*)(&tmp);
        } while(0);
        if(!py_castfloat32(py_arg(5), &self->angularVelocity)) return false;
        if(!py_castfloat32(py_arg(6), &self->linearDamping)) return false;
        if(!py_castfloat32(py_arg(7), &self->angularDamping)) return false;
        if(!py_castfloat32(py_arg(8), &self->gravityScale)) return false;
        if(!py_castfloat32(py_arg(9), &self->sleepThreshold)) return false;
        if(!py_checkint(py_arg(10))) return false;
        self->userData = (void*)py_toint(py_arg(10));
        if(!py_checkbool(py_arg(11))) return false;
        self->enableSleep = py_tobool(py_arg(11));
        if(!py_checkbool(py_arg(12))) return false;
        self->isAwake = py_tobool(py_arg(12));
        if(!py_checkbool(py_arg(13))) return false;
        self->fixedRotation = py_tobool(py_arg(13));
        if(!py_checkbool(py_arg(14))) return false;
        self->isBullet = py_tobool(py_arg(14));
        if(!py_checkbool(py_arg(15))) return false;
        self->isEnabled = py_tobool(py_arg(15));
        if(!py_checkbool(py_arg(16))) return false;
        self->automaticMass = py_tobool(py_arg(16));
        if(!py_checkbool(py_arg(17))) return false;
        self->allowFastRotation = py_tobool(py_arg(17));
        if(!py_checkint(py_arg(18))) return false;
        self->internalValue = py_toint(py_arg(18));
    } else {
        return TypeError("expected 1 or 19 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2BodyDef__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2BodyDef* self = py_touserdata(argv);
    b2BodyDef* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2BodyDef));
    *res = *self;
    return true;
}
static bool b2BodyDef__get_type(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2BodyDef* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->type);
    return true;
}
static bool b2BodyDef__set_type(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2BodyDef* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->type = (b2BodyType)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2BodyDef__get_position(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2BodyDef* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->position));
    return true;
}
static bool b2BodyDef__set_position(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2BodyDef* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->position = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2BodyDef__get_rotation(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2BodyDef* self = py_touserdata(argv);
    do {
        b2Rot* ud = py_newobject(py_retval(), tp_user_b2Rot, 0, sizeof(b2Rot));
        *ud = self->rotation;
    } while(0);
    return true;
}
static bool b2BodyDef__set_rotation(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2BodyDef* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2Rot)) return false;
        self->rotation = *(b2Rot*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2BodyDef__get_linearVelocity(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2BodyDef* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->linearVelocity));
    return true;
}
static bool b2BodyDef__set_linearVelocity(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2BodyDef* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->linearVelocity = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2BodyDef__get_angularVelocity(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2BodyDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->angularVelocity);
    return true;
}
static bool b2BodyDef__set_angularVelocity(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2BodyDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->angularVelocity)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2BodyDef__get_linearDamping(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2BodyDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->linearDamping);
    return true;
}
static bool b2BodyDef__set_linearDamping(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2BodyDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->linearDamping)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2BodyDef__get_angularDamping(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2BodyDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->angularDamping);
    return true;
}
static bool b2BodyDef__set_angularDamping(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2BodyDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->angularDamping)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2BodyDef__get_gravityScale(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2BodyDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->gravityScale);
    return true;
}
static bool b2BodyDef__set_gravityScale(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2BodyDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->gravityScale)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2BodyDef__get_sleepThreshold(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2BodyDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->sleepThreshold);
    return true;
}
static bool b2BodyDef__set_sleepThreshold(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2BodyDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->sleepThreshold)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2BodyDef__get_userData(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2BodyDef* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->userData);
    return true;
}
static bool b2BodyDef__set_userData(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2BodyDef* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->userData = (void*)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2BodyDef__get_enableSleep(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2BodyDef* self = py_touserdata(argv);
    py_newbool(py_retval(), self->enableSleep);
    return true;
}
static bool b2BodyDef__set_enableSleep(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2BodyDef* self = py_touserdata(argv);
    if(!py_checkbool(py_arg(1))) return false;
    self->enableSleep = py_tobool(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2BodyDef__get_isAwake(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2BodyDef* self = py_touserdata(argv);
    py_newbool(py_retval(), self->isAwake);
    return true;
}
static bool b2BodyDef__set_isAwake(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2BodyDef* self = py_touserdata(argv);
    if(!py_checkbool(py_arg(1))) return false;
    self->isAwake = py_tobool(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2BodyDef__get_fixedRotation(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2BodyDef* self = py_touserdata(argv);
    py_newbool(py_retval(), self->fixedRotation);
    return true;
}
static bool b2BodyDef__set_fixedRotation(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2BodyDef* self = py_touserdata(argv);
    if(!py_checkbool(py_arg(1))) return false;
    self->fixedRotation = py_tobool(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2BodyDef__get_isBullet(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2BodyDef* self = py_touserdata(argv);
    py_newbool(py_retval(), self->isBullet);
    return true;
}
static bool b2BodyDef__set_isBullet(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2BodyDef* self = py_touserdata(argv);
    if(!py_checkbool(py_arg(1))) return false;
    self->isBullet = py_tobool(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2BodyDef__get_isEnabled(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2BodyDef* self = py_touserdata(argv);
    py_newbool(py_retval(), self->isEnabled);
    return true;
}
static bool b2BodyDef__set_isEnabled(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2BodyDef* self = py_touserdata(argv);
    if(!py_checkbool(py_arg(1))) return false;
    self->isEnabled = py_tobool(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2BodyDef__get_automaticMass(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2BodyDef* self = py_touserdata(argv);
    py_newbool(py_retval(), self->automaticMass);
    return true;
}
static bool b2BodyDef__set_automaticMass(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2BodyDef* self = py_touserdata(argv);
    if(!py_checkbool(py_arg(1))) return false;
    self->automaticMass = py_tobool(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2BodyDef__get_allowFastRotation(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2BodyDef* self = py_touserdata(argv);
    py_newbool(py_retval(), self->allowFastRotation);
    return true;
}
static bool b2BodyDef__set_allowFastRotation(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2BodyDef* self = py_touserdata(argv);
    if(!py_checkbool(py_arg(1))) return false;
    self->allowFastRotation = py_tobool(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2BodyDef__get_internalValue(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2BodyDef* self = py_touserdata(argv);
    py_newint(py_retval(), self->internalValue);
    return true;
}
static bool b2BodyDef__set_internalValue(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2BodyDef* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->internalValue = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2BodyDef(py_GlobalRef mod) {
    py_Type type = py_newtype("b2BodyDef", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2BodyDef__new__);
    py_bindmagic(type, __init__, b2BodyDef__init__);
    py_bindmethod(type, "copy", b2BodyDef__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "type", b2BodyDef__get_type, b2BodyDef__set_type);
    py_bindproperty(type, "position", b2BodyDef__get_position, b2BodyDef__set_position);
    py_bindproperty(type, "rotation", b2BodyDef__get_rotation, b2BodyDef__set_rotation);
    py_bindproperty(type, "linearVelocity", b2BodyDef__get_linearVelocity, b2BodyDef__set_linearVelocity);
    py_bindproperty(type, "angularVelocity", b2BodyDef__get_angularVelocity, b2BodyDef__set_angularVelocity);
    py_bindproperty(type, "linearDamping", b2BodyDef__get_linearDamping, b2BodyDef__set_linearDamping);
    py_bindproperty(type, "angularDamping", b2BodyDef__get_angularDamping, b2BodyDef__set_angularDamping);
    py_bindproperty(type, "gravityScale", b2BodyDef__get_gravityScale, b2BodyDef__set_gravityScale);
    py_bindproperty(type, "sleepThreshold", b2BodyDef__get_sleepThreshold, b2BodyDef__set_sleepThreshold);
    py_bindproperty(type, "userData", b2BodyDef__get_userData, b2BodyDef__set_userData);
    py_bindproperty(type, "enableSleep", b2BodyDef__get_enableSleep, b2BodyDef__set_enableSleep);
    py_bindproperty(type, "isAwake", b2BodyDef__get_isAwake, b2BodyDef__set_isAwake);
    py_bindproperty(type, "fixedRotation", b2BodyDef__get_fixedRotation, b2BodyDef__set_fixedRotation);
    py_bindproperty(type, "isBullet", b2BodyDef__get_isBullet, b2BodyDef__set_isBullet);
    py_bindproperty(type, "isEnabled", b2BodyDef__get_isEnabled, b2BodyDef__set_isEnabled);
    py_bindproperty(type, "automaticMass", b2BodyDef__get_automaticMass, b2BodyDef__set_automaticMass);
    py_bindproperty(type, "allowFastRotation", b2BodyDef__get_allowFastRotation, b2BodyDef__set_allowFastRotation);
    py_bindproperty(type, "internalValue", b2BodyDef__get_internalValue, b2BodyDef__set_internalValue);
    return type;
}
static py_Type tp_user_b2BodyDef;
static bool b2Filter__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2Filter));
    return true;
}
static bool b2Filter__init__(int argc, py_Ref argv) {
    b2Filter* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2Filter));
    } else if(argc == 1 + 3) {
        if(!py_checkint(py_arg(1))) return false;
        self->categoryBits = py_toint(py_arg(1));
        if(!py_checkint(py_arg(2))) return false;
        self->maskBits = py_toint(py_arg(2));
        if(!py_checkint(py_arg(3))) return false;
        self->groupIndex = py_toint(py_arg(3));
    } else {
        return TypeError("expected 1 or 4 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2Filter__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Filter* self = py_touserdata(argv);
    b2Filter* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2Filter));
    *res = *self;
    return true;
}
static bool b2Filter__get_categoryBits(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Filter* self = py_touserdata(argv);
    py_newint(py_retval(), self->categoryBits);
    return true;
}
static bool b2Filter__set_categoryBits(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Filter* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->categoryBits = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2Filter__get_maskBits(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Filter* self = py_touserdata(argv);
    py_newint(py_retval(), self->maskBits);
    return true;
}
static bool b2Filter__set_maskBits(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Filter* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->maskBits = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2Filter__get_groupIndex(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Filter* self = py_touserdata(argv);
    py_newint(py_retval(), self->groupIndex);
    return true;
}
static bool b2Filter__set_groupIndex(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Filter* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->groupIndex = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2Filter(py_GlobalRef mod) {
    py_Type type = py_newtype("b2Filter", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2Filter__new__);
    py_bindmagic(type, __init__, b2Filter__init__);
    py_bindmethod(type, "copy", b2Filter__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "categoryBits", b2Filter__get_categoryBits, b2Filter__set_categoryBits);
    py_bindproperty(type, "maskBits", b2Filter__get_maskBits, b2Filter__set_maskBits);
    py_bindproperty(type, "groupIndex", b2Filter__get_groupIndex, b2Filter__set_groupIndex);
    return type;
}
static py_Type tp_user_b2Filter;
static bool b2QueryFilter__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2QueryFilter));
    return true;
}
static bool b2QueryFilter__init__(int argc, py_Ref argv) {
    b2QueryFilter* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2QueryFilter));
    } else if(argc == 1 + 2) {
        if(!py_checkint(py_arg(1))) return false;
        self->categoryBits = py_toint(py_arg(1));
        if(!py_checkint(py_arg(2))) return false;
        self->maskBits = py_toint(py_arg(2));
    } else {
        return TypeError("expected 1 or 3 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2QueryFilter__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2QueryFilter* self = py_touserdata(argv);
    b2QueryFilter* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2QueryFilter));
    *res = *self;
    return true;
}
static bool b2QueryFilter__get_categoryBits(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2QueryFilter* self = py_touserdata(argv);
    py_newint(py_retval(), self->categoryBits);
    return true;
}
static bool b2QueryFilter__set_categoryBits(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2QueryFilter* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->categoryBits = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2QueryFilter__get_maskBits(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2QueryFilter* self = py_touserdata(argv);
    py_newint(py_retval(), self->maskBits);
    return true;
}
static bool b2QueryFilter__set_maskBits(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2QueryFilter* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->maskBits = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2QueryFilter(py_GlobalRef mod) {
    py_Type type = py_newtype("b2QueryFilter", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2QueryFilter__new__);
    py_bindmagic(type, __init__, b2QueryFilter__init__);
    py_bindmethod(type, "copy", b2QueryFilter__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "categoryBits", b2QueryFilter__get_categoryBits, b2QueryFilter__set_categoryBits);
    py_bindproperty(type, "maskBits", b2QueryFilter__get_maskBits, b2QueryFilter__set_maskBits);
    return type;
}
static py_Type tp_user_b2QueryFilter;
static bool b2ShapeDef__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2ShapeDef));
    return true;
}
static bool b2ShapeDef__init__(int argc, py_Ref argv) {
    b2ShapeDef* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2ShapeDef));
    } else if(argc == 1 + 13) {
        if(!py_checkint(py_arg(1))) return false;
        self->userData = (void*)py_toint(py_arg(1));
        if(!py_castfloat32(py_arg(2), &self->friction)) return false;
        if(!py_castfloat32(py_arg(3), &self->restitution)) return false;
        if(!py_castfloat32(py_arg(4), &self->density)) return false;
        do {
            if(!py_checktype(py_arg(5), tp_user_b2Filter)) return false;
            self->filter = *(b2Filter*)py_touserdata(py_arg(5));
        } while(0);
        if(!py_checkint(py_arg(6))) return false;
        self->customColor = py_toint(py_arg(6));
        if(!py_checkbool(py_arg(7))) return false;
        self->isSensor = py_tobool(py_arg(7));
        if(!py_checkbool(py_arg(8))) return false;
        self->enableSensorEvents = py_tobool(py_arg(8));
        if(!py_checkbool(py_arg(9))) return false;
        self->enableContactEvents = py_tobool(py_arg(9));
        if(!py_checkbool(py_arg(10))) return false;
        self->enableHitEvents = py_tobool(py_arg(10));
        if(!py_checkbool(py_arg(11))) return false;
        self->enablePreSolveEvents = py_tobool(py_arg(11));
        if(!py_checkbool(py_arg(12))) return false;
        self->forceContactCreation = py_tobool(py_arg(12));
        if(!py_checkint(py_arg(13))) return false;
        self->internalValue = py_toint(py_arg(13));
    } else {
        return TypeError("expected 1 or 14 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2ShapeDef__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ShapeDef* self = py_touserdata(argv);
    b2ShapeDef* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2ShapeDef));
    *res = *self;
    return true;
}
static bool b2ShapeDef__get_userData(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ShapeDef* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->userData);
    return true;
}
static bool b2ShapeDef__set_userData(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ShapeDef* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->userData = (void*)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2ShapeDef__get_friction(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ShapeDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->friction);
    return true;
}
static bool b2ShapeDef__set_friction(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ShapeDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->friction)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2ShapeDef__get_restitution(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ShapeDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->restitution);
    return true;
}
static bool b2ShapeDef__set_restitution(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ShapeDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->restitution)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2ShapeDef__get_density(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ShapeDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->density);
    return true;
}
static bool b2ShapeDef__set_density(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ShapeDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->density)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2ShapeDef__get_filter(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ShapeDef* self = py_touserdata(argv);
    do {
        b2Filter* ud = py_newobject(py_retval(), tp_user_b2Filter, 0, sizeof(b2Filter));
        *ud = self->filter;
    } while(0);
    return true;
}
static bool b2ShapeDef__set_filter(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ShapeDef* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2Filter)) return false;
        self->filter = *(b2Filter*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2ShapeDef__get_customColor(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ShapeDef* self = py_touserdata(argv);
    py_newint(py_retval(), self->customColor);
    return true;
}
static bool b2ShapeDef__set_customColor(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ShapeDef* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->customColor = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2ShapeDef__get_isSensor(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ShapeDef* self = py_touserdata(argv);
    py_newbool(py_retval(), self->isSensor);
    return true;
}
static bool b2ShapeDef__set_isSensor(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ShapeDef* self = py_touserdata(argv);
    if(!py_checkbool(py_arg(1))) return false;
    self->isSensor = py_tobool(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2ShapeDef__get_enableSensorEvents(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ShapeDef* self = py_touserdata(argv);
    py_newbool(py_retval(), self->enableSensorEvents);
    return true;
}
static bool b2ShapeDef__set_enableSensorEvents(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ShapeDef* self = py_touserdata(argv);
    if(!py_checkbool(py_arg(1))) return false;
    self->enableSensorEvents = py_tobool(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2ShapeDef__get_enableContactEvents(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ShapeDef* self = py_touserdata(argv);
    py_newbool(py_retval(), self->enableContactEvents);
    return true;
}
static bool b2ShapeDef__set_enableContactEvents(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ShapeDef* self = py_touserdata(argv);
    if(!py_checkbool(py_arg(1))) return false;
    self->enableContactEvents = py_tobool(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2ShapeDef__get_enableHitEvents(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ShapeDef* self = py_touserdata(argv);
    py_newbool(py_retval(), self->enableHitEvents);
    return true;
}
static bool b2ShapeDef__set_enableHitEvents(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ShapeDef* self = py_touserdata(argv);
    if(!py_checkbool(py_arg(1))) return false;
    self->enableHitEvents = py_tobool(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2ShapeDef__get_enablePreSolveEvents(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ShapeDef* self = py_touserdata(argv);
    py_newbool(py_retval(), self->enablePreSolveEvents);
    return true;
}
static bool b2ShapeDef__set_enablePreSolveEvents(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ShapeDef* self = py_touserdata(argv);
    if(!py_checkbool(py_arg(1))) return false;
    self->enablePreSolveEvents = py_tobool(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2ShapeDef__get_forceContactCreation(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ShapeDef* self = py_touserdata(argv);
    py_newbool(py_retval(), self->forceContactCreation);
    return true;
}
static bool b2ShapeDef__set_forceContactCreation(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ShapeDef* self = py_touserdata(argv);
    if(!py_checkbool(py_arg(1))) return false;
    self->forceContactCreation = py_tobool(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2ShapeDef__get_internalValue(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ShapeDef* self = py_touserdata(argv);
    py_newint(py_retval(), self->internalValue);
    return true;
}
static bool b2ShapeDef__set_internalValue(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ShapeDef* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->internalValue = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2ShapeDef(py_GlobalRef mod) {
    py_Type type = py_newtype("b2ShapeDef", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2ShapeDef__new__);
    py_bindmagic(type, __init__, b2ShapeDef__init__);
    py_bindmethod(type, "copy", b2ShapeDef__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "userData", b2ShapeDef__get_userData, b2ShapeDef__set_userData);
    py_bindproperty(type, "friction", b2ShapeDef__get_friction, b2ShapeDef__set_friction);
    py_bindproperty(type, "restitution", b2ShapeDef__get_restitution, b2ShapeDef__set_restitution);
    py_bindproperty(type, "density", b2ShapeDef__get_density, b2ShapeDef__set_density);
    py_bindproperty(type, "filter", b2ShapeDef__get_filter, b2ShapeDef__set_filter);
    py_bindproperty(type, "customColor", b2ShapeDef__get_customColor, b2ShapeDef__set_customColor);
    py_bindproperty(type, "isSensor", b2ShapeDef__get_isSensor, b2ShapeDef__set_isSensor);
    py_bindproperty(type, "enableSensorEvents", b2ShapeDef__get_enableSensorEvents, b2ShapeDef__set_enableSensorEvents);
    py_bindproperty(type, "enableContactEvents", b2ShapeDef__get_enableContactEvents, b2ShapeDef__set_enableContactEvents);
    py_bindproperty(type, "enableHitEvents", b2ShapeDef__get_enableHitEvents, b2ShapeDef__set_enableHitEvents);
    py_bindproperty(type, "enablePreSolveEvents", b2ShapeDef__get_enablePreSolveEvents, b2ShapeDef__set_enablePreSolveEvents);
    py_bindproperty(type, "forceContactCreation", b2ShapeDef__get_forceContactCreation, b2ShapeDef__set_forceContactCreation);
    py_bindproperty(type, "internalValue", b2ShapeDef__get_internalValue, b2ShapeDef__set_internalValue);
    return type;
}
static py_Type tp_user_b2ShapeDef;
static bool b2ChainDef__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2ChainDef));
    return true;
}
static bool b2ChainDef__init__(int argc, py_Ref argv) {
    b2ChainDef* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2ChainDef));
    } else if(argc == 1 + 8) {
        if(!py_checkint(py_arg(1))) return false;
        self->userData = (void*)py_toint(py_arg(1));
        // _1 points is read-only
        if(!py_checkint(py_arg(3))) return false;
        self->count = py_toint(py_arg(3));
        if(!py_castfloat32(py_arg(4), &self->friction)) return false;
        if(!py_castfloat32(py_arg(5), &self->restitution)) return false;
        do {
            if(!py_checktype(py_arg(6), tp_user_b2Filter)) return false;
            self->filter = *(b2Filter*)py_touserdata(py_arg(6));
        } while(0);
        if(!py_checkbool(py_arg(7))) return false;
        self->isLoop = py_tobool(py_arg(7));
        if(!py_checkint(py_arg(8))) return false;
        self->internalValue = py_toint(py_arg(8));
    } else {
        return TypeError("expected 1 or 9 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2ChainDef__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ChainDef* self = py_touserdata(argv);
    b2ChainDef* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2ChainDef));
    *res = *self;
    return true;
}
static bool b2ChainDef__get_userData(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ChainDef* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->userData);
    return true;
}
static bool b2ChainDef__set_userData(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ChainDef* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->userData = (void*)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2ChainDef__get_points(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ChainDef* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->points);
    return true;
}
static bool b2ChainDef__get_count(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ChainDef* self = py_touserdata(argv);
    py_newint(py_retval(), self->count);
    return true;
}
static bool b2ChainDef__set_count(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ChainDef* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->count = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2ChainDef__get_friction(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ChainDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->friction);
    return true;
}
static bool b2ChainDef__set_friction(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ChainDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->friction)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2ChainDef__get_restitution(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ChainDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->restitution);
    return true;
}
static bool b2ChainDef__set_restitution(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ChainDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->restitution)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2ChainDef__get_filter(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ChainDef* self = py_touserdata(argv);
    do {
        b2Filter* ud = py_newobject(py_retval(), tp_user_b2Filter, 0, sizeof(b2Filter));
        *ud = self->filter;
    } while(0);
    return true;
}
static bool b2ChainDef__set_filter(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ChainDef* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2Filter)) return false;
        self->filter = *(b2Filter*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2ChainDef__get_isLoop(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ChainDef* self = py_touserdata(argv);
    py_newbool(py_retval(), self->isLoop);
    return true;
}
static bool b2ChainDef__set_isLoop(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ChainDef* self = py_touserdata(argv);
    if(!py_checkbool(py_arg(1))) return false;
    self->isLoop = py_tobool(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2ChainDef__get_internalValue(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ChainDef* self = py_touserdata(argv);
    py_newint(py_retval(), self->internalValue);
    return true;
}
static bool b2ChainDef__set_internalValue(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ChainDef* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->internalValue = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2ChainDef(py_GlobalRef mod) {
    py_Type type = py_newtype("b2ChainDef", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2ChainDef__new__);
    py_bindmagic(type, __init__, b2ChainDef__init__);
    py_bindmethod(type, "copy", b2ChainDef__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "userData", b2ChainDef__get_userData, b2ChainDef__set_userData);
    py_bindproperty(type, "points", b2ChainDef__get_points, NULL);
    py_bindproperty(type, "count", b2ChainDef__get_count, b2ChainDef__set_count);
    py_bindproperty(type, "friction", b2ChainDef__get_friction, b2ChainDef__set_friction);
    py_bindproperty(type, "restitution", b2ChainDef__get_restitution, b2ChainDef__set_restitution);
    py_bindproperty(type, "filter", b2ChainDef__get_filter, b2ChainDef__set_filter);
    py_bindproperty(type, "isLoop", b2ChainDef__get_isLoop, b2ChainDef__set_isLoop);
    py_bindproperty(type, "internalValue", b2ChainDef__get_internalValue, b2ChainDef__set_internalValue);
    return type;
}
static py_Type tp_user_b2ChainDef;
static bool b2Profile__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2Profile));
    return true;
}
static bool b2Profile__init__(int argc, py_Ref argv) {
    b2Profile* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2Profile));
    } else if(argc == 1 + 22) {
        if(!py_castfloat32(py_arg(1), &self->step)) return false;
        if(!py_castfloat32(py_arg(2), &self->pairs)) return false;
        if(!py_castfloat32(py_arg(3), &self->collide)) return false;
        if(!py_castfloat32(py_arg(4), &self->solve)) return false;
        if(!py_castfloat32(py_arg(5), &self->buildIslands)) return false;
        if(!py_castfloat32(py_arg(6), &self->solveConstraints)) return false;
        if(!py_castfloat32(py_arg(7), &self->prepareTasks)) return false;
        if(!py_castfloat32(py_arg(8), &self->solverTasks)) return false;
        if(!py_castfloat32(py_arg(9), &self->prepareConstraints)) return false;
        if(!py_castfloat32(py_arg(10), &self->integrateVelocities)) return false;
        if(!py_castfloat32(py_arg(11), &self->warmStart)) return false;
        if(!py_castfloat32(py_arg(12), &self->solveVelocities)) return false;
        if(!py_castfloat32(py_arg(13), &self->integratePositions)) return false;
        if(!py_castfloat32(py_arg(14), &self->relaxVelocities)) return false;
        if(!py_castfloat32(py_arg(15), &self->applyRestitution)) return false;
        if(!py_castfloat32(py_arg(16), &self->storeImpulses)) return false;
        if(!py_castfloat32(py_arg(17), &self->finalizeBodies)) return false;
        if(!py_castfloat32(py_arg(18), &self->splitIslands)) return false;
        if(!py_castfloat32(py_arg(19), &self->sleepIslands)) return false;
        if(!py_castfloat32(py_arg(20), &self->hitEvents)) return false;
        if(!py_castfloat32(py_arg(21), &self->broadphase)) return false;
        if(!py_castfloat32(py_arg(22), &self->continuous)) return false;
    } else {
        return TypeError("expected 1 or 23 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2Profile__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Profile* self = py_touserdata(argv);
    b2Profile* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2Profile));
    *res = *self;
    return true;
}
static bool b2Profile__get_step(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Profile* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->step);
    return true;
}
static bool b2Profile__set_step(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Profile* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->step)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2Profile__get_pairs(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Profile* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->pairs);
    return true;
}
static bool b2Profile__set_pairs(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Profile* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->pairs)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2Profile__get_collide(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Profile* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->collide);
    return true;
}
static bool b2Profile__set_collide(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Profile* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->collide)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2Profile__get_solve(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Profile* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->solve);
    return true;
}
static bool b2Profile__set_solve(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Profile* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->solve)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2Profile__get_buildIslands(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Profile* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->buildIslands);
    return true;
}
static bool b2Profile__set_buildIslands(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Profile* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->buildIslands)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2Profile__get_solveConstraints(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Profile* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->solveConstraints);
    return true;
}
static bool b2Profile__set_solveConstraints(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Profile* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->solveConstraints)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2Profile__get_prepareTasks(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Profile* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->prepareTasks);
    return true;
}
static bool b2Profile__set_prepareTasks(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Profile* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->prepareTasks)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2Profile__get_solverTasks(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Profile* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->solverTasks);
    return true;
}
static bool b2Profile__set_solverTasks(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Profile* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->solverTasks)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2Profile__get_prepareConstraints(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Profile* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->prepareConstraints);
    return true;
}
static bool b2Profile__set_prepareConstraints(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Profile* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->prepareConstraints)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2Profile__get_integrateVelocities(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Profile* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->integrateVelocities);
    return true;
}
static bool b2Profile__set_integrateVelocities(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Profile* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->integrateVelocities)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2Profile__get_warmStart(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Profile* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->warmStart);
    return true;
}
static bool b2Profile__set_warmStart(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Profile* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->warmStart)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2Profile__get_solveVelocities(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Profile* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->solveVelocities);
    return true;
}
static bool b2Profile__set_solveVelocities(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Profile* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->solveVelocities)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2Profile__get_integratePositions(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Profile* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->integratePositions);
    return true;
}
static bool b2Profile__set_integratePositions(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Profile* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->integratePositions)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2Profile__get_relaxVelocities(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Profile* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->relaxVelocities);
    return true;
}
static bool b2Profile__set_relaxVelocities(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Profile* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->relaxVelocities)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2Profile__get_applyRestitution(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Profile* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->applyRestitution);
    return true;
}
static bool b2Profile__set_applyRestitution(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Profile* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->applyRestitution)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2Profile__get_storeImpulses(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Profile* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->storeImpulses);
    return true;
}
static bool b2Profile__set_storeImpulses(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Profile* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->storeImpulses)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2Profile__get_finalizeBodies(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Profile* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->finalizeBodies);
    return true;
}
static bool b2Profile__set_finalizeBodies(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Profile* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->finalizeBodies)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2Profile__get_splitIslands(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Profile* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->splitIslands);
    return true;
}
static bool b2Profile__set_splitIslands(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Profile* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->splitIslands)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2Profile__get_sleepIslands(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Profile* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->sleepIslands);
    return true;
}
static bool b2Profile__set_sleepIslands(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Profile* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->sleepIslands)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2Profile__get_hitEvents(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Profile* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->hitEvents);
    return true;
}
static bool b2Profile__set_hitEvents(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Profile* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->hitEvents)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2Profile__get_broadphase(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Profile* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->broadphase);
    return true;
}
static bool b2Profile__set_broadphase(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Profile* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->broadphase)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2Profile__get_continuous(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Profile* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->continuous);
    return true;
}
static bool b2Profile__set_continuous(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Profile* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->continuous)) return false;
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2Profile(py_GlobalRef mod) {
    py_Type type = py_newtype("b2Profile", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2Profile__new__);
    py_bindmagic(type, __init__, b2Profile__init__);
    py_bindmethod(type, "copy", b2Profile__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "step", b2Profile__get_step, b2Profile__set_step);
    py_bindproperty(type, "pairs", b2Profile__get_pairs, b2Profile__set_pairs);
    py_bindproperty(type, "collide", b2Profile__get_collide, b2Profile__set_collide);
    py_bindproperty(type, "solve", b2Profile__get_solve, b2Profile__set_solve);
    py_bindproperty(type, "buildIslands", b2Profile__get_buildIslands, b2Profile__set_buildIslands);
    py_bindproperty(type, "solveConstraints", b2Profile__get_solveConstraints, b2Profile__set_solveConstraints);
    py_bindproperty(type, "prepareTasks", b2Profile__get_prepareTasks, b2Profile__set_prepareTasks);
    py_bindproperty(type, "solverTasks", b2Profile__get_solverTasks, b2Profile__set_solverTasks);
    py_bindproperty(type, "prepareConstraints", b2Profile__get_prepareConstraints, b2Profile__set_prepareConstraints);
    py_bindproperty(type, "integrateVelocities", b2Profile__get_integrateVelocities, b2Profile__set_integrateVelocities);
    py_bindproperty(type, "warmStart", b2Profile__get_warmStart, b2Profile__set_warmStart);
    py_bindproperty(type, "solveVelocities", b2Profile__get_solveVelocities, b2Profile__set_solveVelocities);
    py_bindproperty(type, "integratePositions", b2Profile__get_integratePositions, b2Profile__set_integratePositions);
    py_bindproperty(type, "relaxVelocities", b2Profile__get_relaxVelocities, b2Profile__set_relaxVelocities);
    py_bindproperty(type, "applyRestitution", b2Profile__get_applyRestitution, b2Profile__set_applyRestitution);
    py_bindproperty(type, "storeImpulses", b2Profile__get_storeImpulses, b2Profile__set_storeImpulses);
    py_bindproperty(type, "finalizeBodies", b2Profile__get_finalizeBodies, b2Profile__set_finalizeBodies);
    py_bindproperty(type, "splitIslands", b2Profile__get_splitIslands, b2Profile__set_splitIslands);
    py_bindproperty(type, "sleepIslands", b2Profile__get_sleepIslands, b2Profile__set_sleepIslands);
    py_bindproperty(type, "hitEvents", b2Profile__get_hitEvents, b2Profile__set_hitEvents);
    py_bindproperty(type, "broadphase", b2Profile__get_broadphase, b2Profile__set_broadphase);
    py_bindproperty(type, "continuous", b2Profile__get_continuous, b2Profile__set_continuous);
    return type;
}
static py_Type tp_user_b2Profile;
static bool b2Counters__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2Counters));
    return true;
}
static bool b2Counters__init__(int argc, py_Ref argv) {
    b2Counters* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2Counters));
    } else if(argc == 1 + 12) {
        if(!py_checkint(py_arg(1))) return false;
        self->staticBodyCount = py_toint(py_arg(1));
        if(!py_checkint(py_arg(2))) return false;
        self->bodyCount = py_toint(py_arg(2));
        if(!py_checkint(py_arg(3))) return false;
        self->shapeCount = py_toint(py_arg(3));
        if(!py_checkint(py_arg(4))) return false;
        self->contactCount = py_toint(py_arg(4));
        if(!py_checkint(py_arg(5))) return false;
        self->jointCount = py_toint(py_arg(5));
        if(!py_checkint(py_arg(6))) return false;
        self->islandCount = py_toint(py_arg(6));
        if(!py_checkint(py_arg(7))) return false;
        self->stackUsed = py_toint(py_arg(7));
        if(!py_checkint(py_arg(8))) return false;
        self->staticTreeHeight = py_toint(py_arg(8));
        if(!py_checkint(py_arg(9))) return false;
        self->treeHeight = py_toint(py_arg(9));
        if(!py_checkint(py_arg(10))) return false;
        self->byteCount = py_toint(py_arg(10));
        if(!py_checkint(py_arg(11))) return false;
        self->taskCount = py_toint(py_arg(11));
        // _11 colorCounts is read-only
    } else {
        return TypeError("expected 1 or 13 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2Counters__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Counters* self = py_touserdata(argv);
    b2Counters* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2Counters));
    *res = *self;
    return true;
}
static bool b2Counters__get_staticBodyCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Counters* self = py_touserdata(argv);
    py_newint(py_retval(), self->staticBodyCount);
    return true;
}
static bool b2Counters__set_staticBodyCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Counters* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->staticBodyCount = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2Counters__get_bodyCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Counters* self = py_touserdata(argv);
    py_newint(py_retval(), self->bodyCount);
    return true;
}
static bool b2Counters__set_bodyCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Counters* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->bodyCount = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2Counters__get_shapeCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Counters* self = py_touserdata(argv);
    py_newint(py_retval(), self->shapeCount);
    return true;
}
static bool b2Counters__set_shapeCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Counters* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->shapeCount = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2Counters__get_contactCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Counters* self = py_touserdata(argv);
    py_newint(py_retval(), self->contactCount);
    return true;
}
static bool b2Counters__set_contactCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Counters* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->contactCount = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2Counters__get_jointCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Counters* self = py_touserdata(argv);
    py_newint(py_retval(), self->jointCount);
    return true;
}
static bool b2Counters__set_jointCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Counters* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->jointCount = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2Counters__get_islandCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Counters* self = py_touserdata(argv);
    py_newint(py_retval(), self->islandCount);
    return true;
}
static bool b2Counters__set_islandCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Counters* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->islandCount = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2Counters__get_stackUsed(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Counters* self = py_touserdata(argv);
    py_newint(py_retval(), self->stackUsed);
    return true;
}
static bool b2Counters__set_stackUsed(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Counters* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->stackUsed = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2Counters__get_staticTreeHeight(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Counters* self = py_touserdata(argv);
    py_newint(py_retval(), self->staticTreeHeight);
    return true;
}
static bool b2Counters__set_staticTreeHeight(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Counters* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->staticTreeHeight = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2Counters__get_treeHeight(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Counters* self = py_touserdata(argv);
    py_newint(py_retval(), self->treeHeight);
    return true;
}
static bool b2Counters__set_treeHeight(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Counters* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->treeHeight = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2Counters__get_byteCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Counters* self = py_touserdata(argv);
    py_newint(py_retval(), self->byteCount);
    return true;
}
static bool b2Counters__set_byteCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Counters* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->byteCount = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2Counters__get_taskCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Counters* self = py_touserdata(argv);
    py_newint(py_retval(), self->taskCount);
    return true;
}
static bool b2Counters__set_taskCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2Counters* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->taskCount = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2Counters__get_colorCounts(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2Counters* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->colorCounts);
    return true;
}
static py_Type register__b2Counters(py_GlobalRef mod) {
    py_Type type = py_newtype("b2Counters", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2Counters__new__);
    py_bindmagic(type, __init__, b2Counters__init__);
    py_bindmethod(type, "copy", b2Counters__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "staticBodyCount", b2Counters__get_staticBodyCount, b2Counters__set_staticBodyCount);
    py_bindproperty(type, "bodyCount", b2Counters__get_bodyCount, b2Counters__set_bodyCount);
    py_bindproperty(type, "shapeCount", b2Counters__get_shapeCount, b2Counters__set_shapeCount);
    py_bindproperty(type, "contactCount", b2Counters__get_contactCount, b2Counters__set_contactCount);
    py_bindproperty(type, "jointCount", b2Counters__get_jointCount, b2Counters__set_jointCount);
    py_bindproperty(type, "islandCount", b2Counters__get_islandCount, b2Counters__set_islandCount);
    py_bindproperty(type, "stackUsed", b2Counters__get_stackUsed, b2Counters__set_stackUsed);
    py_bindproperty(type, "staticTreeHeight", b2Counters__get_staticTreeHeight, b2Counters__set_staticTreeHeight);
    py_bindproperty(type, "treeHeight", b2Counters__get_treeHeight, b2Counters__set_treeHeight);
    py_bindproperty(type, "byteCount", b2Counters__get_byteCount, b2Counters__set_byteCount);
    py_bindproperty(type, "taskCount", b2Counters__get_taskCount, b2Counters__set_taskCount);
    py_bindproperty(type, "colorCounts", b2Counters__get_colorCounts, NULL);
    return type;
}
static py_Type tp_user_b2Counters;
static bool b2DistanceJointDef__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2DistanceJointDef));
    return true;
}
static bool b2DistanceJointDef__init__(int argc, py_Ref argv) {
    b2DistanceJointDef* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2DistanceJointDef));
    } else if(argc == 1 + 17) {
        do {
            if(!py_checktype(py_arg(1), tp_user_b2BodyId)) return false;
            self->bodyIdA = *(b2BodyId*)py_touserdata(py_arg(1));
        } while(0);
        do {
            if(!py_checktype(py_arg(2), tp_user_b2BodyId)) return false;
            self->bodyIdB = *(b2BodyId*)py_touserdata(py_arg(2));
        } while(0);
        do {
            if(!py_checktype(py_arg(3), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(3));
            self->localAnchorA = *(b2Vec2*)(&tmp);
        } while(0);
        do {
            if(!py_checktype(py_arg(4), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(4));
            self->localAnchorB = *(b2Vec2*)(&tmp);
        } while(0);
        if(!py_castfloat32(py_arg(5), &self->length)) return false;
        if(!py_checkbool(py_arg(6))) return false;
        self->enableSpring = py_tobool(py_arg(6));
        if(!py_castfloat32(py_arg(7), &self->hertz)) return false;
        if(!py_castfloat32(py_arg(8), &self->dampingRatio)) return false;
        if(!py_checkbool(py_arg(9))) return false;
        self->enableLimit = py_tobool(py_arg(9));
        if(!py_castfloat32(py_arg(10), &self->minLength)) return false;
        if(!py_castfloat32(py_arg(11), &self->maxLength)) return false;
        if(!py_checkbool(py_arg(12))) return false;
        self->enableMotor = py_tobool(py_arg(12));
        if(!py_castfloat32(py_arg(13), &self->maxMotorForce)) return false;
        if(!py_castfloat32(py_arg(14), &self->motorSpeed)) return false;
        if(!py_checkbool(py_arg(15))) return false;
        self->collideConnected = py_tobool(py_arg(15));
        if(!py_checkint(py_arg(16))) return false;
        self->userData = (void*)py_toint(py_arg(16));
        if(!py_checkint(py_arg(17))) return false;
        self->internalValue = py_toint(py_arg(17));
    } else {
        return TypeError("expected 1 or 18 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2DistanceJointDef__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DistanceJointDef* self = py_touserdata(argv);
    b2DistanceJointDef* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2DistanceJointDef));
    *res = *self;
    return true;
}
static bool b2DistanceJointDef__get_bodyIdA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DistanceJointDef* self = py_touserdata(argv);
    do {
        b2BodyId* ud = py_newobject(py_retval(), tp_user_b2BodyId, 0, sizeof(b2BodyId));
        *ud = self->bodyIdA;
    } while(0);
    return true;
}
static bool b2DistanceJointDef__set_bodyIdA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2DistanceJointDef* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2BodyId)) return false;
        self->bodyIdA = *(b2BodyId*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2DistanceJointDef__get_bodyIdB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DistanceJointDef* self = py_touserdata(argv);
    do {
        b2BodyId* ud = py_newobject(py_retval(), tp_user_b2BodyId, 0, sizeof(b2BodyId));
        *ud = self->bodyIdB;
    } while(0);
    return true;
}
static bool b2DistanceJointDef__set_bodyIdB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2DistanceJointDef* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2BodyId)) return false;
        self->bodyIdB = *(b2BodyId*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2DistanceJointDef__get_localAnchorA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DistanceJointDef* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->localAnchorA));
    return true;
}
static bool b2DistanceJointDef__set_localAnchorA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2DistanceJointDef* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->localAnchorA = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2DistanceJointDef__get_localAnchorB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DistanceJointDef* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->localAnchorB));
    return true;
}
static bool b2DistanceJointDef__set_localAnchorB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2DistanceJointDef* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->localAnchorB = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2DistanceJointDef__get_length(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DistanceJointDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->length);
    return true;
}
static bool b2DistanceJointDef__set_length(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2DistanceJointDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->length)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2DistanceJointDef__get_enableSpring(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DistanceJointDef* self = py_touserdata(argv);
    py_newbool(py_retval(), self->enableSpring);
    return true;
}
static bool b2DistanceJointDef__set_enableSpring(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2DistanceJointDef* self = py_touserdata(argv);
    if(!py_checkbool(py_arg(1))) return false;
    self->enableSpring = py_tobool(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2DistanceJointDef__get_hertz(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DistanceJointDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->hertz);
    return true;
}
static bool b2DistanceJointDef__set_hertz(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2DistanceJointDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->hertz)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2DistanceJointDef__get_dampingRatio(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DistanceJointDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->dampingRatio);
    return true;
}
static bool b2DistanceJointDef__set_dampingRatio(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2DistanceJointDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->dampingRatio)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2DistanceJointDef__get_enableLimit(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DistanceJointDef* self = py_touserdata(argv);
    py_newbool(py_retval(), self->enableLimit);
    return true;
}
static bool b2DistanceJointDef__set_enableLimit(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2DistanceJointDef* self = py_touserdata(argv);
    if(!py_checkbool(py_arg(1))) return false;
    self->enableLimit = py_tobool(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2DistanceJointDef__get_minLength(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DistanceJointDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->minLength);
    return true;
}
static bool b2DistanceJointDef__set_minLength(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2DistanceJointDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->minLength)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2DistanceJointDef__get_maxLength(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DistanceJointDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->maxLength);
    return true;
}
static bool b2DistanceJointDef__set_maxLength(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2DistanceJointDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->maxLength)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2DistanceJointDef__get_enableMotor(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DistanceJointDef* self = py_touserdata(argv);
    py_newbool(py_retval(), self->enableMotor);
    return true;
}
static bool b2DistanceJointDef__set_enableMotor(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2DistanceJointDef* self = py_touserdata(argv);
    if(!py_checkbool(py_arg(1))) return false;
    self->enableMotor = py_tobool(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2DistanceJointDef__get_maxMotorForce(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DistanceJointDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->maxMotorForce);
    return true;
}
static bool b2DistanceJointDef__set_maxMotorForce(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2DistanceJointDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->maxMotorForce)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2DistanceJointDef__get_motorSpeed(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DistanceJointDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->motorSpeed);
    return true;
}
static bool b2DistanceJointDef__set_motorSpeed(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2DistanceJointDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->motorSpeed)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2DistanceJointDef__get_collideConnected(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DistanceJointDef* self = py_touserdata(argv);
    py_newbool(py_retval(), self->collideConnected);
    return true;
}
static bool b2DistanceJointDef__set_collideConnected(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2DistanceJointDef* self = py_touserdata(argv);
    if(!py_checkbool(py_arg(1))) return false;
    self->collideConnected = py_tobool(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2DistanceJointDef__get_userData(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DistanceJointDef* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->userData);
    return true;
}
static bool b2DistanceJointDef__set_userData(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2DistanceJointDef* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->userData = (void*)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2DistanceJointDef__get_internalValue(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2DistanceJointDef* self = py_touserdata(argv);
    py_newint(py_retval(), self->internalValue);
    return true;
}
static bool b2DistanceJointDef__set_internalValue(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2DistanceJointDef* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->internalValue = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2DistanceJointDef(py_GlobalRef mod) {
    py_Type type = py_newtype("b2DistanceJointDef", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2DistanceJointDef__new__);
    py_bindmagic(type, __init__, b2DistanceJointDef__init__);
    py_bindmethod(type, "copy", b2DistanceJointDef__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "bodyIdA", b2DistanceJointDef__get_bodyIdA, b2DistanceJointDef__set_bodyIdA);
    py_bindproperty(type, "bodyIdB", b2DistanceJointDef__get_bodyIdB, b2DistanceJointDef__set_bodyIdB);
    py_bindproperty(type, "localAnchorA", b2DistanceJointDef__get_localAnchorA, b2DistanceJointDef__set_localAnchorA);
    py_bindproperty(type, "localAnchorB", b2DistanceJointDef__get_localAnchorB, b2DistanceJointDef__set_localAnchorB);
    py_bindproperty(type, "length", b2DistanceJointDef__get_length, b2DistanceJointDef__set_length);
    py_bindproperty(type, "enableSpring", b2DistanceJointDef__get_enableSpring, b2DistanceJointDef__set_enableSpring);
    py_bindproperty(type, "hertz", b2DistanceJointDef__get_hertz, b2DistanceJointDef__set_hertz);
    py_bindproperty(type, "dampingRatio", b2DistanceJointDef__get_dampingRatio, b2DistanceJointDef__set_dampingRatio);
    py_bindproperty(type, "enableLimit", b2DistanceJointDef__get_enableLimit, b2DistanceJointDef__set_enableLimit);
    py_bindproperty(type, "minLength", b2DistanceJointDef__get_minLength, b2DistanceJointDef__set_minLength);
    py_bindproperty(type, "maxLength", b2DistanceJointDef__get_maxLength, b2DistanceJointDef__set_maxLength);
    py_bindproperty(type, "enableMotor", b2DistanceJointDef__get_enableMotor, b2DistanceJointDef__set_enableMotor);
    py_bindproperty(type, "maxMotorForce", b2DistanceJointDef__get_maxMotorForce, b2DistanceJointDef__set_maxMotorForce);
    py_bindproperty(type, "motorSpeed", b2DistanceJointDef__get_motorSpeed, b2DistanceJointDef__set_motorSpeed);
    py_bindproperty(type, "collideConnected", b2DistanceJointDef__get_collideConnected, b2DistanceJointDef__set_collideConnected);
    py_bindproperty(type, "userData", b2DistanceJointDef__get_userData, b2DistanceJointDef__set_userData);
    py_bindproperty(type, "internalValue", b2DistanceJointDef__get_internalValue, b2DistanceJointDef__set_internalValue);
    return type;
}
static py_Type tp_user_b2DistanceJointDef;
static bool b2MotorJointDef__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2MotorJointDef));
    return true;
}
static bool b2MotorJointDef__init__(int argc, py_Ref argv) {
    b2MotorJointDef* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2MotorJointDef));
    } else if(argc == 1 + 10) {
        do {
            if(!py_checktype(py_arg(1), tp_user_b2BodyId)) return false;
            self->bodyIdA = *(b2BodyId*)py_touserdata(py_arg(1));
        } while(0);
        do {
            if(!py_checktype(py_arg(2), tp_user_b2BodyId)) return false;
            self->bodyIdB = *(b2BodyId*)py_touserdata(py_arg(2));
        } while(0);
        do {
            if(!py_checktype(py_arg(3), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(3));
            self->linearOffset = *(b2Vec2*)(&tmp);
        } while(0);
        if(!py_castfloat32(py_arg(4), &self->angularOffset)) return false;
        if(!py_castfloat32(py_arg(5), &self->maxForce)) return false;
        if(!py_castfloat32(py_arg(6), &self->maxTorque)) return false;
        if(!py_castfloat32(py_arg(7), &self->correctionFactor)) return false;
        if(!py_checkbool(py_arg(8))) return false;
        self->collideConnected = py_tobool(py_arg(8));
        if(!py_checkint(py_arg(9))) return false;
        self->userData = (void*)py_toint(py_arg(9));
        if(!py_checkint(py_arg(10))) return false;
        self->internalValue = py_toint(py_arg(10));
    } else {
        return TypeError("expected 1 or 11 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2MotorJointDef__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2MotorJointDef* self = py_touserdata(argv);
    b2MotorJointDef* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2MotorJointDef));
    *res = *self;
    return true;
}
static bool b2MotorJointDef__get_bodyIdA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2MotorJointDef* self = py_touserdata(argv);
    do {
        b2BodyId* ud = py_newobject(py_retval(), tp_user_b2BodyId, 0, sizeof(b2BodyId));
        *ud = self->bodyIdA;
    } while(0);
    return true;
}
static bool b2MotorJointDef__set_bodyIdA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2MotorJointDef* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2BodyId)) return false;
        self->bodyIdA = *(b2BodyId*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2MotorJointDef__get_bodyIdB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2MotorJointDef* self = py_touserdata(argv);
    do {
        b2BodyId* ud = py_newobject(py_retval(), tp_user_b2BodyId, 0, sizeof(b2BodyId));
        *ud = self->bodyIdB;
    } while(0);
    return true;
}
static bool b2MotorJointDef__set_bodyIdB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2MotorJointDef* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2BodyId)) return false;
        self->bodyIdB = *(b2BodyId*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2MotorJointDef__get_linearOffset(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2MotorJointDef* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->linearOffset));
    return true;
}
static bool b2MotorJointDef__set_linearOffset(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2MotorJointDef* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->linearOffset = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2MotorJointDef__get_angularOffset(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2MotorJointDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->angularOffset);
    return true;
}
static bool b2MotorJointDef__set_angularOffset(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2MotorJointDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->angularOffset)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2MotorJointDef__get_maxForce(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2MotorJointDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->maxForce);
    return true;
}
static bool b2MotorJointDef__set_maxForce(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2MotorJointDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->maxForce)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2MotorJointDef__get_maxTorque(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2MotorJointDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->maxTorque);
    return true;
}
static bool b2MotorJointDef__set_maxTorque(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2MotorJointDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->maxTorque)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2MotorJointDef__get_correctionFactor(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2MotorJointDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->correctionFactor);
    return true;
}
static bool b2MotorJointDef__set_correctionFactor(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2MotorJointDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->correctionFactor)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2MotorJointDef__get_collideConnected(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2MotorJointDef* self = py_touserdata(argv);
    py_newbool(py_retval(), self->collideConnected);
    return true;
}
static bool b2MotorJointDef__set_collideConnected(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2MotorJointDef* self = py_touserdata(argv);
    if(!py_checkbool(py_arg(1))) return false;
    self->collideConnected = py_tobool(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2MotorJointDef__get_userData(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2MotorJointDef* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->userData);
    return true;
}
static bool b2MotorJointDef__set_userData(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2MotorJointDef* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->userData = (void*)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2MotorJointDef__get_internalValue(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2MotorJointDef* self = py_touserdata(argv);
    py_newint(py_retval(), self->internalValue);
    return true;
}
static bool b2MotorJointDef__set_internalValue(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2MotorJointDef* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->internalValue = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2MotorJointDef(py_GlobalRef mod) {
    py_Type type = py_newtype("b2MotorJointDef", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2MotorJointDef__new__);
    py_bindmagic(type, __init__, b2MotorJointDef__init__);
    py_bindmethod(type, "copy", b2MotorJointDef__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "bodyIdA", b2MotorJointDef__get_bodyIdA, b2MotorJointDef__set_bodyIdA);
    py_bindproperty(type, "bodyIdB", b2MotorJointDef__get_bodyIdB, b2MotorJointDef__set_bodyIdB);
    py_bindproperty(type, "linearOffset", b2MotorJointDef__get_linearOffset, b2MotorJointDef__set_linearOffset);
    py_bindproperty(type, "angularOffset", b2MotorJointDef__get_angularOffset, b2MotorJointDef__set_angularOffset);
    py_bindproperty(type, "maxForce", b2MotorJointDef__get_maxForce, b2MotorJointDef__set_maxForce);
    py_bindproperty(type, "maxTorque", b2MotorJointDef__get_maxTorque, b2MotorJointDef__set_maxTorque);
    py_bindproperty(type, "correctionFactor", b2MotorJointDef__get_correctionFactor, b2MotorJointDef__set_correctionFactor);
    py_bindproperty(type, "collideConnected", b2MotorJointDef__get_collideConnected, b2MotorJointDef__set_collideConnected);
    py_bindproperty(type, "userData", b2MotorJointDef__get_userData, b2MotorJointDef__set_userData);
    py_bindproperty(type, "internalValue", b2MotorJointDef__get_internalValue, b2MotorJointDef__set_internalValue);
    return type;
}
static py_Type tp_user_b2MotorJointDef;
static bool b2MouseJointDef__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2MouseJointDef));
    return true;
}
static bool b2MouseJointDef__init__(int argc, py_Ref argv) {
    b2MouseJointDef* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2MouseJointDef));
    } else if(argc == 1 + 9) {
        do {
            if(!py_checktype(py_arg(1), tp_user_b2BodyId)) return false;
            self->bodyIdA = *(b2BodyId*)py_touserdata(py_arg(1));
        } while(0);
        do {
            if(!py_checktype(py_arg(2), tp_user_b2BodyId)) return false;
            self->bodyIdB = *(b2BodyId*)py_touserdata(py_arg(2));
        } while(0);
        do {
            if(!py_checktype(py_arg(3), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(3));
            self->target = *(b2Vec2*)(&tmp);
        } while(0);
        if(!py_castfloat32(py_arg(4), &self->hertz)) return false;
        if(!py_castfloat32(py_arg(5), &self->dampingRatio)) return false;
        if(!py_castfloat32(py_arg(6), &self->maxForce)) return false;
        if(!py_checkbool(py_arg(7))) return false;
        self->collideConnected = py_tobool(py_arg(7));
        if(!py_checkint(py_arg(8))) return false;
        self->userData = (void*)py_toint(py_arg(8));
        if(!py_checkint(py_arg(9))) return false;
        self->internalValue = py_toint(py_arg(9));
    } else {
        return TypeError("expected 1 or 10 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2MouseJointDef__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2MouseJointDef* self = py_touserdata(argv);
    b2MouseJointDef* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2MouseJointDef));
    *res = *self;
    return true;
}
static bool b2MouseJointDef__get_bodyIdA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2MouseJointDef* self = py_touserdata(argv);
    do {
        b2BodyId* ud = py_newobject(py_retval(), tp_user_b2BodyId, 0, sizeof(b2BodyId));
        *ud = self->bodyIdA;
    } while(0);
    return true;
}
static bool b2MouseJointDef__set_bodyIdA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2MouseJointDef* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2BodyId)) return false;
        self->bodyIdA = *(b2BodyId*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2MouseJointDef__get_bodyIdB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2MouseJointDef* self = py_touserdata(argv);
    do {
        b2BodyId* ud = py_newobject(py_retval(), tp_user_b2BodyId, 0, sizeof(b2BodyId));
        *ud = self->bodyIdB;
    } while(0);
    return true;
}
static bool b2MouseJointDef__set_bodyIdB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2MouseJointDef* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2BodyId)) return false;
        self->bodyIdB = *(b2BodyId*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2MouseJointDef__get_target(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2MouseJointDef* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->target));
    return true;
}
static bool b2MouseJointDef__set_target(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2MouseJointDef* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->target = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2MouseJointDef__get_hertz(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2MouseJointDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->hertz);
    return true;
}
static bool b2MouseJointDef__set_hertz(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2MouseJointDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->hertz)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2MouseJointDef__get_dampingRatio(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2MouseJointDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->dampingRatio);
    return true;
}
static bool b2MouseJointDef__set_dampingRatio(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2MouseJointDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->dampingRatio)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2MouseJointDef__get_maxForce(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2MouseJointDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->maxForce);
    return true;
}
static bool b2MouseJointDef__set_maxForce(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2MouseJointDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->maxForce)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2MouseJointDef__get_collideConnected(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2MouseJointDef* self = py_touserdata(argv);
    py_newbool(py_retval(), self->collideConnected);
    return true;
}
static bool b2MouseJointDef__set_collideConnected(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2MouseJointDef* self = py_touserdata(argv);
    if(!py_checkbool(py_arg(1))) return false;
    self->collideConnected = py_tobool(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2MouseJointDef__get_userData(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2MouseJointDef* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->userData);
    return true;
}
static bool b2MouseJointDef__set_userData(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2MouseJointDef* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->userData = (void*)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2MouseJointDef__get_internalValue(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2MouseJointDef* self = py_touserdata(argv);
    py_newint(py_retval(), self->internalValue);
    return true;
}
static bool b2MouseJointDef__set_internalValue(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2MouseJointDef* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->internalValue = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2MouseJointDef(py_GlobalRef mod) {
    py_Type type = py_newtype("b2MouseJointDef", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2MouseJointDef__new__);
    py_bindmagic(type, __init__, b2MouseJointDef__init__);
    py_bindmethod(type, "copy", b2MouseJointDef__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "bodyIdA", b2MouseJointDef__get_bodyIdA, b2MouseJointDef__set_bodyIdA);
    py_bindproperty(type, "bodyIdB", b2MouseJointDef__get_bodyIdB, b2MouseJointDef__set_bodyIdB);
    py_bindproperty(type, "target", b2MouseJointDef__get_target, b2MouseJointDef__set_target);
    py_bindproperty(type, "hertz", b2MouseJointDef__get_hertz, b2MouseJointDef__set_hertz);
    py_bindproperty(type, "dampingRatio", b2MouseJointDef__get_dampingRatio, b2MouseJointDef__set_dampingRatio);
    py_bindproperty(type, "maxForce", b2MouseJointDef__get_maxForce, b2MouseJointDef__set_maxForce);
    py_bindproperty(type, "collideConnected", b2MouseJointDef__get_collideConnected, b2MouseJointDef__set_collideConnected);
    py_bindproperty(type, "userData", b2MouseJointDef__get_userData, b2MouseJointDef__set_userData);
    py_bindproperty(type, "internalValue", b2MouseJointDef__get_internalValue, b2MouseJointDef__set_internalValue);
    return type;
}
static py_Type tp_user_b2MouseJointDef;
static bool b2PrismaticJointDef__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2PrismaticJointDef));
    return true;
}
static bool b2PrismaticJointDef__init__(int argc, py_Ref argv) {
    b2PrismaticJointDef* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2PrismaticJointDef));
    } else if(argc == 1 + 18) {
        do {
            if(!py_checktype(py_arg(1), tp_user_b2BodyId)) return false;
            self->bodyIdA = *(b2BodyId*)py_touserdata(py_arg(1));
        } while(0);
        do {
            if(!py_checktype(py_arg(2), tp_user_b2BodyId)) return false;
            self->bodyIdB = *(b2BodyId*)py_touserdata(py_arg(2));
        } while(0);
        do {
            if(!py_checktype(py_arg(3), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(3));
            self->localAnchorA = *(b2Vec2*)(&tmp);
        } while(0);
        do {
            if(!py_checktype(py_arg(4), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(4));
            self->localAnchorB = *(b2Vec2*)(&tmp);
        } while(0);
        do {
            if(!py_checktype(py_arg(5), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(5));
            self->localAxisA = *(b2Vec2*)(&tmp);
        } while(0);
        if(!py_castfloat32(py_arg(6), &self->referenceAngle)) return false;
        if(!py_checkbool(py_arg(7))) return false;
        self->enableSpring = py_tobool(py_arg(7));
        if(!py_castfloat32(py_arg(8), &self->hertz)) return false;
        if(!py_castfloat32(py_arg(9), &self->dampingRatio)) return false;
        if(!py_checkbool(py_arg(10))) return false;
        self->enableLimit = py_tobool(py_arg(10));
        if(!py_castfloat32(py_arg(11), &self->lowerTranslation)) return false;
        if(!py_castfloat32(py_arg(12), &self->upperTranslation)) return false;
        if(!py_checkbool(py_arg(13))) return false;
        self->enableMotor = py_tobool(py_arg(13));
        if(!py_castfloat32(py_arg(14), &self->maxMotorForce)) return false;
        if(!py_castfloat32(py_arg(15), &self->motorSpeed)) return false;
        if(!py_checkbool(py_arg(16))) return false;
        self->collideConnected = py_tobool(py_arg(16));
        if(!py_checkint(py_arg(17))) return false;
        self->userData = (void*)py_toint(py_arg(17));
        if(!py_checkint(py_arg(18))) return false;
        self->internalValue = py_toint(py_arg(18));
    } else {
        return TypeError("expected 1 or 19 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2PrismaticJointDef__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2PrismaticJointDef* self = py_touserdata(argv);
    b2PrismaticJointDef* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2PrismaticJointDef));
    *res = *self;
    return true;
}
static bool b2PrismaticJointDef__get_bodyIdA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2PrismaticJointDef* self = py_touserdata(argv);
    do {
        b2BodyId* ud = py_newobject(py_retval(), tp_user_b2BodyId, 0, sizeof(b2BodyId));
        *ud = self->bodyIdA;
    } while(0);
    return true;
}
static bool b2PrismaticJointDef__set_bodyIdA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2PrismaticJointDef* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2BodyId)) return false;
        self->bodyIdA = *(b2BodyId*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2PrismaticJointDef__get_bodyIdB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2PrismaticJointDef* self = py_touserdata(argv);
    do {
        b2BodyId* ud = py_newobject(py_retval(), tp_user_b2BodyId, 0, sizeof(b2BodyId));
        *ud = self->bodyIdB;
    } while(0);
    return true;
}
static bool b2PrismaticJointDef__set_bodyIdB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2PrismaticJointDef* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2BodyId)) return false;
        self->bodyIdB = *(b2BodyId*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2PrismaticJointDef__get_localAnchorA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2PrismaticJointDef* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->localAnchorA));
    return true;
}
static bool b2PrismaticJointDef__set_localAnchorA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2PrismaticJointDef* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->localAnchorA = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2PrismaticJointDef__get_localAnchorB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2PrismaticJointDef* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->localAnchorB));
    return true;
}
static bool b2PrismaticJointDef__set_localAnchorB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2PrismaticJointDef* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->localAnchorB = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2PrismaticJointDef__get_localAxisA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2PrismaticJointDef* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->localAxisA));
    return true;
}
static bool b2PrismaticJointDef__set_localAxisA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2PrismaticJointDef* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->localAxisA = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2PrismaticJointDef__get_referenceAngle(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2PrismaticJointDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->referenceAngle);
    return true;
}
static bool b2PrismaticJointDef__set_referenceAngle(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2PrismaticJointDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->referenceAngle)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2PrismaticJointDef__get_enableSpring(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2PrismaticJointDef* self = py_touserdata(argv);
    py_newbool(py_retval(), self->enableSpring);
    return true;
}
static bool b2PrismaticJointDef__set_enableSpring(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2PrismaticJointDef* self = py_touserdata(argv);
    if(!py_checkbool(py_arg(1))) return false;
    self->enableSpring = py_tobool(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2PrismaticJointDef__get_hertz(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2PrismaticJointDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->hertz);
    return true;
}
static bool b2PrismaticJointDef__set_hertz(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2PrismaticJointDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->hertz)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2PrismaticJointDef__get_dampingRatio(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2PrismaticJointDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->dampingRatio);
    return true;
}
static bool b2PrismaticJointDef__set_dampingRatio(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2PrismaticJointDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->dampingRatio)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2PrismaticJointDef__get_enableLimit(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2PrismaticJointDef* self = py_touserdata(argv);
    py_newbool(py_retval(), self->enableLimit);
    return true;
}
static bool b2PrismaticJointDef__set_enableLimit(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2PrismaticJointDef* self = py_touserdata(argv);
    if(!py_checkbool(py_arg(1))) return false;
    self->enableLimit = py_tobool(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2PrismaticJointDef__get_lowerTranslation(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2PrismaticJointDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->lowerTranslation);
    return true;
}
static bool b2PrismaticJointDef__set_lowerTranslation(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2PrismaticJointDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->lowerTranslation)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2PrismaticJointDef__get_upperTranslation(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2PrismaticJointDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->upperTranslation);
    return true;
}
static bool b2PrismaticJointDef__set_upperTranslation(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2PrismaticJointDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->upperTranslation)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2PrismaticJointDef__get_enableMotor(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2PrismaticJointDef* self = py_touserdata(argv);
    py_newbool(py_retval(), self->enableMotor);
    return true;
}
static bool b2PrismaticJointDef__set_enableMotor(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2PrismaticJointDef* self = py_touserdata(argv);
    if(!py_checkbool(py_arg(1))) return false;
    self->enableMotor = py_tobool(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2PrismaticJointDef__get_maxMotorForce(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2PrismaticJointDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->maxMotorForce);
    return true;
}
static bool b2PrismaticJointDef__set_maxMotorForce(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2PrismaticJointDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->maxMotorForce)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2PrismaticJointDef__get_motorSpeed(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2PrismaticJointDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->motorSpeed);
    return true;
}
static bool b2PrismaticJointDef__set_motorSpeed(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2PrismaticJointDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->motorSpeed)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2PrismaticJointDef__get_collideConnected(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2PrismaticJointDef* self = py_touserdata(argv);
    py_newbool(py_retval(), self->collideConnected);
    return true;
}
static bool b2PrismaticJointDef__set_collideConnected(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2PrismaticJointDef* self = py_touserdata(argv);
    if(!py_checkbool(py_arg(1))) return false;
    self->collideConnected = py_tobool(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2PrismaticJointDef__get_userData(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2PrismaticJointDef* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->userData);
    return true;
}
static bool b2PrismaticJointDef__set_userData(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2PrismaticJointDef* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->userData = (void*)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2PrismaticJointDef__get_internalValue(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2PrismaticJointDef* self = py_touserdata(argv);
    py_newint(py_retval(), self->internalValue);
    return true;
}
static bool b2PrismaticJointDef__set_internalValue(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2PrismaticJointDef* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->internalValue = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2PrismaticJointDef(py_GlobalRef mod) {
    py_Type type = py_newtype("b2PrismaticJointDef", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2PrismaticJointDef__new__);
    py_bindmagic(type, __init__, b2PrismaticJointDef__init__);
    py_bindmethod(type, "copy", b2PrismaticJointDef__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "bodyIdA", b2PrismaticJointDef__get_bodyIdA, b2PrismaticJointDef__set_bodyIdA);
    py_bindproperty(type, "bodyIdB", b2PrismaticJointDef__get_bodyIdB, b2PrismaticJointDef__set_bodyIdB);
    py_bindproperty(type, "localAnchorA", b2PrismaticJointDef__get_localAnchorA, b2PrismaticJointDef__set_localAnchorA);
    py_bindproperty(type, "localAnchorB", b2PrismaticJointDef__get_localAnchorB, b2PrismaticJointDef__set_localAnchorB);
    py_bindproperty(type, "localAxisA", b2PrismaticJointDef__get_localAxisA, b2PrismaticJointDef__set_localAxisA);
    py_bindproperty(type, "referenceAngle", b2PrismaticJointDef__get_referenceAngle, b2PrismaticJointDef__set_referenceAngle);
    py_bindproperty(type, "enableSpring", b2PrismaticJointDef__get_enableSpring, b2PrismaticJointDef__set_enableSpring);
    py_bindproperty(type, "hertz", b2PrismaticJointDef__get_hertz, b2PrismaticJointDef__set_hertz);
    py_bindproperty(type, "dampingRatio", b2PrismaticJointDef__get_dampingRatio, b2PrismaticJointDef__set_dampingRatio);
    py_bindproperty(type, "enableLimit", b2PrismaticJointDef__get_enableLimit, b2PrismaticJointDef__set_enableLimit);
    py_bindproperty(type, "lowerTranslation", b2PrismaticJointDef__get_lowerTranslation, b2PrismaticJointDef__set_lowerTranslation);
    py_bindproperty(type, "upperTranslation", b2PrismaticJointDef__get_upperTranslation, b2PrismaticJointDef__set_upperTranslation);
    py_bindproperty(type, "enableMotor", b2PrismaticJointDef__get_enableMotor, b2PrismaticJointDef__set_enableMotor);
    py_bindproperty(type, "maxMotorForce", b2PrismaticJointDef__get_maxMotorForce, b2PrismaticJointDef__set_maxMotorForce);
    py_bindproperty(type, "motorSpeed", b2PrismaticJointDef__get_motorSpeed, b2PrismaticJointDef__set_motorSpeed);
    py_bindproperty(type, "collideConnected", b2PrismaticJointDef__get_collideConnected, b2PrismaticJointDef__set_collideConnected);
    py_bindproperty(type, "userData", b2PrismaticJointDef__get_userData, b2PrismaticJointDef__set_userData);
    py_bindproperty(type, "internalValue", b2PrismaticJointDef__get_internalValue, b2PrismaticJointDef__set_internalValue);
    return type;
}
static py_Type tp_user_b2PrismaticJointDef;
static bool b2RevoluteJointDef__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2RevoluteJointDef));
    return true;
}
static bool b2RevoluteJointDef__init__(int argc, py_Ref argv) {
    b2RevoluteJointDef* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2RevoluteJointDef));
    } else if(argc == 1 + 18) {
        do {
            if(!py_checktype(py_arg(1), tp_user_b2BodyId)) return false;
            self->bodyIdA = *(b2BodyId*)py_touserdata(py_arg(1));
        } while(0);
        do {
            if(!py_checktype(py_arg(2), tp_user_b2BodyId)) return false;
            self->bodyIdB = *(b2BodyId*)py_touserdata(py_arg(2));
        } while(0);
        do {
            if(!py_checktype(py_arg(3), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(3));
            self->localAnchorA = *(b2Vec2*)(&tmp);
        } while(0);
        do {
            if(!py_checktype(py_arg(4), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(4));
            self->localAnchorB = *(b2Vec2*)(&tmp);
        } while(0);
        if(!py_castfloat32(py_arg(5), &self->referenceAngle)) return false;
        if(!py_checkbool(py_arg(6))) return false;
        self->enableSpring = py_tobool(py_arg(6));
        if(!py_castfloat32(py_arg(7), &self->hertz)) return false;
        if(!py_castfloat32(py_arg(8), &self->dampingRatio)) return false;
        if(!py_checkbool(py_arg(9))) return false;
        self->enableLimit = py_tobool(py_arg(9));
        if(!py_castfloat32(py_arg(10), &self->lowerAngle)) return false;
        if(!py_castfloat32(py_arg(11), &self->upperAngle)) return false;
        if(!py_checkbool(py_arg(12))) return false;
        self->enableMotor = py_tobool(py_arg(12));
        if(!py_castfloat32(py_arg(13), &self->maxMotorTorque)) return false;
        if(!py_castfloat32(py_arg(14), &self->motorSpeed)) return false;
        if(!py_castfloat32(py_arg(15), &self->drawSize)) return false;
        if(!py_checkbool(py_arg(16))) return false;
        self->collideConnected = py_tobool(py_arg(16));
        if(!py_checkint(py_arg(17))) return false;
        self->userData = (void*)py_toint(py_arg(17));
        if(!py_checkint(py_arg(18))) return false;
        self->internalValue = py_toint(py_arg(18));
    } else {
        return TypeError("expected 1 or 19 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2RevoluteJointDef__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2RevoluteJointDef* self = py_touserdata(argv);
    b2RevoluteJointDef* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2RevoluteJointDef));
    *res = *self;
    return true;
}
static bool b2RevoluteJointDef__get_bodyIdA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2RevoluteJointDef* self = py_touserdata(argv);
    do {
        b2BodyId* ud = py_newobject(py_retval(), tp_user_b2BodyId, 0, sizeof(b2BodyId));
        *ud = self->bodyIdA;
    } while(0);
    return true;
}
static bool b2RevoluteJointDef__set_bodyIdA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2RevoluteJointDef* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2BodyId)) return false;
        self->bodyIdA = *(b2BodyId*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2RevoluteJointDef__get_bodyIdB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2RevoluteJointDef* self = py_touserdata(argv);
    do {
        b2BodyId* ud = py_newobject(py_retval(), tp_user_b2BodyId, 0, sizeof(b2BodyId));
        *ud = self->bodyIdB;
    } while(0);
    return true;
}
static bool b2RevoluteJointDef__set_bodyIdB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2RevoluteJointDef* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2BodyId)) return false;
        self->bodyIdB = *(b2BodyId*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2RevoluteJointDef__get_localAnchorA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2RevoluteJointDef* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->localAnchorA));
    return true;
}
static bool b2RevoluteJointDef__set_localAnchorA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2RevoluteJointDef* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->localAnchorA = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2RevoluteJointDef__get_localAnchorB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2RevoluteJointDef* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->localAnchorB));
    return true;
}
static bool b2RevoluteJointDef__set_localAnchorB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2RevoluteJointDef* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->localAnchorB = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2RevoluteJointDef__get_referenceAngle(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2RevoluteJointDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->referenceAngle);
    return true;
}
static bool b2RevoluteJointDef__set_referenceAngle(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2RevoluteJointDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->referenceAngle)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2RevoluteJointDef__get_enableSpring(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2RevoluteJointDef* self = py_touserdata(argv);
    py_newbool(py_retval(), self->enableSpring);
    return true;
}
static bool b2RevoluteJointDef__set_enableSpring(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2RevoluteJointDef* self = py_touserdata(argv);
    if(!py_checkbool(py_arg(1))) return false;
    self->enableSpring = py_tobool(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2RevoluteJointDef__get_hertz(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2RevoluteJointDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->hertz);
    return true;
}
static bool b2RevoluteJointDef__set_hertz(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2RevoluteJointDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->hertz)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2RevoluteJointDef__get_dampingRatio(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2RevoluteJointDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->dampingRatio);
    return true;
}
static bool b2RevoluteJointDef__set_dampingRatio(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2RevoluteJointDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->dampingRatio)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2RevoluteJointDef__get_enableLimit(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2RevoluteJointDef* self = py_touserdata(argv);
    py_newbool(py_retval(), self->enableLimit);
    return true;
}
static bool b2RevoluteJointDef__set_enableLimit(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2RevoluteJointDef* self = py_touserdata(argv);
    if(!py_checkbool(py_arg(1))) return false;
    self->enableLimit = py_tobool(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2RevoluteJointDef__get_lowerAngle(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2RevoluteJointDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->lowerAngle);
    return true;
}
static bool b2RevoluteJointDef__set_lowerAngle(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2RevoluteJointDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->lowerAngle)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2RevoluteJointDef__get_upperAngle(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2RevoluteJointDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->upperAngle);
    return true;
}
static bool b2RevoluteJointDef__set_upperAngle(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2RevoluteJointDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->upperAngle)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2RevoluteJointDef__get_enableMotor(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2RevoluteJointDef* self = py_touserdata(argv);
    py_newbool(py_retval(), self->enableMotor);
    return true;
}
static bool b2RevoluteJointDef__set_enableMotor(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2RevoluteJointDef* self = py_touserdata(argv);
    if(!py_checkbool(py_arg(1))) return false;
    self->enableMotor = py_tobool(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2RevoluteJointDef__get_maxMotorTorque(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2RevoluteJointDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->maxMotorTorque);
    return true;
}
static bool b2RevoluteJointDef__set_maxMotorTorque(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2RevoluteJointDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->maxMotorTorque)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2RevoluteJointDef__get_motorSpeed(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2RevoluteJointDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->motorSpeed);
    return true;
}
static bool b2RevoluteJointDef__set_motorSpeed(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2RevoluteJointDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->motorSpeed)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2RevoluteJointDef__get_drawSize(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2RevoluteJointDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->drawSize);
    return true;
}
static bool b2RevoluteJointDef__set_drawSize(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2RevoluteJointDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->drawSize)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2RevoluteJointDef__get_collideConnected(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2RevoluteJointDef* self = py_touserdata(argv);
    py_newbool(py_retval(), self->collideConnected);
    return true;
}
static bool b2RevoluteJointDef__set_collideConnected(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2RevoluteJointDef* self = py_touserdata(argv);
    if(!py_checkbool(py_arg(1))) return false;
    self->collideConnected = py_tobool(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2RevoluteJointDef__get_userData(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2RevoluteJointDef* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->userData);
    return true;
}
static bool b2RevoluteJointDef__set_userData(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2RevoluteJointDef* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->userData = (void*)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2RevoluteJointDef__get_internalValue(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2RevoluteJointDef* self = py_touserdata(argv);
    py_newint(py_retval(), self->internalValue);
    return true;
}
static bool b2RevoluteJointDef__set_internalValue(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2RevoluteJointDef* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->internalValue = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2RevoluteJointDef(py_GlobalRef mod) {
    py_Type type = py_newtype("b2RevoluteJointDef", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2RevoluteJointDef__new__);
    py_bindmagic(type, __init__, b2RevoluteJointDef__init__);
    py_bindmethod(type, "copy", b2RevoluteJointDef__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "bodyIdA", b2RevoluteJointDef__get_bodyIdA, b2RevoluteJointDef__set_bodyIdA);
    py_bindproperty(type, "bodyIdB", b2RevoluteJointDef__get_bodyIdB, b2RevoluteJointDef__set_bodyIdB);
    py_bindproperty(type, "localAnchorA", b2RevoluteJointDef__get_localAnchorA, b2RevoluteJointDef__set_localAnchorA);
    py_bindproperty(type, "localAnchorB", b2RevoluteJointDef__get_localAnchorB, b2RevoluteJointDef__set_localAnchorB);
    py_bindproperty(type, "referenceAngle", b2RevoluteJointDef__get_referenceAngle, b2RevoluteJointDef__set_referenceAngle);
    py_bindproperty(type, "enableSpring", b2RevoluteJointDef__get_enableSpring, b2RevoluteJointDef__set_enableSpring);
    py_bindproperty(type, "hertz", b2RevoluteJointDef__get_hertz, b2RevoluteJointDef__set_hertz);
    py_bindproperty(type, "dampingRatio", b2RevoluteJointDef__get_dampingRatio, b2RevoluteJointDef__set_dampingRatio);
    py_bindproperty(type, "enableLimit", b2RevoluteJointDef__get_enableLimit, b2RevoluteJointDef__set_enableLimit);
    py_bindproperty(type, "lowerAngle", b2RevoluteJointDef__get_lowerAngle, b2RevoluteJointDef__set_lowerAngle);
    py_bindproperty(type, "upperAngle", b2RevoluteJointDef__get_upperAngle, b2RevoluteJointDef__set_upperAngle);
    py_bindproperty(type, "enableMotor", b2RevoluteJointDef__get_enableMotor, b2RevoluteJointDef__set_enableMotor);
    py_bindproperty(type, "maxMotorTorque", b2RevoluteJointDef__get_maxMotorTorque, b2RevoluteJointDef__set_maxMotorTorque);
    py_bindproperty(type, "motorSpeed", b2RevoluteJointDef__get_motorSpeed, b2RevoluteJointDef__set_motorSpeed);
    py_bindproperty(type, "drawSize", b2RevoluteJointDef__get_drawSize, b2RevoluteJointDef__set_drawSize);
    py_bindproperty(type, "collideConnected", b2RevoluteJointDef__get_collideConnected, b2RevoluteJointDef__set_collideConnected);
    py_bindproperty(type, "userData", b2RevoluteJointDef__get_userData, b2RevoluteJointDef__set_userData);
    py_bindproperty(type, "internalValue", b2RevoluteJointDef__get_internalValue, b2RevoluteJointDef__set_internalValue);
    return type;
}
static py_Type tp_user_b2RevoluteJointDef;
static bool b2WeldJointDef__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2WeldJointDef));
    return true;
}
static bool b2WeldJointDef__init__(int argc, py_Ref argv) {
    b2WeldJointDef* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2WeldJointDef));
    } else if(argc == 1 + 12) {
        do {
            if(!py_checktype(py_arg(1), tp_user_b2BodyId)) return false;
            self->bodyIdA = *(b2BodyId*)py_touserdata(py_arg(1));
        } while(0);
        do {
            if(!py_checktype(py_arg(2), tp_user_b2BodyId)) return false;
            self->bodyIdB = *(b2BodyId*)py_touserdata(py_arg(2));
        } while(0);
        do {
            if(!py_checktype(py_arg(3), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(3));
            self->localAnchorA = *(b2Vec2*)(&tmp);
        } while(0);
        do {
            if(!py_checktype(py_arg(4), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(4));
            self->localAnchorB = *(b2Vec2*)(&tmp);
        } while(0);
        if(!py_castfloat32(py_arg(5), &self->referenceAngle)) return false;
        if(!py_castfloat32(py_arg(6), &self->linearHertz)) return false;
        if(!py_castfloat32(py_arg(7), &self->angularHertz)) return false;
        if(!py_castfloat32(py_arg(8), &self->linearDampingRatio)) return false;
        if(!py_castfloat32(py_arg(9), &self->angularDampingRatio)) return false;
        if(!py_checkbool(py_arg(10))) return false;
        self->collideConnected = py_tobool(py_arg(10));
        if(!py_checkint(py_arg(11))) return false;
        self->userData = (void*)py_toint(py_arg(11));
        if(!py_checkint(py_arg(12))) return false;
        self->internalValue = py_toint(py_arg(12));
    } else {
        return TypeError("expected 1 or 13 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2WeldJointDef__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WeldJointDef* self = py_touserdata(argv);
    b2WeldJointDef* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2WeldJointDef));
    *res = *self;
    return true;
}
static bool b2WeldJointDef__get_bodyIdA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WeldJointDef* self = py_touserdata(argv);
    do {
        b2BodyId* ud = py_newobject(py_retval(), tp_user_b2BodyId, 0, sizeof(b2BodyId));
        *ud = self->bodyIdA;
    } while(0);
    return true;
}
static bool b2WeldJointDef__set_bodyIdA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WeldJointDef* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2BodyId)) return false;
        self->bodyIdA = *(b2BodyId*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2WeldJointDef__get_bodyIdB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WeldJointDef* self = py_touserdata(argv);
    do {
        b2BodyId* ud = py_newobject(py_retval(), tp_user_b2BodyId, 0, sizeof(b2BodyId));
        *ud = self->bodyIdB;
    } while(0);
    return true;
}
static bool b2WeldJointDef__set_bodyIdB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WeldJointDef* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2BodyId)) return false;
        self->bodyIdB = *(b2BodyId*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2WeldJointDef__get_localAnchorA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WeldJointDef* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->localAnchorA));
    return true;
}
static bool b2WeldJointDef__set_localAnchorA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WeldJointDef* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->localAnchorA = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2WeldJointDef__get_localAnchorB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WeldJointDef* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->localAnchorB));
    return true;
}
static bool b2WeldJointDef__set_localAnchorB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WeldJointDef* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->localAnchorB = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2WeldJointDef__get_referenceAngle(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WeldJointDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->referenceAngle);
    return true;
}
static bool b2WeldJointDef__set_referenceAngle(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WeldJointDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->referenceAngle)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2WeldJointDef__get_linearHertz(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WeldJointDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->linearHertz);
    return true;
}
static bool b2WeldJointDef__set_linearHertz(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WeldJointDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->linearHertz)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2WeldJointDef__get_angularHertz(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WeldJointDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->angularHertz);
    return true;
}
static bool b2WeldJointDef__set_angularHertz(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WeldJointDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->angularHertz)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2WeldJointDef__get_linearDampingRatio(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WeldJointDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->linearDampingRatio);
    return true;
}
static bool b2WeldJointDef__set_linearDampingRatio(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WeldJointDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->linearDampingRatio)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2WeldJointDef__get_angularDampingRatio(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WeldJointDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->angularDampingRatio);
    return true;
}
static bool b2WeldJointDef__set_angularDampingRatio(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WeldJointDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->angularDampingRatio)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2WeldJointDef__get_collideConnected(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WeldJointDef* self = py_touserdata(argv);
    py_newbool(py_retval(), self->collideConnected);
    return true;
}
static bool b2WeldJointDef__set_collideConnected(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WeldJointDef* self = py_touserdata(argv);
    if(!py_checkbool(py_arg(1))) return false;
    self->collideConnected = py_tobool(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2WeldJointDef__get_userData(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WeldJointDef* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->userData);
    return true;
}
static bool b2WeldJointDef__set_userData(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WeldJointDef* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->userData = (void*)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2WeldJointDef__get_internalValue(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WeldJointDef* self = py_touserdata(argv);
    py_newint(py_retval(), self->internalValue);
    return true;
}
static bool b2WeldJointDef__set_internalValue(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WeldJointDef* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->internalValue = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2WeldJointDef(py_GlobalRef mod) {
    py_Type type = py_newtype("b2WeldJointDef", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2WeldJointDef__new__);
    py_bindmagic(type, __init__, b2WeldJointDef__init__);
    py_bindmethod(type, "copy", b2WeldJointDef__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "bodyIdA", b2WeldJointDef__get_bodyIdA, b2WeldJointDef__set_bodyIdA);
    py_bindproperty(type, "bodyIdB", b2WeldJointDef__get_bodyIdB, b2WeldJointDef__set_bodyIdB);
    py_bindproperty(type, "localAnchorA", b2WeldJointDef__get_localAnchorA, b2WeldJointDef__set_localAnchorA);
    py_bindproperty(type, "localAnchorB", b2WeldJointDef__get_localAnchorB, b2WeldJointDef__set_localAnchorB);
    py_bindproperty(type, "referenceAngle", b2WeldJointDef__get_referenceAngle, b2WeldJointDef__set_referenceAngle);
    py_bindproperty(type, "linearHertz", b2WeldJointDef__get_linearHertz, b2WeldJointDef__set_linearHertz);
    py_bindproperty(type, "angularHertz", b2WeldJointDef__get_angularHertz, b2WeldJointDef__set_angularHertz);
    py_bindproperty(type, "linearDampingRatio", b2WeldJointDef__get_linearDampingRatio, b2WeldJointDef__set_linearDampingRatio);
    py_bindproperty(type, "angularDampingRatio", b2WeldJointDef__get_angularDampingRatio, b2WeldJointDef__set_angularDampingRatio);
    py_bindproperty(type, "collideConnected", b2WeldJointDef__get_collideConnected, b2WeldJointDef__set_collideConnected);
    py_bindproperty(type, "userData", b2WeldJointDef__get_userData, b2WeldJointDef__set_userData);
    py_bindproperty(type, "internalValue", b2WeldJointDef__get_internalValue, b2WeldJointDef__set_internalValue);
    return type;
}
static py_Type tp_user_b2WeldJointDef;
static bool b2WheelJointDef__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2WheelJointDef));
    return true;
}
static bool b2WheelJointDef__init__(int argc, py_Ref argv) {
    b2WheelJointDef* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2WheelJointDef));
    } else if(argc == 1 + 17) {
        do {
            if(!py_checktype(py_arg(1), tp_user_b2BodyId)) return false;
            self->bodyIdA = *(b2BodyId*)py_touserdata(py_arg(1));
        } while(0);
        do {
            if(!py_checktype(py_arg(2), tp_user_b2BodyId)) return false;
            self->bodyIdB = *(b2BodyId*)py_touserdata(py_arg(2));
        } while(0);
        do {
            if(!py_checktype(py_arg(3), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(3));
            self->localAnchorA = *(b2Vec2*)(&tmp);
        } while(0);
        do {
            if(!py_checktype(py_arg(4), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(4));
            self->localAnchorB = *(b2Vec2*)(&tmp);
        } while(0);
        do {
            if(!py_checktype(py_arg(5), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(5));
            self->localAxisA = *(b2Vec2*)(&tmp);
        } while(0);
        if(!py_checkbool(py_arg(6))) return false;
        self->enableSpring = py_tobool(py_arg(6));
        if(!py_castfloat32(py_arg(7), &self->hertz)) return false;
        if(!py_castfloat32(py_arg(8), &self->dampingRatio)) return false;
        if(!py_checkbool(py_arg(9))) return false;
        self->enableLimit = py_tobool(py_arg(9));
        if(!py_castfloat32(py_arg(10), &self->lowerTranslation)) return false;
        if(!py_castfloat32(py_arg(11), &self->upperTranslation)) return false;
        if(!py_checkbool(py_arg(12))) return false;
        self->enableMotor = py_tobool(py_arg(12));
        if(!py_castfloat32(py_arg(13), &self->maxMotorTorque)) return false;
        if(!py_castfloat32(py_arg(14), &self->motorSpeed)) return false;
        if(!py_checkbool(py_arg(15))) return false;
        self->collideConnected = py_tobool(py_arg(15));
        if(!py_checkint(py_arg(16))) return false;
        self->userData = (void*)py_toint(py_arg(16));
        if(!py_checkint(py_arg(17))) return false;
        self->internalValue = py_toint(py_arg(17));
    } else {
        return TypeError("expected 1 or 18 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2WheelJointDef__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WheelJointDef* self = py_touserdata(argv);
    b2WheelJointDef* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2WheelJointDef));
    *res = *self;
    return true;
}
static bool b2WheelJointDef__get_bodyIdA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WheelJointDef* self = py_touserdata(argv);
    do {
        b2BodyId* ud = py_newobject(py_retval(), tp_user_b2BodyId, 0, sizeof(b2BodyId));
        *ud = self->bodyIdA;
    } while(0);
    return true;
}
static bool b2WheelJointDef__set_bodyIdA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WheelJointDef* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2BodyId)) return false;
        self->bodyIdA = *(b2BodyId*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2WheelJointDef__get_bodyIdB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WheelJointDef* self = py_touserdata(argv);
    do {
        b2BodyId* ud = py_newobject(py_retval(), tp_user_b2BodyId, 0, sizeof(b2BodyId));
        *ud = self->bodyIdB;
    } while(0);
    return true;
}
static bool b2WheelJointDef__set_bodyIdB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WheelJointDef* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2BodyId)) return false;
        self->bodyIdB = *(b2BodyId*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2WheelJointDef__get_localAnchorA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WheelJointDef* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->localAnchorA));
    return true;
}
static bool b2WheelJointDef__set_localAnchorA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WheelJointDef* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->localAnchorA = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2WheelJointDef__get_localAnchorB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WheelJointDef* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->localAnchorB));
    return true;
}
static bool b2WheelJointDef__set_localAnchorB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WheelJointDef* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->localAnchorB = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2WheelJointDef__get_localAxisA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WheelJointDef* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->localAxisA));
    return true;
}
static bool b2WheelJointDef__set_localAxisA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WheelJointDef* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->localAxisA = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2WheelJointDef__get_enableSpring(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WheelJointDef* self = py_touserdata(argv);
    py_newbool(py_retval(), self->enableSpring);
    return true;
}
static bool b2WheelJointDef__set_enableSpring(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WheelJointDef* self = py_touserdata(argv);
    if(!py_checkbool(py_arg(1))) return false;
    self->enableSpring = py_tobool(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2WheelJointDef__get_hertz(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WheelJointDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->hertz);
    return true;
}
static bool b2WheelJointDef__set_hertz(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WheelJointDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->hertz)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2WheelJointDef__get_dampingRatio(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WheelJointDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->dampingRatio);
    return true;
}
static bool b2WheelJointDef__set_dampingRatio(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WheelJointDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->dampingRatio)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2WheelJointDef__get_enableLimit(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WheelJointDef* self = py_touserdata(argv);
    py_newbool(py_retval(), self->enableLimit);
    return true;
}
static bool b2WheelJointDef__set_enableLimit(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WheelJointDef* self = py_touserdata(argv);
    if(!py_checkbool(py_arg(1))) return false;
    self->enableLimit = py_tobool(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2WheelJointDef__get_lowerTranslation(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WheelJointDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->lowerTranslation);
    return true;
}
static bool b2WheelJointDef__set_lowerTranslation(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WheelJointDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->lowerTranslation)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2WheelJointDef__get_upperTranslation(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WheelJointDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->upperTranslation);
    return true;
}
static bool b2WheelJointDef__set_upperTranslation(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WheelJointDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->upperTranslation)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2WheelJointDef__get_enableMotor(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WheelJointDef* self = py_touserdata(argv);
    py_newbool(py_retval(), self->enableMotor);
    return true;
}
static bool b2WheelJointDef__set_enableMotor(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WheelJointDef* self = py_touserdata(argv);
    if(!py_checkbool(py_arg(1))) return false;
    self->enableMotor = py_tobool(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2WheelJointDef__get_maxMotorTorque(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WheelJointDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->maxMotorTorque);
    return true;
}
static bool b2WheelJointDef__set_maxMotorTorque(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WheelJointDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->maxMotorTorque)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2WheelJointDef__get_motorSpeed(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WheelJointDef* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->motorSpeed);
    return true;
}
static bool b2WheelJointDef__set_motorSpeed(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WheelJointDef* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->motorSpeed)) return false;
    py_newnone(py_retval());
    return true;
}
static bool b2WheelJointDef__get_collideConnected(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WheelJointDef* self = py_touserdata(argv);
    py_newbool(py_retval(), self->collideConnected);
    return true;
}
static bool b2WheelJointDef__set_collideConnected(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WheelJointDef* self = py_touserdata(argv);
    if(!py_checkbool(py_arg(1))) return false;
    self->collideConnected = py_tobool(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2WheelJointDef__get_userData(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WheelJointDef* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->userData);
    return true;
}
static bool b2WheelJointDef__set_userData(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WheelJointDef* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->userData = (void*)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2WheelJointDef__get_internalValue(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2WheelJointDef* self = py_touserdata(argv);
    py_newint(py_retval(), self->internalValue);
    return true;
}
static bool b2WheelJointDef__set_internalValue(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2WheelJointDef* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->internalValue = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2WheelJointDef(py_GlobalRef mod) {
    py_Type type = py_newtype("b2WheelJointDef", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2WheelJointDef__new__);
    py_bindmagic(type, __init__, b2WheelJointDef__init__);
    py_bindmethod(type, "copy", b2WheelJointDef__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "bodyIdA", b2WheelJointDef__get_bodyIdA, b2WheelJointDef__set_bodyIdA);
    py_bindproperty(type, "bodyIdB", b2WheelJointDef__get_bodyIdB, b2WheelJointDef__set_bodyIdB);
    py_bindproperty(type, "localAnchorA", b2WheelJointDef__get_localAnchorA, b2WheelJointDef__set_localAnchorA);
    py_bindproperty(type, "localAnchorB", b2WheelJointDef__get_localAnchorB, b2WheelJointDef__set_localAnchorB);
    py_bindproperty(type, "localAxisA", b2WheelJointDef__get_localAxisA, b2WheelJointDef__set_localAxisA);
    py_bindproperty(type, "enableSpring", b2WheelJointDef__get_enableSpring, b2WheelJointDef__set_enableSpring);
    py_bindproperty(type, "hertz", b2WheelJointDef__get_hertz, b2WheelJointDef__set_hertz);
    py_bindproperty(type, "dampingRatio", b2WheelJointDef__get_dampingRatio, b2WheelJointDef__set_dampingRatio);
    py_bindproperty(type, "enableLimit", b2WheelJointDef__get_enableLimit, b2WheelJointDef__set_enableLimit);
    py_bindproperty(type, "lowerTranslation", b2WheelJointDef__get_lowerTranslation, b2WheelJointDef__set_lowerTranslation);
    py_bindproperty(type, "upperTranslation", b2WheelJointDef__get_upperTranslation, b2WheelJointDef__set_upperTranslation);
    py_bindproperty(type, "enableMotor", b2WheelJointDef__get_enableMotor, b2WheelJointDef__set_enableMotor);
    py_bindproperty(type, "maxMotorTorque", b2WheelJointDef__get_maxMotorTorque, b2WheelJointDef__set_maxMotorTorque);
    py_bindproperty(type, "motorSpeed", b2WheelJointDef__get_motorSpeed, b2WheelJointDef__set_motorSpeed);
    py_bindproperty(type, "collideConnected", b2WheelJointDef__get_collideConnected, b2WheelJointDef__set_collideConnected);
    py_bindproperty(type, "userData", b2WheelJointDef__get_userData, b2WheelJointDef__set_userData);
    py_bindproperty(type, "internalValue", b2WheelJointDef__get_internalValue, b2WheelJointDef__set_internalValue);
    return type;
}
static py_Type tp_user_b2WheelJointDef;
static bool b2SensorBeginTouchEvent__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2SensorBeginTouchEvent));
    return true;
}
static bool b2SensorBeginTouchEvent__init__(int argc, py_Ref argv) {
    b2SensorBeginTouchEvent* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2SensorBeginTouchEvent));
    } else if(argc == 1 + 2) {
        do {
            if(!py_checktype(py_arg(1), tp_user_b2ShapeId)) return false;
            self->sensorShapeId = *(b2ShapeId*)py_touserdata(py_arg(1));
        } while(0);
        do {
            if(!py_checktype(py_arg(2), tp_user_b2ShapeId)) return false;
            self->visitorShapeId = *(b2ShapeId*)py_touserdata(py_arg(2));
        } while(0);
    } else {
        return TypeError("expected 1 or 3 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2SensorBeginTouchEvent__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2SensorBeginTouchEvent* self = py_touserdata(argv);
    b2SensorBeginTouchEvent* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2SensorBeginTouchEvent));
    *res = *self;
    return true;
}
static bool b2SensorBeginTouchEvent__get_sensorShapeId(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2SensorBeginTouchEvent* self = py_touserdata(argv);
    do {
        b2ShapeId* ud = py_newobject(py_retval(), tp_user_b2ShapeId, 0, sizeof(b2ShapeId));
        *ud = self->sensorShapeId;
    } while(0);
    return true;
}
static bool b2SensorBeginTouchEvent__set_sensorShapeId(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2SensorBeginTouchEvent* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2ShapeId)) return false;
        self->sensorShapeId = *(b2ShapeId*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2SensorBeginTouchEvent__get_visitorShapeId(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2SensorBeginTouchEvent* self = py_touserdata(argv);
    do {
        b2ShapeId* ud = py_newobject(py_retval(), tp_user_b2ShapeId, 0, sizeof(b2ShapeId));
        *ud = self->visitorShapeId;
    } while(0);
    return true;
}
static bool b2SensorBeginTouchEvent__set_visitorShapeId(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2SensorBeginTouchEvent* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2ShapeId)) return false;
        self->visitorShapeId = *(b2ShapeId*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2SensorBeginTouchEvent(py_GlobalRef mod) {
    py_Type type = py_newtype("b2SensorBeginTouchEvent", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2SensorBeginTouchEvent__new__);
    py_bindmagic(type, __init__, b2SensorBeginTouchEvent__init__);
    py_bindmethod(type, "copy", b2SensorBeginTouchEvent__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "sensorShapeId", b2SensorBeginTouchEvent__get_sensorShapeId, b2SensorBeginTouchEvent__set_sensorShapeId);
    py_bindproperty(type, "visitorShapeId", b2SensorBeginTouchEvent__get_visitorShapeId, b2SensorBeginTouchEvent__set_visitorShapeId);
    return type;
}
static py_Type tp_user_b2SensorBeginTouchEvent;
static bool b2SensorEndTouchEvent__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2SensorEndTouchEvent));
    return true;
}
static bool b2SensorEndTouchEvent__init__(int argc, py_Ref argv) {
    b2SensorEndTouchEvent* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2SensorEndTouchEvent));
    } else if(argc == 1 + 2) {
        do {
            if(!py_checktype(py_arg(1), tp_user_b2ShapeId)) return false;
            self->sensorShapeId = *(b2ShapeId*)py_touserdata(py_arg(1));
        } while(0);
        do {
            if(!py_checktype(py_arg(2), tp_user_b2ShapeId)) return false;
            self->visitorShapeId = *(b2ShapeId*)py_touserdata(py_arg(2));
        } while(0);
    } else {
        return TypeError("expected 1 or 3 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2SensorEndTouchEvent__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2SensorEndTouchEvent* self = py_touserdata(argv);
    b2SensorEndTouchEvent* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2SensorEndTouchEvent));
    *res = *self;
    return true;
}
static bool b2SensorEndTouchEvent__get_sensorShapeId(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2SensorEndTouchEvent* self = py_touserdata(argv);
    do {
        b2ShapeId* ud = py_newobject(py_retval(), tp_user_b2ShapeId, 0, sizeof(b2ShapeId));
        *ud = self->sensorShapeId;
    } while(0);
    return true;
}
static bool b2SensorEndTouchEvent__set_sensorShapeId(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2SensorEndTouchEvent* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2ShapeId)) return false;
        self->sensorShapeId = *(b2ShapeId*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2SensorEndTouchEvent__get_visitorShapeId(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2SensorEndTouchEvent* self = py_touserdata(argv);
    do {
        b2ShapeId* ud = py_newobject(py_retval(), tp_user_b2ShapeId, 0, sizeof(b2ShapeId));
        *ud = self->visitorShapeId;
    } while(0);
    return true;
}
static bool b2SensorEndTouchEvent__set_visitorShapeId(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2SensorEndTouchEvent* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2ShapeId)) return false;
        self->visitorShapeId = *(b2ShapeId*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2SensorEndTouchEvent(py_GlobalRef mod) {
    py_Type type = py_newtype("b2SensorEndTouchEvent", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2SensorEndTouchEvent__new__);
    py_bindmagic(type, __init__, b2SensorEndTouchEvent__init__);
    py_bindmethod(type, "copy", b2SensorEndTouchEvent__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "sensorShapeId", b2SensorEndTouchEvent__get_sensorShapeId, b2SensorEndTouchEvent__set_sensorShapeId);
    py_bindproperty(type, "visitorShapeId", b2SensorEndTouchEvent__get_visitorShapeId, b2SensorEndTouchEvent__set_visitorShapeId);
    return type;
}
static py_Type tp_user_b2SensorEndTouchEvent;
static bool b2SensorEvents__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2SensorEvents));
    return true;
}
static bool b2SensorEvents__init__(int argc, py_Ref argv) {
    b2SensorEvents* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2SensorEvents));
    } else if(argc == 1 + 4) {
        if(!py_checkint(py_arg(1))) return false;
        self->beginEvents = (b2SensorBeginTouchEvent*)py_toint(py_arg(1));
        if(!py_checkint(py_arg(2))) return false;
        self->endEvents = (b2SensorEndTouchEvent*)py_toint(py_arg(2));
        if(!py_checkint(py_arg(3))) return false;
        self->beginCount = py_toint(py_arg(3));
        if(!py_checkint(py_arg(4))) return false;
        self->endCount = py_toint(py_arg(4));
    } else {
        return TypeError("expected 1 or 5 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2SensorEvents__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2SensorEvents* self = py_touserdata(argv);
    b2SensorEvents* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2SensorEvents));
    *res = *self;
    return true;
}
static bool b2SensorEvents__get_beginEvents(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2SensorEvents* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->beginEvents);
    return true;
}
static bool b2SensorEvents__set_beginEvents(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2SensorEvents* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->beginEvents = (b2SensorBeginTouchEvent*)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2SensorEvents__get_endEvents(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2SensorEvents* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->endEvents);
    return true;
}
static bool b2SensorEvents__set_endEvents(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2SensorEvents* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->endEvents = (b2SensorEndTouchEvent*)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2SensorEvents__get_beginCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2SensorEvents* self = py_touserdata(argv);
    py_newint(py_retval(), self->beginCount);
    return true;
}
static bool b2SensorEvents__set_beginCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2SensorEvents* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->beginCount = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2SensorEvents__get_endCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2SensorEvents* self = py_touserdata(argv);
    py_newint(py_retval(), self->endCount);
    return true;
}
static bool b2SensorEvents__set_endCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2SensorEvents* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->endCount = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2SensorEvents(py_GlobalRef mod) {
    py_Type type = py_newtype("b2SensorEvents", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2SensorEvents__new__);
    py_bindmagic(type, __init__, b2SensorEvents__init__);
    py_bindmethod(type, "copy", b2SensorEvents__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "beginEvents", b2SensorEvents__get_beginEvents, b2SensorEvents__set_beginEvents);
    py_bindproperty(type, "endEvents", b2SensorEvents__get_endEvents, b2SensorEvents__set_endEvents);
    py_bindproperty(type, "beginCount", b2SensorEvents__get_beginCount, b2SensorEvents__set_beginCount);
    py_bindproperty(type, "endCount", b2SensorEvents__get_endCount, b2SensorEvents__set_endCount);
    return type;
}
static py_Type tp_user_b2SensorEvents;
static bool b2ContactBeginTouchEvent__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2ContactBeginTouchEvent));
    return true;
}
static bool b2ContactBeginTouchEvent__init__(int argc, py_Ref argv) {
    b2ContactBeginTouchEvent* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2ContactBeginTouchEvent));
    } else if(argc == 1 + 2) {
        do {
            if(!py_checktype(py_arg(1), tp_user_b2ShapeId)) return false;
            self->shapeIdA = *(b2ShapeId*)py_touserdata(py_arg(1));
        } while(0);
        do {
            if(!py_checktype(py_arg(2), tp_user_b2ShapeId)) return false;
            self->shapeIdB = *(b2ShapeId*)py_touserdata(py_arg(2));
        } while(0);
    } else {
        return TypeError("expected 1 or 3 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2ContactBeginTouchEvent__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ContactBeginTouchEvent* self = py_touserdata(argv);
    b2ContactBeginTouchEvent* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2ContactBeginTouchEvent));
    *res = *self;
    return true;
}
static bool b2ContactBeginTouchEvent__get_shapeIdA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ContactBeginTouchEvent* self = py_touserdata(argv);
    do {
        b2ShapeId* ud = py_newobject(py_retval(), tp_user_b2ShapeId, 0, sizeof(b2ShapeId));
        *ud = self->shapeIdA;
    } while(0);
    return true;
}
static bool b2ContactBeginTouchEvent__set_shapeIdA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ContactBeginTouchEvent* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2ShapeId)) return false;
        self->shapeIdA = *(b2ShapeId*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2ContactBeginTouchEvent__get_shapeIdB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ContactBeginTouchEvent* self = py_touserdata(argv);
    do {
        b2ShapeId* ud = py_newobject(py_retval(), tp_user_b2ShapeId, 0, sizeof(b2ShapeId));
        *ud = self->shapeIdB;
    } while(0);
    return true;
}
static bool b2ContactBeginTouchEvent__set_shapeIdB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ContactBeginTouchEvent* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2ShapeId)) return false;
        self->shapeIdB = *(b2ShapeId*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2ContactBeginTouchEvent(py_GlobalRef mod) {
    py_Type type = py_newtype("b2ContactBeginTouchEvent", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2ContactBeginTouchEvent__new__);
    py_bindmagic(type, __init__, b2ContactBeginTouchEvent__init__);
    py_bindmethod(type, "copy", b2ContactBeginTouchEvent__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "shapeIdA", b2ContactBeginTouchEvent__get_shapeIdA, b2ContactBeginTouchEvent__set_shapeIdA);
    py_bindproperty(type, "shapeIdB", b2ContactBeginTouchEvent__get_shapeIdB, b2ContactBeginTouchEvent__set_shapeIdB);
    return type;
}
static py_Type tp_user_b2ContactBeginTouchEvent;
static bool b2ContactEndTouchEvent__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2ContactEndTouchEvent));
    return true;
}
static bool b2ContactEndTouchEvent__init__(int argc, py_Ref argv) {
    b2ContactEndTouchEvent* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2ContactEndTouchEvent));
    } else if(argc == 1 + 2) {
        do {
            if(!py_checktype(py_arg(1), tp_user_b2ShapeId)) return false;
            self->shapeIdA = *(b2ShapeId*)py_touserdata(py_arg(1));
        } while(0);
        do {
            if(!py_checktype(py_arg(2), tp_user_b2ShapeId)) return false;
            self->shapeIdB = *(b2ShapeId*)py_touserdata(py_arg(2));
        } while(0);
    } else {
        return TypeError("expected 1 or 3 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2ContactEndTouchEvent__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ContactEndTouchEvent* self = py_touserdata(argv);
    b2ContactEndTouchEvent* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2ContactEndTouchEvent));
    *res = *self;
    return true;
}
static bool b2ContactEndTouchEvent__get_shapeIdA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ContactEndTouchEvent* self = py_touserdata(argv);
    do {
        b2ShapeId* ud = py_newobject(py_retval(), tp_user_b2ShapeId, 0, sizeof(b2ShapeId));
        *ud = self->shapeIdA;
    } while(0);
    return true;
}
static bool b2ContactEndTouchEvent__set_shapeIdA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ContactEndTouchEvent* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2ShapeId)) return false;
        self->shapeIdA = *(b2ShapeId*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2ContactEndTouchEvent__get_shapeIdB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ContactEndTouchEvent* self = py_touserdata(argv);
    do {
        b2ShapeId* ud = py_newobject(py_retval(), tp_user_b2ShapeId, 0, sizeof(b2ShapeId));
        *ud = self->shapeIdB;
    } while(0);
    return true;
}
static bool b2ContactEndTouchEvent__set_shapeIdB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ContactEndTouchEvent* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2ShapeId)) return false;
        self->shapeIdB = *(b2ShapeId*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2ContactEndTouchEvent(py_GlobalRef mod) {
    py_Type type = py_newtype("b2ContactEndTouchEvent", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2ContactEndTouchEvent__new__);
    py_bindmagic(type, __init__, b2ContactEndTouchEvent__init__);
    py_bindmethod(type, "copy", b2ContactEndTouchEvent__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "shapeIdA", b2ContactEndTouchEvent__get_shapeIdA, b2ContactEndTouchEvent__set_shapeIdA);
    py_bindproperty(type, "shapeIdB", b2ContactEndTouchEvent__get_shapeIdB, b2ContactEndTouchEvent__set_shapeIdB);
    return type;
}
static py_Type tp_user_b2ContactEndTouchEvent;
static bool b2ContactHitEvent__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2ContactHitEvent));
    return true;
}
static bool b2ContactHitEvent__init__(int argc, py_Ref argv) {
    b2ContactHitEvent* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2ContactHitEvent));
    } else if(argc == 1 + 5) {
        do {
            if(!py_checktype(py_arg(1), tp_user_b2ShapeId)) return false;
            self->shapeIdA = *(b2ShapeId*)py_touserdata(py_arg(1));
        } while(0);
        do {
            if(!py_checktype(py_arg(2), tp_user_b2ShapeId)) return false;
            self->shapeIdB = *(b2ShapeId*)py_touserdata(py_arg(2));
        } while(0);
        do {
            if(!py_checktype(py_arg(3), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(3));
            self->point = *(b2Vec2*)(&tmp);
        } while(0);
        do {
            if(!py_checktype(py_arg(4), tp_vec2)) return false;
            c11_vec2 tmp = py_tovec2(py_arg(4));
            self->normal = *(b2Vec2*)(&tmp);
        } while(0);
        if(!py_castfloat32(py_arg(5), &self->approachSpeed)) return false;
    } else {
        return TypeError("expected 1 or 6 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2ContactHitEvent__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ContactHitEvent* self = py_touserdata(argv);
    b2ContactHitEvent* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2ContactHitEvent));
    *res = *self;
    return true;
}
static bool b2ContactHitEvent__get_shapeIdA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ContactHitEvent* self = py_touserdata(argv);
    do {
        b2ShapeId* ud = py_newobject(py_retval(), tp_user_b2ShapeId, 0, sizeof(b2ShapeId));
        *ud = self->shapeIdA;
    } while(0);
    return true;
}
static bool b2ContactHitEvent__set_shapeIdA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ContactHitEvent* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2ShapeId)) return false;
        self->shapeIdA = *(b2ShapeId*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2ContactHitEvent__get_shapeIdB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ContactHitEvent* self = py_touserdata(argv);
    do {
        b2ShapeId* ud = py_newobject(py_retval(), tp_user_b2ShapeId, 0, sizeof(b2ShapeId));
        *ud = self->shapeIdB;
    } while(0);
    return true;
}
static bool b2ContactHitEvent__set_shapeIdB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ContactHitEvent* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2ShapeId)) return false;
        self->shapeIdB = *(b2ShapeId*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2ContactHitEvent__get_point(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ContactHitEvent* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->point));
    return true;
}
static bool b2ContactHitEvent__set_point(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ContactHitEvent* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->point = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2ContactHitEvent__get_normal(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ContactHitEvent* self = py_touserdata(argv);
    py_newvec2(py_retval(), *(c11_vec2*)(&self->normal));
    return true;
}
static bool b2ContactHitEvent__set_normal(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ContactHitEvent* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        self->normal = *(b2Vec2*)(&tmp);
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2ContactHitEvent__get_approachSpeed(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ContactHitEvent* self = py_touserdata(argv);
    py_newfloat(py_retval(), self->approachSpeed);
    return true;
}
static bool b2ContactHitEvent__set_approachSpeed(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ContactHitEvent* self = py_touserdata(argv);
    if(!py_castfloat32(py_arg(1), &self->approachSpeed)) return false;
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2ContactHitEvent(py_GlobalRef mod) {
    py_Type type = py_newtype("b2ContactHitEvent", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2ContactHitEvent__new__);
    py_bindmagic(type, __init__, b2ContactHitEvent__init__);
    py_bindmethod(type, "copy", b2ContactHitEvent__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "shapeIdA", b2ContactHitEvent__get_shapeIdA, b2ContactHitEvent__set_shapeIdA);
    py_bindproperty(type, "shapeIdB", b2ContactHitEvent__get_shapeIdB, b2ContactHitEvent__set_shapeIdB);
    py_bindproperty(type, "point", b2ContactHitEvent__get_point, b2ContactHitEvent__set_point);
    py_bindproperty(type, "normal", b2ContactHitEvent__get_normal, b2ContactHitEvent__set_normal);
    py_bindproperty(type, "approachSpeed", b2ContactHitEvent__get_approachSpeed, b2ContactHitEvent__set_approachSpeed);
    return type;
}
static py_Type tp_user_b2ContactHitEvent;
static bool b2ContactEvents__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2ContactEvents));
    return true;
}
static bool b2ContactEvents__init__(int argc, py_Ref argv) {
    b2ContactEvents* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2ContactEvents));
    } else if(argc == 1 + 6) {
        if(!py_checkint(py_arg(1))) return false;
        self->beginEvents = (b2ContactBeginTouchEvent*)py_toint(py_arg(1));
        if(!py_checkint(py_arg(2))) return false;
        self->endEvents = (b2ContactEndTouchEvent*)py_toint(py_arg(2));
        if(!py_checkint(py_arg(3))) return false;
        self->hitEvents = (b2ContactHitEvent*)py_toint(py_arg(3));
        if(!py_checkint(py_arg(4))) return false;
        self->beginCount = py_toint(py_arg(4));
        if(!py_checkint(py_arg(5))) return false;
        self->endCount = py_toint(py_arg(5));
        if(!py_checkint(py_arg(6))) return false;
        self->hitCount = py_toint(py_arg(6));
    } else {
        return TypeError("expected 1 or 7 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2ContactEvents__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ContactEvents* self = py_touserdata(argv);
    b2ContactEvents* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2ContactEvents));
    *res = *self;
    return true;
}
static bool b2ContactEvents__get_beginEvents(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ContactEvents* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->beginEvents);
    return true;
}
static bool b2ContactEvents__set_beginEvents(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ContactEvents* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->beginEvents = (b2ContactBeginTouchEvent*)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2ContactEvents__get_endEvents(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ContactEvents* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->endEvents);
    return true;
}
static bool b2ContactEvents__set_endEvents(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ContactEvents* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->endEvents = (b2ContactEndTouchEvent*)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2ContactEvents__get_hitEvents(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ContactEvents* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->hitEvents);
    return true;
}
static bool b2ContactEvents__set_hitEvents(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ContactEvents* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->hitEvents = (b2ContactHitEvent*)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2ContactEvents__get_beginCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ContactEvents* self = py_touserdata(argv);
    py_newint(py_retval(), self->beginCount);
    return true;
}
static bool b2ContactEvents__set_beginCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ContactEvents* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->beginCount = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2ContactEvents__get_endCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ContactEvents* self = py_touserdata(argv);
    py_newint(py_retval(), self->endCount);
    return true;
}
static bool b2ContactEvents__set_endCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ContactEvents* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->endCount = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2ContactEvents__get_hitCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ContactEvents* self = py_touserdata(argv);
    py_newint(py_retval(), self->hitCount);
    return true;
}
static bool b2ContactEvents__set_hitCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ContactEvents* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->hitCount = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2ContactEvents(py_GlobalRef mod) {
    py_Type type = py_newtype("b2ContactEvents", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2ContactEvents__new__);
    py_bindmagic(type, __init__, b2ContactEvents__init__);
    py_bindmethod(type, "copy", b2ContactEvents__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "beginEvents", b2ContactEvents__get_beginEvents, b2ContactEvents__set_beginEvents);
    py_bindproperty(type, "endEvents", b2ContactEvents__get_endEvents, b2ContactEvents__set_endEvents);
    py_bindproperty(type, "hitEvents", b2ContactEvents__get_hitEvents, b2ContactEvents__set_hitEvents);
    py_bindproperty(type, "beginCount", b2ContactEvents__get_beginCount, b2ContactEvents__set_beginCount);
    py_bindproperty(type, "endCount", b2ContactEvents__get_endCount, b2ContactEvents__set_endCount);
    py_bindproperty(type, "hitCount", b2ContactEvents__get_hitCount, b2ContactEvents__set_hitCount);
    return type;
}
static py_Type tp_user_b2ContactEvents;
static bool b2BodyMoveEvent__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2BodyMoveEvent));
    return true;
}
static bool b2BodyMoveEvent__init__(int argc, py_Ref argv) {
    b2BodyMoveEvent* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2BodyMoveEvent));
    } else if(argc == 1 + 4) {
        do {
            if(!py_checktype(py_arg(1), tp_user_b2Transform)) return false;
            self->transform = *(b2Transform*)py_touserdata(py_arg(1));
        } while(0);
        do {
            if(!py_checktype(py_arg(2), tp_user_b2BodyId)) return false;
            self->bodyId = *(b2BodyId*)py_touserdata(py_arg(2));
        } while(0);
        if(!py_checkint(py_arg(3))) return false;
        self->userData = (void*)py_toint(py_arg(3));
        if(!py_checkbool(py_arg(4))) return false;
        self->fellAsleep = py_tobool(py_arg(4));
    } else {
        return TypeError("expected 1 or 5 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2BodyMoveEvent__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2BodyMoveEvent* self = py_touserdata(argv);
    b2BodyMoveEvent* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2BodyMoveEvent));
    *res = *self;
    return true;
}
static bool b2BodyMoveEvent__get_transform(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2BodyMoveEvent* self = py_touserdata(argv);
    do {
        b2Transform* ud = py_newobject(py_retval(), tp_user_b2Transform, 0, sizeof(b2Transform));
        *ud = self->transform;
    } while(0);
    return true;
}
static bool b2BodyMoveEvent__set_transform(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2BodyMoveEvent* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2Transform)) return false;
        self->transform = *(b2Transform*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2BodyMoveEvent__get_bodyId(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2BodyMoveEvent* self = py_touserdata(argv);
    do {
        b2BodyId* ud = py_newobject(py_retval(), tp_user_b2BodyId, 0, sizeof(b2BodyId));
        *ud = self->bodyId;
    } while(0);
    return true;
}
static bool b2BodyMoveEvent__set_bodyId(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2BodyMoveEvent* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2BodyId)) return false;
        self->bodyId = *(b2BodyId*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2BodyMoveEvent__get_userData(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2BodyMoveEvent* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->userData);
    return true;
}
static bool b2BodyMoveEvent__set_userData(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2BodyMoveEvent* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->userData = (void*)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2BodyMoveEvent__get_fellAsleep(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2BodyMoveEvent* self = py_touserdata(argv);
    py_newbool(py_retval(), self->fellAsleep);
    return true;
}
static bool b2BodyMoveEvent__set_fellAsleep(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2BodyMoveEvent* self = py_touserdata(argv);
    if(!py_checkbool(py_arg(1))) return false;
    self->fellAsleep = py_tobool(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2BodyMoveEvent(py_GlobalRef mod) {
    py_Type type = py_newtype("b2BodyMoveEvent", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2BodyMoveEvent__new__);
    py_bindmagic(type, __init__, b2BodyMoveEvent__init__);
    py_bindmethod(type, "copy", b2BodyMoveEvent__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "transform", b2BodyMoveEvent__get_transform, b2BodyMoveEvent__set_transform);
    py_bindproperty(type, "bodyId", b2BodyMoveEvent__get_bodyId, b2BodyMoveEvent__set_bodyId);
    py_bindproperty(type, "userData", b2BodyMoveEvent__get_userData, b2BodyMoveEvent__set_userData);
    py_bindproperty(type, "fellAsleep", b2BodyMoveEvent__get_fellAsleep, b2BodyMoveEvent__set_fellAsleep);
    return type;
}
static py_Type tp_user_b2BodyMoveEvent;
static bool b2BodyEvents__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2BodyEvents));
    return true;
}
static bool b2BodyEvents__init__(int argc, py_Ref argv) {
    b2BodyEvents* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2BodyEvents));
    } else if(argc == 1 + 2) {
        if(!py_checkint(py_arg(1))) return false;
        self->moveEvents = (b2BodyMoveEvent*)py_toint(py_arg(1));
        if(!py_checkint(py_arg(2))) return false;
        self->moveCount = py_toint(py_arg(2));
    } else {
        return TypeError("expected 1 or 3 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2BodyEvents__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2BodyEvents* self = py_touserdata(argv);
    b2BodyEvents* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2BodyEvents));
    *res = *self;
    return true;
}
static bool b2BodyEvents__get_moveEvents(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2BodyEvents* self = py_touserdata(argv);
    py_newint(py_retval(), (py_i64)self->moveEvents);
    return true;
}
static bool b2BodyEvents__set_moveEvents(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2BodyEvents* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->moveEvents = (b2BodyMoveEvent*)py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static bool b2BodyEvents__get_moveCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2BodyEvents* self = py_touserdata(argv);
    py_newint(py_retval(), self->moveCount);
    return true;
}
static bool b2BodyEvents__set_moveCount(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2BodyEvents* self = py_touserdata(argv);
    if(!py_checkint(py_arg(1))) return false;
    self->moveCount = py_toint(py_arg(1));
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2BodyEvents(py_GlobalRef mod) {
    py_Type type = py_newtype("b2BodyEvents", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2BodyEvents__new__);
    py_bindmagic(type, __init__, b2BodyEvents__init__);
    py_bindmethod(type, "copy", b2BodyEvents__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "moveEvents", b2BodyEvents__get_moveEvents, b2BodyEvents__set_moveEvents);
    py_bindproperty(type, "moveCount", b2BodyEvents__get_moveCount, b2BodyEvents__set_moveCount);
    return type;
}
static py_Type tp_user_b2BodyEvents;
static bool b2ContactData__new__(int argc, py_Ref argv) {
    py_Type cls = py_totype(argv);
    py_newobject(py_retval(), cls, 0, sizeof(b2ContactData));
    return true;
}
static bool b2ContactData__init__(int argc, py_Ref argv) {
    b2ContactData* self = py_touserdata(argv);
    if(argc == 1) {
        memset(self, 0, sizeof(b2ContactData));
    } else if(argc == 1 + 3) {
        do {
            if(!py_checktype(py_arg(1), tp_user_b2ShapeId)) return false;
            self->shapeIdA = *(b2ShapeId*)py_touserdata(py_arg(1));
        } while(0);
        do {
            if(!py_checktype(py_arg(2), tp_user_b2ShapeId)) return false;
            self->shapeIdB = *(b2ShapeId*)py_touserdata(py_arg(2));
        } while(0);
        do {
            if(!py_checktype(py_arg(3), tp_user_b2Manifold)) return false;
            self->manifold = *(b2Manifold*)py_touserdata(py_arg(3));
        } while(0);
    } else {
        return TypeError("expected 1 or 4 arguments");
    }
    py_newnone(py_retval());
    return true;
}
static bool b2ContactData__copy__(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ContactData* self = py_touserdata(argv);
    b2ContactData* res = py_newobject(py_retval(), py_typeof(argv), 0, sizeof(b2ContactData));
    *res = *self;
    return true;
}
static bool b2ContactData__get_shapeIdA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ContactData* self = py_touserdata(argv);
    do {
        b2ShapeId* ud = py_newobject(py_retval(), tp_user_b2ShapeId, 0, sizeof(b2ShapeId));
        *ud = self->shapeIdA;
    } while(0);
    return true;
}
static bool b2ContactData__set_shapeIdA(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ContactData* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2ShapeId)) return false;
        self->shapeIdA = *(b2ShapeId*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2ContactData__get_shapeIdB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ContactData* self = py_touserdata(argv);
    do {
        b2ShapeId* ud = py_newobject(py_retval(), tp_user_b2ShapeId, 0, sizeof(b2ShapeId));
        *ud = self->shapeIdB;
    } while(0);
    return true;
}
static bool b2ContactData__set_shapeIdB(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ContactData* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2ShapeId)) return false;
        self->shapeIdB = *(b2ShapeId*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static bool b2ContactData__get_manifold(int argc, py_Ref argv) {
    PY_CHECK_ARGC(1);
    b2ContactData* self = py_touserdata(argv);
    do {
        b2Manifold* ud = py_newobject(py_retval(), tp_user_b2Manifold, 0, sizeof(b2Manifold));
        *ud = self->manifold;
    } while(0);
    return true;
}
static bool b2ContactData__set_manifold(int argc, py_Ref argv) {
    PY_CHECK_ARGC(2);
    b2ContactData* self = py_touserdata(argv);
    do {
        if(!py_checktype(py_arg(1), tp_user_b2Manifold)) return false;
        self->manifold = *(b2Manifold*)py_touserdata(py_arg(1));
    } while(0);
    py_newnone(py_retval());
    return true;
}
static py_Type register__b2ContactData(py_GlobalRef mod) {
    py_Type type = py_newtype("b2ContactData", tp_object, mod, NULL);
    py_bindmagic(type, __new__, b2ContactData__new__);
    py_bindmagic(type, __init__, b2ContactData__init__);
    py_bindmethod(type, "copy", b2ContactData__copy__);
    py_bindmethod(type, "addr", struct__address__);
    py_bindproperty(type, "shapeIdA", b2ContactData__get_shapeIdA, b2ContactData__set_shapeIdA);
    py_bindproperty(type, "shapeIdB", b2ContactData__get_shapeIdB, b2ContactData__set_shapeIdB);
    py_bindproperty(type, "manifold", b2ContactData__get_manifold, b2ContactData__set_manifold);
    return type;
}
static py_Type tp_user_b2ContactData;
/* functions */
static bool cfunc__b2SetAllocator(int argc, py_Ref argv) {
    b2AllocFcn* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (b2AllocFcn*)py_toint(py_arg(0));
    b2FreeFcn* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (b2FreeFcn*)py_toint(py_arg(1));
    b2SetAllocator(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2GetByteCount(int argc, py_Ref argv) {
    int res = b2GetByteCount();
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__b2SetAssertFcn(int argc, py_Ref argv) {
    b2AssertFcn* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (b2AssertFcn*)py_toint(py_arg(0));
    b2SetAssertFcn(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2GetVersion(int argc, py_Ref argv) {
    b2Version res = b2GetVersion();
    do {
        b2Version* ud = py_newobject(py_retval(), tp_user_b2Version, 0, sizeof(b2Version));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2GetTicks(int argc, py_Ref argv) {
    b2Timer* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (b2Timer*)py_toint(py_arg(0));
    int res = b2GetTicks(_0);
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__b2GetMilliseconds(int argc, py_Ref argv) {
    const b2Timer* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2Timer*)py_toint(py_arg(0));
    float res = b2GetMilliseconds(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2GetMillisecondsAndReset(int argc, py_Ref argv) {
    b2Timer* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (b2Timer*)py_toint(py_arg(0));
    float res = b2GetMillisecondsAndReset(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2SleepMilliseconds(int argc, py_Ref argv) {
    int _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = py_toint(py_arg(0));
    b2SleepMilliseconds(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Yield(int argc, py_Ref argv) {
    b2Yield();
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Atan2(int argc, py_Ref argv) {
    float _0;
    if(!py_castfloat32(py_arg(0), &_0)) return false;
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    float res = b2Atan2(_0, _1);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2MakeRot(int argc, py_Ref argv) {
    float _0;
    if(!py_castfloat32(py_arg(0), &_0)) return false;
    b2Rot res = b2MakeRot(_0);
    do {
        b2Rot* ud = py_newobject(py_retval(), tp_user_b2Rot, 0, sizeof(b2Rot));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2IsValid(int argc, py_Ref argv) {
    float _0;
    if(!py_castfloat32(py_arg(0), &_0)) return false;
    _Bool res = b2IsValid(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__b2Vec2_IsValid(int argc, py_Ref argv) {
    b2Vec2 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(0));
        _0 = *(b2Vec2*)(&tmp);
    } while(0);
    _Bool res = b2Vec2_IsValid(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__b2Rot_IsValid(int argc, py_Ref argv) {
    b2Rot _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2Rot)) return false;
        _0 = *(b2Rot*)py_touserdata(py_arg(0));
    } while(0);
    _Bool res = b2Rot_IsValid(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__b2AABB_IsValid(int argc, py_Ref argv) {
    b2AABB _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2AABB)) return false;
        _0 = *(b2AABB*)py_touserdata(py_arg(0));
    } while(0);
    _Bool res = b2AABB_IsValid(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__b2SetLengthUnitsPerMeter(int argc, py_Ref argv) {
    float _0;
    if(!py_castfloat32(py_arg(0), &_0)) return false;
    b2SetLengthUnitsPerMeter(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2GetLengthUnitsPerMeter(int argc, py_Ref argv) {
    float res = b2GetLengthUnitsPerMeter();
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2IsValidRay(int argc, py_Ref argv) {
    const b2RayCastInput* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2RayCastInput*)py_toint(py_arg(0));
    _Bool res = b2IsValidRay(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__b2MakePolygon(int argc, py_Ref argv) {
    const b2Hull* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2Hull*)py_toint(py_arg(0));
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2Polygon res = b2MakePolygon(_0, _1);
    do {
        b2Polygon* ud = py_newobject(py_retval(), tp_user_b2Polygon, 0, sizeof(b2Polygon));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2MakeOffsetPolygon(int argc, py_Ref argv) {
    const b2Hull* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2Hull*)py_toint(py_arg(0));
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2Transform _2;
    do {
        if(!py_checktype(py_arg(2), tp_user_b2Transform)) return false;
        _2 = *(b2Transform*)py_touserdata(py_arg(2));
    } while(0);
    b2Polygon res = b2MakeOffsetPolygon(_0, _1, _2);
    do {
        b2Polygon* ud = py_newobject(py_retval(), tp_user_b2Polygon, 0, sizeof(b2Polygon));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2MakeSquare(int argc, py_Ref argv) {
    float _0;
    if(!py_castfloat32(py_arg(0), &_0)) return false;
    b2Polygon res = b2MakeSquare(_0);
    do {
        b2Polygon* ud = py_newobject(py_retval(), tp_user_b2Polygon, 0, sizeof(b2Polygon));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2MakeBox(int argc, py_Ref argv) {
    float _0;
    if(!py_castfloat32(py_arg(0), &_0)) return false;
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2Polygon res = b2MakeBox(_0, _1);
    do {
        b2Polygon* ud = py_newobject(py_retval(), tp_user_b2Polygon, 0, sizeof(b2Polygon));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2MakeRoundedBox(int argc, py_Ref argv) {
    float _0;
    if(!py_castfloat32(py_arg(0), &_0)) return false;
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    b2Polygon res = b2MakeRoundedBox(_0, _1, _2);
    do {
        b2Polygon* ud = py_newobject(py_retval(), tp_user_b2Polygon, 0, sizeof(b2Polygon));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2MakeOffsetBox(int argc, py_Ref argv) {
    float _0;
    if(!py_castfloat32(py_arg(0), &_0)) return false;
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2Vec2 _2;
    do {
        if(!py_checktype(py_arg(2), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(2));
        _2 = *(b2Vec2*)(&tmp);
    } while(0);
    b2Rot _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_b2Rot)) return false;
        _3 = *(b2Rot*)py_touserdata(py_arg(3));
    } while(0);
    b2Polygon res = b2MakeOffsetBox(_0, _1, _2, _3);
    do {
        b2Polygon* ud = py_newobject(py_retval(), tp_user_b2Polygon, 0, sizeof(b2Polygon));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2TransformPolygon(int argc, py_Ref argv) {
    b2Transform _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2Transform)) return false;
        _0 = *(b2Transform*)py_touserdata(py_arg(0));
    } while(0);
    const b2Polygon* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const b2Polygon*)py_toint(py_arg(1));
    b2Polygon res = b2TransformPolygon(_0, _1);
    do {
        b2Polygon* ud = py_newobject(py_retval(), tp_user_b2Polygon, 0, sizeof(b2Polygon));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2ComputeCircleMass(int argc, py_Ref argv) {
    const b2Circle* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2Circle*)py_toint(py_arg(0));
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2MassData res = b2ComputeCircleMass(_0, _1);
    do {
        b2MassData* ud = py_newobject(py_retval(), tp_user_b2MassData, 0, sizeof(b2MassData));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2ComputeCapsuleMass(int argc, py_Ref argv) {
    const b2Capsule* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2Capsule*)py_toint(py_arg(0));
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2MassData res = b2ComputeCapsuleMass(_0, _1);
    do {
        b2MassData* ud = py_newobject(py_retval(), tp_user_b2MassData, 0, sizeof(b2MassData));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2ComputePolygonMass(int argc, py_Ref argv) {
    const b2Polygon* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2Polygon*)py_toint(py_arg(0));
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2MassData res = b2ComputePolygonMass(_0, _1);
    do {
        b2MassData* ud = py_newobject(py_retval(), tp_user_b2MassData, 0, sizeof(b2MassData));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2ComputeCircleAABB(int argc, py_Ref argv) {
    const b2Circle* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2Circle*)py_toint(py_arg(0));
    b2Transform _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_b2Transform)) return false;
        _1 = *(b2Transform*)py_touserdata(py_arg(1));
    } while(0);
    b2AABB res = b2ComputeCircleAABB(_0, _1);
    do {
        b2AABB* ud = py_newobject(py_retval(), tp_user_b2AABB, 0, sizeof(b2AABB));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2ComputeCapsuleAABB(int argc, py_Ref argv) {
    const b2Capsule* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2Capsule*)py_toint(py_arg(0));
    b2Transform _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_b2Transform)) return false;
        _1 = *(b2Transform*)py_touserdata(py_arg(1));
    } while(0);
    b2AABB res = b2ComputeCapsuleAABB(_0, _1);
    do {
        b2AABB* ud = py_newobject(py_retval(), tp_user_b2AABB, 0, sizeof(b2AABB));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2ComputePolygonAABB(int argc, py_Ref argv) {
    const b2Polygon* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2Polygon*)py_toint(py_arg(0));
    b2Transform _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_b2Transform)) return false;
        _1 = *(b2Transform*)py_touserdata(py_arg(1));
    } while(0);
    b2AABB res = b2ComputePolygonAABB(_0, _1);
    do {
        b2AABB* ud = py_newobject(py_retval(), tp_user_b2AABB, 0, sizeof(b2AABB));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2ComputeSegmentAABB(int argc, py_Ref argv) {
    const b2Segment* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2Segment*)py_toint(py_arg(0));
    b2Transform _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_b2Transform)) return false;
        _1 = *(b2Transform*)py_touserdata(py_arg(1));
    } while(0);
    b2AABB res = b2ComputeSegmentAABB(_0, _1);
    do {
        b2AABB* ud = py_newobject(py_retval(), tp_user_b2AABB, 0, sizeof(b2AABB));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2PointInCircle(int argc, py_Ref argv) {
    b2Vec2 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(0));
        _0 = *(b2Vec2*)(&tmp);
    } while(0);
    const b2Circle* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const b2Circle*)py_toint(py_arg(1));
    _Bool res = b2PointInCircle(_0, _1);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__b2PointInCapsule(int argc, py_Ref argv) {
    b2Vec2 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(0));
        _0 = *(b2Vec2*)(&tmp);
    } while(0);
    const b2Capsule* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const b2Capsule*)py_toint(py_arg(1));
    _Bool res = b2PointInCapsule(_0, _1);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__b2PointInPolygon(int argc, py_Ref argv) {
    b2Vec2 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(0));
        _0 = *(b2Vec2*)(&tmp);
    } while(0);
    const b2Polygon* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const b2Polygon*)py_toint(py_arg(1));
    _Bool res = b2PointInPolygon(_0, _1);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__b2RayCastCircle(int argc, py_Ref argv) {
    const b2RayCastInput* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2RayCastInput*)py_toint(py_arg(0));
    const b2Circle* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const b2Circle*)py_toint(py_arg(1));
    b2CastOutput res = b2RayCastCircle(_0, _1);
    do {
        b2CastOutput* ud = py_newobject(py_retval(), tp_user_b2CastOutput, 0, sizeof(b2CastOutput));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2RayCastCapsule(int argc, py_Ref argv) {
    const b2RayCastInput* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2RayCastInput*)py_toint(py_arg(0));
    const b2Capsule* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const b2Capsule*)py_toint(py_arg(1));
    b2CastOutput res = b2RayCastCapsule(_0, _1);
    do {
        b2CastOutput* ud = py_newobject(py_retval(), tp_user_b2CastOutput, 0, sizeof(b2CastOutput));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2RayCastSegment(int argc, py_Ref argv) {
    const b2RayCastInput* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2RayCastInput*)py_toint(py_arg(0));
    const b2Segment* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const b2Segment*)py_toint(py_arg(1));
    _Bool _2;
    if(!py_checkbool(py_arg(2))) return false;
    _2 = py_tobool(py_arg(2));
    b2CastOutput res = b2RayCastSegment(_0, _1, _2);
    do {
        b2CastOutput* ud = py_newobject(py_retval(), tp_user_b2CastOutput, 0, sizeof(b2CastOutput));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2RayCastPolygon(int argc, py_Ref argv) {
    const b2RayCastInput* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2RayCastInput*)py_toint(py_arg(0));
    const b2Polygon* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const b2Polygon*)py_toint(py_arg(1));
    b2CastOutput res = b2RayCastPolygon(_0, _1);
    do {
        b2CastOutput* ud = py_newobject(py_retval(), tp_user_b2CastOutput, 0, sizeof(b2CastOutput));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2ShapeCastCircle(int argc, py_Ref argv) {
    const b2ShapeCastInput* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2ShapeCastInput*)py_toint(py_arg(0));
    const b2Circle* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const b2Circle*)py_toint(py_arg(1));
    b2CastOutput res = b2ShapeCastCircle(_0, _1);
    do {
        b2CastOutput* ud = py_newobject(py_retval(), tp_user_b2CastOutput, 0, sizeof(b2CastOutput));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2ShapeCastCapsule(int argc, py_Ref argv) {
    const b2ShapeCastInput* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2ShapeCastInput*)py_toint(py_arg(0));
    const b2Capsule* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const b2Capsule*)py_toint(py_arg(1));
    b2CastOutput res = b2ShapeCastCapsule(_0, _1);
    do {
        b2CastOutput* ud = py_newobject(py_retval(), tp_user_b2CastOutput, 0, sizeof(b2CastOutput));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2ShapeCastSegment(int argc, py_Ref argv) {
    const b2ShapeCastInput* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2ShapeCastInput*)py_toint(py_arg(0));
    const b2Segment* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const b2Segment*)py_toint(py_arg(1));
    b2CastOutput res = b2ShapeCastSegment(_0, _1);
    do {
        b2CastOutput* ud = py_newobject(py_retval(), tp_user_b2CastOutput, 0, sizeof(b2CastOutput));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2ShapeCastPolygon(int argc, py_Ref argv) {
    const b2ShapeCastInput* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2ShapeCastInput*)py_toint(py_arg(0));
    const b2Polygon* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const b2Polygon*)py_toint(py_arg(1));
    b2CastOutput res = b2ShapeCastPolygon(_0, _1);
    do {
        b2CastOutput* ud = py_newobject(py_retval(), tp_user_b2CastOutput, 0, sizeof(b2CastOutput));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2ComputeHull(int argc, py_Ref argv) {
    const b2Vec2* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2Vec2*)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    b2Hull res = b2ComputeHull(_0, _1);
    do {
        b2Hull* ud = py_newobject(py_retval(), tp_user_b2Hull, 0, sizeof(b2Hull));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2ValidateHull(int argc, py_Ref argv) {
    const b2Hull* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2Hull*)py_toint(py_arg(0));
    _Bool res = b2ValidateHull(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__b2SegmentDistance(int argc, py_Ref argv) {
    b2Vec2 _0;
    do {
        if(!py_checktype(py_arg(0), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(0));
        _0 = *(b2Vec2*)(&tmp);
    } while(0);
    b2Vec2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(b2Vec2*)(&tmp);
    } while(0);
    b2Vec2 _2;
    do {
        if(!py_checktype(py_arg(2), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(2));
        _2 = *(b2Vec2*)(&tmp);
    } while(0);
    b2Vec2 _3;
    do {
        if(!py_checktype(py_arg(3), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(3));
        _3 = *(b2Vec2*)(&tmp);
    } while(0);
    b2SegmentDistanceResult res = b2SegmentDistance(_0, _1, _2, _3);
    do {
        b2SegmentDistanceResult* ud = py_newobject(py_retval(), tp_user_b2SegmentDistanceResult, 0, sizeof(b2SegmentDistanceResult));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2ShapeDistance(int argc, py_Ref argv) {
    b2DistanceCache* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (b2DistanceCache*)py_toint(py_arg(0));
    const b2DistanceInput* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const b2DistanceInput*)py_toint(py_arg(1));
    b2Simplex* _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = (b2Simplex*)py_toint(py_arg(2));
    int _3;
    if(!py_checkint(py_arg(3))) return false;
    _3 = py_toint(py_arg(3));
    b2DistanceOutput res = b2ShapeDistance(_0, _1, _2, _3);
    do {
        b2DistanceOutput* ud = py_newobject(py_retval(), tp_user_b2DistanceOutput, 0, sizeof(b2DistanceOutput));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2ShapeCast(int argc, py_Ref argv) {
    const b2ShapeCastPairInput* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2ShapeCastPairInput*)py_toint(py_arg(0));
    b2CastOutput res = b2ShapeCast(_0);
    do {
        b2CastOutput* ud = py_newobject(py_retval(), tp_user_b2CastOutput, 0, sizeof(b2CastOutput));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2MakeProxy(int argc, py_Ref argv) {
    const b2Vec2* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2Vec2*)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    b2DistanceProxy res = b2MakeProxy(_0, _1, _2);
    do {
        b2DistanceProxy* ud = py_newobject(py_retval(), tp_user_b2DistanceProxy, 0, sizeof(b2DistanceProxy));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2GetSweepTransform(int argc, py_Ref argv) {
    const b2Sweep* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2Sweep*)py_toint(py_arg(0));
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2Transform res = b2GetSweepTransform(_0, _1);
    do {
        b2Transform* ud = py_newobject(py_retval(), tp_user_b2Transform, 0, sizeof(b2Transform));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2TimeOfImpact(int argc, py_Ref argv) {
    const b2TOIInput* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2TOIInput*)py_toint(py_arg(0));
    b2TOIOutput res = b2TimeOfImpact(_0);
    do {
        b2TOIOutput* ud = py_newobject(py_retval(), tp_user_b2TOIOutput, 0, sizeof(b2TOIOutput));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2CollideCircles(int argc, py_Ref argv) {
    const b2Circle* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2Circle*)py_toint(py_arg(0));
    b2Transform _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_b2Transform)) return false;
        _1 = *(b2Transform*)py_touserdata(py_arg(1));
    } while(0);
    const b2Circle* _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = (const b2Circle*)py_toint(py_arg(2));
    b2Transform _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_b2Transform)) return false;
        _3 = *(b2Transform*)py_touserdata(py_arg(3));
    } while(0);
    b2Manifold res = b2CollideCircles(_0, _1, _2, _3);
    do {
        b2Manifold* ud = py_newobject(py_retval(), tp_user_b2Manifold, 0, sizeof(b2Manifold));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2CollideCapsuleAndCircle(int argc, py_Ref argv) {
    const b2Capsule* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2Capsule*)py_toint(py_arg(0));
    b2Transform _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_b2Transform)) return false;
        _1 = *(b2Transform*)py_touserdata(py_arg(1));
    } while(0);
    const b2Circle* _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = (const b2Circle*)py_toint(py_arg(2));
    b2Transform _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_b2Transform)) return false;
        _3 = *(b2Transform*)py_touserdata(py_arg(3));
    } while(0);
    b2Manifold res = b2CollideCapsuleAndCircle(_0, _1, _2, _3);
    do {
        b2Manifold* ud = py_newobject(py_retval(), tp_user_b2Manifold, 0, sizeof(b2Manifold));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2CollideSegmentAndCircle(int argc, py_Ref argv) {
    const b2Segment* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2Segment*)py_toint(py_arg(0));
    b2Transform _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_b2Transform)) return false;
        _1 = *(b2Transform*)py_touserdata(py_arg(1));
    } while(0);
    const b2Circle* _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = (const b2Circle*)py_toint(py_arg(2));
    b2Transform _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_b2Transform)) return false;
        _3 = *(b2Transform*)py_touserdata(py_arg(3));
    } while(0);
    b2Manifold res = b2CollideSegmentAndCircle(_0, _1, _2, _3);
    do {
        b2Manifold* ud = py_newobject(py_retval(), tp_user_b2Manifold, 0, sizeof(b2Manifold));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2CollidePolygonAndCircle(int argc, py_Ref argv) {
    const b2Polygon* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2Polygon*)py_toint(py_arg(0));
    b2Transform _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_b2Transform)) return false;
        _1 = *(b2Transform*)py_touserdata(py_arg(1));
    } while(0);
    const b2Circle* _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = (const b2Circle*)py_toint(py_arg(2));
    b2Transform _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_b2Transform)) return false;
        _3 = *(b2Transform*)py_touserdata(py_arg(3));
    } while(0);
    b2Manifold res = b2CollidePolygonAndCircle(_0, _1, _2, _3);
    do {
        b2Manifold* ud = py_newobject(py_retval(), tp_user_b2Manifold, 0, sizeof(b2Manifold));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2CollideCapsules(int argc, py_Ref argv) {
    const b2Capsule* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2Capsule*)py_toint(py_arg(0));
    b2Transform _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_b2Transform)) return false;
        _1 = *(b2Transform*)py_touserdata(py_arg(1));
    } while(0);
    const b2Capsule* _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = (const b2Capsule*)py_toint(py_arg(2));
    b2Transform _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_b2Transform)) return false;
        _3 = *(b2Transform*)py_touserdata(py_arg(3));
    } while(0);
    b2Manifold res = b2CollideCapsules(_0, _1, _2, _3);
    do {
        b2Manifold* ud = py_newobject(py_retval(), tp_user_b2Manifold, 0, sizeof(b2Manifold));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2CollideSegmentAndCapsule(int argc, py_Ref argv) {
    const b2Segment* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2Segment*)py_toint(py_arg(0));
    b2Transform _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_b2Transform)) return false;
        _1 = *(b2Transform*)py_touserdata(py_arg(1));
    } while(0);
    const b2Capsule* _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = (const b2Capsule*)py_toint(py_arg(2));
    b2Transform _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_b2Transform)) return false;
        _3 = *(b2Transform*)py_touserdata(py_arg(3));
    } while(0);
    b2Manifold res = b2CollideSegmentAndCapsule(_0, _1, _2, _3);
    do {
        b2Manifold* ud = py_newobject(py_retval(), tp_user_b2Manifold, 0, sizeof(b2Manifold));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2CollidePolygonAndCapsule(int argc, py_Ref argv) {
    const b2Polygon* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2Polygon*)py_toint(py_arg(0));
    b2Transform _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_b2Transform)) return false;
        _1 = *(b2Transform*)py_touserdata(py_arg(1));
    } while(0);
    const b2Capsule* _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = (const b2Capsule*)py_toint(py_arg(2));
    b2Transform _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_b2Transform)) return false;
        _3 = *(b2Transform*)py_touserdata(py_arg(3));
    } while(0);
    b2Manifold res = b2CollidePolygonAndCapsule(_0, _1, _2, _3);
    do {
        b2Manifold* ud = py_newobject(py_retval(), tp_user_b2Manifold, 0, sizeof(b2Manifold));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2CollidePolygons(int argc, py_Ref argv) {
    const b2Polygon* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2Polygon*)py_toint(py_arg(0));
    b2Transform _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_b2Transform)) return false;
        _1 = *(b2Transform*)py_touserdata(py_arg(1));
    } while(0);
    const b2Polygon* _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = (const b2Polygon*)py_toint(py_arg(2));
    b2Transform _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_b2Transform)) return false;
        _3 = *(b2Transform*)py_touserdata(py_arg(3));
    } while(0);
    b2Manifold res = b2CollidePolygons(_0, _1, _2, _3);
    do {
        b2Manifold* ud = py_newobject(py_retval(), tp_user_b2Manifold, 0, sizeof(b2Manifold));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2CollideSegmentAndPolygon(int argc, py_Ref argv) {
    const b2Segment* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2Segment*)py_toint(py_arg(0));
    b2Transform _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_b2Transform)) return false;
        _1 = *(b2Transform*)py_touserdata(py_arg(1));
    } while(0);
    const b2Polygon* _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = (const b2Polygon*)py_toint(py_arg(2));
    b2Transform _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_b2Transform)) return false;
        _3 = *(b2Transform*)py_touserdata(py_arg(3));
    } while(0);
    b2Manifold res = b2CollideSegmentAndPolygon(_0, _1, _2, _3);
    do {
        b2Manifold* ud = py_newobject(py_retval(), tp_user_b2Manifold, 0, sizeof(b2Manifold));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2CollideSmoothSegmentAndCircle(int argc, py_Ref argv) {
    const b2SmoothSegment* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2SmoothSegment*)py_toint(py_arg(0));
    b2Transform _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_b2Transform)) return false;
        _1 = *(b2Transform*)py_touserdata(py_arg(1));
    } while(0);
    const b2Circle* _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = (const b2Circle*)py_toint(py_arg(2));
    b2Transform _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_b2Transform)) return false;
        _3 = *(b2Transform*)py_touserdata(py_arg(3));
    } while(0);
    b2Manifold res = b2CollideSmoothSegmentAndCircle(_0, _1, _2, _3);
    do {
        b2Manifold* ud = py_newobject(py_retval(), tp_user_b2Manifold, 0, sizeof(b2Manifold));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2CollideSmoothSegmentAndCapsule(int argc, py_Ref argv) {
    const b2SmoothSegment* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2SmoothSegment*)py_toint(py_arg(0));
    b2Transform _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_b2Transform)) return false;
        _1 = *(b2Transform*)py_touserdata(py_arg(1));
    } while(0);
    const b2Capsule* _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = (const b2Capsule*)py_toint(py_arg(2));
    b2Transform _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_b2Transform)) return false;
        _3 = *(b2Transform*)py_touserdata(py_arg(3));
    } while(0);
    b2DistanceCache* _4;
    if(!py_checkint(py_arg(4))) return false;
    _4 = (b2DistanceCache*)py_toint(py_arg(4));
    b2Manifold res = b2CollideSmoothSegmentAndCapsule(_0, _1, _2, _3, _4);
    do {
        b2Manifold* ud = py_newobject(py_retval(), tp_user_b2Manifold, 0, sizeof(b2Manifold));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2CollideSmoothSegmentAndPolygon(int argc, py_Ref argv) {
    const b2SmoothSegment* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2SmoothSegment*)py_toint(py_arg(0));
    b2Transform _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_b2Transform)) return false;
        _1 = *(b2Transform*)py_touserdata(py_arg(1));
    } while(0);
    const b2Polygon* _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = (const b2Polygon*)py_toint(py_arg(2));
    b2Transform _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_b2Transform)) return false;
        _3 = *(b2Transform*)py_touserdata(py_arg(3));
    } while(0);
    b2DistanceCache* _4;
    if(!py_checkint(py_arg(4))) return false;
    _4 = (b2DistanceCache*)py_toint(py_arg(4));
    b2Manifold res = b2CollideSmoothSegmentAndPolygon(_0, _1, _2, _3, _4);
    do {
        b2Manifold* ud = py_newobject(py_retval(), tp_user_b2Manifold, 0, sizeof(b2Manifold));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2DynamicTree_Create(int argc, py_Ref argv) {
    b2DynamicTree res = b2DynamicTree_Create();
    do {
        b2DynamicTree* ud = py_newobject(py_retval(), tp_user_b2DynamicTree, 0, sizeof(b2DynamicTree));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2DynamicTree_Destroy(int argc, py_Ref argv) {
    b2DynamicTree* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (b2DynamicTree*)py_toint(py_arg(0));
    b2DynamicTree_Destroy(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2DynamicTree_CreateProxy(int argc, py_Ref argv) {
    b2DynamicTree* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (b2DynamicTree*)py_toint(py_arg(0));
    b2AABB _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_b2AABB)) return false;
        _1 = *(b2AABB*)py_touserdata(py_arg(1));
    } while(0);
    unsigned _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    int _3;
    if(!py_checkint(py_arg(3))) return false;
    _3 = py_toint(py_arg(3));
    int res = b2DynamicTree_CreateProxy(_0, _1, _2, _3);
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__b2DynamicTree_DestroyProxy(int argc, py_Ref argv) {
    b2DynamicTree* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (b2DynamicTree*)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    b2DynamicTree_DestroyProxy(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2DynamicTree_MoveProxy(int argc, py_Ref argv) {
    b2DynamicTree* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (b2DynamicTree*)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    b2AABB _2;
    do {
        if(!py_checktype(py_arg(2), tp_user_b2AABB)) return false;
        _2 = *(b2AABB*)py_touserdata(py_arg(2));
    } while(0);
    b2DynamicTree_MoveProxy(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2DynamicTree_EnlargeProxy(int argc, py_Ref argv) {
    b2DynamicTree* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (b2DynamicTree*)py_toint(py_arg(0));
    int _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = py_toint(py_arg(1));
    b2AABB _2;
    do {
        if(!py_checktype(py_arg(2), tp_user_b2AABB)) return false;
        _2 = *(b2AABB*)py_touserdata(py_arg(2));
    } while(0);
    b2DynamicTree_EnlargeProxy(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2DynamicTree_Query(int argc, py_Ref argv) {
    const b2DynamicTree* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2DynamicTree*)py_toint(py_arg(0));
    b2AABB _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_b2AABB)) return false;
        _1 = *(b2AABB*)py_touserdata(py_arg(1));
    } while(0);
    unsigned _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    b2TreeQueryCallbackFcn* _3;
    if(!py_checkint(py_arg(3))) return false;
    _3 = (b2TreeQueryCallbackFcn*)py_toint(py_arg(3));
    void* _4;
    if(!py_checkint(py_arg(4))) return false;
    _4 = (void*)py_toint(py_arg(4));
    b2DynamicTree_Query(_0, _1, _2, _3, _4);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2DynamicTree_RayCast(int argc, py_Ref argv) {
    const b2DynamicTree* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2DynamicTree*)py_toint(py_arg(0));
    const b2RayCastInput* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const b2RayCastInput*)py_toint(py_arg(1));
    unsigned _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    b2TreeRayCastCallbackFcn* _3;
    if(!py_checkint(py_arg(3))) return false;
    _3 = (b2TreeRayCastCallbackFcn*)py_toint(py_arg(3));
    void* _4;
    if(!py_checkint(py_arg(4))) return false;
    _4 = (void*)py_toint(py_arg(4));
    b2DynamicTree_RayCast(_0, _1, _2, _3, _4);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2DynamicTree_ShapeCast(int argc, py_Ref argv) {
    const b2DynamicTree* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2DynamicTree*)py_toint(py_arg(0));
    const b2ShapeCastInput* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const b2ShapeCastInput*)py_toint(py_arg(1));
    unsigned _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    b2TreeShapeCastCallbackFcn* _3;
    if(!py_checkint(py_arg(3))) return false;
    _3 = (b2TreeShapeCastCallbackFcn*)py_toint(py_arg(3));
    void* _4;
    if(!py_checkint(py_arg(4))) return false;
    _4 = (void*)py_toint(py_arg(4));
    b2DynamicTree_ShapeCast(_0, _1, _2, _3, _4);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2DynamicTree_Validate(int argc, py_Ref argv) {
    const b2DynamicTree* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2DynamicTree*)py_toint(py_arg(0));
    b2DynamicTree_Validate(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2DynamicTree_GetHeight(int argc, py_Ref argv) {
    const b2DynamicTree* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2DynamicTree*)py_toint(py_arg(0));
    int res = b2DynamicTree_GetHeight(_0);
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__b2DynamicTree_GetMaxBalance(int argc, py_Ref argv) {
    const b2DynamicTree* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2DynamicTree*)py_toint(py_arg(0));
    int res = b2DynamicTree_GetMaxBalance(_0);
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__b2DynamicTree_GetAreaRatio(int argc, py_Ref argv) {
    const b2DynamicTree* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2DynamicTree*)py_toint(py_arg(0));
    float res = b2DynamicTree_GetAreaRatio(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2DynamicTree_RebuildBottomUp(int argc, py_Ref argv) {
    b2DynamicTree* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (b2DynamicTree*)py_toint(py_arg(0));
    b2DynamicTree_RebuildBottomUp(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2DynamicTree_GetProxyCount(int argc, py_Ref argv) {
    const b2DynamicTree* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2DynamicTree*)py_toint(py_arg(0));
    int res = b2DynamicTree_GetProxyCount(_0);
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__b2DynamicTree_Rebuild(int argc, py_Ref argv) {
    b2DynamicTree* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (b2DynamicTree*)py_toint(py_arg(0));
    _Bool _1;
    if(!py_checkbool(py_arg(1))) return false;
    _1 = py_tobool(py_arg(1));
    int res = b2DynamicTree_Rebuild(_0, _1);
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__b2DynamicTree_ShiftOrigin(int argc, py_Ref argv) {
    b2DynamicTree* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (b2DynamicTree*)py_toint(py_arg(0));
    b2Vec2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(b2Vec2*)(&tmp);
    } while(0);
    b2DynamicTree_ShiftOrigin(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2DynamicTree_GetByteCount(int argc, py_Ref argv) {
    const b2DynamicTree* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2DynamicTree*)py_toint(py_arg(0));
    int res = b2DynamicTree_GetByteCount(_0);
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__b2DefaultWorldDef(int argc, py_Ref argv) {
    b2WorldDef res = b2DefaultWorldDef();
    do {
        b2WorldDef* ud = py_newobject(py_retval(), tp_user_b2WorldDef, 0, sizeof(b2WorldDef));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2DefaultBodyDef(int argc, py_Ref argv) {
    b2BodyDef res = b2DefaultBodyDef();
    do {
        b2BodyDef* ud = py_newobject(py_retval(), tp_user_b2BodyDef, 0, sizeof(b2BodyDef));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2DefaultFilter(int argc, py_Ref argv) {
    b2Filter res = b2DefaultFilter();
    do {
        b2Filter* ud = py_newobject(py_retval(), tp_user_b2Filter, 0, sizeof(b2Filter));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2DefaultQueryFilter(int argc, py_Ref argv) {
    b2QueryFilter res = b2DefaultQueryFilter();
    do {
        b2QueryFilter* ud = py_newobject(py_retval(), tp_user_b2QueryFilter, 0, sizeof(b2QueryFilter));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2DefaultShapeDef(int argc, py_Ref argv) {
    b2ShapeDef res = b2DefaultShapeDef();
    do {
        b2ShapeDef* ud = py_newobject(py_retval(), tp_user_b2ShapeDef, 0, sizeof(b2ShapeDef));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2DefaultChainDef(int argc, py_Ref argv) {
    b2ChainDef res = b2DefaultChainDef();
    do {
        b2ChainDef* ud = py_newobject(py_retval(), tp_user_b2ChainDef, 0, sizeof(b2ChainDef));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2DefaultDistanceJointDef(int argc, py_Ref argv) {
    b2DistanceJointDef res = b2DefaultDistanceJointDef();
    do {
        b2DistanceJointDef* ud = py_newobject(py_retval(), tp_user_b2DistanceJointDef, 0, sizeof(b2DistanceJointDef));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2DefaultMotorJointDef(int argc, py_Ref argv) {
    b2MotorJointDef res = b2DefaultMotorJointDef();
    do {
        b2MotorJointDef* ud = py_newobject(py_retval(), tp_user_b2MotorJointDef, 0, sizeof(b2MotorJointDef));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2DefaultMouseJointDef(int argc, py_Ref argv) {
    b2MouseJointDef res = b2DefaultMouseJointDef();
    do {
        b2MouseJointDef* ud = py_newobject(py_retval(), tp_user_b2MouseJointDef, 0, sizeof(b2MouseJointDef));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2DefaultPrismaticJointDef(int argc, py_Ref argv) {
    b2PrismaticJointDef res = b2DefaultPrismaticJointDef();
    do {
        b2PrismaticJointDef* ud = py_newobject(py_retval(), tp_user_b2PrismaticJointDef, 0, sizeof(b2PrismaticJointDef));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2DefaultRevoluteJointDef(int argc, py_Ref argv) {
    b2RevoluteJointDef res = b2DefaultRevoluteJointDef();
    do {
        b2RevoluteJointDef* ud = py_newobject(py_retval(), tp_user_b2RevoluteJointDef, 0, sizeof(b2RevoluteJointDef));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2DefaultWeldJointDef(int argc, py_Ref argv) {
    b2WeldJointDef res = b2DefaultWeldJointDef();
    do {
        b2WeldJointDef* ud = py_newobject(py_retval(), tp_user_b2WeldJointDef, 0, sizeof(b2WeldJointDef));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2DefaultWheelJointDef(int argc, py_Ref argv) {
    b2WheelJointDef res = b2DefaultWheelJointDef();
    do {
        b2WheelJointDef* ud = py_newobject(py_retval(), tp_user_b2WheelJointDef, 0, sizeof(b2WheelJointDef));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2CreateWorld(int argc, py_Ref argv) {
    const b2WorldDef* _0;
    if(!py_checkint(py_arg(0))) return false;
    _0 = (const b2WorldDef*)py_toint(py_arg(0));
    b2WorldId res = b2CreateWorld(_0);
    do {
        b2WorldId* ud = py_newobject(py_retval(), tp_user_b2WorldId, 0, sizeof(b2WorldId));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2DestroyWorld(int argc, py_Ref argv) {
    b2WorldId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2WorldId)) return false;
        _0 = *(b2WorldId*)py_touserdata(py_arg(0));
    } while(0);
    b2DestroyWorld(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2World_IsValid(int argc, py_Ref argv) {
    b2WorldId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2WorldId)) return false;
        _0 = *(b2WorldId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool res = b2World_IsValid(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__b2World_Step(int argc, py_Ref argv) {
    b2WorldId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2WorldId)) return false;
        _0 = *(b2WorldId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    b2World_Step(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2World_Draw(int argc, py_Ref argv) {
    b2WorldId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2WorldId)) return false;
        _0 = *(b2WorldId*)py_touserdata(py_arg(0));
    } while(0);
    b2DebugDraw* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (b2DebugDraw*)py_toint(py_arg(1));
    b2World_Draw(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2World_GetBodyEvents(int argc, py_Ref argv) {
    b2WorldId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2WorldId)) return false;
        _0 = *(b2WorldId*)py_touserdata(py_arg(0));
    } while(0);
    b2BodyEvents res = b2World_GetBodyEvents(_0);
    do {
        b2BodyEvents* ud = py_newobject(py_retval(), tp_user_b2BodyEvents, 0, sizeof(b2BodyEvents));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2World_GetSensorEvents(int argc, py_Ref argv) {
    b2WorldId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2WorldId)) return false;
        _0 = *(b2WorldId*)py_touserdata(py_arg(0));
    } while(0);
    b2SensorEvents res = b2World_GetSensorEvents(_0);
    do {
        b2SensorEvents* ud = py_newobject(py_retval(), tp_user_b2SensorEvents, 0, sizeof(b2SensorEvents));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2World_GetContactEvents(int argc, py_Ref argv) {
    b2WorldId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2WorldId)) return false;
        _0 = *(b2WorldId*)py_touserdata(py_arg(0));
    } while(0);
    b2ContactEvents res = b2World_GetContactEvents(_0);
    do {
        b2ContactEvents* ud = py_newobject(py_retval(), tp_user_b2ContactEvents, 0, sizeof(b2ContactEvents));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2World_OverlapAABB(int argc, py_Ref argv) {
    b2WorldId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2WorldId)) return false;
        _0 = *(b2WorldId*)py_touserdata(py_arg(0));
    } while(0);
    b2AABB _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_b2AABB)) return false;
        _1 = *(b2AABB*)py_touserdata(py_arg(1));
    } while(0);
    b2QueryFilter _2;
    do {
        if(!py_checktype(py_arg(2), tp_user_b2QueryFilter)) return false;
        _2 = *(b2QueryFilter*)py_touserdata(py_arg(2));
    } while(0);
    b2OverlapResultFcn* _3;
    if(!py_checkint(py_arg(3))) return false;
    _3 = (b2OverlapResultFcn*)py_toint(py_arg(3));
    void* _4;
    if(!py_checkint(py_arg(4))) return false;
    _4 = (void*)py_toint(py_arg(4));
    b2World_OverlapAABB(_0, _1, _2, _3, _4);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2World_OverlapCircle(int argc, py_Ref argv) {
    b2WorldId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2WorldId)) return false;
        _0 = *(b2WorldId*)py_touserdata(py_arg(0));
    } while(0);
    const b2Circle* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const b2Circle*)py_toint(py_arg(1));
    b2Transform _2;
    do {
        if(!py_checktype(py_arg(2), tp_user_b2Transform)) return false;
        _2 = *(b2Transform*)py_touserdata(py_arg(2));
    } while(0);
    b2QueryFilter _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_b2QueryFilter)) return false;
        _3 = *(b2QueryFilter*)py_touserdata(py_arg(3));
    } while(0);
    b2OverlapResultFcn* _4;
    if(!py_checkint(py_arg(4))) return false;
    _4 = (b2OverlapResultFcn*)py_toint(py_arg(4));
    void* _5;
    if(!py_checkint(py_arg(5))) return false;
    _5 = (void*)py_toint(py_arg(5));
    b2World_OverlapCircle(_0, _1, _2, _3, _4, _5);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2World_OverlapCapsule(int argc, py_Ref argv) {
    b2WorldId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2WorldId)) return false;
        _0 = *(b2WorldId*)py_touserdata(py_arg(0));
    } while(0);
    const b2Capsule* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const b2Capsule*)py_toint(py_arg(1));
    b2Transform _2;
    do {
        if(!py_checktype(py_arg(2), tp_user_b2Transform)) return false;
        _2 = *(b2Transform*)py_touserdata(py_arg(2));
    } while(0);
    b2QueryFilter _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_b2QueryFilter)) return false;
        _3 = *(b2QueryFilter*)py_touserdata(py_arg(3));
    } while(0);
    b2OverlapResultFcn* _4;
    if(!py_checkint(py_arg(4))) return false;
    _4 = (b2OverlapResultFcn*)py_toint(py_arg(4));
    void* _5;
    if(!py_checkint(py_arg(5))) return false;
    _5 = (void*)py_toint(py_arg(5));
    b2World_OverlapCapsule(_0, _1, _2, _3, _4, _5);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2World_OverlapPolygon(int argc, py_Ref argv) {
    b2WorldId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2WorldId)) return false;
        _0 = *(b2WorldId*)py_touserdata(py_arg(0));
    } while(0);
    const b2Polygon* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const b2Polygon*)py_toint(py_arg(1));
    b2Transform _2;
    do {
        if(!py_checktype(py_arg(2), tp_user_b2Transform)) return false;
        _2 = *(b2Transform*)py_touserdata(py_arg(2));
    } while(0);
    b2QueryFilter _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_b2QueryFilter)) return false;
        _3 = *(b2QueryFilter*)py_touserdata(py_arg(3));
    } while(0);
    b2OverlapResultFcn* _4;
    if(!py_checkint(py_arg(4))) return false;
    _4 = (b2OverlapResultFcn*)py_toint(py_arg(4));
    void* _5;
    if(!py_checkint(py_arg(5))) return false;
    _5 = (void*)py_toint(py_arg(5));
    b2World_OverlapPolygon(_0, _1, _2, _3, _4, _5);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2World_CastRay(int argc, py_Ref argv) {
    b2WorldId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2WorldId)) return false;
        _0 = *(b2WorldId*)py_touserdata(py_arg(0));
    } while(0);
    b2Vec2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(b2Vec2*)(&tmp);
    } while(0);
    b2Vec2 _2;
    do {
        if(!py_checktype(py_arg(2), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(2));
        _2 = *(b2Vec2*)(&tmp);
    } while(0);
    b2QueryFilter _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_b2QueryFilter)) return false;
        _3 = *(b2QueryFilter*)py_touserdata(py_arg(3));
    } while(0);
    b2CastResultFcn* _4;
    if(!py_checkint(py_arg(4))) return false;
    _4 = (b2CastResultFcn*)py_toint(py_arg(4));
    void* _5;
    if(!py_checkint(py_arg(5))) return false;
    _5 = (void*)py_toint(py_arg(5));
    b2World_CastRay(_0, _1, _2, _3, _4, _5);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2World_CastRayClosest(int argc, py_Ref argv) {
    b2WorldId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2WorldId)) return false;
        _0 = *(b2WorldId*)py_touserdata(py_arg(0));
    } while(0);
    b2Vec2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(b2Vec2*)(&tmp);
    } while(0);
    b2Vec2 _2;
    do {
        if(!py_checktype(py_arg(2), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(2));
        _2 = *(b2Vec2*)(&tmp);
    } while(0);
    b2QueryFilter _3;
    do {
        if(!py_checktype(py_arg(3), tp_user_b2QueryFilter)) return false;
        _3 = *(b2QueryFilter*)py_touserdata(py_arg(3));
    } while(0);
    b2RayResult res = b2World_CastRayClosest(_0, _1, _2, _3);
    do {
        b2RayResult* ud = py_newobject(py_retval(), tp_user_b2RayResult, 0, sizeof(b2RayResult));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2World_CastCircle(int argc, py_Ref argv) {
    b2WorldId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2WorldId)) return false;
        _0 = *(b2WorldId*)py_touserdata(py_arg(0));
    } while(0);
    const b2Circle* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const b2Circle*)py_toint(py_arg(1));
    b2Transform _2;
    do {
        if(!py_checktype(py_arg(2), tp_user_b2Transform)) return false;
        _2 = *(b2Transform*)py_touserdata(py_arg(2));
    } while(0);
    b2Vec2 _3;
    do {
        if(!py_checktype(py_arg(3), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(3));
        _3 = *(b2Vec2*)(&tmp);
    } while(0);
    b2QueryFilter _4;
    do {
        if(!py_checktype(py_arg(4), tp_user_b2QueryFilter)) return false;
        _4 = *(b2QueryFilter*)py_touserdata(py_arg(4));
    } while(0);
    b2CastResultFcn* _5;
    if(!py_checkint(py_arg(5))) return false;
    _5 = (b2CastResultFcn*)py_toint(py_arg(5));
    void* _6;
    if(!py_checkint(py_arg(6))) return false;
    _6 = (void*)py_toint(py_arg(6));
    b2World_CastCircle(_0, _1, _2, _3, _4, _5, _6);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2World_CastCapsule(int argc, py_Ref argv) {
    b2WorldId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2WorldId)) return false;
        _0 = *(b2WorldId*)py_touserdata(py_arg(0));
    } while(0);
    const b2Capsule* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const b2Capsule*)py_toint(py_arg(1));
    b2Transform _2;
    do {
        if(!py_checktype(py_arg(2), tp_user_b2Transform)) return false;
        _2 = *(b2Transform*)py_touserdata(py_arg(2));
    } while(0);
    b2Vec2 _3;
    do {
        if(!py_checktype(py_arg(3), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(3));
        _3 = *(b2Vec2*)(&tmp);
    } while(0);
    b2QueryFilter _4;
    do {
        if(!py_checktype(py_arg(4), tp_user_b2QueryFilter)) return false;
        _4 = *(b2QueryFilter*)py_touserdata(py_arg(4));
    } while(0);
    b2CastResultFcn* _5;
    if(!py_checkint(py_arg(5))) return false;
    _5 = (b2CastResultFcn*)py_toint(py_arg(5));
    void* _6;
    if(!py_checkint(py_arg(6))) return false;
    _6 = (void*)py_toint(py_arg(6));
    b2World_CastCapsule(_0, _1, _2, _3, _4, _5, _6);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2World_CastPolygon(int argc, py_Ref argv) {
    b2WorldId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2WorldId)) return false;
        _0 = *(b2WorldId*)py_touserdata(py_arg(0));
    } while(0);
    const b2Polygon* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const b2Polygon*)py_toint(py_arg(1));
    b2Transform _2;
    do {
        if(!py_checktype(py_arg(2), tp_user_b2Transform)) return false;
        _2 = *(b2Transform*)py_touserdata(py_arg(2));
    } while(0);
    b2Vec2 _3;
    do {
        if(!py_checktype(py_arg(3), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(3));
        _3 = *(b2Vec2*)(&tmp);
    } while(0);
    b2QueryFilter _4;
    do {
        if(!py_checktype(py_arg(4), tp_user_b2QueryFilter)) return false;
        _4 = *(b2QueryFilter*)py_touserdata(py_arg(4));
    } while(0);
    b2CastResultFcn* _5;
    if(!py_checkint(py_arg(5))) return false;
    _5 = (b2CastResultFcn*)py_toint(py_arg(5));
    void* _6;
    if(!py_checkint(py_arg(6))) return false;
    _6 = (void*)py_toint(py_arg(6));
    b2World_CastPolygon(_0, _1, _2, _3, _4, _5, _6);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2World_EnableSleeping(int argc, py_Ref argv) {
    b2WorldId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2WorldId)) return false;
        _0 = *(b2WorldId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool _1;
    if(!py_checkbool(py_arg(1))) return false;
    _1 = py_tobool(py_arg(1));
    b2World_EnableSleeping(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2World_EnableContinuous(int argc, py_Ref argv) {
    b2WorldId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2WorldId)) return false;
        _0 = *(b2WorldId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool _1;
    if(!py_checkbool(py_arg(1))) return false;
    _1 = py_tobool(py_arg(1));
    b2World_EnableContinuous(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2World_SetRestitutionThreshold(int argc, py_Ref argv) {
    b2WorldId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2WorldId)) return false;
        _0 = *(b2WorldId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2World_SetRestitutionThreshold(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2World_SetHitEventThreshold(int argc, py_Ref argv) {
    b2WorldId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2WorldId)) return false;
        _0 = *(b2WorldId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2World_SetHitEventThreshold(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2World_SetCustomFilterCallback(int argc, py_Ref argv) {
    b2WorldId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2WorldId)) return false;
        _0 = *(b2WorldId*)py_touserdata(py_arg(0));
    } while(0);
    b2CustomFilterFcn* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (b2CustomFilterFcn*)py_toint(py_arg(1));
    void* _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = (void*)py_toint(py_arg(2));
    b2World_SetCustomFilterCallback(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2World_SetPreSolveCallback(int argc, py_Ref argv) {
    b2WorldId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2WorldId)) return false;
        _0 = *(b2WorldId*)py_touserdata(py_arg(0));
    } while(0);
    b2PreSolveFcn* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (b2PreSolveFcn*)py_toint(py_arg(1));
    void* _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = (void*)py_toint(py_arg(2));
    b2World_SetPreSolveCallback(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2World_SetGravity(int argc, py_Ref argv) {
    b2WorldId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2WorldId)) return false;
        _0 = *(b2WorldId*)py_touserdata(py_arg(0));
    } while(0);
    b2Vec2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(b2Vec2*)(&tmp);
    } while(0);
    b2World_SetGravity(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2World_GetGravity(int argc, py_Ref argv) {
    b2WorldId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2WorldId)) return false;
        _0 = *(b2WorldId*)py_touserdata(py_arg(0));
    } while(0);
    b2Vec2 res = b2World_GetGravity(_0);
    py_newvec2(py_retval(), *(c11_vec2*)(&res));
    return true;
}
static bool cfunc__b2World_Explode(int argc, py_Ref argv) {
    b2WorldId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2WorldId)) return false;
        _0 = *(b2WorldId*)py_touserdata(py_arg(0));
    } while(0);
    b2Vec2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(b2Vec2*)(&tmp);
    } while(0);
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    float _3;
    if(!py_castfloat32(py_arg(3), &_3)) return false;
    b2World_Explode(_0, _1, _2, _3);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2World_SetContactTuning(int argc, py_Ref argv) {
    b2WorldId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2WorldId)) return false;
        _0 = *(b2WorldId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    float _3;
    if(!py_castfloat32(py_arg(3), &_3)) return false;
    b2World_SetContactTuning(_0, _1, _2, _3);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2World_EnableWarmStarting(int argc, py_Ref argv) {
    b2WorldId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2WorldId)) return false;
        _0 = *(b2WorldId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool _1;
    if(!py_checkbool(py_arg(1))) return false;
    _1 = py_tobool(py_arg(1));
    b2World_EnableWarmStarting(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2World_GetProfile(int argc, py_Ref argv) {
    b2WorldId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2WorldId)) return false;
        _0 = *(b2WorldId*)py_touserdata(py_arg(0));
    } while(0);
    b2Profile res = b2World_GetProfile(_0);
    do {
        b2Profile* ud = py_newobject(py_retval(), tp_user_b2Profile, 0, sizeof(b2Profile));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2World_GetCounters(int argc, py_Ref argv) {
    b2WorldId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2WorldId)) return false;
        _0 = *(b2WorldId*)py_touserdata(py_arg(0));
    } while(0);
    b2Counters res = b2World_GetCounters(_0);
    do {
        b2Counters* ud = py_newobject(py_retval(), tp_user_b2Counters, 0, sizeof(b2Counters));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2World_DumpMemoryStats(int argc, py_Ref argv) {
    b2WorldId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2WorldId)) return false;
        _0 = *(b2WorldId*)py_touserdata(py_arg(0));
    } while(0);
    b2World_DumpMemoryStats(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2CreateBody(int argc, py_Ref argv) {
    b2WorldId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2WorldId)) return false;
        _0 = *(b2WorldId*)py_touserdata(py_arg(0));
    } while(0);
    const b2BodyDef* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const b2BodyDef*)py_toint(py_arg(1));
    b2BodyId res = b2CreateBody(_0, _1);
    do {
        b2BodyId* ud = py_newobject(py_retval(), tp_user_b2BodyId, 0, sizeof(b2BodyId));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2DestroyBody(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    b2DestroyBody(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Body_IsValid(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool res = b2Body_IsValid(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__b2Body_GetType(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    b2BodyType res = b2Body_GetType(_0);
    py_newint(py_retval(), (py_i64)res);
    return true;
}
static bool cfunc__b2Body_SetType(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    b2BodyType _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (b2BodyType)py_toint(py_arg(1));
    b2Body_SetType(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Body_SetUserData(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    void* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (void*)py_toint(py_arg(1));
    b2Body_SetUserData(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Body_GetUserData(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    void* res = b2Body_GetUserData(_0);
    py_newint(py_retval(), (py_i64)res);
    return true;
}
static bool cfunc__b2Body_GetPosition(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    b2Vec2 res = b2Body_GetPosition(_0);
    py_newvec2(py_retval(), *(c11_vec2*)(&res));
    return true;
}
static bool cfunc__b2Body_GetRotation(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    b2Rot res = b2Body_GetRotation(_0);
    do {
        b2Rot* ud = py_newobject(py_retval(), tp_user_b2Rot, 0, sizeof(b2Rot));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2Body_GetTransform(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    b2Transform res = b2Body_GetTransform(_0);
    do {
        b2Transform* ud = py_newobject(py_retval(), tp_user_b2Transform, 0, sizeof(b2Transform));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2Body_SetTransform(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    b2Vec2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(b2Vec2*)(&tmp);
    } while(0);
    b2Rot _2;
    do {
        if(!py_checktype(py_arg(2), tp_user_b2Rot)) return false;
        _2 = *(b2Rot*)py_touserdata(py_arg(2));
    } while(0);
    b2Body_SetTransform(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Body_GetLocalPoint(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    b2Vec2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(b2Vec2*)(&tmp);
    } while(0);
    b2Vec2 res = b2Body_GetLocalPoint(_0, _1);
    py_newvec2(py_retval(), *(c11_vec2*)(&res));
    return true;
}
static bool cfunc__b2Body_GetWorldPoint(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    b2Vec2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(b2Vec2*)(&tmp);
    } while(0);
    b2Vec2 res = b2Body_GetWorldPoint(_0, _1);
    py_newvec2(py_retval(), *(c11_vec2*)(&res));
    return true;
}
static bool cfunc__b2Body_GetLocalVector(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    b2Vec2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(b2Vec2*)(&tmp);
    } while(0);
    b2Vec2 res = b2Body_GetLocalVector(_0, _1);
    py_newvec2(py_retval(), *(c11_vec2*)(&res));
    return true;
}
static bool cfunc__b2Body_GetWorldVector(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    b2Vec2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(b2Vec2*)(&tmp);
    } while(0);
    b2Vec2 res = b2Body_GetWorldVector(_0, _1);
    py_newvec2(py_retval(), *(c11_vec2*)(&res));
    return true;
}
static bool cfunc__b2Body_GetLinearVelocity(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    b2Vec2 res = b2Body_GetLinearVelocity(_0);
    py_newvec2(py_retval(), *(c11_vec2*)(&res));
    return true;
}
static bool cfunc__b2Body_GetAngularVelocity(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2Body_GetAngularVelocity(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2Body_SetLinearVelocity(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    b2Vec2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(b2Vec2*)(&tmp);
    } while(0);
    b2Body_SetLinearVelocity(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Body_SetAngularVelocity(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2Body_SetAngularVelocity(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Body_ApplyForce(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    b2Vec2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(b2Vec2*)(&tmp);
    } while(0);
    b2Vec2 _2;
    do {
        if(!py_checktype(py_arg(2), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(2));
        _2 = *(b2Vec2*)(&tmp);
    } while(0);
    _Bool _3;
    if(!py_checkbool(py_arg(3))) return false;
    _3 = py_tobool(py_arg(3));
    b2Body_ApplyForce(_0, _1, _2, _3);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Body_ApplyForceToCenter(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    b2Vec2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(b2Vec2*)(&tmp);
    } while(0);
    _Bool _2;
    if(!py_checkbool(py_arg(2))) return false;
    _2 = py_tobool(py_arg(2));
    b2Body_ApplyForceToCenter(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Body_ApplyTorque(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    _Bool _2;
    if(!py_checkbool(py_arg(2))) return false;
    _2 = py_tobool(py_arg(2));
    b2Body_ApplyTorque(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Body_ApplyLinearImpulse(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    b2Vec2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(b2Vec2*)(&tmp);
    } while(0);
    b2Vec2 _2;
    do {
        if(!py_checktype(py_arg(2), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(2));
        _2 = *(b2Vec2*)(&tmp);
    } while(0);
    _Bool _3;
    if(!py_checkbool(py_arg(3))) return false;
    _3 = py_tobool(py_arg(3));
    b2Body_ApplyLinearImpulse(_0, _1, _2, _3);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Body_ApplyLinearImpulseToCenter(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    b2Vec2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(b2Vec2*)(&tmp);
    } while(0);
    _Bool _2;
    if(!py_checkbool(py_arg(2))) return false;
    _2 = py_tobool(py_arg(2));
    b2Body_ApplyLinearImpulseToCenter(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Body_ApplyAngularImpulse(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    _Bool _2;
    if(!py_checkbool(py_arg(2))) return false;
    _2 = py_tobool(py_arg(2));
    b2Body_ApplyAngularImpulse(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Body_GetMass(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2Body_GetMass(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2Body_GetRotationalInertia(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2Body_GetRotationalInertia(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2Body_GetLocalCenterOfMass(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    b2Vec2 res = b2Body_GetLocalCenterOfMass(_0);
    py_newvec2(py_retval(), *(c11_vec2*)(&res));
    return true;
}
static bool cfunc__b2Body_GetWorldCenterOfMass(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    b2Vec2 res = b2Body_GetWorldCenterOfMass(_0);
    py_newvec2(py_retval(), *(c11_vec2*)(&res));
    return true;
}
static bool cfunc__b2Body_SetMassData(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    b2MassData _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_b2MassData)) return false;
        _1 = *(b2MassData*)py_touserdata(py_arg(1));
    } while(0);
    b2Body_SetMassData(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Body_GetMassData(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    b2MassData res = b2Body_GetMassData(_0);
    do {
        b2MassData* ud = py_newobject(py_retval(), tp_user_b2MassData, 0, sizeof(b2MassData));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2Body_ApplyMassFromShapes(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    b2Body_ApplyMassFromShapes(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Body_SetAutomaticMass(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool _1;
    if(!py_checkbool(py_arg(1))) return false;
    _1 = py_tobool(py_arg(1));
    b2Body_SetAutomaticMass(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Body_GetAutomaticMass(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool res = b2Body_GetAutomaticMass(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__b2Body_SetLinearDamping(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2Body_SetLinearDamping(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Body_GetLinearDamping(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2Body_GetLinearDamping(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2Body_SetAngularDamping(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2Body_SetAngularDamping(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Body_GetAngularDamping(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2Body_GetAngularDamping(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2Body_SetGravityScale(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2Body_SetGravityScale(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Body_GetGravityScale(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2Body_GetGravityScale(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2Body_IsAwake(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool res = b2Body_IsAwake(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__b2Body_SetAwake(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool _1;
    if(!py_checkbool(py_arg(1))) return false;
    _1 = py_tobool(py_arg(1));
    b2Body_SetAwake(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Body_EnableSleep(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool _1;
    if(!py_checkbool(py_arg(1))) return false;
    _1 = py_tobool(py_arg(1));
    b2Body_EnableSleep(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Body_IsSleepEnabled(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool res = b2Body_IsSleepEnabled(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__b2Body_SetSleepThreshold(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2Body_SetSleepThreshold(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Body_GetSleepThreshold(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2Body_GetSleepThreshold(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2Body_IsEnabled(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool res = b2Body_IsEnabled(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__b2Body_Disable(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    b2Body_Disable(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Body_Enable(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    b2Body_Enable(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Body_SetFixedRotation(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool _1;
    if(!py_checkbool(py_arg(1))) return false;
    _1 = py_tobool(py_arg(1));
    b2Body_SetFixedRotation(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Body_IsFixedRotation(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool res = b2Body_IsFixedRotation(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__b2Body_SetBullet(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool _1;
    if(!py_checkbool(py_arg(1))) return false;
    _1 = py_tobool(py_arg(1));
    b2Body_SetBullet(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Body_IsBullet(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool res = b2Body_IsBullet(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__b2Body_EnableHitEvents(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool _1;
    if(!py_checkbool(py_arg(1))) return false;
    _1 = py_tobool(py_arg(1));
    b2Body_EnableHitEvents(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Body_GetShapeCount(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    int res = b2Body_GetShapeCount(_0);
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__b2Body_GetShapes(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    b2ShapeId* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (b2ShapeId*)py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    int res = b2Body_GetShapes(_0, _1, _2);
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__b2Body_GetJointCount(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    int res = b2Body_GetJointCount(_0);
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__b2Body_GetJoints(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    b2JointId* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (b2JointId*)py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    int res = b2Body_GetJoints(_0, _1, _2);
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__b2Body_GetContactCapacity(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    int res = b2Body_GetContactCapacity(_0);
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__b2Body_GetContactData(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    b2ContactData* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (b2ContactData*)py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    int res = b2Body_GetContactData(_0, _1, _2);
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__b2Body_ComputeAABB(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    b2AABB res = b2Body_ComputeAABB(_0);
    do {
        b2AABB* ud = py_newobject(py_retval(), tp_user_b2AABB, 0, sizeof(b2AABB));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2CreateCircleShape(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    const b2ShapeDef* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const b2ShapeDef*)py_toint(py_arg(1));
    const b2Circle* _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = (const b2Circle*)py_toint(py_arg(2));
    b2ShapeId res = b2CreateCircleShape(_0, _1, _2);
    do {
        b2ShapeId* ud = py_newobject(py_retval(), tp_user_b2ShapeId, 0, sizeof(b2ShapeId));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2CreateSegmentShape(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    const b2ShapeDef* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const b2ShapeDef*)py_toint(py_arg(1));
    const b2Segment* _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = (const b2Segment*)py_toint(py_arg(2));
    b2ShapeId res = b2CreateSegmentShape(_0, _1, _2);
    do {
        b2ShapeId* ud = py_newobject(py_retval(), tp_user_b2ShapeId, 0, sizeof(b2ShapeId));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2CreateCapsuleShape(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    const b2ShapeDef* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const b2ShapeDef*)py_toint(py_arg(1));
    const b2Capsule* _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = (const b2Capsule*)py_toint(py_arg(2));
    b2ShapeId res = b2CreateCapsuleShape(_0, _1, _2);
    do {
        b2ShapeId* ud = py_newobject(py_retval(), tp_user_b2ShapeId, 0, sizeof(b2ShapeId));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2CreatePolygonShape(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    const b2ShapeDef* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const b2ShapeDef*)py_toint(py_arg(1));
    const b2Polygon* _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = (const b2Polygon*)py_toint(py_arg(2));
    b2ShapeId res = b2CreatePolygonShape(_0, _1, _2);
    do {
        b2ShapeId* ud = py_newobject(py_retval(), tp_user_b2ShapeId, 0, sizeof(b2ShapeId));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2DestroyShape(int argc, py_Ref argv) {
    b2ShapeId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2ShapeId)) return false;
        _0 = *(b2ShapeId*)py_touserdata(py_arg(0));
    } while(0);
    b2DestroyShape(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Shape_IsValid(int argc, py_Ref argv) {
    b2ShapeId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2ShapeId)) return false;
        _0 = *(b2ShapeId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool res = b2Shape_IsValid(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__b2Shape_GetType(int argc, py_Ref argv) {
    b2ShapeId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2ShapeId)) return false;
        _0 = *(b2ShapeId*)py_touserdata(py_arg(0));
    } while(0);
    b2ShapeType res = b2Shape_GetType(_0);
    py_newint(py_retval(), (py_i64)res);
    return true;
}
static bool cfunc__b2Shape_GetBody(int argc, py_Ref argv) {
    b2ShapeId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2ShapeId)) return false;
        _0 = *(b2ShapeId*)py_touserdata(py_arg(0));
    } while(0);
    b2BodyId res = b2Shape_GetBody(_0);
    do {
        b2BodyId* ud = py_newobject(py_retval(), tp_user_b2BodyId, 0, sizeof(b2BodyId));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2Shape_IsSensor(int argc, py_Ref argv) {
    b2ShapeId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2ShapeId)) return false;
        _0 = *(b2ShapeId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool res = b2Shape_IsSensor(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__b2Shape_SetUserData(int argc, py_Ref argv) {
    b2ShapeId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2ShapeId)) return false;
        _0 = *(b2ShapeId*)py_touserdata(py_arg(0));
    } while(0);
    void* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (void*)py_toint(py_arg(1));
    b2Shape_SetUserData(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Shape_GetUserData(int argc, py_Ref argv) {
    b2ShapeId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2ShapeId)) return false;
        _0 = *(b2ShapeId*)py_touserdata(py_arg(0));
    } while(0);
    void* res = b2Shape_GetUserData(_0);
    py_newint(py_retval(), (py_i64)res);
    return true;
}
static bool cfunc__b2Shape_SetDensity(int argc, py_Ref argv) {
    b2ShapeId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2ShapeId)) return false;
        _0 = *(b2ShapeId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2Shape_SetDensity(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Shape_GetDensity(int argc, py_Ref argv) {
    b2ShapeId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2ShapeId)) return false;
        _0 = *(b2ShapeId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2Shape_GetDensity(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2Shape_SetFriction(int argc, py_Ref argv) {
    b2ShapeId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2ShapeId)) return false;
        _0 = *(b2ShapeId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2Shape_SetFriction(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Shape_GetFriction(int argc, py_Ref argv) {
    b2ShapeId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2ShapeId)) return false;
        _0 = *(b2ShapeId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2Shape_GetFriction(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2Shape_SetRestitution(int argc, py_Ref argv) {
    b2ShapeId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2ShapeId)) return false;
        _0 = *(b2ShapeId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2Shape_SetRestitution(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Shape_GetRestitution(int argc, py_Ref argv) {
    b2ShapeId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2ShapeId)) return false;
        _0 = *(b2ShapeId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2Shape_GetRestitution(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2Shape_GetFilter(int argc, py_Ref argv) {
    b2ShapeId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2ShapeId)) return false;
        _0 = *(b2ShapeId*)py_touserdata(py_arg(0));
    } while(0);
    b2Filter res = b2Shape_GetFilter(_0);
    do {
        b2Filter* ud = py_newobject(py_retval(), tp_user_b2Filter, 0, sizeof(b2Filter));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2Shape_SetFilter(int argc, py_Ref argv) {
    b2ShapeId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2ShapeId)) return false;
        _0 = *(b2ShapeId*)py_touserdata(py_arg(0));
    } while(0);
    b2Filter _1;
    do {
        if(!py_checktype(py_arg(1), tp_user_b2Filter)) return false;
        _1 = *(b2Filter*)py_touserdata(py_arg(1));
    } while(0);
    b2Shape_SetFilter(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Shape_EnableSensorEvents(int argc, py_Ref argv) {
    b2ShapeId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2ShapeId)) return false;
        _0 = *(b2ShapeId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool _1;
    if(!py_checkbool(py_arg(1))) return false;
    _1 = py_tobool(py_arg(1));
    b2Shape_EnableSensorEvents(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Shape_AreSensorEventsEnabled(int argc, py_Ref argv) {
    b2ShapeId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2ShapeId)) return false;
        _0 = *(b2ShapeId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool res = b2Shape_AreSensorEventsEnabled(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__b2Shape_EnableContactEvents(int argc, py_Ref argv) {
    b2ShapeId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2ShapeId)) return false;
        _0 = *(b2ShapeId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool _1;
    if(!py_checkbool(py_arg(1))) return false;
    _1 = py_tobool(py_arg(1));
    b2Shape_EnableContactEvents(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Shape_AreContactEventsEnabled(int argc, py_Ref argv) {
    b2ShapeId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2ShapeId)) return false;
        _0 = *(b2ShapeId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool res = b2Shape_AreContactEventsEnabled(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__b2Shape_EnablePreSolveEvents(int argc, py_Ref argv) {
    b2ShapeId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2ShapeId)) return false;
        _0 = *(b2ShapeId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool _1;
    if(!py_checkbool(py_arg(1))) return false;
    _1 = py_tobool(py_arg(1));
    b2Shape_EnablePreSolveEvents(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Shape_ArePreSolveEventsEnabled(int argc, py_Ref argv) {
    b2ShapeId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2ShapeId)) return false;
        _0 = *(b2ShapeId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool res = b2Shape_ArePreSolveEventsEnabled(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__b2Shape_EnableHitEvents(int argc, py_Ref argv) {
    b2ShapeId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2ShapeId)) return false;
        _0 = *(b2ShapeId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool _1;
    if(!py_checkbool(py_arg(1))) return false;
    _1 = py_tobool(py_arg(1));
    b2Shape_EnableHitEvents(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Shape_AreHitEventsEnabled(int argc, py_Ref argv) {
    b2ShapeId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2ShapeId)) return false;
        _0 = *(b2ShapeId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool res = b2Shape_AreHitEventsEnabled(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__b2Shape_TestPoint(int argc, py_Ref argv) {
    b2ShapeId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2ShapeId)) return false;
        _0 = *(b2ShapeId*)py_touserdata(py_arg(0));
    } while(0);
    b2Vec2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(b2Vec2*)(&tmp);
    } while(0);
    _Bool res = b2Shape_TestPoint(_0, _1);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__b2Shape_RayCast(int argc, py_Ref argv) {
    b2ShapeId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2ShapeId)) return false;
        _0 = *(b2ShapeId*)py_touserdata(py_arg(0));
    } while(0);
    b2Vec2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(b2Vec2*)(&tmp);
    } while(0);
    b2Vec2 _2;
    do {
        if(!py_checktype(py_arg(2), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(2));
        _2 = *(b2Vec2*)(&tmp);
    } while(0);
    b2CastOutput res = b2Shape_RayCast(_0, _1, _2);
    do {
        b2CastOutput* ud = py_newobject(py_retval(), tp_user_b2CastOutput, 0, sizeof(b2CastOutput));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2Shape_GetCircle(int argc, py_Ref argv) {
    b2ShapeId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2ShapeId)) return false;
        _0 = *(b2ShapeId*)py_touserdata(py_arg(0));
    } while(0);
    b2Circle res = b2Shape_GetCircle(_0);
    do {
        b2Circle* ud = py_newobject(py_retval(), tp_user_b2Circle, 0, sizeof(b2Circle));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2Shape_GetSegment(int argc, py_Ref argv) {
    b2ShapeId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2ShapeId)) return false;
        _0 = *(b2ShapeId*)py_touserdata(py_arg(0));
    } while(0);
    b2Segment res = b2Shape_GetSegment(_0);
    do {
        b2Segment* ud = py_newobject(py_retval(), tp_user_b2Segment, 0, sizeof(b2Segment));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2Shape_GetSmoothSegment(int argc, py_Ref argv) {
    b2ShapeId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2ShapeId)) return false;
        _0 = *(b2ShapeId*)py_touserdata(py_arg(0));
    } while(0);
    b2SmoothSegment res = b2Shape_GetSmoothSegment(_0);
    do {
        b2SmoothSegment* ud = py_newobject(py_retval(), tp_user_b2SmoothSegment, 0, sizeof(b2SmoothSegment));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2Shape_GetCapsule(int argc, py_Ref argv) {
    b2ShapeId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2ShapeId)) return false;
        _0 = *(b2ShapeId*)py_touserdata(py_arg(0));
    } while(0);
    b2Capsule res = b2Shape_GetCapsule(_0);
    do {
        b2Capsule* ud = py_newobject(py_retval(), tp_user_b2Capsule, 0, sizeof(b2Capsule));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2Shape_GetPolygon(int argc, py_Ref argv) {
    b2ShapeId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2ShapeId)) return false;
        _0 = *(b2ShapeId*)py_touserdata(py_arg(0));
    } while(0);
    b2Polygon res = b2Shape_GetPolygon(_0);
    do {
        b2Polygon* ud = py_newobject(py_retval(), tp_user_b2Polygon, 0, sizeof(b2Polygon));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2Shape_SetCircle(int argc, py_Ref argv) {
    b2ShapeId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2ShapeId)) return false;
        _0 = *(b2ShapeId*)py_touserdata(py_arg(0));
    } while(0);
    const b2Circle* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const b2Circle*)py_toint(py_arg(1));
    b2Shape_SetCircle(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Shape_SetCapsule(int argc, py_Ref argv) {
    b2ShapeId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2ShapeId)) return false;
        _0 = *(b2ShapeId*)py_touserdata(py_arg(0));
    } while(0);
    const b2Capsule* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const b2Capsule*)py_toint(py_arg(1));
    b2Shape_SetCapsule(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Shape_SetSegment(int argc, py_Ref argv) {
    b2ShapeId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2ShapeId)) return false;
        _0 = *(b2ShapeId*)py_touserdata(py_arg(0));
    } while(0);
    const b2Segment* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const b2Segment*)py_toint(py_arg(1));
    b2Shape_SetSegment(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Shape_SetPolygon(int argc, py_Ref argv) {
    b2ShapeId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2ShapeId)) return false;
        _0 = *(b2ShapeId*)py_touserdata(py_arg(0));
    } while(0);
    const b2Polygon* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const b2Polygon*)py_toint(py_arg(1));
    b2Shape_SetPolygon(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Shape_GetParentChain(int argc, py_Ref argv) {
    b2ShapeId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2ShapeId)) return false;
        _0 = *(b2ShapeId*)py_touserdata(py_arg(0));
    } while(0);
    b2ChainId res = b2Shape_GetParentChain(_0);
    do {
        b2ChainId* ud = py_newobject(py_retval(), tp_user_b2ChainId, 0, sizeof(b2ChainId));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2Shape_GetContactCapacity(int argc, py_Ref argv) {
    b2ShapeId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2ShapeId)) return false;
        _0 = *(b2ShapeId*)py_touserdata(py_arg(0));
    } while(0);
    int res = b2Shape_GetContactCapacity(_0);
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__b2Shape_GetContactData(int argc, py_Ref argv) {
    b2ShapeId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2ShapeId)) return false;
        _0 = *(b2ShapeId*)py_touserdata(py_arg(0));
    } while(0);
    b2ContactData* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (b2ContactData*)py_toint(py_arg(1));
    int _2;
    if(!py_checkint(py_arg(2))) return false;
    _2 = py_toint(py_arg(2));
    int res = b2Shape_GetContactData(_0, _1, _2);
    py_newint(py_retval(), res);
    return true;
}
static bool cfunc__b2Shape_GetAABB(int argc, py_Ref argv) {
    b2ShapeId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2ShapeId)) return false;
        _0 = *(b2ShapeId*)py_touserdata(py_arg(0));
    } while(0);
    b2AABB res = b2Shape_GetAABB(_0);
    do {
        b2AABB* ud = py_newobject(py_retval(), tp_user_b2AABB, 0, sizeof(b2AABB));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2Shape_GetClosestPoint(int argc, py_Ref argv) {
    b2ShapeId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2ShapeId)) return false;
        _0 = *(b2ShapeId*)py_touserdata(py_arg(0));
    } while(0);
    b2Vec2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(b2Vec2*)(&tmp);
    } while(0);
    b2Vec2 res = b2Shape_GetClosestPoint(_0, _1);
    py_newvec2(py_retval(), *(c11_vec2*)(&res));
    return true;
}
static bool cfunc__b2CreateChain(int argc, py_Ref argv) {
    b2BodyId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2BodyId)) return false;
        _0 = *(b2BodyId*)py_touserdata(py_arg(0));
    } while(0);
    const b2ChainDef* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const b2ChainDef*)py_toint(py_arg(1));
    b2ChainId res = b2CreateChain(_0, _1);
    do {
        b2ChainId* ud = py_newobject(py_retval(), tp_user_b2ChainId, 0, sizeof(b2ChainId));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2DestroyChain(int argc, py_Ref argv) {
    b2ChainId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2ChainId)) return false;
        _0 = *(b2ChainId*)py_touserdata(py_arg(0));
    } while(0);
    b2DestroyChain(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Chain_SetFriction(int argc, py_Ref argv) {
    b2ChainId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2ChainId)) return false;
        _0 = *(b2ChainId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2Chain_SetFriction(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Chain_SetRestitution(int argc, py_Ref argv) {
    b2ChainId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2ChainId)) return false;
        _0 = *(b2ChainId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2Chain_SetRestitution(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Chain_IsValid(int argc, py_Ref argv) {
    b2ChainId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2ChainId)) return false;
        _0 = *(b2ChainId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool res = b2Chain_IsValid(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__b2DestroyJoint(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    b2DestroyJoint(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Joint_IsValid(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool res = b2Joint_IsValid(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__b2Joint_GetType(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    b2JointType res = b2Joint_GetType(_0);
    py_newint(py_retval(), (py_i64)res);
    return true;
}
static bool cfunc__b2Joint_GetBodyA(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    b2BodyId res = b2Joint_GetBodyA(_0);
    do {
        b2BodyId* ud = py_newobject(py_retval(), tp_user_b2BodyId, 0, sizeof(b2BodyId));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2Joint_GetBodyB(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    b2BodyId res = b2Joint_GetBodyB(_0);
    do {
        b2BodyId* ud = py_newobject(py_retval(), tp_user_b2BodyId, 0, sizeof(b2BodyId));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2Joint_GetLocalAnchorA(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    b2Vec2 res = b2Joint_GetLocalAnchorA(_0);
    py_newvec2(py_retval(), *(c11_vec2*)(&res));
    return true;
}
static bool cfunc__b2Joint_GetLocalAnchorB(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    b2Vec2 res = b2Joint_GetLocalAnchorB(_0);
    py_newvec2(py_retval(), *(c11_vec2*)(&res));
    return true;
}
static bool cfunc__b2Joint_SetCollideConnected(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool _1;
    if(!py_checkbool(py_arg(1))) return false;
    _1 = py_tobool(py_arg(1));
    b2Joint_SetCollideConnected(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Joint_GetCollideConnected(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool res = b2Joint_GetCollideConnected(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__b2Joint_SetUserData(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    void* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (void*)py_toint(py_arg(1));
    b2Joint_SetUserData(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Joint_GetUserData(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    void* res = b2Joint_GetUserData(_0);
    py_newint(py_retval(), (py_i64)res);
    return true;
}
static bool cfunc__b2Joint_WakeBodies(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    b2Joint_WakeBodies(_0);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2Joint_GetConstraintForce(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    b2Vec2 res = b2Joint_GetConstraintForce(_0);
    py_newvec2(py_retval(), *(c11_vec2*)(&res));
    return true;
}
static bool cfunc__b2Joint_GetConstraintTorque(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2Joint_GetConstraintTorque(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2CreateDistanceJoint(int argc, py_Ref argv) {
    b2WorldId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2WorldId)) return false;
        _0 = *(b2WorldId*)py_touserdata(py_arg(0));
    } while(0);
    const b2DistanceJointDef* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const b2DistanceJointDef*)py_toint(py_arg(1));
    b2JointId res = b2CreateDistanceJoint(_0, _1);
    do {
        b2JointId* ud = py_newobject(py_retval(), tp_user_b2JointId, 0, sizeof(b2JointId));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2DistanceJoint_SetLength(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2DistanceJoint_SetLength(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2DistanceJoint_GetLength(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2DistanceJoint_GetLength(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2DistanceJoint_EnableSpring(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool _1;
    if(!py_checkbool(py_arg(1))) return false;
    _1 = py_tobool(py_arg(1));
    b2DistanceJoint_EnableSpring(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2DistanceJoint_IsSpringEnabled(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool res = b2DistanceJoint_IsSpringEnabled(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__b2DistanceJoint_SetSpringHertz(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2DistanceJoint_SetSpringHertz(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2DistanceJoint_SetSpringDampingRatio(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2DistanceJoint_SetSpringDampingRatio(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2DistanceJoint_GetSpringHertz(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2DistanceJoint_GetSpringHertz(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2DistanceJoint_GetSpringDampingRatio(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2DistanceJoint_GetSpringDampingRatio(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2DistanceJoint_EnableLimit(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool _1;
    if(!py_checkbool(py_arg(1))) return false;
    _1 = py_tobool(py_arg(1));
    b2DistanceJoint_EnableLimit(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2DistanceJoint_IsLimitEnabled(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool res = b2DistanceJoint_IsLimitEnabled(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__b2DistanceJoint_SetLengthRange(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    b2DistanceJoint_SetLengthRange(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2DistanceJoint_GetMinLength(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2DistanceJoint_GetMinLength(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2DistanceJoint_GetMaxLength(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2DistanceJoint_GetMaxLength(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2DistanceJoint_GetCurrentLength(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2DistanceJoint_GetCurrentLength(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2DistanceJoint_EnableMotor(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool _1;
    if(!py_checkbool(py_arg(1))) return false;
    _1 = py_tobool(py_arg(1));
    b2DistanceJoint_EnableMotor(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2DistanceJoint_IsMotorEnabled(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool res = b2DistanceJoint_IsMotorEnabled(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__b2DistanceJoint_SetMotorSpeed(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2DistanceJoint_SetMotorSpeed(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2DistanceJoint_GetMotorSpeed(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2DistanceJoint_GetMotorSpeed(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2DistanceJoint_SetMaxMotorForce(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2DistanceJoint_SetMaxMotorForce(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2DistanceJoint_GetMaxMotorForce(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2DistanceJoint_GetMaxMotorForce(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2DistanceJoint_GetMotorForce(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2DistanceJoint_GetMotorForce(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2CreateMotorJoint(int argc, py_Ref argv) {
    b2WorldId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2WorldId)) return false;
        _0 = *(b2WorldId*)py_touserdata(py_arg(0));
    } while(0);
    const b2MotorJointDef* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const b2MotorJointDef*)py_toint(py_arg(1));
    b2JointId res = b2CreateMotorJoint(_0, _1);
    do {
        b2JointId* ud = py_newobject(py_retval(), tp_user_b2JointId, 0, sizeof(b2JointId));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2MotorJoint_SetLinearOffset(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    b2Vec2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(b2Vec2*)(&tmp);
    } while(0);
    b2MotorJoint_SetLinearOffset(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2MotorJoint_GetLinearOffset(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    b2Vec2 res = b2MotorJoint_GetLinearOffset(_0);
    py_newvec2(py_retval(), *(c11_vec2*)(&res));
    return true;
}
static bool cfunc__b2MotorJoint_SetAngularOffset(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2MotorJoint_SetAngularOffset(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2MotorJoint_GetAngularOffset(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2MotorJoint_GetAngularOffset(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2MotorJoint_SetMaxForce(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2MotorJoint_SetMaxForce(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2MotorJoint_GetMaxForce(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2MotorJoint_GetMaxForce(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2MotorJoint_SetMaxTorque(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2MotorJoint_SetMaxTorque(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2MotorJoint_GetMaxTorque(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2MotorJoint_GetMaxTorque(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2MotorJoint_SetCorrectionFactor(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2MotorJoint_SetCorrectionFactor(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2MotorJoint_GetCorrectionFactor(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2MotorJoint_GetCorrectionFactor(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2CreateMouseJoint(int argc, py_Ref argv) {
    b2WorldId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2WorldId)) return false;
        _0 = *(b2WorldId*)py_touserdata(py_arg(0));
    } while(0);
    const b2MouseJointDef* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const b2MouseJointDef*)py_toint(py_arg(1));
    b2JointId res = b2CreateMouseJoint(_0, _1);
    do {
        b2JointId* ud = py_newobject(py_retval(), tp_user_b2JointId, 0, sizeof(b2JointId));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2MouseJoint_SetTarget(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    b2Vec2 _1;
    do {
        if(!py_checktype(py_arg(1), tp_vec2)) return false;
        c11_vec2 tmp = py_tovec2(py_arg(1));
        _1 = *(b2Vec2*)(&tmp);
    } while(0);
    b2MouseJoint_SetTarget(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2MouseJoint_GetTarget(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    b2Vec2 res = b2MouseJoint_GetTarget(_0);
    py_newvec2(py_retval(), *(c11_vec2*)(&res));
    return true;
}
static bool cfunc__b2MouseJoint_SetSpringHertz(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2MouseJoint_SetSpringHertz(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2MouseJoint_GetSpringHertz(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2MouseJoint_GetSpringHertz(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2MouseJoint_SetSpringDampingRatio(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2MouseJoint_SetSpringDampingRatio(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2MouseJoint_GetSpringDampingRatio(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2MouseJoint_GetSpringDampingRatio(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2MouseJoint_SetMaxForce(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2MouseJoint_SetMaxForce(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2MouseJoint_GetMaxForce(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2MouseJoint_GetMaxForce(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2CreatePrismaticJoint(int argc, py_Ref argv) {
    b2WorldId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2WorldId)) return false;
        _0 = *(b2WorldId*)py_touserdata(py_arg(0));
    } while(0);
    const b2PrismaticJointDef* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const b2PrismaticJointDef*)py_toint(py_arg(1));
    b2JointId res = b2CreatePrismaticJoint(_0, _1);
    do {
        b2JointId* ud = py_newobject(py_retval(), tp_user_b2JointId, 0, sizeof(b2JointId));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2PrismaticJoint_EnableSpring(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool _1;
    if(!py_checkbool(py_arg(1))) return false;
    _1 = py_tobool(py_arg(1));
    b2PrismaticJoint_EnableSpring(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2PrismaticJoint_IsSpringEnabled(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool res = b2PrismaticJoint_IsSpringEnabled(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__b2PrismaticJoint_SetSpringHertz(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2PrismaticJoint_SetSpringHertz(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2PrismaticJoint_GetSpringHertz(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2PrismaticJoint_GetSpringHertz(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2PrismaticJoint_SetSpringDampingRatio(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2PrismaticJoint_SetSpringDampingRatio(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2PrismaticJoint_GetSpringDampingRatio(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2PrismaticJoint_GetSpringDampingRatio(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2PrismaticJoint_EnableLimit(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool _1;
    if(!py_checkbool(py_arg(1))) return false;
    _1 = py_tobool(py_arg(1));
    b2PrismaticJoint_EnableLimit(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2PrismaticJoint_IsLimitEnabled(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool res = b2PrismaticJoint_IsLimitEnabled(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__b2PrismaticJoint_GetLowerLimit(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2PrismaticJoint_GetLowerLimit(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2PrismaticJoint_GetUpperLimit(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2PrismaticJoint_GetUpperLimit(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2PrismaticJoint_SetLimits(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    b2PrismaticJoint_SetLimits(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2PrismaticJoint_EnableMotor(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool _1;
    if(!py_checkbool(py_arg(1))) return false;
    _1 = py_tobool(py_arg(1));
    b2PrismaticJoint_EnableMotor(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2PrismaticJoint_IsMotorEnabled(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool res = b2PrismaticJoint_IsMotorEnabled(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__b2PrismaticJoint_SetMotorSpeed(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2PrismaticJoint_SetMotorSpeed(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2PrismaticJoint_GetMotorSpeed(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2PrismaticJoint_GetMotorSpeed(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2PrismaticJoint_SetMaxMotorForce(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2PrismaticJoint_SetMaxMotorForce(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2PrismaticJoint_GetMaxMotorForce(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2PrismaticJoint_GetMaxMotorForce(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2PrismaticJoint_GetMotorForce(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2PrismaticJoint_GetMotorForce(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2CreateRevoluteJoint(int argc, py_Ref argv) {
    b2WorldId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2WorldId)) return false;
        _0 = *(b2WorldId*)py_touserdata(py_arg(0));
    } while(0);
    const b2RevoluteJointDef* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const b2RevoluteJointDef*)py_toint(py_arg(1));
    b2JointId res = b2CreateRevoluteJoint(_0, _1);
    do {
        b2JointId* ud = py_newobject(py_retval(), tp_user_b2JointId, 0, sizeof(b2JointId));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2RevoluteJoint_EnableSpring(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool _1;
    if(!py_checkbool(py_arg(1))) return false;
    _1 = py_tobool(py_arg(1));
    b2RevoluteJoint_EnableSpring(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2RevoluteJoint_IsSpringEnabled(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool res = b2RevoluteJoint_IsSpringEnabled(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__b2RevoluteJoint_SetSpringHertz(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2RevoluteJoint_SetSpringHertz(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2RevoluteJoint_GetSpringHertz(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2RevoluteJoint_GetSpringHertz(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2RevoluteJoint_SetSpringDampingRatio(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2RevoluteJoint_SetSpringDampingRatio(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2RevoluteJoint_GetSpringDampingRatio(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2RevoluteJoint_GetSpringDampingRatio(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2RevoluteJoint_GetAngle(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2RevoluteJoint_GetAngle(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2RevoluteJoint_EnableLimit(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool _1;
    if(!py_checkbool(py_arg(1))) return false;
    _1 = py_tobool(py_arg(1));
    b2RevoluteJoint_EnableLimit(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2RevoluteJoint_IsLimitEnabled(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool res = b2RevoluteJoint_IsLimitEnabled(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__b2RevoluteJoint_GetLowerLimit(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2RevoluteJoint_GetLowerLimit(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2RevoluteJoint_GetUpperLimit(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2RevoluteJoint_GetUpperLimit(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2RevoluteJoint_SetLimits(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    b2RevoluteJoint_SetLimits(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2RevoluteJoint_EnableMotor(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool _1;
    if(!py_checkbool(py_arg(1))) return false;
    _1 = py_tobool(py_arg(1));
    b2RevoluteJoint_EnableMotor(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2RevoluteJoint_IsMotorEnabled(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool res = b2RevoluteJoint_IsMotorEnabled(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__b2RevoluteJoint_SetMotorSpeed(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2RevoluteJoint_SetMotorSpeed(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2RevoluteJoint_GetMotorSpeed(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2RevoluteJoint_GetMotorSpeed(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2RevoluteJoint_GetMotorTorque(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2RevoluteJoint_GetMotorTorque(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2RevoluteJoint_SetMaxMotorTorque(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2RevoluteJoint_SetMaxMotorTorque(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2RevoluteJoint_GetMaxMotorTorque(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2RevoluteJoint_GetMaxMotorTorque(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2CreateWeldJoint(int argc, py_Ref argv) {
    b2WorldId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2WorldId)) return false;
        _0 = *(b2WorldId*)py_touserdata(py_arg(0));
    } while(0);
    const b2WeldJointDef* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const b2WeldJointDef*)py_toint(py_arg(1));
    b2JointId res = b2CreateWeldJoint(_0, _1);
    do {
        b2JointId* ud = py_newobject(py_retval(), tp_user_b2JointId, 0, sizeof(b2JointId));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2WeldJoint_SetLinearHertz(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2WeldJoint_SetLinearHertz(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2WeldJoint_GetLinearHertz(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2WeldJoint_GetLinearHertz(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2WeldJoint_SetLinearDampingRatio(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2WeldJoint_SetLinearDampingRatio(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2WeldJoint_GetLinearDampingRatio(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2WeldJoint_GetLinearDampingRatio(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2WeldJoint_SetAngularHertz(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2WeldJoint_SetAngularHertz(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2WeldJoint_GetAngularHertz(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2WeldJoint_GetAngularHertz(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2WeldJoint_SetAngularDampingRatio(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2WeldJoint_SetAngularDampingRatio(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2WeldJoint_GetAngularDampingRatio(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2WeldJoint_GetAngularDampingRatio(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2CreateWheelJoint(int argc, py_Ref argv) {
    b2WorldId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2WorldId)) return false;
        _0 = *(b2WorldId*)py_touserdata(py_arg(0));
    } while(0);
    const b2WheelJointDef* _1;
    if(!py_checkint(py_arg(1))) return false;
    _1 = (const b2WheelJointDef*)py_toint(py_arg(1));
    b2JointId res = b2CreateWheelJoint(_0, _1);
    do {
        b2JointId* ud = py_newobject(py_retval(), tp_user_b2JointId, 0, sizeof(b2JointId));
        *ud = res;
    } while(0);
    return true;
}
static bool cfunc__b2WheelJoint_EnableSpring(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool _1;
    if(!py_checkbool(py_arg(1))) return false;
    _1 = py_tobool(py_arg(1));
    b2WheelJoint_EnableSpring(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2WheelJoint_IsSpringEnabled(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool res = b2WheelJoint_IsSpringEnabled(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__b2WheelJoint_SetSpringHertz(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2WheelJoint_SetSpringHertz(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2WheelJoint_GetSpringHertz(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2WheelJoint_GetSpringHertz(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2WheelJoint_SetSpringDampingRatio(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2WheelJoint_SetSpringDampingRatio(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2WheelJoint_GetSpringDampingRatio(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2WheelJoint_GetSpringDampingRatio(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2WheelJoint_EnableLimit(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool _1;
    if(!py_checkbool(py_arg(1))) return false;
    _1 = py_tobool(py_arg(1));
    b2WheelJoint_EnableLimit(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2WheelJoint_IsLimitEnabled(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool res = b2WheelJoint_IsLimitEnabled(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__b2WheelJoint_GetLowerLimit(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2WheelJoint_GetLowerLimit(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2WheelJoint_GetUpperLimit(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2WheelJoint_GetUpperLimit(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2WheelJoint_SetLimits(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    float _2;
    if(!py_castfloat32(py_arg(2), &_2)) return false;
    b2WheelJoint_SetLimits(_0, _1, _2);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2WheelJoint_EnableMotor(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool _1;
    if(!py_checkbool(py_arg(1))) return false;
    _1 = py_tobool(py_arg(1));
    b2WheelJoint_EnableMotor(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2WheelJoint_IsMotorEnabled(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    _Bool res = b2WheelJoint_IsMotorEnabled(_0);
    py_newbool(py_retval(), res);
    return true;
}
static bool cfunc__b2WheelJoint_SetMotorSpeed(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2WheelJoint_SetMotorSpeed(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2WheelJoint_GetMotorSpeed(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2WheelJoint_GetMotorSpeed(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2WheelJoint_SetMaxMotorTorque(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float _1;
    if(!py_castfloat32(py_arg(1), &_1)) return false;
    b2WheelJoint_SetMaxMotorTorque(_0, _1);
    py_newnone(py_retval());
    return true;
}
static bool cfunc__b2WheelJoint_GetMaxMotorTorque(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2WheelJoint_GetMaxMotorTorque(_0);
    py_newfloat(py_retval(), res);
    return true;
}
static bool cfunc__b2WheelJoint_GetMotorTorque(int argc, py_Ref argv) {
    b2JointId _0;
    do {
        if(!py_checktype(py_arg(0), tp_user_b2JointId)) return false;
        _0 = *(b2JointId*)py_touserdata(py_arg(0));
    } while(0);
    float res = b2WheelJoint_GetMotorTorque(_0);
    py_newfloat(py_retval(), res);
    return true;
}
void py__add_module_box2d() {
    py_GlobalRef mod = py_newmodule("box2d");
    /* structs */
    tp_user_b2Version = register__b2Version(mod);
    tp_user_b2Vec2 = register__b2Vec2(mod);
    tp_user_b2Rot = register__b2Rot(mod);
    tp_user_b2Transform = register__b2Transform(mod);
    tp_user_b2Mat22 = register__b2Mat22(mod);
    tp_user_b2AABB = register__b2AABB(mod);
    tp_user_b2RayCastInput = register__b2RayCastInput(mod);
    tp_user_b2ShapeCastInput = register__b2ShapeCastInput(mod);
    tp_user_b2CastOutput = register__b2CastOutput(mod);
    tp_user_b2MassData = register__b2MassData(mod);
    tp_user_b2Circle = register__b2Circle(mod);
    tp_user_b2Capsule = register__b2Capsule(mod);
    tp_user_b2Polygon = register__b2Polygon(mod);
    tp_user_b2Segment = register__b2Segment(mod);
    tp_user_b2SmoothSegment = register__b2SmoothSegment(mod);
    tp_user_b2Hull = register__b2Hull(mod);
    tp_user_b2SegmentDistanceResult = register__b2SegmentDistanceResult(mod);
    tp_user_b2DistanceProxy = register__b2DistanceProxy(mod);
    tp_user_b2DistanceCache = register__b2DistanceCache(mod);
    tp_user_b2DistanceInput = register__b2DistanceInput(mod);
    tp_user_b2DistanceOutput = register__b2DistanceOutput(mod);
    tp_user_b2SimplexVertex = register__b2SimplexVertex(mod);
    tp_user_b2Simplex = register__b2Simplex(mod);
    tp_user_b2ShapeCastPairInput = register__b2ShapeCastPairInput(mod);
    tp_user_b2Sweep = register__b2Sweep(mod);
    tp_user_b2TOIInput = register__b2TOIInput(mod);
    tp_user_b2TOIOutput = register__b2TOIOutput(mod);
    tp_user_b2ManifoldPoint = register__b2ManifoldPoint(mod);
    tp_user_b2Manifold = register__b2Manifold(mod);
    tp_user_b2TreeNode = register__b2TreeNode(mod);
    tp_user_b2DynamicTree = register__b2DynamicTree(mod);
    tp_user_b2WorldId = register__b2WorldId(mod);
    tp_user_b2BodyId = register__b2BodyId(mod);
    tp_user_b2ShapeId = register__b2ShapeId(mod);
    tp_user_b2JointId = register__b2JointId(mod);
    tp_user_b2ChainId = register__b2ChainId(mod);
    tp_user_b2RayResult = register__b2RayResult(mod);
    tp_user_b2WorldDef = register__b2WorldDef(mod);
    tp_user_b2BodyDef = register__b2BodyDef(mod);
    tp_user_b2Filter = register__b2Filter(mod);
    tp_user_b2QueryFilter = register__b2QueryFilter(mod);
    tp_user_b2ShapeDef = register__b2ShapeDef(mod);
    tp_user_b2ChainDef = register__b2ChainDef(mod);
    tp_user_b2Profile = register__b2Profile(mod);
    tp_user_b2Counters = register__b2Counters(mod);
    tp_user_b2DistanceJointDef = register__b2DistanceJointDef(mod);
    tp_user_b2MotorJointDef = register__b2MotorJointDef(mod);
    tp_user_b2MouseJointDef = register__b2MouseJointDef(mod);
    tp_user_b2PrismaticJointDef = register__b2PrismaticJointDef(mod);
    tp_user_b2RevoluteJointDef = register__b2RevoluteJointDef(mod);
    tp_user_b2WeldJointDef = register__b2WeldJointDef(mod);
    tp_user_b2WheelJointDef = register__b2WheelJointDef(mod);
    tp_user_b2SensorBeginTouchEvent = register__b2SensorBeginTouchEvent(mod);
    tp_user_b2SensorEndTouchEvent = register__b2SensorEndTouchEvent(mod);
    tp_user_b2SensorEvents = register__b2SensorEvents(mod);
    tp_user_b2ContactBeginTouchEvent = register__b2ContactBeginTouchEvent(mod);
    tp_user_b2ContactEndTouchEvent = register__b2ContactEndTouchEvent(mod);
    tp_user_b2ContactHitEvent = register__b2ContactHitEvent(mod);
    tp_user_b2ContactEvents = register__b2ContactEvents(mod);
    tp_user_b2BodyMoveEvent = register__b2BodyMoveEvent(mod);
    tp_user_b2BodyEvents = register__b2BodyEvents(mod);
    tp_user_b2ContactData = register__b2ContactData(mod);
    /* aliases */
    /* functions */
    py_bindfunc(mod, "b2SetAllocator", &cfunc__b2SetAllocator);
    py_bindfunc(mod, "b2GetByteCount", &cfunc__b2GetByteCount);
    py_bindfunc(mod, "b2SetAssertFcn", &cfunc__b2SetAssertFcn);
    py_bindfunc(mod, "b2GetVersion", &cfunc__b2GetVersion);
    py_bindfunc(mod, "b2GetTicks", &cfunc__b2GetTicks);
    py_bindfunc(mod, "b2GetMilliseconds", &cfunc__b2GetMilliseconds);
    py_bindfunc(mod, "b2GetMillisecondsAndReset", &cfunc__b2GetMillisecondsAndReset);
    py_bindfunc(mod, "b2SleepMilliseconds", &cfunc__b2SleepMilliseconds);
    py_bindfunc(mod, "b2Yield", &cfunc__b2Yield);
    py_bindfunc(mod, "b2Atan2", &cfunc__b2Atan2);
    py_bindfunc(mod, "b2MakeRot", &cfunc__b2MakeRot);
    py_bindfunc(mod, "b2IsValid", &cfunc__b2IsValid);
    py_bindfunc(mod, "b2Vec2_IsValid", &cfunc__b2Vec2_IsValid);
    py_bindfunc(mod, "b2Rot_IsValid", &cfunc__b2Rot_IsValid);
    py_bindfunc(mod, "b2AABB_IsValid", &cfunc__b2AABB_IsValid);
    py_bindfunc(mod, "b2SetLengthUnitsPerMeter", &cfunc__b2SetLengthUnitsPerMeter);
    py_bindfunc(mod, "b2GetLengthUnitsPerMeter", &cfunc__b2GetLengthUnitsPerMeter);
    py_bindfunc(mod, "b2IsValidRay", &cfunc__b2IsValidRay);
    py_bindfunc(mod, "b2MakePolygon", &cfunc__b2MakePolygon);
    py_bindfunc(mod, "b2MakeOffsetPolygon", &cfunc__b2MakeOffsetPolygon);
    py_bindfunc(mod, "b2MakeSquare", &cfunc__b2MakeSquare);
    py_bindfunc(mod, "b2MakeBox", &cfunc__b2MakeBox);
    py_bindfunc(mod, "b2MakeRoundedBox", &cfunc__b2MakeRoundedBox);
    py_bindfunc(mod, "b2MakeOffsetBox", &cfunc__b2MakeOffsetBox);
    py_bindfunc(mod, "b2TransformPolygon", &cfunc__b2TransformPolygon);
    py_bindfunc(mod, "b2ComputeCircleMass", &cfunc__b2ComputeCircleMass);
    py_bindfunc(mod, "b2ComputeCapsuleMass", &cfunc__b2ComputeCapsuleMass);
    py_bindfunc(mod, "b2ComputePolygonMass", &cfunc__b2ComputePolygonMass);
    py_bindfunc(mod, "b2ComputeCircleAABB", &cfunc__b2ComputeCircleAABB);
    py_bindfunc(mod, "b2ComputeCapsuleAABB", &cfunc__b2ComputeCapsuleAABB);
    py_bindfunc(mod, "b2ComputePolygonAABB", &cfunc__b2ComputePolygonAABB);
    py_bindfunc(mod, "b2ComputeSegmentAABB", &cfunc__b2ComputeSegmentAABB);
    py_bindfunc(mod, "b2PointInCircle", &cfunc__b2PointInCircle);
    py_bindfunc(mod, "b2PointInCapsule", &cfunc__b2PointInCapsule);
    py_bindfunc(mod, "b2PointInPolygon", &cfunc__b2PointInPolygon);
    py_bindfunc(mod, "b2RayCastCircle", &cfunc__b2RayCastCircle);
    py_bindfunc(mod, "b2RayCastCapsule", &cfunc__b2RayCastCapsule);
    py_bindfunc(mod, "b2RayCastSegment", &cfunc__b2RayCastSegment);
    py_bindfunc(mod, "b2RayCastPolygon", &cfunc__b2RayCastPolygon);
    py_bindfunc(mod, "b2ShapeCastCircle", &cfunc__b2ShapeCastCircle);
    py_bindfunc(mod, "b2ShapeCastCapsule", &cfunc__b2ShapeCastCapsule);
    py_bindfunc(mod, "b2ShapeCastSegment", &cfunc__b2ShapeCastSegment);
    py_bindfunc(mod, "b2ShapeCastPolygon", &cfunc__b2ShapeCastPolygon);
    py_bindfunc(mod, "b2ComputeHull", &cfunc__b2ComputeHull);
    py_bindfunc(mod, "b2ValidateHull", &cfunc__b2ValidateHull);
    py_bindfunc(mod, "b2SegmentDistance", &cfunc__b2SegmentDistance);
    py_bindfunc(mod, "b2ShapeDistance", &cfunc__b2ShapeDistance);
    py_bindfunc(mod, "b2ShapeCast", &cfunc__b2ShapeCast);
    py_bindfunc(mod, "b2MakeProxy", &cfunc__b2MakeProxy);
    py_bindfunc(mod, "b2GetSweepTransform", &cfunc__b2GetSweepTransform);
    py_bindfunc(mod, "b2TimeOfImpact", &cfunc__b2TimeOfImpact);
    py_bindfunc(mod, "b2CollideCircles", &cfunc__b2CollideCircles);
    py_bindfunc(mod, "b2CollideCapsuleAndCircle", &cfunc__b2CollideCapsuleAndCircle);
    py_bindfunc(mod, "b2CollideSegmentAndCircle", &cfunc__b2CollideSegmentAndCircle);
    py_bindfunc(mod, "b2CollidePolygonAndCircle", &cfunc__b2CollidePolygonAndCircle);
    py_bindfunc(mod, "b2CollideCapsules", &cfunc__b2CollideCapsules);
    py_bindfunc(mod, "b2CollideSegmentAndCapsule", &cfunc__b2CollideSegmentAndCapsule);
    py_bindfunc(mod, "b2CollidePolygonAndCapsule", &cfunc__b2CollidePolygonAndCapsule);
    py_bindfunc(mod, "b2CollidePolygons", &cfunc__b2CollidePolygons);
    py_bindfunc(mod, "b2CollideSegmentAndPolygon", &cfunc__b2CollideSegmentAndPolygon);
    py_bindfunc(mod, "b2CollideSmoothSegmentAndCircle", &cfunc__b2CollideSmoothSegmentAndCircle);
    py_bindfunc(mod, "b2CollideSmoothSegmentAndCapsule", &cfunc__b2CollideSmoothSegmentAndCapsule);
    py_bindfunc(mod, "b2CollideSmoothSegmentAndPolygon", &cfunc__b2CollideSmoothSegmentAndPolygon);
    py_bindfunc(mod, "b2DynamicTree_Create", &cfunc__b2DynamicTree_Create);
    py_bindfunc(mod, "b2DynamicTree_Destroy", &cfunc__b2DynamicTree_Destroy);
    py_bindfunc(mod, "b2DynamicTree_CreateProxy", &cfunc__b2DynamicTree_CreateProxy);
    py_bindfunc(mod, "b2DynamicTree_DestroyProxy", &cfunc__b2DynamicTree_DestroyProxy);
    py_bindfunc(mod, "b2DynamicTree_MoveProxy", &cfunc__b2DynamicTree_MoveProxy);
    py_bindfunc(mod, "b2DynamicTree_EnlargeProxy", &cfunc__b2DynamicTree_EnlargeProxy);
    py_bindfunc(mod, "b2DynamicTree_Query", &cfunc__b2DynamicTree_Query);
    py_bindfunc(mod, "b2DynamicTree_RayCast", &cfunc__b2DynamicTree_RayCast);
    py_bindfunc(mod, "b2DynamicTree_ShapeCast", &cfunc__b2DynamicTree_ShapeCast);
    py_bindfunc(mod, "b2DynamicTree_Validate", &cfunc__b2DynamicTree_Validate);
    py_bindfunc(mod, "b2DynamicTree_GetHeight", &cfunc__b2DynamicTree_GetHeight);
    py_bindfunc(mod, "b2DynamicTree_GetMaxBalance", &cfunc__b2DynamicTree_GetMaxBalance);
    py_bindfunc(mod, "b2DynamicTree_GetAreaRatio", &cfunc__b2DynamicTree_GetAreaRatio);
    py_bindfunc(mod, "b2DynamicTree_RebuildBottomUp", &cfunc__b2DynamicTree_RebuildBottomUp);
    py_bindfunc(mod, "b2DynamicTree_GetProxyCount", &cfunc__b2DynamicTree_GetProxyCount);
    py_bindfunc(mod, "b2DynamicTree_Rebuild", &cfunc__b2DynamicTree_Rebuild);
    py_bindfunc(mod, "b2DynamicTree_ShiftOrigin", &cfunc__b2DynamicTree_ShiftOrigin);
    py_bindfunc(mod, "b2DynamicTree_GetByteCount", &cfunc__b2DynamicTree_GetByteCount);
    py_bindfunc(mod, "b2DefaultWorldDef", &cfunc__b2DefaultWorldDef);
    py_bindfunc(mod, "b2DefaultBodyDef", &cfunc__b2DefaultBodyDef);
    py_bindfunc(mod, "b2DefaultFilter", &cfunc__b2DefaultFilter);
    py_bindfunc(mod, "b2DefaultQueryFilter", &cfunc__b2DefaultQueryFilter);
    py_bindfunc(mod, "b2DefaultShapeDef", &cfunc__b2DefaultShapeDef);
    py_bindfunc(mod, "b2DefaultChainDef", &cfunc__b2DefaultChainDef);
    py_bindfunc(mod, "b2DefaultDistanceJointDef", &cfunc__b2DefaultDistanceJointDef);
    py_bindfunc(mod, "b2DefaultMotorJointDef", &cfunc__b2DefaultMotorJointDef);
    py_bindfunc(mod, "b2DefaultMouseJointDef", &cfunc__b2DefaultMouseJointDef);
    py_bindfunc(mod, "b2DefaultPrismaticJointDef", &cfunc__b2DefaultPrismaticJointDef);
    py_bindfunc(mod, "b2DefaultRevoluteJointDef", &cfunc__b2DefaultRevoluteJointDef);
    py_bindfunc(mod, "b2DefaultWeldJointDef", &cfunc__b2DefaultWeldJointDef);
    py_bindfunc(mod, "b2DefaultWheelJointDef", &cfunc__b2DefaultWheelJointDef);
    py_bindfunc(mod, "b2CreateWorld", &cfunc__b2CreateWorld);
    py_bindfunc(mod, "b2DestroyWorld", &cfunc__b2DestroyWorld);
    py_bindfunc(mod, "b2World_IsValid", &cfunc__b2World_IsValid);
    py_bindfunc(mod, "b2World_Step", &cfunc__b2World_Step);
    py_bindfunc(mod, "b2World_Draw", &cfunc__b2World_Draw);
    py_bindfunc(mod, "b2World_GetBodyEvents", &cfunc__b2World_GetBodyEvents);
    py_bindfunc(mod, "b2World_GetSensorEvents", &cfunc__b2World_GetSensorEvents);
    py_bindfunc(mod, "b2World_GetContactEvents", &cfunc__b2World_GetContactEvents);
    py_bindfunc(mod, "b2World_OverlapAABB", &cfunc__b2World_OverlapAABB);
    py_bindfunc(mod, "b2World_OverlapCircle", &cfunc__b2World_OverlapCircle);
    py_bindfunc(mod, "b2World_OverlapCapsule", &cfunc__b2World_OverlapCapsule);
    py_bindfunc(mod, "b2World_OverlapPolygon", &cfunc__b2World_OverlapPolygon);
    py_bindfunc(mod, "b2World_CastRay", &cfunc__b2World_CastRay);
    py_bindfunc(mod, "b2World_CastRayClosest", &cfunc__b2World_CastRayClosest);
    py_bindfunc(mod, "b2World_CastCircle", &cfunc__b2World_CastCircle);
    py_bindfunc(mod, "b2World_CastCapsule", &cfunc__b2World_CastCapsule);
    py_bindfunc(mod, "b2World_CastPolygon", &cfunc__b2World_CastPolygon);
    py_bindfunc(mod, "b2World_EnableSleeping", &cfunc__b2World_EnableSleeping);
    py_bindfunc(mod, "b2World_EnableContinuous", &cfunc__b2World_EnableContinuous);
    py_bindfunc(mod, "b2World_SetRestitutionThreshold", &cfunc__b2World_SetRestitutionThreshold);
    py_bindfunc(mod, "b2World_SetHitEventThreshold", &cfunc__b2World_SetHitEventThreshold);
    py_bindfunc(mod, "b2World_SetCustomFilterCallback", &cfunc__b2World_SetCustomFilterCallback);
    py_bindfunc(mod, "b2World_SetPreSolveCallback", &cfunc__b2World_SetPreSolveCallback);
    py_bindfunc(mod, "b2World_SetGravity", &cfunc__b2World_SetGravity);
    py_bindfunc(mod, "b2World_GetGravity", &cfunc__b2World_GetGravity);
    py_bindfunc(mod, "b2World_Explode", &cfunc__b2World_Explode);
    py_bindfunc(mod, "b2World_SetContactTuning", &cfunc__b2World_SetContactTuning);
    py_bindfunc(mod, "b2World_EnableWarmStarting", &cfunc__b2World_EnableWarmStarting);
    py_bindfunc(mod, "b2World_GetProfile", &cfunc__b2World_GetProfile);
    py_bindfunc(mod, "b2World_GetCounters", &cfunc__b2World_GetCounters);
    py_bindfunc(mod, "b2World_DumpMemoryStats", &cfunc__b2World_DumpMemoryStats);
    py_bindfunc(mod, "b2CreateBody", &cfunc__b2CreateBody);
    py_bindfunc(mod, "b2DestroyBody", &cfunc__b2DestroyBody);
    py_bindfunc(mod, "b2Body_IsValid", &cfunc__b2Body_IsValid);
    py_bindfunc(mod, "b2Body_GetType", &cfunc__b2Body_GetType);
    py_bindfunc(mod, "b2Body_SetType", &cfunc__b2Body_SetType);
    py_bindfunc(mod, "b2Body_SetUserData", &cfunc__b2Body_SetUserData);
    py_bindfunc(mod, "b2Body_GetUserData", &cfunc__b2Body_GetUserData);
    py_bindfunc(mod, "b2Body_GetPosition", &cfunc__b2Body_GetPosition);
    py_bindfunc(mod, "b2Body_GetRotation", &cfunc__b2Body_GetRotation);
    py_bindfunc(mod, "b2Body_GetTransform", &cfunc__b2Body_GetTransform);
    py_bindfunc(mod, "b2Body_SetTransform", &cfunc__b2Body_SetTransform);
    py_bindfunc(mod, "b2Body_GetLocalPoint", &cfunc__b2Body_GetLocalPoint);
    py_bindfunc(mod, "b2Body_GetWorldPoint", &cfunc__b2Body_GetWorldPoint);
    py_bindfunc(mod, "b2Body_GetLocalVector", &cfunc__b2Body_GetLocalVector);
    py_bindfunc(mod, "b2Body_GetWorldVector", &cfunc__b2Body_GetWorldVector);
    py_bindfunc(mod, "b2Body_GetLinearVelocity", &cfunc__b2Body_GetLinearVelocity);
    py_bindfunc(mod, "b2Body_GetAngularVelocity", &cfunc__b2Body_GetAngularVelocity);
    py_bindfunc(mod, "b2Body_SetLinearVelocity", &cfunc__b2Body_SetLinearVelocity);
    py_bindfunc(mod, "b2Body_SetAngularVelocity", &cfunc__b2Body_SetAngularVelocity);
    py_bindfunc(mod, "b2Body_ApplyForce", &cfunc__b2Body_ApplyForce);
    py_bindfunc(mod, "b2Body_ApplyForceToCenter", &cfunc__b2Body_ApplyForceToCenter);
    py_bindfunc(mod, "b2Body_ApplyTorque", &cfunc__b2Body_ApplyTorque);
    py_bindfunc(mod, "b2Body_ApplyLinearImpulse", &cfunc__b2Body_ApplyLinearImpulse);
    py_bindfunc(mod, "b2Body_ApplyLinearImpulseToCenter", &cfunc__b2Body_ApplyLinearImpulseToCenter);
    py_bindfunc(mod, "b2Body_ApplyAngularImpulse", &cfunc__b2Body_ApplyAngularImpulse);
    py_bindfunc(mod, "b2Body_GetMass", &cfunc__b2Body_GetMass);
    py_bindfunc(mod, "b2Body_GetRotationalInertia", &cfunc__b2Body_GetRotationalInertia);
    py_bindfunc(mod, "b2Body_GetLocalCenterOfMass", &cfunc__b2Body_GetLocalCenterOfMass);
    py_bindfunc(mod, "b2Body_GetWorldCenterOfMass", &cfunc__b2Body_GetWorldCenterOfMass);
    py_bindfunc(mod, "b2Body_SetMassData", &cfunc__b2Body_SetMassData);
    py_bindfunc(mod, "b2Body_GetMassData", &cfunc__b2Body_GetMassData);
    py_bindfunc(mod, "b2Body_ApplyMassFromShapes", &cfunc__b2Body_ApplyMassFromShapes);
    py_bindfunc(mod, "b2Body_SetAutomaticMass", &cfunc__b2Body_SetAutomaticMass);
    py_bindfunc(mod, "b2Body_GetAutomaticMass", &cfunc__b2Body_GetAutomaticMass);
    py_bindfunc(mod, "b2Body_SetLinearDamping", &cfunc__b2Body_SetLinearDamping);
    py_bindfunc(mod, "b2Body_GetLinearDamping", &cfunc__b2Body_GetLinearDamping);
    py_bindfunc(mod, "b2Body_SetAngularDamping", &cfunc__b2Body_SetAngularDamping);
    py_bindfunc(mod, "b2Body_GetAngularDamping", &cfunc__b2Body_GetAngularDamping);
    py_bindfunc(mod, "b2Body_SetGravityScale", &cfunc__b2Body_SetGravityScale);
    py_bindfunc(mod, "b2Body_GetGravityScale", &cfunc__b2Body_GetGravityScale);
    py_bindfunc(mod, "b2Body_IsAwake", &cfunc__b2Body_IsAwake);
    py_bindfunc(mod, "b2Body_SetAwake", &cfunc__b2Body_SetAwake);
    py_bindfunc(mod, "b2Body_EnableSleep", &cfunc__b2Body_EnableSleep);
    py_bindfunc(mod, "b2Body_IsSleepEnabled", &cfunc__b2Body_IsSleepEnabled);
    py_bindfunc(mod, "b2Body_SetSleepThreshold", &cfunc__b2Body_SetSleepThreshold);
    py_bindfunc(mod, "b2Body_GetSleepThreshold", &cfunc__b2Body_GetSleepThreshold);
    py_bindfunc(mod, "b2Body_IsEnabled", &cfunc__b2Body_IsEnabled);
    py_bindfunc(mod, "b2Body_Disable", &cfunc__b2Body_Disable);
    py_bindfunc(mod, "b2Body_Enable", &cfunc__b2Body_Enable);
    py_bindfunc(mod, "b2Body_SetFixedRotation", &cfunc__b2Body_SetFixedRotation);
    py_bindfunc(mod, "b2Body_IsFixedRotation", &cfunc__b2Body_IsFixedRotation);
    py_bindfunc(mod, "b2Body_SetBullet", &cfunc__b2Body_SetBullet);
    py_bindfunc(mod, "b2Body_IsBullet", &cfunc__b2Body_IsBullet);
    py_bindfunc(mod, "b2Body_EnableHitEvents", &cfunc__b2Body_EnableHitEvents);
    py_bindfunc(mod, "b2Body_GetShapeCount", &cfunc__b2Body_GetShapeCount);
    py_bindfunc(mod, "b2Body_GetShapes", &cfunc__b2Body_GetShapes);
    py_bindfunc(mod, "b2Body_GetJointCount", &cfunc__b2Body_GetJointCount);
    py_bindfunc(mod, "b2Body_GetJoints", &cfunc__b2Body_GetJoints);
    py_bindfunc(mod, "b2Body_GetContactCapacity", &cfunc__b2Body_GetContactCapacity);
    py_bindfunc(mod, "b2Body_GetContactData", &cfunc__b2Body_GetContactData);
    py_bindfunc(mod, "b2Body_ComputeAABB", &cfunc__b2Body_ComputeAABB);
    py_bindfunc(mod, "b2CreateCircleShape", &cfunc__b2CreateCircleShape);
    py_bindfunc(mod, "b2CreateSegmentShape", &cfunc__b2CreateSegmentShape);
    py_bindfunc(mod, "b2CreateCapsuleShape", &cfunc__b2CreateCapsuleShape);
    py_bindfunc(mod, "b2CreatePolygonShape", &cfunc__b2CreatePolygonShape);
    py_bindfunc(mod, "b2DestroyShape", &cfunc__b2DestroyShape);
    py_bindfunc(mod, "b2Shape_IsValid", &cfunc__b2Shape_IsValid);
    py_bindfunc(mod, "b2Shape_GetType", &cfunc__b2Shape_GetType);
    py_bindfunc(mod, "b2Shape_GetBody", &cfunc__b2Shape_GetBody);
    py_bindfunc(mod, "b2Shape_IsSensor", &cfunc__b2Shape_IsSensor);
    py_bindfunc(mod, "b2Shape_SetUserData", &cfunc__b2Shape_SetUserData);
    py_bindfunc(mod, "b2Shape_GetUserData", &cfunc__b2Shape_GetUserData);
    py_bindfunc(mod, "b2Shape_SetDensity", &cfunc__b2Shape_SetDensity);
    py_bindfunc(mod, "b2Shape_GetDensity", &cfunc__b2Shape_GetDensity);
    py_bindfunc(mod, "b2Shape_SetFriction", &cfunc__b2Shape_SetFriction);
    py_bindfunc(mod, "b2Shape_GetFriction", &cfunc__b2Shape_GetFriction);
    py_bindfunc(mod, "b2Shape_SetRestitution", &cfunc__b2Shape_SetRestitution);
    py_bindfunc(mod, "b2Shape_GetRestitution", &cfunc__b2Shape_GetRestitution);
    py_bindfunc(mod, "b2Shape_GetFilter", &cfunc__b2Shape_GetFilter);
    py_bindfunc(mod, "b2Shape_SetFilter", &cfunc__b2Shape_SetFilter);
    py_bindfunc(mod, "b2Shape_EnableSensorEvents", &cfunc__b2Shape_EnableSensorEvents);
    py_bindfunc(mod, "b2Shape_AreSensorEventsEnabled", &cfunc__b2Shape_AreSensorEventsEnabled);
    py_bindfunc(mod, "b2Shape_EnableContactEvents", &cfunc__b2Shape_EnableContactEvents);
    py_bindfunc(mod, "b2Shape_AreContactEventsEnabled", &cfunc__b2Shape_AreContactEventsEnabled);
    py_bindfunc(mod, "b2Shape_EnablePreSolveEvents", &cfunc__b2Shape_EnablePreSolveEvents);
    py_bindfunc(mod, "b2Shape_ArePreSolveEventsEnabled", &cfunc__b2Shape_ArePreSolveEventsEnabled);
    py_bindfunc(mod, "b2Shape_EnableHitEvents", &cfunc__b2Shape_EnableHitEvents);
    py_bindfunc(mod, "b2Shape_AreHitEventsEnabled", &cfunc__b2Shape_AreHitEventsEnabled);
    py_bindfunc(mod, "b2Shape_TestPoint", &cfunc__b2Shape_TestPoint);
    py_bindfunc(mod, "b2Shape_RayCast", &cfunc__b2Shape_RayCast);
    py_bindfunc(mod, "b2Shape_GetCircle", &cfunc__b2Shape_GetCircle);
    py_bindfunc(mod, "b2Shape_GetSegment", &cfunc__b2Shape_GetSegment);
    py_bindfunc(mod, "b2Shape_GetSmoothSegment", &cfunc__b2Shape_GetSmoothSegment);
    py_bindfunc(mod, "b2Shape_GetCapsule", &cfunc__b2Shape_GetCapsule);
    py_bindfunc(mod, "b2Shape_GetPolygon", &cfunc__b2Shape_GetPolygon);
    py_bindfunc(mod, "b2Shape_SetCircle", &cfunc__b2Shape_SetCircle);
    py_bindfunc(mod, "b2Shape_SetCapsule", &cfunc__b2Shape_SetCapsule);
    py_bindfunc(mod, "b2Shape_SetSegment", &cfunc__b2Shape_SetSegment);
    py_bindfunc(mod, "b2Shape_SetPolygon", &cfunc__b2Shape_SetPolygon);
    py_bindfunc(mod, "b2Shape_GetParentChain", &cfunc__b2Shape_GetParentChain);
    py_bindfunc(mod, "b2Shape_GetContactCapacity", &cfunc__b2Shape_GetContactCapacity);
    py_bindfunc(mod, "b2Shape_GetContactData", &cfunc__b2Shape_GetContactData);
    py_bindfunc(mod, "b2Shape_GetAABB", &cfunc__b2Shape_GetAABB);
    py_bindfunc(mod, "b2Shape_GetClosestPoint", &cfunc__b2Shape_GetClosestPoint);
    py_bindfunc(mod, "b2CreateChain", &cfunc__b2CreateChain);
    py_bindfunc(mod, "b2DestroyChain", &cfunc__b2DestroyChain);
    py_bindfunc(mod, "b2Chain_SetFriction", &cfunc__b2Chain_SetFriction);
    py_bindfunc(mod, "b2Chain_SetRestitution", &cfunc__b2Chain_SetRestitution);
    py_bindfunc(mod, "b2Chain_IsValid", &cfunc__b2Chain_IsValid);
    py_bindfunc(mod, "b2DestroyJoint", &cfunc__b2DestroyJoint);
    py_bindfunc(mod, "b2Joint_IsValid", &cfunc__b2Joint_IsValid);
    py_bindfunc(mod, "b2Joint_GetType", &cfunc__b2Joint_GetType);
    py_bindfunc(mod, "b2Joint_GetBodyA", &cfunc__b2Joint_GetBodyA);
    py_bindfunc(mod, "b2Joint_GetBodyB", &cfunc__b2Joint_GetBodyB);
    py_bindfunc(mod, "b2Joint_GetLocalAnchorA", &cfunc__b2Joint_GetLocalAnchorA);
    py_bindfunc(mod, "b2Joint_GetLocalAnchorB", &cfunc__b2Joint_GetLocalAnchorB);
    py_bindfunc(mod, "b2Joint_SetCollideConnected", &cfunc__b2Joint_SetCollideConnected);
    py_bindfunc(mod, "b2Joint_GetCollideConnected", &cfunc__b2Joint_GetCollideConnected);
    py_bindfunc(mod, "b2Joint_SetUserData", &cfunc__b2Joint_SetUserData);
    py_bindfunc(mod, "b2Joint_GetUserData", &cfunc__b2Joint_GetUserData);
    py_bindfunc(mod, "b2Joint_WakeBodies", &cfunc__b2Joint_WakeBodies);
    py_bindfunc(mod, "b2Joint_GetConstraintForce", &cfunc__b2Joint_GetConstraintForce);
    py_bindfunc(mod, "b2Joint_GetConstraintTorque", &cfunc__b2Joint_GetConstraintTorque);
    py_bindfunc(mod, "b2CreateDistanceJoint", &cfunc__b2CreateDistanceJoint);
    py_bindfunc(mod, "b2DistanceJoint_SetLength", &cfunc__b2DistanceJoint_SetLength);
    py_bindfunc(mod, "b2DistanceJoint_GetLength", &cfunc__b2DistanceJoint_GetLength);
    py_bindfunc(mod, "b2DistanceJoint_EnableSpring", &cfunc__b2DistanceJoint_EnableSpring);
    py_bindfunc(mod, "b2DistanceJoint_IsSpringEnabled", &cfunc__b2DistanceJoint_IsSpringEnabled);
    py_bindfunc(mod, "b2DistanceJoint_SetSpringHertz", &cfunc__b2DistanceJoint_SetSpringHertz);
    py_bindfunc(mod, "b2DistanceJoint_SetSpringDampingRatio", &cfunc__b2DistanceJoint_SetSpringDampingRatio);
    py_bindfunc(mod, "b2DistanceJoint_GetSpringHertz", &cfunc__b2DistanceJoint_GetSpringHertz);
    py_bindfunc(mod, "b2DistanceJoint_GetSpringDampingRatio", &cfunc__b2DistanceJoint_GetSpringDampingRatio);
    py_bindfunc(mod, "b2DistanceJoint_EnableLimit", &cfunc__b2DistanceJoint_EnableLimit);
    py_bindfunc(mod, "b2DistanceJoint_IsLimitEnabled", &cfunc__b2DistanceJoint_IsLimitEnabled);
    py_bindfunc(mod, "b2DistanceJoint_SetLengthRange", &cfunc__b2DistanceJoint_SetLengthRange);
    py_bindfunc(mod, "b2DistanceJoint_GetMinLength", &cfunc__b2DistanceJoint_GetMinLength);
    py_bindfunc(mod, "b2DistanceJoint_GetMaxLength", &cfunc__b2DistanceJoint_GetMaxLength);
    py_bindfunc(mod, "b2DistanceJoint_GetCurrentLength", &cfunc__b2DistanceJoint_GetCurrentLength);
    py_bindfunc(mod, "b2DistanceJoint_EnableMotor", &cfunc__b2DistanceJoint_EnableMotor);
    py_bindfunc(mod, "b2DistanceJoint_IsMotorEnabled", &cfunc__b2DistanceJoint_IsMotorEnabled);
    py_bindfunc(mod, "b2DistanceJoint_SetMotorSpeed", &cfunc__b2DistanceJoint_SetMotorSpeed);
    py_bindfunc(mod, "b2DistanceJoint_GetMotorSpeed", &cfunc__b2DistanceJoint_GetMotorSpeed);
    py_bindfunc(mod, "b2DistanceJoint_SetMaxMotorForce", &cfunc__b2DistanceJoint_SetMaxMotorForce);
    py_bindfunc(mod, "b2DistanceJoint_GetMaxMotorForce", &cfunc__b2DistanceJoint_GetMaxMotorForce);
    py_bindfunc(mod, "b2DistanceJoint_GetMotorForce", &cfunc__b2DistanceJoint_GetMotorForce);
    py_bindfunc(mod, "b2CreateMotorJoint", &cfunc__b2CreateMotorJoint);
    py_bindfunc(mod, "b2MotorJoint_SetLinearOffset", &cfunc__b2MotorJoint_SetLinearOffset);
    py_bindfunc(mod, "b2MotorJoint_GetLinearOffset", &cfunc__b2MotorJoint_GetLinearOffset);
    py_bindfunc(mod, "b2MotorJoint_SetAngularOffset", &cfunc__b2MotorJoint_SetAngularOffset);
    py_bindfunc(mod, "b2MotorJoint_GetAngularOffset", &cfunc__b2MotorJoint_GetAngularOffset);
    py_bindfunc(mod, "b2MotorJoint_SetMaxForce", &cfunc__b2MotorJoint_SetMaxForce);
    py_bindfunc(mod, "b2MotorJoint_GetMaxForce", &cfunc__b2MotorJoint_GetMaxForce);
    py_bindfunc(mod, "b2MotorJoint_SetMaxTorque", &cfunc__b2MotorJoint_SetMaxTorque);
    py_bindfunc(mod, "b2MotorJoint_GetMaxTorque", &cfunc__b2MotorJoint_GetMaxTorque);
    py_bindfunc(mod, "b2MotorJoint_SetCorrectionFactor", &cfunc__b2MotorJoint_SetCorrectionFactor);
    py_bindfunc(mod, "b2MotorJoint_GetCorrectionFactor", &cfunc__b2MotorJoint_GetCorrectionFactor);
    py_bindfunc(mod, "b2CreateMouseJoint", &cfunc__b2CreateMouseJoint);
    py_bindfunc(mod, "b2MouseJoint_SetTarget", &cfunc__b2MouseJoint_SetTarget);
    py_bindfunc(mod, "b2MouseJoint_GetTarget", &cfunc__b2MouseJoint_GetTarget);
    py_bindfunc(mod, "b2MouseJoint_SetSpringHertz", &cfunc__b2MouseJoint_SetSpringHertz);
    py_bindfunc(mod, "b2MouseJoint_GetSpringHertz", &cfunc__b2MouseJoint_GetSpringHertz);
    py_bindfunc(mod, "b2MouseJoint_SetSpringDampingRatio", &cfunc__b2MouseJoint_SetSpringDampingRatio);
    py_bindfunc(mod, "b2MouseJoint_GetSpringDampingRatio", &cfunc__b2MouseJoint_GetSpringDampingRatio);
    py_bindfunc(mod, "b2MouseJoint_SetMaxForce", &cfunc__b2MouseJoint_SetMaxForce);
    py_bindfunc(mod, "b2MouseJoint_GetMaxForce", &cfunc__b2MouseJoint_GetMaxForce);
    py_bindfunc(mod, "b2CreatePrismaticJoint", &cfunc__b2CreatePrismaticJoint);
    py_bindfunc(mod, "b2PrismaticJoint_EnableSpring", &cfunc__b2PrismaticJoint_EnableSpring);
    py_bindfunc(mod, "b2PrismaticJoint_IsSpringEnabled", &cfunc__b2PrismaticJoint_IsSpringEnabled);
    py_bindfunc(mod, "b2PrismaticJoint_SetSpringHertz", &cfunc__b2PrismaticJoint_SetSpringHertz);
    py_bindfunc(mod, "b2PrismaticJoint_GetSpringHertz", &cfunc__b2PrismaticJoint_GetSpringHertz);
    py_bindfunc(mod, "b2PrismaticJoint_SetSpringDampingRatio", &cfunc__b2PrismaticJoint_SetSpringDampingRatio);
    py_bindfunc(mod, "b2PrismaticJoint_GetSpringDampingRatio", &cfunc__b2PrismaticJoint_GetSpringDampingRatio);
    py_bindfunc(mod, "b2PrismaticJoint_EnableLimit", &cfunc__b2PrismaticJoint_EnableLimit);
    py_bindfunc(mod, "b2PrismaticJoint_IsLimitEnabled", &cfunc__b2PrismaticJoint_IsLimitEnabled);
    py_bindfunc(mod, "b2PrismaticJoint_GetLowerLimit", &cfunc__b2PrismaticJoint_GetLowerLimit);
    py_bindfunc(mod, "b2PrismaticJoint_GetUpperLimit", &cfunc__b2PrismaticJoint_GetUpperLimit);
    py_bindfunc(mod, "b2PrismaticJoint_SetLimits", &cfunc__b2PrismaticJoint_SetLimits);
    py_bindfunc(mod, "b2PrismaticJoint_EnableMotor", &cfunc__b2PrismaticJoint_EnableMotor);
    py_bindfunc(mod, "b2PrismaticJoint_IsMotorEnabled", &cfunc__b2PrismaticJoint_IsMotorEnabled);
    py_bindfunc(mod, "b2PrismaticJoint_SetMotorSpeed", &cfunc__b2PrismaticJoint_SetMotorSpeed);
    py_bindfunc(mod, "b2PrismaticJoint_GetMotorSpeed", &cfunc__b2PrismaticJoint_GetMotorSpeed);
    py_bindfunc(mod, "b2PrismaticJoint_SetMaxMotorForce", &cfunc__b2PrismaticJoint_SetMaxMotorForce);
    py_bindfunc(mod, "b2PrismaticJoint_GetMaxMotorForce", &cfunc__b2PrismaticJoint_GetMaxMotorForce);
    py_bindfunc(mod, "b2PrismaticJoint_GetMotorForce", &cfunc__b2PrismaticJoint_GetMotorForce);
    py_bindfunc(mod, "b2CreateRevoluteJoint", &cfunc__b2CreateRevoluteJoint);
    py_bindfunc(mod, "b2RevoluteJoint_EnableSpring", &cfunc__b2RevoluteJoint_EnableSpring);
    py_bindfunc(mod, "b2RevoluteJoint_IsSpringEnabled", &cfunc__b2RevoluteJoint_IsSpringEnabled);
    py_bindfunc(mod, "b2RevoluteJoint_SetSpringHertz", &cfunc__b2RevoluteJoint_SetSpringHertz);
    py_bindfunc(mod, "b2RevoluteJoint_GetSpringHertz", &cfunc__b2RevoluteJoint_GetSpringHertz);
    py_bindfunc(mod, "b2RevoluteJoint_SetSpringDampingRatio", &cfunc__b2RevoluteJoint_SetSpringDampingRatio);
    py_bindfunc(mod, "b2RevoluteJoint_GetSpringDampingRatio", &cfunc__b2RevoluteJoint_GetSpringDampingRatio);
    py_bindfunc(mod, "b2RevoluteJoint_GetAngle", &cfunc__b2RevoluteJoint_GetAngle);
    py_bindfunc(mod, "b2RevoluteJoint_EnableLimit", &cfunc__b2RevoluteJoint_EnableLimit);
    py_bindfunc(mod, "b2RevoluteJoint_IsLimitEnabled", &cfunc__b2RevoluteJoint_IsLimitEnabled);
    py_bindfunc(mod, "b2RevoluteJoint_GetLowerLimit", &cfunc__b2RevoluteJoint_GetLowerLimit);
    py_bindfunc(mod, "b2RevoluteJoint_GetUpperLimit", &cfunc__b2RevoluteJoint_GetUpperLimit);
    py_bindfunc(mod, "b2RevoluteJoint_SetLimits", &cfunc__b2RevoluteJoint_SetLimits);
    py_bindfunc(mod, "b2RevoluteJoint_EnableMotor", &cfunc__b2RevoluteJoint_EnableMotor);
    py_bindfunc(mod, "b2RevoluteJoint_IsMotorEnabled", &cfunc__b2RevoluteJoint_IsMotorEnabled);
    py_bindfunc(mod, "b2RevoluteJoint_SetMotorSpeed", &cfunc__b2RevoluteJoint_SetMotorSpeed);
    py_bindfunc(mod, "b2RevoluteJoint_GetMotorSpeed", &cfunc__b2RevoluteJoint_GetMotorSpeed);
    py_bindfunc(mod, "b2RevoluteJoint_GetMotorTorque", &cfunc__b2RevoluteJoint_GetMotorTorque);
    py_bindfunc(mod, "b2RevoluteJoint_SetMaxMotorTorque", &cfunc__b2RevoluteJoint_SetMaxMotorTorque);
    py_bindfunc(mod, "b2RevoluteJoint_GetMaxMotorTorque", &cfunc__b2RevoluteJoint_GetMaxMotorTorque);
    py_bindfunc(mod, "b2CreateWeldJoint", &cfunc__b2CreateWeldJoint);
    py_bindfunc(mod, "b2WeldJoint_SetLinearHertz", &cfunc__b2WeldJoint_SetLinearHertz);
    py_bindfunc(mod, "b2WeldJoint_GetLinearHertz", &cfunc__b2WeldJoint_GetLinearHertz);
    py_bindfunc(mod, "b2WeldJoint_SetLinearDampingRatio", &cfunc__b2WeldJoint_SetLinearDampingRatio);
    py_bindfunc(mod, "b2WeldJoint_GetLinearDampingRatio", &cfunc__b2WeldJoint_GetLinearDampingRatio);
    py_bindfunc(mod, "b2WeldJoint_SetAngularHertz", &cfunc__b2WeldJoint_SetAngularHertz);
    py_bindfunc(mod, "b2WeldJoint_GetAngularHertz", &cfunc__b2WeldJoint_GetAngularHertz);
    py_bindfunc(mod, "b2WeldJoint_SetAngularDampingRatio", &cfunc__b2WeldJoint_SetAngularDampingRatio);
    py_bindfunc(mod, "b2WeldJoint_GetAngularDampingRatio", &cfunc__b2WeldJoint_GetAngularDampingRatio);
    py_bindfunc(mod, "b2CreateWheelJoint", &cfunc__b2CreateWheelJoint);
    py_bindfunc(mod, "b2WheelJoint_EnableSpring", &cfunc__b2WheelJoint_EnableSpring);
    py_bindfunc(mod, "b2WheelJoint_IsSpringEnabled", &cfunc__b2WheelJoint_IsSpringEnabled);
    py_bindfunc(mod, "b2WheelJoint_SetSpringHertz", &cfunc__b2WheelJoint_SetSpringHertz);
    py_bindfunc(mod, "b2WheelJoint_GetSpringHertz", &cfunc__b2WheelJoint_GetSpringHertz);
    py_bindfunc(mod, "b2WheelJoint_SetSpringDampingRatio", &cfunc__b2WheelJoint_SetSpringDampingRatio);
    py_bindfunc(mod, "b2WheelJoint_GetSpringDampingRatio", &cfunc__b2WheelJoint_GetSpringDampingRatio);
    py_bindfunc(mod, "b2WheelJoint_EnableLimit", &cfunc__b2WheelJoint_EnableLimit);
    py_bindfunc(mod, "b2WheelJoint_IsLimitEnabled", &cfunc__b2WheelJoint_IsLimitEnabled);
    py_bindfunc(mod, "b2WheelJoint_GetLowerLimit", &cfunc__b2WheelJoint_GetLowerLimit);
    py_bindfunc(mod, "b2WheelJoint_GetUpperLimit", &cfunc__b2WheelJoint_GetUpperLimit);
    py_bindfunc(mod, "b2WheelJoint_SetLimits", &cfunc__b2WheelJoint_SetLimits);
    py_bindfunc(mod, "b2WheelJoint_EnableMotor", &cfunc__b2WheelJoint_EnableMotor);
    py_bindfunc(mod, "b2WheelJoint_IsMotorEnabled", &cfunc__b2WheelJoint_IsMotorEnabled);
    py_bindfunc(mod, "b2WheelJoint_SetMotorSpeed", &cfunc__b2WheelJoint_SetMotorSpeed);
    py_bindfunc(mod, "b2WheelJoint_GetMotorSpeed", &cfunc__b2WheelJoint_GetMotorSpeed);
    py_bindfunc(mod, "b2WheelJoint_SetMaxMotorTorque", &cfunc__b2WheelJoint_SetMaxMotorTorque);
    py_bindfunc(mod, "b2WheelJoint_GetMaxMotorTorque", &cfunc__b2WheelJoint_GetMaxMotorTorque);
    py_bindfunc(mod, "b2WheelJoint_GetMotorTorque", &cfunc__b2WheelJoint_GetMotorTorque);
    /* enums */
    ADD_ENUM(b2_toiStateUnknown);
    ADD_ENUM(b2_toiStateFailed);
    ADD_ENUM(b2_toiStateOverlapped);
    ADD_ENUM(b2_toiStateHit);
    ADD_ENUM(b2_toiStateSeparated);
    ADD_ENUM(b2_staticBody);
    ADD_ENUM(b2_kinematicBody);
    ADD_ENUM(b2_dynamicBody);
    ADD_ENUM(b2_bodyTypeCount);
    ADD_ENUM(b2_circleShape);
    ADD_ENUM(b2_capsuleShape);
    ADD_ENUM(b2_segmentShape);
    ADD_ENUM(b2_polygonShape);
    ADD_ENUM(b2_smoothSegmentShape);
    ADD_ENUM(b2_shapeTypeCount);
    ADD_ENUM(b2_distanceJoint);
    ADD_ENUM(b2_motorJoint);
    ADD_ENUM(b2_mouseJoint);
    ADD_ENUM(b2_prismaticJoint);
    ADD_ENUM(b2_revoluteJoint);
    ADD_ENUM(b2_weldJoint);
    ADD_ENUM(b2_wheelJoint);
    ADD_ENUM(b2_colorAliceBlue);
    ADD_ENUM(b2_colorAntiqueWhite);
    ADD_ENUM(b2_colorAquamarine);
    ADD_ENUM(b2_colorAzure);
    ADD_ENUM(b2_colorBeige);
    ADD_ENUM(b2_colorBisque);
    ADD_ENUM(b2_colorBlack);
    ADD_ENUM(b2_colorBlanchedAlmond);
    ADD_ENUM(b2_colorBlue);
    ADD_ENUM(b2_colorBlueViolet);
    ADD_ENUM(b2_colorBrown);
    ADD_ENUM(b2_colorBurlywood);
    ADD_ENUM(b2_colorCadetBlue);
    ADD_ENUM(b2_colorChartreuse);
    ADD_ENUM(b2_colorChocolate);
    ADD_ENUM(b2_colorCoral);
    ADD_ENUM(b2_colorCornflowerBlue);
    ADD_ENUM(b2_colorCornsilk);
    ADD_ENUM(b2_colorCrimson);
    ADD_ENUM(b2_colorCyan);
    ADD_ENUM(b2_colorDarkBlue);
    ADD_ENUM(b2_colorDarkCyan);
    ADD_ENUM(b2_colorDarkGoldenrod);
    ADD_ENUM(b2_colorDarkGray);
    ADD_ENUM(b2_colorDarkGreen);
    ADD_ENUM(b2_colorDarkKhaki);
    ADD_ENUM(b2_colorDarkMagenta);
    ADD_ENUM(b2_colorDarkOliveGreen);
    ADD_ENUM(b2_colorDarkOrange);
    ADD_ENUM(b2_colorDarkOrchid);
    ADD_ENUM(b2_colorDarkRed);
    ADD_ENUM(b2_colorDarkSalmon);
    ADD_ENUM(b2_colorDarkSeaGreen);
    ADD_ENUM(b2_colorDarkSlateBlue);
    ADD_ENUM(b2_colorDarkSlateGray);
    ADD_ENUM(b2_colorDarkTurquoise);
    ADD_ENUM(b2_colorDarkViolet);
    ADD_ENUM(b2_colorDeepPink);
    ADD_ENUM(b2_colorDeepSkyBlue);
    ADD_ENUM(b2_colorDimGray);
    ADD_ENUM(b2_colorDodgerBlue);
    ADD_ENUM(b2_colorFirebrick);
    ADD_ENUM(b2_colorFloralWhite);
    ADD_ENUM(b2_colorForestGreen);
    ADD_ENUM(b2_colorGainsboro);
    ADD_ENUM(b2_colorGhostWhite);
    ADD_ENUM(b2_colorGold);
    ADD_ENUM(b2_colorGoldenrod);
    ADD_ENUM(b2_colorGray);
    ADD_ENUM(b2_colorGray1);
    ADD_ENUM(b2_colorGray2);
    ADD_ENUM(b2_colorGray3);
    ADD_ENUM(b2_colorGray4);
    ADD_ENUM(b2_colorGray5);
    ADD_ENUM(b2_colorGray6);
    ADD_ENUM(b2_colorGray7);
    ADD_ENUM(b2_colorGray8);
    ADD_ENUM(b2_colorGray9);
    ADD_ENUM(b2_colorGreen);
    ADD_ENUM(b2_colorGreenYellow);
    ADD_ENUM(b2_colorHoneydew);
    ADD_ENUM(b2_colorHotPink);
    ADD_ENUM(b2_colorIndianRed);
    ADD_ENUM(b2_colorIndigo);
    ADD_ENUM(b2_colorIvory);
    ADD_ENUM(b2_colorKhaki);
    ADD_ENUM(b2_colorLavender);
    ADD_ENUM(b2_colorLavenderBlush);
    ADD_ENUM(b2_colorLawnGreen);
    ADD_ENUM(b2_colorLemonChiffon);
    ADD_ENUM(b2_colorLightBlue);
    ADD_ENUM(b2_colorLightCoral);
    ADD_ENUM(b2_colorLightCyan);
    ADD_ENUM(b2_colorLightGoldenrod);
    ADD_ENUM(b2_colorLightGoldenrodYellow);
    ADD_ENUM(b2_colorLightGray);
    ADD_ENUM(b2_colorLightGreen);
    ADD_ENUM(b2_colorLightPink);
    ADD_ENUM(b2_colorLightSalmon);
    ADD_ENUM(b2_colorLightSeaGreen);
    ADD_ENUM(b2_colorLightSkyBlue);
    ADD_ENUM(b2_colorLightSlateBlue);
    ADD_ENUM(b2_colorLightSlateGray);
    ADD_ENUM(b2_colorLightSteelBlue);
    ADD_ENUM(b2_colorLightYellow);
    ADD_ENUM(b2_colorLimeGreen);
    ADD_ENUM(b2_colorLinen);
    ADD_ENUM(b2_colorMagenta);
    ADD_ENUM(b2_colorMaroon);
    ADD_ENUM(b2_colorMediumAquamarine);
    ADD_ENUM(b2_colorMediumBlue);
    ADD_ENUM(b2_colorMediumOrchid);
    ADD_ENUM(b2_colorMediumPurple);
    ADD_ENUM(b2_colorMediumSeaGreen);
    ADD_ENUM(b2_colorMediumSlateBlue);
    ADD_ENUM(b2_colorMediumSpringGreen);
    ADD_ENUM(b2_colorMediumTurquoise);
    ADD_ENUM(b2_colorMediumVioletRed);
    ADD_ENUM(b2_colorMidnightBlue);
    ADD_ENUM(b2_colorMintCream);
    ADD_ENUM(b2_colorMistyRose);
    ADD_ENUM(b2_colorMoccasin);
    ADD_ENUM(b2_colorNavajoWhite);
    ADD_ENUM(b2_colorNavyBlue);
    ADD_ENUM(b2_colorOldLace);
    ADD_ENUM(b2_colorOlive);
    ADD_ENUM(b2_colorOliveDrab);
    ADD_ENUM(b2_colorOrange);
    ADD_ENUM(b2_colorOrangeRed);
    ADD_ENUM(b2_colorOrchid);
    ADD_ENUM(b2_colorPaleGoldenrod);
    ADD_ENUM(b2_colorPaleGreen);
    ADD_ENUM(b2_colorPaleTurquoise);
    ADD_ENUM(b2_colorPaleVioletRed);
    ADD_ENUM(b2_colorPapayaWhip);
    ADD_ENUM(b2_colorPeachPuff);
    ADD_ENUM(b2_colorPeru);
    ADD_ENUM(b2_colorPink);
    ADD_ENUM(b2_colorPlum);
    ADD_ENUM(b2_colorPowderBlue);
    ADD_ENUM(b2_colorPurple);
    ADD_ENUM(b2_colorRebeccaPurple);
    ADD_ENUM(b2_colorRed);
    ADD_ENUM(b2_colorRosyBrown);
    ADD_ENUM(b2_colorRoyalBlue);
    ADD_ENUM(b2_colorSaddleBrown);
    ADD_ENUM(b2_colorSalmon);
    ADD_ENUM(b2_colorSandyBrown);
    ADD_ENUM(b2_colorSeaGreen);
    ADD_ENUM(b2_colorSeashell);
    ADD_ENUM(b2_colorSienna);
    ADD_ENUM(b2_colorSilver);
    ADD_ENUM(b2_colorSkyBlue);
    ADD_ENUM(b2_colorSlateBlue);
    ADD_ENUM(b2_colorSlateGray);
    ADD_ENUM(b2_colorSnow);
    ADD_ENUM(b2_colorSpringGreen);
    ADD_ENUM(b2_colorSteelBlue);
    ADD_ENUM(b2_colorTan);
    ADD_ENUM(b2_colorTeal);
    ADD_ENUM(b2_colorThistle);
    ADD_ENUM(b2_colorTomato);
    ADD_ENUM(b2_colorTurquoise);
    ADD_ENUM(b2_colorViolet);
    ADD_ENUM(b2_colorVioletRed);
    ADD_ENUM(b2_colorWheat);
    ADD_ENUM(b2_colorWhite);
    ADD_ENUM(b2_colorWhiteSmoke);
    ADD_ENUM(b2_colorYellow);
    ADD_ENUM(b2_colorYellowGreen);
    ADD_ENUM(b2_colorBox2DRed);
    ADD_ENUM(b2_colorBox2DBlue);
    ADD_ENUM(b2_colorBox2DGreen);
    ADD_ENUM(b2_colorBox2DYellow);
}