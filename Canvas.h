// Contexte de r�alisation: cours B52 - D�veloppement en environnement de base de donn�es
//
// Description:				G�re la taille du canvas (de la console) et le rendu des obstacles
// 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de cr�ation :		2019/12/21
// Auteur :					Fr�d�ric B�langer			


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
	// Constructeur qui initialise la taille de la console et le nombre d'obstacle
	// G�re �galement la cr�ation al�atoire des obstacles
	Canvas(Rectangle const & rectangle, size_t obstacleCount);
	~Canvas() = default;

	
	// D�termine si le canvas est valide (v�rifie si sa largeur ou sa hauteur ne sont pas 0)
	bool const & isValid() const;
	// Accesseur du rectangle repr�sentant la taille du canvas
	Rectangle const & rectangle() const;
	// Accesseur du vecteur contenant les obstacles
	std::vector<Point> const & obstacles() const;
	// Mutateur simultan� u rectangle repr�sentant la taille du canvas et du nombre d'obstacle
	void set(Rectangle const & rectangle, size_t const & obstacleCount);
	// Mutateur du nombre d'obstacle
	void setObstacles(size_t const & obstacleCount);
	// Cr�� tous les obstacles avec des positions al�atoires et les ins�re dans le vecteur d'obstacles
	void randomizeObstacles();
	// Dessine les obstacles sur le canvas
	void drawObstacles(windows_console::image & anImage) const;



private:
	// Rectangle repr�sentant la taille du canvas
	Rectangle mRect;
	// Nombre d'obstacle sur le canvas
	size_t mObstacleCount;
	// Vecteur contenant tous les obstacles
	std::vector<Point> mObstacles;

	// G�n�re al�atoirement la position X d'un obstacle
	double generateRandomObstacleX();
	// G�n�re al�atoirement la position Y d'un obstacle
	double generateRandomObstacleY();
	// G�n�re al�atoirement un objet Point repr�sentant la position d'un obstacle
	void generateRandomObstacle(Point & p);

	
};





#endif // CANVAS_H
