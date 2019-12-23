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
{	//hardcode mais c'est pour empecher le losange ou le rectangle d'utiliser un mutateur qui ne fonctionne que pour le cercle
	if (offspring.chromosome().size() == 24) {
		ShapeCircle  & c{ static_cast<ShapeCircle  &> ((static_cast<CircleSolution  &>(offspring)).shape()) };
		double centerx = abs(c.center().x() + RandomTools::generateRandomNumber(-4, 4));
		double centery = abs(c.center().y() + RandomTools::generateRandomNumber(-4, 4));
		size_t radius = static_cast<size_t>(c.radius()) + static_cast<size_t>(RandomTools::generateRandomNumber(1, 4));
		static_cast<ShapeCircle  &> ((static_cast<CircleSolution  &>(offspring)).shape()).set(Point(centerx, centery), radius);
	}
}
