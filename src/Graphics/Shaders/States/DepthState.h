///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  Distributed under the MIT License  - http://opensource.org/licenses/MIT  //
//                                                                           //
//  Copyright (c) 2013 Gary Paluk      - http://www.plugin.io                //
//  Copyright (c) 2013 Panutat Tejasen - http://www.jimmysoftware.com        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#ifndef DEPTHSTATE_H
#define DEPTHSTATE_H

#include "../../../Core/Objects/EX3Object.h"

namespace EX3
{
    class DepthState
    {
        public:
            DepthState();
            virtual ~DepthState();

            enum CompareMode
            {
                CM_NEVER,
                CM_LESS,
                CM_EQUAL,
                CM_LEQUAL,
                CM_GREATER,
                CM_NOTEQUAL,
                CM_GEQUAL,
                CM_ALWAYS,
                CM_QUANTITY
            };

            bool Enabled;         // default: true
            bool Writable;        // default: true
            CompareMode Compare;  // default: CM_LEQUAL
    };
}

#endif // DEPTHSTATE_H
