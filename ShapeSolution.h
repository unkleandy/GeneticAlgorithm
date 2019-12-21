// Contexte de réalisation: cours B52 - Développement en environnement de base de données
//
// Description:				
// 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de création :		2019/12/21
// Auteur :				

#pragma once
#ifndef SHAPESOLUTION_H
#define SHAPESOLUTION_H

#include <console.h>
#include "Solution.h"
#include "Canvas.h"
#include "Shape.h"


class ShapeSolution : public Solution
{
public:
	ShapeSolution(Canvas const & canvas);
	~ShapeSolution() override = default;

	void draw(windows_console::image & anImage, windows_console::brightness_type  aBrightness, windows_console::color_type aColor) const;
	void processFitness() override;
	bool isInsideCanvas() const;
	bool isObstaclesIntersect() const;

protected:
	Canvas const & mCanvas;
	Shape * mShape;
	void setSolutionBrightness(windows_console::brightness_type aBrightness) override;
	void setSolutionColor(windows_console::color_type aColor) override;
};


#endif // !SHAPESOLUTION_H