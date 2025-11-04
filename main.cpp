#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;


enum GradeLevel { Freshman = 1, Sophomore, Junior, Senior };

namespace StudentUtils {
     void formatName(string &name) {
        transform(name.begin(), name.end(), name.begin(), ::toupper);
    }

     void displayStudentInfo(const string &name, GradeLevel grade, double gpa) {
        cout << "\nStudent Record:\n";
        cout << "Name: " << name << endl;

        // Convert enum to text
        string gradeText;
        switch(grade) {
            case Freshman: gradeText = "Freshman"; break;
            case Sophomore: gradeText = "Sophomore"; break;
            case Junior: gradeText = "Junior"; break;
            case Senior: gradeText = "Senior"; break;
        }
 cout << "Grade Level: " << gradeText << endl;

        // Display GPA formatted to 2 decimal places
        cout << "GPA: " << fixed << setprecision(2) << gpa << endl;
    }
}


int main (){
     string studentName;
    int gradeInput;
    double gpa;

     cout << "Enter student name: ";
    getline(cin, studentName);

     cout << "Enter grade level (1=Freshman, 2=Sophomore, 3=Junior, 4=Senior): ";
    cin >> gradeInput;

     cout << "Enter GPA: ";
    cin >> gpa;

    StudentUtils::formatName(studentName);
    StudentUtils::displayStudentInfo(studentName, static_cast<GradeLevel>(gradeInput), gpa);

    return 0;
    
}
