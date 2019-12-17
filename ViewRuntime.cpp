#include "ViewRuntime.h"



ViewRuntime::ViewRuntime()
{
	using namespace windows_console;
	using namespace std;

	setupWindow();
	// mBlankImage est un buffer vide
	mBlankImage << fill;
}

void ViewRuntime::setupWindow() {
	using namespace windows_console;
	csl << window::title(sTxtTitle);

	csl << window::fit(consoleWidth, consoleHeight, sFontStyle, mRunningFontSize, mRunningFontRatio)
		<< window::unclosable
		<< window::unresizable
		<< window::center
		<< cursor::invisible;
	csl >> mImage;
	csl >> mBlankImage;
}

void ViewRuntime::drawTest() {
	using namespace windows_console;
	mImage << pen(dot, text_color(bright, red), background_color(dark, red))
		<< point(100, 100)
		<< brush(dot, text_color(dark, blue), background_color(dark, blue))
		<< rectangle(105, 105, 150, 150)
		<< no_brush
		<< circle(20, 20, 10)
		<< pen(dot, text_color(bright, yellow), background_color(dark, red))
		<< line(0, 0, 100, 100);
	csl << mImage;
}

void ViewRuntime::clearScreen() {
	using namespace windows_console;
	csl << mBlankImage;
}

void ViewRuntime::readInput() {
	using namespace windows_console;
	console_events ce;
	while (true) {
		ce.read_events();
		while (ce.key_events_count()) {
			switch (ce.next_key_event().ascii_value()) {
			case ' ':
				drawTest();
				break;
			case 'a':
			case 'A':
				clearScreen();
				break;
			}
		}
	}
}
