///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  Distributed under the MIT License  - http://opensource.org/licenses/MIT  //
//                                                                           //
//  Copyright (c) 2013 Gary Paluk      - http://www.plugin.io                //
//  Copyright (c) 2013 Panutat Tejasen - http://www.jimmysoftware.com        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "Float4.h"

using namespace EX3;

//----------------------------------------------------------------------------
Float4::Float4 ()
{
}
//----------------------------------------------------------------------------
Float4::~Float4 ()
{
}
//----------------------------------------------------------------------------
Float4::Float4 (float f0, float f1, float f2, float f3)
{
    m_Tuple[0] = f0;
    m_Tuple[1] = f1;
    m_Tuple[2] = f2;
    m_Tuple[3] = f3;
}
//----------------------------------------------------------------------------
Float4::Float4 (const Float4& f)
{
    m_Tuple[0] = f.m_Tuple[0];
    m_Tuple[1] = f.m_Tuple[1];
    m_Tuple[2] = f.m_Tuple[2];
    m_Tuple[3] = f.m_Tuple[3];
}
//----------------------------------------------------------------------------
Float4& Float4::operator= (const Float4& f)
{
    m_Tuple[0] = f.m_Tuple[0];
    m_Tuple[1] = f.m_Tuple[1];
    m_Tuple[2] = f.m_Tuple[2];
    m_Tuple[3] = f.m_Tuple[3];
    return *this;
}
//----------------------------------------------------------------------------
bool Float4::operator== (const Float4& f) const
{
    for (int i = 0; i < 4; ++i)
    {
        if (m_Tuple[i] != f.m_Tuple[i])
        {
            return false;
        }
    }
    return true;
}
//----------------------------------------------------------------------------
bool Float4::operator!= (const Float4& f) const
{
    for (int i = 0; i < 4; ++i)
    {
        if (m_Tuple[i] != f.m_Tuple[i])
        {
            return true;
        }
    }
    return false;
}
//----------------------------------------------------------------------------
bool Float4::operator< (const Float4& f) const
{
    for (int i = 0; i < 4; ++i)
    {
        if (m_Tuple[i] < f.m_Tuple[i])
        {
            return true;
        }

        if (m_Tuple[i] > f.m_Tuple[i])
        {
            return false;
        }
    }
    return false;
}
//----------------------------------------------------------------------------
bool Float4::operator<= (const Float4& f) const
{
    for (int i = 0; i < 4; ++i)
    {
        if (m_Tuple[i] < f.m_Tuple[i])
        {
            return true;
        }

        if (m_Tuple[i] > f.m_Tuple[i])
        {
            return false;
        }
    }
    return true;
}
//----------------------------------------------------------------------------
bool Float4::operator> (const Float4& f) const
{
    for (int i = 0; i < 4; ++i)
    {
        if (m_Tuple[i] > f.m_Tuple[i])
        {
            return true;
        }

        if (m_Tuple[i] < f.m_Tuple[i])
        {
            return false;
        }
    }
    return false;
}
//----------------------------------------------------------------------------
bool Float4::operator>= (const Float4& f) const
{
    for (int i = 0; i < 4; ++i)
    {
        if (m_Tuple[i] > f.m_Tuple[i])
        {
            return true;
        }

        if (m_Tuple[i] < f.m_Tuple[i])
        {
            return false;
        }
    }
    return true;
}
//----------------------------------------------------------------------------
