#include <iostream>
#include <unordered_map>
#include <sstream>

using namespace std;

// Structure to store student information
struct Student {
    string name;
    string className;
};

unordered_map<int, Student> studentDatabase;

void insertStudent(int id, const string& name, const string& className) {
    studentDatabase[id] = {name, className};
}

void deleteStudent(int id) {
    studentDatabase.erase(id);
}

void inforStudent(int id) {
    if (studentDatabase.find(id) != studentDatabase.end()) {
        cout << studentDatabase[id].name << "," << studentDatabase[id].className << endl;
    } else {
        cout << "NA,NA" << endl;
    }
}

int main() {
    string command;
    while (getline(cin, command)) {
        stringstream ss(command);
        string operation, name, className;
        int id;
        
        ss >> operation;
        if (operation == "Insert") {
            char comma;
            ss >> id >> comma;
            getline(ss, name, ',');
            getline(ss, className);
            insertStudent(id, name, className);
        } 
        else if (operation == "Delete") {
            ss >> id;
            deleteStudent(id);
        } 
        else if (operation == "Infor") {
            ss >> id;
            inforStudent(id);
        }
    }
    return 0;
}

