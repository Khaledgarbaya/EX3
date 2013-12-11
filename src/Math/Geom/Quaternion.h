//////////////////////////////////////////////////////
//
//  Distributed under the MIT License.
//  http://opensource.org/licenses/MIT
//
//  Copyright (c) 2013 Gary Paluk - http://plugin.io
//  Copyright (c) 2013 Panutat Tejasen
//
//////////////////////////////////////////////////////

#ifndef QUATERNION_H
#define QUATERNION_H

#include "Matrix.h"
#include "Vector.h"
#include "../Core/EX3Math.h"

namespace EX3
{
    class Quaternion
    {
        public:
            Quaternion ();  // uninitialized
            Quaternion (float w, float x, float y, float z);
            Quaternion (const Quaternion& q);
            Quaternion (const Matrix& rot);
            Quaternion (const Vector& axis, float angle);

            inline operator const float* () const;
            inline operator float* ();
            inline const float& operator[] (int i) const;
            inline float& operator[] (int i);
            inline float W () const;
            inline float& W ();
            inline float X () const;
            inline float& X ();
            inline float Y () const;
            inline float& Y ();
            inline float Z () const;
            inline float& Z ();

            Quaternion& operator= (const Quaternion& q);

            bool operator== (const Quaternion& q) const;
            bool operator!= (const Quaternion& q) const;
            bool operator<  (const Quaternion& q) const;
            bool operator<= (const Quaternion& q) const;
            bool operator>  (const Quaternion& q) const;
            bool operator>= (const Quaternion& q) const;

            Quaternion operator+ (const Quaternion& q) const;
            Quaternion operator- (const Quaternion& q) const;
            Quaternion operator* (const Quaternion& q) const;
            Quaternion operator* (float scalar) const;
            Quaternion operator/ (float scalar) const;
            Quaternion operator- () const;

            friend Quaternion operator* (float scalar, const Quaternion& q);

            Quaternion& operator+= (const Quaternion& q);
            Quaternion& operator-= (const Quaternion& q);
            Quaternion& operator*= (float scalar);
            Quaternion& operator/= (float scalar);

            void FromRotationMatrix (const Matrix& rot);
            void ToRotationMatrix (Matrix& rot) const;
            void FromAxisAngle (const Vector& axis, float angle);
            void ToAxisAngle (Vector& axis, float& angle) const;

            float Length () const;
            float SquaredLength () const;
            float Dot (const Quaternion& q) const;
            float Normalize (const float epsilon = EX3Math::ZERO_TOLERANCE);
            Quaternion Inverse () const;
            Quaternion Conjugate () const;
            Quaternion Exp () const;
            Quaternion Log () const;

            Vector Rotate (const Vector& vec) const;

            Quaternion& Slerp (float t, const Quaternion& p, const Quaternion& q);
            Quaternion& Intermediate (const Quaternion& q0, const Quaternion& q1, const Quaternion& q2);
            Quaternion& Squad (float t, const Quaternion& q0, const Quaternion& a0, const Quaternion& a1, const Quaternion& q1);

            static const Quaternion ZERO;
            static const Quaternion IDENTITY;

        private:
            float mTuple[4];
    };

    //----------------------------------------------------------------------------
    inline Quaternion::operator const float* () const
    {
        return mTuple;
    }
    //----------------------------------------------------------------------------
    inline Quaternion::operator float* ()
    {
        return mTuple;
    }
    //----------------------------------------------------------------------------
    inline const float& Quaternion::operator[] (int i) const
    {
        return mTuple[i];
    }
    //----------------------------------------------------------------------------
    inline float& Quaternion::operator[] (int i)
    {
        return mTuple[i];
    }
    //----------------------------------------------------------------------------
    inline float Quaternion::W () const
    {
        return mTuple[0];
    }
    //----------------------------------------------------------------------------
    inline float& Quaternion::W ()
    {
        return mTuple[0];
    }
    //----------------------------------------------------------------------------
    inline float Quaternion::X () const
    {
        return mTuple[1];
    }
    //----------------------------------------------------------------------------
    inline float& Quaternion::X ()
    {
        return mTuple[1];
    }
    //----------------------------------------------------------------------------
    inline float Quaternion::Y () const
    {
        return mTuple[2];
    }
    //----------------------------------------------------------------------------
    inline float& Quaternion::Y ()
    {
        return mTuple[2];
    }
    //----------------------------------------------------------------------------
    inline float Quaternion::Z () const
    {
        return mTuple[3];
    }
    //----------------------------------------------------------------------------
    inline float& Quaternion::Z ()
    {
        return mTuple[3];
    }
    //----------------------------------------------------------------------------
}

#endif // QUATERNION_H
