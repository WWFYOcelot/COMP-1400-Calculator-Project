#include <stdio.h> // C standard Library for input/output functions
#include <math.h>  // C math library for math functions 

char initialSelect();	// function prototypes
char advancedSelect();

float checkNum(void);
char checkOperation(char operation, char operations[], int len);
float varSelection();

float bSelection(float num1, char operation, float num2);
float uSelection(float num, char operation);
char eSelection();

float advancedInput();

void clear();

float a = 0;	// variables defined outside of function so that they apply to the entire program
float b = 0;
float c = 0;
float d = 0;
float e = 0;

int main (void) // main function
{
	// intro section
	puts("Welcome to my Command-Line Calculator (CLC)!");
	puts("Developer: Faraan Rashid");
	puts("Version: 3");
	puts("Date: 30th November 2022");
	puts("--------------------------------------------------");

	char select;	 // define variables for later use
	int exit;

	while (select != 'E') { 	// while statement that reruns the program until exit value is entered
	
		select = initialSelect();	// function called to return user selection
					
		if (select != '\n'){	// ensures newline not used in switch statement
			switch (select) { 	// switch case statement for selection options
				case 'B':
					
					puts("Please enter a number."); 	// prompt user for input
					float num1 = checkNum();			// function called to return user input
					
					puts("List of binary operations: addition, subtraction, multiplication, division, remainder, "); 	// relevant information about inputs printed for 
					puts("                           power, maximum, minimum");											// the benefit of the user
					puts("Please enter a binary operation (+, -, *, /, %, P, X, I):");									// prompt user for input
					char binary = getchar();		// receive input from user
					
					puts("Please enter a number."); 	// prompt user for input
					float num2 = checkNum();			// function called to return user input
					
					printf("Result is %.3f.\n", bSelection(num1, binary, num2));	// function called in printf to evaluate inputs, return a result
			
					break;															// use break to exit case
					
				case 'U':					
					
					puts("Please enter a number."); 	// prompt user for input
					float num = checkNum();				// function called to return user input
					
					puts("List of unary operations: square root, logarithm, exponentiaion, ceiling, floor");	// relevant information about inputs printed for the benefit of the user
					puts("Please enter a unary operation (S, L, E, C, F):");									// prompt user for input
					char unary = getchar();		// receive input from user
					
					printf("Result is %.3f.\n", uSelection(num, unary));	// function called in printf to evaluate inputs and return a result, then print result

					break;													// use break to exit case
					
				case 'A':
				
					puts("\nEntering advanced calculator.");	// prints state of calculator
					char aSelect = ' ';							/* selection variable is initialized to an empty space to allow this section to be rerun
																 without this statement, the advanced calculator cannot be reentered since the exit
																 condition will remain true*/
																
					while (aSelect != 'E') {			// loop will repeat the advanced calculator's tasks until the exit condition is met
						aSelect = advancedSelect();		// function provides options and returns user selection 

						if (aSelect != '\n') {
							switch (aSelect) {
								case 'B':
								
									float val1 = advancedInput();    // function receives and returns input from user 
									puts("List of binary operations: addition, subtraction, multiplication, division, remainder, "); 	// relevant information about inputs printed for 
									puts("                           power, maximum, minimum");											// the benefit of the user
									puts("Please enter a binary operation (+, -, *, /, %, P, X, I):");									// prompt user for input
									getchar(); 						// clears input of newline
									char binary = getchar();		// receives input from user 
									float val2 = advancedInput();	// function receives and returns input from user
									
									printf("Result is %.3f.\n", bSelection(val1, binary, val2));	// function called in printf to evaluate inputs and return a result, then print result 
									
									break;		// use break to exit case 
									
								case 'U':
								
									float val = advancedInput();		// function receives and returns input from user
									
									puts("List of unary operations: square root, logarithm, exponentiaion, ceiling, floor");	// relevant information about inputs printed for the benefit of the user
									puts("Please enter a unary operation (S, L, E, C, F):");									// prompt user for input
									char unary = getchar();		// receives input from user
									
									printf("Result is %.3f.\n", uSelection(val, unary));	// function called in printf to evaluate inputs and return a result, then print result
									
									break;		// use break to exit case
									
								case 'E':
								
									puts("Returning to main calculator.");		// prints a statement when user exits advanced calculator
									break;
						
								default:
									puts("Invalid selection for advanced calculator.");		// default statement in case of invalid input 
									clear();												// clear extra inputs
									break;													// use break to exit case 
							}
						}
					}
					
					break;		// use break to exit case
					
				case 'V':
				
					puts("Input a variable.");		// prompts user for input 
					
					char varList[] = {'a', 'b', 'c', 'd', 'e'};		// list of acceptable inputs
					char var;										// variable initialized, input read from user
					scanf("%c", &var);
					var = checkOperation(var, varList, 5);			// function called to evaluate input, returns a valid input 
					
					puts("Enter a number.");	// prompts user for input 
					num = checkNum();			// function is called to receive input from user and return valid input
						
					if (var != '\n') {
						switch (var) {		// switch case statement for variable options
							case 'a':		// each case sets the selected variable to the value that is entered
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
							default:	// default case statement
								puts("Invalid variable. Please try again.");
								clear();	// clear extra inputs
								break;
						}
					
					}
										
					break;			// use break to exit case

				case 'E':
					select = eSelection();	// function is called to run exit statement 
					clear();				// clear extra inputs
					break;					// use break to exit case
					
				default:
					puts("Invalid selection. Please try again.");
			}	// loop will repeat, continuing to prompt the user to select an option, until exit condition is met
		}
	}
} 

