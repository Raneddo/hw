#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

/*#ifndef HUMAN_H
#define HUMAN_H
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>*/

using namespace std;

struct nsa{             // nsa -> n = name, s = surname, a = age
    string name;
    string surname;
    int age;
    bool sex;
};

class human{
    int growth,age,mass, children /*count of children*/;
    bool sex,relat;
    nsa ch[100];
    string name, surname, ms,fms;
    string mansur();
    nsa partner;
    void set_growth(int growth) { this->growth = growth; }
    void set_age(int age) { this->age = age; }
    void set_mass(int mass) { this->mass = mass; }
    void set_children(int cch);
    void set_name(string name) { this->name = name; if(name == "exit") exit(0); }
    void set_surname(string surname) {this->surname = surname; }
    void set_rp();
    void set_sex(string sex);
    friend void help();
    bool get_relatioship() { return relat; }
    void add_child();
    void kill();
    void show_relatioship();
    void show_children();
    void set_relatioships();
    void myinf();
    void new_year();
public:
    void set_parametrs(string name, string surname, int growth, int age, int mass, int cch, string sex);
    void set_parametrs();
    void goup(int &count_errors, string &s);
    void help();
};

//#endif // HUMAN_H

using namespace std;

void human::set_parametrs(string name, string surname, int growth, int age, int mass, int cch, string sex){
    //this->children = 0;
    set_name(name);
    set_surname(surname);
    set_growth(growth);
    set_age(age);
    set_mass(mass);
    set_children(cch);
    set_sex(sex);
}


void human::set_parametrs(){
    int a;
    this->children = 0;
    string s,s1;
    cout << "If you want play, please enter\n"
            "+ name\n"
            "+ male surname\n"
            "+ female surname\n"
            "+ growth\n"
            "+ age\n"
            "+ mass\n"
            //"+ count of children\n"
            "+ sex (man/woman or male/female)\n"
            "\nelse write \"exit\"\n\n";
    cout << "name: ";
    cin >> s;
    set_name(s);
    cout <<"male surname: ";
    cin >> ms;
    //cout << ms << endl;                                             //++++++++++++++++++++
    cout <<"female surname: ";
    cin >> fms;
    //cout << fms << endl;                                           //++++++++++++++++++
    cout << "Enter sex of your character\n";
    cin >> s;
    set_sex(s);
    if(sex) { surname = ms; partner.surname = fms; }
    else { surname = fms; partner.surname = ms; }
    cout <<"growth: ";
    cin >> a;
    set_growth(a);
    cout <<"age: ";
    cin >> a;
    set_age(a);
    cout <<"mass: ";
    cin >> a;
    set_mass(a);
    //cout <<"count of children: ";
    //cin >> a;
    //set_children(a);
}


void human::kill(){
    cout << "Do you really want kill this good person? You are very cruel\n"
            "If you really want kill him/her, you must to enter password\n";
    string s = "I'm very cruel person";
    do{
        if(s != "I'm very cruel person")
            cout << "Incorrect password. Enter password again!\n";
        getline (cin,s);
        if(s == "no kill" || s == "cancel" || s == "exit") { cout << "You made the right choice\n"; return; }
    } while(s != "I'm very cruel person");
    cout << "No, I can't do it. Think again (Kill or No)\n";
    cin >> s;
    if(s == "Kill" || s == "Yes" || s == "kill" || s == "yes" || s == "y" || s == "Y") {
        cout << "You bad human,\n"
                "I don't want to play with you, goodbye\n";
        exit(255);
    }
    else cout << "You made the right choice\n";
}


void human::set_children(int cch) {
    this->children = cch;
    cout << "Enter name and age of all children\n";
    for(int i = 0; i < this->children; i++){
        cout << i+1 << ") ";
        cin >> ch[i].name  >> ch[i].age;
    }
}

void human::show_children(){
    if(children > 0)
    for(int i = 0; i < this->children; i++){
        cout << ch[i].name << " " << ch[i].surname << " is " << ch[i].age << " years old\n";
    }
    else cout << "Your character hasn't children\n";
}

string human::mansur(){
    if(sex == true || relat == false) return surname;
    else return partner.surname;
}

