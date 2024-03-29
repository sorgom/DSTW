//  ============================================================
//  test of modules Com, Log (coverage)
//  ============================================================
//  created by Manfred Sorgo
#include <testlib/TestGroupBase.h>
#include <SYS/Com.h>
#include <SYS/Log.h>

namespace test
{
    TEST_GROUP_BASE(SYS_03, TestGroupBase) {};

    //  test type: coverage
    TEST(SYS_03, T01)
    {
        const ComStateGui s {};
        const ComCmdFld   c {};
        Com::instance().send(s);
        Com::instance().send(c);
        Log::instance().log(MOD_SYS_READER, ERR_MATCH);
    }
}