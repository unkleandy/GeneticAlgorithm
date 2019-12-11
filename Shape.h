#pragma once
#ifndef SHAPE_H
#define SHAPE_H

#include "Rectangle.h"
#include "Point.h"

class Shape
{
public:
	Shape();
	~Shape();
	
	virtual bool isValid() const = 0;
	virtual void draw() const = 0;
	virtual double area() const = 0;
	virtual Rectangle boundingRect() const = 0 ;
	virtual bool contains(Point const & p) const = 0;
	//virtual Shape * clone() const = 0;


private:

};

#endif // SHAPE_H