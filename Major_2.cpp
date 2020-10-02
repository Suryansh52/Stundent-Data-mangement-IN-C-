#include<bits/stdc++.h>						//Includes all Standard C++ Headers
#ifdef unix									//If Compilation Environment is UNIX
#include <math.h>
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <stdlib.h>
#include <unistd.h>							//For usleep() function
#define delay(x) usleep(x*1000)				//For Windows delay function
#define CLS() cout<<"\033[2J\033[1;1H"		//ANSI Escape sequence for clearing screen
int login();
void gotoxy(int x,int y){					//gotoxy function for UNIX
 	printf("%c[%d;%df",0x1B,y,x);			//ANSI Escape Seqeuence  for gotoxy
 } 
#endif
#ifndef unix								//If Compilation Environment is not UNIX
#define CLS() system("cls")					//Windows clearscreen function
#include<windows.h>
void gotoxy(int x,int y){					//gotoxy for Windows - it isn't my code
	y--;
	static HANDLE h=NULL;
	if(!h){
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	}
	COORD c = {x,y};
	SetConsoleCursorPosition(h,c);
}
void delay(unsigned int secs){				//Defining delay function for Windows
	clock_t goal = secs +  clock();			//Using clock to set time to delay till
	while(goal>clock());					//Waiting till that time
}

#endif						
#define FLBSTUD "student.txt"				//Macros for storing filenames for ease
#define FLBCLAS "class.txt"					//The files are binary files
#define RULE(x) cout<<'\n'; for(int _=0;_<80;_++) cout<<x; cout<<'\n' //Outputs Horizontal Consisting of 'x's
#define CL(cl,x) cl==0?1:cl==x				//Macro for disabling search through class
using namespace std;
int strcmpi(const char * s1, const char* s2){			//String compare without case
	return strcasecmp(s1,s2);
}
bool strcmpis(pair <string, int> s1, pair <string,int> s2){ //Compare function for sort()
	return (strcasecmp(s1.first.c_str(),s2.first.c_str()))<0;
}
void load(){								//Loader function [c-p cp]
	CLS();
	cout<<"\n\n\n\n\t\t\t\t  Loading\n\n";
	for (int i=0;i<60;i++){
		cout<<"!";
		gotoxy(i,3);						//Top Loading line
		cout<<"!";
		cout.flush();						//Flush output buffer for delay()
		gotoxy(i+1,7);						//Bottom Loading line
		delay((rand()%60) + 5 );
	}
	cout.flush();
	delay(200);
}
void logscreen()
{
  char username[30];
  char password[30];
  int tr = 0;
  int tru = 1;
  do
  {
    system("cls");
    system("color E0");
    cout<<"\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t";
    cout<<"===========Welcome===========";
    cout<<"\n\n";
    cout<<"\t\t\t\t";
    cout<<"Student Data Managemet System";
    cout<<"\n\n";
    cout<<"\t\t\t\t";
    cout<<"=========Login page=========";
    cout<<"\n\n";
    cout<<"\t\t\t";
    cout<<"Username: ";
    cin>>username;
    cout<<"\t\t\t";
    cout<<"\n";
    cout<<"\t\t\t";
    cout<<"Password: ";
    cin>>password;
    if((strcmp(username,"Suryansh")==0 && strcmp(password,"1234")==0)||(strcmp(username,"Vishesh")==0 && strcmp(password,"4321")==0))
      {
        cout<<"\n\n";
        cout<<"\t\t\t\t";
        cout<<"You are accessed to the system!\n\n";
        cout<<"\t\t\t\t   Press Enter to continue...";
        fflush(stdin);
        getchar();
        system("cls");
        //getchar();
		tru =0;
      }
      else
      {
        system("cls");
        tr = tr+1;
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout<<"\t\t\t\t\t";
        cout<<"No. of attempts remain:"<<3-tr;
        fflush(stdin);
        getchar();
        if(tr>=3)
        {

          cout<<"\t\t\t\t\t\t";
          cout<<"\n";
          cout<<"\t\t\t\t";
          cout<<"   No permission to enter the system!" ;
          getchar();
          exit(1);
        } 
       }
    } while(tru==1);
 }