float advancedInput() {		// function that allows the user to either enter a number or select a previously define variable value to use
	
	int num;				// define/initialize variable for future use
	int exit = 0;

	puts("Enter n to use a number or v to use a variable.");	// prompt user for input
  
	while (exit != -1) {
		char option = getchar();					// receive input from user 
	
		if (option != '\n') {
			switch (option) {						// switch case statement for selection
				case 'n':	
					puts("Enter a number.");		// prompt user for input
					num = checkNum();				// function called to take and evaluate input, acceptable input is then stored
					return num;						// return input as function value of type float
					exit = -1;						// satisfy loop exit condition 
					break;							// use break to exit case 
				case 'v':								
					num = varSelection();			// call function to return the value of a predefined variable 
					return num;						// return value
					exit = -1;						// satisfy loop exit condition 
					break;							// use break to exit case 
				default:								// default value for switch case. 
					puts("Invalid selection. Select n for a number or v for a variable.");
					clear();	// clear extra inputs
					break;		// use break to exit case 
				}
			}
	}
}

float varSelection() {							// function receives no parameters, returns float value of predefined variable 
	int exit = 0;								// define & initialize sentinel value 
	puts("Enter a variable (a, b, c, d, e)");	// prompt user for input 
	while (exit != -1) {						// code section will repeat until exit condition is met 
		char variable;							// variable initialized, input read from user
		scanf("%c", &variable);
		if (variable != '\n') {			// excludes newline from evaluation 
			switch (variable) {			// switch case statement for selection
				case 'a':			
					return a;			// returns value of predefined variable, or zero if variable is undefined
					exit = -1;			// loop exit condition is satisfied 
					break;				// use break to exit case
				case 'b':
					return b;
					exit = -1;
					break;
				case 'c':
					return c;
					exit = -1;
					break;
				case 'd':
					return d;
					exit = -1;
					break;
				case 'e':
					return e;
					exit = -1;
					break;
				default:
					puts("Invalid variable. Please try again.");
					clear();
					break;
			}
		}
	}
}

char eSelection() {		// function receives no parameters, returns a character 
	puts("\nThanks for using my Simple Calculator. Hope to see you again soon. Goodbye!\n");		// print exit message 
	return 'E';																						// return correct value 
}

void clear() {			// void function to clear extra characters from input line 
	char space;								// variable defined, reads a character from input line 
	int check = scanf("%c", &space);
	if (check == 1 && space != '\n') {		/* function is expecting to read a newline, since one will be left in the input line after an input 
												if there is more than just a newline in the input, the function will execute the next code block*/
	char junk[100000];							// char array defined for future use 
	scanf("%s", junk);}							/* scanf reads string, assigns to char array. This removes any characters from the input buffer.
												this also creates a vulnerability by making it possible to overload the char array with a very 
												large string*/
}

