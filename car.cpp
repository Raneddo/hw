#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

class car{
    string name;
    int year;
    string color;
    int max_speed;
    int price;
    friend car set_parametrs(car &a);
    friend void find_year(car *a, int count);
    friend void find_color(car *a,int count);
    friend void find_max_speed(car *a, int count);
    friend void find_price(car *a,int count);
    friend void find_name(car *a, int count);
    friend void find(car *a, int count);
public:
    friend void start(string s, int &count, car *a);
};

void find(car *a, int count){
    cout << "If you want:\n"
            "find by name,  enter \"name\"\n"
            "find by year,  enter \"year\"\n"
            "find by color, enter \"color\"\n"
            "find by price, enter \"price\"\n"
            "find by max speed, enter \"ms\"\n";
    string s;
    cin >> s;
    if(s == "name") find_name(a,count);
    else if (s == "year") find_year(a, count);
    else if (s == "color") find_color(a,count);
    else if (s == "price") find_price(a, count);
    else if (s == "ms") find_max_speed(a, count);
    else cout << "ERROR!!!\n";
}

void find_year(car *a, int count){
    cout << "What year do you would like?\n";
    int tyear;
    cin >> tyear;
    cout << "For " << tyear << " year we find these cars:\n";
    for(int i = 0; i <= count; i++){
        if(a[i].year == tyear) cout << a[i].name << " color: "
                                    << a[i].color << " m.s.: "
                                    << a[i].max_speed << " price: "
                                    << a[i].price << endl;
    }
}

void find_color(car *a, int count){
    cout << "What color do you would like?\n";
    string tyear;
    cin >> tyear;
    cout << "For " << tyear << " color we find these cars:\n";
    for(int i = 0; i <= count; i++){
        if(a[i].color == tyear) cout << a[i].name << " year: "
                                    << a[i].year << " m.s.: "
                                    << a[i].max_speed << " price: "
                                    << a[i].price << endl;
    }
}

void find_max_speed(car *a, int count){
    cout << "What max speed do you would like?\n";
    int tyear;
    cin >> tyear;
    cout << "For " << tyear << " max speed and faster we find these cars:\n";
    for(int i = 0; i <= count; i++){
        if(a[i].max_speed >= tyear) cout << a[i].name << " year: "
                                         << a[i].year << " color: "
                                         << a[i].color << " m.s.: "
                                         << a[i].max_speed << " price: "
                                         << a[i].price << endl;
    }
}

void find_price(car *a, int count){
    cout << "What price do you would like?\n";
    int tyear;
    cin >> tyear;
    cout << "For " << tyear << " price we find these cars:\n";
    for(int i = 0; i <= count; i++){
        if(a[i].price <= tyear && a[i].price != 0)
            cout << a[i].name << " year: "
                 << a[i].year << " color: "
                 << a[i].color << " m.s.: "
                 << a[i].max_speed << " price: "
                 << a[i].price << endl;
    }
}

void find_name(car *a, int count){
    cout << "What name do you would like?\n";
    string tyear;
    cin >> tyear;
    cout << "For " << tyear << "  we find these cars:\n";
    for(int i = 0; i <= count; i++){
        if(a[i].name == tyear) cout << a[i].name << " year: "
                                    << a[i].year << " color: "
                                    << a[i].color << " m.s.: "
                                    << a[i].max_speed << " price: "
                                    << a[i].price << endl;
    }
}

car set_parametrs(car &a){
    cout << "Enter parametrs of the car\n"
            "+ name\n"
            "+ year\n"
            "+ color\n"
            "+ max speed\n"
            "+ price\n";
    cin >> a.name;
    cin >> a.year;
    cin >> a.color;
    cin >> a.max_speed;
    cin >> a.price;
    return a;
}

void start(string s,int  &count, car *a){
    if(s == "add car" || s == "ac") { a[count] = set_parametrs(a[count]); count++; }
    else if(s == "exit") exit(0);
    else if(s == "find" || s == "f") find(a,count);
}

int main(){
    car *a = new car [100];
    int count = 0;
    cout << "Hello, you are seller in cars shop\n"
            "write _this_ (or _this_) -for- _this_:\n"
            "add car (ac) --- add car to shop\n"
            "find (f) ------- find car in the shop\n"
            "exit ----------- exit this program\n";
    string s;
    while(true){
        cin >> s;
        start(s,count,a);
    }
    return 0;
}
