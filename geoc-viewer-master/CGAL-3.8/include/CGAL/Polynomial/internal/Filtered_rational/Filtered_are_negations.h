// Copyright (c) 2005  Stanford University (USA).
// All rights reserved.
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
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/trunk/Kinetic_data_structures/include/CGAL/Polynomial/internal/Filtered_rational/Filtered_are_negations.h $
// $Id: Filtered_are_negations.h 56668 2010-06-09 08:45:58Z sloriot $
// 
//
// Author(s)     : Daniel Russel <drussel@alumni.princeton.edu>

#ifndef CGAL_POLYNOMIAL_INTERNAL_FILTERED_ARE_NEGATIONS_H
#define CGAL_POLYNOMIAL_INTERNAL_FILTERED_ARE_NEGATIONS_H

#include <CGAL/Polynomial/basic.h>

namespace CGAL { namespace POLYNOMIAL { namespace internal {

//------------------------------------------------------------------
template <class P>
class Filtered_are_negations
{
    public:
        typedef typename P::NT NT;
        typedef P first_argument_type;
        typedef P second_argument_type;
        typedef bool result_type;
        Filtered_are_negations(){}

        result_type operator()(const first_argument_type &f0,
            const second_argument_type &f1) const
        {
            for (int i=(std::max)(f0.interval_function().degree(), f1.interval_function().degree()); i>=0; --i) {
                if (!f0.interval_function()[i].do_overlap(-f1.interval_function()[i])) return false;
            }
            if (f0.exact_function().degree() != f1.exact_function().degree()) return false;
            else for (int i=0; i<= f0.exact_function().degree(); ++i) {
                if (f0.exact_function()[i] != -f1.exact_function()[i]) return false;
            }
            return true;
        }
};

} } } //namespace CGAL::POLYNOMIAL::internal
#endif
