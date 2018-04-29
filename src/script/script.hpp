/**
 * @brief Provides basic features, error checking of bitcoin script language.
 *  User inputs string opcode, script checks if valid opcode, appends it to stack. 
 * 
 */

#ifndef _SCRIPT_H
#define _SCRIPT_H

#include "../wallet/stdafx.h"

class Script 
{
    public:
        Script();
        ~Script();
    
    protected:


    private:
        
        // Unlocking Script
        // OR Witness
        template <typename T> 
        std::stack <T> witness;

        // Locking Script
        // OR Witness Script
        template <typename T> 
        std::stack <T> witness_script;

        //instructions
        //stack rules
        //op codes
};

#endif 