#ifndef SMTOKEN_H
#define SMTOKEN_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "sm_consts.h"
#include <algorithm>

using namespace std;

namespace sm{
    struct SToken{
    public:
        //CTOR
        SToken();
        SToken(string str, int sta); //creating a token with an initialized string and state
        friend ostream& operator << (ostream& outs, const SToken& s){ //overload to display a SToken
            outs << "|" << s._s << "|";
            return outs;
        }
        //Big 3
        ~SToken();
        SToken(const SToken& token);
        SToken& operator =(const SToken& rhs);
        //MOD MEMBER FUNCTIONS
        void set_state(int new_state); //sets state of the token
        void set_token(const string &str); //sets a new string for the token
        string type_string() const; //returns a string representing the type of token it's holding
    private:
        string _s; //This string represents the token
        int state; //the state that is represented
        static string snames[MAX_ROWS];
        static bool already_set_state_names;
        //priv functions
        void set_state_names();
    };
}
#endif // SMTOKEN_H
