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