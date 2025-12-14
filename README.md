# Hangman Game in C
A classic command-line Hangman game, built with pure C. This project serves as a foundational exercise in C programming

--

## 🔍 Overview

This is a fully command-line based Hangman game application. The program will choose a random word from a file, and the player will try to guess the word, letter by letter, before the hangman is fully drawn. The project is implemented in C without external libraries beyond the standard library.

## 🎯 Project Goals

* Master the fundamentals of the C language, including file operations, memory allocation, and string handling.
* Develop a complete, playable game from scratch.
* Practice a professional development workflow using Git for version control and a Makefile for compilation.

## 🏗️ Functional Requirements
### Core Features
* Read a list of words from an external text file.
* Select a random word from the list for each new game.
*  Display the hidden word on the screen using underscores (e.g., `_ _ _ _ _`).
* Ask the player for a letter input.
* Check if the guessed letter is in the word.
    * If correct, reveal the letter in the hidden word.
    * If incorrect, increment the error count and draw the next part of the hangman.
* Keep track of already guessed letters to avoid repeated guesses.
* End the game when the player wins (guesses the word) or loses (reaches the maximum number of errors).
* Display a clear win/loss message at the end.
### Visual & User Experience
* Display a welcome header for the game.
* Show the hangman's state using ASCII art, which updates with each error.
* Clearly display the hidden word, the number of remaining lives/guesses, and the letters already tried.
---

## 🚀 How to Compile and Run

### Prerequisites
To compile and run this project, you will need `gcc` (or a similar C compiler) and `make` installed on your system.

### Compilation
1.  Clone the repository to your local machine.
2.  Navigate into the project directory.
3.  Run the `make` command:
    ```sh
    make
    ```
    This will create the executable file named `forca`.

### Running the Game
To start the game, run the executable from your terminal:
```sh
./forca
```
