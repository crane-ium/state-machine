#ifndef SMTG_TEST_H
#define SMTG_TEST_H

#include "sm_table_generator.h"

using namespace std;

using sm::TableGenerator;

class smtg_test
{
public:
    smtg_test();
    void run();

    TableGenerator tg;
};

#endif // SMTG_TEST_H