void human::add_child() {
    if(relat){
    this->children++;
    ch[children-1].sex = (rand()%2);
    //cout << ch[children-1].sex << endl;                          //+++++++++++++++++++++++++++++++++++++=
    cout << "Congratulation :-)\n"
            "How do you name baby-" << ((ch[children-1].sex)?"boy":"girl") << "\n";
    cin >> ch[children-1].name;
    if(ch[children-1].sex) ch[children-1].surname = ms;
    else ch[children-1].surname = fms;
    ch[children-1].age = 0;
    cin.get();
    }
    else cout << "Error. Character isn't married\n";
}

void human::show_relatioship(){
    if(relat)
        cout << "married to " << partner.name << " " << partner.surname << endl;
    else
        cout << "not married\n";
}

void human::set_relatioships(){
    relat = !relat;
    if(relat){
        cout << "Who is partner\nname: ";
        cin >> partner.name;
        cout << "age: ";
        cin >> partner.age;
        if(sex) partner.surname = this->fms;
        else {
            cout << "male husband's surname: ";
            cin >> ms;
            cout << "female husband's surname: ";
            cin >> fms;
            partner.surname = ms;
            this->surname = fms;
            for(int i = 0; i < children; i++){
                if(ch[i].sex) ch[i].surname = ms;
                else ch[i].surname = fms;
            }

        }
        partner.sex = !sex;
        cin.get();
    }
    else cout << "You are no longer married\n";
    cout << endl;
}

void human::set_sex(string sex){
    this -> sex = (sex == "man" || sex == "male" ) ? true : false;
    // without sexism true -- man, false -- woman
}



void human::myinf(){
    cout << "name: --- "   << name
         << "\nsurname:  " << surname
         << "\nsex: ---- " << ((sex)?"man":"woman")
         << "\ngrowth: - " << growth
         << "\nage: ---- " << age
         << "\nchildren: " << children
         << endl;
}

void human::goup(int &count_errors, string &s){
    if(!getline(cin,s)) s = "";
    if(s == "help" || s == "h"){
        help();
    }
    else if (s == "child" || s == "c") add_child();
    else if (s == "children" || s == "cn") { show_children(); cout << endl; }
    else if (s == "relatioship" || s == "r") { show_relatioship(); cout << endl; }
    else if (s == "change relatioship" || s == "cr") set_relatioships();
    else if (s == "kill" ) kill();
    else if (s == "cls") system("cls");
    else if (s == "exit" ) exit(0);
    else if (s == "New Year" || s == "ny") new_year();
    else if (s == "info about pers" || s == "info") { myinf(); cout << endl; }
    else { cout << "Error. Please enter again\n" << endl; count_errors++; }
    if(count_errors > 2){
        cout << "Error. Please enter again.\n";
        help();
        cout << endl;
        count_errors = 0;
    }
}


void human::help(){
    cout << "Enter this (or this) for this:\n"
            "help (h) ------------------- I think, you understand :-)\n"
            "exit ----------------------- if you want finish the game\n"
            "child (c) ------------------ new child in family\n"
            "children (cn) -------------- info of all children\n"
            "relationship (r) ----------- info of relationship your character\n"
            "change relationships (cr) -- set relatioship to reverse\n"
            "New Year (ny) -------------- go to next year\n"
            "info about pers (info) ----- information about your character\n"
            "cls ---------------------- cls terminal\n\n";
}

void human::new_year(){
    this->age++;
    partner.age++;
    for(int i = 0; i < children; i++){
        ch[i].age++;
    }
    system("cls");
    cout << "    Happy New Year!!!  \n"
            " _______  ___________  \n"
            " \\_____/ |~~~~~~~~~~~| \n"
            "  \\   /  |~~~~~~~~~~~| \n"
            "   \\_/   |~~~~~~~~~~~| \n"
            "    |    |___________| \n"
            "  __|__     ___|___    \n";
}

int main(){
    srand(time(0));
    cout << "Welcome! You are in simulator of human\n";
    string s;
    human pers;
    pers.set_parametrs();
    system("cls");
    cout << "Congratulation, you are create your character\n"
            "For help write \"help\"\n";
    int count_errors = 0;
    s = cin.get();
    do{
        pers.goup(count_errors,s);
    } while(true);
    return 0;
}
