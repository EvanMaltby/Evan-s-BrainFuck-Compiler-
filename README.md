Evan-s-BrainFuck-Compiler-
==========================
(Linux/Mac Only!)
A C++ program that turns brainfuck code into C++ and then compiles it and deletes the C++ source
 
To compile the actual C++ code from source:
g++ Compiler.cpp -o CppCompiler
 
To compile a brainfuck program:

$ ./compile

type in the file with the code and it compiles it.

To look at C++ source (to look at the HORRIBLY optimized code):
./CppCompiler
this will make it so it dosent compile nor delete the output file and allows you to inspect.
