///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  Distributed under the MIT License  - http://opensource.org/licenses/MIT  //
//                                                                           //
//  Copyright (c) 2013 Gary Paluk      - http://www.plugin.io                //
//  Copyright (c) 2013 Panutat Tejasen - http://www.jimmysoftware.com        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#ifndef FLOAT4_H
#define FLOAT4_H

namespace EX3
{
    class Float4
    {
        public:
            Float4();
            Float4(const Float4& f);
            ~Float4();

            inline operator const float* () const;
            inline operator float* ();
            inline const float& operator[] (int i) const;
            inline float& operator[] (int i);

            Float4& operator= (const Float4& f);

            bool operator== (const Float4& f) const;
            bool operator!= (const Float4& f) const;
            bool operator<  (const Float4& f) const;
            bool operator<= (const Float4& f) const;
            bool operator>  (const Float4& f) const;
            bool operator>= (const Float4& f) const;

            Float4(float f0, float f1, float f2, float f3);

        protected:
            float m_Tuple[4];
        private:
    };
    //----------------------------------------------------------------------------
    inline Float4::operator const float* () const
    {
        return m_Tuple;
    }
    //----------------------------------------------------------------------------
    inline Float4::operator float* ()
    {
        return m_Tuple;
    }
    //----------------------------------------------------------------------------
    inline const float& Float4::operator[] (int i) const
    {
        return m_Tuple[i];
    }
    //----------------------------------------------------------------------------
    inline float& Float4::operator[] (int i)
    {
        return m_Tuple[i];
    }
}

#endif // FLOAT4_H
