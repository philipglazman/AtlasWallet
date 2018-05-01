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
        // ~Script();

        bool run_script();
        
        bool build_script(std::string a_witness, std::string a_witness_script);

        // Evaluate script.
        bool eval();
    
    protected:


    private:

        // Configuration for which fork rules the script will run on.
        uint32_t fork_rules;

        // bc::machine:::operation::list script;

        // Execution stack.
        std::stack <std::string> execution_stack;

        // Witness script.
        std::queue <std::string> execution_queue;

        //op codes
};

#endif
