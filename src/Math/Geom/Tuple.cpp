//////////////////////////////////////////////////////
//
//  Distributed under the MIT License.
//  http://opensource.org/licenses/MIT
//
//  Copyright (c) 2013 Gary Paluk - http://plugin.io
//  Copyright (c) 2013 Panutat Tejasen
//
//////////////////////////////////////////////////////

#include "Tuple.h"

#include <string.h>

using namespace EX3;

//----------------------------------------------------------------------------
Tuple::Tuple()
{
}
//----------------------------------------------------------------------------
Tuple::Tuple (const Tuple& tuple)
{
    mTuple[0] = tuple.mTuple[0];
    mTuple[1] = tuple.mTuple[1];
    mTuple[2] = tuple.mTuple[2];
    mTuple[3] = tuple.mTuple[3];
}
//----------------------------------------------------------------------------
Tuple::Tuple (float x, float y, float z, float w)
{
    mTuple[0] = x;
    mTuple[1] = y;
    mTuple[2] = z;
    mTuple[3] = w;
}
//----------------------------------------------------------------------------
Tuple::~Tuple()
{
}
//----------------------------------------------------------------------------
Tuple& Tuple::operator= (const Tuple& tuple)
{
    mTuple[0] = tuple.mTuple[0];
    mTuple[1] = tuple.mTuple[1];
    mTuple[2] = tuple.mTuple[2];
    mTuple[3] = tuple.mTuple[3];
    return *this;
}
//----------------------------------------------------------------------------
bool Tuple::operator== (const Tuple& tuple) const
{
    return memcmp(mTuple, tuple.mTuple, 4*sizeof(float)) == 0;
}
//----------------------------------------------------------------------------
bool Tuple::operator!= (const Tuple& tuple) const
{
    return memcmp(mTuple, tuple.mTuple, 4*sizeof(float)) != 0;
}
//----------------------------------------------------------------------------
bool Tuple::operator< (const Tuple& tuple) const
{
    return memcmp(mTuple, tuple.mTuple, 4*sizeof(float)) < 0;
}
//----------------------------------------------------------------------------
bool Tuple::operator<= (const Tuple& tuple) const
{
    return memcmp(mTuple, tuple.mTuple, 4*sizeof(float)) <= 0;
}
//----------------------------------------------------------------------------
bool Tuple::operator> (const Tuple& tuple) const
{
    return memcmp(mTuple, tuple.mTuple, 4*sizeof(float)) > 0;
}
//----------------------------------------------------------------------------
bool Tuple::operator>= (const Tuple& tuple) const
{
    return memcmp(mTuple, tuple.mTuple, 4*sizeof(float)) >= 0;
}
//----------------------------------------------------------------------------
