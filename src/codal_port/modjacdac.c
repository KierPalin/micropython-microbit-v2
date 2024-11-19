//This is a tester module to test if it works
//Remove before finishing the project

#include "py/builtin.h"
#include "py/runtime.h"
#include "py/stream.h"
#include "py/objstr.h"
#include "py/qstr.h"


#if MICROPY_PY_JACDAC


// test()
static mp_obj_t py_jacdac_test(void) {
    mp_printf(&mp_plat_print, "Hello :)\n");
    return mp_const_none;

    // // Create a Python string from a C string:
    // const char *str = "Howdy :)";
    // return mp_obj_new_str(str, strlen(str));  // Make a Python string

    // mp_obj_t bytes = mp_obj_new_bytes((const byte *)"Hello bytes!", 13);
    // return bytes;

    // mp_obj_t number = mp_obj_new_int(42);
    // return number;
}

MP_DEFINE_CONST_FUN_OBJ_0(jacdac_test_obj, py_jacdac_test);

static const mp_rom_map_elem_t mp_module_jacdac_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_jacdac) },
    { MP_ROM_QSTR(MP_QSTR_test), MP_ROM_PTR(&jacdac_test_obj) },
};
static MP_DEFINE_CONST_DICT(mp_module_jacdac_globals, mp_module_jacdac_globals_table);

const mp_obj_module_t mp_module_jacdac = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&mp_module_jacdac_globals,
};

MP_REGISTER_MODULE(MP_QSTR_jacdac, mp_module_jacdac);

#endif