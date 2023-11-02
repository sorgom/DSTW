//  ============================================================
//  class Loader implements I_Loader
//  ============================================================
#pragma once
#ifndef LOADER_H
#define LOADER_H

#include <ifs/I_Loader.h>
#include <baselib/coding.h>
#include <baselib/InstanceMacros.h>

class Loader : public I_Loader
{
public:
    inline Loader()
    {}

    void load(const ProjData& data) const;

    IL_INSTANCE_DEC(Loader)

    NOCOPY(Loader)
};


#endif // H_