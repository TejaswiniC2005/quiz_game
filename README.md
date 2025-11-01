# Quiz Game in C

This is a console-based Quiz Application built in C.
Users can attempt quiz questions, and admins can add new questions and view existing ones.
The program also stores score history in a text file.

---

## Features

* User can take quiz (Multiple Choice Questions)
* Admin can add questions at runtime
* View stored questions (Admin)
* Score history saved to a file (`scores.txt`)
* Uses linked list to store questions
* Input validation for choices (A/B/C/D)

---

## Technologies Used

* C Programming
* Linked Lists
* File Handling
* Dynamic Memory Allocation

---

## How to Run

### Windows (MinGW / GCC)

```
gcc quiz.c -o quiz
./quiz
```

### Linux / Mac

```
gcc quiz.c -o quiz
./quiz
```

## Menu Options

```
1. Start Quiz
2. Add Question (Admin)
3. View Questions (Admin)
4. View Score History
5. Exit
```

## Files

| File       | Description                    |
| ---------- | ------------------------------ |
| quiz.c     | Source code                    |
| scores.txt | Score history (auto-generated) |

---

## Sample Output Menu

====== QUIZ MENU ======
1. Start Quiz
2. Add Question (Admin)
3. View Questions (Admin)
4. View Score History
5. Exit
Choose:
```
## Future Improvements

* Admin login system
* Persistent question storage using file handling
* Difficulty levels
* Timer for questions
* Leaderboard system
* GUI version

---
