#include <iostream>
#include <string>
using namespace std;

#include "User.h"
#include "Note.h"

// default user when no user is logged in
User loggedOutUser;
// current logged in user is saved in this variable, default is loggedOutUser
User currentUser;
// list of registrated users
list<User> userList;

// MAIN PAGE FUNCTIONS
void infoLoginPage();
void initUser();
void setCurrentUser(User);
User getCurrentUser();
User getUserFromList(string, string);
void logout();

// LOGIN PAGE FUNCTIONS
bool checkIfUserExists(string, string);
void login(string, string);
void showUserDoesNotExistMessage();
void showEmptyUserInfoMessage();

// REGISTRATION PAGE FUNCTIONS
bool checkIfUserAlreadyRegistered(string, string);
void registerUser(User);
void emptyUserInfoMessage();
void userAlreadyExistsMessage();

// WELCOME PAGE FUNCTIONS
void createNoteList();
void createNewNote(string, string);
void infoNoteEditorPage();

int main() {
    // initalize default users and notes
    initUser();

    // flag for exiting the programm, default false
    bool exit = false;

    // user input is saved in these variables
    string username;
    string password;

    cout << "Welcome to MyNotes Console Edition" << endl;
    infoLoginPage();

    while(!exit) {
        // flag for the ui
        int uiChoice = 0;

        cout << "Enter a number to proceed: ";
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
                    infoLoginPage();
                }
            } else {
                showEmptyUserInfoMessage();
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

            if (!username.empty() && !password.empty() && !mail.empty()) {
                if (checkIfUserAlreadyRegistered(username, mail)) {
                    userAlreadyExistsMessage();
                } else {
                    User user(username, password, mail);
                    registerUser(user);
                }
            } else {
                emptyUserInfoMessage();
            }
        } else if (uiChoice == -1) {
            exit = true;
        } else {
            // TODO: got back to menu choice
            cout << "Invalid number entered. Application will terminate." << endl;
            break;
        }
    }

    return 0;
}

void infoLoginPage() {
    cout << "##########################" << endl;
    cout << "## WELCOMEPAGE COMMANDS ##" << endl;
    cout << "##  1 --> Login ------- ##" << endl;
    cout << "##  2 --> Registration  ##" << endl;
    cout << "## -1 --> Exit -------- ##" << endl;
    cout << "##########################" << endl;
}

void infoNoteEditorPage() {
    cout << "############################" << endl;
    cout << "### NOTE EDITOR COMMANDS ###" << endl;
    cout << "##  1 --> View Notes -----##" << endl;
    cout << "##  2 --> Create New Note ##" << endl;
    cout << "## -1 --> Logout ---------##" << endl;
    cout << "############################" << endl;

    cout << "Enter a number to proceed: ";
}

// MAIN PAGE FUNCTIONS
void initUser() {
    // 2 testuser with notes are initialized
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

    // put testusers in the list of registrated users
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
    setCurrentUser(loggedOutUser);
}


// LOGIN PAGE FUNCTIONS
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


// REGISTRATION PAGE FUNCTIONS
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
    // this function "renders" the notes of the user as long as the user is logged in

    // logged in flag
    bool loggedIn = true;

    // while logged in the user sees all the notes
    while(loggedIn) {

        // flag for ui
        int uiChoice = 0;

        infoNoteEditorPage();

        cin >> uiChoice;

        // list the notes of the user
        if (uiChoice == 1) {
            int i = 1;

            for (Note n: currentUser.getNotes()) {
                cout << "[" << i << "] " << n.getTitle() << endl;
                i++;
            }

            cout << "Enter the number of the note to view: ";

            // choice = index number of the note the user wants to view
            int choice;
            cin >> choice;
            // decreasing the number because of 0 indexing
            choice--;

            cout << "Title: " << currentUser.getNotes()[choice].getTitle() << endl;
            cout << "Note:\n" << currentUser.getNotes()[choice].getNote() << endl;

            cout << "## END View Note ##" << endl;
        } else if (uiChoice == 2) {
            // create new note
            string title;
            string content;

            cout << "Enter new note title: ";
            cin >> title;

            cout << "Enter note content: " << endl;
            cin >> content;

            createNewNote(title, content);

            cout << "Created new note succesfully" << endl;
        } else if (uiChoice == -1) {
            // log out
            loggedIn = false;
            logout();
        } else {
            cout << "Invalid number entered." << endl;
            break;
        }
    }

}

void createNewNote(string title, string content) {
    // new note gets created and added to current users note list
    Note note(title, content);
    currentUser.addNote(note);
}