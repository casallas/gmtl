// GMTL is (C) Copyright 2001-2011 by Allen Bierbaum
// Distributed under the GNU Lesser General Public License 2.1 with an
// addendum covering inlined code. (See accompanying files LICENSE and
// LICENSE.addendum or http://www.gnu.org/copyleft/lesser.txt)

// This file was originally part of PyJuggler.

// PyJuggler is (C) Copyright 2002, 2003 by Patrick Hartling
// Distributed under the GNU Lesser General Public License 2.1.  (See
// accompanying file COPYING.txt or http://www.gnu.org/copyleft/lesser.txt)

// Includes ====================================================================
#include <boost/python.hpp>
#include <gmtl/VecBase.h>
#include <gmtl/Output.h>
#include <gmtl-wrappers.h>
#include <gmtl-array-wrappers.h>
#include <gmtl-getData-wrappers.h>
#include <gmtl-pickle.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
void _Export_VecBase_int_3()
{
    scope* gmtl_VecBase_int_3_scope = new scope(
    class_< gmtl::VecBase<int,3> >("VecBase3i", init<  >())
        .def(init< const gmtl::VecBase<int,3> & >())
        .def(init< const int &, const int &, const int & >())
        .def("set", (void (gmtl::VecBase<int,3>::*)(const int &, const int &, const int &) )&gmtl::VecBase<int,3>::set)
        .def("set", (void (*)(gmtl::VecBase<int,3>*, list))&gmtlWrappers::VecBase_set)
        .def("set",
             (gmtl::VecBase<int, 3>& (gmtl::VecBase<int, 3>::*)(const gmtl::VecBase<int, 3>&)) &gmtl::VecBase<int, 3>::operator=,
             return_internal_reference<1>())
        .def("getData", (tuple (*)(gmtl::VecBase<int,3>*)) &gmtlWrappers::VecBase_3_getData)
        .add_property("data", (tuple (*)(gmtl::VecBase<int,3>*)) &gmtlWrappers::VecBase_3_getData)
        .def("__getitem__", (int& (gmtl::VecBase<int,3>::*)(const unsigned) ) &gmtl::VecBase<int,3>::operator[], return_value_policy<copy_non_const_reference>())
        .def("__setitem__", (void (*)(gmtl::VecBase<int,3>*, const unsigned, int)) &gmtlWrappers::setArrayElement)
        .def_pickle(gmtlPickle::VecBase3_pickle<int>())
        .def(-self)
        .def(self += self)
        .def(self + self)
        .def(self -= self)
        .def(self - self)
        .def(self *= int())
        .def(self * int())
        .def(int() * self)
        .def(self /= int())
        .def(self / int())
        .def(self == self)
        .def(self != self)
        .def(self_ns::str(self))
    );

    enum_< gmtl::VecBase<int,3>::Params >("Params")
        .value("Size", gmtl::VecBase<int,3>::Size)
    ;

    delete gmtl_VecBase_int_3_scope;

}
