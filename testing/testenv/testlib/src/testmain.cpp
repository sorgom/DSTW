
#define CPPUTEST_MEM_LEAK_DETECTION_DISABLED


// #include <TestLib/CppUTest.h>
#include <CppUTest/TestHarness.h> // i.a. includes MemoryLeakDetectorNewMacros.h
#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTestExt/MockSupport.h>
#include <CppUTest/TestRegistry.h>

#include <TestStepper/TestStepperPlugin.h>
#include <comparators/installComparators.h>

int main(int argc, char** argv)
{
    // const char* argvDef[] = {"exe", "-v"};

    MemoryLeakWarningPlugin::turnOffNewDeleteOverloads();

    TestStepperPlugin::setup();
    test::installComparators(TestStepperPlugin::instance());

    CommandLineTestRunner::RunAllTests(argc, argv);

    return 0;
}