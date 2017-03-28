// Copyright (c) 1997-2001  Utrecht University (The Netherlands),
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
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/trunk/Random_numbers/src/CGAL/Random.cpp $
// $Id: Random.cpp 58582 2010-09-09 09:52:00Z afabri $
// 
//
// Author(s)     : Sven Sch�nherr <sven@inf.ethz.ch>

#include <CGAL/Random.h>
#include <ctime>
#include <sstream>

namespace CGAL {

// Class implementation (continued)
// ================================

// constructors
Random::
Random( )
    :  val(0)
{
    // get system's time
    std::time_t s;
    std::time( &s);
    seed = (unsigned int)s;

    // initialize random numbers generator
    rng.seed(static_cast<boost::int32_t>(seed));
    random_value = get_int(0, 1<<15);
}

Random::
Random( unsigned int  seed)
    : val(0), seed(seed)
{
    // initialize random numbers generator
    rng.seed(static_cast<boost::int32_t>(seed));
    random_value = get_int(0, 1<<15);
}

// seed
unsigned int
Random::get_seed () const
{ 
  return seed; 
}

// state
void 
Random::save_state( Random::State& state) const
{
  std::ostringstream os;
  os << rng;
  state = Random::State(os.str(),random_value, val, seed);
}

void 
Random::restore_state( const Random::State& state)
{
  std::istringstream is(state.rng);
  is >> rng;
  random_value = state.random_value;
  val = state.val;
  seed = state.seed;
}

// Global variables
// ================
Random  default_random;

} //namespace CGAL