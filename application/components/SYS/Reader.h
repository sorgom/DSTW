//  ============================================================
//  class Reader implements I_Reader
//  ============================================================
#pragma once

#include <ifs/I_Reader.h>
#include <BAS/coding.h>

class Reader : public I_Reader
{
public:
    inline Reader() = default;
    void read(CONST_C_STRING filename) const;

    INSTANCE_DEC(Reader)
    NOCOPY(Reader)
};
