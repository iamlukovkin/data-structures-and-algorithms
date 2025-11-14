#ifndef ITERATOR_INTERFACE_H
#define ITERATOR_INTERFACE_H

struct IteratorInterface {
    virtual ~IteratorInterface() = default;

    virtual int operator*() const = 0;

    virtual void operator++() = 0;

    [[nodiscard]] virtual bool equals(const IteratorInterface &other) const = 0;
};

#endif
