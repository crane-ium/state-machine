
#include <iostream>
#include <iomanip>
#include <cassert>
#include "state_machine.h"
#include "sm_consts.h"
#include "smtoken.h"
#include "../../CS8/snq/my_queue.h"

int sm::STokenizer::_table[MAX_ROWS][MAX_COLUMNS];

sm::STokenizer::STokenizer(){
    input = "";
    make_table();
    st_reset();
}

sm::STokenizer::STokenizer(const string& s): STokenizer(){
    input = s;
    make_queue();
}

void sm::STokenizer::make_table(){
    mark_table(0, MAX_ROWS-1, 1, MAX_COLUMNS-1, -1); //set all to -1 besides first column
    set_success_states();
    //RULES FOR NUMS
    mark_table(0, 0, NEG, 4);
    mark_table(0, 1, DEC, 2);
    mark_table(4, 4, DEC, 2);
    mark_table(0, 1, NUMS, 1);
    mark_table(2, 3, NUMS, 3);
    mark_table(4, 4, NUMS, 1);
    //RULES FOR CHARS
    mark_table(0, 0, CHARS, 10);
    mark_table(10, 10, CHARS, 10);
    //RULES FOR SPACES
    mark_table(0, 0, SPACES, 5);
    mark_table(5, 5, SPACES, 5);
    //RULES FOR SPECIFIC PUNCTUATION
    mark_table(0, 0, COMMAS, 6);
    mark_table(6,6, ' ', 6);
}

void sm::STokenizer::mark_table(int row, int start, int end, int state){
    mark_table(row, row, start, end, state);
}

void sm::STokenizer::mark_table(int start_row, int end_row, int start, int end, int state){
    for(int r = start_row; r <= end_row; r++){
        for(int c = start; c <= end; c++){
            _table[r][c] = state;
        }
    }
}

void sm::STokenizer::mark_table(int start_row, int end_row, const string& s, int state){
    for(int i = 0; s[i] != NULL; i++){
        mark_table(start_row, end_row, int(s[i]), int(s[i]), state);
    }
}

void sm::STokenizer::get_table(int t[][MAX_COLUMNS]){
    for(int r = 0; r < MAX_ROWS; r++){
        for(int c = 0; c < MAX_COLUMNS; c++)
            t[r][c] = _table[r][c];
    }
}

void sm::STokenizer::print_table() const{
    for(int r = 0; r < MAX_ROWS; r++){
        for(int c = 0; c < MAX_COLUMNS; c++){
            if(_table[0][c] != -1)
                std::cout << std::setw(3) << this->_table[r][c];
        }
        std::cout << endl;
    }
}

void sm::STokenizer::get_token(){
    start_pos = success_pos; //keeps track of starting position which is previous success
    current_state = start_state; //will be 0
    success_state = 0;
    if(DEBUG){
        cout << endl <<"string: " <<input << endl;
        for(char* c = &input[start_pos]; (*c) != NULL; c++)
            cout << setw(2) << *c;
        cout << endl;}
    for(int i = start_pos; i < input.length(); i++){
        current_state = get_state(current_state, int(input[i]));
        if(current_state == -1){
            if(DEBUG)
                {cout<< "~totoken~";
                cout<<" s_state: "<<success_state;
                cout<<" s_pos: "<<success_pos;
                cout<<" start_pos: "<<start_pos;
                cout<<" c_state: "<<current_state;
                cout<<endl;
            }
            break; //prevent from checking anymore
        }else if(get_state(current_state, 0) == 1){
            success_pos = i;
            success_state = current_state;
        }
    }
    success_pos++;
}

void sm::STokenizer::get_token(const string& s){
    input = s;
    st_reset();
    get_token();
}

void sm::STokenizer::set_string(const string& s){
    input = s;
    st_reset();
    make_queue();
}

int sm::STokenizer::get_state(int row, int column) const{
    assert(row >= 0);
    assert(row < MAX_ROWS);
    assert(column >=0);
    assert(column < MAX_COLUMNS);
    return _table[row][column];
}

void sm::STokenizer::set_success_states(){
    //my explanation: ptrs don't have size, so sizeof(SSTATE) returns allocated memory for it
    //and sizeof(*SSTATE) returns allocated bytes for *SSTATE, which is independent of type
    int length = sizeof(SSTATE)/sizeof(*SSTATE);
    for(int i = 0; i < length; i++){
        _table[SSTATE[i]][0] = 1;
    }
}

sm::SToken& sm::STokenizer::next_token(){
    string temp_s;
    this->get_token();
    temp_s = input.substr(start_pos, \
                          (success_pos<input.length())?(success_pos-start_pos) : 1);
    SToken* token_ptr = new SToken(temp_s, success_state);
    if(DEBUG){
        cout << "tkn ptr: ";
        cout<<*token_ptr<<endl;
    }
    return *token_ptr;
}

void sm::STokenizer::st_reset(){
    start_pos = 0;
    success_pos = 0;
    start_state = 0;
    success_state = 0;
    current_state = start_state;
}

bool sm::STokenizer::more() const{
    if(token_q.empty())
        return false;
    else
        return true;
}

Queue<sm::SToken>& sm::STokenizer::make_queue(){
    token_q.~Queue(); //empty the previous queue
    while(success_pos < input.length()) //iterate while the walker number is < length-1
        token_q.push(this->next_token());
    return token_q;
}
