#include <SIG/SIG_X.h>
#include <SYS/IL.h>

void SIG_X::procFromFld(const UINT8 state)
{
    //  field values are only forwarded to GUI
    //  if GUI state differs
    if (mStateToGui != state)
    {
        mStateToGui = state;
        toGui(mStateToGui);
    }
    else
    { pass(); }
}

void SIG_XS::procFromFld(const UINT8 state, UINT8 speed)
{
    switch (state)
    {
        case SIG_STATE_UNDEF:
        case SIG_STATE_DEFECT:
            speed = 0;
            break;
        default:
            break;
    }
    //  field values are only forwarded to GUI
    //  if GUI state or GUI speed differs
    if (
        (mStateToGui != state) or
        (mSpeedToGui != speed)
    )
    {
        mStateToGui = state;
        mSpeedToGui = speed;
        toGui(mStateToGui, mSpeedToGui);
    }
    else
    { pass(); }
}

void SIG_X::procFromGui(const UINT8 stateFld, const UINT8 stateGui)
{
    mStateToFld = stateFld;
    mStateToGui = stateGui;
    toGui(mStateToGui);
    toFld(mStateToFld);
}

void SIG_XS::procFromGui(const UINT8 stateFld, const UINT8 stateGui, const UINT8 speed)
{
    mStateToFld = stateFld;
    mSpeedToFld = speed;
    mStateToGui = stateGui;
    toGui(mStateToGui, mSpeedToGui);
    toFld(mStateToFld, mSpeedToFld);
}

void SIG_XS::speedToFld(const UINT8 speed)
{
    switch (mStateToFld)
    {
        case SIG_STATE_UNDEF:
            break;
        default:
            if (speed != mSpeedToFld)
            {
                mSpeedToFld = speed;
                toFld(mStateToFld, mSpeedToFld);
            }
            break;    
    };
}

void SIG_X::logMismatch()
{
    IL::getLog().log(COMP_SIG, ERR_MATCH);
}

void SIG_H::process(const ComTeleFld& tele)
{
    const auto state = tele.param1;
    switch (state)
    {
    case SIG_STATE_UNDEF:
    case SIG_STATE_DEFECT:
    case SIG_STATE_H0:
    case SIG_STATE_H1:
        procFromFld(state);
        break;    
    default:
        logMismatch();
        break;    
    };
}

void SIG_H::process(const ComTeleGui& tele)
{
    switch (tele.param1)
    {
    case SIG_STATE_H0:
        proc_H0();
        break;    
    case SIG_STATE_H1:
        proc_H1();
        break;    
    default:
        logMismatch();
        break;    
    };
}

void SIG_H::proc_H0()
{
    switch (mStateToGui)
    {
    case SIG_STATE_UNDEF:
    case SIG_STATE_H1:
    case SIG_STATE_WAIT_H1:
        procFromGui(SIG_STATE_H0, SIG_STATE_WAIT_H0);
        break;
    default:
        break;
    }
}

void SIG_H::proc_H1()
{
    switch (mStateToGui)
    {
    case SIG_STATE_UNDEF:
    case SIG_STATE_H0:
    case SIG_STATE_WAIT_H0:
        procFromGui(SIG_STATE_H1, SIG_STATE_WAIT_H1);
        break;
    default:
        break;
    }
}

void SIG_N::process(const ComTeleGui& tele)
{
    const auto state = tele.param1, speed = tele.param2;
    switch (state)
    {
    case SIG_STATE_N0:
        proc_N0(speed);
        break;    
    case SIG_STATE_N1:
        proc_N1(speed);
        break;    
    default:
        logMismatch();
        break;    
    };
}

void SIG_N::process(const ComTeleFld& tele)
{
    const auto state = tele.param1, speed = tele.param2;
    switch (state)
    {
    case SIG_STATE_UNDEF:
    case SIG_STATE_DEFECT:
    case SIG_STATE_N0:
    case SIG_STATE_N1:
        procFromFld(state, speed);
        break;    
    default:
        logMismatch();
        break;    
    };
}

