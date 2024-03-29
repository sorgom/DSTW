//  ============================================================
//  interface SIG (signal)
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef I_SIG_H
#define I_SIG_H

#include <codebase/BaseTypes.h>

enum E_SigType : UINT8
{
    SIG_TYPE_H = 100,
    SIG_TYPE_N,
    SIG_TYPE_H_N,
    SIG_TYPE_S
};

enum E_SigState : UINT8
{
    SIG_STATE_UNDEF = 101,
    SIG_STATE_DEFECT,

    SIG_STATE_H0,
    SIG_STATE_H1,
    SIG_STATE_N0,
    SIG_STATE_N1,
    SIG_STATE_H0_N0,
    SIG_STATE_H0_N1,
    SIG_STATE_H1_N0,
    SIG_STATE_H1_N1,

    SIG_STATE_WAIT_H0,
    SIG_STATE_WAIT_H1,
    SIG_STATE_WAIT_N0,
    SIG_STATE_WAIT_N1,
    SIG_STATE_WAIT_H0_N0,
    SIG_STATE_WAIT_H0_N1,
    SIG_STATE_WAIT_H1_N0,
    SIG_STATE_WAIT_H1_N1
};

class I_SIG
{
public:
//  commands from GUI
    virtual void fromGui(UINT8 state, UINT8 speed) = 0;

//  infos from field element
    virtual void fromFld(UINT8 state, UINT8 speed) = 0;

//  type info
    virtual UINT8 type() const = 0;    
};

#endif // _H