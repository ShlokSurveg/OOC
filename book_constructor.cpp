//Book using constructor

#include <iostream>
#include <string>
using namespace std;

class Book{
    private:
        string title;
        string author;
        string date;
        static int count;
    public:
        Book(){
            title = "Constituition Of India";
            author = "Dr. B.R. Ambedkar";
            date = "26-11-1949";
            count++;
        }
        Book(string title,string author,string date){
            this->title = title;
            this->author = author;
            this->date = date;
            count++;
        }
        Book(Book &b){
            this->title = b.title;
            this->author = b.author;
            this->date = b.date;
            count++;
        }

        void display(){
            cout<<"Book Title -> "<<title<<endl;
            cout<<"Author -> "<<author<<endl;
            cout<<"Date -> "<<date<<endl;
        }
        
        static int returnCount(){
            return count;
        }
};
int Book::count=0;
int main(){
    string title,author,date;
    cout<<"Enter title of book : ";
    cin>>title;
    cout<<"Enter Author Name : ";
    cin>>author;
    cout<<"Enter date of Upload : ";
    cin>>date;
    Book s1;
    Book s2(title,author,date);
    Book s3(&s2);

    cout<<"Default Constructor !"<<endl;
    s1.display();
    cout<<"Parameterized Constructor !"<<endl;
    s2.display();
    cout<<"Copy Constructor !"<<endl;
    s3.display();

    cout<<"The total no of books are -> "<<Book::returnCount();
}
