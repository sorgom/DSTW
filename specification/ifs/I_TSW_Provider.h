//  ============================================================
//  interface TSW_Provider
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef I_TSW_PROVIDER_H
#define I_TSW_PROVIDER_H

#include "I_TSW.h"
#include "ProjTypes.h"

class I_TSW_Provider
{
public:
    virtual bool has(size_t pos) const = 0;
    virtual I_TSW& at(size_t pos) = 0;

    virtual void reset() = 0;
    virtual void load(const ProjTSW* data, UINT32 num) = 0;
};

#endif // H_