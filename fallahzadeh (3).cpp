#include<iostream>
#include<string>
using namespace std;
static long int staticid = 92000000;
class date{
	int year, month, day;
public:
	date(int y = 0, int m = 0, int d = 0){
		year = y;
		month = m;
		day = d;
	}
	void print(){
		cout << year << "/" << month << "/" << day<<endl;
	}
	void set(){
		cout << "year of birth: ";
		cin >> year;
		cout << "month of birth: ";
		cin >> month;
		cout << "day of birth: ";
		cin >> day;
	}
};
class person {
protected:
	string gender;//male or female
	int age;//>0
	date birthday;
	string name;
	int id;
public:
	person(){
		gender = "unknown";
		age = 0;
		id = 0;
		name = "unknown";
	}
	person(string g, int a,string n,int year,int month,int day):birthday(year,month,day){
		id = staticid++;
		name = n;
		age = a;
		gender = g;
	}
	virtual void print(){
		cout << "name : " << name << endl ;
		cout << "gender : " << gender << endl;
		cout << "age : " << age << endl;
		cout << "id: " << id << endl;
		birthday.print();
	}
	virtual void set(){
		cout << "name : ";
		cin >> name;
		cout << "gender : ";
		cin >> gender;
		cout << "age : ";
		cin >> age;
		birthday.set();
		}
};
class course {
	string coursename;
	int unit;
	int grade;
public:
	course(string name="unknown",int u =0,int g=0){
		coursename = name;
		unit = u;
		grade = g;
	}
	void print(){
		cout << "course name : " << coursename <<endl;
		cout << "unit: " << unit<<endl;
		cout <<"grade: "<<grade <<endl;
	}
	void set(){
		cout << "course name : ";
		cin >> coursename;
		cout << "unit: ";
		cin >> unit;
		cout << "grade: ";
		cin >> grade;	
	}
};
class student : public person {
public:
	virtual void print(){
		cout <<"student info : " << endl;
		cout <<"name : " << name << endl; 
		cout <<"gender : " << gender << endl; 
		cout <<"age : " << age << endl;
		cout <<"id: " << id << endl;
		birthday.print();
		cout <<"average : " << avg << endl;
		cout <<"grade : " << gender << endl;
		cout <<"student id: " << studentID << endl;
		for (int i = 0; i < courseNO; i++){
			c[i].print();
		}
	}
	void setcourse(){
		c[courseNO].set();
		courseNO++;
	}
	student(){
		courseNO = 0;
		avg = 0;
		studentID = 0;
	}
	virtual void set(){
		cout << "name : ";
		cin >> name;
		cout << "gender : ";
		cin >> gender;
		cout << "age : ";
		cin >> age;
		birthday.set();
		cout << "average : ";
		cin >> avg;
		cout << "grade : ";
		cin >> gender;
		cout << "student id: ";
		cin >> studentID;
	}
protected:
	int avg;
	course c[30];
	int courseNO;
	int studentID;
};
class Undergraduate_student : public student {
public:
	Undergraduate_student(){
	}
	void print(){
		cout <<"-------------------------------------"<<endl;
		cout << "undergraduate_student info : " << endl;
		cout << "name : "<< name <<endl;
		cout << "gender : " << gender <<endl;
		cout << "age : " << age <<endl;
		cout << "id: " << id <<endl;
		birthday.print();
		cout << "average : " << avg <<endl;
		cout << "student id: " << studentID <<endl;
		for (int i = 0; i < courseNO; i++){
			c[i].print();
		}
		if (avg < 12){
			cout << "this Undergraduate_student is unQualified"<<endl;
		}
	}
};
class Masters_student : public student {
private:
	string branch;
public:
	Masters_student(){
		branch = "unknown";
	}
	void print(){
		cout <<"-------------------------------------"<<endl;
		cout << "Masters_student info : " << endl;
		cout << "name : " << name << endl;
		cout << "gender : " << gender << endl;
		cout << "age : " << age << endl;
		cout << "id: " << id << endl;
		birthday.print();
		cout << "average : " << avg << endl;
		cout << "branch: " << branch << endl;
		cout << "student id: " << studentID << endl;
		for (int i = 0; i < courseNO; i++){
			c[i].print();
		}
		if (avg < 14){
			cout << "this Msters_student is unQualified" << endl;
		}
	}
	void set(){
		cout <<"-------------------------------------"<<endl;
		cout << "Msters_student info :" << endl;
		cout << "name : ";
		cin >> name;
		cout << "gender : ";
		cin >> gender;
		cout << "age : ";
		cin >> age;
		birthday.set();
		cout << "average : ";
		cin >> avg;
		cout << "student id: ";
		cin >> studentID;
		cout << "branch :";
		cin >> branch;
	}
};
int main()
{
	student *A[3];
	A[0] = new Undergraduate_student;
	A[1] = new Masters_student;
	A[2] = new Masters_student;
	for (int i = 0; i < 3; i++){
		A[i]->set();
		A[i]->setcourse();
		A[i]->print();
	}
	return 0;
}
