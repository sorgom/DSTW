//  ============================================================
//  mock for interface Dispatcher
//  ============================================================
//  created by Manfred Sorgo
#pragma once
#ifndef M_DISPATCHER_H
#define M_DISPATCHER_H

#include <ifs/I_Dispatcher.h>
#include "M_Base.h"

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

        inline PosRes assign(const ElementName& name, E_Subsys subs, size_t pos)
        {
            const INT32 i = call("assign").TPARAM(ElementName, name).PARAM(subs).PARAM(pos).RETURN_DEF_INT(0);
            return i < 0 ? PosRes {0, false} : PosRes {static_cast<size_t>(i), true};
        }
        inline void expectAssign(const ElementName& name, E_Subsys subs, size_t pos, INT32 ret = 0) const
        {
            expect("assign").TPARAM(ElementName, name).PARAM(subs).PARAM(pos).AND_RETURN(ret);
        }

        inline void dispatch(const FldState& tele) const
        {
            call("dispatch").TPARAM(FldState, tele);
        }
        inline void expectDispatch(const FldState& tele) const
        {
            expect("dispatch").TPARAM(FldState, tele);
        }

        inline void dispatch(const GuiCmd& tele) const
        {
            call("dispatch").TPARAM(GuiCmd, tele);
        }
        inline void expectDispatch(const GuiCmd& tele) const
        {
            expect("dispatch").TPARAM(GuiCmd, tele);
        }


        inline void dispatch(size_t id, CmdFld&& tele) const
        {
            call("dispatch").PARAM(id).TPARAM(CmdFld, tele);
        }
        inline void expectDispatch(size_t id, CmdFld& tele) const
        {
            expect("dispatch").PARAM(id).TPARAM(CmdFld, tele);
        }

        inline void dispatch(size_t id, StateGui&& tele) const
        {
            call("dispatch").PARAM(id).TPARAM(StateGui, tele);
        }
        inline void expectDispatch(size_t id, StateGui& tele) const
        {
            expect("dispatch").PARAM(id).TPARAM(StateGui, tele);
        }
    };
} 

#endif // H_