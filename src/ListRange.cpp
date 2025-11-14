#include "../include/ListRange.h"

ListRange::ListRange(Node<int> *head)  : _head(head) {}

GraphIterator ListRange::begin() {
    return GraphIterator(new ListIterator(_head));
}

GraphIterator ListRange::end() {
    return GraphIterator(new ListIterator(nullptr));
}
