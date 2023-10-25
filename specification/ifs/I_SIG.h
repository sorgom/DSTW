//  ============================================================
//  interface SIG
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef I_SIG_TYPE_H
#define I_SIG_TYPE_H

#include <baselib/BaseTypes.h>

enum E_SigType
{
    SIG_TYPE_H = 100,
    SIG_TYPE_N,
    SIG_TYPE_H_N,
    SIG_TYPE_S
};

enum E_SigState
{
    SIG_STATE_H0 = 101,
    SIG_STATE_H1,
    SIG_STATE_N0,
    SIG_STATE_N1,
    SIG_STATE_H0_N0,
    SIG_STATE_H0_N1,
    SIG_STATE_H1_N0,
    SIG_STATE_H1_N1,
    SIG_STATE_UNDEF,
    SIG_STATE_DEFECT,
    SIG_STATE_WAIT
};

class I_SIG
{
public:
//  commands from GUI
    virtual void fromGui(INT32 state, INT32 speed) = 0;

//  infos from field element
    virtual void fromFld(INT32 state, INT32 speed) = 0;

//  type info
    virtual INT32 type() const = 0;    
};

#endif // _H