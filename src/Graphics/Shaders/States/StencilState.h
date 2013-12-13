///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  Distributed under the MIT License  - http://opensource.org/licenses/MIT  //
//                                                                           //
//  Copyright (c) 2013 Gary Paluk      - http://www.plugin.io                //
//  Copyright (c) 2013 Panutat Tejasen - http://www.jimmysoftware.com        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#ifndef STENCILSTATE_H
#define STENCILSTATE_H

#include "../../../Core/Objects/EX3Object.h"

namespace EX3
{
    class StencilState : public EX3Object
    {
        public:
            StencilState();
            virtual ~StencilState();

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

            enum OperationType
            {
                OT_KEEP,
                OT_ZERO,
                OT_REPLACE,
                OT_INCREMENT,
                OT_DECREMENT,
                OT_INVERT,
                OT_QUANTITY
            };

            bool Enabled;            // default: false
            CompareMode Compare;     // default: CM_NEVER
            unsigned int Reference;  // default: 0
            unsigned int Mask;       // default: UINT_MAX (0xFFFFFFFF)
            unsigned int WriteMask;  // default: UINT_MAX (0xFFFFFFFF)
            OperationType OnFail;    // default: OT_KEEP
            OperationType OnZFail;   // default: OT_KEEP
            OperationType OnZPass;   // default: OT_KEEP
    };
}

#endif // STENCILSTATE_H
