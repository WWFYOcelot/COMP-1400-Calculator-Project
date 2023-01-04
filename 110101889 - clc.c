/*
COMP-1400 Assignment 1
Faraan Rashid 
110101889
*/

#include <stdio.h> // C standard Library for input/output functions
#include <math.h>

float checkNum(float num);
char checkOp(char op[], int len);
float varSelection();
int bSelection(float num1, char operation, float num2);
int uSelection(float num, char operation);

float a, b, c, d, e;

int main (void) // main function
{
	// intro section
	puts("Welcome to my Command-Line Calculator (CLC)!");
	puts("Developer: Faraan Rashid");
	puts("Version: 2");
	puts("Date: 18th November 2022");
	puts("--------------------------------------------------");

	// selection options
	puts("\nSelect one of the following items:");
	puts("B) - Binary Mathematical Operations, such as addition and subtraction.");
	puts("U) - Unary Mathematical Operations, such as square root, and log.");
	puts("A) - Advances Mathematical Operations, using variables, arrays.");
	puts("V) - Define variables and assign them values.");
	puts("E) - Exit");

	char select;	 // define variables for later use
	int exit;

	while (select != 'E') { 	// while statement that reruns the program until exit value is entered
	
		fflush(stdin); 	// clear input buffer to ensure correct values are used when scanning				
		
		char inputList[] = {'B', 'U', 'A', 'V', 'E'};	 // list of acceptable input values
		select = checkOp(inputList, 5);					 // function called to take and evaluate input, acceptable input is then stored
		
		exit = 0;	 // exit initialized for use as a sentinel
		
		switch (select) { 	// switch case statement for selection options
			case 'B':
				
				while (exit != -1) { 	// while statement that reruns this code section until the exit condition is met	
				
					puts("Please enter the first number:");		// prompt user for input
					float num1 = checkNum(num1);				// function called to take and evaluate input, input stored
					
					puts("List of binary operations: addition, subtraction, multiplication, division, remainder, "); 	// relevant information about inputs printed for 
					puts("                           power, maximum, minimum");											// the benefit of the user
					puts("Please enter a binary operation (+, -, *, /, %, P, X, I):");									// prompt user for input
					
					char binaries[] = {'+', '-', '*', '/', '%', 'P', 'X','I'};	 // list of acceptable input values
					char operation = checkOp(binaries, 8);						 // function called to take and evaluate input, acceptable input is then stored

					puts("Please enter the second number:");	// prompt user for input
					float num2 = checkNum(num2);				// function called to take and evaluate input, acceptabel input is then stored
				
					if (((operation == '/') || (operation == '%')) && (num2 == 0)) {		// evaluates inputs for invalid mathematical expressions, prompts user to reenter data
						puts("Invalid operation: Divide by zero. Please try again.");
						continue;
					}
					
					if (((operation == 'X') || (operation == 'I')) && (num1 == num2)) {
						puts("Invalid operation: First number equal to second number. Please try again.");
						continue;
					}

					exit = bSelection(num1, operation, num2);	// calls function to evaluate inputs, sets exit to returned value to satisfy loop exit condition
					
				}
			 
				puts("Please select your option ( B , U , A , V , E )");	// prompts user for input, which can be entered once the loop restarts
				break;														// use break to exit case
				
			case 'U':					
				while (exit != -1) {	 // while statement that reruns this code section until the exit condition is met
					
					puts("Please enter a number."); 	// prompt user for input
					float num = checkNum(num);		    // function called to take and evaluate input, acceptable input is then stored
					
					puts("List of unary operations: square root, logarithm, exponentiaion, ceiling, floor");	// relevant information about inputs printed for the benefit of the user
					puts("Please enter a unary operation (S, L, E, C, F):");									// prompt user for input
					char unaries[] = {'S', 'L', 'E', 'C', 'F'}; 	// list of acceptable input values
					char operation = checkOp(unaries, 5);			// function called to take and evaluate input, acceptable input is then stored

					if ((operation == 'S') && (num < 0)) {													// evaluates inputs for invalid mathematical expressions, prompts user to reenter data
						puts("Invalid operation: Square root of a negative number. Please try again.");\
						continue;
					}
					
					if ((operation == 'L') && (num < 1)) {
						puts("Invalid operation: Log of a number less than 1. Please try again.");\
						continue;
					}
					
					exit = uSelection(num, operation);	 // calls function to evaluate inputs, sets exit to returned value to satisfy loop exit condition
					
				}
				puts("\nPlease select your option ( B , U , A , V , E )"); 		// prompts user for input, which can be entered once the loop restarts
				break;															// use break to exit case
			case 'A':
							
				char aSelect = ' ';	 // define variable for later use
			
				// welcome screen, selection options
				puts("Entering advanced calculator.");
				puts("B) - Binary Mathematical Operations, such as addition and subtraction.");
				puts("U) - Unary Mathematical Operations, such as square root, and log.");
				puts("E) - Return to main Calculator");
								
				while (aSelect != 'E') {	 // while statement that keeps program in advanced calculator until exit condition is met
					
					
					char aInputs[] = {'B', 'U', 'E'};	 // list of acceptable input values
					aSelect = checkOp(aInputs, 3);	 	 // function called to take and evaluate input, acceptable input is then stored
					
					if (aSelect != '\n') { 		// checks input for newline to ensure it isn't being read as input
						switch (aSelect) {		// switch case statement for selection options
							
							while (exit != -1) {	// while statement that reruns this code section until the exit condition is met
								
								case 'B':
									puts("Enter the first number.");			// prompt user for input
									float val1 = varSelection(a, b, c, d, e); 	// function called to take and evaluate input, acceptable input is then stored
									
									puts("List of binary operations: addition, subtraction, multiplication, division, remainder, "); 	// relevant information about inputs printed for the 
									puts("                           power, maximum, minimum");											// benefit of the user
									puts("Please enter a binary operation (+, -, *, /, %, P, X, I):");		// prompt user for input
									char binaries[] = {'+', '-', '*', '/', '%', 'P', 'X','I'};				// list of acceptable inputs
									char binaryOp = checkOp(binaries, 8);									// function called to take and evaluate input, acceptable input is then stored
									
									puts("Enter the second number.");				// prompt user for input
									float val2 = varSelection(a, b, c, d, e);		// function called to take and evaluate input, acceptable input is then stored
									
									if (((binaryOp == '/') || (binaryOp == '%')) && (val2 == 0)) {		// evaluates inputs for invalid mathematical expressions, prompts user to reenter data
										puts("Invalid operation: Divide by zero. Please try again.");
										continue;
									}
									
									if (((binaryOp == 'X') || (binaryOp == 'I')) && (val1 == val2)) {
										puts("Invalid operation: First number equal to second number. Please try again.");
										continue;
									}
									
									exit = bSelection(val1, binaryOp, val2); 	// calls function to evaluate inputs, sets exit to returned value to satisfy loop exit condition 

								}

								puts("\nPlease select your option ( B , U , E )");		// prompts user for input, which can be entered once the loop restarts 
								break;													// use break to exit case
								
							case 'U':
							
								while (exit != -1) {	// while statement that reruns this code section until the exit condition is met
								
									puts("Enter a number.");					// prompt user for input
									float val = varSelection(a, b, c, d, e);	// function called to take and evaluate input, acceptable input is then stored
									
									puts("List of unary operations: square root, logarithm, exponentiaion, ceiling, floor");	// relevant information about inputs printed for the benefit of the user 
									puts("Please enter a unary operation (S, L, E, C, F):");									// list of acceptable inputs 
									char unaries[] = {'S', 'L', 'E', 'C', 'F'};		// list of acceptable input values 
									char oper = checkOp(unaries, 5);				// function called to take and evaluate input, acceptable input is then stored
									
									if ((oper == 'S') && (val < 0)) {		// evaluates inputs for invalid mathematical expressions, prompts user to reenter data 
										puts("Invalid operation: Square root of a negative number. Please try again.");	
										continue;
									}
									
									if ((oper == 'L') && (val < 1)) {
										puts("Invalid operation: Log of a number less than 1. Please try again.");
										continue;
									}
									
									exit = uSelection(val, oper);	// calls function to evaluate inputs, sets exit to returned value to satisfy loop exit condition
									
								}
								
								puts("\nPlease select your option ( B , U , E )");		// prompts user for input, which can be entered once the loop restarts 
								break; 													// use break to exit case
								
							case 'E':
								puts("Returning to main calculator.");		// entering 'E' will exit the advanced calculator loop, causing the program to return to the main calculator 
								break;										// use break to exit case
							
							default:													// default case statement. Technically unnecessary since input validation ensures only valid inputs can be entered.
								puts("Invalid input. Please try again.");				// prompts user to reenter data
								puts("\nPlease select your option ( B , U , E )");		// prompts user for input, which can be entered once the loop restarts 
								break;													// use break to exit case
							
						}
					}
					// loop will repeat, continuing to prompt the user to select an option, until exit condition is met 
				}
				
				puts("\nPlease select your option ( B , U , A , V , E )");		// prompts user for input, which can be entered once the loop restarts 
				break;															// use break to exit case
				
			case 'V':
			
				puts("Input a variable.");		// prompts user for input 
				
				fflush(stdin);									// clears input buffer to ensure right input is being used
				char varList[] = {'a', 'b', 'c', 'd', 'e'};		// list of acceptable inputs
				char variable = checkOp(varList, 5);			// function called to take and evaluate input, acceptable input is then stored
				
				puts("Enter a number.");		// prompts user for input
				
				float num = checkNum(num);		// function called to take and evaluate input, acceptable input is then stored
				
				switch (variable) {		// switch case statement for variable options
					case 'a':			// each case sets the selected variable to the value that is entered
						a = num;					 
						break;
					case 'b':
						b = num;
						break;
					case 'c':
						c = num;
						break;
					case 'd':
						d = num;
						break;
					case 'e':
						e = num;
						break;
					default:	// default case statement. Technically unnecessary since input validation ensures only valid inputs can be entered.
						puts("Invalid input. Please try again.");
				}
				
				puts("\nPlease select your option ( B , U , A , V , E )");	
				break;												// use break to exit case
			case 'E':
				puts("\nThanks for using my Simple Calculator. Hope to see you again soon. Goodbye!\n");		// output based on selection
				break;																						// use break to exit case
			
			default:	// default case statement. Technically unnecessary since input validation ensures only valid inputs can be entered.
				puts("Invalid input. Please try again.");
				puts("\nPlease select your option ( B , U , A , V , E )");
		}	// loop will repeat, continuing to prompt the user to select an option, until exit condition is met
	}
} 



