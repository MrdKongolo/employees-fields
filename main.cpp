#include <iostream>

using namespace std;

class AbsractEmployee{
    virtual void AskForPromotion() = 0;
};

class Employee:AbsractEmployee {
    private :
        string Company;
        int Age;
    protected:
        string Name;
    public :
        void setName(string name){
            Name = name;
        }
        string getName(){
            return Name;
        }
        void setCompany(string company){
            Company = company;
        }
        string getCompany(){
            return Company;
        }
        void setAge(int age){
            if(age >= 18)
                Age = age;
        }
        int getAge(){ return Age;}

        void IntroduceYourself(){
            cout << "Name - " << Name << endl;
            cout << "Company - " << Company << endl;
            cout << "Age - " << Age << endl;
        }

        Employee(string name, string company, int age){
            Name = name;
            Company = company;
            Age = age;
        }
        void AskForPromotion(){
            if(Age>30){
                std::cout<<Name<< " got promoted!"<<endl;
            }else{
                std::cout<<Name<<" , sorry no promotion for you!"<<endl;
            }
        }
        virtual void Work(){
            cout <<Name<< " is checking email, task backlog, perfoming tasks ..."<<endl;
        }
};

class Developer:public Employee{
    public:
        string FavProgrammingLangage;
        Developer(string name, string company, int age, string favProgrammingLangage):Employee(name,company,age){
            FavProgrammingLangage = favProgrammingLangage;
        }
        void FixBug(){
            cout<<Name<< " fixed bug using "<<FavProgrammingLangage<<endl;
        }
        void Work(){
            cout <<Name<< " is writing " <<FavProgrammingLangage<< " code" <<endl;
        }
};

class Teacher:public Employee {
    public:
        string Subject;
        Teacher(string name, string company, int age, string subject):Employee(name,company,age){
            Subject = subject;
        }
        void PrepareLesson(){
            cout <<Name<<" is preparing "<<Subject << " lesson" <<endl;
        }
        void Work(){
            cout <<Name<< " is teaching " <<Subject<<endl;
        }
};
int main()
{
    //Employee empl = Employee("Saldina","CodeBeauty",25);
    //Employee empl2 = Employee("John","Amazon",35);
    Developer d = Developer("Mrd","Ngoma",32,"C++");
    //d.FixBug();
    //d.AskForPromotion();

     Teacher t = Teacher("Mike","School",28,"Maths");
     //t.AskForPromotion();
     //t.PrepareLesson();
     d.Work();
     t.Work();

     Employee *em = &d;
     em->Work();

    return 0;
}
