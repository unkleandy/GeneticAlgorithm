#include "CircleMutationByGene.h"
#include "CircleSolution.h"
#include "ShapeCircle.h"
#include "RandomTools.h"
#include "Point2d.h"
#include "RandomTools.h"
#include <memory>


CircleMutationByGene::CircleMutationByGene()
{
}

void CircleMutationByGene::mutate(Solution & offspring)
{
	try {
		ShapeCircle * offspringCircle = new ShapeCircle();
		*offspringCircle = static_cast<ShapeCircle const &> ((static_cast<CircleSolution const &>(offspring)).shape());
		double centerx = abs(offspringCircle->center().x() + RandomTools::generateRandomNumber(-5, 5));
		double centery = abs(offspringCircle->center().y() + RandomTools::generateRandomNumber(-5, 5));
		size_t radius = offspringCircle->radius() + RandomTools::generateRandomNumber(1, 5);
		Point p;
		p.setX(centerx);
		p.setY(centery);
		offspringCircle->setCenter(p);
		offspringCircle->setRadius(radius);

		static_cast<CircleSolution &>(offspring).setShape(offspringCircle);
		
	}
	catch (int e) {}
}