float checkNum(float num) {		// function to ensure inputs are float values, taking a float value as a parameter
	
	int exit = 0;				// define & initialize variable for later use
	
	while (exit != -1) {		// while loop will keep prompting & accepting inputs until a valid input is entered
	char space;										// variable defined
	int check = scanf("%f%c", &num, &space);		// variable set to value of scanf taking a float and a char input
	if (check != 2 || space != '\n'){				// checks whether or not scanf is taking both inputs & whether the char input is a newline
		printf("Incorrect input, try again.\n");	// if incorrect input is received, the user is prompted
		fflush(stdin);								// clears input buffer
		char junk = getchar();						// receives any extra characters as a redundancy
		}						
	else {
		exit = -1;			// if valid input was received, based on the above evaluation, the loop's exit condition is met
		return num;}		// the function returns a valid float value 
	}
}

char checkOp (char op[], int len) {		// function to validate inputs based on a list of valid inputs, takes a list of characters and the length of the list as inputs
	
	int exit = 0;	// variables defined/initialized for future use 
	char space;
	char oper;
	
	do {											// do while ensures code is run at least once
		int check = scanf("%c%c", &oper, &space);	// variable defined as scanf receiving input from two chars
		
		if (check != 2 || space != '\n') {			// checks whether or not scanf is taking both inputs & whether the second input is a newline					// receives any leftover characters 
			fflush(stdin);							// clears input buffer
			char junk = getchar();					// stores extra characters as a redundancy
			exit = 0;								// sets sentinel value accordingly
		}
		else {										
			for (size_t i = 0; i < len; i++) {		// if a single character input was received, a for loop is used to check it 
				if (oper == op[i])					// against the list of acceptable values passed into the function
					exit = -1;			// if input is deemed valid, the exit condition is met
			}
		}
		
		if (exit != -1)								// prints an error message and prompts the user for another input if the exit condition is not met
			puts("Invalid input, try again.");

	} while(exit != -1);
	return oper; 			// returns the inputted character if it is an acceptble input 
}

