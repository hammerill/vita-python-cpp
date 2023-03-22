#include <python2.7/Python.h>

int main()
{
	Py_Initialize();

	PyRun_SimpleString("import os");
	PyRun_SimpleString("os.system('clear')");

	return 0;
}
