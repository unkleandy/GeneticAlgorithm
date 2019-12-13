
#include <console.h>
#include "ShapeOptimizer.h"
#include "ShapeCircle.h"
#include "ShapeRectangle.h"
#include "ViewMenu.h"
#include "ViewRuntime.h"
#include "Point.h"
#include "Size.h"
#include "Rectangle.h"

int main() {

	ViewMenu viewmenu;




	// Code utilis� pour tests, conserv� pour r�f�rences futures
	
	//ShapeOptimizer shOptimizer;
	//ViewRuntime viewRuntime;
	//ShapeCircle aCircle;
	//Point centre(20.0, 20.0);
	//Point ptAtester(20.0, 11.0);
	//aCircle.set(centre,10.0);
	//aCircle.draw();
	//double area = aCircle.area();
	//Rectangle boundingRect = aCircle.boundingRect();
	//bool inside = aCircle.contains(ptAtester);
	//bool valid = aCircle.isValid();

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











	// Code non utilis�, conserv� pour r�f�rences futures
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