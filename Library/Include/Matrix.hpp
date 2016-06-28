//***************************************************************************//
// Matrix Class Interface
//
// Created: April 6, 2007
// By: Jeremy M Miller
//
// Copyright (c) 2007 Jeremy Michael Miller. 
// Author: = "Jeremy Michael Miller"
// Copyright: = "Copyright 2006, Mathmatical Miller,  All rights reserved."
// Credits = ["Jeremy Michael Miller"]
// License: "Fair use v0.9"
// Version: "0.0.1"
// Maintainer: "Jeremy Michael Miller"
// Email: "maybe_later@mst.dnsalias.net"
// Status: "Alpha"
//***************************************************************************//

#ifndef MST_MATH_MATRIX_HPP
#define MST_MATH_MATRIX_HPP

#include "Vector.hpp"

//#define LEFT_HAND

//***************************************************************************//
namespace MST
{
  //*************************************************************************//
  template <class T, unsigned char D>
  class Matrix
  {
  private:
    //***********************************************************************//
    Vector<T, D> mtMatrix[D];
    //***********************************************************************//
  public:
    //***********************************************************************//
    //-----------------------------------------------------------------------//
    Matrix() { this->Identity(); }
    ~Matrix() {}
    //-----------------------------------------------------------------------//

    //-----------------------------------------------------------------------//
    // TODO Implement See Page 86 in Linear Algebra Book
    T Determinate() const;

    void Identity();
    void Zero();

    // TODO Test these
    void RotateAboutX(T& rtAngle);
    void RotateAboutY(T& rtAngle);
    void RotateAboutZ(T& rtAngle);
    void RotateAboutAxis(Vector<T, D>& rtAxis, T& rtAngle);

    // TODO Test these
    void Translate(T& rtX, T& rtY, T& rtZ);
    void Translate(Vector<T, D>& rtVector);

    // TODO Implement
    void Transpose();

    void Perspective(T tVerticalFOV, T tAspect, T tNearClipPlane, T tFarClipPlane);

    void ColumnMajor(T pArray[D * D]) const;
    void RowMajor(T pArray[D * D]) const;
    //-----------------------------------------------------------------------//

    //-----------------------------------------------------------------------//
    T operator()(unsigned char ucRow, unsigned char ucColumn) const;
    Vector<T, D>& operator[](unsigned char ucRow);
    Matrix<T, D> operator*(const Matrix<T, D>& rhs) const;  // Matrix Multiplication
    Matrix<T, D> operator*(const T& rhs) const;             // Scalar Multiplication
    Matrix<T, D> operator+(const Matrix<T, D>& rhs) const;  // Matrix Addition
    Matrix<T, D> operator-(const Matrix<T, D>& rhs) const;  // Matrix Subtraction
    //-----------------------------------------------------------------------//
    //***********************************************************************//
  }; // End of class Matrix
  //*************************************************************************//
} // End of namespace MST
//***************************************************************************//

#endif // MST_MATH_MATRIX_HPP
