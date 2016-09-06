#include <Python.h>

#include "hashBomb.h"

static PyObject *hashBomb_getpowhash(PyObject *self, PyObject *args)
{
    char *output;
    PyObject *value;
#if PY_MAJOR_VERSION >= 3
    PyBytesObject *input;
#else
    PyStringObject *input;
#endif
    if (!PyArg_ParseTuple(args, "S", &input))
        return NULL;
    Py_INCREF(input);
    output = PyMem_Malloc(256);

#if PY_MAJOR_VERSION >= 3
    hashBomb_2048((char *)PyBytes_AsString((PyObject*) input), output);
#else
    hashBomb_2048((char *)PyString_AsString((PyObject*) input), output);
#endif
    Py_DECREF(input);
#if PY_MAJOR_VERSION >= 3
    value = Py_BuildValue("y#", output, 256);
#else
    value = Py_BuildValue("s#", output, 256);
#endif
    PyMem_Free(output);
    return value;
}

static PyMethodDef HashBombMethods[] = {
    { "getPoWHash", hashBomb_getpowhash, METH_VARARGS, "Returns the proof of work hash" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef HashBombModule = {
    PyModuleDef_HEAD_INIT,
    "hashBomb_2048",
    "...",
    -1,
    HashBombMethods
};

PyMODINIT_FUNC PyInit_nist5_hash(void) {
    return PyModule_Create(&HashBombModule);
}

#else

PyMODINIT_FUNC initnist5_hash(void) {
    (void) Py_InitModule("hashBomb_2048", HashBombMethods);
}
#endif