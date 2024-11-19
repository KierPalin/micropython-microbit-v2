//This is a tester module to test if it works
//Remove before finishing the project

#include "py/builtin.h"
#include "py/runtime.h"
#include "py/stream.h"
#include "py/objstr.h"


#if MICROPY_PY_SUBSYSTEM

// info()
static mp_obj_t py_subsystem_info(void) {
    mp_obj_t open_args[2] = {
        mp_obj_new_str("hello.txt", strlen("hello.txt")), // filename
        MP_OBJ_NEW_QSTR(MP_QSTR_rb)                       // read binary
    };
    // Obtaining the file descriptor
    mp_obj_t hello_f_descriptor = mp_builtin_open(2, open_args, (mp_map_t *)&mp_const_empty_map);

    // Creating a variable string to contain the file data (even if its binary)
    size_t sz = 1024;
    vstr_t vstr;
    vstr_init(&vstr, sz);

    // Reading the file with the stream module
    int error;
    mp_uint_t out_sz = mp_stream_read_exactly(hello_f_descriptor, vstr.buf, sz, &error);
    vstr.len = out_sz;

    // Check for errors reading the file
    if (error != 0) {
        if (mp_is_nonblocking_error(error)) {
            return mp_const_none;
        }
        mp_raise_OSError(error);
    } else {
        // Return the content as a Python bytes object
        // return mp_obj_new_bytes_from_vstr(&vstr);

        // return a comma separated list of strings: "file,text".split(",")
        VSTR_FIXED(sep, 2);
        vstr_add_str(&sep, ",");
        const mp_obj_t args[2] = {
            mp_obj_new_str_from_vstr(&vstr),
            mp_obj_new_str_from_vstr(&sep)
        };
        mp_obj_t list = mp_obj_str_split(2 , args);
        return list;
    }
}
MP_DEFINE_CONST_FUN_OBJ_0(subsystem_info_obj, py_subsystem_info);

static const mp_rom_map_elem_t mp_module_subsystem_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_subsystem) },
    { MP_ROM_QSTR(MP_QSTR_info), MP_ROM_PTR(&subsystem_info_obj) },
};
static MP_DEFINE_CONST_DICT(mp_module_subsystem_globals, mp_module_subsystem_globals_table);

const mp_obj_module_t mp_module_subsystem = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&mp_module_subsystem_globals,
};

MP_REGISTER_MODULE(MP_QSTR_subsystem, mp_module_subsystem);

#endif