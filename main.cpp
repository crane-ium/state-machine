#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "state_machine.h"
#include "smtoken.h"

using namespace std;

void print_tokens(const string& s){
    sm::STokenizer st(s);
    sm::SToken t;
    while(st.more()){
        st>>t; //makes t the next popped token
        cout << t << endl;
    }
    cout << "Done!\n\n";
}

int main()
{
    print_tokens("it was the night of october 17th. pi was still 3.14.");
    print_tokens("1, 2,345.5 ");
    //    print_tokens("");
//    print_tokens("1 2 3.4 -5 t5s h#Ad !!55");
//    print_tokens("Hello, World!");
//    string s = "1,-2 .3!";
//    print_tokens(s);
}
