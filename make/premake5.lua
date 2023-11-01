--  ============================================================
--  Makefile build rules for premake5:
--  ============================================================

--  ============================================================
--  > tests.make
--  module tests and system tests at once runtime
--  ->  bin/tests
--  ============================================================
workspace 'tests'
    configurations { 'ci' }
    language    'C++'
    objdir      'obj/%{prj.name}'

    includedirs {
        '../testing/testenv',
        '../specification',
        '../application',
        '../application/modules',
        '../devel'
    }

    buildoptions { '-std=c++98 -pedantic-errors' }

    project 'tests'
        kind        'ConsoleApp'
        targetdir   'bin'

        files { 
            '../application/modules/**.cpp',
            '../testing/testenv/**.cpp',
            '../testing/tests/**.cpp'
        }

        defines { 'NDEBUG' }
        optimize 'On'
        libdirs { '../BuildCppUTest/lib' }
        links { 'CppUTest', 'CppUTestExt' }

--  ============================================================
--  > coverage.make
--  -   coverage instrumented application (static lib)
--  -   module tests only runtime
--  ->  bin/coverage_tests
--  ============================================================
workspace 'coverage'
    configurations { 'ci' }
    language    'C++'
    objdir      'obj/%{prj.name}'

    includedirs {
        '../testing/testenv',
        '../specification',
        '../application',
        '../application/modules',
        '../devel'
    }

    buildoptions { '-std=c++98 -pedantic-errors' }

    project 'coverage_app'
        kind        'StaticLib'
        targetdir   'lib'
        
        files { 
            '../application/modules/**.cpp',
        }

        defines { 'DEBUG' }
        symbols 'On'
        buildoptions {'-fprofile-arcs -ftest-coverage'}

    project 'coverage_tests'
        kind        'ConsoleApp'
        targetdir   'bin'

        files { 
            '../testing/testenv/**.cpp',
            '../testing/tests/moduletests/**.cpp'
        }

        defines { 'DEBUG' }
        symbols 'On'

        libdirs { 'lib', '../BuildCppUTest/lib' }
        links { 'coverage_app', 'CppUTest', 'CppUTestExt', 'gcov' }
        linkoptions { '--coverage' }

--  ============================================================
--  > dstw.make
--  application runtime
--  ->  bin/dstw
--  ============================================================
workspace 'dstw'
    configurations { 'ci' }
    language    'C++'
    objdir      'obj/%{prj.name}'

    includedirs {
        '../specification',
        '../application',
        '../application/modules',
    }

    buildoptions { '-std=c++98 -pedantic-errors' }

    project 'dstw'
        kind        'ConsoleApp'
        targetdir   'bin'
        
        files { 
            '../application/**.cpp'
        }

        defines { 'NDEBUG' }
        optimize 'On'
    

