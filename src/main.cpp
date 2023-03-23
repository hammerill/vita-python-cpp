#include <python2.7/Python.h>

int main(int argc, char *argv[])
{
	Py_NoSiteFlag = 1;
	Py_IgnoreEnvironmentFlag = 1;
	Py_NoUserSiteDirectory = 1;

	Py_SetProgramName((char*)"app0:eboot.bin");
	Py_InitializeEx(1);
	PySys_SetPath((char*)"app0:lib/python27.zip;app0:lib/python2.7;ux0:/data/lib/python27.zip;ux0:/data/lib/python2.7");

	FILE *fp;
    fp = fopen("app0:main.py", "r");
    PyRun_SimpleFile(fp, "main.py");

	Py_Finalize();
	return 0;
}