int scan(){							//Scan function for input of only non-negative integers
	string ch;						
	int i,v;
	do{
		v=1;
		cin>>ch;
		for(i=0;i<ch.size();i++){	//Checking each character is digit
			if(!isdigit(ch[i])){
				v=0;
				break;
			}
		}	
	}while(!v);
	return atoi(ch.c_str());		//Coverting string back to integer
}
char bGs[8][4] = {"A+","B+", "AB+", "O+", "A-", "B-", "AB-", "O-"}; 
int fee[12] = {					
1000,
1000,
1000,
1000,
1000,
1000,
1000,
1000,
1000,
1000,
1000,
1000
};
char * strTitle(int x){				//Coverting Title from Integer to readable text
	static char title[8] = " ";
	if(x==1)
		strcpy(title,"Master");
	else if(x==2)
		strcpy(title,"Mr");
	else
		strcpy(title,"Miss");
	return title;
}

class Student {						
	int title;  
	char studentName[30];
	int rollNo;
	char fatherName[30];
	char motherName[30];
	char address[80];
	char bloodGroup[4];
	public:
	void getDetails(void);			
	void printDetails(void){		
		cout<<"Student Name  : "<<strTitle(title)<<' '<<studentName<<endl;
		cout<<"Roll No.      : "<<rollNo<<endl;
		cout<<"Father's Name : "<<fatherName<<endl;
		cout<<"Mother's Name : "<<motherName<<endl;
		cout<<"Address       : "<<address<<endl;
		cout<<"Blood Group   : "<<bloodGroup<<endl;
	}
	int retRollNo(){				
		return rollNo;
	}
	char * retString(char x){		//Return all strings avaialable from the Student Class
		if(x=='T')
			return strTitle(title);
		if(x=='N')
			return studentName;
		if(x=='F')
			return fatherName;
		if(x=='M')
			return motherName;
		if(x=='A')
			return address;
		if(x=='B')
			return bloodGroup;
	}
	char * retStudentName(){		
		return retString('N');
	}
	void modDetail(char ch);		
};

void Student::getDetails(){			
system("CLS");
	cout<<"Enter Title \n(Master = 1, Mr = 2, Miss = 3)  : ";
	do{
		title = scan();
	}while(title!=1 && title!=2 && title!=3);
	cout<<"Enter Student Name    : ";
	do{
		gets(studentName);
	}while(strlen(studentName)==0);
	cout<<"Enter Roll No.        : ";
	do{
		rollNo=scan();
	}while(rollNo<1);
	cout<<"Enter Father Name     : ";
	do{
		
		gets(fatherName);
	}while(strlen(fatherName)==0);
	cout<<"Enter Mother Name     : ";
	do{
		gets(motherName);
	}while(strlen(motherName)==0);
	cout<<"Enter Address         : ";
	do{
		gets(address);
	}while(strlen(address)==0);
	cout<<"Enter Blood Group  [ A+, B+, AB+, O+, A-, B-, AB-, O-]  : ";
	int v = 0,i;
	do{
		gets(bloodGroup);
		for (i=0;i<strlen(bloodGroup);i++) bloodGroup[i] = toupper(bloodGroup[i]);
		for(i=0;i<8;i++)
			if(!strcmp(bloodGroup,bGs[i])){
				v=1;
				break;
			}
	}while(!v);
}
void Student::modDetail(char ch){	
system("CLS");
	if(ch=='T'){					
		cout<<"Enter Title \n(Master = 1, Mr = 2, Miss = 3)  : ";
		do{
			title=scan();
		}while(title!=1 && title!=2 && title!=3);
	}
	else if(ch=='N'){
		cout<<"Enter Student Name    : ";
		do{
			gets(studentName);
		}while(strlen(studentName)==0);	
	}
	else if(ch=='R'){
		int r=rollNo;					//Save current Roll No.
		cout<<"Enter Roll No.        : ";
		fstream fl(FLBSTUD,ios::in|ios::binary);
		Student obj;
		do{
			rollNo = scan();
			fl.close();
			fl.open(FLBSTUD,ios::in|ios::binary);
			while(!fl.eof()){
				fl.read((char*)&obj, sizeof(obj));
				if(fl.eof())
					break;
				if(obj.retRollNo()==rollNo && r!=rollNo){	//Check if the new rollNo already exists
					cout<<"\nSame Roll No. Already Exists !\n";
					cout<<"Enter Roll No.        : ";
					rollNo = -1;
				}
			}
		}while(rollNo<1);
		fl.close();
	}
	else if(ch=='F'){
		cout<<"Enter Father Name     : ";
		do{
			gets(fatherName);
		}while(strlen(fatherName)==0);
	}
	else if(ch=='M'){
		cout<<"Enter Mother Name     : ";
		do{
			gets(motherName);
		}while(strlen(motherName)==0);	
	}
	else if(ch=='A'){
		cout<<"Enter Address         : ";
		do{
			gets(address);
		}while(strlen(address)==0);
	}
	else {
		cout<<"Enter Blood Group     : ";
		int v = 0,i;
		do{
			gets(bloodGroup);					//Loop for checking valid Blood Groups
			for (i=0;i<strlen(bloodGroup);i++) bloodGroup[i] = toupper(bloodGroup[i]);
			for(i=0;i<8;i++)
				if(!strcmp(bloodGroup,bGs[i])){
					v=1;
					break;
				}
		}while(!v);
	}
}

