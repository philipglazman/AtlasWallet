#ifndef _OPERATION_H
#define _OPERATION_H

#include "../wallet/stdafx.h"

class Operation 
{
    public:
        
        Operation(); 

        // calls a specific operation
        std::stack<std::string>& call_operation(std::string a_code,std::stack<std::string>&);
    
    protected:

    private:
    
        typedef void (*ScriptFunction)(void);
        typedef std::unordered_map<std::string, ScriptFunction> op_code_map;

        typedef std::stack<std::string>& stack;

        op_code_map m_op_code_map;

        // Operators for pushing values onto stack.
        stack& OP_1(stack);

        //Operators for stack manipulation
        stack& OP_DROP(stack);
        stack& OP_DUP(stack);
        stack& OP_DEPTH(stack);
        
        // Operators for binary artithmetic
        stack& OP_EQUAL(stack);  

        // Operators for arithmetic
        stack& OP_1ADD(stack);  
        stack& OP_1SUB(stack);
        stack& OP_NEGATE(stack);  
        stack& OP_ABS(stack);  
        stack& OP_ADD(stack);  
        stack& OP_SUB(stack);
        stack& OP_NUMEQUAL(stack);  
        stack& OP_NUMNOTEQUAL(stack);
        stack& OP_LESSTHAN(stack);
        stack& OP_GREATERTHAN(stack);
        stack& OP_LESSTHANOREQUAL(stack);
        stack& OP_GREATERTHANOREQUAL(stack);
        stack& OP_MIN(stack);
        stack& OP_MAX(stack);
        stack& OP_WITHIN(stack);

        // Operators for cryptography
        stack& OP_RIPEMD160(stack);
        stack& OP_SHA1(stack);
        stack& OP_SHA256(stack);
        stack& OP_HASH160(stack);
        stack& OP_HASH256(stack);

        // Utilities for cryptography
        std::string hash_SHA256(std::string);
        std::string hash_RIPEMD160(std::string);
        std::string hash_SHA1(std::string);       
};

#endif