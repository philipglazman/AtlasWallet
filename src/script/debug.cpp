#include "../wallet/stdafx.h"

int main()
{
    std::stack<std::string> my_stack;

    my_stack.push("2");
    my_stack.push("3");

    Operation operators;

    operators.call_operation("OP_1",my_stack);

    while(!my_stack.empty())
    {
        std::cout << my_stack.top() << std::endl;
        my_stack.pop();
    }
}
