# Simple Line Editor in C

## Team Members

- Sirisha K
- Sujay VS

## Features Implemented

1. Insert a line
2. Delete a line
3. Display the document

## Data Structure

The editor uses an array of strings.

The array stores each line of the document, while lineCount
keeps track of the number of lines currently stored.

An array was chosen because it is simple to implement and
works well for a small text document.

## Commands

- insert <number>
- delete <number>
- display
- help
- exit

## Compilation

```bash
gcc main.c -o editor