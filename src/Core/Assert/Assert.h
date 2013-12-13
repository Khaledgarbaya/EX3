///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  Distributed under the MIT License  - http://opensource.org/licenses/MIT  //
//                                                                           //
//  Copyright (c) 2013 Gary Paluk      - http://www.plugin.io                //
//  Copyright (c) 2013 Panutat Tejasen - http://www.jimmysoftware.com        //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#ifndef ASSERT_H
#define ASSERT_H

#include "../../Core/CoreLib.h"

namespace EX3
{

    class Assert
    {
        public:
            Assert(bool condition, const char* file, int line, const char* format, ...);
            ~Assert();
        protected:
        private:
    };

}

// TODO allocate to Assert::Assert on preprocessor directive
#define assertion(condition, format, ...) assert(condition)

#endif // ASSERT_H