float varSelection() {		// function that allows the user to either enter a number or select a previously define variable value to use
	
	int num;				// define/initialize variable for future use
	int exit = 0;

	puts("Enter n to use a number or v to use a variable.");	// prompt user for input
  
		
		fflush(stdin);						// clear buffer to ensure newline is not taken as an input
		char options[] = {'n', 'v'};		// list of acceptable inputs
		char option = checkOp(options, 2);	// function called to take and evaluate input, acceptable input is then stored
	
		switch (option) {					// switch case statement for selection
			case 'n':
				fflush(stdin);						// clear buffer to ensure newline is not taken as an input
				puts("Enter a number.");			// prompt user for input
				num = checkNum(num);				// function called to take and evaluate input, acceptable input is then stored
				return num;							// return input as function value of type float
				break;
			case 'v':
				fflush(stdin);									// clear buffer to ensure newline is not taken as an input
				puts("Enter a variable (a, b, c, d, e)");		// prompt user for input 
				char varList[] = {'a', 'b', 'c', 'd', 'e'};		// list of acceptable inputs 
				char variable = checkOp(varList, 5);			// function called to take and evaluate input, acceptable input is then stored
			
				switch (variable) {			// switch case statement for selection
					case 'a':			
						return a;			// returns value of predefined variable, or zero if variable is undefined
						break;				// use break to exit case
					case 'b':
						return b;
						break;
					case 'c':
						return c;
						break;
					case 'd':
						return d;
						break;
					case 'e':
						return e;
						break;
				}
			default:								// default value for switch case. Technically not necessary because of input validation
				puts("Invalid input. Try again.");
		}
	
}

