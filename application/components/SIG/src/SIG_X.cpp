#include <SIG/SIG_X.h>
#include <SYS/IL.h>


void SIG_X::procFromFld(const INT32 state, INT32 speed)
{
    //  ============================================================
    //  field values are only forwrded to GUI
    //  if GUI state or GUI speed differs
    //  ============================================================
    bool ok = (mStateToGui != state);

    switch (state)
    {
        case SIG_STATE_UNDEF:
            speed = 0;
            break;
        case SIG_STATE_DEFECT:
            speed = 0;
            break;
        default:
            ok = ok or (mSpeedToGui != speed);
            break;
    }

    if (ok)
    {
        mStateToGui = state;
        mSpeedToGui = speed;
        IL::getSIG_Hub().toGui(mId, mStateToGui, mSpeedToGui);
    }
    else
    {pass();}
}

void SIG_X::procFromGui(const INT32 state, const INT32 speed)
{
    //  ============================================================
    //  GUI values are NOT forwarded to field if
    //  already reported to GUI 
    //  OR
    //  already sent to field
    //  ============================================================
    if (
        (mStateToGui == state) and 
        (mSpeedToGui == speed)
    )
    {pass();}
    else if (
        (mStateToFld == state) and 
        (mSpeedToFld == speed)
    )
    {pass();}
    else
    {
        mStateToFld = state;
        mSpeedToFld = speed;
        mStateToGui = SIG_STATE_WAIT;
        IL::getSIG_Hub().toFld(mId, mStateToFld, mSpeedToFld);
        IL::getSIG_Hub().toGui(mId, mStateToGui, mSpeedToGui);
    }
}

void SIG_X::logMissmatch()
{
    IL::getLog().log(MOD_SIG, ERR_MATCH);
}

void SIG_H::fromFld(const INT32 state, const INT32 speed)
{
    bool ok = true;
    switch (state)
    {
    case SIG_STATE_H0:
        break;    
    case SIG_STATE_H1:
        break;    
    case SIG_STATE_UNDEF:
        break;    
    case SIG_STATE_DEFECT:
        break;    
    default:
        ok = false;
        break;    
    };

    if (ok)
    {
        procFromFld(state, 0);
    }
    else
    {
        logMissmatch();
    }
}

void SIG_H::fromGui(const INT32 state, const INT32 speed)
{
    bool ok = true;
    switch (state)
    {
    case SIG_STATE_H0:
        break;    
    case SIG_STATE_H1:
        break;    
    default:
        ok = false;
        break;    
    };

    if (ok)
    {
        procFromGui(state, 0);
    }
    else
    {
        logMissmatch();
    }
}

void SIG_N::fromFld(const INT32 state, const INT32 speed)
{
    bool ok = true;
    switch (state)
    {
    case SIG_STATE_N0:
        break;    
    case SIG_STATE_N1:
        break;    
    case SIG_STATE_UNDEF:
        break;    
    case SIG_STATE_DEFECT:
        break;    
    default:
        ok = false;
        break;    
    };

    if (ok)
    {
        procFromFld(state, speed);
    }
    else
    {
        logMissmatch();
    }
}

void SIG_N::fromGui(const INT32 state, const INT32 speed)
{
    bool ok = true;
    switch (state)
    {
    case SIG_STATE_N0:
        break;    
    case SIG_STATE_N1:
        break;    
    default:
        ok = false;
        break;    
    };

    if (ok)
    {
        procFromGui(state, speed);
    }
    else
    {
        logMissmatch();
    }
}

void SIG_H_N::fromFld(const INT32 state, const INT32 speed)
{
    bool ok = true;
    switch (state)
    {
    case SIG_STATE_H0_N0:
        break;    
    case SIG_STATE_H0_N1:
        break;    
    case SIG_STATE_H1_N0:
        break;    
    case SIG_STATE_H1_N1:
        break;    
    case SIG_STATE_UNDEF:
        break;    
    case SIG_STATE_DEFECT:
        break;    
    default:
        ok = false;
        break;    
    };

    if (ok)
    {
        procFromFld(state, speed);
    }
    else
    {
        logMissmatch();
    }
}

void SIG_H_N::fromGui(const INT32 state, const INT32 speed)
{
    bool ok = true;
    switch (state)
    {
    case SIG_STATE_H0_N0:
        break;    
    case SIG_STATE_H0_N1:
        break;    
    case SIG_STATE_H1_N0:
        break;    
    case SIG_STATE_H1_N1:
        break;    
    default:
        ok = false;
        break;    
    };

    if (ok)
    {
        procFromGui(state, speed);
    }
    else
    {
        logMissmatch();
    }
}