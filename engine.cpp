#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

class dvig{
    bool first, second;
public:
    void set_dvig(string s);
    dvig() { first = 0; second = 0; }
};


void dvig::set_dvig(string s){
    if(s == "first") first = !first;
    else if(s == "second") second = !second;
    else if(s == "exit") exit(0);
    else { cout << "ERROR\n"; return; }
    cout << "The  first engine is" << ((first)?" ":"n't ") << "running\n"
         << "The second engine is" << ((second)?" ":"n't ") << "running\n";
}

int main(){
    string s;
    dvig a;
    cout << "Hello, write \"first\" to change work first engine\n"
            "and \"second\" for second or \"exit\" for exit\n";
    while(true){
        cin >> s;
        a.set_dvig(s);
    }
    return 0;
}
