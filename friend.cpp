#include<iostream>
#include<string>
using namespace std;

class Student{
    private:
        string name;
        int rollNumber;
        string studentClass;
        char division;
        string dob;
        string aadharNumber;
        string bloodGroup;
        string contactAddress;
        string telephoneNumber;
        double marks1;
        double marks2;
        double marks3;
        static int count;
    public:
    Student(string name, int rollNumber, string studentClass, char division, string dob,
    string aadharNumber, string bloodGroup, string contactAddress, string telephoneNumber,double marks1,double marks2,double marks3)
    {
        this->name = name;
        this->rollNumber = rollNumber;
        this->studentClass = studentClass;
        this->division = division;
        this->dob = dob;
        this->aadharNumber = aadharNumber;
        this->bloodGroup = bloodGroup;
        this->contactAddress = contactAddress;
        this->telephoneNumber = telephoneNumber;
        this->marks1=marks1;
        this->marks2=marks2;
        this->marks3=marks3;
        count++;
    }
    void display() {
        cout << "Name: " <<name<<endl;
        cout << "Roll Number: " <<rollNumber<<endl;
        cout << "Class: " <<studentClass<<endl;
        cout << "Division: " <<division<<endl;
        cout << "Date of Birth: " <<dob<<endl;
        cout << "Aadhar Number: " <<aadharNumber<<endl;
        cout << "Blood Group: " <<bloodGroup<<endl;
        cout << "Contact Address: " <<contactAddress<<endl;
        cout << "Telephone Number: " <<telephoneNumber<<endl;
    }
    
    static int returnCount(){
        return count;
    }
    friend double calcPercentage(Student);
};
int Student::count=0;
double calcPercentage(Student s)
{
    return ( ((s.marks1+s.marks2+s.marks3)/300)*100 );
}
int main()
{
    Student s1("John Doe", 101, "10th", 'A', "01-01-2005", "123456789012", "O+", "123 Main St,City", "1234567890",90.3,91.2,93.1);
    Student s2("Jane Smith", 102, "10th", 'B', "02-02-2005", "987654321012", "A+", "456 Elm St,City", "0987654321",94.8,95.2,97.5);
    cout<<"\nStudent 1: "<<endl;
    s1.display();
    cout<<"The perecntage is: "<<calcPercentage(s1);
    cout<<"\n\nStudent 2: "<<endl;
    s2.display();
      cout<<"The perecntage is: "<<calcPercentage(s2);
    cout<<"\n\nThe total number of students are: "<<Student::returnCount()<<endl;
    return 0;
}