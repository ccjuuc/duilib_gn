#ifndef _VERSIONHELPERS_H_INCLUDED_
#define _VERSIONHELPERS_H_INCLUDED_
#include <specstrings.h>

namespace DuiLib 
{
#define _WIN32_WINNT_NT4                    0x0400
#define _WIN32_WINNT_WIN2K                  0x0500
#define _WIN32_WINNT_WINXP                  0x0501
#define _WIN32_WINNT_WS03                   0x0502
#define _WIN32_WINNT_WIN6                   0x0600
#define _WIN32_WINNT_VISTA                  0x0600
#define _WIN32_WINNT_WS08                   0x0600
#define _WIN32_WINNT_LONGHORN               0x0600
#define _WIN32_WINNT_WIN7                   0x0601
#define _WIN32_WINNT_WIN8                   0x0602
#define _WIN32_WINNT_WINBLUE                0x0603
#define _WIN32_WINNT_WINTHRESHOLD           0x0A00 /* ABRACADABRA_THRESHOLD*/
#define _WIN32_WINNT_WIN10                  0x0A00 /* ABRACADABRA_THRESHOLD*/

	#define WM_DPICHANGED                   0x02E0

	 BOOL IsWindowsVersionOrGreater(WORD wMajorVersion, WORD wMinorVersion, WORD wServicePackMajor);

	 BOOL IsWindowsXPOrGreater();

	 BOOL IsWindowsXPSP1OrGreater();

	 BOOL IsWindowsXPSP2OrGreater();

	 BOOL IsWindowsXPSP3OrGreater();

	 BOOL IsWindowsVistaOrGreater();

	 BOOL IsWindowsVistaSP1OrGreater();

	 BOOL IsWindowsVistaSP2OrGreater();

	 BOOL IsWindows7OrGreater();

	 BOOL IsWindows7SP1OrGreater();

	 BOOL IsWindows8OrGreater();

	 BOOL IsWindows8Point1OrGreater();

	 BOOL IsWindowsThresholdOrGreater();

	 BOOL IsWindows10OrGreater();

	 BOOL IsWindowsServer();
}
#endif // _VERSIONHELPERS_H_INCLUDED_
