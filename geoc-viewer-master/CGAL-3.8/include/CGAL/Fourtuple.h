// Copyright (c) 1999,2001  Utrecht University (The Netherlands),
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
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/trunk/STL_Extension/include/CGAL/Fourtuple.h $
// $Id: Fourtuple.h 56667 2010-06-09 07:37:13Z sloriot $
// 
//
// Author(s)     : Andreas Fabri

#ifndef CGAL_FOURTUPLE_H
#define CGAL_FOURTUPLE_H

#ifndef CGAL_NO_DEPRECATED_CODE

namespace CGAL {

template < class T >
struct Fourtuple
{
  typedef T value_type;

  T  e0, e1, e2, e3;

  Fourtuple() CGAL_DEPRECATED
  {}

  Fourtuple(const T & a0, const T & a1, const T & a2, const T & a3) CGAL_DEPRECATED
    : e0(a0), e1(a1), e2(a2), e3(a3)
  {}
};

} //namespace CGAL

#endif // CGAL_NO_DEPRECATED_CODE

#endif // CGAL_FOURTUPLE_H