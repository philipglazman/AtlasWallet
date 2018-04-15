/**
 * @brief Provides basic features, error checking of bitcoin script language.
 *  User inputs string opcode, script checks if valid opcode, appends it to stack. 
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
        
        // Locking Script.
        template <typename T> 
        std::stack <T> output_script_stack;

        //instructions
        //stack rules
        //op codes
};

#endif 