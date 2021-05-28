// Contexte de réalisation: cours B52 - Développement en environnement de base de données
//
// Description:				Superclasse abstraite dont les sousclasses représentent des formes géométriques utilisées dans 
//							le projet.Englobe les points en communs des différentes formes.
//
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de création :		2019/12/21
// Auteur :					Frédéric Bélanger	

#pragma once
#ifndef SHAPE_H
#define SHAPE_H

#include <console.h>
#include "Rectangle.h"
#include "Point.h"

class Shape
{
public:
	Shape() = default;
	~Shape() = default;
	
	// Les sousclasses doivent avoir une méthode pour vérifier si leurs paramètres sont valides.
	virtual bool const & isValid() const = 0;

	// Les sousclasses doivent avoir une méthode pour dessiner la forme géométrique correspondante à l'écran.
	virtual void draw(windows_console::image & anImage, windows_console::brightness_type const & aBrightness, windows_console::color_type const & aColor) const = 0;

	// Les sousclasses doivent avoir une méthode pour calculer l'aire la forme géométrique correspondante.
	virtual double const & area() const = 0;

	// Les sousclasses doivent avoir un accesseur qui retourne un objet Rectangle qui correspont aux limites en hauteur et en largeur de la forme correspondante.
	// Ce rectangle "virtuel" (il n'est pas dessiné) correspont aux points x et y les plus petits et les plus grands de la forme (il "entoure" celle-ci). Il sert
	// a vérifier si des parties de la forme se trouve à l'extérieur du canevas.
	virtual Rectangle boundingRect() const = 0; // Je ne sais pas pourquoi mais si je retourne une Rectangle const & les populations n'évoluent plus.

	// Les sousclasses doivent avoir une méthode qui vérifie si un point se trouve à l'intérieur de la forme correspondante. Retourne un "false" si un point est sur
	// la bordure de la forme. Il doit être complètement à l'intérieur pour qu'un "true" soit retourné.
	virtual bool const & contains(Point const & p) const = 0;

	// Les sousclasses doivent avoir un mutateur pour modifier la luminosité de la forme affichée à l'écran. Les formes plus lumineuses représentent les meilleures solutions
	// trouvées par l'IA.
	virtual void setShapeBrightness(windows_console::brightness_type const & aBrightness) = 0;

	// Les sousclasses doivent avoir un mutateur pour modifier la couleur de la forme affichée à l'écran. Lorsqu'il y a plusieurs populations qui sont évaluées en même temps, 
	// chacune a sa propre couleur.
	virtual void setShapeColor(windows_console::color_type const & aColor)=0;



protected:
	// Représente la luminosité de la forme lorsqu'elle est affichée à l'écran.
	windows_console::brightness_type mShapeBrightness{ windows_console::brightness_type::dark};

	// Représente la couleur de la forme lorsqu'elle est affichée à l'écran.
	windows_console::color_type mShapeColor{ windows_console::color_type::red};

};

#endif // SHAPE_H