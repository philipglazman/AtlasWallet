/**
 * @brief Implementation of the Script class.
 * 
 * @file script.cpp
 * @author Philip Glazman
 * @date 5/3/18
 */
#include "../wallet/stdafx.h"

/**
 * @brief Construct a new script::script object
 * 
 * @author Philip Glazman
 * @date 4/28/18
 */
Script::Script()
{
    // Configure current consensus rules for the stack to comply with.
    m_fork_rules = bc::machine::rule_fork::all_rules;

    m_operation = new Operation::Operation();
};

/**
 * @brief Destroy the script::script object
 * 
 * @author Philip Glazman
 * @date 4/28/18
 */
Script::~Script()
{
    delete m_operation;
};


/**
 * @brief Evaluates the script on the current execution stack and returns if script is valid.
 * 
 * @author Philip Glazman
 * @date 5/3/18
 */
bool
Script::is_valid()
{
    if(m_execution_stack.size()==1 and (m_execution_stack.top()=="1" || m_execution_stack.top()=="True"))
    {
        return true;
    }
    else
    {
        return false;
    }
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
    std::string script = a_witness +" "+ a_witness_script;
   
    // Use istringstream class to parse witness and witness script.
    std::istringstream execution_item (script);


    // Operater/Operand at specific point in script.
    std::string execution_pointer;

    while(execution_item)
    {
        execution_pointer.clear();
        execution_item >> execution_pointer;

        if( execution_pointer != "" )
        {
            // Push the witness onto the execution stack.
            std::cout << execution_pointer << std::endl;
            m_operation->call_operation(execution_pointer,m_execution_stack);
        }
    };
};

/**
 * @brief Clears the current execution stack.
 * 
 * @return true 
 * @return false
 * 
 * @author Philip Glazman
 * @date 5/3/18 
 */
bool
Script::clear_script()
{
    while(!m_execution_stack.empty())
    {
        m_execution_stack.pop();
    }

    return true;
};