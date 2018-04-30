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

        bool run_script();
        
        // Builds script programatically using operation codes.
        bc::machine::program build_script();
    
    protected:


    private:

        // Configuration for which fork rules the script will run on.
        uint32_t fork_rules;

        // bc::machine:::operation::list script;

        // Unlocking Script
        // OR Witness
        template <typename T> 
        std::stack <T> witness;

        // Locking Script
        // OR Witness Script
        template <typename T> 
        std::stack <T> witness_script;

        // Execution stack.
        template <typename T>
        std::stack <T>> execution_stack;

        //op codes
};

#endif 