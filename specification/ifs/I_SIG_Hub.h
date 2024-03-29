//  ============================================================
//  interface SIG_Hub
//  ============================================================
//  created by Manfred Sorgo
#pragma once
#ifndef I_SIG_HUB_H
#define I_SIG_HUB_H

#include "ComTypes.h"

class I_SIG_Hub
{
public:
    virtual void toFld(size_t id, UINT8 state, UINT8 speed = 0) const = 0;
    virtual void toGui(size_t id, UINT8 state, UINT8 speed = 0) const = 0;

    virtual void fromDsp(size_t pos, const ComFldState& tele) const = 0;
    virtual void fromDsp(size_t pos, const ComGuiCmd&   tele) const = 0;
};

#endif // H_