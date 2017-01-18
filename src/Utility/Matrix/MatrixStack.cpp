#include "Utility/Matrix/MatrixStack.h"
#include <boost/log/trivial.hpp>

MatrixStack::MatrixStack(void)
{
	_matricies = std::list<Matrix4f>();
}

MatrixStack::~MatrixStack(void)
{
}

void MatrixStack::Push(const Matrix4f& matrix)
{
	_matricies.push_back(matrix);
}

Matrix4f MatrixStack::GetTransformMatrix()
{
	Matrix4f lfinal = Matrix4f();
	lfinal.setIdentity(4, 4);
	for (std::list<Matrix4f>::iterator it=_matricies.begin(); it != _matricies.end(); ++it)
	{
		lfinal = lfinal * (*it);
	}
	return lfinal;

}

Matrix4f MatrixStack::GetReverseTransformMatrix()
{
	Matrix4f lfinal;
	lfinal.setIdentity(4, 4);
	for (std::list<Matrix4f>::reverse_iterator it= _matricies.rbegin(); it != _matricies.rend(); ++it)
	{
		Matrix4f r = (*it);
		lfinal = lfinal * (*it);
	}
	return lfinal;
}

void MatrixStack::Pop()
{
	_matricies.pop_back();
}