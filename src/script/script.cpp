#include "script.hpp"

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
Script::~Script()
{
    
};


/**
 * @brief 
 * 
 * @author Philip Glazman
 * @date 4/28/18
 */
bool
Script::run_script()
{

};

/**
 * @brief 
 * 
 * @return bc::machine::program 
 */
bc::machine::program
Script::build_script()
{
    
    // Build script from operation codes.
    bc::machine::operation::list operations = {

    };

    // Connct operation codes into Bitcoin script.
    bc::chain::script script (operations);

    //return bc::machine::program script()
};