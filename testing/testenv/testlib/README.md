## directory content

**CppUTest.h**
```
frequently used includes of CppUTest
but also
- the TestSteps
- some useful macros

CppUTest parameter macros
raw typing:
    .withParameterOfType("SomeStruct", "param", param)
strin constant c__SomeStruct defined:
    .withParameterOfType(c__SomeStruct, "param", param)
use:
  .TPARAM(SomeStruct, param)

raw typing:
    .withParameter("param", param)
use:
    .PARAM(param)
```

**GenProjData.h**
```
ProjData generator
    presets all proj data
    with element names in reversed alphanumerical order
    from capacity down to 1
    e.g. TSW, capacity 100:
        "TSW 100 *" .. "TSW 001 *"

    dumps data to file

    additional features
    -   set SIG type for signal data
    -   set LCR type for level crossing data
```

**TestArrays.h**
```
array types for test issues

MutableArray
- keeps objects in the same order as they were added
- stores objects of one class
- provides const and mutable object access
- provides C style array access to data
```

**TestGroupBase.h**
```
base CppUTest test group
```

**TestLib.h**
```
basic test features
```

**TestLiterals.h**
```
literals for testing
- header and source content is generated by sript
```
