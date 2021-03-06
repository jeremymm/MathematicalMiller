//***************************************************************************//
// Point Class Interface
//
// Created: April 6, 2007
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

#ifndef MST_MATH_POINT_HPP
#define MST_MATH_POINT_HPP

#include <assert.h>
#include <memory.h>

//***************************************************************************//
namespace MST
{
  //*************************************************************************//
  // Point class. NOTE the lack of virtual methods including the non-virtual
  // destructor.  This because I want to be able to have many Point objects
  // without wasting 4 bytes on the vtable pointer.  Therefore, object derived
  // from this object must call Point's destructor explicitly.
  template <class T, unsigned char D>
  class Point
  {
  private:
    //***********************************************************************//
    //***********************************************************************//
  protected:
    //***********************************************************************//
    // This array stores information about the current position of the point
    // mtaComponent[0] => X
    // mtaComponent[1] => Y
    // mtaComponent[2] => Z
    // mtaComponent[3] => W
    T mtaComponent[D];
    //***********************************************************************//
  public:
    //***********************************************************************//
    //-----------------------------------------------------------------------//
    // Contructor sets all the coordinates to zero or the orgin
    Point() { memset(&mtaComponent, 0L, sizeof(T) * D); }
    // TODO Bounds check
    Point(float fX, float fY, float fZ, float fW) { mtaComponent[0] = fX; mtaComponent[1] = fY; mtaComponent[2] = fZ; mtaComponent[3] = fW; }
    ~Point() {}  // NOTE: non-virtual. See the comment on top of this class declaration.
    //-----------------------------------------------------------------------//

    //-----------------------------------------------------------------------//
    void Get(T& Xout, T& Yout, T& Zout)
    {
      Xout = mtaComponent[0];
      Yout = mtaComponent[1];
      if(D > 2)
        Zout = mtaComponent[2];
    }
    void Set(T Xin, T Yin, T Zin)
    {
      mtaComponent[0] = Xin;
      mtaComponent[1] = Yin;
      if(D > 2)
        mtaComponent[2] = Zin;
    }
    //-----------------------------------------------------------------------//

    //-----------------------------------------------------------------------//
    // These methods return the coordinates of the current position
    T& rX()  {return mtaComponent[0];} // Returns X
    T& rY()  {return mtaComponent[1];} // Returns Y
    T& rZ()  {return mtaComponent[2];} // Returns Z

    T X() const {return mtaComponent[0];} // Returns X
    T Y() const {return mtaComponent[1];} // Returns Y
    T Z() const {return mtaComponent[2];} // Returns Z
    //-----------------------------------------------------------------------//

    //-----------------------------------------------------------------------//
    // These methods set the coordinates of the point
    void rX(T& Xin) {mtaComponent[0] = Xin;} // Sets X
    void rY(T& Yin) {mtaComponent[1] = Yin;} // Sets Y
    void rZ(T& Zin) {mtaComponent[2] = Zin;} // Sets Z

    void X(T Xin) {mtaComponent[0] = Xin;} // Sets X
    void Y(T Yin) {mtaComponent[1] = Yin;} // Sets Y
    void Z(T Zin) {mtaComponent[2] = Zin;} // Sets Z
    //-----------------------------------------------------------------------//

    //-----------------------------------------------------------------------//
    T& operator[](unsigned char ucIndex)
    {
      assert(ucIndex < D);

      if(ucIndex < D)
        return mtaComponent[ucIndex];
      return mtaComponent[D - 1];
    }
    //-----------------------------------------------------------------------//

    //-----------------------------------------------------------------------//
    Point<T, D>& operator=(const Point<T, D>& rhs)
    {
      memcpy(&mtaComponent, &rhs.mtaComponent, D * sizeof(T));
      return *this;
    }
    //-----------------------------------------------------------------------//
    //***********************************************************************//
  };
  //*************************************************************************//
}
//***************************************************************************//

#endif // MST_MATH_POINT_HPP
