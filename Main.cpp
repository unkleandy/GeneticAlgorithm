#include <console.h>


using namespace::std;
using namespace windows_console;

int main() {
	csl << window::title("B52")
		<< window::fit(300, 200, "Consolas", font::size_type{ 3 }, font::ratio_type{ 1 })
		<< window::unclosable
		<< window::unresizable
		<< window::center
		<< cursor::invisible;

	image im;
	im << pen(dot, text_color(bright, red), background_color(dark, red))
		<< point(100, 100)
		<< brush(dot, text_color(dark, blue), background_color(dark, blue))
		<< rectangle(105, 105, 150, 150)
		<< no_brush
		<< circle(200, 155, 50)
		<< line(0, 0, 250, 100);


	csl << im;

	console_events ce;
	ce.read_events();
	while (ce.key_events_count())
		switch (ce.next_key_event().ascii_value())
		{
		case 27: return 0;
		case ' ': return 0;
			break;
		default: break;

		}

	return 0;
}