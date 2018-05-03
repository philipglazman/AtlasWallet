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
    
        // Stack representing Bitcoin execution stack.
        typedef std::stack<std::string>& stack;

        typedef stack (*func)(stack);
        typedef std::unordered_map<std::string, func> op_code_map;

        op_code_map m_op_code_map;

        // Operators for pushing values onto stack.
        static stack OP_1(stack);

        //Operators for stack manipulation
        static stack OP_DROP(stack);
        static stack OP_DUP(stack);
        static stack OP_DEPTH(stack);
        
        // Operators for binary artithmetic
        static stack OP_EQUAL(stack);  

        // Operators for arithmetic
        static stack OP_1ADD(stack);  
        static stack OP_1SUB(stack);
        static stack OP_NEGATE(stack);  
        static stack OP_ABS(stack);  
        static stack OP_ADD(stack);  
        static stack OP_SUB(stack);
        static stack OP_NUMEQUAL(stack);  
        static stack OP_NUMNOTEQUAL(stack);
        static stack OP_LESSTHAN(stack);
        static stack OP_GREATERTHAN(stack);
        static stack OP_LESSTHANOREQUAL(stack);
        static stack OP_GREATERTHANOREQUAL(stack);
        static stack OP_MIN(stack);
        static stack OP_MAX(stack);
        static stack OP_WITHIN(stack);

        // Operators for cryptography
        static stack OP_RIPEMD160(stack);
        static stack OP_SHA1(stack);
        static stack OP_SHA256(stack);
        static stack OP_HASH160(stack);
        static stack OP_HASH256(stack);

        // Utilities for cryptography
        static std::string hash_SHA256(std::string);
        static std::string hash_RIPEMD160(std::string);
        static std::string hash_SHA1(std::string);       
};

#endif