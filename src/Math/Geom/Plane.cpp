//////////////////////////////////////////////////////
//
//  Distributed under the MIT License.
//  http://opensource.org/licenses/MIT
//
//  Copyright (c) 2013 Gary Paluk - http://plugin.io
//  Copyright (c) 2013 Panutat Tejasen
//
//////////////////////////////////////////////////////

#include "Plane.h"

#include <cstring>
#include <cmath>

using namespace EX3;

//----------------------------------------------------------------------------
Plane::Plane ()
{
}
//----------------------------------------------------------------------------
Plane::Plane (const Plane& plane)
    :
    mTuple(plane.mTuple)
{
}
//----------------------------------------------------------------------------
Plane::~Plane ()
{
}
//----------------------------------------------------------------------------
Plane::Plane (float normal0, float normal1, float normal2, float constant)
{
    mTuple[0] = normal0;
    mTuple[1] = normal1;
    mTuple[2] = normal2;
    mTuple[3] = -constant;
}
//----------------------------------------------------------------------------
Plane::Plane (const Vector& normal, float constant)
{
    mTuple[0] = normal[0];
    mTuple[1] = normal[1];
    mTuple[2] = normal[2];
    mTuple[3] = -constant;
}
//----------------------------------------------------------------------------
Plane::Plane (const Vector& normal, const Point& p)
{
    mTuple[0] = normal[0];
    mTuple[1] = normal[1];
    mTuple[2] = normal[2];
    mTuple[3] = -p.Dot(normal);
}
//----------------------------------------------------------------------------
Plane::Plane (const Point& p0, const Point& p1, const Point& p2)
{
    Vector edge1 = p1 - p0;
    Vector edge2 = p2 - p0;
    Vector normal = edge1.UnitCross(edge2);
    mTuple[0] = normal[0];
    mTuple[1] = normal[1];
    mTuple[2] = normal[2];
    mTuple[3] = -p0.Dot(normal);
}
//----------------------------------------------------------------------------
Plane::Plane (const Tuple& tuple)
    :
    mTuple(tuple)
{
}
//----------------------------------------------------------------------------
Plane& Plane::operator= (const Plane& plane)
{
    mTuple = plane.mTuple;
    return *this;
}
//----------------------------------------------------------------------------
bool Plane::operator== (const Plane& plane) const
{
    return memcmp(mTuple, plane.mTuple, 4*sizeof(float)) == 0;
}
//----------------------------------------------------------------------------
bool Plane::operator!= (const Plane& plane) const
{
    return memcmp(mTuple, plane.mTuple, 4*sizeof(float)) != 0;
}
//----------------------------------------------------------------------------
bool Plane::operator< (const Plane& plane) const
{
    return memcmp(mTuple, plane.mTuple, 4*sizeof(float)) < 0;
}
//----------------------------------------------------------------------------
bool Plane::operator<= (const Plane& plane) const
{
    return memcmp(mTuple, plane.mTuple, 4*sizeof(float)) <= 0;
}
//----------------------------------------------------------------------------
bool Plane::operator> (const Plane& plane) const
{
    return memcmp(mTuple, plane.mTuple, 4*sizeof(float)) > 0;
}
//----------------------------------------------------------------------------
bool Plane::operator>= (const Plane& plane) const
{
    return memcmp(mTuple, plane.mTuple, 4*sizeof(float)) >= 0;
}
//----------------------------------------------------------------------------
float Plane::Normalize (const float epsilon)
{
    float length = sqrtf(mTuple[0]*mTuple[0] + mTuple[1]*mTuple[1] + mTuple[2]*mTuple[2]);

    if (length > epsilon)
    {
        float invLength = 1.0f/length;
        mTuple[0] *= invLength;
        mTuple[1] *= invLength;
        mTuple[2] *= invLength;
        mTuple[3] *= invLength;
    }

    return length;
}
//----------------------------------------------------------------------------
float Plane::DistanceTo (const Point& p) const
{
    return mTuple[0]*p[0] + mTuple[1]*p[1] + mTuple[2]*p[2] + mTuple[3];
}
//----------------------------------------------------------------------------
int Plane::WhichSide (const Point& p) const
{
    float distance = DistanceTo(p);

    if (distance < 0.0f)
    {
        return -1;
    }
    else if (distance > 0.0f)
    {
        return +1;
    }
    else
    {
        return 0;
    }
}
//----------------------------------------------------------------------------
