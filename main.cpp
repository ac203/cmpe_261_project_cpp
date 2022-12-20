#include <iostream>
#include <string>
using namespace std;

#include "User.h"
#include "Note.h"

User currentUser;
list<User> userList;

// MAIN
void initUser();
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
    initUser();

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
