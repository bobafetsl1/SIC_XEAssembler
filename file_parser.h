/*  
    Ian Rigg, Richard Valles, Chris Andaya, Arron Mccarter
    masc1258
    prog1 : file_parser.h
    CS530, Spring 2014
    Team Florida
*/

#ifndef FILE_PARSER_H
#define FILE_PARSER_H

#include <string>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class file_parser {
    public:
        // ctor, filename is the parameter.  A driver program will read
        // the filename from the command line, and pass the filename to
        // the file_parser constructor.  Filenames must not be hard-coded.
        file_parser(string); 
        
        // dtor
        ~file_parser();
        
        // reads the source file, storing the information is some
        // auxiliary data structure you define in the private section. 
        // Throws a file_parse_exception if an error occurs.
        // if the source code file fails to conform to the above
        // specification, this is an error condition.     
        void read_file();
        
        // returns the token found at (row, column).  Rows and columns
        // are zero based.  Returns the empty string "" if there is no 
        // token at that location. column refers to the four fields
        // identified above.
        string get_token(unsigned int, unsigned int);
        
        // prints the source code file to stdout.  Should not repeat 
        // the exact formatting of the original, but uses tabs to align
        // similar tokens in a column. The fields should match the 
        // order of token fields given above (label/opcode/operands/comments)
	    void print_file();
        
        // returns the number of lines in the source code file
        int size();
        
    private:
        // your variables and private methods go here
        string in_file_name;
    	std::ifstream infile;
    	ofstream outfile;
    	struct parsed_line{
    		string label;
    		string opcode;
    		string operand;
    		string comment;
    		parsed_line():  label(" "),
                            opcode(" "),
                            operand(" "),
                            comment(" "){}
    	};
    	string line;
    	int v_counter;
        stringstream ss_error;
    	vector<parsed_line> contents;

    	void throw_error(string);
    	int is_comment(char);
     	int is_opcode(char,int);
     	int is_operand(char,int,int);
     	int is_label(char, int);
     	int has_too_many_tokens(char);
};

#endif  
