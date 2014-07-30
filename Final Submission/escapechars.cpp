#include <string>
#include <iostream>

/*
 * Reads in a character, and returns a string.
 * In most cases the returned string is simply the one- character string containing ch.
 * However, in the following exceptional cases, the returned string contains two characters:
 * -If ch is a space, a tab, a carriage return or a newline, then the returned string 
 *  comprises a backslash followed by s, t, r or n respectively.
 * -If ch is a backslash or a decimal digit, then the returned string comprises a backslash
 *  followed by the input character (i.e. ch).
 * @Param ch The character.
 * @Return The string representation of ch.
 *
 * @Author: Ben Euden
 */
std::string escapeChar(char ch)
{
	
	// Alternate character check
	switch(ch){
		case ' ':
		{
			return std::string("\\s");
		}
		case '\r':
		{
			return std::string("\\r");
		}
		case '\n':
		{
			return std::string("\\n");
		}
		case '\\':
		{
			return (std::string("\\") += ch);
		}
		case '\t':
		{
			return std::string("\\t");
		}
		default:
		{	if(isdigit(ch))
			{
				return (std::string("\\") += ch);
			}
			else{
				return std::string(1,ch);
			}
		}
	}

}

/*
 * Reads successive characters from the standard input 
 * processes each character using the function escapeChar
 * and writes the results to the standard output.
 */
int main()
{
	char c;
	while(std::cin.get(c)){
		std::cout << (escapeChar(c));
	}
	return 0;
}
