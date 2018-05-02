#include "../wallet/stdafx.h"

Operation::Operation()
{
    // m_op_code_map.emplace("OP_1",&OP_1);

}

std::stack<std::string>& Operation::OP_1(std::stack<std::string>& a_stack)
{
    a_stack.push("1");
    return a_stack;
}

std::stack<std::string>& OP_0(std::stack<std::string>& a_stack)
{
    a_stack.push({});
    return a_stack;
}

std::stack<std::string>& OP_FALSE(std::stack<std::string>& a_stack)
{
    a_stack.push({});
    return a_stack;
}

std::stack<std::string>& OP_ADD(std::stack<std::string>& a_stack)
{
    int x = std::stoi(a_stack.top());
    a_stack.pop();
    int y = std::stoi(a_stack.top());
    a_stack.pop();

    a_stack.push(std::to_string(x+y));
    return a_stack;
}

std::stack<std::string>& OP_EQUAL(std::stack<std::string>& a_stack)
{
    std::string x = a_stack.top();
    a_stack.pop();
    std::string y = a_stack.top();
    a_stack.pop();

    if(x==y)
    {
        a_stack.push("1");
    }
    else
    {
        a_stack.push("0");
    }
    return a_stack;
}

std::stack<std::string>& Operation::call_operation(std::string a_code,std::stack<std::string> &a_stack)
{
    if(a_code == "OP_1")
    {
        a_stack = OP_1(a_stack);
        return a_stack;
    }
}