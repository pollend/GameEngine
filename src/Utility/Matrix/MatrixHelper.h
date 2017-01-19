//
// Created by michaelpollind on 1/18/17.
//

#ifndef _MATRIXHELPER_H
#define _MATRIXHELPER_H

#include <Eigen/Dense>


using Eigen::Matrix4f;
using Eigen::Matrix3f;
using Eigen::Vector3f;
using Eigen::Quaternionf;

class MatrixHelper {
    public:

    static Matrix4f Translation(Vector3f v);

    static Matrix4f RotationX(float amount);
    static Matrix4f RotationY(float amount);
    static Matrix4f RotationZ(float amount);

    static Matrix4f Scale(Vector3f scale);

    static Matrix4f Scale(float x, float y, float z);
    static Matrix4f FromQuaternion(Quaternionf q);
};


#endif //ASSIGMENT_3_MATRIXHELPER_H
