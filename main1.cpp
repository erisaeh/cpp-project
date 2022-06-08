#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;


string encoding(string text){
    string temp = text;
    for(int i = 0;i<temp.length();i++){
        temp[i] = text[i]+4;
    }
    return temp;
}
string decoding(string text){
    string temp = text;
    for(int i = 0;i<temp.length();i++){
        temp[i] = text[i]-4;
    }
    return temp;
}

bool isExists(string search , string fileName){
    string line;
    ifstream inputFile(fileName+".txt");
    while(getline(inputFile , line)){
        if(line == search){
            return true;
        }
    }
    inputFile.close();
    return false;
}


class Person{
    public:
        Person(string a="empty",string b="empty" , string c="empty"){
            fName = a;
            lName = b;
            callNumber = c;
        }
    protected:
        string fName , lName,callNumber;
};


class Student : public Person{
    friend class Morabi;
    friend class Team;
    friend int partition(Student *array, int low, int high);
    public:
        Student(string a="empty" , string b="empty",
        string c="empty" , string d="empty"){
           fName = a;
           lName = b;
           stdNumber = c;
           callNumber = d;
        }
    private:
        string stdNumber;
};

class Team{
    friend class Morabi;
    public:
        Team(string a="empty" , string b="empty" ,string c = "empty" , string d = "Q1"){
            teamName = a;
            morabifName = b;
            morabilName = c;
            sportCode = d;
            if(sportCode == "Q1") size = 11;
            else if(sportCode == "Q2") size = 6;
            else size = 2;
        }
    private:
        void setStudents(){
            students = new Student[size];
            string fName , lName,stdNumber,callNumber;
            
            for(int i = 0;i<size;i++){
                cout << "enter fname:\n";
                cin >> fName;
                cout << "enter lname:\n";
                cin >> lName;
                if(isExists(fName+ " " + lName , "students")){
                    cout << "error!student is already in another team!\n";
                    continue;
                }
                ofstream outputFile,outputFile2;
                outputFile.open("students.txt", std::ios_base::app);
                outputFile << fName << " " << lName << endl;
                outputFile2.open("studentsencode.txt", std::ios_base::app);
                outputFile2 << encoding(fName) << " " << encoding(lName) << endl;
                outputFile.close();
                cout << "enter stdNumber:\n";
                cin >> stdNumber;
                cout << "enter callNumber:\n";
                cin >> callNumber;
                students[i] = Student(fName , lName , 
                stdNumber , callNumber);
            }
        }
        
    
        void swap(Student *a, Student *b){
                Student t = *a;
                *a = *b;
                *b = t;
        }
};