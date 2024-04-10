#ifndef TYPEMAP_H
#define TYPEMAP_H

#include <unordered_map>
#include <variant>
#include "TypeList.h"

template<typename... V>
class TypeMap{
public:
    TypeMap() {};

    template<typename T>
    void AddValue(T value){
        constexpr int index = types::template GetIndex<T>();
        values[index] = value;
    }

    template<typename T>
    T GetValue(){
        constexpr int index = types::template GetIndex<T>();
        std::variant<V...> variantValue = values.at(index);
        return std::get<T>(variantValue);
    }

    template<typename T>
    bool Contains(){
        return types::template IsIncluded<T>;
    }

    template<typename T>
    void RemoveValue(){
        constexpr int index = types::template GetIndex<T>();
        values.erase(index);
    }

private:
    std::unordered_map<int, std::variant<V...>> values;
    using types = TypeList<V...>;

};

#endif // TYPEMAP_H
