//////////////////////////////////////////////////////
//
//  Distributed under the MIT License.
//  http://opensource.org/licenses/MIT
//
//  Copyright (c) 2013 Gary Paluk - http://plugin.io
//  Copyright (c) 2013 Panutat Tejasen
//
//////////////////////////////////////////////////////

#include "Point.h"
#include "Tuple.h"

#include <float.h>

using namespace EX3;

const Point Point::ORIGIN(0.0f, 0.0f, 0.0f);

//----------------------------------------------------------------------------
Point::Point()
{
    mTuple[0] = 0.0f;
    mTuple[1] = 0.0f;
    mTuple[2] = 0.0f;
    mTuple[3] = 1.0f;
}
//----------------------------------------------------------------------------
Point::Point (const Point& pnt)
{
    mTuple[0] = pnt.mTuple[0];
    mTuple[1] = pnt.mTuple[1];
    mTuple[2] = pnt.mTuple[2];
    mTuple[3] = 1.0f;
}
//----------------------------------------------------------------------------
Point::Point (float x, float y, float z)
{
    mTuple[0] = x;
    mTuple[1] = y;
    mTuple[2] = z;
    mTuple[3] = 1.0f;
}
//----------------------------------------------------------------------------
Point::~Point()
{
}
//----------------------------------------------------------------------------
Point& Point::operator= (const Point& pnt)
{
    mTuple[0] = pnt.mTuple[0];
    mTuple[1] = pnt.mTuple[1];
    mTuple[2] = pnt.mTuple[2];
    mTuple[3] = 1.0f;
    return *this;
}
//----------------------------------------------------------------------------
Vector Point::operator- (const Point& pnt) const
{
    return Vector
    (
        mTuple[0] - pnt.mTuple[0],
        mTuple[1] - pnt.mTuple[1],
        mTuple[2] - pnt.mTuple[2]
    );
}
//----------------------------------------------------------------------------
Point Point::operator+ (const Vector& vec) const
{
    return Point
    (
        mTuple[0] + vec[0],
        mTuple[1] + vec[1],
        mTuple[2] + vec[2]
    );
}
//----------------------------------------------------------------------------
Point Point::operator- (const Vector& vec) const
{
    return Point
    (
        mTuple[0] - vec[0],
        mTuple[1] - vec[1],
        mTuple[2] - vec[2]
    );
}
//----------------------------------------------------------------------------
Point& Point::operator+= (const Vector& vec)
{
    mTuple[0] += vec[0];
    mTuple[1] += vec[1];
    mTuple[2] += vec[2];
    return *this;
}
//----------------------------------------------------------------------------
Point& Point::operator-= (const Vector& vec)
{
    mTuple[0] -= vec[0];
    mTuple[1] -= vec[1];
    mTuple[2] -= vec[2];
    return *this;
}
//----------------------------------------------------------------------------
Point Point::operator+ (const Point& pnt) const
{
    return Point
    (
        mTuple[0] + pnt.mTuple[0],
        mTuple[1] + pnt.mTuple[1],
        mTuple[2] + pnt.mTuple[2]
    );
}
//----------------------------------------------------------------------------
Point Point::operator* (float scalar) const
{
    return Point
    (
        scalar*mTuple[0],
        scalar*mTuple[1],
        scalar*mTuple[2]
    );
}
//----------------------------------------------------------------------------
Point Point::operator/ (float scalar) const
{
    if (scalar != 0.0f)
    {
        float invScalar = 1.0f/scalar;
        return Point
        (
            invScalar*mTuple[0],
            invScalar*mTuple[1],
            invScalar*mTuple[2]
        );
    }

    return Point(FLT_MAX, FLT_MAX, FLT_MAX);
}
//----------------------------------------------------------------------------
Point EX3::operator* (float scalar, const Point& pnt)
{
    return pnt*scalar;
}
//----------------------------------------------------------------------------
Point& Point::operator+= (const Point& pnt)
{
    mTuple[0] += pnt[0];
    mTuple[1] += pnt[1];
    mTuple[2] += pnt[2];
    return *this;
}
//----------------------------------------------------------------------------
Point& Point::operator-= (const Point& pnt)
{
    mTuple[0] -= pnt[0];
    mTuple[1] -= pnt[1];
    mTuple[2] -= pnt[2];
    return *this;
}
//----------------------------------------------------------------------------
Point& Point::operator*= (float scalar)
{
    mTuple[0] *= scalar;
    mTuple[1] *= scalar;
    mTuple[2] *= scalar;
    return *this;
}
//----------------------------------------------------------------------------
Point& Point::operator/= (float scalar)
{
    if (scalar != 0.0f)
    {
        float invScalar = 1.0f/scalar;
        mTuple[0] *= invScalar;
        mTuple[1] *= invScalar;
        mTuple[2] *= invScalar;
    }
    else
    {
        mTuple[0] = FLT_MAX;
        mTuple[1] = FLT_MAX;
        mTuple[2] = FLT_MAX;
    }

    return *this;
}
//----------------------------------------------------------------------------
Point Point::operator- () const
{
    return Point(-mTuple[0], -mTuple[1], -mTuple[2]);
}
//----------------------------------------------------------------------------
float Point::Dot (const Vector& vec) const
{
    return mTuple[0]*vec[0] + mTuple[1]*vec[1] + mTuple[2]*vec[2];
}
//----------------------------------------------------------------------------
