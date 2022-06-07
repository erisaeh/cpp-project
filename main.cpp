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