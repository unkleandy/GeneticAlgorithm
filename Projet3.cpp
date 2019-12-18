
#include <console.h>
#include "ShapeOptimizer.h"
#include "ShapeCircle.h"
#include "ShapeRectangle.h"
#include "ShapeEquilateralTriangle.h"
#include "ShapeDiamond.h"
#include "ViewMenu.h"
#include "ViewRuntime.h"
#include "Point.h"
#include "Size.h"
#include "Rectangle.h"

int main() {
	// Ajoute un filtre pour ne pas générer 2 événements lors d'une entrée au cliavier (un au "key up" et un au "key down")
	windows_console::csl << windows_console::key_events::add_filter<windows_console::key_filter_up>;
	ViewMenu viewMenu;
	ViewRuntime viewRuntime;
	ShapeOptimizer shapeOptimizer(viewMenu, viewRuntime);
	ShapeOptimizer * shapeOptimizerPtr = & shapeOptimizer;
	viewMenu.setShapeOptimizer(shapeOptimizerPtr);
	viewRuntime.setShapeOptimizer(shapeOptimizerPtr);
	shapeOptimizer.run();




	// Code utilisé pour tests, conservé pour références futures
	

	//ViewRuntime viewRuntime;
	//ShapeDiamond aDiamond;
	//Point center(40.0, 40);

	//Point ptAtester(25,30);
	//aDiamond.set(20,20,center,0);



	//aDiamond.draw();
	//double area = aTriangle.area();
	//Rectangle boundingRect = aTriangle.boundingRect();
	//bool inside = aTriangle.contains(ptAtester);
	//bool valid = aTriangle.isValid();

	//aCircle.set(centre, 0);
	//valid = aCircle.isValid();

	//ShapeRectangle aRectangle;
	//aRectangle.set(Point(40, 40), Size(30, 60));
	//aRectangle.draw();
	//inside = aRectangle.contains(ptAtester);
	//ptAtester.set(45, 70);
	//inside = aRectangle.contains(ptAtester);
	//valid = aRectangle.isValid();
	//area = aRectangle.area();

	//aRectangle.setSize(Size(0, 10));
	//valid = aRectangle.isValid();
	//aRectangle.setSize(Size(20, 0));
	//valid = aRectangle.isValid();

	//Canvas aCanvas(Rectangle(0,0,300, 200), 20);
	//valid = aCanvas.isValid();
	//aCanvas.drawObstacles();











	// Code non utilisé, conservé pour références futures
	/*using namespace windows_console;
	using namespace std;

	std::string old_title;
	csl >> window::title(old_title);

	csl << window::title("B52");

	csl << window::fit(300, 200, "Consolas", font::size_type{ 3 }, font::ratio_type{ 1.0 })
		<< window::unclosable
		<< window::unresizable
		<< window::center
		<< cursor::invisible;

	image im;
	im << pen(dot, text_color(bright, red), background_color(dark, red))
		<< point(100,100)
		<< brush(dot, text_color(dark, blue), background_color(dark, blue))
		<< rectangle(105, 105, 150, 150)
		<< no_brush
		<< circle(20,20,10)
		<< pen(dot, text_color(bright, yellow), background_color(dark, red))
		<< line(0,0,100,100) ;
	csl << im;

	image i2;
	i2 << fill;

	console_events ce;
	while (true) {
		ce.read_events();
		while (ce.key_events_count()) {
			switch (ce.next_key_event().ascii_value()) {
			case 27: return 0;
			case ' ':
				csl << im;
				break;
			case 'a':
			case 'A':
				csl << i2;
				break;
			}
		}
	}*/

	return 0;
}