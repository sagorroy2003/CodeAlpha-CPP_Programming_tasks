#include<iostream>
#include<iomanip> // input/output manipulation 
#include<string>
#include<vector>

using namespace std;

// GPA (Grade Point Average): Calculated for one semester only.
// CGPA (Cumulative GPA): Calculated for all semesters combined.
//.........................................................................
// GPA = (Sum of (Grade Point × Credit Hours)) / (Total Credit Hours for the semester)
//
// Example:
// Course 1: Grade = 3.7, Credit = 3  → 3.7 * 3 = 11.1
// Course 2: Grade = 3.9, Credit = 4  → 3.9 * 4 = 15.6
// Total Grade Points = 11.1 + 15.6 = 26.7
// Total Credit Hours = 3 + 4 = 7
// GPA = 26.7 / 7 = 3.814 ≈ 3.81
//.........................................................................
// CGPA = (Sum of (Grade Point × Credit Hours) for all semesters) / (Total Credit Hours for all semesters)
//
// Example:
// Semester 1: Total Grade Points = 26.7, Total Credit Hours = 7
// Semester 2: Total Grade Points = 11.4, Total Credit Hours = 3
// Overall Total Grade Points = 26.7 + 11.4 = 38.1
// Overall Total Credit Hours = 7 + 3 = 10
// CGPA = 38.1 / 10 = 3.81


int main() {
    int number_of_semesters;
    cout << "Enter number of semesters: ";
    cin >> number_of_semesters;

    float overall_total_credit = 0;
    float overall_total_grade_point = 0;

    for(int sem = 1; sem <= number_of_semesters; sem++) {
        int number_of_course;

        cout << "\nEnter the number of courses in semester " << sem << ": ";
        cin >> number_of_course;

        float semester_total_credit = 0;
        float semester_total_grade_point = 0;

        float grade_point, credit_hour;
        string course_name;
        vector<string> all_course(number_of_course);
        vector<float> store_grade_point(number_of_course);

        cout << "\nEnter course details for semester " << sem << ":\n";

        for(int i=0; i< number_of_course; i++) {
            cout << "\n....course " << i+1 << "....\n";

            cout <<"Enter Course Name: ";
            cin.ignore();
            getline(cin, course_name); // can take space string
            all_course[i] = course_name;

            cout << "Enter Grade point (0.00 - 4.00): ";
            cin >> grade_point;
            store_grade_point[i] = grade_point;

            cout << "Enter Credit Hours: ";
            cin >> credit_hour;

            // semester totals
            semester_total_credit += credit_hour;
            semester_total_grade_point += grade_point * credit_hour;

            // overall totals
            overall_total_credit += credit_hour;
            overall_total_grade_point += grade_point * credit_hour;

            cout << "....DONE....\n";
        }

        // calculate GPA for this semester
        float gpa = semester_total_grade_point / semester_total_credit;

        cout << "\n# Semester " << sem << " Results\n";
        for(int i = 0; i < number_of_course; i++) {
            cout << i + 1 << ". " << all_course[i] 
                 << " - Grade: " << fixed << setprecision(2) 
                 << store_grade_point[i] << endl;
        }

        cout << "Semester GPA: " << fixed << setprecision(2) << gpa << "\n";
        cout << "--------------------------\n";
    }

    // calculate final CGPA
    float cgpa = overall_total_grade_point / overall_total_credit;

    cout << "\nFINAL CGPA (All Semesters): " << fixed << setprecision(2) << cgpa << endl;

    return 0;
}
