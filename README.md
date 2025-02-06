# get_next_line

## 📌 Description

This project involves writing a C function, get_next_line, which reads a line from a file descriptor each time it's called. It handles multiple file descriptors and works with varying buffer sizes. The focus is on efficient memory management, avoiding leaks, and using static variables.

## 📋 Objectives

- Learn about the use of **static** variables in C.
- Properly manage dynamic memory to avoid *memory leaks*.
- Implement an efficient solution for reading files line by line.
- Optimize the number of `read()` calls to improve performance.

## 🚀 Usage

### 📥 Compilation

To compile the function along with a test program, use:

```sh
cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```




