//
// Created by michaelpollind on 1/19/17.
//

#include <cstdio>
#include "RenderingProcedure.h"

RenderingProcedure::RenderingProcedure(RenderingProcedure* next) {
    _next = next;
}

RenderingProcedure::~RenderingProcedure() {
}

RenderingProcedure* RenderingProcedure::GetNextProcedureInChain() {
    return _next;
}