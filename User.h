//
// Created by Ali Cinar on 20.12.2022.
//

#ifndef CMPE_261_PROJECT_CPP_USER_H
#define CMPE_261_PROJECT_CPP_USER_H

#include <string>
#include <list>
#include "Note.h"

using namespace std;

class User {
private:
    string userName;
    string password;
    string mail;
    list<Note> notes;

public:
    User();
    User(string, string, string);
    string getUserName();
    string getPassWord();
    string getMail();
    list<Note> getNotes();
    void addNote(Note);
//    void updateNotes();
//    void deleteNote(Note);

};

#endif //CMPE_261_PROJECT_CPP_USER_H