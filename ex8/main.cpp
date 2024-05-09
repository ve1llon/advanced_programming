#include "components.h"
#include "flyweight_leaves.h"

int main() {
    ExpressionFactory factory;
    auto m2 = factory.CreateConstant(2);
    auto g = factory.CreateConstant(9.81);
    auto F = factory.CreateConstant(10.8);

    auto v = factory.CreateVariable("m1");
    auto expression = std::make_shared<Subtraction>(std::make_shared<Multiplication>(std::make_shared<Addition>(v, m2),g),F);

    std::map<std::string, double> context;
    context["m1"] = 1.5;

    std::cout << "Expression: " << std::endl;
    expression->Print();
    std::cout << std::endl;

    std::cout << "Answer: " << std::endl;
    std::cout << expression->Calculate(context) << std::endl;

    return 0;
}
