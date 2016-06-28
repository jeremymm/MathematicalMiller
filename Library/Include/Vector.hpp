//***************************************************************************//
// Vector Class Interface
//
// Created: April 3, 2007
// By: Jeremy M Miller
//
// Author: = "Jeremy Michael Miller"
// Copyright: = "Copyright 2007, Mathmatical Miller,  All rights reserved."
// Credits = ["Jeremy Michael Miller"]
// License: "Fair use v0.9"
// Version: "0.0.1"
// Maintainer: "Jeremy Michael Miller"
// Email: "maybe_later@mst.dnsalias.net"
// Status: "Alpha"
//***************************************************************************//

#ifndef MST_MATH_VECTOR_HPP
#define MST_MATH_VECTOR_HPP

#include "Point.hpp"

//***************************************************************************//
namespace MST
{
  //*************************************************************************//
  template <class T, unsigned char  D> class Matrix;
  //*************************************************************************//

  //*************************************************************************//
  template <class T, unsigned char  D>
  class Vector : public Point<T, D>
  {
  private:
  public:
    Vector()  {}
    ~Vector() { Point<T,D>::~Point(); } // Calling base class's destructor since base
                                   // class's destructor is not virtual for
                                   // performance reasons.

    void Cross(const Vector<T, D>& rVector1, const Vector<T, D>& rVector2);

    T Dot(const Vector<T,D>& rInput) const;

    T Magnitude() const;
    void Normalize();


    T operator()(unsigned char ucIndex) const
    {
      assert(ucIndex < D);

      if(ucIndex < D)
        return Point<T,D>::mtaComponent[ucIndex];
      return Point<T,D>::mtaComponent[D - 1];
    }

    T& operator[](unsigned char ucIndex)
    {
      assert(ucIndex < D);

      if(ucIndex < D)
        return Point<T,D>::mtaComponent[ucIndex];
      return Point<T,D>::mtaComponent[D - 1];
    }

    Vector<T,D> operator+(const Vector<T,D>& rhs) const;
    Vector<T,D> operator-(const Vector<T,D>& rhs) const;
    Vector<T,D> operator*(const T& rhs) const
    {

      Vector<T,D> tTempVector;
      for(unsigned char i = 0; i < D; i++)
      {
        tTempVector[i] = Point<T,D>::mtaComponent[i] * rhs;
      }
      return tTempVector;
    }
    Vector<T,D> operator/(const T& rhs) const
    {
      Vector<T,D> tTempVector;
      for(unsigned char i = 0; i < D; i++)
      {
        tTempVector[i] = Point<T,D>::mtaComponent[i] / rhs;
      }
      return tTempVector;
    }

    void Transform(Matrix<T,D>& rMatrix);
    void Clear()
    {
      for(unsigned char i = 0; i < D; i++)
      {
        Point<T,D>::mtaComponent[i] = 0.0;
      }
    }
  }; // End of class Vector
  //*************************************************************************//
} // End of namespace MST
//***************************************************************************//

#endif // MST_MATH_VECTOR_HPP
