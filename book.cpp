//Create a book class with private members title author year and create static variable to count number of books
#include<iostream>
#include<string>
using namespace std;

class book{
    private:
        string title;
        string author;
        string date;
        static int count;
    public:
        book(string title,string author,string date){
            this->title = title;
            this->author = author;
            this->date = date;
            count++;
        }
        void display(){
            cout<<"Book Title -> "<<title<<endl;
            cout<<"Book Author -> "<<author<<endl;
            cout<<"Date of Upload -> "<<date<<endl;
        }
        static int returnCount(){
            return count;
        }
};
int book::count=0;
int main(){
    book b1("Vimpy Kid","Harshit Seth","14-07-2005");
    book b2("Geronimo Stilton","Yohaan Thadaney","04-02-2006");
    book b3("Started from the bottom now we at the top","Harshit Seth","14-07-2005");
    cout<<"---------------------------------------"<<endl
    b1.display();
    cout<<"---------------------------------------"<<endl
    b2.display();
    cout<<"---------------------------------------"<<endl
    b3.display();
    cout<<"---------------------------------------"<<endl
    cout<<"Total No of Books -> "<<book::returnCount();
}