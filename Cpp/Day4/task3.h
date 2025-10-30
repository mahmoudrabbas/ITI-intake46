



struct Department;
void displayDepartmentWithHighestSalary(vector<Department> departments);

void displayDepartment(const Department& dept);
double totalSalary(const Department& dept);

const Department* findHighestTotalSalaryDepartment(vector<Department>& departments);


struct Employee {
    string name;
    int id;
    int salary;
};

struct Department {
    int id;
    string name;
    vector<Employee> employees;
};

// task three - Corporate Hierarchy
void task3() {

    Department it = {1,"IT", {
                {"Mahmoud", 1, 7000},
                {"Omar", 2, 6000},
                {"Youssef", 3, 8000}
    }};

    Department cs = {2,"CS", {
                {"Sara", 4, 5000},
                {"Nour", 5, 5500}
    }};

    Department is = {3,"IS", {
                {"Ali", 6, 4000},
                {"Mona", 7, 4500},
                {"Karim", 8, 4700}
    }};
    vector<Department> company = {it, cs, is};

    const Department* highestDept = findHighestTotalSalaryDepartment(company);
    if (highestDept) {
        cout << "\nDepartment with highest total salary:\n";
        displayDepartment(*highestDept);
    }
}


double totalSalary(const Department& dept) {
    double total = 0;
    for (const auto& emp : dept.employees) {
        total += emp.salary;
    }
    return total;
}

void displayDepartment(const Department& dept) {
    cout << "Department: " << dept.name << endl;
    cout << "Employees:" << endl;
    for (const Employee& e : dept.employees) {
        cout << "  ID: " << e.id << ", Name: " << e.name
             << ", Salary: " << e.salary << endl;
    }
    cout << "Total Salary: " << totalSalary(dept) << endl;
}

const Department* findHighestTotalSalaryDepartment(vector<Department>& departments) {
    if (departments.empty()) throw runtime_error("No Department found");

    const Department* highest = &departments[0];
    double maxSalary = totalSalary(departments[0]);

    for (const auto& dept : departments) {
        double currentTotal = totalSalary(dept);
        if (currentTotal > maxSalary) {
            maxSalary = currentTotal;
            highest = &dept;
        }
    }

    return highest;
}



#ifndef DAY4_TASK3_H
#define DAY4_TASK3_H

#endif //DAY4_TASK3_H