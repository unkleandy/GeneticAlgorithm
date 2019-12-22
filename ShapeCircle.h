// Contexte de r�alisation: cours B52 - D�veloppement en environnement de base de donn�es
//
// Description:				Repr�sente les cercles qui sont dessin�s � l'�cran.	
//
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de cr�ation :		2019/12/21
// Auteur :					Fr�d�ric B�langer	

#pragma once
#ifndef SHAPE_CIRCLE_H
#define SHAPE_CIRCLE_H

#include <console.h>
#include "Point.h"
#include "Rectangle.h"
#include "Shape.h"

class ShapeCircle : public Shape {
public:
	ShapeCircle() = default;
	~ShapeCircle() = default;

	Point const & center() const;
	double const & radius() const;

	// Mutateur du centre du cercle
	void setCenter(Point const & center);

	// Mutateur du rayon du cercle
	void setRadius(double const & radius);

	// Mutateur simultan� du centre et du rayon du cercle
	void set(Point const & center, double const & radius);

	// V�rifie si les param�tres du cercle sont valide (Le rayon n'est pas 0)
	bool const & isValid() const override; // pas mRadius = 0, 

	// Dessine le cercle � l'�cran
	void draw(windows_console::image & anImage, windows_console::brightness_type  const & aBrightness, windows_console::color_type const & aColor) const override;
	
	// Retourne l'aire du cercle
	double const & area() const override;

	// Retourne un objet Rectangle qui correspont aux limites en hauteur et en largeur du cercle. Ce rectangle "virtuel" (il 
	// n'est pas dessin�) correspont aux points x et y les plus petits et les plus grands de la forme (il "entoure" celle-ci). 
	// Il sert a v�rifier si des parties du cercle se trouve � l'ext�rieur du canevas.
	Rectangle boundingRect() const override; // Je ne sais pas pourquoi mais si je retourne une Rectangle const & les populations n'�voluent plus.

	// V�rifie si un point se trouve � l'int�rieur du cercle. Retourne un "false" si un point est sur
	// la bordure. Il doit �tre compl�tement � l'int�rieur pour qu'un "true" soit retourn�. Pour faire la
	// v�rification on calcule la distance entre le point �valu� et le centre du cercle. Si celle-ci est inf�rieure au
	// rayon du cercle alors le point se trouve � l'int�rieur.
	bool const & contains(Point const & p) const override;   

	// Mutateur pour modifier la luminosit� du cercle affich� � l'�cran. Les cercles plus lumineux repr�sentent les meilleures solutions
	// trouv�es par l'IA.
	void setShapeBrightness(windows_console::brightness_type const & aBrightness)override;

	// Mutateur pour modifier la couleur du cercle affich� � l'�cran. Lorsqu'il y a plusieurs populations qui sont �valu�es en m�me temps, 
	// chacune a sa propre couleur.
	void setShapeColor(windows_console::color_type const & aColor)override;



private:
	// Centre du cercle
	Point mCenter{Point(10,10)};

	// Rayon du cercle
	double mRadius{1};


};

#endif // SHAPE_CIRCLE_H