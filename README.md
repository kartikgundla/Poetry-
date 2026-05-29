# 📜 PoetryVerse

A C++ console application that brings the world of poetry to your terminal — read classic and modern poems, discover poetry facts, and write your own verses.

## ✨ Features

- Read Poet's Poems — Randomly displays classic poems by poets like John Keats, William Shakespeare, William Wordsworth, and Percy Bysshe Shelley
- Read Modern Poems — Randomly displays contemporary poems by Maya Angelou, Pablo Neruda, Dylan Thomas, Allen Ginsberg, and more
- Poetry Facts — Learn interesting facts about the history and forms of poetry
- Write Your Own Poem — Compose and save your own poems with a title
- View Saved Poems — Browse all previously written user poems

## 🗂️ Project Structure

```
poetry/
├── main.cpp           # Main program logic and class definitions
├── poetryverse.h      # Header file with class declarations
├── old_poets.txt      # Classic poems collection
├── modern_poems.txt   # Modern poems collection
├── poetry_facts.txt   # Poetry facts database
└── userpoems.txt      # Stores user-written poems
```

## 🧱 OOP Concepts Used

- Abstract Base Class — `Content` with a pure virtual `display()` function
- Inheritance — `Poem`, `PoetPoem`, `UserPoem`, `ModernPoem`, and `Fact` all extend base classes
- Polymorphism — Each class overrides `display()` differently
- File Handling — User poems are saved to and read from `userpoems.txt`

## 🛠️ How to Compile & Run

Make sure you have a C++ compiler (g++) installed.

```bash
g++ main.cpp -o poetryverse
./poetryverse
```

On Windows:
```bash
g++ main.cpp -o poetryverse.exe
poetryverse.exe
```

## 📋 Menu Options

```
===== Poetry Verse =====
1. Read Poet's Poem
2. Read Modern Poem
3. Read Poetry Fact
4. Write Your Own Poem
5. Show Saved User Poems
6. Exit
```

## 📌 Requirements

- C++11 or later
- Standard library only (no external dependencies)

## 👤 Author

Kartik Gundla - https://github.com/kartikgundla
