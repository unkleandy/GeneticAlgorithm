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
	void draw(windows_console::image & anImage) const override;
	double area() const override;
	Rectangle boundingRect() const override;
	bool contains(Point const & p) const override;   
	// Shape * clone() const override;

	
};

#endif // SHAPE_RECTANGLE_H