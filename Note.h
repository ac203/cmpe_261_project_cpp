//
// Created by Ali Cinar on 20.12.2022.
//

#ifndef CMPE_261_PROJECT_CPP_NOTE_H
#define CMPE_261_PROJECT_CPP_NOTE_H

#include <string>

using namespace std;

class Note {
private:
    int id;
    string title;
    string note;

public:
    Note(string, string);
    int getId();
    string getTitle();
    void setTitle(string);
    string getNote();
    void setNote(string);
};


#endif //CMPE_261_PROJECT_CPP_NOTE_H
