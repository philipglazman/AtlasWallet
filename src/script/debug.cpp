#include "../wallet/stdafx.h"

int main()
{
    std::stack<std::string> my_stack;

    Operation operators;

    operators.call_operation("1",my_stack);
    operators.call_operation("2",my_stack);
    operators.call_operation("OP_ADD",my_stack);
    operators.call_operation("4",my_stack);
    operators.call_operation("OP_EQUAL",my_stack);

    while(!my_stack.empty())
    {
        std::cout << my_stack.top() << std::endl;
        my_stack.pop();
    }
}
