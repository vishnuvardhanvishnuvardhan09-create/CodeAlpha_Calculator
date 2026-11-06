/**
 * ============================================================================
 * Project: CodeAlpha C Programming Internship
 * Task 1: Basic Calculator Program in C
 * File: calculator.c
 * Description: A menu-driven console calculator supporting addition,
 *              subtraction, multiplication, and division. Implements robust
 *              input validation, buffer clearing, and edge-case handling.
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/* Function Prototypes for Arithmetic Operations */
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

/* Function Prototypes for UI and Input Handling */
void displayMenu(void);
void clearInputBuffer(void);
int getMenuChoice(void);
double getDoubleInput(const char *prompt);

int main(void) {
    int choice;
    double num1, num2, result;

    printf("====================================================\n");
    printf("       WELCOME TO THE CODEALPHA C CALCULATOR        \n");
    printf("====================================================\n");

    /* Main calculation loop: runs until user selects option 5 (Exit) */
    do {
        displayMenu();
        choice = getMenuChoice();

        switch (choice) {
            case 1: /* Addition */
                printf("\n--- Addition ---\n");
                num1 = getDoubleInput("Enter first number: ");
                num2 = getDoubleInput("Enter second number: ");
                result = add(num1, num2);
                printf("\n>>> Result: %.2f + %.2f = %.2f\n", num1, num2, result);
                break;

            case 2: /* Subtraction */
                printf("\n--- Subtraction ---\n");
                num1 = getDoubleInput("Enter first number: ");
                num2 = getDoubleInput("Enter second number: ");
                result = subtract(num1, num2);
                printf("\n>>> Result: %.2f - %.2f = %.2f\n", num1, num2, result);
                break;

            case 3: /* Multiplication */
                printf("\n--- Multiplication ---\n");
                num1 = getDoubleInput("Enter first number: ");
                num2 = getDoubleInput("Enter second number: ");
                result = multiply(num1, num2);
                printf("\n>>> Result: %.2f * %.2f = %.2f\n", num1, num2, result);
                break;

            case 4: /* Division */
                printf("\n--- Division ---\n");
                num1 = getDoubleInput("Enter first number (dividend): ");
                num2 = getDoubleInput("Enter second number (divisor): ");

                /* Edge-case check: Division by zero */
                if (num2 == 0.0) {
                    printf("\n>>> [Error]: Division by zero is undefined! Please choose a non-zero divisor.\n");
                } else {
                    result = divide(num1, num2);
                    printf("\n>>> Result: %.2f / %.2f = %.2f\n", num1, num2, result);
                }
                break;

            case 5: /* Exit */
                printf("\nThank you for using the Calculator. Goodbye!\n");
                break;

            default: /* Invalid choice handling */
                printf("\n>>> [Error]: Invalid choice (%d)! Please select a number from 1 to 5.\n", choice);
                break;
        }

    } while (choice != 5);

    return 0;
}

/**
 * Displays the calculator menu options to the user.
 */
void displayMenu(void) {
    printf("\n=========================================\n");
    printf("               CALCULATOR MENU           \n");
    printf("=========================================\n");
    printf("  1. Addition\n");
    printf("  2. Subtraction\n");
    printf("  3. Multiplication\n");
    printf("  4. Division\n");
    printf("  5. Exit\n");
    printf("=========================================\n");
}

/**
 * Clears remaining characters from the standard input stream
 * up to the newline character or EOF, preventing input buffer pollution.
 */
void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        /* Discard characters */
    }
}

/**
 * Prompts the user for a menu choice and validates integer input.
 * Handles non-numeric inputs gracefully without infinite loops.
 *
 * @return Validated integer entered by the user.
 */
int getMenuChoice(void) {
    int choice;
    while (1) {
        printf("Enter your choice (1-5): ");
        int status = scanf("%d", &choice);

        if (status == 1) {
            clearInputBuffer();
            return choice;
        } else if (status == EOF) {
            /* If EOF is reached (e.g., stdin closed), exit gracefully */
            printf("\nInput stream ended. Exiting...\n");
            return 5;
        } else {
            printf("[Error]: Invalid input! Please enter a valid number.\n");
            clearInputBuffer();
        }
    }
}

/**
 * Prompts the user for a numerical (double) value and validates input.
 * If non-numeric characters are entered, the buffer is cleared and the
 * user is re-prompted.
 *
 * @param prompt Text prompt shown to the user.
 * @return Validated double precision number.
 */
double getDoubleInput(const char *prompt) {
    double value;
    while (1) {
        printf("%s", prompt);
        int status = scanf("%lf", &value);

        if (status == 1) {
            clearInputBuffer();
            return value;
        } else if (status == EOF) {
            /* Default to 0.0 on EOF to prevent hang */
            return 0.0;
        } else {
            printf("[Error]: Invalid input! Please enter a valid numerical value.\n");
            clearInputBuffer();
        }
    }
}

/**
 * Adds two numbers.
 */
double add(double a, double b) {
    return a + b;
}

/**
 * Subtracts the second number from the first number.
 */
double subtract(double a, double b) {
    return a - b;
}

/**
 * Multiplies two numbers.
 */
double multiply(double a, double b) {
    return a * b;
}

/**
 * Divides the first number by the second number.
 */
double divide(double a, double b) {
    return a / b;
}
