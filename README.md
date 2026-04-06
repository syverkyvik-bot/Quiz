## Overview
This is a C++ quiz game with a graphical user interface (GUI). 
The application loads multiple-choice questions from a text file and allows users to answer them by clicking buttons. 
It tracks the player's score and displays the final result when all questions are completed.

## How the Program Works

### Main Loop
The program initializes by:
1. Opening the `questions.txt` file containing quiz questions
2. Creating an AnimationWindow-based GUI
3. Displaying the first question with four answer options as clickable buttons
4. Entering a main event loop that:
   - Listens for button clicks
   - Validates answers (green for correct, red for incorrect)
   - Increments the score when correct answers are selected
   - Loads the next question when the "Next" button is clicked
   - Displays the final score when all questions are completed

### File Format
Questions are stored in `questions.txt` with the following format:

## Compilation and Running

To compile the project:
```bash
meson compile -Cbuild
```
To run:
```bash
./build/program
```

### Questions

To add or remove questions edit the `questions.txt` file.
When adding new questions use '?' at the end of the question, ';' between the answers and before the answer that should be written as a number from 1 to 4 at the end. Follow example under:

Hvilket land er kjent for pyramider i Giza?;Mexico;India;Egypt;Peru;3


## Key Components

### `readFile.cpp / readFile.h` - Questions Class
Handles all file I/O and question parsing:
- **`openFile()`**: Opens the questions.txt file
- **`setFullQuestion()`**: Reads a complete line from the file
- **`setQuestion()`**: Extracts the question text (everything before the "?")
- **`setOptionsAndAnswer()`**: Parses answer options separated by semicolons and identifies the correct answer
- **`setQuestionOptionsAnswer()`**: Combines the above methods to process a complete question
- **`getQuestion()`, `getOptions()`, `getAnswer()`**: Getter methods for the parsed data
- **`isFinished()`**: Checks if the file has reached its end

### `GUI.cpp / GUI.h` - GUI Class
Extends `AnimationWindow` to create the user interface:
- **Constructor**: Initializes four option buttons and a "Next" button with appropriate styling and size
- **`displayQuestion()`**: Renders the current question in a cyan box at the top of the window
- **`checkAnswer(size_t buttonNumber)`**: Validates the selected answer, changes button color (green for correct, red for incorrect), and updates the score
- **`addScore()` / `getScore()`**: Manages the player's score
- **`updateOptions()`**: Updates button labels and callbacks for the next question
- **`displayScore()`**: Shows the final score when the quiz is completed

## Resources and Tools Used

### Libraries
- **AnimationWindow**: A custom graphics library provided by TDT4102 at NTNU for creating interactive windows and GUI components
- **SDL2**: Underlying graphics library used by AnimationWindow
- **C++ Standard Library**: For file I/O (`<fstream>`), string handling (`<string>`), and vector operations (`<vector>`)

### Build System
- **Meson**: Build system used to compile the project with proper dependency management

### External Tools
- AI assistance (ChatGPT/Copilot): Used for debugging, code structure suggestions, and documentation
- VS Code: Development environment with C++ extensions

### AI-Generated Code
The following parts were assisted or reviewed with ChatGPT:
- isFinished() function
- help for debugging
- Documentation


