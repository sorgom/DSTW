//  ============================================================
//  interface SIG_Provider
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef I_SIG_PROVIDER_H
#define I_SIG_PROVIDER_H

#include "I_SIG.h"
#include "ProjTypes.h"

class I_SIG_Provider
{
public:
    virtual bool has(size_t pos) const = 0;
    virtual I_SIG& at(size_t pos) = 0;

    virtual void reset() = 0;
    virtual void load(const ProjSIG* data, UINT32 num) = 0;
};

#endif // H_