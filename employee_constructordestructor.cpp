#include <iostream>
#include <string>
using namespace std;

class Employee{
    private:
        int emp_id;
        string name;
        string post;
        string branch;
        static int count;
    public:
        Employee(){
            emp_id = 103;
            name = "Santosh";
            post = "Manager";
            branch = "IT";
            count++;
        }
        Employee(int emp_id,string name,string post,string branch){
            this->emp_id=emp_id;
            this->name=name;
            this->post=post;
            this->branch=branch;
            count++;
        }
        Employee(Employee &a){
            this->emp_id = a.emp_id;
            this->name = a.name;
            this->post = a.post;
            this->branch = a.branch;
            count++;
        }
        ~Employee(){
            cout<<"Destructor Called !"<<endl;
        }
        void display(){
            cout<<"Emp No -> "<<emp_id<<endl;
            cout<<"Emp Name -> "<<name<<endl;
            cout<<"Post -> "<<post<<endl;
            cout<<"Branch -> "<<branch<<endl;
        }
        static int returnCount(){
            return count;
        }
};

int Employee::count=0;
int main(){
    int emp_id;
    string name,post,branch;
    cout<<"Enter Employee ID : ";
    cin>>emp_id;
    cout<<"Enter Student Name : ";
    cin>>name;
    cout<<"Enter Post : ";
    cin>>post;

    Employee e1;
    Employee e2(emp_id,name,post,branch);
    Employee e3(e2);

    e1.display();
    e2.display();
    e3.display();
    cout<<"Total Number of Employees -> "<<Employee::returnCount();
}