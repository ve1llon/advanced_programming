#ifndef FLYWEIGHT_LEAVES_H
#define FLYWEIGHT_LEAVES_H

#include <iostream>
#include <memory>

#include "composite.h"

class Variable : public Expression {
public:
    Variable(const std::string& nname){
        name = nname;
    }

    void Print() override {
        std::cout << name;
    }

    double Calculate(std::map<std::string, double>& context) override {
        return context[name];
    }

private:
    std::string name;
};

class Constant : public Expression {
public:
    Constant(double nvalue){
        value = nvalue;
    }

    void Print() override {
        std::cout << value;
    }

    double Calculate(std::map<std::string, double>& context) override {
        return value;
    }

private:
    double value;
};

class ExpressionFactory {
public:
    ExpressionFactory() {
        for (int i = -5; i <= 256; ++i)
            constants[i] = std::make_shared<Constant>(i);
    }

    std::shared_ptr<Constant> CreateConstant(double nvalue) {
        if ((nvalue == static_cast<int>(nvalue)) && (nvalue >= -5 && nvalue <= 256))
            return constants[nvalue];
        else
            return std::make_shared<Constant>(nvalue);
    }

    std::shared_ptr<Variable> CreateVariable(const std::string& nname) {
        return std::make_shared<Variable>(nname);
    }

private:
    std::map<double, std::shared_ptr<Constant>> constants;
};

#endif // FLYWEIGHT_LEAVES_H
