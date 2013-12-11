//////////////////////////////////////////////////////
//
//  Distributed under the MIT License.
//  http://opensource.org/licenses/MIT
//
//  Copyright (c) 2013 Gary Paluk - http://plugin.io
//  Copyright (c) 2013 Panutat Tejasen
//
//////////////////////////////////////////////////////

#ifndef MATRIX_H
#define MATRIX_H

#include "Tuple.h"
#include "Point.h"
#include "Vector.h"

namespace EX3
{
    class Matrix
    {
        public:
            Matrix ();
            Matrix (const Matrix& mat);
            Matrix (bool isZero);
            Matrix (float m00, float m01, float m02, float m03,
                    float m10, float m11, float m12, float m13,
                    float m20, float m21, float m22, float m23,
                    float m30, float m31, float m32, float m33);
            Matrix (const float* entry, bool isRowMajor);
            Matrix (const Vector& axis, float angle);
            ~Matrix();

            inline operator const float* () const;
            inline operator float* ();
            inline const float* operator[] (int row) const;
            inline float* operator[] (int row);
            inline const float& operator() (int row, int column) const;
            inline float& operator() (int row, int column);

            void SetRow (int row, const Tuple& tuple);
            void GetRow (int row, Tuple& tuple) const;
            void SetColumn (int column, const Tuple& tuple);
            void GetColumn (int column, Tuple& tuple) const;

            void GetColumnMajor (float* columnMajor) const;

            Matrix& operator= (const Matrix& mat);

            bool operator== (const Matrix& mat) const;
            bool operator!= (const Matrix& mat) const;
            bool operator<  (const Matrix& mat) const;
            bool operator<= (const Matrix& mat) const;
            bool operator>  (const Matrix& mat) const;
            bool operator>= (const Matrix& mat) const;

            Matrix operator+ (const Matrix& mat) const;
            Matrix operator- (const Matrix& mat) const;
            Matrix operator* (float scalar) const;
            Matrix operator/ (float scalar) const;
            Matrix operator- () const;

            friend Matrix operator* (float scalar, const Matrix& mat);

            Matrix& operator+= (const Matrix& mat);
            Matrix& operator-= (const Matrix& mat);
            Matrix& operator*= (float scalar);
            Matrix& operator/= (float scalar);

            void ToZero ();
            void ToIdentity ();
            void ToDiagonal (float m00, float m11, float m22);
            void ToRotation (const Vector& axis, float angle);

            Matrix Transpose () const;
            Matrix Inverse (const float epsilon = 0.0f) const;
            Matrix Adjoint () const;
            float Determinant () const;
            Matrix operator* (const Matrix& mat) const;
            void Orthonormalize ();

            Tuple operator* (const Tuple& tuple) const;

            friend Tuple operator* (const Tuple& tuple, const Matrix& mat);

            Point operator* (const Point& pnt) const;
            Vector operator* (const Vector& vec) const;

            void ToObliqueProjection (const Point& origin, const Vector& normal, const Vector& direction);
            void ToPerspectiveProjection (const Point& origin, const Vector& normal, const Point& eye);
            void ToReflection (const Point& origin, const Vector& normal);

            static const Matrix ZERO;
            static const Matrix IDENTITY;

        private:
            float mEntry[16];
    };

    //----------------------------------------------------------------------------
    inline Matrix::operator const float* () const
    {
        return mEntry;
    }
    //----------------------------------------------------------------------------
    inline Matrix::operator float* ()
    {
        return mEntry;
    }
    //----------------------------------------------------------------------------
    inline const float* Matrix::operator[] (int row) const
    {
        return &mEntry[4*row];
    }
    //----------------------------------------------------------------------------
    inline float* Matrix::operator[] (int row)
    {
        return &mEntry[4*row];
    }
    //----------------------------------------------------------------------------
    inline const float& Matrix::operator() (int row, int column) const
    {
        return mEntry[column + 4*row];
    }
    //----------------------------------------------------------------------------
    inline float& Matrix::operator() (int row, int column)
    {
        return mEntry[column + 4*row];
    }
    //----------------------------------------------------------------------------
}

#endif // MATRIX_H
