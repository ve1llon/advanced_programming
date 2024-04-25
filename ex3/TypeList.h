#ifndef TYPELIST_H
#define TYPELIST_H

#include <iostream>
#include <string>

template<typename... nTypes>
struct TypeList{
public:
    template<int i, typename... U>
    struct GetType{};

    template<typename T, typename... U>
    struct GetType<0, T, U...>{
        using ntype = T;
    };

    template<int i, typename T, typename... U>
    struct GetType<i, T, U...>{
        using ntype = typename GetType<i - 1, U...>::ntype;
    };

    template<int i>
    using GetType_call = typename GetType<i, nTypes...>::ntype;


    static constexpr int len = sizeof...(nTypes);


    template<typename T>
    static constexpr int GetIndex(){
        if constexpr (sizeof...(nTypes) > 0){
            if constexpr (std::is_same_v<T, GetType_call<0>>)
                return 0;
            else
                return GetIndex<1, T>();
        }
        else
            return static_cast<int>(-1);
    }

    template<int i, typename T>
    static constexpr int GetIndex(){
        if constexpr (i < sizeof...(nTypes)){
            if constexpr (std::is_same_v<T, GetType_call<i>>)
                return i;
            else
                return GetIndex<i + 1, T>();
        }
        else
            return static_cast<int>(-1);
    }


    template<typename T>
    static constexpr bool IsIncluded = (GetIndex<T>() != static_cast<int>(-1));


    template<typename T>
    using Append = TypeList<nTypes..., T>;


    template<typename T>
    using BeginAdd = TypeList<T, nTypes...>;
};
#endif // TYPELIST_H
