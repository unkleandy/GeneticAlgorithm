// Contexte de realisation: cours B52 - Developpement en environnement de base de donnees
//
// Description : Classe abstraite generale pour representer une solution de forme (cercle, rectangle, etc.)
// 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de creation : 2019/12/21
// Auteur : Etienne Cote

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
	Shape const & shape() const;
	void setShape(Shape * shape);

	/////////////////////////////////////////////////////////////////////
	//Methode qui appelle la methode draw de la shape voulue (pointeur)//
	/////////////////////////////////////////////////////////////////////
	void draw(windows_console::image & anImage, windows_console::brightness_type  aBrightness, windows_console::color_type aColor) const;

	////////////////////////////////////////////////////////////////////////////////////////
	//Methode qui evalue les performances d'une solution et si elle devrait se reproduire.//
	//Appelle les deux methodes plus bas et assigne la valeur 0 si les test ne passent pas//
	////////////////////////////////////////////////////////////////////////////////////////
	void processFitness() override;

	///////////////////////////////////////////////////////////////////////////
	//Methode qui teste si la solution se trouve bien a l'interieur du canvas//
	///////////////////////////////////////////////////////////////////////////
	bool isInsideCanvas() const;

	/////////////////////////////////////////////////////////////////////////////////////////
	//Methode qui teste si la solution ne possede pas d'obstacles a l'interieur de son aire//
	/////////////////////////////////////////////////////////////////////////////////////////
	bool isObstaclesIntersect() const;

protected:
	///////////////////////
	//Reference au canvas//
	Canvas const & mCanvas;
	///////////////////////

	//////////////////////////////////////////////////////////
	//Pointeur vers la bonne forme (cercle, rectangle, etc.)//
	//////////////////////////////////////////////////////////
	Shape * mShape;

	void setSolutionBrightness(windows_console::brightness_type aBrightness) override;
	void setSolutionColor(windows_console::color_type aColor) override;

};

#endif // !SHAPESOLUTION_H