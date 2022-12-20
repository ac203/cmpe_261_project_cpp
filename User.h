//
// Created by Ali Cinar on 20.12.2022.
//

#ifndef CMPE_261_PROJECT_CPP_USER_H
#define CMPE_261_PROJECT_CPP_USER_H

#include <string>
#include <list>
#include <vector>
#include "Note.h"

using namespace std;

class User {
private:
    string username;
    string password;
    string mail;
    vector<Note> notes;

public:
    User();
    User(string, string, string);
    string getUsername();
    string getPassword();
    string getMail();
    vector<Note> getNotes();
    void addNote(Note);
//    void updateNotes();
//    void deleteNote(Note);

};

#endif //CMPE_261_PROJECT_CPP_USER_H