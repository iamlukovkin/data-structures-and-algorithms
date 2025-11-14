#include "../include/GraphIterator.h"

GraphIterator::GraphIterator(IteratorInterface *it) : impl(it) {}

GraphIterator::~GraphIterator() {
    delete impl;
}

int GraphIterator::operator*() const {
    return (*impl).operator*();
}

GraphIterator &GraphIterator::operator++() {
    (*impl).operator++();
    return *this;
}

bool GraphIterator::operator!=(const GraphIterator &other) const {
    return !impl->equals(*other.impl);
}
