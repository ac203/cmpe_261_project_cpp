//
// Created by Ali Cinar on 20.12.2022.
//

#include "User.h"
#include "Note.h"

User::User() {}

User::User(string username, string password, string mail) {
    this->username = username;
    this->password = password;
    this->mail = mail;
}

string User::getUsername() {
    return username;
}

string User::getPassword() {
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
