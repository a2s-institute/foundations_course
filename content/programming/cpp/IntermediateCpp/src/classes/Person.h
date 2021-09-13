#pragma once

    #include <string>
    #include <iostream>

    class Person
    {

    private:
        std::string firstName;
        std::string lastName;
        int age;

    public:

        int count;
        Person();

        Person(std::string fName, std::string lName);

        Person(std::string fName, std::string lName, int age);

        ~Person();

        void SetFirstName(std::string fName);
        std::string GetFirstName();
        
        void SetLastName(std::string lName);
        std::string GetLastName();

        void SetAge(int age);
        int GetAge();

        void SayHello();

};