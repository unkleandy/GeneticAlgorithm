// Contexte de réalisation: cours B52 - Développement en environnement de base de données
//
// Description:				Gère la taille du canvas (de la console) et le rendu des obstacles
// 
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
// 
// Date de création :		2019/12/21
// Auteur :					Frédéric Bélanger			


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
	// Gère également la création aléatoire des obstacles
	Canvas(Rectangle const & rectangle, size_t obstacleCount);
	~Canvas() = default;

	
	// Détermine si le canvas est valide (vérifie si sa largeur ou sa hauteur ne sont pas 0)
	bool const & isValid() const;
	// Accesseur du rectangle représentant la taille du canvas
	Rectangle const & rectangle() const;
	// Accesseur du vecteur contenant les obstacles
	std::vector<Point> const & obstacles() const;
	// Mutateur simultané u rectangle représentant la taille du canvas et du nombre d'obstacle
	void set(Rectangle const & rectangle, size_t const & obstacleCount);
	// Mutateur du nombre d'obstacle
	void setObstacles(size_t const & obstacleCount);
	// Créé tous les obstacles avec des positions aléatoires et les insère dans le vecteur d'obstacles
	void randomizeObstacles();
	// Dessine les obstacles sur le canvas
	void drawObstacles(windows_console::image & anImage) const;



private:
	// Rectangle représentant la taille du canvas
	Rectangle mRect;
	// Nombre d'obstacle sur le canvas
	size_t mObstacleCount;
	// Vecteur contenant tous les obstacles
	std::vector<Point> mObstacles;

	// Génère aléatoirement la position X d'un obstacle
	double generateRandomObstacleX();
	// Génère aléatoirement la position Y d'un obstacle
	double generateRandomObstacleY();
	// Génère aléatoirement un objet Point représentant la position d'un obstacle
	void generateRandomObstacle(Point & p);

	
};





#endif // CANVAS_H
