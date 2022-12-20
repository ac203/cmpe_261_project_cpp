//
// Created by Ali Cinar on 20.12.2022.
//

#include "Note.h"

int idCounter = 1;

Note::Note(string title, string note) {
    id = idCounter;
    this->title = title;
    this->note = note;
    idCounter++;
}

int Note::getId() {
    return id;
}

string Note::getTitle() {
    return title;
}

void Note::setTitle(string title) {
    this->title = title;
}

string Note::getNote() {
    return note;
}

void Note::setNote(string note) {
    this->note = note;
}
