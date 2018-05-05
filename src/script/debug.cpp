#include "../wallet/stdafx.h"

int main()
{
    /*std::stack<std::string> my_stack;
    Operation operators;
    operators.call_operation("1",my_stack);
    operators.call_operation("2",my_stack);
    operators.call_operation("OP_ADD",my_stack);
    operators.call_operation("3",my_stack);
    operators.call_operation("OP_EQUAL",my_stack);
    while(!my_stack.empty())
    {
        std::cout << my_stack.top() << std::endl;
        my_stack.pop();
    }*/

    Script my_script;

    std::string witness = "1 2";
    std::string witness_script = "OP_ADD 4 OP_EQUAL";
    my_script.build_script(witness, witness_script);
    std::cout << my_script.is_valid() << std::endl;
}
