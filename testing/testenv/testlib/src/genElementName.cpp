#include <testlib/genElementName.h>

#include <cstdio>
#include <baselib/Mem.h>

namespace test
{

    const ElementName& genElementName(const UINT32 num, const CONST_C_STRING name)
    {
        static ElementName eName = {{""}};
        Mem::zero(eName);
        Mem::set(eName, 0);
        std::sprintf(eName.chars + 1, "%s %03u ", name, num);
        return eName;
    }
    void genElementName(ElementName& eName, const UINT32 num, const CONST_C_STRING name)
    {
        Mem::copy(eName, genElementName(num, name));
    }

} // namespace