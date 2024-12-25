#include <iostream>

using namespace std;

struct polinom{
    int x; 
    int P1[10] = {0,6,8,0,5,0,1,0,0,15};
    int P2[10] = {3,0,4,0,0,3,2,2,0,10};
    int P3[10] = {0,0,0,0,0,0,0,1,0,5};
    int P1s[5] = {6,8,5,1,15};
    int P3s[2] = {1,5};
    int P1x[5] = {8,7,5,3,0};
    int P3x[2] = {2,0};
    void printP1();
    void printP2();
    void printP3();
    void add();
    void substract();
    void multiply();
    void derivative();
};

void polinom::printP1(){
    x=9;
    for(int i=0; i<10; i++){
        if(P1[i] != 0){
            cout << " +(" << P1[i] << "x^" << x << ")";
        }
        x--;
    }
    cout << endl;
}

void polinom::printP2(){
    x=9;
    for(int i=0; i<10; i++){
        if(P2[i] != 0){
            cout << " +(" << P2[i] << "x^" << x << ")";
        }
        x--;
    }
    cout << endl;  
}

void polinom::printP3(){
    x=9;
    for(int i=0; i<10; i++){
        if(P3[i] != 0){
            cout << " +(" << P3[i] << "x^" << x << ")";
        }
        x--;
    }
    cout << endl;
}

void polinom::add(){
    x=9;
    int hasil[9];
    for(int i=0; i<10; i++){
        hasil[i] = P1[i]+P2[i];
        if(hasil[i]!=0){
            cout << "+(" << hasil[i] << "x^" << x << ")";
        }
        x--;
    }
}

void polinom::substract(){
    x=9;
    int hasil[9];
    for(int i=0; i<10; i++){
        hasil[i] = P1[i]-P2[i];
        if(hasil[i] != 0){
            cout << "(" << hasil[i] << "x^" << x << ")" << "+";
        }
        x--;
    }
}
void polinom::multiply(){
    int hasil[10];
    int hasil2[10];
    for(int i=0; i<5; i++){
        for(int j=0; j<2; j++){
            hasil[i] = P1s[i]*P3s[j];
            hasil2[i] = P1x[i]+P3x[j];
            if(hasil[i]==40 || hasil[i]==25){        
                continue;
            }
            if(hasil2[i]==hasil2[i-1]){
                hasil[i]=hasil[i]+hasil[i-1];
            }
                cout << " +(" << hasil[i] << "x^" << hasil2[i] <<")";
        }
    }
}
void polinom::derivative(){
    x=9;
    int hasil[9];
    for(int i=0; i<10; i++){
        hasil[i] = P2[i]*x;
        if(hasil[i] != 0){
            cout << " +(" << hasil[i] << "x^" << x-1 << ")";
        }
        x--;
    }
}

int main(){
    polinom *pol=new polinom();
    cout << "P1 : ";
    pol->printP1();
    cout << "\nP2 : ";
    pol->printP2();
    cout << "\nP3 : ";
    pol->printP3();
    cout << "\nOperasi Aritmatika : \n";
    cout << "Penjumlahan : ";
    pol->add();
    cout << "\nPengurangan : ";
    pol->substract();
    cout << "\nPerkalian : ";
    pol->multiply();
    cout << "\nTurunan : ";
    pol->derivative();
    cout << endl;
    
    return 0;
}