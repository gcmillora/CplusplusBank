//AMDG

//Standard library used
#include<iostream>
#include<cstdlib>
#include<sstream>
 
using namespace std; 

//Struct used for stack and queue representation
typedef struct myList {
	string expression;
	struct myList* next;
}myList;

//Function declarations

//Utility function
char menu(char ch);
void programDescription();
void programGuidelines();

//Function that does the main operations
void evaluateExpression();

//Functions for common stack and queue operations
myList* pushStack (myList* myStack, string top);
myList* enqueueQueue(myList* myQueue, string top);
myList* popDequeue(myList* myTempList);

//Main function
int main() {
	
	//While-loop that runs until the user terminates the program
	while(1) {
		
		
		//Calls the menu() function which shows the program's interface to the user. Stores the user's choice to the char variable ch
		char ch = menu(ch);
		
		//Switch-case for the user's desired action
		switch(toupper(ch)) {
			case 'P':
				programDescription();
				break;
			case 'E':
				evaluateExpression();
				break;
			case 'G':
				programGuidelines();
				break;
			case 'X':
				printf("Auf Wiedersehen!\n");
				return 0;
			default:
				printf("Please choose a valid choice!\n");
				system("pause");
				break;
		}
    }
}

//Function that prompts the main interface of the program
char menu(char ch) {
	
    system("cls");
	cout << "Welcome to this Evaluator program! Please choose an action to perform..." << endl;
	cout << "\t[P] Program Description" << endl;
	cout << "\t[E] Evaluate Expressions(s)" << endl;
	cout << "\t[G] Program Guidelines" << endl; 
	cout << "\t[X] Exit" << endl;
	cout << "Choice: ";
	cin >> ch; 
	fflush(stdin);
	
	return ch; 
}

//Function that shows users the description of the program
void programDescription() {
	
	system("cls");
	cout << "---PROGRAM DESCRIPTION---" << endl;
	cout << "=========================" << endl;
	cout << "Program by:" << endl;
	cout << "\tManabat, Daniel Gabriel, 2019 - 60012" << endl; 
	cout << "\tGador, Ferdinand, 2019-08264" << endl;
	cout << "Dates covered: March 15 - 21, 2021" << endl;
	cout << "Brief description:" << endl;
	cout << "\tThis program converts a given infix expression to its equivalent postfix counterpart" << endl;
	cout << "\tThere are THREE available actions in this program:" << endl;
	cout << "\t\t*";
	cout << "Choice [P]: Prompts the program description of the program" << endl;
	cout << "\t\t*";
	cout << "Choice [E]: Prompts the user to enter their desired infix expression and the" << endl;
	cout << "\t\tprogram will evaluate the expression and transform it to its postfix expression" << endl; 
	cout << "\t\t*";
	cout << "Choice [G]: Prompts the guidelines, Do's and Dont's, and limitations of the program"<< endl;
	cout << "\t\t*";
	cout << "Choice [X]: Exits the program" << endl;
	cout << "Program development information:" << endl;
	cout << "\tGador did the postfix evaluation algorithm" << endl; 
	cout << "\tManabat did the input to postfix algorithm, as well as the other functionalities of the program\n" << endl;
	system("pause");
}

//Function that shows users the guidelines of the programs
void programGuidelines() {
	
	system("cls");
	cout << "----PROGRAM GUIDELINES----" << endl; 
	cout << "==========================" << endl;
	cout << "\nGENERAL FAQs and RULES: "<< endl; 
	cout << "  1. No negative integers is allowed for this program. Otherwise, it will fail" << endl;
	cout << "\t*Example: (-4)+2 --> Will terminate the process.\n" << endl; 
	cout << "  2. Allowed inputs: " << endl;
	cout << "\t>Non-negative INTEGER: " << endl;
	cout << "\t*Example: 0, 10,4, 1000 --> Allowed | -1, 0.98, 3.1415, 34.35 --> Will terminate the process.  " << endl;
	cout << "\t>Operators (except exponent operator) and Parentheses: " << endl; 
	cout << "\t*Example: '+', '-', '*', '/' --> Allowed | '^', '{}', '...', ',', '~', 'x' --> Will terminate the process.\n" << endl; 
	cout << "  3. Parentheses should be paired." << endl;
	cout << "\t*Example: (1+2) --> Allowed | (1+2 or 1+2) --> Will terminate the process.\n " << endl; 
	cout << "  4. Incomplete expressions will not be evaluated." << endl; 
	cout << "\t*Example: '1++', '2+3+', '6*5/' --> Will terminate the process.\n " << endl; 
	cout << "  5. Integers greater than 10 can also be evaluated by this program." << endl; 
	cout << "\t*Example: 10000*3 will still yield result. \n" << endl;
	cout << "  6. Inputs cannot be empty." << endl; 
	cout << "\t*Example: using empty space as an input will terminate the process\n" << endl; 
	cout << "======================THANK YOU======================" << endl; 
	system("pause"); 
	
}

