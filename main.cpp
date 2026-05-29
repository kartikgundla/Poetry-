// main.cpp
#include "poetryverse.h"
#include <cstdlib>
#include <ctime>
#include <vector>


void displayRandomPoem(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Error opening file.\n";
        return;
    }

    vector<string> poems;
    string line, poem;

    while (getline(file, line)) {
        if (line == "---") {                // end of one poem
            if (!poem.empty()) {
                poems.push_back(poem);
                poem.clear();
            }
        } else {
            poem += line + "\n";
        }
    }

    if (!poem.empty()) poems.push_back(poem); // add last poem if no trailing ---

    if (poems.empty()) {
        cout << "No poems found.\n";
        return;
    }

    srand(time(0));
    int randomIndex = rand() % poems.size();

    cout << poems[randomIndex] << endl;
}

// ------------------ Poem Definitions ------------------
void Poem::display() {
    cout << "\nTitle: " << title << "\nPoem:\n" << text << endl;
}

// ------------------ PoetPoem Definitions ------------------
void PoetPoem::display() {
    displayRandomPoem("old_poets.txt");
}

// ------------------ UserPoem Definitions ------------------
void UserPoem::writePoem() {
    cout << "\nEnter the title of your poem: ";
    cin.ignore(); // clear buffer
    getline(cin, title);

    cout << "Write your poem below (type END on a new line to finish):\n";
    string line;
    text = "";
    while (true) {
        getline(cin, line);
        if (line == "END") break;
        text += line + "\n";
    }
    saveToFile();  // <-- Save poem after writing
    cout << "\nPoem saved successfully to file!\n";
}

void UserPoem::display() {
    cout << "\n--- User's Poem by " << username << " ---";
    Poem::display();
}

// Save to file
void UserPoem::saveToFile() {
    ofstream fout("userpoems.txt", ios::app); // append mode
    if (!fout) {
        cout << "Error opening file for writing!\n";
        return;
    }
    fout << "User: " << username << "\n";
    fout << "Title: " << title << "\n";
    fout << text << "\n";
    fout << "-------------------------\n";
    fout.close();
}

// Show saved poems
void UserPoem::showSavedPoems() {
    ifstream fin("userpoems.txt");
    if (!fin) {
        cout << "\nNo poems found yet.\n";
        return;
    }
    cout << "\n--- All Saved User Poems ---\n";
    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }
    fin.close();
}

// ------------------ ModernPoem Definitions ------------------
void ModernPoem::display() {
    displayRandomPoem("modern_poems.txt");
}

// ------------------ Fact Definitions ------------------
void Fact::display() {
    displayRandomPoem("poetry_facts.txt");
}

// ------------------ Main Function ------------------
int main() {
    int choice;
    do {
        cout << "\n===== Poetry Verse =====\n";
        cout << "1. Read Poet's Poem\n";
        cout << "2. Read Modern Poem\n";
        cout << "3. Read Poetry Fact\n";
        cout << "4. Write Your Own Poem\n";
        cout << "5. Show Saved User Poems\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                PoetPoem p("John Keats");
                p.display();
                break;
            }
            case 2: {
                
                 ModernPoem m;
                m.display();
                break;
            }
            case 3: {
               Fact f("The shortest poem in English is 'Adam / Had ’em' by Strickland Gillilan.");
                f.display();
                break;
            }
            case 4: {
                UserPoem u("Guest");
                u.writePoem();
                break;
            }
            case 5: {
                UserPoem u;
                u.showSavedPoems();
                break;
            }
            case 6:
                cout << "\nThank you for visiting PoetryVerse!\n";
                break;
            default:
                cout << "\nInvalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
