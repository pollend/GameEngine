#include "Utility/BoundedBox.h"


BoundedBox::BoundedBox(Vector3f position, Vector3f size)
{
	Position = position;
	Size = size;
}


BoundedBox::~BoundedBox(void)
{
}


bool BoundedBox::BoundedBoxIntersection(BoundedBox boundedBox)
{
	return !(Position.x() < boundedBox.Position.x() + boundedBox.Size.x() || Position.x() + Size.x() < boundedBox.Position.x() ||
    Position.y() < boundedBox.Position.y() + boundedBox.Size.y() || Position.y() + Size.y() < boundedBox.Position.y() ||
    Position.z() < boundedBox.Position.z() + boundedBox.Size.z() || Position.z() + Size.z() < boundedBox.Position.z());

}
bool BoundedBox::IsBoundBoxContainPoint(Vector3f point)
{
	return Position.x() > point.x() && Position.x() + Size.x() < point.x() &&
    Position.y() > point.y() && Position.y() + Size.y() < point.y() &&
    Position.z() > point.z() && Position.z() + Size.z() < point.z();
}
