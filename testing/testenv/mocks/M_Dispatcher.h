//  ============================================================
//  mock for interface Dispatcher
//  ============================================================
//  created by Manfred Sorgo
#pragma once
#ifndef M_DISPATCHER_H
#define M_DISPATCHER_H

#include <ifs/I_Dispatcher.h>
#include "M_Base.h"
#include <baselib/Mem.h>

namespace test
{
    MOCK_CLASS(Dispatcher)
    {
    public:
        MOCK_CON(Dispatcher)

        inline void reset()
        {
            call("reset");
        }
        inline void expectReset() const
        {
            expect("reset");
        }
        inline void index()
        {
            call("index");
        }
        inline void expectIndex() const
        {
            expect("index");
        }

        inline INT32 assign(const ElementName& name, E_Subsys subs, UINT32 pos)
        {
            return call("assign").TPARAM(ElementName, name).PARAM(subs).PARAM(pos).RETI(0);
        }
        inline void expectAssign(const ElementName& name, E_Subsys subs, UINT32 pos, INT32 ret = 0) const
        {
            expect("assign").TPARAM(ElementName, name).PARAM(subs).PARAM(pos).ARETV(ret);
        }
        inline void expectAssign(E_Subsys subs, UINT32 pos, INT32 ret = 0) const
        {
            expect("assign").PARAM(subs).PARAM(pos).IGNORE().ARETV(ret);
        }

        inline bool label(ElementName& name, UINT32 id) const
        {
            Mem::copy(name, mLabel);
            return call("label").PARAM(id).RETI(true);
        }
        inline void setLabel(const ElementName& name)
        {
            Mem::copy(mLabel, name);
        }
        inline void expectLabel(UINT32 id, bool ret = true) const
        {
            expect("label").PARAM(id).ARETV(ret);
        }

        inline bool dispatch(const FldState& tele) const
        {
            return call("dispatch").TPARAM(FldState, tele).RETI(true);
        }
        inline void expectDispatch(const FldState& tele, bool ret = true) const
        {
            expect("dispatch").TPARAM(FldState, tele).ARETV(ret);
        }

        inline bool dispatch(const GuiCmd& tele) const
        {
            return call("dispatch").TPARAM(GuiCmd, tele).RETI(true);
        }
        inline void expectDispatch(const GuiCmd& tele, bool ret = true) const
        {
            expect("dispatch").TPARAM(GuiCmd, tele).ARETV(ret);
        }

        inline void expectDispatch(bool ret = true, UINT32 num = 1) const
        {
            expect(num, "dispatch").IGNORE().ARETV(ret);
        }
    private:
        ElementName mLabel;
    };
} 

#endif // H_