#ifndef VECTOR_RANGE_H
#define VECTOR_RANGE_H

#include <cstddef>
#include "RangeInterface.h"
#include "VectorIterator.h"

struct VectorRange : public RangeInterface {
    int *_data;
    size_t _size;

    explicit VectorRange(int *data, size_t size);

    GraphIterator begin() override;

    GraphIterator end() override;
};

#endif
