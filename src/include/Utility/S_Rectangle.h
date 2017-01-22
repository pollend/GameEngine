#ifndef _SHADER_H_
#define _SHADER_H_
#include <Eigen/Dense>


using Eigen::Matrix4f;
using Eigen::Matrix3f;
using Eigen::Vector3f;
using Eigen::Vector2f;
using Eigen::Quaternionf;
class S_Rectangle
{
public:
	Vector2f Position;
	Vector2f Size;

	S_Rectangle();
	S_Rectangle(Vector2f position, Vector2f size);
	~S_Rectangle(void);
	/**
	*check if two rectangles are intersecting
	**/
	bool RectangleIntersection(S_Rectangle r);
	/**
	*tells if a point is in a rectangle
	**/
	bool IsPointContainedInRectangle(Vector2f point);
};

#endif