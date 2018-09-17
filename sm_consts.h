#ifndef SM_CONSTS_H
#define SM_CONSTS_H

#include <iostream>

using namespace std;

const int DEBUG = false;

const int MAX_COLUMNS = 256; //max columns in table, representing the ascii value
const int MAX_ROWS = 40; //max rows in table, representing the state

//TOKEN TYPES: Each represents the state to be successful for this type of token
const int WORD[] = {20,21};
const int INT[] = {1,2,3,4,8,36,37};
const int DOUBLE[] = {12,14,15,16};
const int SPACE[] = {27};
const int COMMA[] = {29};
const int PUNC[] = {25};
const int TIME[] = {32,33,35};
const int END_OF_SSTATE[] = {-1};

//
static const int* SSTATE[] ={ //success state const
    WORD, INT, DOUBLE, SPACE, COMMA, END_OF_SSTATE
};

//strings holding an array of characters to be categorized
const string CHARS = "abcdefghijklmnopqrtstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string NUMS = "0123456789";
const string NEG = "-";
const string DEC = ".";
const string COMMAS = ",";
const string PUNCS = ",.;'\"!";
const string SYMBOLS = ",.:;'\"()[]{}-!@#$%^&*<>?_-=+`~/|\\";
const string SPACES = " _";
const string TIMENUMS = "012345";


#endif // SM_CONSTS_H
