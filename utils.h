#pragma once

namespace utils {
	void SafeDelete(void* ptr) {
		if (ptr) {
			delete ptr;

			ptr = nullptr;
		}
	}
}