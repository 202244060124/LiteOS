/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Test Runner Used To Run Each Test Below=====*/
#define RUN_TEST_NO_ARGS
#define RUN_TEST(TestFunc, TestLineNum, ...)                    \
    {                                                           \
        Unity.CurrentTestName = #TestFunc "(" #__VA_ARGS__ ")"; \
        Unity.CurrentTestLineNumber = TestLineNum;              \
        Unity.NumberOfTests++;                                  \
        if (TEST_PROTECT()) {                                   \
            setUp();                                            \
            TestFunc(__VA_ARGS__);                              \
        }                                                       \
        if (TEST_PROTECT() && !TEST_IS_IGNORED) {               \
            tearDown();                                         \
        }                                                       \
        UnityConcludeTest();                                    \
    }

/*=======Automagically Detected Files To Include=====*/
#include <setjmp.h>
#include <stdio.h>
#include "funky.h"
#include "stanky.h"
#include "unity.h"


/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_TheFirstThingToTest(void);
extern void test_TheSecondThingToTest(void);
extern void test_TheThirdThingToTest(void);
extern void test_TheFourthThingToTest(void);

/*=======Test Reset Option=====*/
void resetTest(void);
void resetTest(void)
{
    tearDown();
    setUp();
}

/*=======MAIN=====*/
int main(void)
{
    UnityBegin("testdata/testsample.c");
    RUN_TEST(test_TheFirstThingToTest, 21, RUN_TEST_NO_ARGS);
    RUN_TEST(test_TheSecondThingToTest, 43, RUN_TEST_NO_ARGS);
    RUN_TEST(test_TheThirdThingToTest, 53, RUN_TEST_NO_ARGS);
    RUN_TEST(test_TheFourthThingToTest, 58, RUN_TEST_NO_ARGS);

    return (UnityEnd());
}
