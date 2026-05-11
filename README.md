# CMSC-313-Project-3
Project 3 deals with C-Language, ASM and Optimization

The whole purpose of this project is to create a C-language program that generates a hexadecimal dump of a binary file and to analyze how different compiler optimization levels affect the generated assembly code.

This project majorly demonstrates
- file input/output in C,
- hexadecimal and ASCII formatting,
- command-line argument processing,
- and the impact of compiler optimizations on assembly generation

Each line of the program contains:
1. the hexadecimal offset/address,
2. sixteen hexadecimal byte values,
3. and the ASCII representation of those bytes.

Non-printable ASCII characters are replaced with a `.` character.