#pragma once
#ifndef P_DELETE_H
#define P_DELETE_H

template <typename T>
inline void pDelete(T* pointer) {
	if (pointer) {
		delete pointer;
		pointer = nullptr;
	}
}

#endif // P_DELETE_H