float checkNum() {		// function to ensure inputs are float values, taking a float value as a parameter
	
	int exit = 0;				// define & initialize variable for later use
	float val;
	char space;
	
	while (exit != -1) {					// while loop will keep prompting & accepting inputs until a valid input is entered
	int check = scanf("%f", &val);			// variables set to value of scanf taking a float and a char input
	int check2 = scanf("%c", &space);
	if (check != 1 || check2 != 1 || space != '\n') {	// checks whether or not scanf is taking both inputs & whether the char input is a newline
		clear();
		puts("Incorrect input, try again.");	// if incorrect input is received, the user is prompted
		}						
	else {
		exit = -1;			// if valid input was received, based on the above evaluation, the loop's exit condition is met
		return val;}		// the function returns a valid float value 
	}
}

char checkOperation(char operation, char operations[], int len) { 	/* function to validate operations used in the calculator, taking a character,
																		a character array and an integer representing the length of the character
																		array as parameters */
	int exit = 0;		// sentinel value defined & initialized to a non-sentinel value
	
	while (exit != -1) { 						// repeats until condition is met
		for (int i = 0; i < len; i++) {			// loops through entries in the char array passed into the function
			if (operation == operations[i])		// checks if the character passed into the function is in the char array
				exit = -1;						// satisfies exit condition
		}

		if (exit != -1) {						// checks whether or not exit condition has been satisfied; executes if no
			puts("Reenter operation.");			// prompts user for input, receives input from user
			scanf("%c", &operation);
		}
	}	

	return operation;							// once a usable value has been identified, it is returned as the function value 

}

char advancedSelect() {		// function takes no parameters and returns a character
	// selection options
	puts("\nSelect one of the following items:");
	puts("B) - Binary Mathematical Operations, such as addition and subtraction.");
	puts("U) - Unary Mathematical Operations, such as square root, and log.");
	puts("E) - Exit");
	
	int exit = 0;			// sentinel value defined and initalized for later use
	do {
		char selection = getchar();		// receive input from user 
		if (selection != '\n') {		// ensure newline is not used for selection 
			switch (selection) {		// switch case based on selection 
				case 'B':				// selection will return value that is inputted when a valid value is entered
					return 'B';	 		// return statement 
					exit = -1;			// exit condition for loop satisfied 
					break;				// use break to exit case
				case 'U':
					return 'U';
					exit = -1;
					break;
				case 'E':
					return 'E';
					exit = -1;
					break;
				default:	// default case
					puts("Invalid selection for advanced calculator.");
					clear();
					break;
			}
		} 
	} while (exit != -1); 	// exit condition for loop 
	
}

char initialSelect() { 		// function takes no parameters and returns a character 
	// selection options
	puts("\nSelect one of the following items:");
	puts("B) - Binary Mathematical Operations, such as addition and subtraction.");
	puts("U) - Unary Mathematical Operations, such as square root, and log.");
	puts("A) - Advances Mathematical Operations, using variables, arrays.");
	puts("V) - Define variables and assign them values.");
	puts("E) - Exit");
	
	int exit = 0;			// sentinel value defined and initalized for later use
	do {
		char selection = getchar();		// receive input from user 
		if (selection != '\n') {		// ensure newline is not used for selection 
			switch (selection) {		// switch case based on selection 
				case 'B':				// selection will return value that is inputted when a valid value is entered
					return 'B';	 		// return statement 
					exit = -1;			// exit condition for loop satisfied 
					break;				// use break to exit case
				case 'U':
					return 'U';
					exit = -1;
					break;
				case 'A':
					return 'A';
					exit = -1;
					break;
				case 'V':
					return 'V';
					exit = -1;
					break;
				case 'E':
					return 'E';
					exit = -1;
					break;
				default:			// default case 
					puts("Invalid selection for main calculator. Please try again.");
					clear();
					break;
			}
		} 
	} while (exit != -1); 		// exit condition for loop 
}



