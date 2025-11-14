#include "../include/ListIterator.h"

ListIterator::ListIterator(Node<int> *node) : current(node) {}

int ListIterator::operator*() const {
    return current->data;
}

void ListIterator::operator++() {
    current = current->next;
}

bool ListIterator::equals(const IteratorInterface &other) const {
    const auto *o = dynamic_cast<const ListIterator *>(&other);
    return o && o->current == current;
}
