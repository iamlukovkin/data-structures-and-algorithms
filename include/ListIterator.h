#ifndef LIST_ITERATOR_H
#define LIST_ITERATOR_H

#include "Node.h"
#include "IteratorInterface.h"

struct ListIterator : public IteratorInterface {
    Node<int> *current;

    explicit ListIterator(Node<int> *node);

    int operator*() const override;

    void operator++() override;

    [[nodiscard]] bool equals(const IteratorInterface &other) const override;
};

#endif
