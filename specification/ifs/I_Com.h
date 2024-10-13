//  ============================================================
//  Interface Com
//  - field and GUI communication device
//  ============================================================
//  created by Manfred Sorgo

#pragma once

#include "DataTypes.h"

class I_Com
{
public:
    virtual void run() = 0;
    virtual void stop() = 0;
    virtual void toFld(const ComTele& tele) const = 0;
    virtual void toGui(const ComTele& tele) const = 0;
};
