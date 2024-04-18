#include <iostream>
#include <cassert>

template <typename T>
class less_than_comparable {
public:
    bool operator> (T const& other) const {
        return static_cast<T const&>(*this).value() > other.value();
    }

    bool operator>= (T const& other) const {
        return static_cast<T const&>(*this).value() >= other.value();
    }

    bool operator<= (T const& other) const {
        return static_cast<T const&>(*this).value() <= other.value();
    }

    bool operator== (T const& other) const {
        return static_cast<T const&>(*this).value() == other.value();
    }

    bool operator!= (T const& other) const {
        return static_cast<T const&>(*this).value() != other.value();
    }
};

template <typename T>
class counter {
public:
    counter() { get_count() += 1;}
    ~counter() { get_count() -= 1; }

    static int count() { return get_count(); }

private:
    static int& get_count() {
        static int m_count = 0;
        return m_count;
    }
};

class Number: public less_than_comparable <Number>, public counter <Number> {
public:
    Number(int value): m_value{value} {}

    int value() const { return m_value; }

    bool operator< (Number const& other) const {
        return m_value < other.m_value;
    }
private:
    int m_value;
};

int main(){
    Number one{1};
    Number two{2};
    Number three{3};
    Number four{4};
    assert(one >= one);
    assert(three <= four);
    assert(two == two);
    assert(three > two);
    assert(one < two);
    std::cout << "Count: " << counter<Number>::count() << std::endl;
    return 0;
}
