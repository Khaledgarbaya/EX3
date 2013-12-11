//////////////////////////////////////////////////////
//
//  Distributed under the MIT License.
//  http://opensource.org/licenses/MIT
//
//  Copyright (c) 2013 Gary Paluk - http://plugin.io
//  Copyright (c) 2013 Panutat Tejasen
//
//////////////////////////////////////////////////////

#ifndef POINT_H
#define POINT_H

#include "Point.h"
#include "Vector.h"

namespace EX3
{
    class Point : public Tuple
    {
        public:
            Point();
            Point (const Point& pnt);
            Point (float x, float y, float z);
            ~Point();

            Point& operator= (const Point& pnt);

            Vector operator- (const Point& pnt) const;

            Point operator+ (const Vector& vec) const;
            Point operator- (const Vector& vec) const;
            Point& operator+= (const Vector& vec);
            Point& operator-= (const Vector& vec);

            Point operator+ (const Point& pnt) const;
            Point operator* (float scalar) const;
            Point operator/ (float scalar) const;

            friend Point operator* (float scalar, const Point& pnt);

            Point& operator+= (const Point& pnt);
            Point& operator-= (const Point& pnt);
            Point& operator*= (float scalar);
            Point& operator/= (float scalar);
            Point operator- () const;

            float Dot (const Vector& vec) const;

            static const Point ORIGIN;
    };
}

#endif // POINT_H
