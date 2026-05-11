This project compares the assebmly code generated from `hexdump.c` using three GCC optimization levels:

- `-O0`
- `-O1`
- `-O3`

The source program reads a binary file in 16-byte blocks and prints:
- the hexadecimal offset,
- hexadecimal byte values,
- and printable ASCII characters.

Because the program contains loops, condiitonals, formatted output, and file operations, it is useful for observing the effects of compiler optimization.

---

# `-O0` Analysis

The `-O0` assembly output contains little to no optimization.

Observations:
- more instructions overall,
- more stack memory usage,
- more variable loads and stores to memory,
- loops and conditionals closely match the original C source code.

This version is the easiest to read because the compiler preserves the original structure of the program. However, it is less efficient due to unnecessary memory operations and reduced register optimization.

---

# `-O1` Analysis

The `-O1` optimization level introduces moderate optimization.

Characteristics observed:
- reduced redundant instructions,
- improved register usage,
- simplified control flow,
- fewer repeated memory accesses.

Compared to `-O0`, the assembly becomes shorter and more efficient while still remaining relatively understandable.

This optimization level balances readability and performance.

---

# `-O3` Analysis

The `-O3` optimization level applies aggressive optimization techniques focused on performance.

Characteristics observed:
- more compact instruction sequences,
- heavier register usage,
- reordered instructions,
- tighter loop structures,
- reduced unnecessary branching.

Compared to `-O0` and `-O1`, the generated assembly is significantly harder to follow because the compiler prioritizes execution speed rather than readability.

The resulting assembly code no longer closely resembles the original C source structure.

---

# Comparison

The primary difference between optimization levels is the tradeoff between readability and efficiency.

`-O0` prioritizes debugging and readability. The generated assembly follows the original C code closely but includes many unnecessary instructions and memory accesses.

`-O1` begins improving performance by simplifying operations and using registers more effectively.

`-O3` focuses heavily on execution efficiency. It minimizes redundant operations and improves instruction flow, but the generated assembly becomes much more difficult to analyze manually.

As optimization increases:
- instruction count generally decreases,
- register usage increases,
- and code readability decreases.

---

# Final Understanding

Compiler optimization significantly changes the generated assembly code.

Lower optimization levels preserve readability and debugging simplicity, while higher optimization levels improve execution performance by reducing unnecessary operations and simplifying instruction flow.