// Copyright (c) 2000  Max-Planck-Institute Saarbruecken (Germany).
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
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/trunk/Partition_2/include/CGAL/Partition_2/Iterator_list.h $
// $Id: Iterator_list.h 56107 2010-05-11 07:12:41Z afabri $
// 
//
// Author(s)     : Susan Hert <hert@mpi-sb.mpg.de>

#ifndef CGAL_ITERATOR_LIST_H
#define CGAL_ITERATOR_LIST_H

#include <list>

namespace CGAL {

template <class Iterator>
class Iterator_list : public std::list<Iterator> {

public:
  Iterator_list() {}

  Iterator_list(Iterator first, Iterator beyond) 
  {
      if (first == beyond) return;

      for (Iterator current = first; current != beyond; current++)
      {
         this->push_back(current);
      } 
  }
};

}

#endif // CGAL_ITERATOR_LIST_H
