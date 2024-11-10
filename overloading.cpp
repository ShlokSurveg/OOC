#include<iostream>
#include<string>
using namespace std;

class Complex{
    private:
        int real = 0;
        int imag = 0;
    public:
        void setComplex(){
            cout<<"Enter real part :";
            cin>>real;
            cout<<"Enter the Imaginary Part : ";
            cin>>imag;
            cout<<"Complex Number has been stored."<<endl;
        }
        void display(){
            cout<<"The complex number is -> ";
            if(imag<0)
                cout<<real<<imag<<"i"<<endl;
            else
                cout<<real<<"+"<<imag<<"i"<<endl;
        }
        
        Complex operator +(Complex c){
            Complex ans;
            ans.real = real + c.real;
            ans.imag = imag + c.imag;
            return ans;
        }
        Complex operator -(Complex c){
            Complex ans;
            ans.real = real - c.real;
            ans.imag = imag - c.imag;
            return ans;
        }
        Complex operator *(Complex c){
            Complex ans;
            ans.real = real * c.real;
            ans.imag = imag * c.imag;
            return ans;
        }
        Complex operator /(Complex c){
            Complex ans;
            ans.real = real / c.real;
            ans.imag = imag / c.imag;
            return ans;
        }
};

int main(){
    Complex c1,c2,c3;
    c1.setComplex();
    c2.setComplex();
    int ch;
    cout<<"-----MENU-----"<<endl;
    cout<<"1.Add"<<endl<<"2.Substract"<<endl<<"3.Multiply"<<endl<<"4.Divide"<<endl<<endl<<"Your Choice -> ";
    cin>>ch;
    switch(ch){
        case 1: c3 = c1+c2;
                c3.display();
                break;
        case 2: c3 = c1-c2;
                c3.display();
                break;
        case 3: c3 = c1*c2;
                c3.display();
                break;
        case 4: c3 = c1/c2;
                c3.display();
                break;
        default:cout<<"Invalid Input!"<<endl;
    }   cout<<"Exiting.....";
}