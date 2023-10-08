
#include <Signal/Signal.h>

E_Result Signal::HN0()
{
    mPort.toFld(SIG_TO_FLD_HN0);
    chgState(SIG_TO_GUI_WAIT_HN0);
    return RES_OK;
}

E_Result Signal::HN1()
{
    mPort.toFld(SIG_TO_FLD_HN1);
    chgState(SIG_TO_GUI_WAIT_HN1);
    return RES_OK;
}

void Signal::fromFld(E_SigTromFld rcv)
{
    switch(rcv)
    {
    case SIG_FROM_FLD_HN0:
        chgState(SIG_TO_GUI_HN0);
        break;
    case SIG_FROM_FLD_HN1:
        chgState(SIG_TO_GUI_HN1);
        break;
    case SIG_FROM_FLD_UNDEF:
        chgState(SIG_TO_GUI_UNDEF);
        break;
    case SIG_FROM_FLD_DEFECT:
        chgState(SIG_TO_GUI_DEFECT);
        break;
    default:
        break;
    }
}

void Signal::chgState(E_SigToGui state)
{
    if (state != mState)
    {
        mState = state;
        mPort.toGui(mState);
    }
}