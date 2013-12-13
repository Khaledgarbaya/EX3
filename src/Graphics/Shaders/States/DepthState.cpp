///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  Distributed under the MIT License  - http://opensource.org/licenses/MIT  //
//                                                                           //
//  Copyright (c) 2013 Gary Paluk      - http://www.plugin.io                //
//  Copyright (c) 2013 Panutat Tejasen - http://www.jimmysoftware.com        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "DepthState.h"

using namespace EX3;

//----------------------------------------------------------------------------
DepthState::DepthState()
    :
    Enabled(true),
    Writable(true),
    Compare(CM_LEQUAL)
{
}
//----------------------------------------------------------------------------
DepthState::~DepthState()
{
}
//----------------------------------------------------------------------------
