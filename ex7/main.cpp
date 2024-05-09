#include "abstraction.h"

int main() {

    std::cout << "first: " << std::endl;

    mVector<int> vect1;
    Set<int> set1(&vect1, 5);

    set1.AddElem(1);
    std::cout << "set1.IsIncludeedElem(1) = " << set1.IsIncludeedElem(1) << std::endl;
    set1.AddElem(3);
    std::cout << "set1.IsIncludeedElem(3) = " << set1.IsIncludeedElem(3) << std::endl;
    set1.DelElem(3);
    std::cout << "set1.IsIncludeedElem(3) = " << set1.IsIncludeedElem(3) << std::endl;
    set1.AddElem(7);
    set1.AddElem(5);

    std::cout << "set1 include: " << std::endl;
    for (size_t i = 0; i < set1.GetSize(); ++i)
        std::cout << set1.GetElem(i) << std::endl;


    std::cout << "second: " << std::endl;

    mVector<int> vect2;
    Set<int> set2(&vect2, 5);

    set2.AddElem(67);
    set2.AddElem(3);
    set2.AddElem(5);
    set2.AddElem(9);

    std::cout << "set2 include: " << std::endl;
    for (size_t i = 0; i < set2.GetSize(); ++i)
        std::cout << set2.GetElem(i) << std::endl;


    std::cout << "third: " << std::endl;

    Set<int> u_set = set1.UnionSets(&set2);

    std::cout << "u_set include: " << std::endl;
    for (size_t i = 0; i < u_set.GetSize(); ++i)
        std::cout << u_set.GetElem(i) << std::endl;


    std::cout << "fourth: " << std::endl;

    Set<int> it_set = set1.IntersectSets(&set2);

    std::cout << "it_set include: " << std::endl;
    for (size_t i = 0; i < it_set.GetSize(); ++i) {
        std::cout << it_set.GetElem(i) << std::endl;
    }


    std::cout << "fifth: " << std::endl;

    set1.AddElem(34);
    set1.AddElem(77);
    set1.AddElem(64);
    set1.AddElem(-23);
    set1.AddElem(45);
    set2.AddElem(77);
    set2.AddElem(3);
    set2.AddElem(-1);
    set2.AddElem(23);

    std::cout << "set1 include: " << std::endl;
    for (size_t i = 0; i < set1.GetSize(); ++i)
        std::cout << set1.GetElem(i) << std::endl;

    std::cout << "set2 include: " << std::endl;
    for (size_t i = 0; i < set2.GetSize(); ++i)
        std::cout << set2.GetElem(i) << std::endl;


    std::cout << "sixth: " << std::endl;

    Set<int> u_set2 = set1.UnionSets(&set2);

    std::cout << "u_set2 include: " << std::endl;
    for (size_t i = 0; i < u_set2.GetSize(); ++i)
        std::cout << u_set2.GetElem(i) << std::endl;


    std::cout << "seventh: " << std::endl;

    Set<int> it_set2 = set1.IntersectSets(&set2);

    std::cout << "it_set include: " << std::endl;
    for (size_t i = 0; i < it_set2.GetSize(); ++i) {
        std::cout << it_set2.GetElem(i) << std::endl;
    }

    return 0;
}