class Class {						
	char class_standard[30];
	char studentName[30];
	int rollNo;
	int Sem;
	public:
	void getDetails();				
	void printDetails(int i=1){		
	
		cout<<"Student Name   : "<<studentName<<endl;
		if(i)
			cout<<"Branch : "<<class_standard<<endl;
		cout<<"Roll No.       : "<<rollNo<<endl;
		cout<<"Sem        : "<<Sem<<endl;
	}
	int retClass(){					
		return Sem;
	}
	int retRollNo(){				
		return rollNo;
	}
	char * retString(char x){		//Return all strings avaialable from the Class class
		if(x=='N')
			return studentName;
		if(x=='C')
		return class_standard;
	}
	char * retStudentName(){	
		return retString('N');
	}
	char * retClass_standard(){
		return retString('C');
	}
	void modDetail(char ch);
};
void Class::getDetails(){		
system("CLS");
	cout<<"Enter Branch : ";
	do{
		gets(class_standard);
	}while(strlen(class_standard)==0);
	cout<<"Enter Student Name   : ";
	do{
		gets(studentName);
	}while(strlen(studentName)==0);
	cout<<"Enter Roll No.       : ";
	do{
		rollNo = scan();
	}while(rollNo<1);
	cout<<"Enter Sem        : ";
	do{
		Sem = scan();
	}while(Sem<1);
}
void Class::modDetail(char ch){		
system("CLS");
	if(ch=='C'){
		cout<<"Branch            : ";
		do{
			gets(class_standard);
		}while(strlen(class_standard)==0);
	}
	else if(ch=='N'){
		cout<<"Enter Student Name              : ";
		do{
			gets(studentName);
		}while(strlen(studentName)==0);	
	}
	else if(ch=='R'){
		fstream fl(FLBCLAS,ios::in|ios::binary);
		Class obj;
		int r = rollNo;				//Save Current Roll No.
		cout<<"Enter Roll No.                  : ";
		do{
			rollNo = scan();
			fl.close();
			fl.open(FLBCLAS,ios::in|ios::binary);
			while(!fl.eof()){
				fl.read((char*)&obj, sizeof(obj));
				if(fl.eof())
					break;				//Check if new Roll No. Already Exists
				if(obj.retRollNo()==rollNo && r!=rollNo){
					cout<<"\nSame Roll No. Already Exists !\n";
					cout<<"Enter Roll No.        : ";
					rollNo=-1;
				}
			}
		}while(rollNo<1);
		fl.close();
	}
	else {
		cout<<"Sem                         : ";
		int v = 0,i;
		do{
			Sem = scan();
		}while(Sem>1);
	}
}

