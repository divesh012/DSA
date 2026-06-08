#include <iostream>
#include <string>
using namespace std;

class Teacher {
  // Properties
 private:
  double salary;

 public:
  string name;
  string dept;
  string subject;

  // Non Parameterized Constructor
  Teacher() { dept = "Computer Science"; }

  // Parameterized Constructor
  Teacher(string name, string dept, string subject, double salary) {
    this->name = name;
    this->dept = dept;
    this->subject = subject;
    this->salary = salary;
  }
  // Copy Cnstructor
  Teacher(Teacher& origObj) {  // passed by reference
    cout << "I am custom copy Constructor!!!" << endl;
    this->name = origObj.name;
    this->dept = origObj.dept;
    this->subject = origObj.subject;
    this->salary = origObj.salary;
  }

  // method //member function
  void changeDept(string newDept) { dept = newDept; }
  // setter --> private value ko set krne main kam ate
  void setSalary(double s) { salary = s; }
  // getter --> private value ko get krne main kam ate
  double getSalary() { return salary; }
  void getInfo() {
    cout << "This is teacher Imp details \nname: " << name
         << " Subject: " << subject << endl;
  }
};
class Student {
 public:
  string name;
  double* cgpaPtr;  // pointer Create

  Student(string name, double cgpa) {
    this->name = name;
    cgpaPtr = new double;
    *cgpaPtr = cgpa;
  }
  Student(Student& obj) {
    this->name = obj.name;
    cgpaPtr = new double;
    *cgpaPtr = *obj.cgpaPtr;
  }
  ~Student() {
    cout << "Hii I delete everything Called as destructor!!" << endl;
    delete cgpaPtr;  // They can be not show but internal work memory free
  }

  void getInfo() {
    cout << "Name: " << name << endl;
    cout << "CGPA: " << *cgpaPtr << endl;
  }
};

int main() {
  Student s1("Rahul Kumar", 8.9);
  Student s2(s1);  // neha kumar
  s1.getInfo();
  *(s2.cgpaPtr) = 9.2;
  s1.getInfo();
  s2.name = "Neha Kumar";
  s2.getInfo();

  Teacher t1("Divesh", "Computer Science", "c++", 25000);  // cunstructor call
  t1.getInfo();
  t1.name = "Divesh";
  // t1.dept="Computer Science";
  t1.subject = "c++";
  // t1.salary = 25000; ---> this is not work because this is private access
  // modifier
  t1.setSalary(25000);
  cout << "This is teacher dept: " << t1.dept << endl;
  cout << t1.getSalary() << endl;
  cout << "\n!!-------called Copy Constructor------!!" << endl;
  Teacher t2(t1);  // copy constructor
  t2.getInfo();
  return 0;
}
// Inheritance
#include <iostream>
#include <string>
using namespace std;

class person {
 public:
  string name;
  int age;

  // person(string name,int age){
  // this ->name = name;
  // this ->age = age;
  // }
  // person(){
  //  cout<<"Parent consstructor"<<endl;

  //}
  //~person(){
  // cout<<"Parent desstructor"<<endl;

  //}
};

class student : public person {
  // name age rollNo
 public:
  int rollNo;
  // student(string name,int age,int rollno): person(name,age){ //cunstructor
  // called do not used datatype only name string name or int age that type
  // cout<<"child constructor"<<endl;
  // this -> rollno = rollno;
};

class teacher : public person {
 public:
  string subject;
};
// ~student (){
//    cout<<"Child desstructor"<<endl;
// }
// void getInfo(){
///    cout<<"Name: "<<name<<endl;
//   cout<<"Age: "<<age<<endl;
//    cout<<"Roll NO.: "<<rollno<<endl;
//  }
//};

int main() {
  teacher t1;
  student s1;
  s1.name = "I love";
  cout << s1.name << endl;
  t1.name = "Divesh Kuthe";
  t1.subject = "Physics";
  cout << t1.name << " and " << t1.subject << endl;
  // s1.rollno = 15;
  // s1.getInfo();
  return 0;
}
// Static Function and virtual function
#include <iostream>
#include <string>
using namespace std;
class A {  // automatically abstact clss because pure virtual function
 public:
  int x;
  void incX() { x = x + 1; }
  // virtual void draw() = 0; //pure Virtual function
};
// class circle: public shape{
//   public:
// void draw(){
//   cout<<"drw the circle"<<endl;
//}
//};

int main() {
  A obj1;
  A obj;
  obj.x = 0;
  cout << obj.x << endl;
  obj.incX();
  cout << obj.x << endl;
  A obj2;
  obj1.x = 100;
  obj2.x = 200;
  cout << obj1.x << endl;
  obj1.incX();
  cout << obj2.x << endl;

  return 0;
}