void SIG_N::proc_N0(const UINT8 speed)
{
    switch (mStateToGui)
    {
    case SIG_STATE_UNDEF:
    case SIG_STATE_N1:
    case SIG_STATE_WAIT_N1:
        procFromGui(SIG_STATE_N0, SIG_STATE_WAIT_N0, speed);
        break;
    default:
        speedToFld(speed);
        break;
    }
}

void SIG_N::proc_N1(const UINT8 speed)
{
    switch (mStateToGui)
    {
    case SIG_STATE_UNDEF:
    case SIG_STATE_N0:
    case SIG_STATE_WAIT_N0:
        procFromGui(SIG_STATE_N1, SIG_STATE_WAIT_N1, speed);
        break;
    default:
        speedToFld(speed);
        break;
    }
}

void SIG_H_N::process(const ComTeleGui& tele)
{
    const auto state = tele.param1, speed = tele.param2;
    switch (state)
    {
    case SIG_STATE_H0_N0:
        proc_H0_N0(speed);
        break;    
    case SIG_STATE_H0_N1:
        proc_H0_N1(speed);
        break;    
    case SIG_STATE_H1_N0:
        proc_H1_N0(speed);
        break;    
    case SIG_STATE_H1_N1:
        proc_H1_N1(speed);
        break;    
    default:
        logMismatch();
        break;    
    };
}

void SIG_H_N::process(const ComTeleFld& tele)
{
    const auto state = tele.param1, speed = tele.param2;
    switch (state)
    {
    case SIG_STATE_UNDEF:
    case SIG_STATE_DEFECT:
    case SIG_STATE_H0_N0:
    case SIG_STATE_H0_N1:
    case SIG_STATE_H1_N0:
    case SIG_STATE_H1_N1:
        procFromFld(state, speed);
        break;    
    default:
        logMismatch();
        break;    
    };
}

void SIG_H_N::proc_H0_N0(const UINT8 speed)
{
    switch (mStateToGui)
    {
    case SIG_STATE_UNDEF:

    case SIG_STATE_H0_N1:
    case SIG_STATE_H1_N0:
    case SIG_STATE_H1_N1:

    case SIG_STATE_WAIT_H0_N1:
    case SIG_STATE_WAIT_H1_N0:
    case SIG_STATE_WAIT_H1_N1:
        procFromGui(SIG_STATE_H0_N0, SIG_STATE_WAIT_H0_N0, speed);
        break;
    default:
        speedToFld(speed);
        break;
    }

}
void SIG_H_N::proc_H0_N1(const UINT8 speed)
{
    switch (mStateToGui)
    {
    case SIG_STATE_UNDEF:
    case SIG_STATE_H0_N0:

    case SIG_STATE_H1_N0:
    case SIG_STATE_H1_N1:
    case SIG_STATE_WAIT_H0_N0:

    case SIG_STATE_WAIT_H1_N0:
    case SIG_STATE_WAIT_H1_N1:
        procFromGui(SIG_STATE_H0_N1, SIG_STATE_WAIT_H0_N1, speed);
        break;
    default:
        speedToFld(speed);
        break;
    }
    
}
void SIG_H_N::proc_H1_N0(const UINT8 speed)
{
    switch (mStateToGui)
    {
    case SIG_STATE_UNDEF:
    case SIG_STATE_H0_N0:
    case SIG_STATE_H0_N1:

    case SIG_STATE_H1_N1:
    case SIG_STATE_WAIT_H0_N0:
    case SIG_STATE_WAIT_H0_N1:

    case SIG_STATE_WAIT_H1_N1:
        procFromGui(SIG_STATE_H1_N0, SIG_STATE_WAIT_H1_N0, speed);
        break;
    default:
        speedToFld(speed);
        break;
    }
    
}
void SIG_H_N::proc_H1_N1(const UINT8 speed)
{
    switch (mStateToGui)
    {
    case SIG_STATE_UNDEF:
    case SIG_STATE_H0_N0:
    case SIG_STATE_H0_N1:
    case SIG_STATE_H1_N0:

    case SIG_STATE_WAIT_H0_N0:
    case SIG_STATE_WAIT_H0_N1:
    case SIG_STATE_WAIT_H1_N0:

        procFromGui(SIG_STATE_H1_N1, SIG_STATE_WAIT_H1_N1, speed);
        break;
    default:
        speedToFld(speed);
        break;
    }
}

