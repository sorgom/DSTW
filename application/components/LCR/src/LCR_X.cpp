#include <LCR/LCR_X.h>
#include <SYS/IL.h>

void LCR_X::open()
{
    switch (mStateToGui)
    {
        case LCR_STATE_UNDEF:
        case LCR_STATE_CLOSED:
        case LCR_STATE_WAIT_CLOSED:
            mStateToGui = LCR_STATE_WAIT_OPEN;
            toGui();
            toFld(LCR_STATE_OPEN);
            break;
        default:
            break;
    }
}

void LCR_X::close()
{
    switch (mStateToGui)
    {
        case LCR_STATE_UNDEF:
        case LCR_STATE_OPEN:
        case LCR_STATE_WAIT_OPEN:
            mStateToGui = LCR_STATE_WAIT_CLOSED;
            toGui();
            toFld(LCR_STATE_CLOSED);
            break;
        default:
            break;
    }
}

void LCR_X::toFld(const UINT8 state) const
{
    IL::getLCR_Hub().toFld(mId, state);
}

void LCR_X::fromGui(const UINT8 state)
{
    switch (state)
    {
        case LCR_STATE_CLOSED:
            close();
            break;
        case LCR_STATE_OPEN:
            open();
            break;
        default:
            IL::getLog().log(MOD_LCR, ERR_MATCH);
            break;
    }
}

bool LCR_X::validState(const UINT8 state)
{
    bool ok = false;
    switch (state)
    {
    case LCR_STATE_UNDEF:
    case LCR_STATE_DEFECT:
    case LCR_STATE_OPEN:
    case LCR_STATE_CLOSED:
        ok = true;
        break;
    default:
        IL::getLog().log(MOD_LCR, ERR_MATCH);
        break;    
    };
    return ok;
}

void LCR::fromFld(const UINT8 state, const UINT8 ubk)
{
    if (state == mStateToGui)
    { pass(); }
    else if (not validState(state))
    { pass(); }
    else
    {
        mStateToGui = state;
        toGui();
    }
}

void LCR::toGui() const
{
    IL::getLCR_Hub().toGui(mId, mStateToGui);
}

bool LCR_UBK::validUbk(const UINT8 state)
{
    bool ok = false;
    switch (state)
    {
    case LCR_UBK_STATE_UNDEF:
    case LCR_UBK_STATE_DEFECT:
    case LCR_UBK_STATE_OCCUPIED:
    case LCR_UBK_STATE_FREE:
        ok = true;
        break;    
    default:
        IL::getLog().log(MOD_LCR, ERR_MATCH);
        break;    
    };
    return ok;
}

void LCR_UBK::fromFld(const UINT8 state, const UINT8 ubk)
{
    if (
        (state == mStateToGui) and
        (ubk   == mUbkToGui)
    )
    { pass(); }
    else if (not (
        validState(state) and 
        validUbk(ubk))
    )
    { pass(); }
    else
    {
        mStateToGui = state;
        mUbkToGui = ubk;
        toGui();
    }
}

void LCR_UBK::toGui() const
{
    IL::getLCR_Hub().toGui(mId, mStateToGui, mUbkToGui);
}