float bSelection(float num1, char operation, float num2) {	// function which executes the selection process for binary operations, 
															// takes two floats and a character, which represents the operation entered by the user, as parameters.
															// Function returns an int, which is used to satisfy the exit conditions of loops elsewhere in the program
															
	float result;	// variables defined/initialized for future use
	int exit = 0;
	
	char binaryList[] = {'+', '-', '*', '/', '%', 'P', 'X','I'};	// list of acceptable inputs
	operation = checkOperation(operation, binaryList, 8);			// operation set equal to returned value of function that evaluates input and receives new input if initial input was invalid 			
	
	while (exit != -1) {	// statement will continue to be executed until exit condition is met 
		if (((operation == '/') || (operation == '%')) && (num2 == 0)) {	// if statement checks for invalid mathematical operations
			puts("Invalid operation: Divide by zero.");						// prints an error message
			puts("Reenter second number.");									// prompts user for a new input 
			num2 = checkNum();												// calls function to receive and return new input from user
			}
		else
			exit = -1;	// if input is valid, loop exit condition is met
		}
		
		if (((operation == 'X') || (operation == 'I')) && (num1 == num2)) {		// checks whether two equal numbers are being compared
			puts("First number is equal to second number.");					// prints an appropriate message 
			return num1;														// returns number as function output, since comparison evaluated to two equal numbers 
		}

	
	switch (operation) {	// switch case statement based on operation input
		case '+': 
			result = num1 + num2;						// perform operation
			break;										// use break to end switch case statement
		case '-':
			result = num1 - num2;						// perform operation
			break;										// use break to end switch case statement
		case '*':
			result = num1 * num2;						// perform operation
			break;										// use break to end switch case statement
		case '/':
			result = num1 / num2;						// perform operation; does not account for divide by zero because this is considered an invalid input earlier in the program
			break;										// use break to end switch case statement
		case '%':
			result = (int)num1 % (int)num2;				// perform operation; does not account for divide by zero because this is considered an invalid input earlier in the program
			break;										// use break to end switch case statement							
		case 'P':
			result = pow(num1, num2);					// perform operation
			break;										// use break to end switch case statement
		case 'X':								
			if (num1>num2) 								// compares the values of num1 and num2, giving the larger number as the result
				result = num1;							// does not account for both numbers being equal because entering two equal numbers 
			else if (num2>num1)							// produces an error earlier in the program, forcing the user to enter two different numbers
				result = num2;
			break;										// use break to end switch case statement
		case 'I':
			if (num1<num2) 								// compares the values of num1 and num2, giving the larger number as the result
				result = num1;							// does not account for both numbers being equal because entering two equal numbers 
			else if (num2<num1)							// produces an error earlier in the program, forcing the user to enter two different numbers
				result = num2;							// satisfy exit condition for loop
			break;										// use break to end switch case statement
		default:
			puts("Invalid binary operation. Please try again.");		// error message 		
			clear();													// clear extra inputs
			break;														// use break to exit case 
	}
	
	return result;		// result of operation is returned 

}

float uSelection(float num, char operation) {	// function which executes the selection process for unary operations, 
												// takes a float and a character, which represents the operation entered by the user, as parameters.
												// Function returns an int, which is used to satisfy the exit conditions of loops elsewhere in the program
	
	float result;		// variables defined/initialized for future use 
	int exit = 0;
	
	char unaryList[] = {'S', 'L', 'E', 'C', 'F'}; 			// list of acceptable input values
	operation = checkOperation(operation, unaryList, 5);	// operation set equal to returned value of function that evaluates input and receives new input if initial input was invalid 			
	
	while (exit != -1) {	// statement will continue to be executed until exit condition is met 
		if ((operation == 'S') && (num < 0)) {						// if statement checks for invalid mathematical expressions
			puts("Invalid input: Root of a negative number.");		// prints appropriate error message 
			puts("Reenter number.");								// prompts user for input 
			num = checkNum();										// calls function to receive and return new input from user 
		}
		else if ((operation == 'L') && (num < 1)) {					// if statement checks for invalid mathematical expressions
			puts("Invalid input: Logarithm doesn't exist.");		// prints appropriate error message 
			puts("Reenter number.");								// prompts user for input 
			num = checkNum();										// calls function to receive and return new input from user 
		}
		else				// if neither invalid operation was flagged, exit condition is satisfied 
			exit =-1;		
		
	}
	
	switch (operation) {	 // switch case statement based on operation input 
		case 'S':
			result = sqrt(num);			// perform operation
			break;						// use break to end switch case statement
		case 'L':
			result = log10(num);		// perform operation
			break;						// use break to end switch case statement
		case 'E':				
			result = exp(num);			// perform operation
			break;						// use break to end switch case statement
		case 'C':
			result = ceil(num);			// perform operation
			break;						// use break to end switch case statement
		case 'F':
			result = floor(num);		// perform operation
			break;						// use break to end switch case statement		
		default:
			puts("Invalid unary operation. Please try again.");		// print error message 
			clear();												// clear extra inputs
			break;													// use break to exit case 
	}
	
	return result; 		// result of operation is returned
}
