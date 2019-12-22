// Contexte de r�alisation: cours B52 - D�veloppement en environnement de base de donn�es
//
// Description:				Repr�sente les Rectangles qui sont dessin�s � l'�cran.	
//
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de cr�ation :		2019/12/21
// Auteur :					Fr�d�ric B�langer

#pragma once
#ifndef SHAPE_RECTANGLE_H
#define SHAPE_RECTANGLE_H

#include<console.h>
#include<Rect2d.h>
#include "Shape.h"

// valid pas de height ou width � 0
// polygon: pas de croisement de ligne. La classe donn�e le fait deja

class ShapeRectangle : public Shape, public bg::Rect2d {
public:
	ShapeRectangle() = default;
	~ShapeRectangle() = default;

	// V�rifie si les param�tres du rectangle sont valide (La largeur ou la hauteur ne sont pas 0)
	bool const & isValid() const override;

	// Dessine le rectangle � l'�cran
	void draw(windows_console::image & anImage, windows_console::brightness_type const & aBrightness, windows_console::color_type const & aColor) const override;
	
	// Retourne l'aire du rectangle
	double const & area() const override;

	// Retourne un objet Rectangle qui correspont aux limites en hauteur et en largeur du rectangle. M�me si en th�rie cette m�thode
	// retourne un objet de sa propre classe il est n�cessaire de l'implanter car elle est un override d'une classe virtuelle pure.
	// Il sert a v�rifier si des parties de la forme se trouve � l'ext�rieur du canevas.
	Rectangle boundingRect() const override; // Je ne sais pas pourquoi mais si je retourne une Rectangle const & les populations n'�voluent plus.

	// V�rifie si un point se trouve � l'int�rieur du rectangle. Retourne un "false" si un point est sur
	// la bordure. Il doit �tre compl�tement � l'int�rieur pour qu'un "true" soit retourn�.
	bool const & contains(Point const & p) const override;

	// Mutateur pour modifier la luminosit� du rectangle affich� � l'�cran. Les rectangles plus lumineux repr�sentent les meilleures solutions
	// trouv�es par l'IA.
	void setShapeBrightness(windows_console::brightness_type const & aBrightness)override;
	
	// Mutateur pour modifier la couleur du rectangle affich� � l'�cran. Lorsqu'il y a plusieurs populations qui sont �valu�es en m�me temps, 
	// chacune a sa propre couleur.
	void setShapeColor(windows_console::color_type const & aColor)override;

};

#endif // SHAPE_RECTANGLE_H