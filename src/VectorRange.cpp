#include "../include/VectorRange.h"

VectorRange::VectorRange(int *data, size_t size) : _data(data), _size(size) {}

GraphIterator VectorRange::begin() {
    return GraphIterator(new VectorIterator(_data));
}

GraphIterator VectorRange::end() {
    return GraphIterator(new VectorIterator(_data + _size));
}
