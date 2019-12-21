// Contexte de réalisation: cours B52 - Développement en environnement de base de données
//
// Description:				
// 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de création :		2019/12/21
// Auteur :		

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