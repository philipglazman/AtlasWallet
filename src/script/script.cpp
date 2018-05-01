#include "../wallet/stdafx.h"

/**
 * @brief Construct a new script::script object
 * 
 * @author Philip Glazman
 * @date 4/28/18
 */
Script::Script()
{
    fork_rules = bc::machine::rule_fork::all_rules;

};

/**
 * @brief Destroy the script::script object
 * 
 * @author Philip Glazman
 * @date 4/28/18
 */
// Script::~Script()
// {
    
// };


/**
 * @brief 
 * 
 * @author Philip Glazman
 * @date 4/28/18
 */
bool
Script::run_script()
{
    return true;
};

/**
 * @brief 
 * 
 * @param witness 
 * @param witness_script 
 * @return true 
 * @return false 
 * 
 * @author Philip Glazman
 * @date 4/30/18
 */
bool
Script::build_script(std::string a_witness, std::string a_witness_script)
{
    // Use istringstream class to parse witness and witness script.
    std::istringstream witness (a_witness);
    std::istringstream witness_script (a_witness_script);

    // Operater/Operand at specific point in script.
    std::string execution_pointer;

    while(witness)
    {
        execution_pointer.clear();
        witness >> execution_pointer;

        if( execution_pointer != "" )
        {
            // Push the witness onto the execution stack.
            std::cout << execution_pointer << std::endl;
            execution_stack.push(execution_pointer);
        }
    };

    while(witness_script)
    {
        execution_pointer.clear();
        witness_script >> execution_pointer;
        
        if( execution_pointer != "" )
        {
            // Add execution operations to queue.
            std::cout << execution_pointer << std::endl;
            execution_queue.push(execution_pointer);
        }
    };
};

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 * 
 * @author Philip Glazman
 * @date 4/30/18
 */
bool
Script::eval()
{
    while(!execution_queue.empty())
    {
        
    }

};