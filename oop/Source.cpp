#include<iostream>
#include<string>
#include<vector>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include<fstream>
#include <Windows.h>

using namespace std;
template<typename t> //template

void GoToXY(int, int); //function for going to x and y position
void Welcome();    // function of welcome screen
void Login(); //login function to database
void GoToXY(int x, int y)
{

	COORD coord;

	coord.X = x;

	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void Welcome()
{
	system("cls");
	system("color 74");
	GoToXY(14, 10);
	SetConsoleTextAttribute(GetStdHandle, 0x132);
	cout << "         WELCOME TO SEECS MANAGEMENT SYSTEM             " << endl;
	GoToXY(33, 15);
	cout << "THIS IS DATABASE OF\n";
	GoToXY(14, 16);
	cout << "SCHOOL OF ELECTRICAL ENGINEERING AND COMPUTER SCIENCES" << endl;
	GoToXY(25, 20);
	cout << "PRESS ENTER TO ACCESS THE SYSTEM" << endl;
	GoToXY(25, 21);
	cout << "................................";
	getchar();
	system("cls");
}
string getpassword(const string& prompt = "Enter password> ")
{
	string result; // Set the console mode to no-echo, not-line-buffered input
	DWORD mode, count;
	HANDLE ih = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE oh = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!GetConsoleMode(ih, &mode))
		throw runtime_error("TO GET PASSWORD: You must be connected to a console to use this program.\n");
	SetConsoleMode(ih, mode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT)); // Get the password string
	WriteConsoleA(oh, prompt.c_str(), prompt.length(), &count, NULL);
	char c;
	while (ReadConsoleA(ih, &c, 1, &count, NULL) && (c != '\r') && (c != '\n'))
	{
		if (c == '\b')
		{

			if (result.length())
			{
				WriteConsoleA(oh, "\b \b", 3, &count, NULL);
				result.erase(result.end() - 1);
			}
		}
		else
		{
			WriteConsoleA(oh, "*", 1, &count, NULL);
			result.push_back(c);
		}
	} // Restore the console

	SetConsoleMode(ih, mode);
	return result;
}

void Login()
{
	int y = 0;
	int z = 0;
	string username, psrwd;
	int x = 1;
	GoToXY(5, 10);
	system("cls");
	system("color 74");
	SetConsoleTextAttribute(GetStdHandle, 0x132);

	while (x)
	{
		if (!z)//condition if five time wrong name entered wait
		{
			system("cls");
			GoToXY(5, 10);
			system("color 74");
			SetConsoleTextAttribute(GetStdHandle, 0x132);
			cout << " USER NAME:     ";
			cin >> username;
			GoToXY(7, 16);
		}
		else;
		if (username == "SEECS") //if name is right else re_enter name
		{
			if (!y)
			{
				GoToXY(10, 16);
				psrwd = getpassword(" PASSWORD:> ");
			}
			else;
			if (psrwd == "seecs123")
			{
				system("cls");
				system("color 74");
				SetConsoleTextAttribute(GetStdHandle, 0x132);
				x = 0;
			}
			else
			{
				x = 1;
				system("cls");
				system("color 74");
				SetConsoleTextAttribute(GetStdHandle, 0x132);
				GoToXY(10, 13);
				cout << "USERNAME: SEECS" << endl;
				GoToXY(10, 15);
				cout << "INVALID PASSWORD";
				GoToXY(10, 16);
				psrwd = getpassword("RE - ENTER PASSWORD> ");
				y++;
				z = 1;
				continue;
			}
		}
		else
		{
			z++;
			x = 1;

			system("cls");
			GoToXY(5, 10);
			system("color 74");
			SetConsoleTextAttribute(GetStdHandle, 0x132);
			cout << "INVALID USERNAME" << endl;
			GoToXY(5, 13);
			cout << " Rw-Enter USER NAME:     ";
			cin >> username;
			if (z == 4)
			{
				GoToXY(7, 19);
				cout << "    5 times incorrect USERNAME entered, wait 5 seconds" << endl;
				z = 0;
				for (unsigned short i = 1; i < 6; i++)
				{
					Sleep(1000);
					GoToXY(28, 21);
					cout << "......   " << i << "  ........";
				}
			}
		}
	}
}


