#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <Node/Node.h>
#include <Eigen/Dense>

using Eigen::Vector3f;
using Eigen::Matrix4f;
using Eigen::Quaternionf;
class Camera : public Node
{
private:
	Matrix4f _viewMatrix;

public:
	Vector3f Position;
	Quaternionf Rotation;


	Camera(std::string ID,Matrix4f ViewMatrix);
	Camera(std::string ID,float fov,float aspect, float zNear, float zFar);
	Camera(std::string ID,float left, float top, float right, float bottom, float zNear,float zFar);

	~Camera(void);

	/** 
	*returns the transform matrix for the camera
	**/
	Matrix4f GetMatrix();
	/**
	*returns the transform for the matrix relative to the camera
	**/
	Matrix4f GetTransformMatrixRelativeToNode(Node * node);
	/**
	*gets the view matrix of the camera
	**/
	Matrix4f GetViewMatrix();
};

#endif
