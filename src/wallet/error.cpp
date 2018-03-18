/*
*   Implementation of the Error class.
*/

#include "stdafx.h"

// Initializes error reports.

std::queue<std::string> Error::m_ErrorMsgs;


/**/
/*
Errors::InitErrorReporting()
NAME
Errors::InitErrorReporting()
SYNOPSIS
void Errors::InitErrorReporting()
DESCRIPTION
This function empties the error queue in order to remove any junk.
RETURNS
Returns nothing
AUTHOR
Philip Glazman
DATE
1/8/2018
*/
/**/
void
Error::InitErrorReporting()
{
	while (!m_ErrorMsgs.empty()) m_ErrorMsgs.pop();
}

/**/
/*
Errors::RecordError(string &a_emsg)
NAME
Errors::RecordError(string &a_emsg)
SYNOPSIS
void Errors::RecordError(string &a_emsg)
a_emsg            --> Error message to push to the queue.
DESCRIPTION
This function pushes a string error message to the queue.
RETURNS
Returns nothing.
AUTHOR
Philip Glazman
DATE
1/8/2018
*/
/**/
void
Error::RecordError(std::string a_emsg)
{
	m_ErrorMsgs.push(a_emsg);
}

/**/
/*
Errors::DisplayErrors()
NAME
Errors::DisplayErrors()
SYNOPSIS
void Errors::DisplayErrors()
DESCRIPTION
This function outputs any error messages in the queue.
RETURNS
Returns nothing.
AUTHOR
Philip Glazman
DATE
1/8/2018
*/
/**/
void
Error::DisplayErrors()
{	
	// While there are any error messages, print them to the screen.
	while (!m_ErrorMsgs.empty())
	{
		std::cout << std::setw(15) << std::right << m_ErrorMsgs.front() << std::endl;
		m_ErrorMsgs.pop();
	}
}