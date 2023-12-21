#include <iostream>
#include <string>
#include <cstdlib>

class Baby {
protected:
    std::string name;
    std::string sex;
public:
    Baby(const std::string& n, const std::string& s) : name(n), sex(s) {
        std::cout << "Hello, my name is " << name << " and I am " << sex << std::endl;
    }
};

class Kinder : public Baby {
protected:
    int f_color;
public:
    Kinder(const std::string& n, const std::string& s) : Baby(n, s), f_color(rand() % 7) {
        std::cout << "My favorite color is ";
        switch (f_color) {
        case 1: std::cout << "red"; break;
        case 2: std::cout << "green"; break;
        case 3: std::cout << "blue"; break;
        case 4: std::cout << "yellow"; break;
        case 5: std::cout << "orange"; break;
        case 6: std::cout << "purple"; break;
        default: std::cout << "none";
        }
        std::cout << std::endl;
    }
};

class Pupil : public Kinder {
protected:
    int mentality;
public:
    Pupil(const std::string& n, const std::string& s) : Kinder(n, s), mentality(rand() % 3) {
        if (mentality == 1)
            std::cout << "I am a humanitarian pupil" << std::endl;
        else if (mentality == 2)
            std::cout << "I am a technical pupil" << std::endl;
        else
            std::cout << "I am a pupil with no defined mentality" << std::endl;
    }
};

class Teen : public Pupil {
protected:
    int hobby;
public:
    Teen(const std::string& n, const std::string& s) : Pupil(n, s), hobby(rand() % 5) {
        switch (hobby) {
        case 1: std::cout << "My hobby is music" << std::endl; break;
        case 2: std::cout << "My hobby is sport" << std::endl; break;
        case 3: std::cout << "My hobby is dancing" << std::endl; break;
        case 4: std::cout << "My hobby is math" << std::endl; break;
        default: std::cout << "I have no specific hobby" << std::endl;
        }
    }
};

class Student : public Teen {
protected:
    int num_Friends;
public:
    Student(const std::string& n, const std::string& s) : Teen(n, s), num_Friends(rand() % 101) {
        if (num_Friends > 0)
            std::cout << "I have " << num_Friends << " friends" << std::endl;
        else
            std::cout << "I have no friends" << std::endl;
    }
};

class Youth : public Student {
protected:
    bool education;
public:
    Youth(const std::string& n, const std::string& s) : Student(n, s), education(rand() % 2 == 1) {
        if (education)
            std::cout << "I have an education" << std::endl;
        else
            std::cout << "I don't have an education" << std::endl;
    }
};

class Adult : public Youth {
protected:
    bool job;
    bool family;
public:
    Adult(const std::string& n, const std::string& s) : Youth(n, s), job(false), family(rand() % 2 == 1) {
        if (education) {
            job = rand() % 2 == 1;
            if (job)
                std::cout << "I have a job" << std::endl;
            else
                std::cout << "I don't have a job" << std::endl;
        }
        else
            std::cout << "I don't have a job" << std::endl;

        if (family)
            std::cout << "I have a family" << std::endl;
        else
            std::cout << "I don't have a family" << std::endl;
    }
};

class Elderly : public Adult {
protected:
    bool gr_children;
    int success;
public:
    Elderly(const std::string& n, const std::string& s) : Adult(n, s), gr_children(family&& rand() % 2 == 1) {
        if (gr_children)
            std::cout << "I have grandchildren" << std::endl;
        else
            std::cout << "I don't have grandchildren" << std::endl;

        success = (education ? 30 : 0) + (job ? 20 : 0) + (num_Friends / 10) + (family ? 25 : 0) + (gr_children ? 15 : 0);
        if (success < 50)
            std::cout << "My level of success is low - " << success << "/100" << std::endl;
        else
            std::cout << "My level of success is high - " << success << "/100" << std::endl;

    }
};

int main() {
    srand(static_cast<unsigned int>(time(0)));
    std::string name, sex;
    std::cin >> name >> sex;
    Elderly e(name, sex);
    return EXIT_SUCCESS;
}

