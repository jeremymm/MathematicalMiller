//***************************************************************************//
// Random Class Implementation
//
// Created: April 14, 2007
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

//***************************************************************************//
#include "Random.hpp"
//***************************************************************************//

//***************************************************************************//
#include <assert.h>
#include <stdlib.h>
#include <time.h>
//***************************************************************************//

//***************************************************************************//
namespace MST
{
  //-------------------------------------------------------------------------//
  // To see why I do this you can visit this site http://www.bluehabu.com/?p=8
  // TODO rational types do not work.
  //template class Random<unsigned char>;
  //template class Random<char>;
  //template class Random<unsigned short>;
  //template class Random<short>;
  //template class Random<unsigned long>;
  //template class Random<long>;
  //template class Random<unsigned long long>;
  //template class Random<long long>;
  template class Random<float>;
  template class Random<double>;
  template class Random<long double>;
  //-------------------------------------------------------------------------//

  //-------------------------------------------------------------------------//
  template <class T>
  Random<T>::Random()
  {
    // TODO Come up with a better seed generation.
    srand(rand() * time(0)); 
  }
  //-------------------------------------------------------------------------//

  //-------------------------------------------------------------------------//
  template <class T>
  Random<T>::~Random()
  {
  }
  //-------------------------------------------------------------------------//

  //-------------------------------------------------------------------------//
  template <class T>
  T Random<T>::Generate()
  {
    return rand()/T(RAND_MAX); 
  }
  //-------------------------------------------------------------------------//

  //-------------------------------------------------------------------------//
  template <class T>
  T Random<T>::Generate(T tMax)
  {
    return (T)(tMax * rand()/T(RAND_MAX));
  }
  //-------------------------------------------------------------------------//

  //-------------------------------------------------------------------------//
  template <class T>
  T Random<T>::Generate(T tMin, T tMax)
  {
    assert(tMin < tMax);  // Why is your min greater or equal to your max
    if(tMin > tMax)
    {
      return tMax + T((tMin - tMax) * rand()/T(RAND_MAX)); 
    }
    return tMin + T((tMax - tMin) * rand()/T(RAND_MAX));
  }
  //-------------------------------------------------------------------------//
} // End of namespace MST
//***************************************************************************//
