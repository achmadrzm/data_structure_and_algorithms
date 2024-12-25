#include <iostream>

using namespace std;

struct bilKompleks{
    private:
        int a,b,c,d;
    public:
        void add(int a, int b, int c, int d);
        void substract(int a, int b, int c, int d);
        void multiply(int a, int b, int c, int d);
        void divided(int a, int b, int c, int d);
};

void bilKompleks::add(int a, int b, int c, int d){
    a=a;
    b=b;
    c=c;
    d=d;
    cout << "(" << a << "+" << b << "i)" << "+" << "(" << c << "+" << d << "i)" << "=";
    cout << "(" << a << "+" << c << ")" << "+" << "(" << b << "+" << d << ")i" << "\n";
}

void bilKompleks::substract(int a, int b, int  c, int d){
    a=a;
    b=b;
    c=c;
    d=d;
    cout << "(" << a << "+" << b << "i)" << "-" << "(" << c << "+" << d << "i)" << "=";
    cout<< "(" << a << "-" << c << ")" << "+" << "(" << b << "-" << d << ")i" << "\n";
}

void bilKompleks::multiply(int a, int b, int c, int d){
    a=a;
    b=b;
    c=c;
    d=d;
    cout << "(" << a << "+" << b << "i)" << "*" << "(" << c << "+" << d << "i)" << "=";
    cout << "(" << a*c << "-" << b*d << ")" << "+" << "(" << a*d << "+" << b*c << ")i" << "\n";
}

void bilKompleks::divided(int a, int b, int c, int d){
    a=a;
    b=b;
    c=c;
    d=d;
    cout << "(" << a << "+" << b << "i)" << "/" << "(" << c << "+" << d << "i)" << "=";
    cout << "[(" << a*c << "+" << b*d << ")/" << "(" << a*a << "+" << b*b << ")] + [(" << b*c << "-" << a*d << ")/" << "(" << c*c << "+" << d*d << ")]i" << "\n";
}

int main(){
    bilKompleks *kom=new bilKompleks();
    int a,b,c,d;
    cout<<"Masukkan a = ";
    cin>>a;
    cout<<"Masukkan b = ";
    cin>>b;
    cout<<"Masukkan c = ";
    cin>>c;
    cout<<"Masukkan d = ";
    cin>>d;
    cout << "\nPenjumlahan : ";
    kom->add(a,b,c,d);
    cout << "Pengurangan : ";
    kom->substract(a,b,c,d);
    cout << "Perkalian : ";
    kom->multiply(a,b,c,d);
    cout << "Pembagian : ";
    kom->divided(a,b,c,d);
    
    return 0;
}