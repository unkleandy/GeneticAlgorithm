
#include <console.h>
#include "ShapeOptimizer.h"
#include "ShapeCircle.h"
#include "ShapeRectangle.h"
#include "ShapeDiamond.h"
#include "ViewMenu.h"
#include "ViewRuntime.h"
#include "Point.h"
#include "Size.h"
#include "Rectangle.h"

#include "Chromosome.h"
#include <vector>

int main() {

	//std::vector<bool> test;

	//test = { 1,1,0,0,1,1,0,0 };

	//Chromosome c;

	//uint32_t a{}, b{};

	//c.resize(test.size());

	//c.write(uint32_t(10), 0, 8);

	//c.read(a, 0, 8);

	//c.write(uint32_t(6), 0, 8);

	//c.read(a, 0, 8);
	

	// Ajoute un filtre pour ne pas générer 2 événements lors d'une entrée au cliavier (un au "key up" et un au "key down")
	windows_console::csl << windows_console::key_events::add_filter<windows_console::key_filter_up>;
	ViewMenu viewMenu;
	ViewRuntime viewRuntime;
	ShapeOptimizer shapeOptimizer(viewMenu, viewRuntime);
	ShapeOptimizer * shapeOptimizerPtr = & shapeOptimizer;
	viewMenu.setShapeOptimizer(shapeOptimizerPtr);
	viewRuntime.setShapeOptimizer(shapeOptimizerPtr);
	shapeOptimizer.run();

	return 0;
}