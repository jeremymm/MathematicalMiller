//***************************************************************************//
// Vector Class Implementation
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
//***************************************************************************//

#include "Vector.hpp"
#include "Matrix.hpp"

#include <math.h>

namespace MST
{
  //*************************************************************************//
  // Explicit instantiations
  template class Vector<float, 2>;
  template class Vector<float, 3>; 
  template class Vector<float, 4>; 
  template class Vector<double, 2>;
  template class Vector<double, 3>;
  template class Vector<double, 4>;
  //*************************************************************************//

  //*************************************************************************//
  template <class T, unsigned char D>
  Vector<T, D> Vector<T, D>::operator+(const Vector<T, D>& rhs) const
  {
    Vector<T,D> tTempVector;
    for(unsigned char i = 0; i < D; i++)
    {
      tTempVector[i] = this->mtaComponent[i] + rhs.mtaComponent[i];
    }
    return tTempVector;
  }
  //*************************************************************************//

  //*************************************************************************//
  template <class T, unsigned char D>
  Vector<T, D> Vector<T, D>::operator-(const Vector<T, D>& rhs) const
  {
    Vector<T,D> tTempVector;
    for(unsigned char i = 0; i < D; i++)
    {
      tTempVector[i] = this->mtaComponent[i] - rhs.mtaComponent[i];
    }
    return tTempVector;
  }
  //*************************************************************************//

  //*************************************************************************//
  template <class T, unsigned char D>
  void Vector<T, D>::Cross(const Vector<T, D>& rVector1, const Vector<T, D>& rVector2)
  {
    assert(D >= 3);
    if(D >= 3)
    {
      this->mtaComponent[0] = (rVector2.mtaComponent[1] * rVector1.mtaComponent[2]) - 
        rVector2.mtaComponent[2] * rVector1.mtaComponent[1];
      this->mtaComponent[1] = rVector2.mtaComponent[2] * rVector1.mtaComponent[0] - 
        rVector2.mtaComponent[0] * rVector1.mtaComponent[2];
      this->mtaComponent[2] = rVector2.mtaComponent[0] * rVector1.mtaComponent[1] - 
        rVector2.mtaComponent[1] * rVector1.mtaComponent[0];
    }

    //Vector res;
    //res.x = (y * v.z) - (z * v.y);
    //res.y = (z * v.x) - (x * v.z);
    //res.z = (x * v.y) - (y * v.x);
    //return res;
    return;
  }
  //*************************************************************************//

  //*************************************************************************//
  template <class T, unsigned char D>
  T Vector<T, D>::Dot(const Vector<T, D>& rInput) const
  {
    T tResult = 0.0;

    for(unsigned char i = 0; i < D; i++)
      tResult += this->mtaComponent[i] * rInput.mtaComponent[i];

    return tResult;
  }
  //*************************************************************************//

  //*************************************************************************//
  template<class T, unsigned char D>
  T Vector<T, D>::Magnitude() const
  { 
    T tSum = 0.0;
    for(unsigned char d = 0; d < D; d++)
      tSum += (this->mtaComponent[d] * this->mtaComponent[d]);

    return sqrt(tSum);
  }
  //*************************************************************************//

  //*************************************************************************//
  template<class T, unsigned char D>
  void Vector<T, D>::Normalize()
  {
    T tMagnitude = this->Magnitude();
    for(unsigned char d = 0; d < D; d++)
      this->mtaComponent[d] /= tMagnitude;
  }
  //*************************************************************************//

  //*************************************************************************//
  template<class T, unsigned char D>
  void Vector<T, D>::Transform(Matrix<T,D>& rMatrix)
  {
    Vector<T, D> tTempVector;
    for(unsigned char i = 0; i < D; i++)
    {
      tTempVector[i] = rMatrix[i].Dot(*this);
    }
    *this = tTempVector;
  }
  //*************************************************************************//
}
//***************************************************************************//