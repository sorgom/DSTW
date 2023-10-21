//  ============================================================
//  Storage of Name Type Position
//  ============================================================
//  created by Manfred Sorgo

#pragma once
#ifndef NTPARRAY_H
#define NTPARRAY_H

#include <ifs/DataTypes.h>
#include <baselib/StackArray.h>
#include <baselib/Mem.h>

struct Ntp
{
    ElementName name;
    INT32 type;
    UINT32 pos;
};

const Ntp& genNtp(
        const ElementName& name,
        INT32 type = 0,
        UINT32 pos = 0
    );

template <UINT32 CAP>
class NtpArray : public StackArray<Ntp, CAP>
{
public:
    inline bool isGreater(const Ntp& a, const Ntp& b) const
    {
        return Mem::cmp(a.name, b.name) > 0;
    }
    
    inline UINT32 addNtp(const ElementName& name, INT32 type, UINT32 pos)
    {
        return this->add(genNtp(name, type, pos));
    }
};

template <UINT32 CAP>
class NtpIndex : public StackArrayIndex<Ntp, CAP>
{
public:
    inline NtpIndex(const NtpArray<CAP>& a):
        StackArrayIndex<Ntp, CAP>(a)
    {}

    inline INT32 findNtp(const ElementName& name) const
    {
        return this->findRef(genNtp(name));
    }
};

#endif // H_