class person
{
private:                      //Person class data members
	string name;
	string sex;
	int age;
	string city;
public:
	person()                     //default constructor
	{
		name = "";
		sex = "";
		city = "";
		age = 0;
	}
	person(string n, string s, string c, int a) //parametarized constructor
	{
		name = n;
		sex = s;
		city = c;
		age = a;
	}
	//setter and getter functions for student class
	void setter(string n, string s, string c, int a)
	{
		name = n;
		sex = s;
		city = c;
		age = a;
	}
	string getname()
	{
		return name;           //it returns the name 
	}
	int getage()
	{
		return age;     //it returns the age 
	}
	string getsex()
	{
		return sex;     // it return the sex
	}
	string getcity()
	{
		return city;      //it return the city  name
	}
};
class student :public person
{
private:
	double gpa;
	char section;      //Student  attributes
	string department;
	int id;
	double fee;
public:
	student() //default constructor of student class
	{
		gpa = 0;
		section = '\0';
		department = "";
		id = 0;
	}
	student(string n, string s, string c, int a, double g, char se, string d, int i)
		:person(n, s, c, a)//parametarized constructor
	{
		gpa = g;
		section = se;
		department = d;
		id = i;
	}
	//setters function for student class
	void setter(string n, string s, string c, int a, double g, char se, string d, int i)
	{
		person::setter(n, s, c, a);
		gpa = g;
		section = se;
		department = d;
		id = i;
	}
	string getdepartment()
	{
		return department;
	}
	//friend functions
	friend ostream& operator <<(ostream &, vector<student>);    //friend function display lis of stdents
	friend void editstudent(vector<student> &); //edit student data
	friend void deleteSTUDENT(vector<student> &);  //delete any particular student
	friend void addstudent(vector<student> &);        //add the new student
	friend void viewparticularstudent(vector<student>);   //view particlar student
	friend class staff;                           //exam branch is friend of stdent
	friend class professor;                       //professor friend with stdent
	friend class Accounts;                        //accounts is friend with student
	friend class laibrary;
	friend void read(vector<student> &);
};
ostream& operator <<(ostream &strm, vector<student> v)
{
	int x;
	char d;
	system("cls");
	system("color 74");
	SetConsoleTextAttribute(GetStdHandle, 0x132);
	GoToXY(30, 13);
	cout << "WELCOME TO STUDENT INFORMATION SECTION" << endl;
	GoToXY(33, 15);
	cout << "1.VIEW ACADEMIC INFORMAION " << endl;
	GoToXY(33, 16);
	cout << "2.VIEW PERSONAL INFORMATION" << endl;
	GoToXY(33, 18);
	cout << "..ENTER CHOICE.." << endl;
	GoToXY(36, 19);
	cin >> x;                      //enter the choice value of x
	do
	{

		if (x == 1)                //if  entered value is 1
		{
			cout << " Name" << "\t\tGPA" << "  \t" << " section" << "\t" << "departemnt" << "\t" << "id" << endl << endl;
			for (unsigned int i = 0; i<v.size(); i++)
			{                                                //acedemic data of the stdents
				strm << ".." << v[i].getname() << "\t\t" << v[i].gpa << "\t " << v[i].section << " \t " << v[i].department << "\t " << v[i].id << endl;
			}

		}
		else if (x == 2)   //its true if entered value is 2
		{                        //personnal data of students
			
			for (int i = 0; i<v.size(); i++)
			{
				strm << "NAME    : " << v[i].getname() << endl <<"SEX     : "<< v[i].getsex() <<endl<<"CITY    : " << v[i].getcity() <<endl<<"AGE     : " << v[i].getage() << endl;
				for (int i = 0; i < 40; i++)
				{
					cout << "=";
				}
				cout << endl << endl;
			}
			
		}
		cout << "press y/n for seeing again" << endl;
		cin >> d;                      //enter the charactor y 
		cout << "press enter to continue.....";
		getchar();
		system("cls");
		if (d == 'y')     //if entered charactor is y
		{
			cout << "...enter 1 for to view acedemic data of student...." << endl << "...enter 2 for to view personal data of student..." << endl;
			cin >> x;            //again enter the value of x
		}
		else
			x = -1;                 //else end the loop here
	} while (x == 1 || x == 2);

	cout << "...thank you for display the list of student ....." << endl;
	return strm;
}
void editstudent(vector<student>& v)    //get vector from the stdents
{
	system("cls");
	system("color 74");
	SetConsoleTextAttribute(GetStdHandle, 0x132);
	unsigned int x, ID;           //enter the ID for edit it
	string s;
	cout << ".......enter your ID of Student......";
	cin >> ID;    //get ID
	for (int i = 0; i<v.size(); i++)
	{
		if (v[i].id == ID)     //entered ID is equal to id of any student then
		{
			cout << "Name.." << v[i].getname() << endl << "sex.." << v[i].getsex() << endl
				<< "age .." << v[i].getage() << endl << "city  " << v[i].getcity() << endl << "gpa is.." << v[i].gpa << endl <<
				"department  " << v[i].department << endl << "id.." << v[i].id << endl;
			cout << "you can change    gpa,section, of the student..." << endl;
			cout << "enter 1 for to change gpa of student...." << endl << "enter 2 for to change section of student...." << endl;
			cin >> x;               //enter vale of x to change its data
			if (x == 1)           //if value is 1
			{
				cout << " .......enter new new gpa of ..." << v[i].getname() << "     ";
				cin >> v[i].gpa;
				//enter the new Gpa of student
			}
			else
			{
				cout << "enter new new section of ..." << v[i].getname() << "     ";
				cin >> v[i].section;
			}           //else enter the new section of stdent

			read(v);            //call to read function
		}
	}
	cout << "thank you for editing student data......." << endl << endl << endl;
	cout << "PRESS ENTER TO CONTINUE" << endl;
	getchar();
}

void viewparticularstudent(vector<student> v)
{
	system("cls");
	system("color 74");
	SetConsoleTextAttribute(GetStdHandle, 0x132);
	unsigned int ID;
	GoToXY(5, 5);
	cout << "Enter the id of the student" << endl;
	cin >> ID;//get  its ID of student
	for (int i = 0; i<v.size(); i++)
	{
		if (v[i].id == ID)     //entered id is valid or not
		{
			GoToXY(0,7);
			cout << "Name      : " << v[i].getname() << endl << "Sex       : " << v[i].getsex() << endl
				<< "Age       : " << v[i].getage() << endl << "City      : " << v[i].getcity() << endl << "GPA       : " << v[i].gpa << endl <<
				"Department: " << v[i].department << endl << "ID        : " << v[i].id << endl;
		}
	}
	cout << endl;
}
void addstudent(vector<student> &v)
{
	system("cls");
	system("color 74");
	SetConsoleTextAttribute(GetStdHandle, 0x132);
	static int ID = 19;
	ID++;
	student s;     //temp object
	string n, se, c;
	int a;
	cout << "ENTER DATA OF THE STUDENT" << endl;
	cout << "enter name,sex,city,age,section,department,id,gpa, of the new student....." << endl;
	cout << "Name..";
	cin >> n;
	s.id = ID;
	cout << "age   .";
	cin >> a;
	cout << "sex ...";
	cin >> se;
	cout << "city..";
	cin >> c;
	cout << "section...";
	cin >> s.section;
	cout << "deparment...";
	cin >> s.department;

	cout << "gpa...";
	cin >> s.gpa;         //get the atributes of student
	s.person::setter(n, se, c, a);    //it calls to person setter function
	v.push_back(s);   //it pushes the object in list of stdents
	read(v);             //call to read function
	cout << "thank you for inserting new student in school..." << endl;
	cout << "PRESS ENTER TO CONTINUE" << endl;
	getchar();
}