void insertStudent(){			
system("CLS");
	Student obj,obj2;
	char ch;
	int v=0;
	cout<<"Enter Details for new Student :\n";
	obj.getDetails();
	fstream fl1(FLBSTUD, ios::in|ios::binary);
	ofstream fl2;
	if(!fl1){					//If file does not exist, create new file
		fl2.open(FLBSTUD,ios::out|ios::binary);
		fl2.write((char*)&obj, sizeof(obj));
		fl2.close();
		cout<<"Record successfully inserted !\n";
		return;
	}
	while(!fl1.eof()){
		fl1.read((char*)&obj2,sizeof(obj));
		if(fl1.eof()){
			break;
		}
		if(obj.retRollNo()==obj2.retRollNo()){		//If record with same Roll No. exists, then abort insertion
			cout<<"Record with same Roll No. with following details already exists : \n";
			obj2.printDetails();
			cout<<"Insertion Aborted !\n";
			return;
		}
		else if(strcmpi(obj.retStudentName(),obj2.retStudentName())==0){
			if (!v)							//Warns user that Record with same name exists
				cout<<"Warning : Record with same name exists with follwing details : \n";
			obj2.printDetails();
			cout<<'\n';
			v=1;
		}
	}
	if(v){
		cout<<"Do you still wish to insert record (Y/N) ? ";
		do{									
			cin>>ch;
			ch = toupper(ch);
		}while(ch!= 'Y' && ch!='N');
		if(ch=='N'){
			cout<<"Insertion Aborted !\n";
			return;
		}
	}
	fl2.open(FLBSTUD,ios::out|ios::app|ios::binary);
	fl2.seekp(0,ios::end);
	fl2.write((char*)&obj, sizeof(obj));
	fl2.close();
	cout<<"Record Inserted successfully !\n";
}
void insertClass(){							
system("CLS");
	Class obj,obj2;
	char ch;
	int v=0;
	cout<<"Enter Branch Details :\n";
	obj.getDetails();
	fstream fl1(FLBCLAS, ios::in|ios::binary);
	ofstream fl2;
	if(!fl1){								
		fl2.open(FLBCLAS,ios::out|ios::binary);
		fl2.write((char*)&obj, sizeof(obj));
		fl2.close();
		cout<<"Record Inserted successfully !\n";
		return;
	}
	while(!fl1.eof()){
		fl1.read((char*)&obj2,sizeof(obj));
		if(fl1.eof()){
			break;
		}
		if(obj.retRollNo()==obj2.retRollNo()){		//Abort if same Roll No already exists
			cout<<"Record with same Roll No. with following details already exists : \n";
			obj2.printDetails();
			cout<<"Insertion Aborted !\n";
			return;
		}
		else if(strcmpi(obj.retStudentName(),obj2.retStudentName())==0){
			if (!v)									//Warns user if record with same Roll No. Already Exists
				cout<<"Warning : Record with same name exists with follwing details : \n";
			obj2.printDetails();
			cout<<'\n';
			v=1;
		}
	}
	if(v){									//Asks for confirmation after warning
		cout<<"Do you still wish to insert record (Y/N) ? ";
		do{
			cin>>ch;
			ch = toupper(ch);
		}while(ch!= 'Y' && ch!='N');
		if(ch=='N'){
			cout<<"Insertion Aborted !\n";
			return;
		}
	}
	fl2.open(FLBCLAS,ios::out|ios::app|ios::binary);
	fl2.seekp(0,ios::end);
	fl2.write((char*)&obj, sizeof(obj));
	fl2.close();
	cout<<"Record Inserted successfully !\n";
cout<<"";
}

