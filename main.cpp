#include <iostream>
#include <string>
using namespace std;

#include "User.h"
#include "Note.h"

User loggedOfUser;
User currentUser;
list<User> userList;

// MAIN
void info();

void initUser();
void setCurrentUser(User);
User getCurrentUser();
User getUserFromList(string, string);
void logout();

// LOGIN PANEL
bool checkIfUserExists(string, string);
void login(string, string);
void showUserDoesNotExistMessage();
void showEmptyUserInfoMessage();

// REGISTRATION PANEL
bool checkIfUserAlreadyRegistered(string, string);
void registerUser(User);
void emptyUserInfoMessage();
void userAlreadyExistsMessage();

// WELCOME PANEL
void createNoteList();
void viewNote(Note);
void createNewNote();
void backToWelcomePage();
void saveNote();

int main() {
    initUser();
    bool exit = false;

    string username;
    string password;
    int uiChoice = 0;

    cout << "Welcome to MyNotes Console Edition" << endl;
    info();

    while(!exit) {
        cin >> uiChoice;

        if (uiChoice == 1) {
            cout << "Login" << endl;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;

            if (!username.empty() && !password.empty()) {
                bool userExists = checkIfUserExists(username, password);

                if (userExists) {
                    login(username, password);
                    createNoteList();
                } else {
                    showUserDoesNotExistMessage();
                    info();
                }
            }
        } else if (uiChoice == 2) {
            string mail;

            cout << "Register" << endl;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            cout << "Enter mail: ";
            cin >> mail;

            User user(username, password, mail);

            // TODO: -> Registration Panel Methods

            registerUser(user);
        } else if (uiChoice == -1) {
            exit = true;
        }
    }

    return 0;
}

void info() {
    cout << "########################" << endl;
    cout << "## ---- COMMANDS ---- ##" << endl;
    cout << "## Login ---------> 1 ##" << endl;
    cout << "## Registration --> 2 ##" << endl;
    cout << "## Exit ---------> -1 ##" << endl;
    cout << "########################" << endl;
}

// MAIN
void initUser() {
    User testUser("testuser", "1234", "abc@mail.com");
    User testUser2("aa", "aa", "aa");

    Note note1("Note 1", "This is the first note.");
    Note note2("Note 2", "This is the second note.");
    Note note3("Note 3", "This is the third note.");
    Note note4("Note 4", "This is the 4th note.");
    Note note5("Note FIVE", "Note number five.");
    Note note6("6th Note", "Note number six.");

    testUser.addNote(note1);
    testUser.addNote(note2);
    testUser.addNote(note3);

    testUser2.addNote(note4);
    testUser2.addNote(note5);
    testUser2.addNote(note6);

    userList.push_back(testUser);
    userList.push_back(testUser2);
}

void setCurrentUser(User user) {
    currentUser = user;
}

User getCurrentUser() {
    return currentUser;
}

User getUserFromList(string username, string password) {
    // get registered user from user list

    User user;
    for (User u : userList) {
        if (u.getUsername() == username && u.getPassword() == password) {
            user = u;
        }
    }
    return user;
}

void logout() {
    setCurrentUser(loggedOfUser);
}


// LOGIN PANEL
bool checkIfUserExists(string username, string password) {
    // iterate through list of users and return true if user exists
    for (User u : userList) {
        if (username == u.getUsername() && password == u.getPassword()) {
            return true;
        }
    }
    return false;
}

void login(string username, string password) {
    // set user as current user
    setCurrentUser(getUserFromList(username, password));
    cout << "Logged in succesfully" << endl;
}

void showUserDoesNotExistMessage() {
    cout << "User does not exist" << endl;
}

void showEmptyUserInfoMessage() {
    cout << "Please enter username & password" << endl;
}


// REGISTRATION PANEL
bool checkIfUserAlreadyRegistered(string username, string mail) {
    // iterate through list of users and return true if user is already registered
    for (User u : userList) {
        if (username == u.getUsername() || mail == u.getMail()) {
            return true;
        }
    }
    return false;
}

void registerUser(User user) {
    userList.push_back(user);
}

void emptyUserInfoMessage() {
    cout << "Please fill in your information" << endl;
}

void userAlreadyExistsMessage() {
    cout << "User already exists" << endl;
}


// WELCOME PANEL
void createNoteList() {
    int i = 1;

    for (Note n : currentUser.getNotes()) {
        cout << "[" << i << "] " << n.getNote() << endl;
        i++;
    }

    // TODO: view note

    cout << "Enter the number of the note to view" << endl;

    int choice;
    cin >> choice;

}
// Note viewNote(index of notelist);
void viewNote(Note);
void createNewNote();
void backToWelcomePage();
void saveNote();