//Function that convertes the given infix expression to its postfix counterpart, and evaluates the inputted expression into its result
void evaluateExpression() {

	system("cls");
	//----------variable declaration-----------//
	string expression;											//---> Stores the user input to a string variable
	myList* myStack = NULL;										//---> Stack declaration (for operators)
	myList* myQueue = NULL;										//---> Queue declaration (for resulting 
	int i = 0;													//---> Int variable used for loop iteration
	
	//Prompts the user to input their desired infix expression
	cout << "Enter infix expression: ";
	getline(cin, expression);
	 
	//While-loop that runs until i is equal to the length of the entered expression
	while (i < expression.length()) {
		
		//Checks if the current character of the string is a numeric number. If yes,
		if (isdigit(expression[i]) != 0) {
			
				
			string operand = "";								//--->This string will store the ith character of the inputted expression in a string 
			
			//This while-loop will scan if the following characters from the current iteration of the expression is a number. Only terminates if it encounters a non-numeric character
			while (isdigit(expression[i]) != 0) {
				operand += expression[i];						//Appends the current character in the string operand
				i++;											//Increments i to move onto the next character in the expression
			}
			
			myQueue = enqueueQueue(myQueue, operand);			//Calls the enqueueQueue function which adds the string operand in the queue.  
		}
		
		//If the current character of the string is not a numeric number,
		else {
			
			//Initially scans if the character is within the allowed symbols of the infix expression. If yes, 
			if (expression[i] == '%' || expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '(' || expression[i] == ')') {
				
				//converts the expression[i] to a string and stores it to a string variable
				string operators;
				operators.push_back(expression[i]);
				
				//Initially checks if the stack is empty. If true, it will push the created string to the stack
				if (myStack == NULL) {
					myStack = pushStack(myStack, operators);
				}
				
				//If stack is not empty, then:  
				else {
					
					//Stores the top of the stack in a string called top. Used for precedence comparison
					string top = myStack->expression;
					
					//Checks if the current traced character in the inputted expression is a closing parenthesis
					if (expression[i] == ')'){
						
						//While loop that traces the stack until an opening parenthesis is encountered
						while (myStack->expression != "(") {
							myQueue = enqueueQueue(myQueue, myStack->expression);			//Enqueues the top of the stack in the queue through the enqueueQueue function
							myStack = popDequeue(myStack);									//Pops the top element out of the stack through the popDequeue function
							if (myStack == NULL) break;										//Checks if the stack is empty. If yes, the loop will break
						}
						
						//If the stack became null, which means that the opening parenthesis was never found in the expression. It will break the whole process
							//and display the appropriate message that informs the user that they inputted an incorrect infix expression
						if (myStack == NULL) {
							cout << "\nINVALID INPUT! Enter a proper infix expression. Please refer to the Program Guidelines [G] in the main menu\n" << endl;
							system("pause");
							return;
						}
						//If stack is not empty, the opening parenthesis was found in the expression. We then proceed in popping the opening parenthesis out of the stack. 
						else if (myStack != NULL) {
							myStack = popDequeue(myStack);
						}
					}
					
					//Precedence evaluation: If the current traced character in the expression is an operator with higher precedence
					else if (((expression[i] == '*' ||expression[i] == '/') && (top == "+" ||top == "-" ||top == "("))){
						myStack = pushStack(myStack, operators);							//pushes the string operators (current character in the expression) into the stack
					}
					
					//Precedence evaluation: If the current traced character is +/- and the top character is an opening parenthesis, we push it to the stack
					else if ((expression[i] == '+' || expression[i] == '-') && (top == "(" )) {
						myStack = pushStack(myStack, operators);
					}
					
					//Precedence evaluation: If the current traced character is an opening parenthesis, we push it to the stack everytime.
					else if((expression[i] == '(') && (top == "+" || top == "-" || top == "*" || top == "/" || top == "(")) {
						myStack = pushStack(myStack, operators);
					}
					
					//Precedence evaluation: If the current traced character has a lower precendence than the operator character at the top of the stack
					else if ((expression[i] == '+' || '-') && (top == "*" || top == "/" || top == "+" || top == "-") || ((expression[i] == '*' || '/') && (top == "*" || top == "/"))) {					
						myStack = popDequeue(myStack);										//Pops the top element of the stack
						myQueue = enqueueQueue(myQueue, top);								//Enqueues the popped element on the queue
						myStack = pushStack(myStack, operators);							//Pushes the current operator character at the top of the stack
					}			
				}
			}
			
			//If the current traced character in the expression is a space, we just skip it in evaluation
			else if (expression[i] == ' ') {
				i++;	
			}
			
			//Else, if the current traced character is not within the allowed symbols for the infix expression,
				//then we terminate the whole process and display the appropriate message.
			else {
				cout <<"\nINVALID INPUT! Enter an infix expression with proper operands and operators. Please refer to the Program Guidelines [G] in the main menu\n" << endl;
				system("pause");
				return;
			}
			
			//Increments the iteration variable
			i++;
		}
	}
	
	
	//After the completing the evaluation of the expression, we take what's left on the stack all the way to the queue
	while (myStack != NULL) {
		//If the stack still contains an opening parenthesis, this means that the user has inputted an unpaired parenthesis in his/her expression
			//Therefore, this will stop the whole evaluation and it will display the appropriate message to inform the user
		if (myStack->expression == "(") {
			cout << "\nINVALID INPUT! There's an unpaired parenthesis in the inputted expression. Please refer to the Program Guidelines [G] in the main menu\n" << endl;
			system("pause");
			return;
		}
		//Stores the current top element in the stack and enqueues the element to the queue
		string temp = myStack->expression;
		myQueue = enqueueQueue(myQueue, temp);
		//Pops the top element from the stack and updates the stack. 
		myStack = popDequeue(myStack);
	}
	
	//Additional error handling: If the user only inputted spaces, it will terminate the process and display the appropriate message.
	if (myQueue == NULL) {
		cout << "\nINVALID INPUT! There's no enough input. Please refer to the Program Guidelines [G] in the main menu\n" << endl;
		system("pause");
		return;
	}
	
	//Displays the converted postfix expression to the user
	cout << "\nPOSTFIX EXPRESSION: ";
	myList* printer = myQueue;
	while (printer != NULL) {
		cout << printer->expression;
		printer = printer->next;
	}
	cout <<"\n";

	//============================================================================================================================================================//
	//This part of the program contains the POSTFIX evaluation of the inputted expression. 
	
	//Re-initialize the myStack to NULL
	myStack = NULL;
	
	//This while-loop runs until myQueue becomes empty
	while (myQueue != NULL) {
		
		//Check if the first element in queue is a number. If yes, 
		if (isdigit(myQueue->expression[0]) != 0) {
			myStack = pushStack(myStack, myQueue->expression);			//We push the number into the stack
		}
		
		//If not a number, we perform the operation based on that element
		else {
			
			//----------Variable declaration-----------//
			string operators = myQueue->expression;						//--->We store the current element of the queue in a string
			int operands[2];											//--->Int array used for storing the operands stored from the stack
			int result; 												//--->Stores the result after the operation of the two operands
			
			//For loop that runs until i = 2. Used for extracting the operands from the 
			for (int i = 0; i < 2; i++) {
				
				//Checks if the current top element of the stack is a number. If true,
				if (isdigit(myStack->expression[0]) != 0) { 
					
					//Converts the element into an integer
					operands[i] = atoi(myStack->expression.c_str());
					//Checks if the next element of the stack is null and there's only 1 extracted operand. This means that the user has inputted
						//a wrong infix expression. Terminates the whole process and display the appropriate message
					if (i == 0 && myStack->next == NULL) {
						cout << "\nINVALID INPUT! Enter a proper infix expression. Please refer to the Program Guidelines [G] in the main menu\n" << endl;
						system("pause");
						return;	
					}
					//Pops the top element of the stack afterwards
					myStack = popDequeue(myStack);  
				}
				
				//Checks for the other condition: If the first element on the top element is a '-' character, indicating a negative number,
					//we take that as the next operand
				else if (myStack->expression[0] == '-' && isdigit(myStack->expression[1]) != 0 ) {
					
					//Converts the element into an integer
					operands[i] = atoi(myStack->expression.c_str());
					//Same logic with line 281
					if (i == 0 && myStack->next == NULL) {
						cout << "\nINVALID INPUT! Enter a proper infix expression. Please refer to the Program Guidelines [G] in the main menu\n" << endl;
						system("pause");
						return;	
					} 
					//Pops the top element on the stack afterwards
					myStack = popDequeue(myStack);  
				}
				
				//If the number on the top of the stack is an operator instead of an operand, the user has inputted a wrong infix expression
					//Terminates the process, displays the appropriate message.
				else {
					cout << "\nINVALID INPUT! Enter a proper infix expression. Please refer to the Program Guidelines [G] in the main menu\n" << endl;
					system("pause");
					return;
				}
			}
			
			//Conditional statement based on the current first element in the queue:
			if (operators == "+") {
				result = operands[1] + operands[0];
			}
			else if (operators == "-") {
				result = operands[1] - operands[0];	
			}
			else if (operators == "*") {
				result = operands[1] * operands[0];
			}
			else if (operators == "/") {
				//Double-checks if the first operand is 0 since it will result to an indeterminate output.
					//It will terminate the whole process and display the appropriate message
				if (operands[0] == 0) {
					cout << "\nINVALID INPUT! The given infix will result to an indeterminate output. Expression cannot be evaluated even further." << endl; 
					system("pause"); 
					return;
				}
				result = operands[1] / operands[0];
			}
			
			//Extra error handling for program reliability: If the current element is not an operator, the following lines will run 
			else {
				cout << "\nINVALID INPUT! Enter a proper infix expression. Please refer to the Program Guidelines [G] in the main menu\n" << endl; 
				system("pause");
				return;
			}
			
			//Converts the result into a string (sstream library) and pushes it back to the stack
			stringstream ss;
			ss << result; 
			string new_result = ss.str(); 
			myStack = pushStack(myStack, new_result);
		}
		//Updates the queue
		myQueue = popDequeue(myQueue);
	}
	
	//Displays the evaluated result. Which is stored as the first element of the stack
	cout << "EVALUATED RESULT: " << myStack->expression << "\n" << endl; 
	
	//Deletes allocated memory to avoid memory leakage
	delete myStack; 
	delete myQueue; 
	system("pause");
}

//Function that pushes an element into the stack
myList* pushStack (myList* myStack, string top) {
	
	myList* newNode = new myList;
	newNode->expression = top; 
	newNode->next = myStack; 
	myStack = newNode; 
	return myStack;
}

//Function that enqueues an element into the queue
myList* enqueueQueue(myList* myQueue, string top) {
	
	myList* newNode = new myList; 
	newNode->expression = top; 
	newNode->next = NULL; 
	
	if (myQueue == NULL) {
		myQueue = newNode;
	}
	else {
		myList* temp = myQueue; 
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode; 
	}
	
	return myQueue;
}

//Function that deletes the top/first element of the stack/queue, deallocates its memory, and updates the list 
myList* popDequeue(myList* myTempList) {
	
	myList* temp = myTempList; 
	myTempList = myTempList->next; 
	delete temp;
	return myTempList; 
}
