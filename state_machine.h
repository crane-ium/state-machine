#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <iostream>
#include "sm_consts.h"
#include "smtoken.h"

#include "../../CS8/snq/my_queue.h"

using namespace std;

namespace sm{
    class STokenizer{
    public:
        //CTORs
        STokenizer();
        STokenizer(const string& s);
        //BIG 3 not necessary here

        //MOD MEMBER FUNCS
        void get_table(int t[][MAX_COLUMNS]); //if you wanted to set a completely new table
        void set_string(const string& s); //sets our input to a new string
        void get_token(); //returns if there is a token in string[current_pos:]
        void get_token(const string& s); //returns token based on passed string
        SToken& next_token(); //returns a SToken instance
        //CONST MEMBER FUNCS
        void print_table() const; //prints the adjacency table: Not viable in a DOS window because it's too big
        bool more() const; //checks if there's more in the queue to pop
        //FRIEND FUNCTIONS
        friend STokenizer& operator >> (STokenizer& lhs, sm::SToken& rhs){ //moves a new token over
            rhs = lhs.token_q.pop();
            return lhs;
        }
    private:
        //PRIV VARS
        int start_state, current_state, success_state; //initial state, current recorded state
        unsigned int start_pos, success_pos; //current pos in token, last success in token
        string input; //The string containing tokens
        static int _table[MAX_ROWS][MAX_COLUMNS]; //static across all instances
        Queue<SToken> token_q; //keeps track of my tokens

        //PRIVATE FUNCTIONS
        void make_table(); //sets all of table to -1 (except first column)
        void set_success_states(); //uses mark_table() functoins to fill in a state machine table
        void st_reset(); //resets variables to accept a new string
        //mark_table: fills in set rows/columns with a current state based on requirements
        void mark_table(const int row, int start, int end, int state);
        void mark_table(int start_row, int end_row, int start, int end, int state);
        void mark_table(int start_row, int end_row, const string& s, int state);
        Queue<SToken>& make_queue(); //deletes old queue and makes a new queue
        //get_state: returns a state in (row, column) of the table
        int get_state(int row, int column) const;
    };

}

#endif // STATE_MACHINE_H
