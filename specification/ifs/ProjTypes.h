//  ============================================================
//  projectation data types
//  ============================================================
//  created by Manfred Sorgo
#pragma once
#ifndef PROJTYPES_H
#define PROJTYPES_H

#include "ComTypes.h"

#include <codebase/packBegin.h>

struct ProjTSW
{
    ComName name;
};
static_assert(NumComNameChars == sizeof(ProjTSW));

struct ProjSIG
{
    ComName name;
    INT32 type;
};
static_assert(NumComNameChars + SI32 == sizeof(ProjSIG));

struct ProjLCR
{
    ComName name;
    INT32 type;
};
static_assert(NumComNameChars + SI32 == sizeof(ProjLCR));

struct ProjSEG
{
    ComName name;
};
static_assert(NumComNameChars == sizeof(ProjSEG));

#include <codebase/packEnd.h>

#endif // H_