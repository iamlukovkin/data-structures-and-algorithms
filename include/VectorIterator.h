#ifndef VECTOR_ITERATOR_H
#define VECTOR_ITERATOR_H

#include "IteratorInterface.h"

struct VectorIterator : public IteratorInterface {
    int *current;

    explicit VectorIterator(int *ptr);

    int operator*() const override;

    void operator++() override;

    [[nodiscard]] bool equals(const IteratorInterface &other) const override;
};

#endif
