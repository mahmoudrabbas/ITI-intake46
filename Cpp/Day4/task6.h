//
// Created by PC on 10/30/2025.
//





struct Student {
    int id{};
    string name;
    int age{};
    int grade{};
};


void displayStudents(vector<Student> &students);
void addStudent(vector<Student> &students);
void updateStudent(vector<Student> &students);
void searchStudent(vector<Student> &students);
void (*menu[])(vector<Student>&) = { addStudent, updateStudent, searchStudent, displayStudents};

void task6() {
    Student s = {1,"Mahmoud",4,100};
    Student s2 = {2,"Mohamed",5,100};
    Student s3 = {3,"Ahmed",7,100};
    Student s4 = {4,"Ali",7,100};

    vector<Student> students = {s, s2, s3, s4};


    int choice;
    while (true) {
        cout << "\n=== Student Database ===\n";
        cout << "1. Add Student\n";
        cout << "2. Update Student\n";
        cout << "3. Search Student\n";
        cout << "4. Display Students\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 0) break;
        if (choice >= 1 && choice <= 4) {
            menu[choice - 1](students);
        }else {
            cout << "Invalid Choice\n";
            break;
        }
    }

}



void displayStudents(vector<Student> &students) {
    for (int i = 0; i < students.size(); i++) {
        cout << "ID: " << students[i].id << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Age: " << students[i].age << endl;
        cout << "Grade: " << students[i].grade << endl;
    }
};

void addStudent(vector<Student> &students) {
    Student s;
    cout << "Enter ID: ";
    cin >> s.id;
    cout << "Enter Name: ";
    cin >> s.name;
    cout << "Enter Age: ";
    cin >> s.age;
    cout << "Enter Grade: ";
    cin >> s.grade;
    students.push_back(s);
    cout << "Student Added" << endl;
}

void updateStudent(vector<Student>& students) {
    int id;
    cout << "Enter student ID to update: ";
    cin >> id;

    bool found = false;

    for (auto& s : students) {
        if (s.id == id) {
            cout << "Enter new name: ";
            cin >> s.name;
            cout << "Enter new age: ";
            cin >> s.age;
            cout << "Enter new grade: ";
            cin >> s.grade;

            cout << "Student updated\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "student not found!\n";
    }
}

void searchStudent(vector<Student> &students) {
    string name;
    cout << "Enter student Name: ";
    cin>>name;
    for (int i = 0; i < students.size(); i++) {
        if (students[i].name == name) {
            cout << "ID: " << students[i].id << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Age: " << students[i].age << endl;
            cout << "Grade: " << students[i].grade << endl;
            return;
        }
    }

    cout << "Student not found" << endl;
}



#ifndef DAY4_TASK6_H
#define DAY4_TASK6_H

#endif //DAY4_TASK6_H