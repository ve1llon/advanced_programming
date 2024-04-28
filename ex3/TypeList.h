#ifndef TYPELIST_H
#define TYPELIST_H

#include <iostream>
#include <string>

template<typename... nTypes>
struct TypeList{
public:

    template<size_t i, typename... U>
    struct GetType{};

    template<typename T, typename... U>
    struct GetType<0, T, U...>{
        using ntype = T;
    };

    template<size_t i, typename T, typename... U>
    struct GetType<i, T, U...>{
        using ntype = typename GetType<i - 1, U...>::ntype;
    };

    template<size_t i>
    using GetType_call = typename GetType<i, nTypes...>::ntype;


    static constexpr std::size_t len = sizeof...(nTypes);


    template<typename T>
    static constexpr size_t GetIndex(){
        static_assert(sizeof...(nTypes) > 0, "Incorrect Type");
        if constexpr (std::is_same_v<T, GetType_call<0>>)
            return 0;
        else
            return GetIndex<1, T>();
    }

    template<size_t i, typename T>
    static constexpr size_t GetIndex(){
        static_assert(sizeof...(nTypes) > i, "Incorrect Type");
        if constexpr (std::is_same_v<T, GetType_call<i>>)
            return i;
        else
            return GetIndex<i + 1, T>();
    }

    template<typename T>
    static constexpr bool CheckIsIncluded() {
        return false;
    }

    template<typename T, typename U, typename... V>
    static constexpr bool CheckIsIncluded() {
        return std::is_same_v<T, U> || CheckIsIncluded<T, V...>();
    }

    template<typename T>
    static constexpr bool IsIncluded = CheckIsIncluded<T, nTypes...>();


    template<typename T>
    using Append = TypeList<nTypes..., T>;


    template<typename T>
    using BeginAdd = TypeList<T, nTypes...>;
};

#endif // TYPELIST_H
