
#define _CRTDBG_MAP_ALLOC       // for detecting memory leaks
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <iostream>
#include <stdlib.h>             // for detecting memory leaks
#include <crtdbg.h>             // for detecting memory leaks
#include <Mmsystem.h>
#include "constants.h"
#include "context.h"
#include "core/math.h"
#include "core/sprites/animatedSprite.h"
#include "game/data/food.h"

// Function prototypes
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int);
bool CreateMainWindow(HWND &, HINSTANCE, int);
LRESULT WINAPI WinProc(HWND, UINT, WPARAM, LPARAM);

HWND hwnd = NULL;

//=============================================================================
// Starting point for a Windows application
//=============================================================================
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
#if defined(DEBUG) | defined(_DEBUG)
	// Check for memory leak if debug build.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// Attach to console for debugging.
	AllocConsole();
	AttachConsole(GetCurrentProcessId());
	freopen("CON", "w", stdout);
#endif

	// Try creating a window.
	if (!CreateMainWindow(hwnd, hInstance, nCmdShow)) {
		return 1;
	}

	// Initialize application context.
	Context::Initialize();

	// Initialize graphics.
	Context::Get()->GetGraphicsRenderer()->Initialize(hwnd, GAME_WIDTH, GAME_HEIGHT, FULLSCREEN);
	
	// Initialize game.
	Context::Get()->GetGame()->Initialize();

	// Main message loop.
	MSG msg;
	int done = 0;
	while (!done)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			// look for quit message
			if (msg.message == WM_QUIT)
				done = 1;

			// decode and pass messages on to WinProc
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			// Run game.
			Context::Get()->GetGame()->Run();
		}
	}

	Context::Get()->ReleaseAll();

	return msg.wParam;
}

//=============================================================================
// window event callback function
//=============================================================================
LRESULT WINAPI WinProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	// Let input manager process any input messages.
	if (
		Context::Get() != nullptr && 
		Context::Get()->GetInputManager()->ProccessKeyMessage(msg, wParam)
	)
	{
		return 0;
	}

	// Let Windows handle it instead.
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

//=============================================================================
// Create the window
// Returns: false on error
//=============================================================================
bool CreateMainWindow(HWND &hwnd, HINSTANCE hInstance, int nCmdShow)
{
	WNDCLASSEX wcx;

	// Fill in the window class structure with parameters 
	// that describe the main window. 
	wcx.cbSize = sizeof(wcx);           // size of structure 
	wcx.style = CS_HREDRAW | CS_VREDRAW;    // redraw if size changes 
	wcx.lpfnWndProc = WinProc;          // points to window procedure 
	wcx.cbClsExtra = 0;                 // no extra class memory 
	wcx.cbWndExtra = 0;                 // no extra window memory 
	wcx.hInstance = hInstance;          // handle to instance 
	wcx.hIcon = NULL;
	wcx.hCursor = LoadCursor(NULL, IDC_ARROW);   // predefined arrow 
	wcx.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);    // black background 
	wcx.lpszMenuName = NULL;           // name of menu resource 
	wcx.lpszClassName = CLASS_NAME;     // name of window class 
	wcx.hIconSm = NULL;                 // small class icon 

	// Register the window class. 
	// RegisterClassEx returns 0 on error.
	if (RegisterClassEx(&wcx) == 0)    // if error
		return false;

	//set up the screen in windowed or fullscreen mode?
	DWORD style;
	if (FULLSCREEN)
		style = WS_EX_TOPMOST | WS_VISIBLE | WS_POPUP;
	else
		style = WS_OVERLAPPEDWINDOW;

	// Create window
	hwnd = CreateWindow(
		CLASS_NAME,             // name of the window class
		GAME_TITLE,             // title bar text
		style,                  // window style
		CW_USEDEFAULT,          // default horizontal position of window
		CW_USEDEFAULT,          // default vertical position of window
		GAME_WIDTH,             // width of window
		GAME_HEIGHT,            // height of the window
		(HWND)NULL,            // no parent window
		(HMENU)NULL,           // no menu
		hInstance,              // handle to application instance
		(LPVOID)NULL);         // no window parameters

	// if there was an error creating the window
	if (!hwnd)
		return false;

	if (!FULLSCREEN)             // if window
	{
		// Adjust window size so client area is GAME_WIDTH x GAME_HEIGHT
		RECT clientRect;
		GetClientRect(hwnd, &clientRect);   // get size of client area of window
		MoveWindow(
			hwnd,
			0,												// Left
			0,												// Top
			GAME_WIDTH + (GAME_WIDTH - clientRect.right),		// Right
			GAME_HEIGHT + (GAME_HEIGHT - clientRect.bottom),	// Bottom
			TRUE											// Repaint the window
		);
	}

	// Show the window
	ShowWindow(hwnd, nCmdShow);

	return true;
}
