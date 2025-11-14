#ifndef LIST_RANGE_H
#define LIST_RANGE_H

#include "RangeInterface.h"
#include "Node.h"
#include "ListIterator.h"

struct ListRange : public RangeInterface {
    Node<int> *_head;

    explicit ListRange(Node<int> *head);

    GraphIterator begin() override;

    GraphIterator end() override;
};

#endif
