#include <iostream>
#include <string>
#include <map>


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
 * Read from the standard input, divide the input into phrases 
 * and write each phrase to the standard output in the form of the serial number of its prefix
 * followed by its extra character (escaped using escapeChar)
 * followed by a newline.
 *
 * Example output for command -> echo "aaaaa aaaaa" | ./a.out : 
 *
 * 0a
 * 1a
 * 2\s 
 * 2a 
 * 2\n
 * 
 * @Author: Ben Euden.
 */
int main()
{
	std::map<std::string, unsigned int> char_map;
	char c;
	std::string temp, substring;
	// put in the empty string
	char_map.insert(std::pair<std::string, unsigned int>(std::string(""), 0));
	while(std::cin.get(c))
	{
		temp += c;
		if(char_map.insert(std::pair<std::string, unsigned int>(temp, char_map.size())).second)
		{
			if(temp.size() > 1)
			{
				substring = temp.substr(0, temp.size()-1);
				std::cout << char_map.find(substring)->second << escapeChar(c) << std::endl;
			}
			else{
				std::cout << char_map.find("")->second << escapeChar(c) << std::endl;
			}
			temp.clear();
		}
		substring = temp.substr(0, temp.size()-1);
		
	}
	if(temp.size() == 1){
		std::cout << char_map.find(substring)->second << escapeChar(c) << std::endl;
	}
	return 0;
}
