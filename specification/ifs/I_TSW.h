//  ============================================================
//  interface TSW (track switch)
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef I_TSW_H
#define I_TSW_H

#include <codebase/BaseTypes.h>

enum E_TswState : UINT8
{
    TSW_STATE_LEFT = 101,
    TSW_STATE_RIGHT,
    TSW_STATE_UNDEF,
    TSW_STATE_DEFECT,
    TSW_STATE_WAIT_LEFT,
    TSW_STATE_WAIT_RIGHT
};

enum E_TswGuiCmd : UINT8
{
    TSW_GUI_GMD_WU = 201,
    TSW_GUI_GMD_LEFT,
    TSW_GUI_GMD_RIGHT
};

class I_TSW
{
public:
//  commands from GUI
    virtual void fromGui(UINT8 cmd) = 0;

//  infos from field element
    virtual void fromFld(UINT8 state) = 0;
};

#endif // _H