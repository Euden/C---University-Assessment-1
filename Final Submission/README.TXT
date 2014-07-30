The following files were written in correspondence with the set C++
assessment based on Lempel-Zil(LZ) data compression. While Lempem-Ziv uses
binary numbers in encoding this assessment required using decimal numbers to
encode ASCII and contains only printing characters plus space, tab,
carriage return and newline.

Usage:

escapeChars.cpp - This program will print out any escape characters within 
the input given alongside any characters.. 

Example:

$ g++ -g -std=c++11 -Wall escapechars.cpp
$ echo "The 39 Steps" | ./a.out
The\s\3\9\sSteps\n$

lzphrases.cpp - This a program that will divide up a stream of input into ‘phrases’.In general, each phrase is the shortest sequence of characters that has not previously been identified as a phrase within the input stream.

Example:

$ g++ -g -std=c++11 -Wall -o lzphrases lzphrases.cpp
$ echo "aaaaa aaaaa" | ./lzphrases
a
aa
aa\s
aaa
aa\n
$

lzcode.cpp - This program gives each phrase a serial number starting at 1, with Phrase 0 being the empty string. Then each phrase (from Phrase 1 onwards) will consist of a prefix— i.e. a lower-numbered phrase, possibly Phrase 0—plus one extra character at the end.


DISCLAIMER: 

 This was written as a solution to an assessment for THE UNIVERSITY OF KENT.
 All rights to the program are property of the university and any usage is 
 for demonstration purposes only.

Author:

Ben Euden
Email: be41@kent.ac.uk / beneuden@hotmail.com
