//  ============================================================
//  interface TSW_Hub
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef I_TSW_HUB_H
#define I_TSW_HUB_H

#include "ComTypes.h"

class I_TSW_Hub
{
public:
    virtual void toFld(size_t id, UINT8 cmd) const = 0;
    virtual void toGui(size_t id, UINT8 state) const = 0;

    virtual void fromDsp(size_t pos, const FldState& tele) const = 0;
    virtual void fromDsp(size_t pos, const GuiCmd&   tele) const = 0;
};

#endif // _H