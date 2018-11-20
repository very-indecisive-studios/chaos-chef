#pragma once

#include <windows.h>
#include <WindowsX.h>
#include <string>
#include <XInput.h>

namespace core {
	const int KEYS_ARRAY_LEN = 256;     // size of key arrays

   // what values for clear(), bit flag
	const UCHAR KEYS_DOWN = 1;
	const UCHAR KEYS_PRESSED = 2;
	const UCHAR TEXT_IN = 8;
	const UCHAR KEYS_TEXT = KEYS_DOWN + KEYS_PRESSED + TEXT_IN;

	class InputManager {
	private:
		bool keysDown[KEYS_ARRAY_LEN];     // true if specified key is down
		bool keysPressed[KEYS_ARRAY_LEN];  // true if specified key was pressed
		std::string textIn;                         // user entered text
		char charIn;                                // last character entered
		bool newLine;                               // true on start of new line

	public:
		InputManager();

		~InputManager();

		// Initialize mouse and controller input.
		// Throws GameError
		// Pre: hwnd = window handle
		// capture = true to capture mouse.
		LRESULT proccessKeyMessage(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

		// Save key down state
		void keyDown(WPARAM);

		// Save key up state
		void keyUp(WPARAM);

		// Save the char just entered in textIn string
		void keyIn(WPARAM);

		// Returns true if the specified VIRTUAL KEY is down, otherwise false.
		bool isKeyDown(UCHAR vkey) const;

		// Return true if the specified VIRTUAL KEY has been pressed in the most recent frame.
		// Key presses are erased at the end of each frame.
		bool wasKeyPressed(UCHAR vkey) const;

		// Return true if any key was pressed in the most recent frame.
		// Key presses are erased at the end of each frame.
		bool anyKeyPressed() const;

		// Clear the specified key press
		void clearKeyPress(UCHAR vkey);

		// Clear specified input buffers where what is any combination of
		// KEYS_DOWN, KEYS_PRESSED, MOUSE, TEXT_IN or KEYS_MOUSE_TEXT.
		// Use OR '|' operator to combine parmeters.
		void clear(UCHAR what);

		// Clears key and text input data
		void clearAll();

		// Clear text input buffer
		void clearTextIn();

		// Return text input as a string
		std::string getTextIn();

		// Return last character entered
		char getCharIn();
	};
}