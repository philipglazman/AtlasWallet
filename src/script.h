/**
 * @brief Provides basic features, error checking of bitcoin script language.
 * 
 */

#ifndef _SCRIPT_H
#define _SCRIPT_H

#include "stdafx.h"

class Script 
{
    public:
        Script();
        ~Script();
    
    protected:


    private:
        //include stack
        template <typename T> 
        std::stack <T> stack;

        //instructions
        //stack rules
        //op codes

        std::vector <std::string> opCodes = {"op_0","op_false","op_pushdata1","op_pushdata2","op_pushdata4","op_1negate"}; 


};

#endif 