void deleteSTUDENT(vector<student>& St)   //it delete the student from the list
{
	system("cls");
	system("color 74");
	SetConsoleTextAttribute(GetStdHandle, 0x132);
	int Id;
	int i = 0;
	cout << "Enter the id to delete STUDENT " << endl;    //enter the ID of student
	cin >> Id;
	for (i = 0; i < St.size() && St[i].id != Id; i++)  //it contine till Entered iD is equal to id of student
	{
	}
	cout << "Student " << St[i].getname() << " with id" << St[i].id << " is DELETED" << endl;
	St.erase(St.begin() + i);            //it delete the element here
	read(St);
}
class Employee :public person
{
protected:
	int id;           //data member of an Employee
	unsigned int salary;
public:
	Employee()
	{                 // default constuctor
		id = 0;
		salary = 0;
	}
	Employee(int Id, unsigned int s, string n, string se, string c, int x)
		:person(n, se, c, x)
	{
		id = Id;                   // parametrize constructor
		salary = s;
	}
	void setter(int Id, unsigned int s, string n, string se, string c, int x)
	{                                 //setter function for setting the values
		person::setter(n, se, c, x);
		id = Id;
		salary = s;
	}
	void setsalary(int x)
	{
		salary = x;    //set salary here
	}
	int getid()
	{
		return id;    //return the ID here
	}
	int getsalary()
	{
		return salary;    //return salary here
	}
	friend void display(vector<Employee>);
};

class professor :public Employee
{
protected:
	string subject;         //attributes of the Employee class
	string qualification;
public:
	professor()
	{                       //default constructor
		subject = "";
		qualification = "";
	}
	professor(string s, string q, int Id, unsigned int sal, string n, string se, string c, int x)
		:Employee(Id, sal, n, se, c, x)
	{
		subject = s;                    //paramerizee consturctor
		qualification = q;
	}
	void setter(string s, string q, int Id, unsigned int sal, string n, string se, string c, int x)
	{
		Employee::setter(Id, sal, n, se, c, x);
		subject = s;       //setter function for the professor
		qualification = q;
	}
	string getsubject()
	{
		return subject;     //it return the subject
	}
	string getqualification()
	{
		return qualification;     //it return the qualification

	}
	friend ostream& operator <<(ostream &, vector<professor>);            //it display the list of professor
	friend void edititem(vector<professor> &);    //  it edit the information of teacher  
	friend void deleteitem(vector<professor> &);   //it deleate the teacher 
	friend void additem(vector<professor> &);                   //it add new teacher to the school
	friend void viewparticular(vector<professor>);         //it view the particular to the list
	friend class staff;                //staff  is friend of professor class 
	friend class Accounts;             //Accounts is friend of Professor class
	friend void readprofessor(vector<professor> &);
};

void deleteitem(vector<professor>& St)   //it delete the student from the list
{
	int Id;
	int i = 0;
	system("cls");
	system("color 74");
	SetConsoleTextAttribute(GetStdHandle, 0x132);
	cout << "Enter the id to delete  professor " << endl;    //enter the ID of student
	cin >> Id;
	for (i = 0; i < St.size() && St[i].id != Id; i++)  //it contine till Entered iD is equal to id of student
	{
	}
	cout << "Professor " << St[i].getname() << " with id" << St[i].id << " is DELETED" << endl;
	St.erase(St.begin() + i);            //it delete the element here
	readprofessor(St);
}
ostream& operator <<(ostream &strm, vector<professor> v)
{
	int x;
	char d;
	system("color F0");
	cout << "   Here we have acedemic and personal data of student....." << endl;
	cout << "...enter 1 for to view acedemic data of student...." << endl << "...enter 2 for to view personal data of student..." << endl;
	cin >> x;
	do
	{

		if (x == 1)           //enter 1 
		{
			cout << "Name" << "  \tsubject" << "\t" << "qulification" << "\t" << "salary" << "\t" << "        id" << endl << endl;
			for (int i = 0; i<v.size(); i++)
			{
				strm << v[i].getname() << "  \t  " << v[i].subject << " \t " << v[i].qualification << " \t " << v[i].getsalary() << "            \t " << v[i].getid() << endl;
			}
		}
		else if (x == 2)     //enter 2
		{
			cout << "...Name.." << "\t" << "...sex.." << "\t" << "..city..." << "\t" << "..age..." << endl << endl;
			for (int i = 0; i<v.size(); i++)
			{
				strm << "    " << v[i].getname() << "  \t" << v[i].getsex() << "     \t " << v[i].getcity() << "     \t " << v[i].getage() << endl;
			}
		}
		cout << "again you want to see press y/n" << endl;
		cin >> d;
		cout << "press enter to continue....";
		getchar();
		system("cls");
		if (d == 'y')    //enter value char y 
		{
			cout << "...enter 1 for to view acedemic data of student...." << endl << "...enter 2 for to view personal data of student..." << endl;
			cin >> x;
		}
		else
			x = -1;    //to end the loop
	} while (x == 1 || x == 2);

	cout << "...........thank you for display the list of student ....." << endl;
	return strm;
}
void edititem(vector<professor>& v)
{
	system("cls");
	system("color 74");
	SetConsoleTextAttribute(GetStdHandle, 0x132);
	int x;
	unsigned int ID;
	cout << "    ..Enter the ID of teacher ........";
	cin >> ID;
	for (int i = 0; i<v.size(); i++)
	{
		if (v[i].id == ID)   //if ID id the valid
		{
			cout << "Name.." << v[i].getname() << endl << "sex.." << v[i].getsex() << endl
				<< "age .." << v[i].getage() << endl << "city  " << v[i].getcity() << endl << "subject is.." << v[i].subject << endl <<
				"department  " << v[i].qualification << endl << "id.." << v[i].id << "salary is.." << v[i].salary;
			cout << "you can change   salary ,subjects, of the teacher..." << endl;
			cout << "enter 1 change salary ...." << endl << "enter 2 subjects of...." << endl;
			cin >> x;
			if (x == 1)    //enter 1 for x
			{
				cout << "enter new new gpa of ..." << v[i].getname() << "     ";
				cin >> v[i].salary;      //get the new salary
			}
			else
			{
				cout << "enter new new section of ..." << v[i].getname() << "     ";
				cin >> v[i].subject;     //get the new subject
			}
			readprofessor(v);          //call to readprofessor functin

		}
	}
	cout << "thank you for editing teacher data......." << endl << endl << endl;
	cout << "press enter..............";
	getchar();
}

