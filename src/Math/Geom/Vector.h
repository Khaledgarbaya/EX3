//////////////////////////////////////////////////////
//
//  Distributed under the MIT License.
//  http://opensource.org/licenses/MIT
//
//  Copyright (c) 2013 Gary Paluk - http://plugin.io
//  Copyright (c) 2013 Panutat Tejasen
//
//////////////////////////////////////////////////////

#ifndef VECTOR_H
#define VECTOR_H

#include "Tuple.h"
#include "../Core/EX3Math.h"

namespace EX3
{
    class Vector : public Tuple
    {
        public:
            Vector ();
            Vector (const Vector& vec);
            Vector (float x, float y, float z);
            ~Vector ();

            Vector& operator= (const Vector& vec);

            Vector operator+ (const Vector& vec) const;
            Vector operator- (const Vector& vec) const;
            Vector operator* (float scalar) const;
            Vector operator/ (float scalar) const;
            Vector operator- () const;

            friend Vector operator* (float scalar, const Vector& vec);

            Vector& operator+= (const Vector& vec);
            Vector& operator-= (const Vector& vec);
            Vector& operator*= (float scalar);
            Vector& operator/= (float scalar);

            float Length () const;
            float SquaredLength () const;
            float Dot (const Vector& vec) const;
            float Normalize (const float epsilon = EX3Math::ZERO_TOLERANCE);
            Vector Cross (const Vector& vec) const;
            Vector UnitCross (const Vector& vec) const;

            static const Vector ZERO;
            static const Vector UNIT_X;
            static const Vector UNIT_Y;
            static const Vector UNIT_Z;
    };
}

#endif // VECTOR_H
