// Copyright (c) 2006 Foundation for Research and Technology-Hellas (Greece).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you may redistribute it under
// the terms of the Q Public License version 1.0.
// See the file LICENSE.QPL distributed with CGAL.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/trunk/Voronoi_diagram_2/include/CGAL/Regular_triangulation_adaptation_traits_2.h $
// $Id: Regular_triangulation_adaptation_traits_2.h 56667 2010-06-09 07:37:13Z sloriot $
// 
//
// Author(s)     : Menelaos Karavelas <mkaravel@iacm.forth.gr>

#ifndef CGAL_REGULAR_TRIANGULATION_ADAPTATION_TRAITS_2_H
#define CGAL_REGULAR_TRIANGULATION_ADAPTATION_TRAITS_2_H 1

#include <CGAL/Voronoi_diagram_2/basic.h>
#include <CGAL/Voronoi_diagram_2/Regular_triangulation_nearest_site_2.h>
#include <CGAL/Voronoi_diagram_2/Adaptation_traits_base_2.h>
#include <CGAL/Voronoi_diagram_2/Site_accessors.h>
#include <CGAL/Voronoi_diagram_2/Construct_dual_points.h>
#include <CGAL/Voronoi_diagram_2/Adaptation_traits_functors.h>

namespace CGAL {

template<class RT2>
struct Regular_triangulation_adaptation_traits_2
  : public CGAL_VORONOI_DIAGRAM_2_INS::Adaptation_traits_base_2
  <RT2,
   CGAL_VORONOI_DIAGRAM_2_INS::Point_accessor
   <typename RT2::Geom_traits::Point_2,RT2,Tag_true>,
   CGAL_VORONOI_DIAGRAM_2_INS::Regular_triangulation_Voronoi_point_2<RT2>,
   CGAL_VORONOI_DIAGRAM_2_INS::Regular_triangulation_nearest_site_2<RT2> >
{
  typedef typename RT2::Geom_traits::Point_2           Point_2;
  typedef typename RT2::Geom_traits::Weighted_point_2  Site_2;
};


} //namespace CGAL

#endif // CGAL_REGULAR_TRIANGULATION_ADAPTATION_TRAITS_2_H
