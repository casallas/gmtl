/************************************************************** ggt-head beg
 *
 * GGT: Generic Graphics Toolkit
 *
 * Original Authors:
 *   Allen Bierbaum
 *
 * -----------------------------------------------------------------
 * File:          $RCSfile: IntersectionTest.cpp,v $
 * Date modified: $Date: 2002-08-06 21:08:48 $
 * Version:       $Revision: 1.2 $
 * -----------------------------------------------------------------
 *
 *********************************************************** ggt-head end */
/*************************************************************** ggt-cpr beg
*
* GGT: The Generic Graphics Toolkit
* Copyright (C) 2001,2002 Allen Bierbaum
*
* This library is free software; you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public
* License as published by the Free Software Foundation; either
* version 2.1 of the License, or (at your option) any later version.
*
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
* Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public
* License along with this library; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*
 ************************************************************ ggt-cpr end */
#include "IntersectionTest.h"
#include <cppunit/extensions/MetricRegistry.h>

#include <gmtl/Intersection.h>

namespace gmtlTest
{
   void IntersectionTest::testIntersectAABoxAABox()
   {
      // Test overlapping boxes
      {
         gmtl::AABoxf box1(gmtl::Point3f(-1,-1,-1), gmtl::Point3f(1,1,1));
         gmtl::AABoxf box2(gmtl::Point3f(0,0,0), gmtl::Point3f(2,2,2));
         CPPUNIT_ASSERT(gmtl::intersect(box1, box2));
      }

      // Test boxes with shared edge
      {
         gmtl::AABoxf box1(gmtl::Point3f(-1,-1,-1), gmtl::Point3f(0,0,0));
         gmtl::AABoxf box2(gmtl::Point3f(0,0,0), gmtl::Point3f(-1,-1,-1));
         CPPUNIT_ASSERT(gmtl::intersect(box1, box2));
      }

      // Test non-overlapping boxes
      {
         gmtl::AABoxf box1(gmtl::Point3f(-2,-2,-2), gmtl::Point3f(-1,-1,-1));
         gmtl::AABoxf box2(gmtl::Point3f(1,1,1), gmtl::Point3f(2,2,2));
         CPPUNIT_ASSERT(! gmtl::intersect(box1, box2));
      }
   }

