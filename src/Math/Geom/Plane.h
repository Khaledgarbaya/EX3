///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  Distributed under the MIT License  - http://opensource.org/licenses/MIT  //
//                                                                           //
//  Copyright (c) 2013 Gary Paluk      - http://www.plugin.io                //
//  Copyright (c) 2013 Panutat Tejasen - http://www.jimmysoftware.com        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#ifndef PLANE_H
#define PLANE_H

#include "Point.h"
#include "Vector.h"
#include "../Core/EX3Math.h"

namespace EX3
{
    class Plane
    {
        public:
            Plane();
            Plane (const Plane& plane);
            Plane (float normal0, float normal1, float normal2, float constant);
            Plane (const Vector& normal, float constant);
            Plane (const Vector& normal, const Point& p);
            Plane (const Point& p0, const Point& p1, const Point& p2);
            Plane (const Tuple& tuple);
            ~Plane();

            inline operator const float* () const;
            inline operator float* ();
            inline const float& operator[] (int i) const;
            inline float& operator[] (int i);

            Plane& operator= (const Plane& plane);

            bool operator== (const Plane& plane) const;
            bool operator!= (const Plane& plane) const;
            bool operator<  (const Plane& plane) const;
            bool operator<= (const Plane& plane) const;
            bool operator>  (const Plane& plane) const;
            bool operator>= (const Plane& plane) const;

            inline void SetNormal (const Vector& normal);
            inline void SetConstant (float constant);
            inline Vector GetNormal () const;
            inline float GetConstant () const;

            float Normalize (const float epsilon = EX3Math::ZERO_TOLERANCE);
            float DistanceTo (const Point& p) const;
            int WhichSide (const Point& p) const;

        private:
            Tuple mTuple;
    };

    //----------------------------------------------------------------------------
    inline Plane::operator const float* () const
    {
        return (const float*)mTuple;
    }
    //----------------------------------------------------------------------------
    inline Plane::operator float* ()
    {
        return (float*)mTuple;
    }
    //----------------------------------------------------------------------------
    inline const float& Plane::operator[] (int i) const
    {
        return mTuple[i];
    }
    //----------------------------------------------------------------------------
    inline float& Plane::operator[] (int i)
    {
        return mTuple[i];
    }
    //----------------------------------------------------------------------------
    inline void Plane::SetNormal (const Vector& normal)
    {
        mTuple[0] = normal[0];
        mTuple[1] = normal[1];
        mTuple[2] = normal[2];
    }
    //----------------------------------------------------------------------------
    inline void Plane::SetConstant (float constant)
    {
        mTuple[3] = -constant;
    }
    //----------------------------------------------------------------------------
    inline Vector Plane::GetNormal () const
    {
        return Vector(mTuple[0], mTuple[1], mTuple[2]);
    }
    //----------------------------------------------------------------------------
    inline float Plane::GetConstant () const
    {
        return -mTuple[3];
    }
    //----------------------------------------------------------------------------
}

#endif // PLANE_H
