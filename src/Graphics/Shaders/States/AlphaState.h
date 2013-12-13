///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  Distributed under the MIT License  - http://opensource.org/licenses/MIT  //
//                                                                           //
//  Copyright (c) 2013 Gary Paluk      - http://www.plugin.io                //
//  Copyright (c) 2013 Panutat Tejasen - http://www.jimmysoftware.com        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#ifndef ALPHASTATE_H
#define ALPHASTATE_H

#include "../../../Core/Objects/EX3Object.h"
#include "../../../Math/Core/Float4.h"

namespace EX3
{
    class AlphaState : public EX3Object
    {
        public:
            AlphaState();
            virtual ~AlphaState();

            enum SrcBlendMode
            {
                SBM_ZERO,
                SBM_ONE,
                SBM_DST_COLOR,
                SBM_ONE_MINUS_DST_COLOR,
                SBM_SRC_ALPHA,
                SBM_ONE_MINUS_SRC_ALPHA,
                SBM_DST_ALPHA,
                SBM_ONE_MINUS_DST_ALPHA,
                SBM_SRC_ALPHA_SATURATE,
                SBM_CONSTANT_COLOR,
                SBM_ONE_MINUS_CONSTANT_COLOR,
                SBM_CONSTANT_ALPHA,
                SBM_ONE_MINUS_CONSTANT_ALPHA,
                SBM_QUANTITY
            };

            enum DstBlendMode
            {
                DBM_ZERO,
                DBM_ONE,
                DBM_SRC_COLOR,
                DBM_ONE_MINUS_SRC_COLOR,
                DBM_SRC_ALPHA,
                DBM_ONE_MINUS_SRC_ALPHA,
                DBM_DST_ALPHA,
                DBM_ONE_MINUS_DST_ALPHA,
                DBM_CONSTANT_COLOR,
                DBM_ONE_MINUS_CONSTANT_COLOR,
                DBM_CONSTANT_ALPHA,
                DBM_ONE_MINUS_CONSTANT_ALPHA,
                DBM_QUANTITY
            };

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

        bool BlendEnabled;      // default: false
        SrcBlendMode SrcBlend;  // default: SBM_SRC_ALPHA
        DstBlendMode DstBlend;  // default: DBM_ONE_MINUS_SRC_ALPHA
        bool CompareEnabled;    // default: false
        CompareMode Compare;    // default: CM_ALWAYS
        float Reference;        // default: 0, always in [0,1]
        Float4 ConstantColor;   // default: (0,0,0,0)
    };
}

#endif // ALPHASTATE_H
