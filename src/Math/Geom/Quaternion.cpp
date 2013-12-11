///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  Distributed under the MIT License  - http://opensource.org/licenses/MIT  //
//                                                                           //
//  Copyright (c) 2013 Gary Paluk      - http://www.plugin.io                //
//  Copyright (c) 2013 Panutat Tejasen - http://www.jimmysoftware.com        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "Quaternion.h"

#include <cstring>
#include <cfloat>
#include <cmath>

using namespace EX3;

const Quaternion Quaternion::ZERO(0.0f, 0.0f, 0.0f, 0.0f);
const Quaternion Quaternion::IDENTITY(1.0f, 0.0f, 0.0f, 0.0f);

//----------------------------------------------------------------------------
Quaternion::Quaternion ()
{
}
//----------------------------------------------------------------------------
Quaternion::Quaternion (float w, float x, float y, float z)
{
    mTuple[0] = w;
    mTuple[1] = x;
    mTuple[2] = y;
    mTuple[3] = z;
}
//----------------------------------------------------------------------------
Quaternion::Quaternion (const Quaternion& q)
{
    mTuple[0] = q.mTuple[0];
    mTuple[1] = q.mTuple[1];
    mTuple[2] = q.mTuple[2];
    mTuple[3] = q.mTuple[3];
}
//----------------------------------------------------------------------------
Quaternion::Quaternion (const Matrix& rot)
{
    FromRotationMatrix(rot);
}
//----------------------------------------------------------------------------
Quaternion::Quaternion (const Vector& axis, float angle)
{
    FromAxisAngle(axis, angle);
}
//----------------------------------------------------------------------------
Quaternion& Quaternion::operator= (const Quaternion& q)
{
    mTuple[0] = q.mTuple[0];
    mTuple[1] = q.mTuple[1];
    mTuple[2] = q.mTuple[2];
    mTuple[3] = q.mTuple[3];
    return *this;
}
//----------------------------------------------------------------------------
bool Quaternion::operator== (const Quaternion& q) const
{
    return memcmp(mTuple, q.mTuple, 4*sizeof(float)) == 0;
}
//----------------------------------------------------------------------------
bool Quaternion::operator!= (const Quaternion& q) const
{
    return memcmp(mTuple, q.mTuple, 4*sizeof(float)) != 0;
}
//----------------------------------------------------------------------------
bool Quaternion::operator< (const Quaternion& q) const
{
    return memcmp(mTuple, q.mTuple, 4*sizeof(float)) < 0;
}
//----------------------------------------------------------------------------
bool Quaternion::operator<= (const Quaternion& q) const
{
    return memcmp(mTuple, q.mTuple, 4*sizeof(float)) <= 0;
}
//----------------------------------------------------------------------------
bool Quaternion::operator> (const Quaternion& q) const
{
    return memcmp(mTuple, q.mTuple, 4*sizeof(float)) > 0;
}
//----------------------------------------------------------------------------
bool Quaternion::operator>= (const Quaternion& q) const
{
    return memcmp(mTuple, q.mTuple, 4*sizeof(float)) >= 0;
}
//----------------------------------------------------------------------------
Quaternion Quaternion::operator+ (const Quaternion& q) const
{
    Quaternion result;
    for (int i = 0; i < 4; ++i)
    {
        result.mTuple[i] = mTuple[i] + q.mTuple[i];
    }
    return result;
}
//----------------------------------------------------------------------------
Quaternion Quaternion::operator- (const Quaternion& q) const
{
    Quaternion result;
    for (int i = 0; i < 4; ++i)
    {
        result.mTuple[i] = mTuple[i] - q.mTuple[i];
    }
    return result;
}
//----------------------------------------------------------------------------
Quaternion Quaternion::operator* (const Quaternion& q) const
{
    Quaternion result;

    result.mTuple[0] =
        mTuple[0]*q.mTuple[0] -
        mTuple[1]*q.mTuple[1] -
        mTuple[2]*q.mTuple[2] -
        mTuple[3]*q.mTuple[3];

    result.mTuple[1] =
        mTuple[0]*q.mTuple[1] +
        mTuple[1]*q.mTuple[0] +
        mTuple[2]*q.mTuple[3] -
        mTuple[3]*q.mTuple[2];

    result.mTuple[2] =
        mTuple[0]*q.mTuple[2] +
        mTuple[2]*q.mTuple[0] +
        mTuple[3]*q.mTuple[1] -
        mTuple[1]*q.mTuple[3];

    result.mTuple[3] =
        mTuple[0]*q.mTuple[3] +
        mTuple[3]*q.mTuple[0] +
        mTuple[1]*q.mTuple[2] -
        mTuple[2]*q.mTuple[1];

    return result;
}
//----------------------------------------------------------------------------
Quaternion Quaternion::operator* (float scalar) const
{
    Quaternion result;
    for (int i = 0; i < 4; ++i)
    {
        result.mTuple[i] = scalar*mTuple[i];
    }
    return result;
}
//----------------------------------------------------------------------------
Quaternion Quaternion::operator/ (float scalar) const
{
    Quaternion result;
    int i;

    if (scalar != 0.0f)
    {
        float invScalar = 1.0f/scalar;
        for (i = 0; i < 4; ++i)
        {
            result.mTuple[i] = invScalar*mTuple[i];
        }
    }
    else
    {
        for (i = 0; i < 4; ++i)
        {
            result.mTuple[i] = FLT_MAX;
        }
    }

    return result;
}
//----------------------------------------------------------------------------
Quaternion Quaternion::operator- () const
{
    Quaternion result;
    for (int i = 0; i < 4; ++i)
    {
        result.mTuple[i] = -mTuple[i];
    }
    return result;
}
//----------------------------------------------------------------------------
Quaternion EX3::operator* (float scalar, const Quaternion& q)
{
    return q*scalar;
}
//----------------------------------------------------------------------------
Quaternion& Quaternion::operator+= (const Quaternion& q)
{
    for (int i = 0; i < 4; ++i)
    {
        mTuple[i] += q.mTuple[i];
    }
    return *this;
}
//----------------------------------------------------------------------------
Quaternion& Quaternion::operator-= (const Quaternion& q)
{
    for (int i = 0; i < 4; ++i)
    {
        mTuple[i] -= q.mTuple[i];
    }
    return *this;
}
//----------------------------------------------------------------------------
Quaternion& Quaternion::operator*= (float scalar)
{
    for (int i = 0; i < 4; ++i)
    {
        mTuple[i] *= scalar;
    }
    return *this;
}
//----------------------------------------------------------------------------
Quaternion& Quaternion::operator/= (float scalar)
{
    int i;

    if (scalar != 0.0f)
    {
        float invScalar = 1.0f/scalar;
        for (i = 0; i < 4; ++i)
        {
            mTuple[i] *= invScalar;
        }
    }
    else
    {
        for (i = 0; i < 4; ++i)
        {
            mTuple[i] = FLT_MAX;
        }
    }

    return *this;
}
//----------------------------------------------------------------------------
void Quaternion::FromRotationMatrix (const Matrix& rot)
{
    const int next[3] = { 1, 2, 0 };

    float trace = rot(0,0) + rot(1,1) + rot(2,2);
    float root;

    if (trace > (float)0)
    {
        root = sqrtf(trace + 1.0f);  // 2w
        mTuple[0] = 0.5f*root;
        root = 0.5f/root;  // 1/(4w)
        mTuple[1] = (rot(2,1) - rot(1,2))*root;
        mTuple[2] = (rot(0,2) - rot(2,0))*root;
        mTuple[3] = (rot(1,0) - rot(0,1))*root;
    }
    else
    {
        // |w| <= 1/2
        int i = 0;
        if (rot(1,1) > rot(0,0))
        {
            i = 1;
        }
        if (rot(2,2) > rot(i,i))
        {
            i = 2;
        }
        int j = next[i];
        int k = next[j];

        root = sqrtf(rot(i,i) - rot(j,j) - rot(k,k) + (float)1);
        float* quat[3] = { &mTuple[1], &mTuple[2], &mTuple[3] };
        *quat[i] = 0.5f*root;
        root = 0.5f/root;
        mTuple[0] = (rot(k,j) - rot(j,k))*root;
        *quat[j] = (rot(j,i) + rot(i,j))*root;
        *quat[k] = (rot(k,i) + rot(i,k))*root;
    }
}
//----------------------------------------------------------------------------
void Quaternion::ToRotationMatrix (Matrix& rot) const
{
    float twoX  = 2.0f*mTuple[1];
    float twoY  = 2.0f*mTuple[2];
    float twoZ  = 2.0f*mTuple[3];
    float twoWX = twoX*mTuple[0];
    float twoWY = twoY*mTuple[0];
    float twoWZ = twoZ*mTuple[0];
    float twoXX = twoX*mTuple[1];
    float twoXY = twoY*mTuple[1];
    float twoXZ = twoZ*mTuple[1];
    float twoYY = twoY*mTuple[2];
    float twoYZ = twoZ*mTuple[2];
    float twoZZ = twoZ*mTuple[3];

    rot(0,0) = 1.0f - (twoYY + twoZZ);
    rot(0,1) = twoXY - twoWZ;
    rot(0,2) = twoXZ + twoWY;
    rot(0,3) = 0.0f;
    rot(1,0) = twoXY + twoWZ;
    rot(1,1) = 1.0f - (twoXX + twoZZ);
    rot(1,2) = twoYZ - twoWX;
    rot(1,3) = 0.0f;
    rot(2,0) = twoXZ - twoWY;
    rot(2,1) = twoYZ + twoWX;
    rot(2,2) = 1.0f - (twoXX + twoYY);
    rot(2,3) = 0.0f;
    rot(3,0) = 0.0f;
    rot(3,1) = 0.0f;
    rot(3,2) = 0.0f;
    rot(3,3) = 1.0f;
}
//----------------------------------------------------------------------------
void Quaternion::FromAxisAngle (const Vector& axis, float angle)
{
    float halfAngle = 0.5f*angle;
    float sn = sinf(halfAngle);
    mTuple[0] = cosf(halfAngle);
    mTuple[1] = sn*axis[0];
    mTuple[2] = sn*axis[1];
    mTuple[3] = sn*axis[2];
}
//----------------------------------------------------------------------------
void Quaternion::ToAxisAngle (Vector& axis, float& angle) const
{
    float sqrLength = mTuple[1]*mTuple[1] + mTuple[2]*mTuple[2]
        + mTuple[3]*mTuple[3];

    if (sqrLength > 0.0f)
    {
        angle = 2.0f*acosf(mTuple[0]);
        float invLength = 1.0f/sqrtf(sqrLength);
        axis[0] = mTuple[1]*invLength;
        axis[1] = mTuple[2]*invLength;
        axis[2] = mTuple[3]*invLength;
    }
    else
    {
        angle = 0.0f;
        axis[0] = 1.0f;
        axis[1] = 0.0f;
        axis[2] = 0.0f;
    }
}
//----------------------------------------------------------------------------
float Quaternion::Length () const
{
    return sqrtf(mTuple[0]*mTuple[0] + mTuple[1]*mTuple[1] +
        mTuple[2]*mTuple[2] + mTuple[3]*mTuple[3]);
}
//----------------------------------------------------------------------------
float Quaternion::SquaredLength () const
{
    return mTuple[0]*mTuple[0] + mTuple[1]*mTuple[1] +
        mTuple[2]*mTuple[2] + mTuple[3]*mTuple[3];
}
//----------------------------------------------------------------------------
float Quaternion::Dot (const Quaternion& q) const
{
    return mTuple[0]*q.mTuple[0] + mTuple[1]*q.mTuple[1] +
        mTuple[2]*q.mTuple[2] + mTuple[3]*q.mTuple[3];
}
//----------------------------------------------------------------------------
float Quaternion::Normalize (const float epsilon)
{
    float length = Length();

    if (length > epsilon)
    {
        float invLength = 1.0f/length;
        mTuple[0] *= invLength;
        mTuple[1] *= invLength;
        mTuple[2] *= invLength;
        mTuple[3] *= invLength;
    }
    else
    {
        length = 0.0f;
        mTuple[0] = 0.0f;
        mTuple[1] = 0.0f;
        mTuple[2] = 0.0f;
        mTuple[3] = 0.0f;
    }

    return length;
}
//----------------------------------------------------------------------------
Quaternion Quaternion::Inverse () const
{
    Quaternion inverse;

    float norm = SquaredLength();
    if (norm > 0.0f)
    {
        float invNorm = 1.0f/norm;
        inverse.mTuple[0] = mTuple[0]*invNorm;
        inverse.mTuple[1] = -mTuple[1]*invNorm;
        inverse.mTuple[2] = -mTuple[2]*invNorm;
        inverse.mTuple[3] = -mTuple[3]*invNorm;
    }
    else
    {
        for (int i = 0; i < 4; ++i)
        {
            inverse.mTuple[i] = 0.0f;
        }
    }

    return inverse;
}
//----------------------------------------------------------------------------
Quaternion Quaternion::Conjugate () const
{
    return Quaternion(mTuple[0], -mTuple[1], -mTuple[2], -mTuple[3]);
}
//----------------------------------------------------------------------------
Quaternion Quaternion::Exp () const
{
    Quaternion result;

    float angle = sqrtf(mTuple[1]*mTuple[1] +
        mTuple[2]*mTuple[2] + mTuple[3]*mTuple[3]);

    float sn = sinf(angle);
    result.mTuple[0] = cosf(angle);

    int i;

    if (fabsf(sn) > 0.0f)
    {
        float coeff = sn/angle;
        for (i = 1; i < 4; ++i)
        {
            result.mTuple[i] = coeff*mTuple[i];
        }
    }
    else
    {
        for (i = 1; i < 4; ++i)
        {
            result.mTuple[i] = mTuple[i];
        }
    }

    return result;
}
//----------------------------------------------------------------------------
Quaternion Quaternion::Log () const
{
    Quaternion result;
    result.mTuple[0] = 0.0f;

    int i;

    if (fabsf(mTuple[0]) < 1.0f)
    {
        float angle = acosf(mTuple[0]);
        float sn = sinf(angle);
        if (fabsf(sn) > 0.0f)
        {
            float coeff = angle/sn;
            for (i = 1; i < 4; ++i)
            {
                result.mTuple[i] = coeff*mTuple[i];
            }
            return result;
        }
    }

    for (i = 1; i < 4; ++i)
    {
        result.mTuple[i] = mTuple[i];
    }
    return result;
}
//----------------------------------------------------------------------------
Vector Quaternion::Rotate (const Vector& vec) const
{
    Matrix rot;
    ToRotationMatrix(rot);
    return rot*vec;
}
//----------------------------------------------------------------------------
Quaternion& Quaternion::Slerp (float t, const Quaternion& p,
    const Quaternion& q)
{
    float cs = p.Dot(q);
    float angle = acosf(cs);

    if (fabsf(angle) > 0.0f)
    {
        float sn = sinf(angle);
        float invSn = 1.0f/sn;
        float tAngle = t*angle;
        float coeff0 = sinf(angle - tAngle)*invSn;
        float coeff1 = sinf(tAngle)*invSn;

        mTuple[0] = coeff0*p.mTuple[0] + coeff1*q.mTuple[0];
        mTuple[1] = coeff0*p.mTuple[1] + coeff1*q.mTuple[1];
        mTuple[2] = coeff0*p.mTuple[2] + coeff1*q.mTuple[2];
        mTuple[3] = coeff0*p.mTuple[3] + coeff1*q.mTuple[3];
    }
    else
    {
        mTuple[0] = p.mTuple[0];
        mTuple[1] = p.mTuple[1];
        mTuple[2] = p.mTuple[2];
        mTuple[3] = p.mTuple[3];
    }

    return *this;
}
//----------------------------------------------------------------------------
Quaternion& Quaternion::Intermediate (const Quaternion& q0,
    const Quaternion& q1, const Quaternion& q2)
{
    Quaternion q1Inv = q1.Conjugate();
    Quaternion p0 = q1Inv*q0;
    Quaternion p2 = q1Inv*q2;
    Quaternion arg = -0.25f*(p0.Log() + p2.Log());
    Quaternion a = q1*arg.Exp();
    *this = a;
    return *this;
}
//----------------------------------------------------------------------------
Quaternion& Quaternion::Squad (float t, const Quaternion& q0,
    const Quaternion& a0, const Quaternion& a1, const Quaternion& q1)
{
    float slerpT = 2.0f*t*(1.0f - t);
    Quaternion slerpP = Slerp(t, q0, q1);
    Quaternion slerpQ = Slerp(t, a0, a1);
    return Slerp(slerpT, slerpP, slerpQ);
}
//----------------------------------------------------------------------------
