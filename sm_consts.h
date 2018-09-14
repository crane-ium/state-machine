#ifndef SM_CONSTS_H
#define SM_CONSTS_H

#include <iostream>

using namespace std;

const int DEBUG = false;

const int MAX_COLUMNS = 256; //max columns in table, representing the ascii value
const int MAX_ROWS = 20; //max rows in table, representing the state

//TOKEN TYPES: Each represents the state to be successful for this type of token
const int WORD = 10;
const int INT = 1;
const int DOUBLE = 3;
const int SPACE = 5;
const int COMMA = 6;

//
const int SSTATE[] ={ //success state const
    WORD, INT, DOUBLE, SPACE, COMMA
};

//strings holding an array of characters to be categorized
const string CHARS = "abcdefghijklmnopqrtstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string NUMS = "0123456789";
const string NEG = "-";
const string DEC = ".";
const string COMMAS = ",";
const string PUNCS = ",.:;'\"()[]{}-!@#$%^&*<>?_-=+`~/|\\";
const string SPACES = " _";


#endif // SM_CONSTS_H
