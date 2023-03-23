#include <python2.7/Python.h>

int main(int argc, char *argv[])
{
	Py_NoSiteFlag = 1;
	Py_IgnoreEnvironmentFlag = 1;
	Py_NoUserSiteDirectory = 1;

	Py_SetProgramName((char*)"app0:eboot.bin");
	Py_InitializeEx(0);
	PySys_SetPath((char*)"app0:lib/python27.zip;app0:lib/python2.7;ux0:/data/lib/python27.zip;ux0:/data/lib/python2.7");

	FILE *fp_ytdl;
    fp_ytdl = fopen("app0:ytdl.py", "r");
    PyRun_SimpleFile(fp_ytdl, "ytdl.py");

	FILE *fp_main;
    fp_main = fopen("app0:main.py", "r");
    PyRun_SimpleFile(fp_main, "main.py");

	Py_Finalize();
	return 0;
}
