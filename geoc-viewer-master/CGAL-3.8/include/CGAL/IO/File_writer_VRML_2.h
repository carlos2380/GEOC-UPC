// Copyright (c) 1997  Utrecht University (The Netherlands),
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
// $URL: svn+ssh://scm.gforge.inria.fr/svn/cgal/trunk/Stream_support/include/CGAL/IO/File_writer_VRML_2.h $
// $Id: File_writer_VRML_2.h 56667 2010-06-09 07:37:13Z sloriot $
// 
//
// Author(s)     : Lutz Kettner  <kettner@mpi-sb.mpg.de>

#ifndef CGAL_IO_FILE_WRITER_VRML_2_H
#define CGAL_IO_FILE_WRITER_VRML_2_H 1

#include <CGAL/basic.h>
#include <iostream>
#include <cstddef>

namespace CGAL {

class File_writer_VRML_2 {
    std::ostream*      m_out;
    std::size_t        m_facets;
public:
    File_writer_VRML_2() {}
    std::ostream& out() const { return *m_out; }
    void write_header( std::ostream& o,
                       std::size_t vertices,
                       std::size_t halfedges,
                       std::size_t facets);
    void write_footer() const;
    void write_vertex( const double& x, const double& y, const double& z) {
        out() << "                                "
              << x << ' ' << y << ' ' << z << ',' << '\n';
    }
    void write_facet_header() const;
    void write_facet_begin( std::size_t) {
        out() << "                            ";
    }
    void write_facet_vertex_index( std::size_t idx) { out() << idx << ',';}
    void write_facet_end() { out() << "-1,\n"; }
};

} //namespace CGAL
#endif // CGAL_IO_FILE_WRITER_VRML_2_H //
// EOF //
