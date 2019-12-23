// Contexte de r�alisation: cours B52 - D�veloppement en environnement de base de donn�es
//
// Description:	Methode pour faire un reset de pointeurs;	
// 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de cr�ation :		2019/12/21
// Auteur :	Andrea Cohen

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