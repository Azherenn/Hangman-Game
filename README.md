# 🕵️‍♂️ Hangman Game in C (Jogo da Forca)

A robust command-line Hangman game built with pure C. This project demonstrates core programming concepts such as file handling, memory management, structs, and cross-platform compatibility.

## 🌟 Key Features

- **Cross-Platform:** Runs natively on both Windows and Linux (auto-detects OS for screen clearing).
- **Database System:** Reads words, IDs, difficulty levels, and **contextual tips** from an external `database.txt` file.
- **Robust Input Handling:**
  - Automatic uppercase conversion.
  - Keyboard buffer cleaning to prevent input errors.
  - History tracking of incorrect guesses.
- **Dynamic Gameplay:**
  - Visual feedback with ASCII art.
  - Win/Loss detection logic.
  - Tip display to help the player.

## 🛠️ Technical Concepts Applied

- **Structs:** organized data management for game objects.
- **Pointers:** efficient memory manipulation and string passing.
- **File I/O:** `fopen`, `fgets`, and string parsing with `strtok`.
- **Preprocessor Directives:** `#ifdef` for OS-specific commands.

## 🚀 How to Compile and Run

### Prerequisites
You need a C compiler (like GCC) installed.

### 1. Clone the repository
```bash
git clone https://github.com/Azherenn/Hangman-Game.git
cd Hangman-Game
```


### 2. Compile
Use `gcc` to compile the source code.

```bash
gcc main.c -o hangman
```

*(On Windows, this automatically creates hangman.exe)*

### 3. Run
Make sure `database.txt` is in the same folder as the executable.
```
./hangman
```
*(Or just `hangman.exe` on Windows cmd)*

## 📂 Project Structure

- `main.c`: Contains the game logic, main loop, and UI functions.
- `database.txt`: Stores the words and tips (Format: `ID;WORD;TIP;LEVEL`).

## 👤 Author

Developed by **[Magno / Ricardo]** as a portfolio project for C programming.
