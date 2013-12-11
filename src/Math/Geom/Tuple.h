//////////////////////////////////////////////////////
//
//  Distributed under the MIT License.
//  http://opensource.org/licenses/MIT
//
//  Copyright (c) 2013 Gary Paluk - http://plugin.io
//  Copyright (c) 2013 Panutat Tejasen
//
//////////////////////////////////////////////////////

#ifndef TUPLE_H
#define TUPLE_H

namespace EX3
{
    class Tuple
    {
        public:
            Tuple();
            Tuple (const Tuple& tuple);
            Tuple (float x, float y, float z, float w);
            virtual ~Tuple();

            inline operator const float* () const;
            inline operator float* ();
            inline const float& operator[] (int i) const;
            inline float& operator[] (int i);
            inline float X () const;
            inline float& X ();
            inline float Y () const;
            inline float& Y ();
            inline float Z () const;
            inline float& Z ();
            inline float W () const;
            inline float& W ();

            Tuple& operator= (const Tuple& tuple);

            bool operator== (const Tuple& tuple) const;
            bool operator!= (const Tuple& tuple) const;
            bool operator<  (const Tuple& tuple) const;
            bool operator<= (const Tuple& tuple) const;
            bool operator>  (const Tuple& tuple) const;
            bool operator>= (const Tuple& tuple) const;

        protected:
            float mTuple[4];
    };

    inline Tuple::operator const float* () const
    {
        return mTuple;
    }
    //----------------------------------------------------------------------------
    inline Tuple::operator float* ()
    {
        return mTuple;
    }
    //----------------------------------------------------------------------------
    inline const float& Tuple::operator[] (int i) const
    {
        return mTuple[i];
    }
    //----------------------------------------------------------------------------
    inline float& Tuple::operator[] (int i)
    {
        return mTuple[i];
    }
    //----------------------------------------------------------------------------
    inline float Tuple::X () const
    {
        return mTuple[0];
    }
    //----------------------------------------------------------------------------
    inline float& Tuple::X ()
    {
        return mTuple[0];
    }
    //----------------------------------------------------------------------------
    inline float Tuple::Y () const
    {
        return mTuple[1];
    }
    //----------------------------------------------------------------------------
    inline float& Tuple::Y ()
    {
        return mTuple[1];
    }
    //----------------------------------------------------------------------------
    inline float Tuple::Z () const
    {
        return mTuple[2];
    }
    //----------------------------------------------------------------------------
    inline float& Tuple::Z ()
    {
        return mTuple[2];
    }
    //----------------------------------------------------------------------------
    inline float Tuple::W () const
    {
        return mTuple[3];
    }
    //----------------------------------------------------------------------------
    inline float& Tuple::W ()
    {
        return mTuple[3];
    }
}

#endif // TUPLE_H