   void IntersectionTest::testTimingIntersectAABoxAABox()
   {
      gmtl::AABoxf box1(gmtl::Point3f(-1,-1,-1), gmtl::Point3f(1,1,1));
      gmtl::AABoxf box2(gmtl::Point3f(0,0,0), gmtl::Point3f(2,2,2));
      const long iters(400000);
      unsigned true_count(0);
      CPPUNIT_METRIC_START_TIMING();

      for(long iter=0;iter<iters; ++iter)
      {
         if (gmtl::intersect(box1, box2))
         {
            ++true_count;
         }
         box2.mMax[0] += 0.01;
      }

      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("IntersectionTest/IntersectAABoxAABox", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%

      CPPUNIT_ASSERT(true_count > 0.0f);
   }
   
   
   
   void IntersectionTest::testIntersectAABoxPoint()
   {
      // Test point in box
      {
         gmtl::AABoxf box1(gmtl::Point3f(-1,-1,-1), gmtl::Point3f(1,1,1));
         gmtl::Point3f point(gmtl::Point3f(0,0,0));
         CPPUNIT_ASSERT(gmtl::intersect(box1, point));
      }

      //////////
      
      // test point on edge (bottom face)
      {
         gmtl::AABoxf box1(gmtl::Point3f(-1,-1,-1), gmtl::Point3f(0,0,0));
         gmtl::Point3f point(gmtl::Point3f(-0.5f,-1,-0.5f));
         CPPUNIT_ASSERT(gmtl::intersect(box1, point));
      }
      // test point on edge (top face)
      {
         gmtl::AABoxf box1(gmtl::Point3f(-1,-1,-1), gmtl::Point3f(0,0,0));
         gmtl::Point3f point(gmtl::Point3f(-0.5f,0,-0.5f));
         CPPUNIT_ASSERT(gmtl::intersect(box1, point));
      }
      // test point on edge (left face)
      {
         gmtl::AABoxf box1(gmtl::Point3f(-1,-1,-1), gmtl::Point3f(0,0,0));
         gmtl::Point3f point(gmtl::Point3f(-1.0f,-0.5,-0.5f));
         CPPUNIT_ASSERT(gmtl::intersect(box1, point));
      }
      // test point on edge (right face)
      {
         gmtl::AABoxf box1(gmtl::Point3f(-1,-1,-1), gmtl::Point3f(0,0,0));
         gmtl::Point3f point(gmtl::Point3f(0.0f,-0.5,-0.5f));
         CPPUNIT_ASSERT(gmtl::intersect(box1, point));
      }
      // test point on edge (near face)
      {
         gmtl::AABoxf box1(gmtl::Point3f(-1,-1,-1), gmtl::Point3f(0,0,0));
         gmtl::Point3f point(gmtl::Point3f(-0.5f,-0.5,0.0f));
         CPPUNIT_ASSERT(gmtl::intersect(box1, point));
      }
      // test point on edge (far face)
      {
         gmtl::AABoxf box1(gmtl::Point3f(-1,-1,-1), gmtl::Point3f(0,0,0));
         gmtl::Point3f point(gmtl::Point3f(-0.5f,-0.5,-1.0f));
         CPPUNIT_ASSERT(gmtl::intersect(box1, point));
      }
      
      /////////

      // test point outside (bottom face)
      {
         gmtl::AABoxf box1(gmtl::Point3f(-1,-1,-1), gmtl::Point3f(0,0,0));
         gmtl::Point3f point(gmtl::Point3f(-0.5f,-1.01,-0.5f));
         CPPUNIT_ASSERT(!gmtl::intersect(box1, point));
      }
      // test point outside (top face)
      {
         gmtl::AABoxf box1(gmtl::Point3f(-1,-1,-1), gmtl::Point3f(0,0,0));
         gmtl::Point3f point(gmtl::Point3f(-0.5f,0.01,-0.5f));
         CPPUNIT_ASSERT(!gmtl::intersect(box1, point));
      }
      // test point outside (left face)
      {
         gmtl::AABoxf box1(gmtl::Point3f(-1,-1,-1), gmtl::Point3f(0,0,0));
         gmtl::Point3f point(gmtl::Point3f(-1.01f,-0.5,-0.5f));
         CPPUNIT_ASSERT(!gmtl::intersect(box1, point));
      }
      // test point outside (right face)
      {
         gmtl::AABoxf box1(gmtl::Point3f(-1,-1,-1), gmtl::Point3f(0,0,0));
         gmtl::Point3f point(gmtl::Point3f(0.01f,-0.5,-0.5f));
         CPPUNIT_ASSERT(!gmtl::intersect(box1, point));
      }
      // test point outside (near face)
      {
         gmtl::AABoxf box1(gmtl::Point3f(-1,-1,-1), gmtl::Point3f(0,0,0));
         gmtl::Point3f point(gmtl::Point3f(-0.5f,-0.5,0.01f));
         CPPUNIT_ASSERT(!gmtl::intersect(box1, point));
      }
      // test point outside (far face)
      {
         gmtl::AABoxf box1(gmtl::Point3f(-1,-1,-1), gmtl::Point3f(0,0,0));
         gmtl::Point3f point(gmtl::Point3f(-0.5f,-0.5,-1.01f));
         CPPUNIT_ASSERT(!gmtl::intersect(box1, point));
      }
      
      // @todo, could use more rigorous testing here, test all sides of the box, 
      //        in and out and on the edges...
   }

   void IntersectionTest::testTimingIntersectAABoxPoint()
   {
      gmtl::AABoxf box1(gmtl::Point3f(-1,-1,-1), gmtl::Point3f(1,1,1));
      gmtl::Point3f point(gmtl::Point3f(-0.5f,-0.5,-1.01f));
      const long iters(400000);
      unsigned true_count(0);
      CPPUNIT_METRIC_START_TIMING();

      for(long iter=0;iter<iters; ++iter)
      {
         if (gmtl::intersect(box1, point))
         {
            ++true_count;
         }
         point[0] += 0.01;
      }

      CPPUNIT_METRIC_STOP_TIMING();
      CPPUNIT_ASSERT_METRIC_TIMING_LE("IntersectionTest/IntersectAABoxPoint", iters, 0.075f, 0.1f);  // warn at 7.5%, error at 10%

      CPPUNIT_ASSERT(true_count > 0.0f);
   }
}