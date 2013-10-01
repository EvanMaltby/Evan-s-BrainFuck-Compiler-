#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <cerrno>
#include <stdio.h>
#include <unistd.h>
#include <sstream>
using namespace std;


std::string get_file_contents(const char *filename)
{
  std::ifstream in(filename, std::ios::in | std::ios::binary);
  if (in)
  {
    std::string contents;
    in.seekg(0, std::ios::end);
    contents.resize(in.tellg());
    in.seekg(0, std::ios::beg);
    in.read(&contents[0], contents.size());
    in.close();
    return(contents);
  }
  throw(errno);
}

string ConvertToC(string input)
{
	string output = "#include <stdio.h> \n int main(){ \n int * p;\n p = new int[30000]; \n int currentbyte = 0; \n";
	int currentchar = 0;
	while (currentchar != input.length())
	{
		int counter;
		bool stillincrmenting = false;
		switch (input[currentchar])
		{
			case '>':
            output += " currentbyte++; \n";
		    break;
		    case '<':
		    output += " currentbyte--; \n";
		    break;
		    case '+':
		    output += " p[currentbyte]++; \n";
		    break;
		    case '-':
		    output += " p[currentbyte]--; \n";
		    break;
		    case '[':
		    output += "while(p[currentbyte] != 0){ \n";
		    break;
		    case ']':
            output += "} \n";
            break;
            case '.':
            output += "printf(\"%c\",p[currentbyte]); \n";
            break;
            case ',':
            output += "p[currentbyte] = getchar(); \n";
            break;
		}
		currentchar += 1;
	}
	output += "}";
	return output;
}

int main()
{
	//open file for reading & writing
	fstream inputfile;
	string inputfilename;
	//display welcome
	cout<<"Welcome to Evan's BrainFuck Interperter \nWhat file would you like to compile?"<<endl;
	cin>>inputfilename;
	string input;
	//load while file into string 
	input = get_file_contents(inputfilename.c_str());
	//convert that to C++
	string output = ConvertToC(input);
	//close file
	inputfile.close();
	//messages and checks if open if so then saves output into inputfile stream
	cout<<"Creating Output...."<<endl;
	inputfile.open("output.cpp", std::fstream::in | std::fstream::out | std::ios::trunc);
    if (inputfile.is_open())
    {
    	inputfile << output;
    }
    else
    {
    	cout<<"Error sending output \n";
    }
    //let the script compile and delete WHAT A HACK!
	return 0;
}
