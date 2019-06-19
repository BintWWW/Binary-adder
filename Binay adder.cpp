/*
Programmer: Bintao Wang
Program: bwangP5.cpp
Purpose: to allow computer do the binary addtion and convert binary to decimal, and convert decimal to binary

Input:two binary numbers
Output:the sum of binary numbers, and that in decimal.

*/




#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

class binary{                        //define the class
    unsigned long long int data;     //data inputed

public:
    binary () {};                       // default constructor
    binary (unsigned long long int theData)  // copy constructor
          {data = theData;};

    binary  operator+ (binary);   // overload within class; first operand implicit
    binary& operator= (int);
    friend binary operator+ (float, binary);  // friend allows "normal" parameters
    friend ostream& operator<< (ostream&, binary);      //cout
    friend istream& operator>> (istream&, binary&);     //cin
    int todecimal();                                    //turn binary to decimal
    binary tobinary (int i);                            //turn decimal to binary
    //int turn(){return digit;}
};

ostream& operator<< (ostream& co, binary g)
{
   co << g.data << endl;
   return co;
}

istream& operator>> (istream& ci, binary& g)
{
    ci >> g.data;
    return ci;
}

int main(){
    binary one, two, three;                         // the number that is going to be put in
    int inum;                                       // const int
    cout << "Type in two binary numbers to add: ";
    cin >> one;
    cin >> two;
    one = one + two;
    cout << "Sum is: " << one << endl;

    inum = 18;
    three = inum;
    three = three + 4;
    cout << "Binary is: " << three << endl;
    cout << "Its decimal value is: " << three.todecimal() << endl;
    return 0;
}

int binary::todecimal(){                    //turn binary to decimal
    unsigned long long int temp = data;     //using temp instead of data in calculation
    unsigned long long int decimal = 0;     //the result in decimal
    int num = 0;
    while(temp!=0){
        decimal += temp%10*pow(2,num);
        num ++;
        temp = temp/10;
    }
    return decimal;

}
binary binary ::tobinary (int i){           //turn decimal to binary
    binary newbinary(data);
    int thei = i;
    int binary = 0;                         //the result in binary
    int num = 0;
    while(thei!=0){
        binary += thei%2*pow(10,num);
        num ++;
        thei = thei/2;
    }
    newbinary.data = binary;
    return newbinary;
}
binary binary::operator+ (binary b){        //telling how to use a "+" sign
    binary newbinary(data);
    newbinary.data = todecimal()+b.todecimal();
    return newbinary;
}
binary& binary:: operator= (int i){         //telling how to use a "=" sign
    *this = tobinary(i);

    return *this;
}
