///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  Distributed under the MIT License  - http://opensource.org/licenses/MIT  //
//                                                                           //
//  Copyright (c) 2013 Gary Paluk      - http://www.plugin.io                //
//  Copyright (c) 2013 Panutat Tejasen - http://www.jimmysoftware.com        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "StencilState.h"

using namespace EX3;

StencilState::StencilState()
    :
    Enabled(false),
    Compare(CM_NEVER),
    Reference(0),
    Mask(UINT_MAX),
    WriteMask(UINT_MAX),
    OnFail(OT_KEEP),
    OnZFail(OT_KEEP),
    OnZPass(OT_KEEP)
{
}

StencilState::~StencilState()
{
}
