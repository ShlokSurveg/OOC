#include<iostream>
#include<string>
using namespace std;

class Employee
{
    private:
        string ename;
        int empId;
        
    public:
        Employee(){
            cout<<"\nEMPLOYEE DETAILS"<<endl;
        }
        
        Employee(string ename,int empId)
        {
            this->ename = ename;
            this->empId = empId;
        }
        
        void display()
        {
            cout<<"Employee Name: "<<ename<<endl;
            cout<<"Employee Id: "<<empId<<endl;
        }
        
        virtual double earnings()=0;
};

class SalariedEmployee: public Employee
{
    private:
        double weeklySal;
    
    public:
        SalariedEmployee() : Employee()
        {
            cout<<"\nSalaried Employee"<<endl;
            cout<<"-----------------"<<endl;
        }
        
        SalariedEmployee(string ename, int empId, double weeklySal) : Employee(ename, empId)
        {
            this->weeklySal = weeklySal;
        }
        
        void display()
        {
            Employee::display();
            cout<<"Weekly Salary: "<<weeklySal<<endl;
        }
        
        double earnings(){
            return weeklySal;
        }
};

class HourlyEmployee: public Employee
{
    private:
        double wage;
        double hours;
    
    public:
        HourlyEmployee() : Employee()
        {
            cout<<"\nHourly Employee"<<endl;
            cout<<"-----------------"<<endl;
        }
        
        HourlyEmployee(string ename, int empId, double wage, double hours) : Employee(ename, empId)
        {
            this->wage = wage;
            this->hours = hours;
        }
        
        void display()
        {
            Employee::display();
            cout << "Wage: " << wage << endl;
            cout << "Hours: " << hours << endl;
        }
        double earnings()
        {
            if (hours < 40) 
            {
                return hours * wage;
            } 
            else 
            {
                return 40 * wage + ((hours - 40) * wage * 1.5);
            }
        }
};

class CommissionEmployee : public Employee
{
    private:
        double grossSales;
        double commissionRate;
    
    public:
        CommissionEmployee() : Employee()
        {
            cout<<"\nCommission Employee"<<endl;
            cout<<"-----------------"<<endl;
        }
        
        CommissionEmployee(string ename, int empId, double grossSales, double commissionRate) : Employee(ename, empId)
        {
            this->grossSales = grossSales;
            this->commissionRate = commissionRate;
        }
        
        void display()
        {
            Employee::display();
            cout << "Gross Sales: " << grossSales << endl;
            cout << "Commission Rate: " << commissionRate << endl;
        }
        double earnings()
        {
            return grossSales * commissionRate;
        }
};

int main()
{
    SalariedEmployee se("Aditya", 1, 1000.0);
    HourlyEmployee he("Aryan", 2, 20.0, 45.0);
    CommissionEmployee ce("Rahul", 3, 5000.0, 0.1);

    SalariedEmployee demo;
    se.display();
    cout<<"Earnings: "<<se.earnings()<<endl;
    
    HourlyEmployee demo1;
    he.display();
    cout<<"Earnings: "<<he.earnings()<<endl;
    
    CommissionEmployee demo2;
    ce.display();
    cout<<"Earnings: "<<ce.earnings()<<endl;
    return 0;
}
