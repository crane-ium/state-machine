#include "smtoken.h"

string sm::SToken::snames[MAX_ROWS];

sm::SToken::SToken(){
    _s = "~test~";
    state = -1;
    set_state_names();
}

sm::SToken::SToken(string str, int sta){
    set_state_names();
    _s = str;
    state = sta;
}

sm::SToken::~SToken(){
    if(DEBUG)
        cout << "stoken destructor\n";
}

sm::SToken::SToken(const SToken& token){
    this->set_state_names();
    this->_s = token._s;
    this->state = token.state;
}
sm::SToken& sm::SToken::operator =(const SToken& rhs){
    if(DEBUG)
        cout<<"stoken ctor =\n";
    //COPY SWAP IDIOm
    if(this == &rhs)
        return *this;
    SToken temp(rhs);
    swap(temp._s, this->_s);
    swap(temp.state, this->state);
    if(DEBUG)
        cout << *this << " returning stoken ctor\n";
    return *this;
}

void sm::SToken::set_state_names(){
    for(int i = 0; i < MAX_ROWS; i++)
        snames[i] = "UNKNOWN";
    snames[WORD] = "ALPHA";
    snames[INT] = "INTEGER";
    snames[DOUBLE] = "DOUBLE";
    snames[SPACE] = "SPACE";
    snames[COMMA] = "COMMA";
}

void sm::SToken::set_state(int new_state){
    this->state = new_state;
}

void sm::SToken::set_token(const string& str){
    this->_s = str;
}
