#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <iostream>
#include <memory>

#include "composite.h"

class Addition : public Expression {
public:
    Addition(std::shared_ptr<Expression> nfirst, std::shared_ptr<Expression> nsecond){
        first = nfirst;
        second = nsecond;
    }

    void Print() override {
        std::cout << "(";
        first->Print();
        std::cout << "+";
        second->Print();
        std::cout << ")";
    }

    double Calculate(std::map<std::string, double>& context) override {
        return first->Calculate(context) + second->Calculate(context);
    }

private:
    std::shared_ptr<Expression> first;
    std::shared_ptr<Expression> second;
};


class Subtraction : public Expression {
public:
    Subtraction(std::shared_ptr<Expression> nfirst, std::shared_ptr<Expression> nsecond){
        first = nfirst;
        second = nsecond;
    }

    void Print() override {
        std::cout << "(";
        first->Print();
        std::cout << "-";
        second->Print();
        std::cout << ")";
    }

    double Calculate(std::map<std::string, double>& context) override {
        return first->Calculate(context) - second->Calculate(context);
    }

private:
    std::shared_ptr<Expression> first;
    std::shared_ptr<Expression> second;
};


class Multiplication : public Expression {
public:
    Multiplication(std::shared_ptr<Expression> nfirst, std::shared_ptr<Expression> nsecond){
        first = nfirst;
        second = nsecond;
    }

    void Print() override {
        std::cout << "(";
        first->Print();
        std::cout << "*";
        second->Print();
        std::cout << ")";
    }

    double Calculate(std::map<std::string, double>& context) override {
        return first->Calculate(context) * second->Calculate(context);
    }

private:
    std::shared_ptr<Expression> first;
    std::shared_ptr<Expression> second;
};


#endif // COMPONENTS_H
