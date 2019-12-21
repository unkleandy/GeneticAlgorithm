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
	int mHalfWidth;
	int mHalfHeight;
	int mOrientation;
	Point mCenter;



public:
	ShapeDiamond() = default;
	~ShapeDiamond() = default;

	void set(int a, int b, Point center = Point(0.0, 0.0), int orientationDegrees = 0);
	void setHalfWidth(int halfWidth);
	void setHalfHeight(int halfHeight);
	void setOrientation(int orientation);
	void setCenter(Point center);
	int halfWidth();
	int halfHeight();
	int orientation();
	Point center();
	bool isValid() const override;
	void draw(windows_console::image & anImage, windows_console::brightness_type  aBrightness, windows_console::color_type aColor) const override;
	double area() const override;
	Rectangle boundingRect() const override;
	bool contains(Point const & p) const override;
	void setShapeBrightness(windows_console::brightness_type aBrightness)override;
	void setShapeColor(windows_console::color_type aColor)override;



};

#endif // SHAPE_DIAMOND_H