int dispClassRecord(){			

	Class obj;
	int v=0;
	fstream fl(FLBCLAS, ios::in|ios::binary);
	if(!fl){					
		cout<<"Empty Records !\n";
		return 0;
	}
	while(!fl.eof()){
		fl.read((char*)&obj, sizeof(obj));
		if(fl.eof())
			break;
		v=1;
		obj.printDetails();
		RULE('-');
	}
	fl.close();
	if(!v)
		cout<<"Empty Records !\n";
	cout<<"";
	return v;
}
int dispStudentRecord(){		
system("CLS");
	Student obj;
	int v=0;
	fstream fl(FLBSTUD, ios::in|ios::binary);
	if(!fl){					
		cout<<"Empty Records !\n";
		return 0;
	}
	while(!fl.eof()){
		fl.read((char*)&obj, sizeof(obj));
		if(fl.eof())
			break;
		v=1;
		obj.printDetails();
		RULE('-');
	}
	fl.close();
	if(!v)
		cout<<"Empty Records !\n";
	cout<<"";
	return v;
}
int searchClassID(const string str = "search"){		
	fstream fl(FLBCLAS,ios::in|ios::ate|ios::binary);
	if((!fl)||fl.tellg()==0){						
		cout<<"No Records Found !\n";
		return 0;
	}
	fl.close();
	fl.open(FLBCLAS,ios::in|ios::binary);
	cout<<"Enter "<<" (0 for options) : "; //0 to search independent of class
	int cl;
	char ch;
	char query[30];
	Class obj;
	int found = 0;
	do{
		cin>>cl;
	}while(cl>12 || cl<0);
	cout<<"Enter Attribute to search :\n";
	cout<<"  (N)ame of Student.\n";
	cout<<"Enter your choice : ";
	do{
		cin>>ch;
		ch = toupper(ch);
	}while(ch!='N');
	cout<<"Enter Name of student : ";
	do{
		gets(query);
	}while(strlen(query)==0);

	
	while(!fl.eof()){
		fl.read((char*)&obj,sizeof(obj));
		if(fl.eof()){
			break;
		}
		if(CL(cl,obj.retClass())){			//Check class using the defined Macro
			if((strcmpi(query,obj.retString(ch))==0)){
				if(!found)
					cout<<"\nSearch Results : \n\n";
				obj.printDetails();
				RULE('-');
				found = 1;
			}
		}
	}
	if(!found)
		cout<<"No Records Found !\n";
	fl.close();
	return found;
}
int searchStudentID(const string str = "search"){	
system("CLS");
	fstream fl(FLBSTUD,ios::in|ios::ate|ios::binary);
	if((!fl)||fl.tellg()==0){						//If file is empty or zero size
		cout<<" No Records Found !\n";
		return 0;
	} 
	fl.close();
	fl.open(FLBSTUD,ios::in|ios::binary);
	char ch;
	char query[30];
	Student obj;
	int found = 0;
	cout<<"Enter Attribute to "<<str<<" :\n";
	cout<<"  (T)itle.\n";
	cout<<"  (N)ame of Student.\n";
	cout<<"  (F)ather's Name.\n";
	cout<<"  (M)other's Name.\n";
	cout<<"  (A)ddress.\n";
	cout<<"  (B)lood Group.\n";
	cout<<"Enter your choice : ";
	do{
		cin>>ch;
		ch = toupper(ch);
	}while(ch!='T' && ch!='N' && ch!='F' && ch!='M' && ch!='A' && ch!='B');
	cout<<"\nEnter Query : ";
	do{
		gets(query);
	}while(strlen(query)==0);
	while(!fl.eof()){
		fl.read((char*)&obj,sizeof(obj));
		if(fl.eof()){
			break;
		}
		if((strcmpi(query,obj.retString(ch))==0)){
			if(!found)
				cout<<"\nSearch Results : \n\n";
			obj.printDetails();
			RULE('-');
			found = 1;
		}
	}
	if(!found)
		cout<<"No Records Found !\n";
	fl.close();
cout<<"";	
	return found;
}
int searchByRollNo(int i){			//Search Record by Roll No., 1 for Class, 2 for Student
system("CLS");
	int r;
	if(i==1){
		Class obj;
		int found = 0;
		int cl;
		cout<<"Enter Roll No. to search for : ";
		cin>>r;
		fstream fl(FLBCLAS,ios::in|ios::binary);
		if(!fl){							//No file exists
			cout<<"No Records Found !\n";
			return 0;
		}
		while(!fl.eof()){
			fl.read((char*)&obj,sizeof(obj));
			if(fl.eof()){
				break;
			}
			if(CL(cl,obj.retClass())){
				if(r==obj.retRollNo()){				//Match attribute for each Record
					if(!found)
						cout<<"\nSearch Results : \n\n";
					obj.printDetails();
					RULE('-');
					found = 1;
				}
			}
		}
		if(!found)
			cout<<"No Records Found !\n";
		fl.close();
		cout<<"";
		return found;
	}
	else{
		int found=0;
		Student obj;
		cout<<"Enter Roll No. to search for : ";
		cin>>r;
		fstream fl(FLBSTUD,ios::in|ios::binary);
		if(!fl){					//No file exists
			cout<<"No Records Found !\n";
			return 0;
		}
		while(!fl.eof()){
			fl.read((char*)&obj,sizeof(obj));
			if(fl.eof()){
				break;
			}
			if(r==obj.retRollNo()){
				if(!found)
					cout<<"\nSearch Results : \n\n";
				obj.printDetails();
				RULE('-');
				found = 1;
			}
		}
		if(!found)
			cout<<"No Records Found !\n";
		fl.close();
		cout<<"";
		return found;
	}
}

