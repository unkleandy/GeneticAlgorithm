// Contexte de r�alisation: cours B52 - D�veloppement en environnement de base de donn�es
//
// Description:				Superclasse abstraite dont les sousclasses repr�sentent des formes g�om�triques utilis�es dans 
//							le projet.Englobe les points en communs des diff�rentes formes.
//
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de cr�ation :		2019/12/21
// Auteur :					Fr�d�ric B�langer	

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
	
	// Les sousclasses doivent avoir une m�thode pour v�rifier si leurs param�tres sont valides.
	virtual bool const & isValid() const = 0;

	// Les sousclasses doivent avoir une m�thode pour dessiner la forme g�om�trique correspondante � l'�cran.
	virtual void draw(windows_console::image & anImage, windows_console::brightness_type const & aBrightness, windows_console::color_type const & aColor) const = 0;

	// Les sousclasses doivent avoir une m�thode pour calculer l'aire la forme g�om�trique correspondante.
	virtual double const & area() const = 0;

	// Les sousclasses doivent avoir un accesseur qui retourne un objet Rectangle qui correspont aux limites en hauteur et en largeur de la forme correspondante.
	// Ce rectangle "virtuel" (il n'est pas dessin�) correspont aux points x et y les plus petits et les plus grands de la forme (il "entoure" celle-ci). Il sert
	// a v�rifier si des parties de la forme se trouve � l'ext�rieur du canevas.
	virtual Rectangle boundingRect() const = 0; // Je ne sais pas pourquoi mais si je retourne une Rectangle const & les populations n'�voluent plus.

	// Les sousclasses doivent avoir une m�thode qui v�rifie si un point se trouve � l'int�rieur de la forme correspondante. Retourne un "false" si un point est sur
	// la bordure de la forme. Il doit �tre compl�tement � l'int�rieur pour qu'un "true" soit retourn�.
	virtual bool const & contains(Point const & p) const = 0;

	// Les sousclasses doivent avoir un mutateur pour modifier la luminosit� de la forme affich�e � l'�cran. Les formes plus lumineuses repr�sentent les meilleures solutions
	// trouv�es par l'IA.
	virtual void setShapeBrightness(windows_console::brightness_type const & aBrightness) = 0;

	// Les sousclasses doivent avoir un mutateur pour modifier la couleur de la forme affich�e � l'�cran. Lorsqu'il y a plusieurs populations qui sont �valu�es en m�me temps, 
	// chacune a sa propre couleur.
	virtual void setShapeColor(windows_console::color_type const & aColor)=0;



protected:
	// Repr�sente la luminosit� de la forme lorsqu'elle est affich�e � l'�cran.
	windows_console::brightness_type mShapeBrightness{ windows_console::brightness_type::dark};

	// Repr�sente la couleur de la forme lorsqu'elle est affich�e � l'�cran.
	windows_console::color_type mShapeColor{ windows_console::color_type::red};

};

#endif // SHAPE_H