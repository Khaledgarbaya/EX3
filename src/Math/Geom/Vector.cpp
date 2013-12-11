//////////////////////////////////////////////////////
//
//  Distributed under the MIT License.
//  http://opensource.org/licenses/MIT
//
//  Copyright (c) 2013 Gary Paluk - http://plugin.io
//  Copyright (c) 2013 Panutat Tejasen
//
//////////////////////////////////////////////////////

#include "Vector.h"

#include <cfloat>
#include <cmath>

using namespace EX3;

//----------------------------------------------------------------------------
Vector::Vector ()
{
    mTuple[0] = 0.0f;
    mTuple[1] = 0.0f;
    mTuple[2] = 0.0f;
    mTuple[3] = 0.0f;
}
//----------------------------------------------------------------------------
Vector::Vector (const Vector& vec)
{
    mTuple[0] = vec.mTuple[0];
    mTuple[1] = vec.mTuple[1];
    mTuple[2] = vec.mTuple[2];
    mTuple[3] = 0.0f;
}
//----------------------------------------------------------------------------
Vector::Vector (float x, float y, float z)
{
    mTuple[0] = x;
    mTuple[1] = y;
    mTuple[2] = z;
    mTuple[3] = 0.0f;
}
//----------------------------------------------------------------------------
Vector::~Vector ()
{
}
//----------------------------------------------------------------------------
Vector& Vector::operator= (const Vector& vec)
{
    mTuple[0] = vec.mTuple[0];
    mTuple[1] = vec.mTuple[1];
    mTuple[2] = vec.mTuple[2];
    mTuple[3] = 0.0f;
    return *this;
}
//----------------------------------------------------------------------------
Vector Vector::operator+ (const Vector& vec) const
{
    return Vector
    (
        mTuple[0] + vec.mTuple[0],
        mTuple[1] + vec.mTuple[1],
        mTuple[2] + vec.mTuple[2]
    );
}
//----------------------------------------------------------------------------
Vector Vector::operator- (const Vector& vec) const
{
    return Vector
    (
        mTuple[0] - vec.mTuple[0],
        mTuple[1] - vec.mTuple[1],
        mTuple[2] - vec.mTuple[2]
    );
}
//----------------------------------------------------------------------------
Vector Vector::operator* (float scalar) const
{
    return Vector
    (
        scalar*mTuple[0],
        scalar*mTuple[1],
        scalar*mTuple[2]
    );
}
//----------------------------------------------------------------------------
Vector Vector::operator/ (float scalar) const
{
    if (scalar != 0.0f)
    {
        float invScalar = 1.0f/scalar;
        return Vector
        (
            invScalar*mTuple[0],
            invScalar*mTuple[1],
            invScalar*mTuple[2]
        );
    }

    return Vector(FLT_MAX, FLT_MAX, FLT_MAX);
}
//----------------------------------------------------------------------------
Vector Vector::operator- () const
{
    return Vector(-mTuple[0], -mTuple[1], -mTuple[2]);
}
//----------------------------------------------------------------------------
namespace EX3
{
    Vector operator* (float scalar, const Vector& vec)
    {
        return vec*scalar;
    }
}
//----------------------------------------------------------------------------
Vector& Vector::operator+= (const Vector& vec)
{
    mTuple[0] += vec[0];
    mTuple[1] += vec[1];
    mTuple[2] += vec[2];
    return *this;
}
//----------------------------------------------------------------------------
Vector& Vector::operator-= (const Vector& vec)
{
    mTuple[0] -= vec[0];
    mTuple[1] -= vec[1];
    mTuple[2] -= vec[2];
    return *this;
}
//----------------------------------------------------------------------------
Vector& Vector::operator*= (float scalar)
{
    mTuple[0] *= scalar;
    mTuple[1] *= scalar;
    mTuple[2] *= scalar;
    return *this;
}
//----------------------------------------------------------------------------
Vector& Vector::operator/= (float scalar)
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
float Vector::Length () const
{
    float sqrLength = mTuple[0]*mTuple[0] + mTuple[1]*mTuple[1] + mTuple[2]*mTuple[2];
    return sqrtf(sqrLength);
}
//----------------------------------------------------------------------------
float Vector::SquaredLength () const
{
    float sqrLength = mTuple[0]*mTuple[0] + mTuple[1]*mTuple[1] + mTuple[2]*mTuple[2];
    return sqrLength;
}
//----------------------------------------------------------------------------
float Vector::Dot (const Vector& vec) const
{
    float dotProduct = mTuple[0]*vec.mTuple[0] + mTuple[1]*vec.mTuple[1] + mTuple[2]*vec.mTuple[2];
    return dotProduct;
}
//----------------------------------------------------------------------------
float Vector::Normalize (const float epsilon)
{
    float length = Length();

    if (length > epsilon)
    {
        float invLength = 1.0f/length;
        mTuple[0] *= invLength;
        mTuple[1] *= invLength;
        mTuple[2] *= invLength;
    }
    else
    {
        length = 0.0f;
        mTuple[0] = 0.0f;
        mTuple[1] = 0.0f;
        mTuple[2] = 0.0f;
    }

    return length;
}
//----------------------------------------------------------------------------
Vector Vector::Cross (const Vector& vec) const
{
    return Vector
    (
        mTuple[1]*vec.mTuple[2] - mTuple[2]*vec.mTuple[1],
        mTuple[2]*vec.mTuple[0] - mTuple[0]*vec.mTuple[2],
        mTuple[0]*vec.mTuple[1] - mTuple[1]*vec.mTuple[0]
    );
}
//----------------------------------------------------------------------------
Vector Vector::UnitCross (const Vector& vec) const
{
    Vector cross
    (
        mTuple[1]*vec.mTuple[2] - mTuple[2]*vec.mTuple[1],
        mTuple[2]*vec.mTuple[0] - mTuple[0]*vec.mTuple[2],
        mTuple[0]*vec.mTuple[1] - mTuple[1]*vec.mTuple[0]
    );

    cross.Normalize();
    return cross;
}
//----------------------------------------------------------------------------
