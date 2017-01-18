#ifndef _MATRIX_STACK_H_
#define _MATRIX_STACK_H_

#include <list>
#include <Eigen/Dense>

using Eigen::Matrix4f;

class MatrixStack
{
private:
	//a stack of matricies
	 std::list<Matrix4f> _matricies;

public:

	MatrixStack(void);
	~MatrixStack(void);

	/**
	 *pushes on the stack
	 **/
	void Push(const Matrix4f& matrix);
	/**
	 * pop from the matrix stack
	 **/
	void Pop();
	
	/**
	*get the full transform set from beginning of the set to the end
	**/
	Matrix4f GetTransformMatrix();
	
	/**
	 * get the full transform set from the end of the set to the beginning
	 **/
	Matrix4f GetReverseTransformMatrix();

};

#endif