void viewparticular(vector<professor> v)
{
	system("cls");
	system("color 74");
	SetConsoleTextAttribute(GetStdHandle, 0x132);
	unsigned int ID;
	cout << "   Enter the ID of Teacher    ...." << endl;
	cin >> ID;
	for (int i = 0; i<v.size(); i++)
	{
		if (v[i].id == ID)      //if this ID is valid one
		{
			cout << "Name    : " << v[i].getname() << endl << "sex     : " << v[i].getsex() << endl
				<< "age     : " << v[i].getage() << endl << "city    : " << v[i].getcity() << endl << "Qualification: " << v[i].qualification << endl <<
				"subject :" << v[i].subject << endl << "ID      : " << v[i].id << endl << "Salary  : " << v[i].salary;
		}
		
	}
	cout << "press enter";
	getchar();
}
void additem(vector<professor> &v)
{
	professor s;            //temp object of professor class 
	static int ID = 108;
	ID++;
	string n, se, c;
	int a;
	system("cls");
	system("color 74");
	SetConsoleTextAttribute(GetStdHandle, 0x132);
	cout << "Enter data of new student" << endl;
	cout << "name\tsex\tcity\tage,subject,qualification,id,salary, of the new student....." << endl;
	cout << "Name..";
	cin >> n;
	cout << "age   .";
	cin >> a;
	cout << "sex ...";
	cin >> se;
	cout << "city..";
	cin >> c;
	cout << "subject...";
	cin >> s.subject;
	cout << "qualification...";
	cin >> s.qualification;
	s.id = ID;
	cout << "salary...";
	cin >> s.salary;
	s.person::setter(n, se, c, a);        //it passess to the setter function of person class
	v.push_back(s);       // it pushes the object to the list of teachers
	readprofessor(v);             //call to the read professor function
	cout << "thank you for inserting new professor in school..." << endl;
	cout << "press enter for another inqury .......";
	Sleep(6000);
	system("cls");
}
class staff :public Employee          //public inheritence
{
protected:
	string qualification;
	int rank;                         //attributes of the staff class
	string type;
public:
	staff()
	{                           //default constrctor
		qualification = "";
		rank = 0;
		type = "";
	}
	staff(string q, int r, string ty, int Id, unsigned int s, string n, string se, string c, int x)
		:Employee(Id, s, n, se, c, x)
	{
		qualification = q;    //parametrize constructor         
		rank = r;
		type = ty;
	}
	void setter(string q, int r, string ty, int Id, unsigned int s, string n, string se, string c, int x)
	{
		Employee::setter(Id, s, n, se, c, x);
		qualification = q;                 //it calls to the setter fnction of person class
		rank = r;
		type = ty;
	}
	string getqualification()
	{
		return qualification;        //it return the qualification
	}
	string getype()
	{
		return type;            //it return the type 
	}
	int getrank()
	{
		return rank;              //it return the rank
	}
	friend void show(vector<staff>);                //it show the staff
	friend void menu(vector<staff>);       //it calls to the menu function
										   //	void connectstudent(vector<student> &);       //connectstudent through staff
										   //	void connectprofessor(vector<professor> &);   //connectprofessor through staff
	friend void readstaff(vector<staff> &);
};


void show(vector<staff> v)
{
	int x;
	char d;
	cout << "   Here we have acedemic and personal data of staff....." << endl;
	cout << "...enter 1 for to view acedemic data of staff...." << endl << "...enter 2 for to view personal data of staff..." << endl;
	cin >> x;
	do
	{

		if (x == 1)
		{
			cout << "Name.." << "           \tId" << "    \tsalary" << "   \tqualification" << "\t rank" << "\ttype" << endl;
			for (int i = 0; i<v.size(); i++)
			{
				cout << v[i].getname() << "      \t" << v[i].getid() << "     \t  " << v[i].getsalary() << "      \t" <<
					v[i].qualification << "   \t" << v[i].rank << "       \t " << v[i].type << endl;
			}
		}

		else if (x == 2)
		{
			cout << "...Name.." << "\t" << "...sex.." << "\t" << "..city..." << "\t" << "..age..." << endl << endl;
			for (int i = 0; i<v.size(); i++)
			{
				cout << "    " << v[i].getname() << "  \t" << v[i].getsex() << "     \t " << v[i].getcity() << "     \t " << v[i].getage() << endl;
			}
		}
		cout << "again you want to see press   in exam branch y/n" << endl;
		cin >> d;
		if (d == 'y')
		{
			cout << "...enter 1 for to view acedemic data of staff...." << endl << "...enter 2 for to view personal data of staff..." << endl;
			cin >> x;

		}
		else
			x = -1;
	} while (x == 1 || x == 2);

	cout << "...thank you for display the list of staff ....." << endl;
}

