//
// Created by hun46 on 2019. 04. 23..
//

#ifndef GREENFOXORGANIZATION_COHORT_H
#define GREENFOXORGANIZATION_COHORT_H

#include "Student.h"
#include "Mentor.h"
#include <vector>

class Cohort {
public:
    Cohort(std::string);

    void addStudent(Student*);
    void addMentor(Mentor*);
    void info();
private:
    std::string _name;
    std::vector<Student> _students;
    std::vector<Mentor> _mentors;

};


#endif //GREENFOXORGANIZATION_COHORT_H
