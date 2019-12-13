#pragma once
#ifndef CANVAS_H
#define CANVAS_H

#include <vector>
#include "Rectangle.h"
#include "Size.h"
#include "Point.h"

class Canvas
{
	
public:
	Canvas() = default;
	Canvas(Rectangle rectangle, size_t obstacleCount);
	~Canvas() = default;

	

	bool isValid() const;
	Rectangle const & rectangle() const;
	std::vector<Point> const & obstacles() const;
	void set(Rectangle const & rectangle, size_t obstacleCount);
	void setObstacles(size_t obstacleCount);
	void randomizeObstacles();
	// void drawBackground() const;
	void drawObstacles() const;



private:
	Rectangle mRect;
	size_t mObstacleCount;
	std::vector<Point> mObstacles;

	double generateRandomObstacleX();
	double generateRandomObstacleY();
	void generateRandomObstacle(Point & p);

	
};





#endif // CANVAS_H
