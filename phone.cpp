#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

int cnum = 0;

class number{
    string name;
    string addess;
    string nom;
    int count;
    void set_add();
    void set_name();
    void set_number();
public:
    void change_num(number *a);
    void set_inf();
    void call(number *a);
    void show_count(number *a);
};

void number::set_add(){
    cout << "Write address of subscriber:\n";
    cin >> this->addess;
}
void number::set_name(){
    cout << "Write name of subscriber:\n";
    cin >> this->name;
}
void number::set_number(){
    cout << "Write number of subscriber:\n";
    cin >> this->nom;
}
void number::change_num(number *a){
    cout << "Number that's are change:\n";
    string s;
    cin >> s;
    for(int i = 0; i < cnum; i++){
        if(s == a[i].nom) {
            cout << "Write new number of subscriber:\n";
            cin >> a[i].nom;
            return;
        }
    }
    cout << "The entered number does not exist.\n";
}
void number::set_inf(){
    this->set_name();
    this->set_add();
    this->set_number();
    this->count = 0;
    cnum++;
}
void number::call(number *a){
    cout << "What number do you pick to call?\n";
    string s;
    cin >> s;
    for(int i = 0; i < cnum; i++){
        if(a[i].nom == s) {
            cout << "Call made\n";
            a[i].count++;
            return;
        }
    }
    cout << "The entered number doesn't exist.\n";
}
void number::show_count(number *a){
    cout << "What number do you pick to watch count of calls?\n";
    string s;
    cin >> s;
    for(int i = 0; i < cnum; i++){
        if(a[i].nom == s){
            cout << "This subscriber made " << a[i].count << " calls.\n";
            return;
        }
    }
    cout << "The entered number doesn't exist.\n";
}


int main(){
    number *a = new number [100];
    string s;
    while(true){
        cin >> s;
        if(s == "new subscriber" || s == "ns") a[cnum].set_inf();
        else if(s == "change num" || s == "cn") a->change_num(a);
        else if(s == "call") a->call(a);
        else if(s == "show count" || s == "sc") a->show_count(a);
        else if(s == "exit") exit(0);
    }
    return 0;
}
