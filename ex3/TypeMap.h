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
        constexpr size_t index = types::template GetIndex<T>();
        values.insert({index, value});
    }

    template<typename T>
    T GetValue(){
        try {
            constexpr size_t index = types::template GetIndex<T>();
            std::variant<V...> variantValue = values.at(index);
            return std::get<T>(variantValue);
        } catch (...) {
            std::cout << "Invalid Value" << std::endl;
        }
    }

    template<typename T>
    bool Contains(){
        return types::template IsIncluded<T>;
    }

    template<typename T>
    void RemoveValue(){
        constexpr size_t index = types::template GetIndex<T>();
        values.erase(index);
    }

private:
    std::unordered_map<size_t, std::variant<V...>> values;
    using types = TypeList<V...>;

};

#endif // TYPEMAP_H
