#include <cassert>
#include <stdexcept>
#include <iostream>

// TODO: Define "Student" class
class Student {
 public:
  // constructor
  Student(std::string name, int grade, float gpa);
  // accessors
  std::string GetName() const;
  int GetGrade() const;
  float GetGpa() const;
  // mutators
  void SetName(std::string name);
  void SetGrade(int grade);
  void SetGpa(float gpa);

 private:
  // name
  std::string name_;
  // grade
  int grade_;
  // GPA
  float gpa_;
};

// Define the Constructor
Student::Student(std::string name, int grade, float gpa) {
    SetName(name);
    SetGrade(grade);
    SetGpa(gpa);
}

// Define the Setters/Mutators
void Student::SetName(std::string name) {
    name_ = name;
}
void Student::SetGrade(int grade) {
    if (grade > 0 && grade <= 12) {
        grade_ = grade;
    }else {
        throw "Invalid Grade value";
    }
}
void Student::SetGpa(float gpa) {
    if (gpa > 0.0 && gpa <= 4.0) {
        gpa_ = gpa;
    }else {
        throw "Invalid gpa value";
    }
}

// Define Accessor Func
std::string Student::GetName() const { return name_; }
int Student::GetGrade() const { return grade_; }
float Student::GetGpa() const { return gpa_; }

// TODO: Test
int main() {
    Student student1("Jessica Wilson", 4, 3.0);
    student1.SetGrade(5);
    assert(student1.GetName() == "Jessica Wilson");
    assert(student1.GetGrade() == 5);
    assert(student1.GetGpa() == 3.0);

    bool caught{false};
    try {
      Student invalid_student("Jane Doe", 2, 6.7);
    } catch (...) {
      caught = true;
    }
    assert(caught);

    try {
       Student invalid_student("Jane Doe", 100, 6.7); 
    }catch (const char* msg){
        std::cerr << msg << std::endl;
    }
}