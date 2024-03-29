//  associated header
#include <testlib/TestLiterals.h>

#define C_STR_DEF(NAME) \
    const CONST_C_STRING c__ ## NAME = #NAME;

namespace test
{
    C_STR_DEF(ELM)

    //# C_STR_DEF
    C_STR_DEF(Com)
    C_STR_DEF(ComCmdFld)
    C_STR_DEF(ComFldState)
    C_STR_DEF(ComGuiCmd)
    C_STR_DEF(ComName)
    C_STR_DEF(ComStateGui)
    C_STR_DEF(Dispatcher)
    C_STR_DEF(LCR)
    C_STR_DEF(LCR_Hub)
    C_STR_DEF(LCR_Provider)
    C_STR_DEF(Log)
    C_STR_DEF(PosRes)
    C_STR_DEF(ProjLCR)
    C_STR_DEF(ProjSEG)
    C_STR_DEF(ProjSIG)
    C_STR_DEF(ProjTSW)
    C_STR_DEF(Reader)
    C_STR_DEF(SIG)
    C_STR_DEF(SIG_Hub)
    C_STR_DEF(SIG_Provider)
    C_STR_DEF(TSW)
    C_STR_DEF(TSW_Hub)
    C_STR_DEF(TSW_Provider)
    //# END

} // namespace
