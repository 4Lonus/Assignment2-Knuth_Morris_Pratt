# Assignment2-Knuth_Morris_Pratt

## OS, Programming Language & Other

- OS: Windows 11
- Programming Language: C++
- IDE VisualStudio Code

## How to Run

### Compile

Using g++ in console, navigate to the fodler in which the main.cpp and main.h are located (using "cd folder_name" or "cd ../" to open a folder or go back), and then run:

```bash
g++ main.cpp -o main
```

It should create a new main.exe file inside the same folder.

### Run

Within the same folder run:

```bash
./main
```

## Algorithm Explanation

This project implements the Knuth-Morris-Pratt (KMP) string matching algorithm. The algorithm searches for a word inside a larger given text.

The intuitive aproach would tell us to just go character by character and when we find a matching first character, just check its following characters. But this is inneficient.

This algorithm, improves by keeping information of the previous matches, such that we start looking for the next possible match position. This reduces some unnecesarry comparisons, making the algorithm, generally more efficient.

## Resuts

When aplying the algoritm into two different texts, with the same Keyword, the first text did contained the word but the second one did not.
