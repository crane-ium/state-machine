#include "smtoken.h"

string sm::SToken::snames[MAX_ROWS];
bool sm::SToken::already_set_state_names = false;

sm::SToken::SToken(){
    _s = "";
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
    if(already_set_state_names) //avoid repeat filling a static var
        return;
    for(int i = 0; i < MAX_ROWS; i++)
        snames[i] = "UNKNOWN";
    //Takes a var[] and loops through it while adding in str into a respective array
    //This keeps track of success state names
#define s_loop(var, str) for(unsigned int n=0; n<sizeof(var)/sizeof(*var); n++) snames[var[n]] = str
    s_loop(WORD,"ALPHA");
    s_loop(INT,"INTEGER");
    s_loop(DOUBLE,"DOUBLE");
    s_loop(SPACE,"SPACE");
    s_loop(COMMA,"COMMA");
    s_loop(TIME, "TIME");
    s_loop(PUNC, "PUNCS");

    already_set_state_names = true;
}

void sm::SToken::set_state(int new_state){
    this->state = new_state;
}

void sm::SToken::set_token(const string& str){
    this->_s = str;
}

string sm::SToken::type_string() const{
    //ternary operator to guarantee the state put into the array is >0
    return snames[(state>=0) ? state : 0];
}