void registeredstudent(vector<student> &v)
{        //registration of the student
	student temp1("Ahsan fahim", "male", "islamabad", 20, 4, 'B', "CS", 1);
	student temp2("Fahad zia", "male", "Islamabad", 20, 4, 'B', "CS", 2);
	student temp3("Zain ul abdin", "male", "larkana ", 21, 3.26, 'B', "CS", 3);
	student temp4("Usama shoukat", "male", "DG khan ", 20, 2.8, 'B', "CS", 4);
	student temp5("Fazeel ", "male", "Khanival ", 20, 3, 'B', "CS", 5);
	student temp6("abdul Muueed", "male", "Lahore", 21, 2.8, 'B', "CS", 6);
	student temp7("Usama khalid", "male", "Karachi", 20, 3.56, 'B', "CS", 7);
	student temp8("Taha mazari", "male", "Lahore ", 21, 3.11, 'B', "CS", 8);
	student temp9("raza abbas", "male", "Lahore", 19, 3.56, 'B', "CS", 9);
	student temp10("Faizan Baig", "male", "Lahore ", 20, 3, 'B', "CS", 10);
	student temp11("Saad sohil ", "male", "   Cant ", 20, 3.56, 'B', "CS", 11);
	student temp12("Ubaid rehman", "male", "Faislabad ", 21, 3.2, 'B', "CS", 12);
	student temp13("Suchal riaz ", "male", "islamabad", 20, 3.58, 'B', "CS", 13);
	student temp14("Awais waheed ", "male", "Lahore", 20, 3.4, 'B', "CS", 14);
	student temp15("Samrah ", "Female", "Sahiwal ", 19, 2.8, 'B', "CS", 15);
	student temp16("Shiza arshad", "Female", "Tobatek singh", 19, 2.8, 'B', "CS", 16);
	student temp17("Shizina", "Female", "Islamabad ", 19, 3, 'B', "CS", 17);
	student temp18("Mishal ajiz", "Female", "Islamabad", 19, 3.1, 'B', "CS", 18);
	student temp19("Nathumalomani", "male", "UmerKot ", 18, 3.44, 'B', "CS", 19);
	v.push_back(temp1); v.push_back(temp2); v.push_back(temp3); v.push_back(temp4); v.push_back(temp5); v.push_back(temp6);
	v.push_back(temp7); v.push_back(temp8); v.push_back(temp9); v.push_back(temp10); v.push_back(temp11); v.push_back(temp12);
	v.push_back(temp13); v.push_back(temp14); v.push_back(temp15); v.push_back(temp16); v.push_back(temp17); v.push_back(temp18); v.push_back(temp19);
}

void registeredprofessor(vector<professor> &v)
{  //registration of the professor
	professor temp1("programming", "Ms", 100, 130000, "Shmyal binmansoor", "male", "Karachi", 38);
	professor temp2("Math", "PhD", 101, 140000, "Quanita Kiran ", "Female", "Islamabad", 43);
	professor temp3("physics ", "PhD ", 102, 120000, "Naila Amir", "Female", "Islamabad", 34);
	professor temp4("programming", "Ms", 103, 130000, "Hirra Anwer", "Female", "Islamabad", 35);
	professor temp5("physics ", "M.phil", 104, 120000, "Sabeen Sher", "Female", "Islamabad", 43);
	professor temp6("Math", "Ms", 105, 140000, " atifa Kanwal", "Female", "Islamabad", 39);
	professor temp7("DLD ", "PhD", 106, 150000, "Arshad Nazir ", "male", "Rawal Pindi", 48);
	professor temp8("IR ", "PhD", 107, 100000, "Bilal Zubair", "male", "Islamabad", 34);
	professor temp9("Managment ", "MBA ", 108, 120000, "Talha Aleem", "male", "Rawalpindi", 38);
	v.push_back(temp1); v.push_back(temp2); v.push_back(temp3); v.push_back(temp4); v.push_back(temp5);
	v.push_back(temp6); v.push_back(temp7); v.push_back(temp8); v.push_back(temp9);
}
void registeredstaff(vector<staff> &v)
{
	//registration og staff members
	staff temp1("BA   ", 11, "clerk   ", 201, 60000, "Tanveer Ahmed", "male", "Islamabad", 32);
	staff temp2("BA   ", 11, "accountant", 202, 50000, "javeed Khan", "male", "Rawalpindi", 34);
	staff temp3("Socilogy", 17, "HoD    ", 203, 120000, "aqib Javed", "male", "Lahore", 41);
	staff temp4("BA   ", 11, "manager  ", 204, 100000, "Ameen Ali", "male", "Islamabad ", 45);
	v.push_back(temp1);	v.push_back(temp2); v.push_back(temp3);	v.push_back(temp4);
}

class Accounts
{
public:
	void getrigisterd();
	int  getfeestudent(vector<student>);                  //get the fee of student
	void showsalaryprofessor(vector<professor>);             //show salary of professor
	void showsalarystaff(vector<staff>);             //show the salary of person
	void setfeestudent(vector<student>&);           //set the fee of student
	void showstudentfee(vector<student>);          //show the fee of end semester fee
};
void Accounts::setfeestudent(vector<student> &v)
{
	double laibraryfee = 600, medicalfee = 600, sport = 600, tution = 78000;
	for (int i = 0; i<v.size(); i++)
	{
		v[i].fee = laibraryfee + medicalfee + sport + tution;         //it charge the fee of to every student
	}
}
void Accounts::showstudentfee(vector<student> v)
{
	student t;
	unsigned int ID;
	double laibraryfee = 600, medicalfee = 600, sport = 600, tution = 78000;        //it show the student fee
	system("cls");
	system("color 74");
	SetConsoleTextAttribute(GetStdHandle, 0x132);
	GoToXY(7, 7);
	cout << "Enter your ID to Check your Account"<<endl;
	cin >> ID;           //enter the ID of student
	for (int i = 0; i<v.size(); i++)
	{
		if (v[i].id == ID)       //if entered ID is vaild or not
		{
			GoToXY(7, 10);
			cout << "Name       : " << v[i].getname() << endl;
			GoToXY(7, 12);
			cout << "Tution Fee : " << tution << endl;
			GoToXY(7, 14);
			cout << "Medical Fee: " << medicalfee << endl;
			GoToXY(7, 16);
			cout << "Library Fee: " << laibraryfee << endl;
			GoToXY(7, 18);
			cout << "Sports Fee : " << sport << endl;
		}
	}
	GoToXY(7, 20);
	cout << "THANK YOU!!" << endl << endl;
}
void Accounts::showsalaryprofessor(vector<professor> v)
{
	unsigned int ID, x;
	char ch;
	int i;
	cout << "Enter your ID to Check your Account"<<endl;
	cin >> ID;                          //enter the valid ID 
	for (i = 0; i<v.size(); i++)
	{
		if (v[i].id == ID)
		{
			cout << "NAME  : " << v[i].getname() << endl;
			cout << "SALARY: " << v[i].getsalary() << endl;
			break;
		}
	}

	cout << "Do you want to change something? y/n" << endl;
	cin >> ch;
	if (ch == 'y')
	{
		cout << "Enter New Salary of " << v[i].getname() << endl;
		cin >> x;
		v[i].setsalary(x);
	}
	else
		cout << "Thank You" << endl;
}
void Accounts::showsalarystaff(vector<staff> v)
{
	unsigned int ID, x;
	char ch;
	int i;
	cout << "....Enter the ID of Staff member......" << endl;
	cin >> ID;
	for (i = 0; i<v.size(); i++)          //Enter the valid ID .............
	{
		if (v[i].getid() == ID)
		{
			cout << ".....the name of staff member is ......" << v[i].getname() << endl;
			cout << ".....salary is......" << v[i].getsalary() << endl;
			break;
		}
	}
	cout << "...Do you want to change then press y/n" << endl;
	cin >> ch;
	if (ch == 'y')
	{
		cout << ".....Enter New Salary of ...." << v[i].getname() << endl;
		cin >> x;
		v[i].setsalary(x);
	}
	else
		cout << "Thank You for Inqury of Accounts of Staff......" << endl;
}
class laibrary
{
	vector<string> s;         // it is the list of book prsent there
public:
	char registerd(vector<student>);          //it checck you are registered or not 
	laibrary()
	{                                //it set the content of laibrary
		s.push_back("1:C++ 4th edition"); s.push_back("2 :C++ 7th edition"); s.push_back("3:Digital Design Morris Mano 4th edition"); s.push_back("4 :Thomas Calculus 9th edition"); s.push_back("5 :Discreate Mathmaticas "); s.push_back(" 6 :Haliday Physics");
		s.push_back("7 : Secular and Nationnalist jinnah"); s.push_back(" 8: calculus 11th edition "); s.push_back(" 9: Democracy in pakistan "); s.push_back("10 :Paradise Lost ");
	}//it set the laibrary 
	void showlaibrary();                      //it show the content of laibrary
	void issuebook(vector<student>);          //it here issue the books
};

