#include <iostream>
#include <string>
#include <set>

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
                 case '\t':
                 {
                       return std::string("\\t");
                 }
                 default:
                 {
                 	if(isdigit(ch))
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
 * Returned string is the result of processing each character in str with escapeChar
 * and concatenating the results together.
 * For example, if str is the string "1st, 2nd and 3rd"
 * the returned string should be "\1st,\s\2nd\sand\s\3rd".
 *
 * @Param str the string to process.
 * @Return concat_string The processed string.
 *
 * @Author: Ben Euden
 */
std::string escapeString(const std::string& str)
{
	std::string concat_string;	
	for(auto it = str.begin(); it != str.end(); ++it)
	{
		concat_string += escapeChar((*it));
	}

	return concat_string;

}

/*
 * Read from the standard input, divide the input into phrases using escapeString
 * and write the phrases to the standard output.
 */
int main()
{

	std::set<std::string> string_set;
	// get the input.
	char c;
	std::string temp;
	std::string lastPhrase;
	while(std::cin.get(c))
	{
		temp += c;
		if(string_set.insert(temp).second)
		{
			std::cout << escapeString(temp) << std::endl;
			temp.clear();
		}
		lastPhrase = temp;	
	}

	if(lastPhrase.size() == 1) {
		std::cout << escapeString(lastPhrase) << std::endl;
	}

	return 0;
}	
