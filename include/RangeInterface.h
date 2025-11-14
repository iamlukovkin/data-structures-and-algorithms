#ifndef RANGE_INTERFACE_H
#define RANGE_INTERFACE_H

#include "GraphIterator.h"

struct RangeInterface {
    virtual ~RangeInterface() = default;

    virtual GraphIterator begin() = 0;

    virtual GraphIterator end() = 0;
};

#endif