char laibrary::registerd(vector<student> v)
{
	unsigned int ID;
	int x = 0;
	system("cls");
	system("color 74");
	SetConsoleTextAttribute(GetStdHandle, 0x132);
	GoToXY(5, 5);
	cout << "Enter the ID of student" << endl;
	cin >> ID;
	for (int i = 0; i<v.size(); i++)
	{
		if (v[i].id == ID)                 //if this is valid ID then you are registered in the laibrary
		{
			GoToXY(5, 7);
			cout << "STUDENT NAME(Registered): " << v[i].getname() << endl;
			GoToXY(5, 9);
			cout << "BOOKS AVAILABLE IN THE LIBRARY";
			x++;
		}
	}
	if (x == 1)
		return 'y';         //if you are registered here already
	else
		return 'n';      //else it return no
}
void laibrary::showlaibrary()
{
	for (int i = 0; i<s.size(); i++)
	{
		cout << endl;
		cout << s[i] << endl;                //it show the content of laibrary
	}
}
void laibrary::issuebook(vector<student> c)
{
	unsigned int ID, x;
	char ch;
	ch = registerd(c);     //it check that you are registered or not
	if (ch == 'y')
	{
		showlaibrary();
		GoToXY(5, 30);
		cout << "WELCOME! Enter ID of book you want to issue" << endl << endl;
		cin >> x;
		cout << "THANK YOU! BOOK" << *(s.begin() + (x - 1)) << " HAS BEEN ISSUED." << endl;
		s.erase(s.begin() + (x - 1));//it remove the book from laibrary content
	}
	else
	{
		GoToXY(5, 13);
		cout << "SORRY! YOU ARE NOT REGISTERED";
	}
}
void studentrights(vector<student> s)
{
	int x;
	char ch;
	laibrary temp;
	Accounts Ac;
	system("cls");
	system("color 74");
	SetConsoleTextAttribute(GetStdHandle, 0x132);
	GoToXY(20, 2);
	cout << " YOU ARE lOGGED IN AS STUDENT" << endl << endl;
	GoToXY(10, 8);
	cout << "Enter Choice" << endl;
	
	GoToXY(6, 10);
	cout << "   1. View Your Information  " << endl;
	GoToXY(6, 12);
	cout << "   2. Issue The Book from Laibrary  " << endl << endl;
	GoToXY(6, 14);
	cout << "   3. Account Inqury About Semester Fee   " << endl;
	GoToXY(6, 16);
	do {
		cin >> x;
		if (!(x >= 1 && x <= 3))
		{
			cout << "Enter Valid Choice" << endl;
		}
	} while (!(x >= 1 && x <= 3));
	do
	{
		switch (x)
		{
		case 1:
		{ viewparticularstudent(s); break; }       //it view the particular student information
		case 2:
		{ temp.issuebook(s); break; }        //it issue the book here
		case 3:
		{Ac.setfeestudent(s); Ac.showstudentfee(s); break; }        //it show the student fee here
		default:
			;
		}
		cout << "  Enter y for previous menu " << endl;
		cout << " Enter n for main menu" << endl;
		cin >> ch;
		if (ch == 'y')
		{
			system("cls");
			system("color 74");
			SetConsoleTextAttribute(GetStdHandle, 0x132);
			GoToXY(10, 10);
			cout << "ENTER CHOICE" << endl;
			GoToXY(5, 12);
			cout << "1. View Your Information    " << endl << endl;
			GoToXY(5, 14);
			cout << "2. Issue The Book from Laibrary  " << endl << endl;
			GoToXY(5, 16);
			cout << "3. Account Inqury About Semester Fee " << endl << endl;
			GoToXY(5, 18);
			cout << "4. EXIT" << endl;
			cin >> x;
		}
		else
			x = -1;
	} while (x >= 1 && x <= 4);
}
void teacherrights(vector<professor> p, vector<student> s)
{
	int x;
	char ch;
	Accounts Ac;
	system("cls");
	system("color 74");
	SetConsoleTextAttribute(GetStdHandle, 0x132);
	GoToXY(25, 2);
	cout << "Enter Choice";
	GoToXY(20, 3);
	cout << " YOU ARE lOGIN AS PROFESSOR" << endl << endl;
	cout << "    1 : view own information     " << endl << endl;
	cout << "    2 : view particular student  " << endl << endl;
	cout << "    3 : view all the students    " << endl << endl;
	cout << "    4 : view your account inqury   " << endl << endl;
	cin >> x;
	do
	{
		switch (x)
		{
		case 1: {viewparticular(p); break; }  //it view the particular  teacher 
		case 2: {viewparticularstudent(s); break; }   //it view the particular student
		case 3: {cout << s; break; }          //it dispaly the student list
		case 4: {Ac.showsalaryprofessor(p); break; }        //salary of the professor 
		default:
			cout << "it is not the vaild one ";
		}
		
		cout << " PRESS    y for previos menu and n for main menu" << endl;
		cin >> ch;
		if (ch == 'y')       //you want to continue furthur 
		{
			system("cls");
			system("color 74");
			SetConsoleTextAttribute(GetStdHandle, 0x132);
			GoToXY(7, 7);
			cout << "Enter choice" << endl;
			cout << "    1 : view own information     " << endl << endl;
			cout << "    2 : view particular student  " << endl << endl;
			cout << "    3 : view all the students    " << endl << endl;
			cout << "    4 : view your account inqury   " << endl << endl;
			cout << "    5 : exit from here              " << endl << endl;
			
			cin >> x;
		}
		else
			x = -1;        //else end loop here
	} while (x >= 1 && x <= 5);
}
void exammember(vector<staff> ex, vector<professor> p, vector<student> s)
{
	int x, y;
	char ch;
	Accounts Ac;
	system("cls");
	system("color 74");
	SetConsoleTextAttribute(GetStdHandle, 0x132);
	GoToXY(20, 2);
	cout << "ENTER CHOICE" << endl;
	cout << " YOU ARE lOGGED IN AS EXAM BRANCH MEMBER" << endl << endl;
	cout << "    1: view particular information     " << endl << endl;
	cout << "    2: display information " << endl << endl;
	cout << "    3:  edit the information " << endl << endl;
	cout << "    4:  add the new one     " << endl << endl;
	cout << "    5:  delete the part     " << endl << endl;
	cout << "    6:  view own accounts information  " << endl << endl;

	cin >> x;
	do
	{
		switch (x)
		{
		case 1:
		{
			cout << " ENTER YOUR CHOICE"<<endl;
			cout << "  1  : view own information   " << endl;
			cout << "  2  : view professor information " << endl;
			cout << "  3  : view  student information   " << endl;
			
			cin >> y;
			do
			{
				switch (y)           //another switch case			
				{
				case 1:
				{ show(ex); break; }   //it show exam branch itself
				case 2: {viewparticular(p); break; }      //view particular 
				case 3: {viewparticularstudent(s); break; }       //it view particular student
				default:
					cout << "this is not valid one ...." << endl;
				}
				cout << " you want to view particular information it again y/n " << endl << endl;
				cin >> ch;                //enter the charactor 
				if (ch == 'y')
				{
					cout << "  1 :view own information   " << endl;
					cout << "  2  : view professor information " << endl;
					cout << "  3  : view  student information   " << endl;
					cout << "   4 :to exit from here             " << endl;
					cout << "  Enter the value of y from above list ...";
					cin >> y;
				}
				else                 //else end the loop here
					y = -1;
			} while (y >= 1 && y <= 3);
			break;
		}

		case 2:
		{
			cout << " 1 :display the information of students  " << endl;
			cout << " 2 :display the information of professor  " << endl;
			cout << " enter value of y   ";
			cin >> y;
			do
			{
				switch (y)
				{
				case 1: {cout << s; break; }      //it display the list of student
				case 2: {cout << p; break; }      //it display the list of professor
				default:cout << "this is not valid one ...." << endl;
				}
				cout << " you want display the list thto view it again y/n " << endl << endl;
				cin >> ch;
				if (ch == 'y')       //enter validity
				{
					cout << " 1 :display the information of students  " << endl;
					cout << " 2 :display the information of professor  " << endl;
					cout << "   3 : for Exit                           " << endl;
					cout << "  Enter the value of y from above list ...";
					cin >> y;
				}
				else
					y = -1;     //else end the loop here
			} while (y >= 1 && y <= 2);
			break;
		}
		case 3:
		{
			cout << " 1:edit the information of student   " << endl;
			cout << " 2:edit the information of professor  " << endl;
			cout << " enter value of y   ";
			cin >> y;
			do
			{
				switch (y)
				{
				case 1: {editstudent(s); break; }          //edit the student to list
				case 2: {edititem(p); break; }          //edit  teacher
				case 3: { y = 4; break; }
				default:cout << "this is not valid one ...." << endl;
				}
				cout << " you want to Edit  it again y/n " << endl << endl;
				cin >> ch;
				if (ch == 'y')
				{
					cout << " 1:edit the information of student   " << endl;
					cout << " 2:edit the information of professor  " << endl;
					cout << " 3 : for to Exit                      " << endl;
					cout << "  Enter the value of y from above list ...";
					cin >> y;
				}
				else
					y = -1;    //end the loop here
			} while (y >= 1 && y <= 2);
			break;
		}
		case 4:
		{
			cout << " 1 :Add new student to the list       " << endl;
			cout << " 2 :Add new professor to the list      " << endl;
			cout << " enter value of y   ";
			cin >> y;
			do
			{
				switch (y)
				{
				case 1: {addstudent(s); break; }    //add new student to the school
				case 2: {additem(p); break; }   //add new teacher to the school 
				default:cout << "this is not valid one ...." << endl;
				}
				cout << " you want add new one again y/n " << endl << endl;
				cin >> ch;
				if (ch == 'y')
				{
					cout << " 1 :Add new student to the list       " << endl;
					cout << " 2 :Add new professor to the list      " << endl;
					cout << "  3 : for to Exit                     " << endl;
					cout << "  Enter the value of y from above list ...";
					cin >> y;
				}
				else
					y = -1;       //end the loop here
			} while (y >= 1 && y <= 2);
			break;
		}
		case 5:
		{
			cout << "    1: for delete student      :" << endl;
			cout << "    2: for delete professor    :" << endl;
			cout << " Enter the value of Y ........";
			cin >> y;
			do
			{
				switch (y)
				{
				case 1: {deleteSTUDENT(s); break; }   //delete an student from the list 
				case 2: {deleteitem(p); break; }      //delete an professor 
				default:
					cout << " this is the invaild number      " << endl << endl;
				}
				cout << " again do you want to delete st,pro   y/n  ";
				cin >> ch;
				if (ch == 'y')
				{
					cout << "    1: for delete student      :" << endl;
					cout << "    2: for delete professor    :" << endl;
					cout << "    3: for Exit                :" << endl;
					cout << "   Enter the value of Y ........";
					cin >> y;
				}
				else
					y = -1;
			} while (y >= 1 && y <= 2);
			break;
		}
		case 6:
		{
			Ac.showsalarystaff(ex);    //show the salary of staff
			break;
		}
		default:
			cout << " there is no valid one ........." << endl;
		}
		cout << " Still you want inqury As Staff  y/n " << endl << endl;
		cin >> ch;
		if (ch == 'y')
		{
			system("color F0");
			system("cls");
			cout << "    1: view particular information     " << endl << endl;
			cout << "    2: display information " << endl << endl;
			cout << "    3:  edit the information " << endl << endl;
			cout << "    4:  add the new one     " << endl << endl;
			cout << "    5:  delete the part     " << endl << endl;
			cout << "    6:  view own accounts information  " << endl << endl;
			cout << "   7: to Exit From here            " << endl;
			cout << "  Enter the value of x from above list for inqury furthur ...";
			cin >> x;
		}
		else
			x = -1;  //end loop here 
	} while (x >= 1 && x <= 6);
}
void menu(vector<student> s, vector<professor> p, vector<staff> st)
{
	int x;
	char ch;
	system("cls");
	system("color 74");
	SetConsoleTextAttribute(GetStdHandle, 0x132);
	GoToXY(33, 5);
	cout << "# WELCOME #" << endl;
	GoToXY(10, 10);
	cout << "ENTER CHOICE" << endl;
	GoToXY(5, 12);
	cout << "1. As a Student    " << endl << endl;
	GoToXY(5, 14);
	cout << "2. As a Teacher  " << endl << endl;
	GoToXY(5, 16);
	cout << "3. As an EXAM BRANCH MEMBER " << endl << endl;
	do {
		GoToXY(10, 22);
		cin >> x;
		if (!(x >= 1 && x <= 3))
		{
			GoToXY(10, 20);
			cout << "ENTER VALID CHOICE" << endl;
		}
	} while (!(x >= 1 && x <= 3));
	do
	{
		switch (x)
		{
		case 1:
		{
			studentrights(s); break;   //goes in the student function
		}
		case 2:
		{
			system("cls");
			teacherrights(p, s); break;      //goes in the teacher function
		}
		case 3:
		{   system("cls");
		exammember(st, p, s); break; //goes in the staff function
		}
		default:
			x = -1;
			GoToXY(7, 20);
			cout << "ENTER VALID CHOICE  " << endl;
		}

			system("cls");
			system("color 74");
			SetConsoleTextAttribute(GetStdHandle, 0x132);
			GoToXY(10, 10);
			cout << "ENTER CHOICE" << endl;
			GoToXY(5, 12);
			cout << "1. As a Student    " << endl << endl;
			GoToXY(5, 14);
			cout << "2. As a Teacher  " << endl << endl;
			GoToXY(5, 16);
			cout << "3. As an EXAM BRANCH MEMBER " << endl << endl;
			GoToXY(5, 18);
			cout << "4. exit";
			cin >> x;
			
		
	} while (x >= 1 && x < 4);
}
void read(vector<student> &v)
{
	ofstream of;
	of.open("student.txt", ios::out);
	of << "  Name " << "\n" << "City\nSex\nage\nDepartment\nsection\nid\ngpa\nfee" << endl;
	for (int i = 0; i<v.size(); i++)
	{
		of << v[i].getname() << "\n";
		of << v[i].getcity() << "\n";
		of << v[i].getsex() << "\n";
		of << v[i].getage() << "\n";
		of << v[i].department << "\n";
		of << v[i].section << "\n";
		of << v[i].id << "\n";
		of << v[i].gpa << "\n";
	}
	of.close();
}
void readprofessor(vector<professor> &v)
{
	ofstream of;
	of.open("professor.txt", ios::out);
	of << "  Name " << "\n" << "City\nSex\nage\nDepartment\nQualification\nsalary\subject\nid" << endl;
	for (int i = 0; i<v.size(); i++)
	{
		of << v[i].getname() << "\n";
		of << v[i].getcity() << "\n";
		of << v[i].getsex() << "\n";
		of << v[i].getage() << "\n";
		of << v[i].getqualification() << "\n";
		of << v[i].getsalary() << "\n";
		of << v[i].getsubject() << "\n";
		of << v[i].getid() << "\n";
	}
	of.close();
}
void readstaff(vector<staff> &v)
{
	ofstream of;
	of.open("staff.txt", ios::out);
	of << "  Name " << "\n" << "City\nSex\nage\nDepartment\nQAULIFICATION\nRANK\nTYPE\nID" << endl;
	for (int i = 0; i<v.size(); i++)
	{
		of << v[i].getname() << "\n";
		of << v[i].getcity() << "\n";
		of << v[i].getsex() << "\n";
		of << v[i].getage() << "\n";
		of << v[i].getqualification() << "\n";
		of << v[i].getrank() << "\n";
		of << v[i].getype() << "\n";
		of << v[i].getid() << "\n";
	}
	of.close();
}
int main()
{
	vector<student> cs;
	vector<professor> pro;
	vector<staff> stf;
	laibrary lib;
	registeredstudent(cs);
	registeredprofessor(pro);
	registeredstaff(stf);
	Accounts Ac;
	read(cs);
	readprofessor(pro);
	readstaff(stf);
	Welcome();
	system("cls");
	Login();
	system("color F0");
	menu(cs, pro, stf);
	return 0;
}
