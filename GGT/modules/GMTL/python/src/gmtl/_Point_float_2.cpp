/*************** <auto-copyright.pl BEGIN do not edit this line> **************
 *
 * PyJuggler is (C) Copyright 2002, 2003 by Patrick Hartling
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 * -----------------------------------------------------------------
 * File:          $RCSfile: _Point_float_2.cpp,v $
 * Date modified: $Date: 2005-06-05 00:48:52 $
 * Version:       $Revision: 1.4 $
 * -----------------------------------------------------------------
 *
 *************** <auto-copyright.pl END do not edit this line> ***************/


// Includes ====================================================================
#include <boost/python.hpp>
#include <gmtl/Point.h>
#include <gmtl-pickle.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
void _Export_Point_float_2()
{
    scope* gmtl_Point_float_2_scope = new scope(
    class_< gmtl::Point<float,2>, bases< gmtl::VecBase<float,2> > >("Point2f", init<  >())
        .def(init< const gmtl::Point<float,2> & >())
        .def(init< const gmtl::VecBase<float,2> & >())
        .def(init< const gmtl::VecBase<float,2,gmtl::meta::VecBinaryExpr<gmtl::VecBase<float,2>, gmtl::VecBase<float,2>, gmtl::meta::VecPlusBinary> > & >())
        .def(init< const gmtl::VecBase<float,2,gmtl::meta::VecBinaryExpr<gmtl::VecBase<float,2>, gmtl::VecBase<float,2>, gmtl::meta::VecMinusBinary> > & >())
        .def(init< const gmtl::VecBase<float,2,gmtl::meta::VecBinaryExpr<gmtl::VecBase<float,2>, gmtl::VecBase<float,2>, gmtl::meta::VecMultBinary> > & >())
        .def(init< const gmtl::VecBase<float,2,gmtl::meta::VecBinaryExpr<gmtl::VecBase<float,2>, gmtl::VecBase<float,2>, gmtl::meta::VecDivBinary> > & >())
        .def(init< const gmtl::VecBase<float,2,gmtl::meta::VecBinaryExpr<gmtl::VecBase<float,2>, gmtl::VecBase<float,2,gmtl::meta::ScalarArg<float> >, gmtl::meta::VecMultBinary> > & >())
        .def(init< const gmtl::VecBase<float,2,gmtl::meta::VecBinaryExpr<gmtl::VecBase<float,2>, gmtl::VecBase<float,2,gmtl::meta::ScalarArg<float> >, gmtl::meta::VecDivBinary> > & >())
        .def(init< const float &, const float & >())
        .def_pickle(gmtlPickle::Point2_pickle<float>())
    );

    enum_< gmtl::Point<float,2>::Params >("Params")
        .value("Size", gmtl::Point<float,2>::Size)
    ;

    delete gmtl_Point_float_2_scope;

}