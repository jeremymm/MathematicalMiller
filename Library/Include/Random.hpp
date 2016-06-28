//***************************************************************************//
// Random Class Interface
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
namespace MST
{
  template <class T>
  class Random
  {
  private:
  public:
    Random();
    ~Random();

    T Generate();
    T Generate(T tMax);
    T Generate(T tMin, T tMax);
  };
} // End of namespace MST
//***************************************************************************//