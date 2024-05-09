#ifndef COMPOSITE_H
#define COMPOSITE_H

#include <string>
#include <map>

class Expression {
public:
    virtual ~Expression() {}

    virtual void Print() = 0;
    virtual double Calculate(std::map<std::string, double>& context) = 0;
};

#endif // COMPOSITE_H
