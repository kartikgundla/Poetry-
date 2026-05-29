// poetryverse.h
#include <iostream>
#include <string>
#include <vector>
#include <fstream>  // <-- Added for file handling
using namespace std;

// ------------------ Abstract Base Class ------------------
class Content {
protected:
    string title;
public:
    Content(string t = "") : title(t) {}
    virtual void display() = 0; // Pure virtual function
    virtual ~Content() {}
};

// ------------------ Poem Base Class ------------------
class Poem : public Content {
protected:
    string text;
public:
    Poem(string t = "", string tx = "") : Content(t), text(tx) {}
    virtual void display();
};

// ------------------ PoetPoem Class ------------------
class PoetPoem : public Poem {
public:
    void display() override;
};

// ------------------ UserPoem Class ------------------
class UserPoem : public Poem {
    string username;
public:
    UserPoem(string u = "") : username(u) {}
    void writePoem();
    void display() override;
    void saveToFile();    // <-- Added
    void showSavedPoems();// <-- Added
};

// ------------------ ModernPoem Class ------------------
class ModernPoem : public Poem {
public:
    void display() override;
};

// ------------------ Fact Class ------------------
class Fact : public Content {
public:
    void display() override;
};