void sortByStudents(char ch){			
	vector <pair<string,int> > lst;		//Make vector of pairs of string to sort by and Roll No.
	int i;
	if(ch=='C'){						//Sort Class Records
		Class obj;
		int v=0;
		fstream fl(FLBCLAS, ios::in|ios::binary);
		if(!fl){
			cout<<"Empty Records !\n";
			return;
		}
		while(!fl.eof()){
			fl.read((char*)&obj, sizeof(obj));
			if(fl.eof())
				break;
			v=1;
			lst.push_back(make_pair(obj.retString('N'),obj.retRollNo())); //Push each pair in the vector
		}
		fl.close();
		if(v==0){
			cout<<"Empty Records !\n";
			return;
		}
		sort(lst.begin(),lst.end(),strcmpis);	//Sort using <algorithm> sort and Custom Comparison 
		fstream tmp("temp.txt",ios::out|ios::binary);
		fl.open(FLBCLAS,ios::in|ios::binary);
		fl.seekg(0,ios::beg);
		for(i=0;i<lst.size();i++){
			fl.close();
			fl.open(FLBCLAS,ios::in|ios::binary);
			while(!fl.eof()){
				fl.read((char*)&obj, sizeof(obj));
				if(fl.eof())
					break;
				if(obj.retRollNo()==lst[i].second){		//Check each Roll No. from each pair and write record to new file
					tmp.write((char*)&obj,sizeof(obj));
				}
			}
		}
		fl.close();
		tmp.close();
		remove(FLBCLAS);
		rename("temp.txt",FLBCLAS);
		cout<<"\nThe Records have been successfully sorted !\n\n";
		dispClassRecord();
	}
	else{					
		Student obj;
		int v=0;
		char c;
		fstream fl(FLBSTUD, ios::in|ios::binary);
		system("CLS");
		cout<<"Enter criteria to sort :\n";
		cout<<"  (N)ame of Student.\n";
		cout<<"  (T)itle.\n";
		cout<<"Enter your choice : \n";		
		do{
			cin>>c;
			c=toupper(c);
		}while(c!='N' && c!='T');
		if(!fl){
			cout<<"Empty Records !\n";
			return;
		}
		while(!fl.eof()){
			fl.read((char*)&obj, sizeof(obj));
			if(fl.eof())
				break;
			v=1;
			lst.push_back(make_pair(obj.retString(c),obj.retRollNo()));	//Push each pair in the vector
		}
		fl.close();
		if(v==0){
			cout<<"Empty Records !\n";
			return;
		}
		sort(lst.begin(),lst.end(),strcmpis);	//Sort using <algorithm> sort and Custom Comparison 
		fstream tmp("temp.txt",ios::out|ios::binary);
		fl.open(FLBSTUD,ios::in|ios::binary);
		fl.seekg(0,ios::beg);
		for(i=0;i<lst.size();i++){
			fl.close();
			fl.open(FLBSTUD,ios::in|ios::binary);
			while(!fl.eof()){
				fl.read((char*)&obj, sizeof(obj));
				if(fl.eof())
					break;
				if(obj.retRollNo()==lst[i].second){		//Check each Roll No. from each pair and write record to new file
					tmp.write((char*)&obj,sizeof(obj));
				}
			}
		}
		fl.close();
		tmp.close();
		remove(FLBSTUD);
		rename("temp.txt",FLBSTUD);
		cout<<"\nThe Records have been successfully sorted !\n\n";
		dispStudentRecord();
	}
}

void delClassRecord(){			
system("CLS");
	Class obj;					
	int f=0;
	if(!searchClassID("delete from"))
		return;
	cout<<"\nEnter Roll No. to delete : ";
	int r;
	char ch;
	cin>>r;
	fstream fl(FLBCLAS, ios::in|ios::binary);
	fstream fo("temp.dat", ios::out|ios::binary);
	while(!fl.eof()){
		fl.read((char*)&obj, sizeof(obj));
		if(fl.eof())
			break;
		if (r==obj.retRollNo()){
			cout<<"Record with following info will be deleted :\n\n";
			obj.printDetails();
			cout<<"Do you wish to continue ? (Y/N) : ";
			do{
				cin>>ch;
				ch = toupper(ch);
			}while(ch!='N' && ch!='Y');
			if(ch=='N'){
				cout<<"Deletion Aborted !\n";
				fl.close();
				fo.close();
				remove("temp.dat");
				return;
			}
			f=1;
			continue;
		}
		fo.write((char*)&obj,sizeof(obj));
	}
	fl.close();
	fo.close();
	remove(FLBCLAS);
	rename("temp.dat",FLBCLAS);
	if(f)
		cout<<"Record Successfully Deleted !\n";
	else
		cout<<"No Such Record Exists !\n";
cout<<"";		
}
void delStudentRecord(){			
system("CLS");
	Student obj;					
	int f=0;
	if(!searchStudentID("delete using"))
		return;
	cout<<"\nEnter Roll No. to delete : ";
	int r;
	char ch;
	cin>>r;
	fstream fl(FLBSTUD, ios::in|ios::binary);
	fstream fo("temp.dat", ios::out|ios::binary);
	while(!fl.eof()){
		fl.read((char*)&obj, sizeof(obj));
		if(fl.eof())
			break;
		if (r==obj.retRollNo()){
			cout<<"Record with following info will be deleted :\n\n";
			obj.printDetails();
			cout<<"Do you wish to continue ? (Y/N) : ";
			do{
				cin>>ch;
				ch = toupper(ch);
			}while(ch!='N' && ch!='Y');
			if(ch=='N'){
				cout<<"Deletion Aborted !\n";
				
				fl.close();
				fo.close();
				remove("temp.dat");
				return;
			}
			f=1;
			continue;
		}
		fo.write((char*)&obj,sizeof(obj));
	}
	fl.close();
	fo.close();
	remove(FLBSTUD);
	rename("temp.dat",FLBSTUD);
	if(f)
		cout<<"Record Successfully Deleted !\n";
	else
		cout<<"No Such Record Exists !\n";
cout<<"";
}

