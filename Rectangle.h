// Contexte de réalisation: cours B52 - Développement en environnement de base de données
//
// Description:				Typedef pour la classe Rect2d qui représente la largeur et la hauteur, les positions
//							X et Y (sous la forme d'un objet Point) et les dimensions (sous la forme d'un objet Size)
//							d'un rectangle
//
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de création :		2019/12/21
// Auteur :					Frédéric Bélanger

#pragma once
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <Rect2d.h>

// La classe Rectangle est simplement un typedef de la classe Rect2d
using Rectangle = bg::Rect2d;

#endif // RECTANGLE_H