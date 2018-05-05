/**
 * @brief Implementation of Operation class.
 * 
 * @file operation.cpp
 * @author Philip Glazman
 * @date 5/3/18
 */

#include "../wallet/stdafx.h"

/**
 * @brief Construct a new Operation:: Operation object
 * 
 * @author Philip Glazman
 * @date 5/3/18
 */
Operation::Operation()
{
    // Operation Codes are loaded into hash map for efficient lookup.

    // Insert operation codes for stack manipulation.
    m_op_code_map.emplace("OP_DROP",this->OP_DROP);
    m_op_code_map.emplace("OP_DUP",this->OP_DUP);
    m_op_code_map.emplace("OP_DEPTH",this->OP_DEPTH);
    
    // Insert operation codes for binary arithmetic.
    m_op_code_map.emplace("OP_EQUAL",this->OP_EQUAL);

    // Insert operation codes for arithmetic.
    m_op_code_map.emplace("OP_1ADD",this->OP_1ADD);
    m_op_code_map.emplace("OP_1SUB",this->OP_1SUB);
    m_op_code_map.emplace("OP_NEGATE",this->OP_NEGATE);
    m_op_code_map.emplace("OP_ABS",this->OP_ABS);
    m_op_code_map.emplace("OP_ADD",this->OP_ADD);
    m_op_code_map.emplace("OP_SUB",this->OP_SUB);
    m_op_code_map.emplace("OP_NUMEQUAL",this->OP_NUMEQUAL);
    m_op_code_map.emplace("OP_NUMNOTEQUAL",this->OP_NUMNOTEQUAL);
    m_op_code_map.emplace("OP_LESSTHAN",this->OP_LESSTHAN);
    m_op_code_map.emplace("OP_GREATERTHAN",this->OP_GREATERTHAN);
    m_op_code_map.emplace("OP_LESSTHANOREQUAL",this->OP_LESSTHANOREQUAL);
    m_op_code_map.emplace("OP_GREATERTHANOREQUAL",this->OP_GREATERTHANOREQUAL);
    m_op_code_map.emplace("OP_MIN",this->OP_MIN);
    m_op_code_map.emplace("OP_MAX",this->OP_MAX);
    m_op_code_map.emplace("OP_WITHIN",this->OP_WITHIN);

    // Insert operation codes for cryptography.
    m_op_code_map.emplace("OP_RIPEMD160",this->OP_RIPEMD160);
    m_op_code_map.emplace("OP_SHA1",this->OP_SHA1);
    m_op_code_map.emplace("OP_SHA256",this->OP_SHA256);
    m_op_code_map.emplace("OP_HASH160",this->OP_HASH160);
    m_op_code_map.emplace("OP_HASH256",this->OP_HASH256);
    
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
Operation::stack 
Operation::OP_ADD(Operation::stack  a_stack)
{
    int x = std::stoi(a_stack.top());
    a_stack.pop();
    int y = std::stoi(a_stack.top());
    a_stack.pop();

    a_stack.push(std::to_string(x+y));
    return a_stack;
};

/**
 * @brief Flips the sign of the top item.
 * 
 * @param a_stack 
 * @return std::stack<std::string>& 
 * 
 * @author Philip Glazman
 * @date 5/2/18
 */
std::stack<std::string>&
Operation::OP_NEGATE(std::stack<std::string>& a_stack)
{
    int x = std::stoi(a_stack.top());
    x *= -1;
    
    a_stack.push(std::to_string(x));
    return a_stack;
};

/**
 * @brief Operator for popping two top items, subtracting them, and pushing result onto stack.
 * 
 * @param a_stack 
 * @return std::stack<std::string>& 
 * 
 * @author Philip Glazman
 * @date 5/2/18
 */
std::stack<std::string>&
Operation::OP_SUB(std::stack<std::string>& a_stack)
{
    int x = std::stoi(a_stack.top());
    a_stack.pop();
    int y = std::stoi(a_stack.top());
    a_stack.pop();

    // Subtract first from second
    a_stack.push(std::to_string(y-x));
    return a_stack;
};

/**
 * @brief Operator that returns true if top two items are equal numbers.
 * 
 * @param a_stack 
 * @return std::stack<std::string>& 
 * 
 * @author Philip Glazman
 * @date 5/2/18
 */
std::stack<std::string>&
Operation::OP_NUMEQUAL(std::stack<std::string>& a_stack)
{
    std::string x = a_stack.top();
    a_stack.pop();
    std::string y = a_stack.top();
    a_stack.pop();

    if(x==y)
    {
        a_stack.push("TRUE");
    }
    else
    {
        a_stack.push("FALSE");
    }
    return a_stack;
};

/**
 * @brief Operator that returns true if top two items are not equal numbers.
 * 
 * @param a_stack 
 * @return std::stack<std::string>& 
 * 
 * @author Philip Glazman
 * @date 5/2/18
 */
std::stack<std::string>&
Operation::OP_NUMNOTEQUAL(std::stack<std::string>& a_stack)
{
    std::string x = a_stack.top();
    a_stack.pop();
    std::string y = a_stack.top();
    a_stack.pop();

    if(x!=y)
    {
        a_stack.push("TRUE");
    }
    else
    {
        a_stack.push("FALSE");
    }
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
Operation::OP_EQUAL(std::stack<std::string>& a_stack)
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
Operation::OP_1ADD(std::stack<std::string>& a_stack)
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
Operation::OP_1SUB(std::stack<std::string>& a_stack)
{
    int x = std::stoi(a_stack.top());
    x--;
    a_stack.push(std::to_string(x));
    return a_stack;
}

/**
 * @brief Operator for changing the sign of the top item to positive.
 * 
 * @param a_stack 
 * @return std::stack<std::string>& 
 * 
 * @author Philip Glazman
 * @date 5/2/18
 */
std::stack<std::string>&
Operation::OP_ABS(std::stack<std::string>& a_stack)
{
    int x = std::stoi(a_stack.top());
    x = std::abs(x);
    a_stack.push(std::to_string(x));
    return a_stack;
}

/**
 * @brief Operator that returns true if second item is less than top item.
 * 
 * @param a_stack 
 * @return std::stack<std::string>& 
 * 
 * @author Philip Glazman
 * @date 5/2/18
 */
std::stack<std::string>&
Operation::OP_LESSTHAN(std::stack<std::string>& a_stack)
{
    int x = std::stoi(a_stack.top());
    a_stack.pop();
    
    int y = std::stoi(a_stack.top());
    a_stack.pop();

    if( y < x)
    {
        a_stack.push("TRUE");
    }
    else
    {
        a_stack.push("FALSE");
    }
    return a_stack;
};

/**
 * @brief Operator that returns true if second item is greater than top item.
 * 
 * @param a_stack 
 * @return std::stack<std::string>& 
 * 
 * @author Philip Glazman
 * @date 5/2/18
 */
std::stack<std::string>&
Operation::OP_GREATERTHAN(std::stack<std::string>& a_stack)
{
    int x = std::stoi(a_stack.top());
    a_stack.pop();
    
    int y = std::stoi(a_stack.top());
    a_stack.pop();

    if( y > x)
    {
        a_stack.push("TRUE");
    }
    else
    {
        a_stack.push("FALSE");
    }
    return a_stack;
};

/**
 * @brief Operator that returns true if second item is less than or equal to top item.
 * 
 * @param a_stack 
 * @return std::stack<std::string>& 
 * 
 * @author Philip Glazman
 * @date 5/2/18
 */
std::stack<std::string>&
Operation::OP_LESSTHANOREQUAL(std::stack<std::string>& a_stack)
{
    int x = std::stoi(a_stack.top());
    a_stack.pop();
    
    int y = std::stoi(a_stack.top());
    a_stack.pop();

    if( y <= x)
    {
        a_stack.push("TRUE");
    }
    else
    {
        a_stack.push("FALSE");
    }
    return a_stack;
};

/**
 * @brief Operator that returns true if second item is greater than or equal to top item.
 * 
 * @param a_stack 
 * @return std::stack<std::string>& 
 * 
 * @author Philip Glazman
 * @date 5/2/18
 */
std::stack<std::string>&
Operation::OP_GREATERTHANOREQUAL(std::stack<std::string>& a_stack)
{
    int x = std::stoi(a_stack.top());
    a_stack.pop();
    
    int y = std::stoi(a_stack.top());
    a_stack.pop();

    if( y >= x)
    {
        a_stack.push("TRUE");
    }
    else
    {
        a_stack.push("FALSE");
    }
    return a_stack;
};

/**
 * @brief Operator that pushes onto the stack the minimum item of the top two items.
 * 
 * @param a_stack 
 * @return std::stack<std::string>& 
 * 
 * @author Philip Glazman
 * @date 5/2/18
 */
std::stack<std::string>&
Operation::OP_MIN(std::stack<std::string>& a_stack)
{
    int x = std::stoi(a_stack.top());
    a_stack.pop();
    
    int y = std::stoi(a_stack.top());
    a_stack.pop();

    if( x < y)
    {
        a_stack.push(std::to_string(x));
    }
    else
    {   
        a_stack.push(std::to_string(y));
    }

    return a_stack;
};

/**
 * @brief Operator that pushes onto the stack the maximum item of the top two items.
 * 
 * @param a_stack 
 * @return std::stack<std::string>& 
 * 
 * @author Philip Glazman
 * @date 5/2/18
 */
std::stack<std::string>&
Operation::OP_MAX(std::stack<std::string>& a_stack)
{
    int x = std::stoi(a_stack.top());
    a_stack.pop();
    
    int y = std::stoi(a_stack.top());
    a_stack.pop();

    if( x > y)
    {
        a_stack.push(std::to_string(x));
    }
    else
    {   
        a_stack.push(std::to_string(y));
    }

    return a_stack;
};

/**
 * @brief 
 * 
 * @param a_stack 
 * @return std::stack<std::string>& 
 * 
 * @author Philip Glazman
 * @date 5/2/18
 */
std::stack<std::string>&
Operation::OP_WITHIN(std::stack<std::string>& a_stack)
{
    int x = std::stoi(a_stack.top());
    a_stack.pop();
    
    int y = std::stoi(a_stack.top());
    a_stack.pop();

    int z = std::stoi(a_stack.top());
    a_stack.pop();

    if( z >= y && z < x)
    {
        a_stack.push("TRUE");
    }
    else
    {   
        a_stack.push("FALSE");
    }

    return a_stack;
};

/**
 * @brief Operator for popping the top item off the stack
 * 
 * @param a_stack 
 * @return std::stack<std::string>& 
 * 
 * @author Philip Glazman
 * @date 5/2/18
 */
std::stack<std::string>&
Operation::OP_DROP(std::stack<std::string>& a_stack)
{
    if(!a_stack.empty())
    {
        a_stack.pop();
    };
    
    return a_stack;
};

/**
 * @brief Duplicates the tope item in the stack.
 * 
 * @param a_stack 
 * @return std::stack<std::string>& 
 * 
 * @author Philip Glazman
 * @date 5/2/18
 */
std::stack<std::string>&
Operation::OP_DUP(std::stack<std::string>& a_stack)
{
    a_stack.push(a_stack.top());
    return a_stack;
};

/**
 * @brief Operator for counting the items on the stack and pushing the result onto the stack
 * 
 * @param a_stack 
 * @return std::stack<std::string>& 
 * 
 * @author Philip Glazman
 * @date 5/2/18
 */
std::stack<std::string>&
Operation::OP_DEPTH(std::stack<std::string>& a_stack)
{
    std::string count_stack = std::to_string(a_stack.size());
    a_stack.push(count_stack);
    return a_stack;
};

/**
 * @brief Operator for pushing RIPEMD160 hash of the top item onto the stack
 * 
 * @param a_stack 
 * @return std::stack<std::string>& 
 * 
 * @author Philip Glazman
 * @date 5/2/18
 */
std::stack<std::string>&
Operation::OP_RIPEMD160(std::stack<std::string>& a_stack)
{
    std::string hashed_string = hash_RIPEMD160(a_stack.top());

    a_stack.pop();
    a_stack.push(hashed_string);
};

/**
 * @brief Operator for pushing SHA1 hash of the top item onto the stack
 * 
 * @param a_stack 
 * @return std::stack<std::string>& 
 * 
 * @author Philip Glazman
 * @date 5/2/18
 */
std::stack<std::string>& 
Operation::OP_SHA1(std::stack<std::string>& a_stack)
{
    std::string hashed_string = hash_SHA1(a_stack.top());

    a_stack.pop();
    a_stack.push(hashed_string);
};

/**
 * @brief Operator for pushing SHA256 hash of the top item onto the stack
 * 
 * @param a_stack 
 * @return std::stack<std::string>& 
 * 
 * @author Philip Glazman
 * @date 5/2/18
 */
std::stack<std::string>& 
Operation::OP_SHA256(std::stack<std::string>& a_stack)
{
    std::string hashed_string = hash_SHA256(a_stack.top());

    a_stack.pop();
    a_stack.push(hashed_string);
};

/**
 * @brief Operator for pushing RIPEMD160(SHA256(n)) hash of the top item onto the stack
 * 
 * @param a_stack 
 * @return std::stack<std::string>& 
 * 
 * @author Philip Glazman
 * @date 5/2/18
 */
std::stack<std::string>& 
Operation::OP_HASH160(std::stack<std::string>& a_stack)
{
    // SHA256 hash string
    std::string sha256_hashed_string = hash_SHA256(a_stack.top());
    
    // Double hash with RIPMD160
    std::string hashed_string = hash_RIPEMD160(sha256_hashed_string);

    a_stack.pop();
    a_stack.push(hashed_string);
};

/**
 * @brief Operator for pushing SHA256(SHA256(n)) hash of the top item onto the stack
 * 
 * @param a_stack 
 * @return std::stack<std::string>& 
 * 
 * @author Philip Glazman
 * @date 5/2/18
 */
std::stack<std::string>&
Operation::OP_HASH256(std::stack<std::string>& a_stack)
{
    // SHA256 hash string
    std::string sha256_hashed_string = hash_SHA256(a_stack.top());
    
    // Double SHA256 hash
    std::string hashed_string = hash_SHA256(sha256_hashed_string);

    a_stack.pop();
    a_stack.push(hashed_string);
};

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

    
    // Iterator for op code hash map.
    std::unordered_map<std::string,func>::iterator iter;

    iter = m_op_code_map.find(a_code);

    if(iter != m_op_code_map.end())
    {
        std::cout << "Operation Code Found" << std::endl;
        a_stack = (*iter->second)(a_stack);
    }
    else
    {
        std::cout << "Operation Code NOT Found" << std::endl;
    }
    
    return a_stack;
};

/**
 * @brief Applies SHA256 hash function on a string.
 * 
 * @return std::string 
 * 
 * @author Philip Glazman
 * @date 5/2/18
 */
std::string
Operation::hash_SHA256(std::string a_string)
{
    // Digest
    unsigned char digest[SHA256_DIGEST_LENGTH];

    char str[a_string.length()];

    strncpy(str,a_string.c_str(),sizeof(a_string));
    
    SHA256((unsigned char*)&str,strlen(str),(unsigned char*)&digest);    

    char mdString[SHA256_DIGEST_LENGTH*2+1];

    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
    };

    return  std::string(mdString);
};

