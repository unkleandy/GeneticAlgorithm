#include <console.h>
#include "Canvas.h"
#include "RandomTools.h"


Canvas::Canvas(Rectangle const & rectangle, size_t obstacleCount)
	:
	mRect{ rectangle }
{
	set(Rectangle(0, 0, 300, 200), 20);
	mObstacles.resize(obstacleCount);
	randomizeObstacles();
}

bool const & Canvas::isValid() const{
	return mRect.isValid();
}

Rectangle const & Canvas::rectangle() const {
	return mRect;
}

std::vector<Point> const & Canvas::obstacles() const {
	return mObstacles;
}

void Canvas::set(Rectangle const & rectangle, size_t const & obstacleCount) {
	mRect = rectangle;
	setObstacles(obstacleCount);
}

void Canvas::setObstacles(size_t const & obstacleCount) {
	mObstacles.resize(obstacleCount);
}

int Canvas::generateRandomObstacleX() {
	return RandomTools::generateRandomNumber(static_cast<int>(mRect.topLeft().x()), static_cast<int>((mRect.topLeft().x() + mRect.size().width())));
}
int Canvas::generateRandomObstacleY() {
	return RandomTools::generateRandomNumber(static_cast<int>(mRect.topLeft().y()), static_cast<int>((mRect.topLeft().y() + mRect.size().height())));
}

void Canvas::generateRandomObstacle(Point & p) {
	p.set(generateRandomObstacleX(), generateRandomObstacleY());
}

void Canvas::randomizeObstacles() {
	for (Point & point : mObstacles) {
		generateRandomObstacle(point);
	}
}

void Canvas::drawObstacles(windows_console::image & anImage) const {
	using namespace windows_console;
	for (Point const & obstacle : mObstacles) {
		anImage << pen(dot, text_color(bright, yellow), background_color(dark, yellow))
			<< point(static_cast<int>(obstacle.x()), static_cast<int>(obstacle.y()));
	}

}