int bSelection(float num1, char operation, float num2) {	// function which executes the selection process for binary operations, 
															// takes two floats and a character, which represents the operation entered by the user, as parameters.
															// Function returns an int, which is used to satisfy the exit conditions of loops elsewhere in the program
															
	float result;	// variables defined/initialized for future use
	int exit = 0;
	
	switch (operation) {	// switch case statement based on operation input
		case '+': 
			result = num1 + num2;																// perform operation
			printf("The result of %.2f %c %.2f is %.2f.\n", num1, operation, num2, result);		// print result
			exit = -1;																			// satisfy exit condition for loop
			break;																				// use break to end switch case statement
		case '-':
			result = num1 - num2;																// perform operation
			printf("The result of %.2f %c %.2f is %.2f.\n", num1, operation, num2, result);		// print result
			exit = -1;																			// satisfy exit condition for loop
			break;																				// use break to end switch case statement
		case '*':
			result = num1 * num2;																// perform operation
			printf("The result of %.2f %c %.2f is %.2f.\n", num1, operation, num2, result);		// print result
			exit = -1;																			// satisfy exit condition for loop
			break;																				// use break to end switch case statement
		case '/':
			result = num1 / num2;																// perform operation; does not account for divide by zero because this is considered an invalid input earlier in the program
			printf("The result of %.2f %c %.2f is %.2f.\n", num1, operation, num2, result);		// print result
			exit = -1;																			// satisfy exit condition for loop
			break;																				// use break to end switch case statement
		case '%':
			result = (int)num1 % (int)num2;														// perform operation; does not account for divide by zero because this is considered an invalid input earlier in the program
			printf("The remainder of %.2f / %.2f is %.2f.\n", num1, num2, result);				// print result
			exit = -1;																			// satisfy exit condition for loop
			break;																				// use break to end switch case statement							
		case 'P':
			result = pow(num1, num2);															// perform operation
			printf("The result of %.2f %c %.2f is %.2f.\n", num1, operation, num2, result);		// print result
			exit = -1;																			// satisfy exit condition for loop
			break;																				// use break to end switch case statement
			
		case 'X':								
			if (num1>num2) 										// compares the values of num1 and num2, giving the larger number as the result
				result = num1;									// does not account for both numbers being equal because entering two equal numbers 
			else if (num2>num1)									// produces an error earlier in the program, forcing the user to enter two different numbers
				result = num2;
			printf("The bigger number is %.2f.\n", result);		// print result
			exit = -1;											// satisfy exit condition for loop
			break;												// use break to end switch case statement
			
		case 'I':
			if (num1<num2) 										// compares the values of num1 and num2, giving the larger number as the result
				result = num1;									// does not account for both numbers being equal because entering two equal numbers 
			else if (num2<num1)									// produces an error earlier in the program, forcing the user to enter two different numbers
				result = num2;
			printf("The smaller number is %.2f.\n", result);	// print result
			exit = -1;											// satisfy exit condition for loop
			break;												// use break to end switch case statement
	}
	
	return exit;		// int value returned to satisfy exit condition of loops earlier in the program

}

int uSelection(float num, char operation) {		// function which executes the selection process for unary operations, 
												// takes a float and a character, which represents the operation entered by the user, as parameters.
												// Function returns an int, which is used to satisfy the exit conditions of loops elsewhere in the program
	
	float result;		// variables define/initialized for future use 
	int exit = 0;
	
	switch (operation) {	 // switch case statement based on operation input 
		case 'S':
			result = sqrt(num);											// perform operation
			printf("Square root of %.2f is %.2f.\n", num, result);				// print result
			exit = -1;													// satisfy exit condition for loop
			break;														// use break to end switch case statement
		case 'L':
			result = log10(num);										// perform operation
			printf("The log of %.2f is %.2f.\n", num, result);			// print result
			exit = -1;													// satisfy exit condition for loop
			break;														// use break to end switch case statement
		case 'E':				
			result = exp(num);											// perform operation
			printf("e^%.2f is %.2f.\n", num, result);					// print result
			exit = -1;													// satisfy exit condition for loop
			break;														// use break to end switch case statement
		case 'C':
			result = ceil(num);											// perform operation
			printf("The ceiling of %.2f is %.2f.\n", num, result);		// print result
			exit = -1;													// satisfy exit condition for loop
			break;														// use break to end switch case statement
		case 'F':
			result = floor(num);										// perform operation
			printf("The floor of %.2f is %.2f.\n", num, result);		// print result
			exit = -1;													// satisfy exit condition for loop
			break;														// use break to end switch case statement		
	}
	
	return exit; 		// int value returned to satisfy exit condition of loops earlier in the program
}