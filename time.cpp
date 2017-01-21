#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

class vremya{
    int h,m,s;
    void set_time();
    void set_hours();
    void set_minutes();
    void set_seconds();
public:
    friend ostream& operator <<(ostream& out, vremya& a){
        out << a.h << ':' << a.m << ':' << a.s << endl;
        return out;
    }
    friend istream& operator >>(istream& in, vremya &a){
        char dubpo;
        in >> a.h >> dubpo >> a.m >> dubpo >> a.s;
        a.set_time();
        return in;
    }
    friend vremya operator +(vremya a, vremya b);
    vremya *operator +=(vremya a);
    friend vremya operator +(vremya a, int s);
    vremya *operator +=(int s);
};

vremya operator +(vremya a, vremya b){
    a.s += b.s;
    a.m += b.m;
    a.h += b.h;
    a.set_time();
    return a;
}
vremya* vremya::operator +=(vremya a){
    this->s += a.s;
    this->m += a.m;
    this->h += a.h;
    this->set_time();
    return this;
}
vremya operator +(vremya a, int s){
    a.s += s;
    a.set_time();
    return a;
}
vremya* vremya::operator +=(int s){
    this->s += s;
    this->set_time();
    return this;
}
void vremya::set_time(){
    m += s / 60;
    s %= 60;
    h += m / 60;
    m %= 60;
    h %= 24;
}


int main(){
    return 0;
}
