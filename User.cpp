//
// Created by Ali Cinar on 20.12.2022.
//

#include "User.h"
#include "Note.h"

User::User() {}

User::User(string userName, string password, string mail) {
    this->userName = userName;
    this->password = password;
    this->mail = mail;
}

string User::getUserName() {
    return userName;
}

string User::getPassWord() {
    return password;
}

string User::getMail() {
    return mail;
}

list<Note> User::getNotes() {
    return notes;
}

void User::addNote(Note note) {
    notes.push_back(note);
}
/*

void User::updateNotes() {
        notes = Main.noteService.getAllNotes(this);
}

void User::deleteNote(Note note) {
    notes.remove(note);
}

 */
