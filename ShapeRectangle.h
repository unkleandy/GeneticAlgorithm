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

	bool isValid() const override; 
	void draw(windows_console::image & anImage, windows_console::brightness_type  aBrightness, windows_console::color_type aColor) const override;
	double area() const override;
	Rectangle boundingRect() const override;
	bool contains(Point const & p) const override;   
	void setShapeBrightness(windows_console::brightness_type aBrightness)override;
	void setShapeColor(windows_console::color_type aColor)override;

	
};

#endif // SHAPE_RECTANGLE_H