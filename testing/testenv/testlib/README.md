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

    additional features
    -   set signal type for signal data
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
