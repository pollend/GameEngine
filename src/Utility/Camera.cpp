#include "Utility/Camera.h"
#include "math.h"
#include "Utility/Matrix/MatrixStack.h"
#include "Utility/Matrix/MatrixHelper.h"

Camera::Camera(Matrix4f ViewMatrix)
{
	_viewMatrix= ViewMatrix;

	Position = Vector3f(0,0,0);
	Rotation  = Quaternionf();
}

Camera::Camera(float fov,float aspect, float zNear, float zFar)
{
	double lh = 1.0f/tan(fov/2.0f);
	_viewMatrix = Matrix4f();
	_viewMatrix <<
			lh/aspect,0,0,0,
			0,lh,0,0,
			0,0,(zFar+zNear)/(zNear-zFar),(2.0f*zFar*zNear)/( zNear-zFar ),
			0,0,-1,0;
	
	Position = Vector3f(0,0,0);
	Rotation  = Quaternionf();
}

Camera::Camera(float left, float top, float right, float bottom, float zNear,float zFar)
{
	_viewMatrix = Matrix4f();
	_viewMatrix << (2.0f/(right-left)),0,0,-((right+left)/(right-left)),
	0,(2.0f/(top-bottom)),0,-((top+bottom)/(top-bottom)),
	0,0,-(2.0f/(zFar-zNear)),-((zFar+zNear)/(zFar-zNear)),
	0,0,0,1;

	Position = Vector3f(0,0,0);
	Rotation  = Quaternionf();
}

Camera::~Camera(void)
{

}

Matrix4f Camera::GetMatrix()
{
	Matrix4f lposition = MatrixHelper::Translation(Position.reverse());
	Matrix4f lRotation = MatrixHelper::FromQuaternion(Rotation) ;

    return (lRotation * lposition);
}

Matrix4f Camera::GetTransformMatrixRelativeToNode(Node * node)
{
	MatrixStack lstack = MatrixStack();
	Node * lnode = node;
	while(lnode != NULL)
	{
		lstack.Push(lnode->GetMatrix());
		lnode = lnode->GetParent();
	}
	lstack.Push(GetMatrix());
	return lstack.GetReverseTransformMatrix();
}

Matrix4f Camera::GetViewMatrix()
{
	return _viewMatrix;
}
