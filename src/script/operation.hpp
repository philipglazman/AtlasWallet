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

        op_code_map m_op_code_map;

        std::stack<std::string>& OP_1(std::stack<std::string>& a_stack);
        
};

#endif