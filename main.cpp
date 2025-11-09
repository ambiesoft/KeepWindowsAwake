#include <windows.h>
#include <string>

#include "../lsMisc/CommandLineParser.h"
#include "../lsMisc/stdosd/stdosd.h"

#define APP_NAME L"KeepsAwake"
#define APP_VERSION L"1.0.0"

#define I18N(x) x

#define DEFAULT_TIMEOUT_SECONDS 300

#pragma comment(lib, "shlwapi.lib")

using namespace Ambiesoft;
using namespace Ambiesoft::stdosd;

int APIENTRY WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nShowCmd)
{
	CCommandLineParserW parser(I18N(L"Keeps Windows Awake"), APP_NAME);

	int nTimeout = -1;
	parser.AddOption(
		{ L"--timeout", L"-t" },
		ArgCount::ArgCount_One,
		& nTimeout,
		ArgEncodingFlags_Default,
		stdFormat(I18N(L"Set timeout in seconds (default: %d)"), DEFAULT_TIMEOUT_SECONDS));

	bool bHelp = false;
	parser.AddOption(
		{ L"--help", L"-h", L"/?", L"/h" },
		ArgCount::ArgCount_Zero,
		& bHelp,
		ArgEncodingFlags_Default,
		I18N(L"Show help information"));

	parser.Parse();

	if(parser.hadUnknownOption())
	{
		std::wstring unknowns;
		unknowns = stdFormat(I18N(L"Unknown option: %s\n"), parser.getFirstUnknowOptionString().c_str());
		
		MessageBoxW(NULL,
			unknowns.c_str(),
			APP_NAME L" v" APP_VERSION,
			MB_ICONERROR);
		return 1;
	}

	if(bHelp)
	{
		MessageBoxW(NULL, 
			parser.getHelpMessage().c_str(),
			APP_NAME L" v" APP_VERSION,
			MB_ICONINFORMATION);
		return 0;
	}

	if (nTimeout == -1)
		nTimeout = DEFAULT_TIMEOUT_SECONDS;
	if(nTimeout <=0 )
	{
		MessageBoxW(NULL, I18N(L"Timeout must be positive integer."), APP_NAME, MB_ICONERROR);
		return 1;
	}

	// Prevent the system from entering sleep mode
	SetThreadExecutionState(ES_CONTINUOUS | ES_SYSTEM_REQUIRED);
	
	Sleep(nTimeout * 1000);
	
	SetThreadExecutionState(ES_CONTINUOUS);
	return 0;
}
