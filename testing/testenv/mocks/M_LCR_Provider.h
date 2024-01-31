//  ============================================================
//  mock for interface LCR_Provider
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef M_LCR_PROVIDER_H
#define M_LCR_PROVIDER_H

#include <ifs/I_LCR_Provider.h>
#include "M_Base.h"
#include "M_LCR.h"

namespace test
{
    MOCK_CLASS(LCR_Provider)
    {
    public:
        MOCK_CON(LCR_Provider)

        inline bool has(size_t pos) const
        {
            return call("has").PARAM(pos).RETURN_DEF_BOOL(true);
        }
        inline void expectHas(size_t pos, bool ret = true) const
        {
            expect("has").PARAM(pos).AND_RETURN_BOOL(ret);
        }

        inline I_LCR& at(size_t pos)
        {
            return M_LCR::instance();
        }

        inline void reset()
        {
            call("reset");
        }
        inline void expectReset() const
        {
            expect("reset");
        }
        
        inline void load(const ProjLCR* data, UINT32 num)
        {
            call("load").PARAM(num);
        }
        inline void expectLoad(UINT32 num) const
        {
            expect("load").PARAM(num);
        }
   };
}
#endif // H_