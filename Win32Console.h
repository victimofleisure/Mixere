// Copyleft 2004 Chris Korda
// This program is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by the Free
// Software Foundation; either version 2 of the License, or any later version.
/*
		chris korda

		rev		date		comments
		00		31jul04		initial version

		Create a Win32 console and redirect standard I/O to it

*/

#ifndef WIN32_CONSOLE_INCLUDED
#define WIN32_CONSOLE_INCLUDED

// The Win32Console object creates a Win32 console and redirects standard I/O
// to it.  This allows a GUI application or DLL to use standard I/O functions
// such as printf and scanf.  The console's screen buffer size can also be
// changed if desired.  All the member functions are static, so there's no need
// to create an instance of this object.  Only the Create function is required.
//
class Win32Console {
public:
//
// Creates a Win32 console and redirects standard I/O to it.
//
// Remarks: Create can be called at any time, but it's usually best to call it
// from the application's InitInstance function, or the DLL's DllMain function.
// Note that if Create succeeds, all standard I/O works: the C file API and the
// C++ streams API, and not only output, but also input, including conio.h
// functions such as getch and kbhit.
//
// Returns: True if successful.
//
	static	bool	Create();
//
// Changes the size of the Win32 console's screen buffer.
//
// Remarks: If the default screen buffer size (typically 80 columns by 300
// rows) is acceptable, there's no need to call this function.
//
// The specified width and height cannot be less than the width and height of
// the screen buffer's window.  The specified dimensions also cannot be less
// than the minimum size allowed by the system.  This minimum depends on the
// current font size for the console (selected by the user) and the SM_CXMIN
// and SM_CYMIN values returned by the GetSystemMetrics function.
//
// Returns: True if successful.
//
	static	bool	SetScreenBufferSize(
		int		Cols,		// The desired number of columns.
		int		Rows		// The desired number of rows.
	);
//
// Determines whether the Win32 console was created.
//
// Returns: True if the console was created.
//
	static	bool	IsOpen();

private:
	static	bool	m_IsOpen;	// True if the console was created.

// Redirects an I/O handle to a standard file stream.
//
// Returns: True if successful.
//
	static	bool	Redirect(
		HANDLE	Handle,		// The I/O handle to redirect.
		FILE	*File,		// Receives the file stream.
		LPCSTR	Mode		// The file mode to set.
	);
};

inline bool	Win32Console::IsOpen()
{
	return(m_IsOpen);
}

#endif
