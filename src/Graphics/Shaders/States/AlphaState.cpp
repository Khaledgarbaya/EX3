///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  Distributed under the MIT License  - http://opensource.org/licenses/MIT  //
//                                                                           //
//  Copyright (c) 2013 Gary Paluk      - http://www.plugin.io                //
//  Copyright (c) 2013 Panutat Tejasen - http://www.jimmysoftware.com        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "AlphaState.h"

using namespace EX3;

//----------------------------------------------------------------------------
AlphaState::AlphaState()
    :
    BlendEnabled(false),
    SrcBlend(SBM_SRC_ALPHA),
    DstBlend(DBM_ONE_MINUS_SRC_ALPHA),
    CompareEnabled(false),
    Compare(CM_ALWAYS),
    Reference(0.0f),
    ConstantColor(0.0f, 0.0f, 0.0f, 0.0f)
{
}
//----------------------------------------------------------------------------
AlphaState::~AlphaState()
{
}
//----------------------------------------------------------------------------
