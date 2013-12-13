///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  Distributed under the MIT License  - http://opensource.org/licenses/MIT  //
//                                                                           //
//  Copyright (c) 2013 Gary Paluk      - http://www.plugin.io                //
//  Copyright (c) 2013 Panutat Tejasen - http://www.jimmysoftware.com        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "OffsetState.h"

using namespace EX3;

//----------------------------------------------------------------------------
OffsetState::OffsetState()
    :
    FillEnabled(false),
    LineEnabled(false),
    PointEnabled(false),
    Scale(0.0f),
    Bias(0.0f)
{
}
//----------------------------------------------------------------------------
OffsetState::~OffsetState()
{
}
//----------------------------------------------------------------------------
