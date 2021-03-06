// Copyright (c) 1999  Utrecht University (The Netherlands),
// ETH Zurich (Switzerland), Freie Universitaet Berlin (Germany),
// INRIA Sophia-Antipolis (France), Martin-Luther-University Halle-Wittenberg
// (Germany), Max-Planck-Institute Saarbruecken (Germany), RISC Linz (Austria),
// and Tel-Aviv University (Israel).  All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; version 2.1 of the License.
// See the file LICENSE.LGPL distributed with CGAL.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/trunk/Homogeneous_kernel/include/CGAL/Homogeneous/LineH2.h $
// $Id: LineH2.h 56667 2010-06-09 07:37:13Z sloriot $
// 
//
// Author(s)     : Stefan Schirra

#ifndef CGAL_LINEH2_H
#define CGAL_LINEH2_H

#include <CGAL/array.h>

namespace CGAL {

template < class R_ >
class LineH2
{
    typedef typename R_::FT                   FT;
    typedef typename R_::RT                   RT;
    typedef typename R_::Point_2              Point_2;
    typedef typename R_::Vector_2             Vector_2;
    typedef typename R_::Direction_2          Direction_2;
    typedef typename R_::Segment_2            Segment_2;
    typedef typename R_::Ray_2                Ray_2;
    typedef typename R_::Line_2               Line_2;

    typedef cpp0x::array<RT, 3>               Rep;
    typedef typename R_::template Handle<Rep>::type  Base;

    Base base;

public:

    typedef R_                                    R;

    LineH2() {}
    LineH2(const RT& a, const RT& b, const RT& c)
      : base(CGAL::make_array(a, b, c)) {}

    bool           operator==(const LineH2<R>& l) const;
    bool           operator!=(const LineH2<R>& l) const;

    const RT &     a() const { return get(base)[0]; }
    const RT &     b() const { return get(base)[1]; }
    const RT &     c() const { return get(base)[2]; }

};

template < class R >
CGAL_KERNEL_MEDIUM_INLINE
bool
LineH2<R>::operator==(const LineH2<R>& l) const
{
  if (  (a() * l.c() != l.a() * c() )
      ||(b() * l.c() != l.b() * c() ) )
  {
      return false;
  }
  int sc  = static_cast<int>(CGAL_NTS sign(c()));
  int slc = static_cast<int>(CGAL_NTS sign(l.c()));
  if ( sc == slc )
  {
      if (sc == 0)
          return (  (a()*l.b() == b()*l.a() )
                  &&(CGAL_NTS sign(a() )== CGAL_NTS sign( l.a() ))
                  &&(CGAL_NTS sign(b() )== CGAL_NTS sign( l.b() )) );
      else
          return true;
  }
  else
      return false;
}

template < class R >
inline
bool
LineH2<R>::operator!=(const LineH2<R>& l) const
{ return !(*this == l); }

} //namespace CGAL

#endif // CGAL_LINEH2_H
