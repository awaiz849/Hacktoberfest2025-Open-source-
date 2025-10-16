#include <stdio.h>
#include <ctype.h>   // for isdigit()
#include <math.h>    // for pow()
#include <stdlib.h>  // for exit()

#define MAX 10

int stack[MAX];
char post_expr[MAX];
int top = -1;

// Push element onto stack
void push(int val) {
    if (top == MAX - 1) {
	printf("Stack Overflow\n");
	exit(1);
    }
    stack[++top] = val;
}

// Pop element from stack
int pop() {
    if (top == -1) {
	printf("Stack Underflow\n");
	exit(1);
    }
    return (stack[top--]);
}

// Evaluate postfix expression
int eval_Postfix() {
    int i = 0;
    char ch;
    int val1, val2, result;

    while ((ch = post_expr[i++]) != '\0') {
	if (isdigit(ch)) {
	    push(ch - '0');  // Convert char digit to int
	}
	else {
	    // Pop two operands
	    val2 = pop();
	    val1 = pop();

	    switch (ch) {
		case '+': result = val1 + val2; break;
		case '-': result = val1 - val2; break;
		case '*': result = val1 * val2; break;
		case '/': result = val1 / val2; break;
		case '%': result = val1 % val2; break;
		default:
		    printf("Invalid operator: %c\n", ch);
		    exit(1);
	    }
	    push(result);
	}
    }
    return (pop());
}

int main() {
    int result;

    printf("Enter postfix expression (single digit operands): ");
    scanf("%s", post_expr);

    result = eval_Postfix();
    printf("Result = %d\n", result);

    return 0;
}