int totalRevenueGenerated(){			//Calculates total fee based on Total=Sum(Fee for Each class  * Total students in that class)
system("CLS");
	int i,found =0;
	Class obj;
	int total = 0;
	fstream fl(FLBCLAS,ios::in|ios::binary);
	if(!fl){
	cout<<" \n\n   Total Fee Revenue Generated  : \t"<<total<<".00"<<'\n';
		return 0;
	}
	while(!fl.eof()){
		fl.read((char*)&obj,sizeof(obj));
		if(fl.eof()){
			break;
		}
		total += ::fee[obj.retClass()-1];
	}
	fl.close();
	cout<<" \n\n   Total Fee Revenue Generated  : \t"<<total<<".00"<<'\n';
	cout<<"";
	return found;
}
void modEntry(char c){				//Modify Record Entry
system("CLS");
	if(c=='C'){
		Class obj;
		if(!searchClassID("search for"))
			return;					//Searches for Records and Modifies using Roll No. based on attribute
		fstream fl(FLBCLAS,ios::in|ios::binary);
		int r,pos;
		char ch;
		int found = 0;
		cout<<"Enter Roll No. of Record to modify : ";
		do{
			cin>>r;
		}while(r<1);
		while(!fl.eof()){
			pos=fl.tellg();
			fl.read((char*)&obj,sizeof(obj));
			if(fl.eof())
				break;
			if(r==obj.retRollNo()){
				cout<<'\n';
				fl.close();
				fl.open(FLBCLAS,ios::out|ios::in|ios::binary);
				while(pos--) fl.get();
				cout<<"Enter Attribute to modify :\n";
				cout<<"  (N)ame of Student.\n";
				cout<<"  (C)lass \n";
				cout<<"  (R)oll No.\n";
				cout<<"Enter your choice : ";
				do{
					cin>>ch;
					ch = toupper(ch);
				}while(ch!='N' && ch!='C' && ch!='R' && ch!='S');
				obj.modDetail(ch);
				obj.printDetails();
				fl.write((char*)&obj,sizeof(obj));
				RULE('-');
				break;
			}
		}
		return;
	}
		Student obj;
		if(!searchStudentID("search for"))
			return;				//Searches for Records and Modifies using Roll No. based on attribute
		fstream fl(FLBSTUD,ios::in|ios::binary);
		int r,pos;
		char ch;
		int found = 0;
		cout<<"Enter Roll No. of Record to modify : ";
		do{
			cin>>r;
		}while(r<1);
		while(!fl.eof()){
			pos=fl.tellg();
			fl.read((char*)&obj,sizeof(obj));
			if(fl.eof())
				break;
			if(r==obj.retRollNo()){
				cout<<'\n';
				fl.close();
				fl.open(FLBSTUD,ios::out|ios::in|ios::binary);
				while(pos--) fl.get();
				cout<<"Enter Attribute to modify :\n";
				cout<<"  (T)itle.\n";
				cout<<"  (N)ame of Student.\n";
				cout<<"  (R)oll No.\n";
				cout<<"  (F)ather's Name.\n";
				cout<<"  (M)other's Name.\n";
				cout<<"  (A)ddress.\n";
				cout<<"  (B)lood Group.\n";
				cout<<"Enter your choice : ";
				do{
					cin>>ch;
					ch = toupper(ch);
				}while(ch!='T' && ch!='N' &&ch!='R' && ch!='F' && ch!='M' && ch!='A' && ch!='B');
				obj.modDetail(ch);
				obj.printDetails();
				fl.write((char*)&obj, sizeof(obj));
				RULE('-');
				break;
			}
		}
}

