///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  Distributed under the MIT License  - http://opensource.org/licenses/MIT  //
//                                                                           //
//  Copyright (c) 2013 Gary Paluk      - http://www.plugin.io                //
//  Copyright (c) 2013 Panutat Tejasen - http://www.jimmysoftware.com        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "EX3Object.h"

using namespace EX3;

//----------------------------------------------------------------------------
EX3Object::EX3Object()
{
}
//----------------------------------------------------------------------------
EX3Object::~EX3Object()
{
}
//----------------------------------------------------------------------------
void EX3Object::SetName (const std::string& name)
{
    m_Name = name;
}
//----------------------------------------------------------------------------
const std::string& EX3Object::GetName () const
{
    return m_Name;
}
//----------------------------------------------------------------------------