/**
 * @brief Applies RIPEMD160 hash function a string.
 * 
 * @return std::string 
 * 
 * @author Philip Glazman
 * @date 5/2/18
 */
std::string 
Operation::hash_RIPEMD160(std::string a_string)
{
    unsigned char digest[RIPEMD160_DIGEST_LENGTH];

    char str[a_string.length()];

    strncpy(str,a_string.c_str(),sizeof(a_string));
    
    RIPEMD160((unsigned char*)&str,strlen(str),(unsigned char*)&digest);    

    char mdString[RIPEMD160_DIGEST_LENGTH*2+1];

    for(int i = 0; i < RIPEMD160_DIGEST_LENGTH; i++)
    {
         sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
    }

    return std::string(mdString);
};

/**
 * @brief Applies SHA1 hash function on string.
 * 
 * @return std::string 
 * 
 * @author Philip Glazman
 * @date 5/2/18
 */
std::string
Operation::hash_SHA1(std::string a_string)
{
    unsigned char digest[SHA_DIGEST_LENGTH];
    
    char str[a_string.length()];

    strncpy(str,a_string.c_str(),sizeof(a_string));
    
    SHA1((unsigned char*)&str,strlen(str),(unsigned char*)&digest);    

    char mdString[SHA_DIGEST_LENGTH*2+1];

    for(int i = 0; i < SHA_DIGEST_LENGTH; i++)
    {
        sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);
    }

    return std::string(mdString);
};