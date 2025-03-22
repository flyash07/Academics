# Lexical Analyzer & Parser Project

## Description
This project implements a simple compiler frontend consisting of:
- Lexical Analyzer
- Symbol Table Management
- Parser

It tokenizes input, identifies keywords, operators, special symbols, and parses input according to defined rules.

---

## Files
- `findkeywords.c` : Identifies keywords from input.
- `remove.c` : Removes unwanted characters like comments and whitespace.
- `checksymbols.c` : Checks for operators and special symbols.
- `token.c` : Manages token structure.
- `symbol_table.c` : Handles symbol table creation and lookup.
- `la.c` : The lexical analyzer driver.
- `parser.c` : Basic parser implementation.

---

## Compilation

```bash
gcc -Wall -Wextra -std=c11 findkeywords.c remove.c checksymbols.c token.c symbol_table.c la.c parser.c -o compiler
