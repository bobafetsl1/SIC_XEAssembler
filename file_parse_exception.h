/*  
    Ian Rigg, Richard Valles, Chris Andaya, Arron Mccarter
    masc1258
    Prog1: file_parse_exception.h
    Exception class for file_parser
    CS530 Spring 2014
    Team Florida
    created originally by Alan Riggins
*/    

#ifndef FILE_PARSE_EXCEPTION_H
#define FILE_PARSE_EXCEPTION_H
#include <string> 

using namespace std;

class file_parse_exception {

public:
    file_parse_exception(string s) {
        message = s;        
        }
        
    file_parse_exception() {
        message = "An error has occurred";
        }
        
    string getMessage() {
        return message;
    }
    
private:
    string message;
};    

#endif

