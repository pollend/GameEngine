//
// Created by michaelpollind on 1/18/17.
//

#include "MatrixHelper.h"

Matrix4f MatrixHelper::Translation(Vector3f v) {

    Matrix4f c;
    c << 1,0,0,0,
         0,1,0,0,
         0,0,1,0,
         v[0],v[1],v[2],1;
    return c;
}

Matrix4f MatrixHelper::RotationX(float amount) {
    Matrix4f c;
    c << 1,0,0,0,
         0,cos(amount),sin(amount),0,
         0,-sin(amount),cos(amount),0,
         0,0,0,1;
    return c;
}

Matrix4f MatrixHelper::RotationY(float amount) {
    Matrix4f c;
    c << cos(amount),0,-sin(amount),0,
            0,1,0,0,
            sin(amount),0,cos(amount),0,
            0,0,0,1;
    return c;
}

Matrix4f MatrixHelper::RotationZ(float amount) {
    Matrix4f c;
    c << cos(amount),sin(amount),0,0,
        -sin(amount),cos(amount),0,0,
        0,0,1,0,
        0,0,0,1;
    return c;
}

Matrix4f MatrixHelper::Scale(float x, float y, float z) {
    Matrix4f c;
    c << x,0,0,0,
         0,y,0,0,
         0,0,z,0,
         0,0,0,1;
    return c;
}

Matrix4f MatrixHelper::Scale(Vector3f scale) {
    Matrix4f c;
    c << scale[0],0,0,0,
         0,scale[1],0,0,
         0,0,scale[2],0,
         0,0,0,1;
    return c;
}

Matrix4f MatrixHelper::FromQuaternion(Quaternionf q) {
    Matrix3f temp =  q.toRotationMatrix();
    Matrix4f final = Matrix4f::Identity();
    final.block(0,0,3,3) = temp;
    return final;
}

