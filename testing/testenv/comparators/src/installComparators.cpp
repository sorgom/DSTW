#include <comparators/installComparators.h>

#include <ifs/ComTypes.h>
#include <comparators/Comparator.h>
#include <comparators/ostreams.h>
#include <testlib/TestLiterals.h>

#define ADD_COMP(NAME) \
    static Comparator<NAME> cmp_ ## NAME; \
    plugin.installComparator(c__ ## NAME, cmp_ ## NAME);

namespace test
{
    void installComparators(MockSupportPlugin& plugin)
    {
        //# ADD_COMP
        ADD_COMP(ComCmdFld)
        ADD_COMP(ComFldState)
        ADD_COMP(ComGuiCmd)
        ADD_COMP(ComName)
        ADD_COMP(ComStateGui)
        //# END
    }
}
