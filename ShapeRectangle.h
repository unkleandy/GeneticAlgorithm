// Contexte de réalisation: cours B52 - Développement en environnement de base de données
//
// Description:				Représente les Rectangles qui sont dessinés à l'écran.	
//
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de création :		2019/12/21
// Auteur :					Frédéric Bélanger

#pragma once
#ifndef SHAPE_RECTANGLE_H
#define SHAPE_RECTANGLE_H

#include<console.h>
#include<Rect2d.h>
#include "Shape.h"

// valid pas de height ou width à 0
// polygon: pas de croisement de ligne. La classe donnée le fait deja

class ShapeRectangle : public Shape, public bg::Rect2d {
public:
	ShapeRectangle() = default;
	~ShapeRectangle() = default;

	// Vérifie si les paramètres du rectangle sont valide (La largeur ou la hauteur ne sont pas 0)
	bool const & isValid() const override;

	// Dessine le rectangle à l'écran
	void draw(windows_console::image & anImage, windows_console::brightness_type const & aBrightness, windows_console::color_type const & aColor) const override;
	
	// Retourne l'aire du rectangle
	double const & area() const override;

	// Retourne un objet Rectangle qui correspont aux limites en hauteur et en largeur du rectangle. Même si en thérie cette méthode
	// retourne un objet de sa propre classe il est nécessaire de l'implanter car elle est un override d'une classe virtuelle pure.
	// Il sert a vérifier si des parties de la forme se trouve à l'extérieur du canevas.
	Rectangle boundingRect() const override; // Je ne sais pas pourquoi mais si je retourne une Rectangle const & les populations n'évoluent plus.

	// Vérifie si un point se trouve à l'intérieur du rectangle. Retourne un "false" si un point est sur
	// la bordure. Il doit être complètement à l'intérieur pour qu'un "true" soit retourné.
	bool const & contains(Point const & p) const override;

	// Mutateur pour modifier la luminosité du rectangle affiché à l'écran. Les rectangles plus lumineux représentent les meilleures solutions
	// trouvées par l'IA.
	void setShapeBrightness(windows_console::brightness_type const & aBrightness)override;
	
	// Mutateur pour modifier la couleur du rectangle affiché à l'écran. Lorsqu'il y a plusieurs populations qui sont évaluées en même temps, 
	// chacune a sa propre couleur.
	void setShapeColor(windows_console::color_type const & aColor)override;

};

#endif // SHAPE_RECTANGLE_H