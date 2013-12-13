///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  Distributed under the MIT License  - http://opensource.org/licenses/MIT  //
//                                                                           //
//  Copyright (c) 2013 Gary Paluk      - http://www.plugin.io                //
//  Copyright (c) 2013 Panutat Tejasen - http://www.jimmysoftware.com        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#include "Assert.h"

using namespace EX3;

//----------------------------------------------------------------------------
Assert::Assert(bool condition, const char* file, int line, const char* format, ...)
{
    if (condition)
    {
        return;
    }
    //TODO log this to a file and/or window message
}
//----------------------------------------------------------------------------
Assert::~Assert()
{
}
//----------------------------------------------------------------------------
