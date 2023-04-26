#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

class Employee {
    std::string name;
    std::string email;
    std::string designation;
    int salary;
    int group_id;

public:
    Employee(std::string name, std::string email, std::string designation, int salary, int group_id)
        : name(name), email(email), designation(designation), salary(salary), group_id(group_id) {}

    int get_group_id() { return group_id; }
    void set_group_id(int new_group_id) { group_id = new_group_id; }

    friend std::ostream& operator<<(std::ostream& os, const Employee& employee);
    friend std::istream& operator>>(std::istream& is, Employee& employee);
};

std::ostream& operator<<(std::ostream& os, const Employee& employee) {
    os << "Name: " << employee.name << ", Email: " << employee.email << ", Designation: " << employee.designation
       << ", Salary: " << employee.salary << ", Group ID: " << employee.group_id;
    return os;
}

std::istream& operator>>(std::istream& is, Employee& employee) {
    is >> employee.name >> employee.email >> employee.designation >> employee.salary >> employee.group_id;
    return is;
}

class Group {
    std::string name;
    int id;
    std::string focus_area;
    std::vector<Employee> employees;

public:
    Group(std::string name, int id, std::string focus_area) : name(name), id(id), focus_area(focus_area) {}

    void add_employee(Employee emp) { employees.push_back(emp); }

    Group operator-(int count) {
        srand(time(0));
        for (int i = 0; i < count; ++i) {
            if (employees.size() > 0) {
                int index = rand() % employees.size();
                employees.erase(employees.begin() + index);
            }
        }
        return *this;
    }

    Group operator+(const Group& other) {
        Group merged(name + "_" + other.name, id, focus_area + "_" + other.focus_area);
        for (const auto& emp : employees) {
            merged.add_employee(emp);
        }
        for (const auto& emp : other.employees) {
            merged.add_employee(emp);
        }
        return merged;
    }

    std::pair<Group, Group> operator/(int num_of_groups) {
        Group g1(name + "_1", id * 10 + 1, focus_area);
        Group g2(name + "_2", id * 10 + 2, focus_area);
        for (size_t i = 0; i < employees.size(); ++i) {
            if (i % 2 == 0) {
                g1.add_employee(employees[i]);
            } else {
                g2.add_employee(employees[i]);
            }
            employees[i].set_group_id((i % 2 == 0) ? g1.id : g2.id);
        }
        return std::make_pair(g1, g2);
    }

    friend std::ostream& operator<<(std::ostream& os, const Group& group);
    friend std::istream& operator>>(std::istream& is, Group& group);
};

std::ostream& operator<<(std::ostream& os, const Group& group) {
    os << "Group: " << group.name << ", ID: " << group.id << ", Focus Area: " << group.focus_area << '\n';
    os << "Employees: " << '\n';
        for (const auto& emp : group.employees) {
        os << "\n\t" << emp;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Group& group) {
    is >> group.name >> group.id >> group.focus_area;
    return is;
}

int main() {
    Group g1("Engineering", 1, "Software Development");
    Group g2("Design", 2, "UI/UX");

    g1.add_employee(Employee("Alice", "alice@gwitter.com", "Software Engineer", 90000, 1));
    g1.add_employee(Employee("Bob", "bob@gwitter.com", "Software Engineer", 95000, 1));
    g1.add_employee(Employee("Charlie", "charlie@gwitter.com", "Software Engineer", 92000, 1));

    g2.add_employee(Employee("David", "david@gwitter.com", "Designer", 85000, 2));
    g2.add_employee(Employee("Eve", "eve@gwitter.com", "Designer", 88000, 2));

    std::cout << "Original Groups:\n";
    std::cout << g1 << "\n\n";
    std::cout << g2 << "\n\n";

    g1 = g1 - 1;
    std::cout << "After Layoffs:\n";
    std::cout << g1 << "\n\n";

    Group g3 = g1 + g2;
    std::cout << "After Merging:\n";
    std::cout << g3 << "\n\n";

    auto [g4, g5] = g3 / 2;
    std::cout << "After Splitting:\n";
    std::cout << g4 << "\n\n";
    std::cout << g5 << "\n\n";

    return 0;
}

