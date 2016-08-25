Francisco Munoz

SID: 861174271

NETID: fmuno003

email: fmuno003@ucr.edu

CS014 - Lab 01

-------------------------------------------------------------------------------  
Specfics of each function:

display function displays the vector that holds the repeating series in the Fibonacci sequence

fibCount function lets the user know how many of each number there are in the repeating series

fibMod function creates the Fibonacci sequence and then mods the sequence by the value M that the user inputted. It then returns the vector that holds the repeating sequence.

checkPairs functions just sets the 2D vector at that value to 1 so that it allows the program that that pair has appeared and removes it.

vectorFill function fills up the 2D vector with the value 0.

displayVector function displays the pairs that are remaining in a compact box.

secondPair function checks for the next value for the Fibonacci sequence that has not been used. For exmaple, if the pair 2,0 has not been used the 0 will be used as the second number.

firstPair function checks for the next value for the Fibonnacci sequence that has not been used. For example, if the pair 2,0 has not been used the 2 will be used as the second number.

remainingPairs function runs through the 2D vector to check if there are still remaining pairs that can be used in the Fibonacci sequence. For example, if the vector V.at(2).at(0) is set to 0, the pair 2,0 will be used next.

--------------------------------------------------------------------------------

The program starts off by asking the user to input a value for M, which will be the
modulus value. Right after, the user is asked to use their own inputs or the hardcoded inputs
in the program. If he/she says yes to using their own inputs, he/she must input two numbers, 
the first to be the first value in the Fibonacci series and the second value to be the second
number in the Fibonacci series. The user is prompted to run the program 1 time or go through
a complete run through of the whole program. The program then continues to calculate all the pairs in 
the series, removing the pairs appearing in the repeating series of the Fibonnaci sequence
and in the end showing that all the pairs have been removed. The user is then prompted 
with a question to continue with new values or if he/she wishes to end the program.
