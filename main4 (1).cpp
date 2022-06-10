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
 int partition(Student *array, int low, int high)
        {

            
            Student pivot = array[high];

            
            int i = (low - 1);
            
            for (int j = low; j < high; j++)
            {
                if (array[j].stdNumber <= pivot.stdNumber)
                {

                                
                    i++;

                    
                    swap(&array[i], &array[j]);
                }
            }

            
            swap(&array[i + 1], &array[high]);

            
            return (i + 1);
        }

        void quickSort(Student *array, int low, int high)
            {
                if (low < high)
                {

                    
                    int pi = partition(array, low, high);

                    
                    quickSort(array, low, pi - 1);

                    
                    quickSort(array, pi + 1, high);
                }
            }
        int binarySearch(Student *arr, int l, int r, string stdNumber)
            {
                if (r >= l) {
                    int mid = l + (r - l) / 2;
        
                    if (arr[mid].stdNumber == stdNumber)
                        return mid;
    
                    if (arr[mid].stdNumber > stdNumber)
                        return binarySearch(arr, l, mid - 1, stdNumber);
            

                    return binarySearch(arr, mid + 1, r, stdNumber);
                }
        
                return -1;
            }
        
        string teamName,
        morabifName,morabilName,
        sportCode;
        int size=0;
        Student *students;
};

class Morabi : public Person{
    public:
        Morabi(string a="empty",string b="empty" , string c="empty"){
            fName = a;
            lName = b;
            callNumber = c;
        }
        void setStudents(Team &a){
            a.setStudents();
        }
        Team createTeam(){
            if(inTeam){
                cout << "error!morabi is alrady in another team!\n";
                return Team();
            }
            string teamName,
            sportCode;
            cout << "enter team name:\n";
            cin >> teamName;
            if(isExists(teamName , "teams")){
                cout << "error!such team is exists!\n";
                return Team();
            }
            ofstream outputFile;
            outputFile.open("teams.txt", std::ios_base::app);
            outputFile << teamName<<endl;
            outputFile.close();
            cout << "sport code:\n";
            cin >> sportCode;
            inTeam = true;
            return Team(teamName , fName,lName , sportCode);
        }
    	void editTeam(Team a){
            int choice,index;
            string stdNumber;
            cout << "enter a choice:\n"
            << "1.chnage a student\n"
            << "2.chnage morabi\n"
            << "3.change team name:\n";
            cin >> choice;
            if(choice == 1){
                cout << "enter stdnumber:\n";
                cin >> stdNumber;
                index = indexOfStudent(a , stdNumber);
                if(index == -1){
                    cout << "error student not found!\n";
                }else{
                    cout << "enter new fname:\n";
                    cin >> a.students[index].fName;
                    cout << "enter new lname:\n";
                    cin >> a.students[index].lName;
                    cout << "enter new callNumber:\n";
                    cin >> a.students[index].callNumber;
                    cout << "enter new stdNumber:\n";
                    cin >> a.students[index].stdNumber;
                }
            }else if(choice == 2){
                cout << "enter new morabi fname:\n";
                cin >> a.morabifName;
                cout << "enter new morabi lname:\n";
                cin >> a.morabilName;
            }else{
                cout << "enter team new name:\n";
                cin >> a.teamName;
            }

        }
    private:
        void sortStudents(Team a){
            a.quickSort(a.students , 0 , a.size-1);
        }
        int indexOfStudent(Team a , string stdNumber){
            sortStudents(a);
            return a.binarySearch(a.students , 0 , a.size-1,stdNumber);
        }
        bool inTeam = false;
            
        
};
