// Copyright (c) 2003  INRIA Sophia-Antipolis (France).
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
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/trunk/Triangulation_3/include/CGAL/internal/Dummy_tds_3.h $
// $Id: Dummy_tds_3.h 51517 2009-08-26 12:52:38Z spion $
//
//
// Author(s)     : Sylvain Pion

#ifndef CGAL_INTERNAL_TRIANGULATION_DUMMY_TDS_3_H
#define CGAL_INTERNAL_TRIANGULATION_DUMMY_TDS_3_H

namespace CGAL { namespace internal {

// Dummy TDS which provides all types that a vertex_base or cell_base can use.
struct Dummy_tds_3 {
  struct Vertex {};
  struct Cell {};
  struct Facet {};
  struct Edge {};

  struct Vertex_handle {};
  struct Cell_handle {};

  struct Vertex_iterator {};
  struct Cell_iterator {};
  struct Facet_iterator {};
  struct Edge_iterator {};

  struct Cell_circulator {};
  struct Facet_circulator {};
};

}} // namespace CGAL::internal

#endif // CGAL_INTERNAL_TRIANGULATION_DUMMY_TDS_3_H
