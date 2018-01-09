/*
* Class to manage error reporting.
*/
#ifndef _ERROR_H      
#define _ERROR_H

#include "stdafx.h"

class Error 
{
    
public:

	// Initializes error reports.
	static void InitErrorReporting();

	// Records an error message.
	static void RecordError(std::string &a_emsg);

	// Displays the collected error message.
	static void DisplayErrors();

private: 

    // Error stack.
    static std::queue<std::string> m_ErrorMsgs;
};

#endif