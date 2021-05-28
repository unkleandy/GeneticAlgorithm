// Contexte de r�alisation: cours B52 - D�veloppement en environnement de base de donn�es
//
// Description:				Repr�sente les losanges qui sont dessin�s � l'�cran.	
//
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de cr�ation :		2019/12/21
// Auteur :					Fr�d�ric B�langer

#pragma once
#ifndef SHAPE_DIAMOND_H
#define SHAPE_DIAMOND_H

#include <console.h>
#include <Polygon2d.h>
#include "Shape.h"
#include "Point.h"

class ShapeDiamond : public Shape {

private:
	bg::Polygon2d mDiamond;

	// Distance entre le centre du losange et un c�t� horizontal
	int mHalfWidth{1};

	// Distance entre le centre du losange et un c�t� vertical
	int mHalfHeight{1};

	// Orientation du losange en degr�
	int mOrientation{0};

	// Centre du losange
	Point mCenter{Point(10,10)};

public:
	ShapeDiamond() = default;
	~ShapeDiamond() = default;

	// Mutateur simultan� de la distance entre le centre du losange et un c�t� horizontal, la distance
	// entre le centre du losange et un c�t� vertical, le centre et l'orientation du losange
	void set(int const & halfWidth, int const & halfHeight, Point const & center = Point(0.0, 0.0), int const & orientationDegrees = 0);

	// Mutateur de la distance entre le centre du losange et un c�t� horizontal
	void setHalfWidth(int const & halfWidth);

	// Mutateur de la distance entre le centre du losange et un c�t� vertical
	void setHalfHeight(int const & halfHeight);

	// Mutateur de l'orientation du losange en degr�
	void setOrientation(int const & orientation);

	// Mutateur du centre du losange
	void setCenter(Point const & center);

	// Accesseur de la distance entre le centre du losange et un c�t� horizontal
	int const & halfWidth() const;

	// Accesseur de la distance entre le centre du losange et un c�t� vertical
	int const & halfHeight() const;

	// Accesseur de l'orientation du losange en degr�
	int const & orientation() const;

	// Accesseur du centre du losange
	Point const & center() const;

	// V�rifie si les param�tres du losange sont valide ("halfWith" ou "halfHeight" ne sont pas 0)
	bool const & isValid() const override;

	// Dessine le losange � l'�cran
	void draw(windows_console::image & anImage, windows_console::brightness_type const & aBrightness, windows_console::color_type const & aColor) const override;
	
	// Retourne l'aire du losange
	double const & area() const override;

	// Retourne un objet Rectangle qui correspont aux limites en hauteur et en largeur du losange. Ce rectangle "virtuel" (il 
	// n'est pas dessin�) correspont aux points x et y les plus petits et les plus grands de la forme (il "entoure" celle-ci). 
	// Il sert a v�rifier si des parties de la forme se trouve � l'ext�rieur du canevas.
	Rectangle boundingRect() const override; // Je ne sais pas pourquoi mais si je retourne une Rectangle const & les populations n'�voluent plus.

	// V�rifie si un point se trouve � l'int�rieur du losange. Retourne un "false" si un point est sur
	// la bordure. Il doit �tre compl�tement � l'int�rieur pour qu'un "true" soit retourn�.
	bool const & contains(Point const & p) const override;

	// Mutateur pour modifier la luminosit� du losange affich� � l'�cran. Les losanges plus lumineux repr�sentent les meilleures solutions
	// trouv�es par l'IA.
	void setShapeBrightness(windows_console::brightness_type const & aBrightness)override;

	// Mutateur pour modifier la couleur du losange affich� � l'�cran. Lorsqu'il y a plusieurs populations qui sont �valu�es en m�me temps, 
	// chacune a sa propre couleur.
	void setShapeColor(windows_console::color_type const & aColor)override;

};

#endif // SHAPE_DIAMOND_H