int main(){
	char ch;
	char ch1;
	int ch2;
	logscreen();
	load();
	system("color B0");
	do{
		CLS();
		RULE("*");
		cout<<"\t\t\t    Student Management System";
		RULE("*");
		cout<<"\t1. Student Database Management.\n";
		cout<<"\t2. Branch Database Management.\n";
		cout<<"\t0. Exit.\n\n";
		cout<<"Enter your choice : ";
		fflush(stdin);
		cin>>ch1;
		if(ch1=='1'){
			fflush(stdin);
			system("color A0");
			load();
			do{
				CLS();
				RULE("*");
				cout<<"\t\t\tStudent Database Management System";
				RULE('-');
				cout<<"\t1.  Insert Records.\n";
				cout<<"\t2.  Display all Records.\n";
				cout<<"\t3.  Search for a Record using Roll No.\n";
				cout<<"\t4.  Search for a Record using other Attributes.\n";
				cout<<"\t5.  Sort all Records.\n";
				cout<<"\t6.  Modify a Record.\n";
				cout<<"\t7.  Delete a Record.\n";
				cout<<"\t0.  Exit.\n";
				cout<<"\nEnter your choice : ";
				ch2 = scan();
				switch(ch2){
					case 1:
						insertStudent();
						cout<<"\nType any key and press Enter...";
						break;
					case 2:
						dispStudentRecord();
						cout<<"\nType any key and press Enter...";
						break;
					case 3:
						searchByRollNo(2);
						cout<<"\nType any key and press Enter...";
						break;
					case 4:
						searchStudentID();
						cout<<"\nType any key and press Enter...";
						break;
					case 5:
						sortByStudents('S');
						cout<<"\nType any key and press Enter...";
						break;
					case 6:
						modEntry('S');
						cout<<"\nType any key and press Enter...";
						break;
					case 7:
						delStudentRecord();
						cout<<"\nType any key and press Enter...";
						break;
						default:
						cout<<"invalid input";
				}
				fflush(stdin);
				if(ch2)
					cin>>ch;
				else
					load();
			}while(ch2!=0);
		}
		if(ch1=='2'){
			fflush(stdin);
			system("color F0");
			load();
			do{
				CLS();
				RULE("*");
				cout<<"\t\t\t     Branch Management System";
				RULE("*");
				cout<<"\t\t\tBranch Database Management System";
				RULE('-');
				cout<<"\t1.  Insert Records.\n";
				cout<<"\t2.  Display all Records.\n";
				cout<<"\t3.  Search for a Record using Roll No.\n";
				cout<<"\t4.  Search for a Record using other Attributes.\n";
				cout<<"\t5.  Sort all Records.\n";
				cout<<"\t6.  Modify a Record.\n";
				cout<<"\t7.  Delete a Record.\n";
				cout<<"\t9.  Display Total Fee Revenue Generated.\n";
				cout<<"\t0.  Exit.\n";
				cout<<"\nEnter your choice : ";
				ch2 = scan();
				switch(ch2){
					case 1:
						insertClass();
						cout<<"\nType any key and press Enter...";
						break;
					case 2:
						dispClassRecord();
						cout<<"\nType any key and press Enter...";
						break;
					case 3:
						searchByRollNo(1);
						cout<<"\nType any key and press Enter...";
						break;
					case 4:
						searchClassID();
						cout<<"\nType any key and press Enter...";
						break;
					case 5:
						sortByStudents('C');
						cout<<"\nType any key and press Enter...";
						break;
					case 6:
						modEntry('C');
						cout<<"\nType any key and press Enter...";
						break;
					case 7:
						delClassRecord();
						cout<<"\nType any key and press Enter...";
						break;
					case 8:
						checkNoInClass();
						cout<<"\nType any key and press Enter...";
						break;
					case 9:
						totalRevenueGenerated();
						cout<<"\nType any key and press Enter...";
						break;
						default:
							cout<<"invalid input";
				}
				fflush(stdin);
				if(ch2)
					cin>>ch;
				else{
					load();
				}
			}while(ch2!=0);
		}
	}while(ch1!='0');
	CLS();
	return 0;
}

