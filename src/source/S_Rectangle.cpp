#include "Utility/S_Rectangle.h"

S_Rectangle::S_Rectangle()
{
}


S_Rectangle::S_Rectangle(Vector2f position, Vector2f size)
{
	Position = position;
	Size = size;

}

bool S_Rectangle::RectangleIntersection(S_Rectangle r)
{
	return !(Position.x() < r.Position.x() + r.Size.x() || Position.x() + Size.x() > r.Position.x() || Position.y() < r.Position.y() + r.Size.y() || Position.y() + Size.y() > r.Position.y());
}

bool S_Rectangle::IsPointContainedInRectangle(Vector2f point)
{
	return Position.x() > point.x() && Position.x() + Size.x() < point.x() && Position.y() > point.y() && Position.y() + Size.y() < point.y();
}


S_Rectangle::~S_Rectangle(void)
{
}
