#ifndef GRAPH_ITERATOR_H
#define GRAPH_ITERATOR_H

#include "IteratorInterface.h"

class GraphIterator {
private:
    IteratorInterface *impl;
public:
    explicit GraphIterator(IteratorInterface *it);

    ~GraphIterator();

    int operator*() const;

    GraphIterator &operator++();

    bool operator!=(const GraphIterator &other) const;
};

#endif
