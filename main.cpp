#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "state_machine.h"
#include "smtoken.h"
#include "sm_unittest.h"
#include <ctime>
#include <sstream>

using namespace std;
using sm::print_tokens;

int main()
{
    sm_unittest tester;
    tester.run_unittest();
    string s;
    s = "it was the night of october 17th. pi was still 3.14 at ";

    //get time https://stackoverflow.com/questions/16357999/current-date-and-time-as-string
    auto t = time(NULL); //auto uses template argument deduction to find the type
    auto tm = *localtime(&t);
    ostringstream oss;
    oss << put_time(&tm, "%H:%M");
    s += oss.str();

    print_tokens(s.c_str());
}
