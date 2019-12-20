#include "CircleMutationByGene.h"
#include "CircleSolution.h"
#include "ShapeCircle.h"
#include "RandomTools.h"
#include "Point2d.h"
#include "RandomTools.h"


void CircleMutationByGene::mutate(Solution & offspring)
{
	ShapeCircle offspringCircle = static_cast<ShapeCircle const &> ((static_cast<CircleSolution const &>(offspring)).shape());

	double centerx = offspringCircle.center().x() + RandomTools::generateRandomNumber(-5, 5);
	double centery = offspringCircle.center().y() + RandomTools::generateRandomNumber(-5, 5);
	size_t radius = offspringCircle.radius() + RandomTools::generateRandomNumber(1, 5);
	Point p;
	p.setX(centerx);
	p.setY(centery);
	offspringCircle.setCenter(p);
	offspringCircle.setRadius(radius);

	static_cast<CircleSolution &>(offspring).setShape(&offspringCircle);

	offspring.encode();
}
