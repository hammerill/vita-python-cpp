#include <python2.7/Python.h>

int main(int argc, char *argv[])
{
	// Py_SetProgramName((char*)"app0:eboot.bin");
	Py_Initialize();

	// FILE *fp;
    // fp = fopen("app0:main.py", "r");
    // PyRun_SimpleFile(fp, "main.py");

	PyRun_SimpleString("text_file = open('ux0:data/sample.txt', 'w')\n");
	PyRun_SimpleString("n = text_file.write('Hola ot balabola.')\n");
	PyRun_SimpleString("text_file.close()\n");

	Py_Finalize();
	return 0;
}
