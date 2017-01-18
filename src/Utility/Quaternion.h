#ifndef _QUATERNION_H_
#define _QUATERNION_H_

#include <Utility/Matrix/Matrix4x4.h>

class Quaternion
{
private:

public:
	float X;
	float Y;
	float Z;
	float W;

	Quaternion(void);
	/*
	*Euler Angles are used to convert the base number to a quaternion base
	*/
	Quaternion(float yaw, float roll, float pitch);
	
	/*
	*straight values can be inputed if need be
	*/
	Quaternion(float x, float y, float z, float w);
	~Quaternion(void);

	/*
	*converts a quanterion to a matrix
	*/
	Matrix4x4 ConvertToMatrix();
};


#endif