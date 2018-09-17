#ifndef SM_TABLE_GENERATOR_H
#define SM_TABLE_GENERATOR_H

/*sm::TableGenerator is a class that will generate a state table
 * based on an input string. It will be able to dynamically
 * and cleanly fill a table with better management than
 * manual input would allow
 *
 * I would like it to be able to eventually accept any type
 *
 * For now it will only accept char*
 *
 * */

#include <vector>
#include <iostream>
#include "../../CS8/snq/my_queue.h"

using namespace std;

namespace sm{
    class TableGenerator{
    public:
        /*Generate a table of type T
         */

        //CTORs
        TableGenerator();
        TableGenerator(char* c);
        //MOD MEMBER FUNCTIONS
        void add(const string &s); //adds strings to our vect
        //FRIEND FUNCTIONS
        friend istream& operator >> (istream& ins, TableGenerator& rhs){
            //finish this later, figure out how to cin>>array???
            //OK, so what we need to do is define a friend func for istream>>vector<T>
            //then allow the intake of that vector one at a time!?
            //OR maybe that's overkill and i should just allow this to be for string
            return ins;
        }
    private:
        vector<vector<int>> _table; //state-table
        Queue<string> input; //array or vector or queue of inputs aka a string
        //PRIVATE MOD FUNCTIONS
        void process_queue(); //Processes the queue; this is the important function
    };
}

#endif // SM_TABLE_GENERATOR_H
