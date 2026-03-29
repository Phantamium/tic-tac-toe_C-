# Tic-Tac-Toe AI using Minimax (C++)

## Overview

This project is a command-line Tic-Tac-Toe game developed in C++. It includes a computer opponent that uses the **Minimax algorithm** to make decisions. The objective is to demonstrate how a computer can simulate possible future game states and choose a move based on those outcomes.

---

## Problem Statement

In turn-based games, making a good move often requires thinking ahead and considering possible responses from the opponent. This project explores how a computer can apply this idea using a recursive decision-making algorithm.

---

## Approach

### Game Representation

The board is represented using a one-dimensional array of size 9. Each position corresponds to a cell in the Tic-Tac-Toe grid.
The opponent chooses from 1-9 and enters a number based on where they want to place their pointer.

1st row - 1 | 2 | 3
2nd row - 4 | 5 | 6
3rd row - 7 | 8 | 9

### Minimax Algorithm

The Minimax algorithm is used to evaluate moves:

* The computer simulates possible moves recursively
* It assumes the opponent also plays optimally
* Each outcome is assigned a score:

  * +1 → computer wins
  * -1 → player wins
  * 0 → tie or depth limit reached

To control recursion depth, a depth limit is applied during evaluation.

---

## Features

* Interactive command-line gameplay
* Player vs Computer mode
* Move validation
* Win and tie detection
* AI opponent using Minimax with depth limitation

---

## How to Run

### Requirements

* C++ compiler (g++ recommended)

### Steps

```
g++ main.cpp -o game
./game
```

---

## Project Structure

```
.
├── main.cpp
├── report/
│   └── Project_Report.pdf
└── README.md
```

---

## Challenges Faced

* Implementing recursive decision-making using Minimax
* Managing game state during simulation (making and undoing moves)
* Ensuring correct win and tie detection

---

## Learning Outcomes

* Understanding how game trees are explored
* Applying recursion in a practical scenario
* Improving debugging and logical reasoning skills

---

## Limitations

* The depth limit may cause the AI to miss some optimal moves
* All wins and losses are treated equally, without prioritizing faster outcomes
* The game only allows the opponent to move first, and doesn't let the player decide if they wanna let the computer make the first move
* The game doesn't let the oppponent to set a difficulty level (a lower or higher depth level) , for that they will have to change the code, no option provided for that in the terminal after the code is run

---

## Conclusion

This project demonstrates how a classical algorithm like Minimax can be used to simulate decision-making in games. Even with a depth-limited approach, the system is able to provide a challenging opponent and illustrates key concepts in artificial intelligence.

---
