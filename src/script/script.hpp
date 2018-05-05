/**
 * @brief Script class manipulates a Bitcoin execution stack using Bitcoin script rules.
 * 
 * @file script.hpp
 * @author Philip Glazman
 * @date 5/3/18
 */

#ifndef _SCRIPT_H
#define _SCRIPT_H

#include "../wallet/stdafx.h"
#include "operation.hpp"

class Script 
{
    public:

        // Constructor, initializes consensus rules for the script to comply to.
        Script();

        // Destructor.
        ~Script();

        // Evaluates sthe script on the current execution stack.
        bool is_valid();

        // Builds the execution stack using the provided witness and witness script.
        bool build_script(std::string a_witness, std::string a_witness_script);

        // Clears the current Bitcoin execution stack.
        bool clear_script();
    
    protected:

    private:

        // Creates Operation object.
        Operation * m_operation;

        // Configuration for which fork rules the script will run on.
        uint32_t m_fork_rules;

        // Execution stack.
        std::stack <std::string> m_execution_stack;

        // Witness script.
        std::queue <std::string> m_execution_queue;

};

#endif
