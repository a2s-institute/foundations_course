#include <iostream>
#include <string>

using namespace std;

// This is a simple class that can store basic student information
class StudentInfo {
  public:
    // This is a default constructor.
    // It is used to create a student information object without providing any
    // details about the student
    StudentInfo()
    {
        name_ = "Unknown";
        nationality_ = "Unknown";
        age_ = -1;
        gender_ = "Unknown";
        studentID_ = -1;
    }

    // This is a parameterized constructor.
    // This can be used to create a complete student ID by providing all the
    // student information at the creation time.
    StudentInfo(string name, string nationality, int age, string gender, int ID)
    {
        name_ = name;
        nationality_ = nationality;
        age_ = age;
        gender_ = gender;
        studentID_ = ID;
    }

    // This is a destructor.
    // This will be automatically called when an object of this class is
    // destroyed
    ~StudentInfo() {}

    // These are called getters and setters.
    // Such methods are used for setting or getting values of the object
    // properties
    string getName() { return name_; }
    void setName(string name) { name_ = name; }

    string getNationality() { return nationality_; }
    void setNationality(string nationality) { nationality_ = nationality; }

    int getAge() { return age_; }
    void setAge(int age) { age_ = age; }

    string getGender() { return gender_; }
    void setGender(string gender) { gender_ = gender; }

    int getStudentID() { return studentID_; }
    void setStudentID(int studentID) { studentID_ = studentID; }

    void printStudentDetails()
    {
        cout << "\n============= Student Details =============" << endl;
        cout << "Name: " << name_ << "\nNationality: " << nationality_
             << "\nAge: " << age_ << "\nGender: " << gender_
             << "\nID: " << studentID_ << endl;
        cout << "===========================================" << endl;
    }

  protected:
    // These are the properties of every student we wish to store.
    string name_;
    string nationality_;
    int age_;
    string gender_;
    int studentID_;
};

int main()
{
    // Create a default student object
    StudentInfo student1;
    // This will print all default invalid values assigned to the student object
    student1.printStudentDetails();

    // Fill in the student information in the object
    student1.setName("Ahmed");
    student1.setNationality("Sudan");
    student1.setAge(23);
    student1.setGender("Male");
    student1.setStudentID(1);
    // This will now print the proper filled student information.
    student1.printStudentDetails();

    // Create another student info object for another person
    // We will now use the parameterized constructor to simplyfy creating the
    // object
    StudentInfo student2("Sushant", "India", 28, "Male", 2);
    // This will print the complete and correct student details
    student2.printStudentDetails();

    // Assume one year has passed, update the age of both the students
    student1.setAge(student1.getAge() + 1);
    student2.setAge(student2.getAge() + 1);

    // Print the updated details of both the students
    cout << "\n\nAfter one year..." << endl;
    student1.printStudentDetails();
    student2.printStudentDetails();

    return 0;
}
