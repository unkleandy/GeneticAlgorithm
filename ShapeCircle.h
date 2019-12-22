// Contexte de réalisation: cours B52 - Développement en environnement de base de données
//
// Description:				Représente les cercles qui sont dessinés à l'écran.	
//
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de création :		2019/12/21
// Auteur :					Frédéric Bélanger	

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

	// Mutateur simultané du centre et du rayon du cercle
	void set(Point const & center, double const & radius);

	// Vérifie si les paramètres du cercle sont valide (Le rayon n'est pas 0)
	bool const & isValid() const override; // pas mRadius = 0, 

	// Dessine le cercle à l'écran
	void draw(windows_console::image & anImage, windows_console::brightness_type  const & aBrightness, windows_console::color_type const & aColor) const override;
	
	// Retourne l'aire du cercle
	double const & area() const override;

	// Retourne un objet Rectangle qui correspont aux limites en hauteur et en largeur du cercle. Ce rectangle "virtuel" (il 
	// n'est pas dessiné) correspont aux points x et y les plus petits et les plus grands de la forme (il "entoure" celle-ci). 
	// Il sert a vérifier si des parties du cercle se trouve à l'extérieur du canevas.
	Rectangle boundingRect() const override; // Je ne sais pas pourquoi mais si je retourne une Rectangle const & les populations n'évoluent plus.

	// Vérifie si un point se trouve à l'intérieur du cercle. Retourne un "false" si un point est sur
	// la bordure. Il doit être complètement à l'intérieur pour qu'un "true" soit retourné. Pour faire la
	// vérification on calcule la distance entre le point évalué et le centre du cercle. Si celle-ci est inférieure au
	// rayon du cercle alors le point se trouve à l'intérieur.
	bool const & contains(Point const & p) const override;   

	// Mutateur pour modifier la luminosité du cercle affiché à l'écran. Les cercles plus lumineux représentent les meilleures solutions
	// trouvées par l'IA.
	void setShapeBrightness(windows_console::brightness_type const & aBrightness)override;

	// Mutateur pour modifier la couleur du cercle affiché à l'écran. Lorsqu'il y a plusieurs populations qui sont évaluées en même temps, 
	// chacune a sa propre couleur.
	void setShapeColor(windows_console::color_type const & aColor)override;



private:
	// Centre du cercle
	Point mCenter{Point(10,10)};

	// Rayon du cercle
	double mRadius{1};


};

#endif // SHAPE_CIRCLE_H