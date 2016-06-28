//***************************************************************************//
// Vector Class Interface
//
// Created: April 3, 2007
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

#ifndef MST_MATH_FIBONACCI_HPP
#define MST_MATH_FIBONACCI_HPP

#include <iostream>

namespace MST
{
  class Fibonacci
  {
  private:
  public:
    Fibonacci();
    ~Fibonacci();

    static void* Generate(void* ulEnd/*, std::ostream& ostmOutput, char cSeperator = ' '*/);
  };
}

#endif // MST_MATH_FIBONACCI_HPP
