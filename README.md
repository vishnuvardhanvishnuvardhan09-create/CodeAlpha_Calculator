# CodeAlpha_Calculator - Basic Calculator in C

Developed as part of the CodeAlpha C Programming Internship

---

## 📌 Project Overview

This project is a console-based arithmetic calculator written in standard C (C99+). It provides a clean, menu-driven interface enabling users to execute essential arithmetic operations—Addition, Subtraction, Multiplication, and Division—repeatedly until choosing to exit.

The program emphasizes robust software engineering practices, featuring defensive input validation, buffer clearing, prevention of infinite loops upon non-numeric input, and safe handling of edge cases like division by zero.

---

## ✨ Features

- **Menu-Driven Interface:** Built with a `do-while` loop and `switch-case` construct for structured flow control.
- **Modular Architecture:** Dedicated, self-contained functions for each arithmetic operation (`add`, `subtract`, `multiply`, `divide`).
- **High Precision:** Uses `double` precision floating-point numbers formatted cleanly to 2 decimal places.
- **Defensive Input Handling:**
  - Automatically cleans `stdin` buffer to eliminate infinite loops caused by non-numeric inputs (e.g., entering `"abc"` instead of numbers).
  - Handles invalid menu choices gracefully with informative feedback.
  - Intercepts division by zero with custom error messaging without program crashes.
- **Zero Compiler Warnings:** Fully compliant with `-Wall -Wextra` GCC flags.

---

## 📂 Project Structure

```text
CodeAlpha_Calculator/
├── calculator.c       # Source code containing all functions & main loop
├── README.md          # Comprehensive documentation and run guide
└── .gitignore         # Ignores build artifacts and executables
```

---

## 🛠️ Compilation and Execution

### Prerequisites
You need a C compiler installed, such as `gcc` (MinGW / MSYS2 on Windows, or standard GCC on Linux/macOS).

### 1. Compile
Open your terminal/command prompt in the `CodeAlpha_Calculator` directory and execute:

```bash
gcc -Wall -Wextra -o calculator calculator.c
```

### 2. Run
- **On Windows:**
  ```powershell
  .\calculator.exe
  ```
- **On Linux / macOS:**
  ```bash
  ./calculator
  ```

---

## 🖥️ Sample Outputs

### 1. Addition & Subtraction
```text
=========================================
               CALCULATOR MENU           
=========================================
  1. Addition
  2. Subtraction
  3. Multiplication
  4. Division
  5. Exit
=========================================
Enter your choice (1-5): 1

--- Addition ---
Enter first number: 10
Enter second number: 5

>>> Result: 10.00 + 5.00 = 15.00
```

### 2. Subtraction & Multiplication
```text
Enter your choice (1-5): 2

--- Subtraction ---
Enter first number: 10
Enter second number: 5

>>> Result: 10.00 - 5.00 = 5.00

Enter your choice (1-5): 3

--- Multiplication ---
Enter first number: 10
Enter second number: 5

>>> Result: 10.00 * 5.00 = 50.00
```

### 3. Division & Handling Division by Zero
```text
Enter your choice (1-5): 4

--- Division ---
Enter first number (dividend): 10
Enter second number (divisor): 5

>>> Result: 10.00 / 5.00 = 2.00

Enter your choice (1-5): 4

--- Division ---
Enter first number (dividend): 10
Enter second number (divisor): 0

>>> [Error]: Division by zero is undefined! Please choose a non-zero divisor.
```

### 4. Handling Invalid Menu Choice & Invalid Non-Numeric Input
```text
Enter your choice (1-5): 9

>>> [Error]: Invalid choice (9)! Please select a number from 1 to 5.

Enter your choice (1-5): abc
[Error]: Invalid input! Please enter a valid number.
Enter your choice (1-5): 5

Thank you for using the Calculator. Goodbye!
```

---

## 📄 License
This project is open-source and intended for educational and internship evaluation purposes.
