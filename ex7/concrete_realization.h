#ifndef CONCRETE_REALIZATION_H
#define CONCRETE_REALIZATION_H

#include <vector>
#include <unordered_set>
#include <algorithm>

#include "abstract_realization.h"

template <typename T>
class mVector: public Storage<T> {
public:
    void Add(T elem) override{
        if (!IsIncludeed(elem))
            mvect.push_back(elem);
    }

    void Del(T elem) override{
        if (IsIncludeed(elem))
            mvect.erase(std::find(mvect.begin(), mvect.end(), elem));
    }

    bool IsIncludeed(T elem) override{
        return (std::find(mvect.begin(), mvect.end(), elem) != mvect.end());
    }

    Storage<T>* Union(Storage<T>* other) override{
        mVector<T>* new_vect = new mVector<T>;

        for (size_t i = 0; i < this->GetSize(); ++i) {
                T new_elem = this->GetElem(i);
                new_vect->Add(new_elem);
        }

        for (size_t i = 0; i < other->GetSize(); ++i) {
            T new_elem = other->GetElem(i);
            if (!new_vect->IsIncludeed(new_elem))
                new_vect->Add(new_elem);
        }
        return new_vect;
    }

    Storage<T>* Intersect(Storage<T>* other) override{
        mVector<T>* new_vect = new mVector<T>;
        for (size_t i = 0; i < other->GetSize(); ++i) {
            T new_elem = other->GetElem(i);
            if (this->IsIncludeed(new_elem))
                new_vect->Add(new_elem);
        }
        return new_vect;
    }

    size_t GetSize() override{
        return mvect.size();
    }

    T GetElem(size_t index) override{
        return mvect[index];
    }

private:
    std::vector<T> mvect;
};


template <typename T>
class mHashTable: public Storage<T> {
public:
    void Add(T elem) override{
        mtable.insert(elem);
    }

    void Del(T elem) override{
        mtable.erase(elem);
    }

    bool IsIncludeed(T elem) override{
        return (mtable.find(elem) != mtable.end());
    }

    Storage<T>* Union(Storage<T>* other) override{
        std::vector<T> mvect;
        mvect.insert(mvect.end(), mtable.begin(), mtable.end());

        mHashTable<T>* new_table = new mHashTable<T>;
        for(auto elem: mvect)
            new_table->Add(elem);

        for (size_t i = 0; i < other->GetSize(); ++i) {
            T new_elem = other->GetElem(i);
            if (!new_table->IsIncludeed(new_elem))
                new_table->Add(new_elem);
        }

        return new_table;
    }

    Storage<T>* Intersect(Storage<T>* other) override{
        mHashTable<T>* new_table = new mHashTable<T>;

        for (size_t i = 0; i < other->GetSize(); ++i) {
            T new_elem = other->GetElem(i);
            if (this->IsIncludeed(new_elem))
                new_table->Add(new_elem);
        }

        return new_table;
    }

    size_t GetSize() override{
        return mtable.size();
    }

    T GetElem(size_t index) override{
        std::vector<T> mvect;
        mvect.insert(mvect.end(), mtable.begin(), mtable.end());
        return mvect[index];
    }


private:
    std::unordered_set<T> mtable;
};

#endif // CONCRETE_REALIZATION_H
