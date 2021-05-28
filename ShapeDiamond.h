// Contexte de réalisation: cours B52 - Développement en environnement de base de données
//
// Description:				Représente les losanges qui sont dessinés à l'écran.	
//
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de création :		2019/12/21
// Auteur :					Frédéric Bélanger

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

	// Distance entre le centre du losange et un côté horizontal
	int mHalfWidth{1};

	// Distance entre le centre du losange et un côté vertical
	int mHalfHeight{1};

	// Orientation du losange en degré
	int mOrientation{0};

	// Centre du losange
	Point mCenter{Point(10,10)};

public:
	ShapeDiamond() = default;
	~ShapeDiamond() = default;

	// Mutateur simultané de la distance entre le centre du losange et un côté horizontal, la distance
	// entre le centre du losange et un côté vertical, le centre et l'orientation du losange
	void set(int const & halfWidth, int const & halfHeight, Point const & center = Point(0.0, 0.0), int const & orientationDegrees = 0);

	// Mutateur de la distance entre le centre du losange et un côté horizontal
	void setHalfWidth(int const & halfWidth);

	// Mutateur de la distance entre le centre du losange et un côté vertical
	void setHalfHeight(int const & halfHeight);

	// Mutateur de l'orientation du losange en degré
	void setOrientation(int const & orientation);

	// Mutateur du centre du losange
	void setCenter(Point const & center);

	// Accesseur de la distance entre le centre du losange et un côté horizontal
	int const & halfWidth() const;

	// Accesseur de la distance entre le centre du losange et un côté vertical
	int const & halfHeight() const;

	// Accesseur de l'orientation du losange en degré
	int const & orientation() const;

	// Accesseur du centre du losange
	Point const & center() const;

	// Vérifie si les paramètres du losange sont valide ("halfWith" ou "halfHeight" ne sont pas 0)
	bool const & isValid() const override;

	// Dessine le losange à l'écran
	void draw(windows_console::image & anImage, windows_console::brightness_type const & aBrightness, windows_console::color_type const & aColor) const override;
	
	// Retourne l'aire du losange
	double const & area() const override;

	// Retourne un objet Rectangle qui correspont aux limites en hauteur et en largeur du losange. Ce rectangle "virtuel" (il 
	// n'est pas dessiné) correspont aux points x et y les plus petits et les plus grands de la forme (il "entoure" celle-ci). 
	// Il sert a vérifier si des parties de la forme se trouve à l'extérieur du canevas.
	Rectangle boundingRect() const override; // Je ne sais pas pourquoi mais si je retourne une Rectangle const & les populations n'évoluent plus.

	// Vérifie si un point se trouve à l'intérieur du losange. Retourne un "false" si un point est sur
	// la bordure. Il doit être complètement à l'intérieur pour qu'un "true" soit retourné.
	bool const & contains(Point const & p) const override;

	// Mutateur pour modifier la luminosité du losange affiché à l'écran. Les losanges plus lumineux représentent les meilleures solutions
	// trouvées par l'IA.
	void setShapeBrightness(windows_console::brightness_type const & aBrightness)override;

	// Mutateur pour modifier la couleur du losange affiché à l'écran. Lorsqu'il y a plusieurs populations qui sont évaluées en même temps, 
	// chacune a sa propre couleur.
	void setShapeColor(windows_console::color_type const & aColor)override;

};

#endif // SHAPE_DIAMOND_H