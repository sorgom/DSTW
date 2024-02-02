//  ============================================================
//  literals for testing
//  - header and source content is generated by sript
//  ============================================================
//  created by Manfred Sorgo

#ifndef TESTLIB_LITERALS_H
#define TESTLIB_LITERALS_H

#include <codebase/BaseTypes.h>

#define C_STR_DEC(NAME) \
    extern const CONST_C_STRING c__ ## NAME;

namespace test
{
    C_STR_DEC(ELM)

    //# C_STR_DEC
    C_STR_DEC(CmdFld)
    C_STR_DEC(Com)
    C_STR_DEC(Dispatcher)
    C_STR_DEC(ComName)
    C_STR_DEC(FldState)
    C_STR_DEC(GuiCmd)
    C_STR_DEC(LCR)
    C_STR_DEC(LCR_Hub)
    C_STR_DEC(LCR_Provider)
    C_STR_DEC(Log)
    C_STR_DEC(PosRes)
    C_STR_DEC(ProjLCR)
    C_STR_DEC(ProjSEG)
    C_STR_DEC(ProjSIG)
    C_STR_DEC(ProjTSW)
    C_STR_DEC(Reader)
    C_STR_DEC(SIG)
    C_STR_DEC(SIG_Hub)
    C_STR_DEC(SIG_Provider)
    C_STR_DEC(StateGui)
    C_STR_DEC(TSW)
    C_STR_DEC(TSW_Hub)
    C_STR_DEC(TSW_Provider)
    //# END
} // namespace

#endif // _H
