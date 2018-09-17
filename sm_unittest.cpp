#include "sm_unittest.h"
#include <time.h>

using namespace std;

sm_unittest::sm_unittest()
{

}

void sm_unittest::print(){
    cout << "String: " << str << endl;
    machine.set_string(str);
    while(machine.more()){
        machine >> stoken;
        cout << setw(8) << stoken.type_string() << setw(10) << stoken << endl;
    }
    cout << "Done\n\n";
}

void sm_unittest::set_str(const string &s){
    str = s;
    print();
}

void sm_unittest::run_unittest(){
    set_str(""); //test empty string
    set_str("&"); //single unknown
    set_str("<>|~"); //multiple unkno=wns
    set_str("1"); //single digit
    set_str("-3.1415926");
    set_str("12,345,6789.0.5");
    set_str("123:50:59, 80:61 12:16am 00:00pm 1:32 1:70pm 13:00 12:12");
    set_str("End of test!");
}
