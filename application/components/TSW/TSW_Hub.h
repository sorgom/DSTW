//  ============================================================
//  class TSW_Hub implements I_TSW_Hub
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef TSW_HUB_H
#define TSW_HUB_H

#include <BAS/coding.h>
#include <ifs/I_Hub.h>

class TSW_Hub : public I_TSW_Hub
{
public:
    inline TSW_Hub() = default;

    void toFld(size_t id, UINT8 param1, UINT8 param2 = PARAM_UNDEF) const;
    void toGui(size_t id, UINT8 param1, UINT8 param2 = PARAM_UNDEF) const;

    void fromDsp(size_t pos, const ComTeleFld& tele) const;
    void fromDsp(size_t pos, const ComTeleGui& tele) const;

    IL_INSTANCE_DEC(TSW_Hub)

    NOCOPY(TSW_Hub)
};

#endif // _H
