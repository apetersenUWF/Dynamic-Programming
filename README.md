# Dynamic-Programming-Project

This program contains two solutions to the Longest Common Subsequence Problem (LCS). One which computes 
and returns the string that is the LCS of two strings using O(m*n) memory, and another which returns only 
the length of the LCS using O(2 x m) memory. Both algorithms use dynamic programming to find the solution in O(n x m)
time for what would otherwise be a O(n!) problem using naive brute-force methods.

The LCS problem has applications in biology, data analysis, text editors, and many other fields.

The purpose of the program is to allow the user to input strings into a file and find their lcs and/or compare the
similarity of the strings. The strings can be of any length. Any two strings can be assigned a character that represents
their level of similarity. Criteria are:

**H = high similarity between the strings**
*High similarity exists if the length of the shorter string is within 10% of the length of the longer string and the longest common subsequence is at least 90% of the length of the shorter string.*
**M = medium similarity between the strings**
*Medium similarity exists if the criteria for High similarity is not met but the length of the shorter string is within 20% of the longer string and the longest common subsequence is 80% of the length of the shorter string.*
**L = low similarity between the strings**
*Low similarity exists if the criteria for Medium similarity is not met but the length of the shorter string is within 40% of the longer string and the longest common subsequence is 50% of the length of the shorter string.*
**D = the two strings are dissimilar**
*Dissimilar strings are any that meet none of the above criteria.*

# How to Use

This program comes with a Makefile, to use it run the command "make" in the command line interface.
This will generate an executable called "run".
Verify that the data files "twoStrings.txt" and "multiStrings.txt" are in the same directory as the executable.
Verify that the "twoStrings.txt" file contains exactly two strings, one on each line, which you would like
to find the lcs for.
Verify that the "multiStrings.txt" filke contains the number of strings on the first line, followed by exactly
that number of strings, one on each line. These strings will each be compared to every other string by the above criteria, the
actual LCS string will not be found only the length.

Issue the command "./run" in the command line to run the executable.
No user interaction is required beyond this point.
The program will output the two strings from "twoStrings.txt" followed by their LCSA length, and the LCS itself.
The program will also output a table showing the result of comparing each string to every other string from the
"multiStrings.txt" file. The output will look similar to this

-------------------------------------------------- 
Original Strings: 
1: "string1" 
2: "string2"  
Longest Common Subsequence:
Length = 794
"LCS"
--------------------------------------------------
   00 01 02 03 04 05 06 07 
00  -  D  D  D  L  D  M  D 
01  -  -  D  D  D  D  D  H 
02  -  -  -  H  D  H  D  D 
03  -  -  -  -  D  H  D  D 
04  -  -  -  -  -  D  M  D 
05  -  -  -  -  -  -  D  D 
06  -  -  -  -  -  -  -  D 
07  -  -  -  -  -  -  -  - 

After this, the program will terminate. Feel free to try different strings to see how the output changes.