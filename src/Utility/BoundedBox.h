#ifndef _BOUNDED_BOX_H_
#define _BOUNDED_BOX_H_

#include <Eigen/Dense>

using Eigen::Vector3f;
using Eigen::Vector2f;
using Eigen::Matrix4f;
using Eigen::Quaternionf;
class BoundedBox
{
public:
	Vector3f Position;
	Vector3f Size;

	/**
	 * creates a bound box for the postion and size
	 **/
	BoundedBox(Vector3f position, Vector3f Size);
	~BoundedBox(void);

	/** 
	*detects if two bounded boxes are intersecting 
	**/
	bool BoundedBoxIntersection(BoundedBox boundedBox);

	/** 
	*detects in the point is inside of a boundedBox. 
	**/
	bool IsBoundBoxContainPoint(Vector3f point);
};


#endif