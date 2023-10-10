#pragma once
#ifndef SIGNALPORT_H
#define SIGNALPORT_H

#include <ifs/I_SignalPort.h>
#include <baselib/InstanceMacros.h>

class SignalPort : public I_SignalPort
{
public:
    inline void toFld(E_SigToFld cmd) const {}
    inline void toGui(E_SigToGui cmd) const {}

    DDI_INSTANCE_DEC(SignalPort)
};

#endif // _H
