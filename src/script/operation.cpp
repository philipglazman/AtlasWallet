#include "../wallet/stdafx.h"

/**
 * @brief Construct a new Operation:: Operation object
 * 
 * @author Philip Glazman
 * @date 5/2/18
 */
Operation::Operation()
{
    // m_op_code_map.emplace("OP_1",&OP_1);

};

/**
 * @brief Operator for pushing value "1" onto the stack.
 * 
 * @param a_stack 
 * @return std::stack<std::string>& 
 * 
 * @author Philip Glazman
 * @date 5/2/18
 */
std::stack<std::string>&
Operation::OP_1(std::stack<std::string>& a_stack)
{
    a_stack.push("1");
    return a_stack;
};

/**
 * @brief Operator for pushing an emptry array onto the stack.
 * 
 * @param a_stack 
 * @return std::stack<std::string>& 
 * 
 * @author Philip Glazman
 * @date 5/2/18
 */
std::stack<std::string>&
OP_0(std::stack<std::string>& a_stack)
{
    a_stack.push({});
    return a_stack;
};

/**
 * @brief Operator for pushing empty array onto the stack.
 * 
 * @param a_stack 
 * @return std::stack<std::string>& 
 * 
 * @author Philip Glazman
 * @date 5/2/18
 */
std::stack<std::string>&
OP_FALSE(std::stack<std::string>& a_stack)
{
    a_stack.push({});
    return a_stack;
};

/**
 * @brief Operator for popping two top items, adding them, and pushing result onto stack.
 * 
 * @param a_stack 
 * @return std::stack<std::string>& 
 * 
 * @author Philip Glazman
 * @date 5/2/18
 */
std::stack<std::string>&
OP_ADD(std::stack<std::string>& a_stack)
{
    int x = std::stoi(a_stack.top());
    a_stack.pop();
    int y = std::stoi(a_stack.top());
    a_stack.pop();

    a_stack.push(std::to_string(x+y));
    return a_stack;
};

/**
 * @brief Operator for pushing 1 if top two items are equal, push 0 if otherwise.
 * 
 * @param a_stack 
 * @return std::stack<std::string>& 
 * 
 * @author Philip Glazman
 * @date 5/2/18
 */
std::stack<std::string>&
OP_EQUAL(std::stack<std::string>& a_stack)
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
};

/**
 * @brief Operator for incrementing top value of stack.
 * 
 * @param a_stack 
 * @return std::stack<std::string>& 
 * 
 * @author Philip Glazman
 * @date 5/2/18
 */
std::stack<std::string>&
OP_1ADD(std::stack<std::string>& a_stack)
{
    int x = std::stoi(a_stack.top());
    x++;
    a_stack.push(std::to_string(x));
    return a_stack;
}

/**
 * @brief Operator for decrementing top value of stack.
 * 
 * @param a_stack 
 * @return std::stack<std::string>& 
 * 
 * @author Philip Glazman
 * @date 5/2/18
 */
std::stack<std::string>&
OP_1SUB(std::stack<std::string>& a_stack)
{
    int x = std::stoi(a_stack.top());
    x--;
    a_stack.push(std::to_string(x));
    return a_stack;
}

/**
 * @brief Calls appropriate operation codes and changes stack.
 * 
 * @param a_code 
 * @param a_stack 
 * @return std::stack<std::string>& 
 * 
 * @author Philip Glazman
 * @date 5/2/18
 */
std::stack<std::string>&
Operation::call_operation(std::string a_code,std::stack<std::string> &a_stack)
{
    if(a_code.length() == 1)
    {
        try
        {
            // Change to integer.
            int n = std::stoi(a_code);

            // 1- 75
            if(n > 0 && n < 76)
            {
                a_stack.push(std::to_string(n));
                return a_stack;
            };
        }
        catch(std::exception e)
        {
            std::cout << e.what() << std::endl;
        }
    };

    if(a_code == "OP_1")
    {
        a_stack = OP_1(a_stack);
        return a_stack;
    }

    if(a_code == "OP_ADD")
    {
        a_stack = OP_ADD(a_stack);
        return a_stack;
    }

    if(a_code == "OP_EQUAL")
    {
        a_stack = OP_EQUAL(a_stack);
        return a_stack;
    }
};