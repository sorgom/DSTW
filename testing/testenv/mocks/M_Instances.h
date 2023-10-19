//  ============================================================
//  mock instances (for ddi)
//  for interface I_<NAME>
//  - function m_<NAME>() returns mock instance 
//  - function mock_<NAME>() plugs mock instance into ddi
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef M_INSTANCES_H
#define M_INSTANCES_H

#include <ddi/ddi.h>

//## INCLUDES_LOCAL
#include "M_FldCom.h"
#include "M_SignalPort.h"
#include "M_TrackSwitch.h"
#include "M_TrackSwitchFactory.h"
#include "M_TrackSwitchHub.h"
//## END

#define MOCK_DEC(NAME) \
    inline M_ ## NAME& m_ ## NAME() { return M_ ## NAME::instance(); } \
    inline void mock_ ## NAME() { ddi::set ## NAME(m_ ## NAME()); }

namespace test
{
    //# MOCK_DEC
    MOCK_DEC(FldCom)
    MOCK_DEC(SignalPort)
    MOCK_DEC(TrackSwitch)
    MOCK_DEC(TrackSwitchFactory)
    MOCK_DEC(TrackSwitchHub)
    //# END

    inline void unmock() { ddi::reset(); }
}

#endif // _H