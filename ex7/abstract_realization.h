#ifndef ABSTRACT_REALIZATION_H
#define ABSTRACT_REALIZATION_H

#include <iostream>

template <typename T>
class Storage {
public:

    virtual void Add(T elem) = 0;
    virtual void Del(T elem) = 0;
    virtual bool IsIncludeed(T elem) = 0;
    virtual Storage<T>* Union(Storage<T>* other) = 0;
    virtual Storage<T>* Intersect(Storage<T>* other) = 0;

    virtual size_t GetSize() = 0;
    virtual T GetElem(size_t index) = 0;

    virtual ~Storage(){};
};

#endif // ABSTRACT_REALIZATION_H
