#ifndef ABSTRACTION_H
#define ABSTRACTION_H

#include <iostream>
#include <vector>

#include "abstract_realization.h"
#include "concrete_realization.h"

template <typename T>
class Set {
public:
    Set(Storage<T>* st, size_t n){
        storage =  st;
        N = n;
    }

    void AddElem(T elem){
        storage->Add(elem);
        if (storage->GetSize() == N)
            StorageEdit();
    }

    void DelElem(T elem){
        storage->Del(elem);
        if (storage->GetSize() == N)
            StorageEdit();
    }

    bool IsIncludeedElem(T elem){
        return storage->IsIncludeed(elem);
    }

    Set UnionSets(Set* other){
        return Set(storage->Union(other->storage), N);
    }

    Set IntersectSets(Set* other){
        return Set(storage->Intersect(other->storage), N);
    }

    void StorageEdit(){
        if (mVector<T>* mvect = dynamic_cast<mVector<T>*>(storage)){
            Storage<T>* new_table = new mHashTable<T>;

            for (size_t i = 0; i < mvect->GetSize(); ++i){
                T new_elem = mvect->GetElem(i);
                new_table->Add(new_elem);
            }
            storage = new_table;

        }
        else if (mHashTable<T>* mtable = dynamic_cast<mHashTable<T>*>(storage)){
            Storage<T>* new_vect = new mVector<T>;

            for (size_t i = 0; i < mtable->GetSize(); ++i){
                T new_elem = mtable->GetElem(i);
                new_vect->Add(new_elem);
            }

            storage = new_vect;
        }
    }

    size_t GetSize(){
        return storage->GetSize();
    }

    T GetElem(size_t i){
        return storage->GetElem(i);
    }

private:
    Storage<T>* storage;
    size_t N;
};

#endif // ABSTRACTION_H
