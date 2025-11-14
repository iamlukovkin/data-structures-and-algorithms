#include "../include/VectorIterator.h"

VectorIterator::VectorIterator(int *ptr) : current(ptr) {}

int VectorIterator::operator*() const {
    return *current;
}

void VectorIterator::operator++() {
    ++current;
}

bool VectorIterator::equals(const IteratorInterface &other) const {
    const auto *o = dynamic_cast<const VectorIterator *>(&other);
    return o && o->current == current;
}
