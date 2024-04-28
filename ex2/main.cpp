#include <vector>
#include <string>
#include "ex2.h"

void test1(){
    using nList0 = TypeList<>;
    static_assert(nList0::len == 0);
    static_assert(!nList0::IsIncluded<int>);

    using nList1 = nList0::Append<int>;
    using nList2 = nList1::Append<char>;
    using nList3 = nList2::Append<double>;
    using nList4 = nList3::Append<std::vector<int>>;

    static_assert(std::is_same_v<nList4::GetType_call<0>, int>);
    static_assert(std::is_same_v<nList4::GetType_call<1>, char>);
    static_assert(std::is_same_v<nList4::GetType_call<2>, double>);
    static_assert(std::is_same_v<nList4::GetType_call<3>, std::vector<int>>);
    static_assert(nList4::len == 4);
    static_assert(nList4::GetIndex<int>() == 0);
    static_assert(nList4::GetIndex<char>() == 1);
    static_assert(nList4::GetIndex<double>() == 2);
    static_assert(nList4::GetIndex<std::vector<int>>() == 3);
    static_assert(nList4::IsIncluded<int>);
    static_assert(nList4::IsIncluded<char>);
    static_assert(nList4::IsIncluded<double>);
    static_assert(nList4::IsIncluded<std::vector<int>>);
    static_assert(!nList4::IsIncluded<float>);

    using nList5 = nList4::BeginAdd<std::string>;
    using nList6 = nList5::BeginAdd<std::vector<std::string>>;

    static_assert(std::is_same_v<nList6::GetType_call<0>, std::vector<std::string>>);
    static_assert(std::is_same_v<nList6::GetType_call<1>, std::string>);
    static_assert(std::is_same_v<nList6::GetType_call<2>, int>);
    static_assert(std::is_same_v<nList6::GetType_call<3>, char>);
    static_assert(std::is_same_v<nList6::GetType_call<4>, double>);
    static_assert(std::is_same_v<nList6::GetType_call<5>, std::vector<int>>);
    static_assert(nList6::len == 6);
    static_assert(nList6::GetIndex<std::vector<std::string>>() == 0);
    static_assert(nList6::GetIndex<std::string>() == 1);
    static_assert(nList6::GetIndex<int>() == 2);
    static_assert(nList6::GetIndex<char>() == 3);
    static_assert(nList6::GetIndex<double>() == 4);
    static_assert(nList6::GetIndex<std::vector<int>>() == 5);
    static_assert(nList6::IsIncluded<std::vector<std::string>>);
    static_assert(nList6::IsIncluded<std::string>);
    static_assert(!nList6::IsIncluded<float>);

}

int main(){
    test1();
    return 0;
}
