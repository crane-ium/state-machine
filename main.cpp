#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "state_machine.h"
#include "smtoken.h"

using namespace std;

void print_tokens(const char c[]){
    sm::STokenizer st(c);
    sm::SToken t;
    while(st.more()){
        st>>t; //makes t the next popped token
        cout << setw(8) << t.type_string() << setw(10) << t << endl;
    }
    cout << "Done!\n\n";
}

int main()
{
    print_tokens("it was the night of october 17th. pi was still 3.14...");
    print_tokens("1,123,456,789.10 xx");
    print_tokens("12,345 123,1.0 123,1 234,345.000,00,0,34,123");
}
