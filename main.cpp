#include <windows.h>

int APIENTRY WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nShowCmd)
{
	// Prevent the system from entering sleep mode
	SetThreadExecutionState(ES_CONTINUOUS | ES_SYSTEM_REQUIRED | ES_DISPLAY_REQUIRED);
	
	// Keep the application in 5 minuites
	Sleep(5 * 60 * 1000);
	
	return 0;
}
