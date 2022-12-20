#include <iostream>
#include <string>
using namespace std;

#include "User.h"
#include "Note.h"

User currentUser();

// MAIN
void setCurrentUser(User);
User getCurrentUser();
User getUserFromList(string, string);
void logout();

// LOGIN PANEL
bool checkIfUserExists(string, string);
void login();
void showUserDoesNotExistMessage();
void showEmptyUserInfoMessage();

// REGISTRATION PANEL
bool checkIfUserAlreadyRegistered(string, string);
void registerUser();
void emptyUserInfoMessage();
void userAlreadyExistsMessage();

// WELCOME PANEL
void createNoteList();
void viewNote(Note);
void createNewNote();
void backToWelcomePage();
void saveNote();


int main() {
    string username;
    string password;
    int uiChoice = 0;

    cout << "Welcome to MyNotes Console Edition" << endl;
    cout << "For login press 1, for registration press 2" << endl;

    cin >> uiChoice;

    if (uiChoice == 1) {
        cout << "Login" << endl;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
    } else if (uiChoice == 2) {
        string mail;

        cout << "Register" << endl;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        cout << "Enter mail: ";
        cin >> mail;
    }

    return 0;
}
