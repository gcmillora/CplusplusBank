/*
	Program created by: 
		[2019-60019] Greg Norman C. Millora
		Bachelor of Science in Computer Science
		University of the Philippines - Mindanao
	Last Date Modified:
		March 21, 2021
	--------------------------------------------
	Program Description:
		The main purpose of the program is to convert an
		infix expression to its equivalent postfix expression.
		The program will also output the result of the converted
		expression. Moreoever, the program specifications is
		displayed under the Program Guidelines, which outputs
		the limitations and recommendations of the program.
*/

#include<iostream>
#include<stdio.h>
#include<string>
#include<cmath>

using namespace std;

//User-defined datatypes used for the program.
//It includes the datatype Node,list, and queue.

struct Node{
	string input;
	struct Node *next;
};
struct list{ //Datatype list is used as a stack.
	int len;
	struct Node *head;
};
struct queue{
	int len;
	struct Node *head;
	struct Node *tail;
};

//Function prototypes needed for the initialization
//of the user-defined datatypes.
struct Node *createNode();
struct queue *createQueue();
struct list *createList();

//Function prototypes of the printing functions for
//the menu, program description and program guidelines.
void displayName();
void displayMenu();
void displayDescription();
void displayGuidelines();

//Function prototypes of the basic operations used for
//a stack implementation.
void push(struct list*,string);
string top(struct list*);
string pop(struct list *);


//Function prototypes of the basic operations used for
//a queue implementation.
int enqueue(struct queue *,string);
string dequeue(struct queue *);
void print_queue(struct queue *);

//Function prototypes of the main actions or operations
//used for the program solution.
int evalOperator(char,char);
void inf_post(string , struct queue * , struct list *, bool&);
bool evaluateExpression(struct list * , struct queue * );


int main(){
	struct list *stack;
	struct queue *queue;
	string input;
	char choice;
	bool flag = true;
	//A while-loop that runs until the user prompts the program
	//to terminate.
	while(1){
		system("cls");
		displayMenu(); //Displays the menu section of the program.
		cout<<"Choice: ";
		cin>> choice;
		cin.sync(); //cin.sync() discards all unread characters from the input buffer.
		switch(choice){ //A switch statement to evaluate the choice inputted by the user.
			case 'P': //User chose to display the program description.
				system("cls");
				displayDescription();
				system("pause");
				break;
			case 'G'://User chose to display the program guidelines.
				system("cls");
				displayGuidelines();
				system("pause");
				break;
			case 'E': //User chose to proceed with the infix-postfix conversion.
			    while(1){
					cin.sync(); 
					system("cls");
					cout<<"Please enter an expression: ";
					getline(cin,input);
					stack = createList();//Create a new stack for every run.
					queue = createQueue();//Create a new queue for every run.
					inf_post(input,queue,stack,flag);
					if(flag) evaluateExpression(stack,queue);
				
					cout<<"\n\nDo you want to enter another expression(Y/N)? ";
					cin>>choice;
					if(choice=='Y'){//Checks if the user wants to continue, if the input is 'Y' then continue
									//otherwise, go back to main menu.
						continue;
					}
					else if(choice =='N')
						break;
					else{
						cout<<endl;
						cout<<"Error: Invalid input! Program is going back to menu."<<endl;
						break;
					}
				}
				system("pause");
				break;
			case 'X': //User chose to terminate the program.
				cout<<"\n\nThank you for using the program! \nHope to see you soon :)"<<endl;
				return 0;
			default: //User inputted a choice not found in the menu, loops again and prompts
					//the user to input a new choice.
				cout<<"Please input an appropriate choice."<<endl;
				system("pause");
		}
	
	}
	return 0;
}

//A function to initialize a node, returns
//a data of type Node. Sets the next node to
//NULL, and node->input to empty.
struct Node *createNode(){
	struct Node *temp;
	temp = new Node;
	temp->next=NULL;
	temp->input="asdf";
	return temp;
};

//A function to initialize a list, returns
//a data of type list. Sets the head of the
//list to NULL and the length of the list
//to 0.
struct list *createList(){
	struct list *temp;
	temp = new list;
	temp->head=NULL;
	temp->len=0;
	return temp;
};

//A function to initialize a queue, returns
//a data of type list. Sets the head and tail
// of the queue to NULL and the length of the 
//queue to 0.
struct queue *createQueue(){
	struct queue *temp;
	temp = new queue;
	temp->head=NULL;
	temp->tail = NULL;
	temp->len =0;
	return temp;
};

//A function to display the menu section of the program.
void displayMenu(){
		cout<<"Welcome to this Expression Evaluator program! Please choose an action to";
		cout<<endl<<"perform..."<<endl<<endl;
		cout<<"[P] Program Description"<<endl;
		cout<<"[G] Program Guidelines"<<endl;
		cout<<"[E] Evaluate Expression(s)"<<endl;
		cout<<"[X] Exit"<<endl;
}

//A function to display the program description of the program.
void displayDescription(){
	cout<<"[PROGRAM DESCRIPTION]\n"<<endl;
	cout<<"Program created by: "<<endl;
	cout<<"\t2019-60019 - Greg Norman Millora"<<endl;
	cout<<"Dates covered: "<<endl;
	cout<<"\tMarch 20, 2021"<<endl;
	cout<<"------------------------------------------------------------------------"<<endl;
	cout<<"Program Description: "<<endl;
	cout<<"\tThe main objective of the program is to convert an infix expression\n"<<
		"into its equivalent postfix expression. Morever, it evaluates the expression\n"<<
		"and outputs the result."<<endl;
	cout<<"\tThe user can select from four choices or actions, specifically: "<<endl;
	cout<<"[P] : Shows the program description of the program. It includes who created the program, the duration\n"
		<<"\tof the development, and a brief description of the actions available by the program."<<endl;
	cout<<"[G] : Shows the program guidelines of the program. It includes the program specifications, in example,\n"
		<<"\tthe rules in regards to the input and output, limitations and extent of the program."<<endl;
	cout<<"[E] : Let the user to provide or input an expression, expectedly in INFIX format, and converts it to\n "
		<<"\tits equivalent postfix expression. It also outputs the result of the expression inputted."<<endl;
	cout<<"[X] : Exits the program and say goodbye to the user."<<endl;
	cout<<endl;
	cout<<"Program Development: "<<endl;
	cout<<"\tThe entire source code was coded by Greg Norman Millora including the debugging."<<endl;
	cout<<"\tNote: Please read the program guidelines to run the program smoothly."<<endl;
}

//A function to display the program guidelines of the program.
void displayGuidelines(){
	cout<<"[PROGRAM GUIDELINES]\n"<<endl;
	cout<<"\tThese guidelines provides information on the limitations and extent of the program, specifically,\n"
		<<"the acceptable inputs, operators and expression."<<endl<<endl;
	cout<<"1. Only non-negative integers are allowed. Integers such as -1, -5, and etc. will result to an error."<<endl;
	cout<<"2. Only the operators for subtraction ( – ), division ( / ), multiplication ( * ), addition ( + ), and modulo ( % )\n"
		<<"are allowed. Any other operators will result to an error."<<endl;
	cout<<"3. Parentheses are the only brackets allowed. Other various typographical forms are not allowed."<<endl;
	cout<<"4. Spaces can be used as delimeters, there are no restriction with the number of spaces allowed."<<endl;
	cout<<"5. The only form of multiplication allowed is with the use of the operator '*', the form (a)(b) will\n"
		<<"result to an error."<<endl;
}

//A function to check the precedence of the operators. Compares the current operator
//on the top of the stack, and the current operator read from the input. Returns
//the appropriate integer number to determine which step is next in the conversion
//of the expression.
int evalOperator(char inside,char outside){
	if((inside=='*'||inside=='/'||inside=='%')&&(outside=='+'||outside=='-')){
		//If the operator on the top of the stack is either *,/, or % and the
		//current operator read in the input string is + or -, then return 1.
		return 1;
	}
	else if((inside=='+'||inside=='-')&&(outside=='*'||outside=='/'||outside=='%')){
		//If the operator on the top of the stack is either + or - and the
		//current operator read in the input string is *,/, or %, then return 0.
		return 0;
	}
	else if((inside=='*'||inside=='/'||inside=='%')&&(outside=='*'||outside=='/'||outside=='%')){
		//If the operator on the top of the stack is either *,/, or % and the
		//current operator read in the input string is *,/, or %, then return 1.
		return 1;
	}
	else if((inside=='+'||inside=='-')&&(outside=='+'||outside=='-')){
		//If the operator on the top of the stack is either + or - and the
		//current operator read in the input string is + or -, then return 0.
		return 1;
	}
	else
		return 99;
}

//A function to push an element to the stack. Has the parameters, the 
//struct list, or the stack, and the string to be pushed into the stack.
void push(struct list *stack, string op){
	struct Node *newnode; //Create a new node to store the new element.
	newnode = createNode();
	newnode->input = op;
	if (stack->head == NULL) {//If the top or head of the stack is NULL then
		stack->head = newnode;//assign the new node to the head of the stack.
		stack->len = 1;		
	}
	else{
	newnode->next = stack->head;//Else, assign the current head of the stack
	stack->head = newnode;		//to the next node of the new node, and assign
	stack->len +=1;				//the new node as the head of the stack. Increment
		}						//the length of the stack by 1;
}

//A function to get the value of the string data of
//the head of the stack. Returns the string 'input' from
//node stack->head.
string top(struct list *stack){
	return stack->head->input;
}

//A function to get the value of the string data of
//the head of the stack and deletes the current head
//of the stack. Returns a data of type string which 
//is the string data of the head node. 
string pop(struct list *stack){
	struct Node *tmpnode;//Create a temporary node to store
	tmpnode = stack->head;//the current head node of the stack.
	string op = tmpnode->input;//Assign the string data of the head to a string.
	stack->head = stack->head->next; //Assign the head of the stack to its next node.
	//Decrement the length of the stack and delete the temporary node.
	stack->len -=1; 
	free(tmpnode);
	return op;
}

//A function to enqueue an element to the queue. Has the parameters struct queue*
//or the queue, and the string to be enqueued to the queue.
int enqueue(struct queue* queue, string val){
	struct Node *newnode;//Create a new node to store the new element.
	newnode = createNode();
	newnode->input = val;
	if (queue->head == NULL) {//If the top or head of the queue is NULL then
		queue->head = newnode;//assign the newnode to the head and tail of the queue.
		queue->tail = newnode;
		queue->len = 1;	
		return 1;	//Increment the length of the queue by 1.
	}
	queue->tail->next = newnode; //Else, assign the new node to the next node
	queue->tail = newnode;		//of the tail node of the queue.
	queue->len +=1;	
	return 1;		//Increment the length of the queue by 1.
	
}

//A function to dequeue from a queue. Has the parameter struct queue* or
//the queue to do the operation from.
string dequeue(struct queue *queue){
	struct Node *tmpnode; //Create a temporary node to store the current head of the queue.
	tmpnode = queue->head;
	string val = tmpnode->input;
	queue->head = queue->head->next; //Assign the next node of the head of the queue as the
	queue->len -=1;					//head of the queue, and decrement the length of the queue by 1.
	free(tmpnode);	//Delete the temporary node.
	if(queue->head==NULL) //If the head of the queue is NULL then the tail must be also NULL.
		queue->tail=NULL;
	return val;
}

//A function to print the elements of the queue. Has the parameter struct queue*
//or the queue to do the operation from.
void print_queue(struct queue *queue){
	struct Node *node;
    node = queue->head;
	if(node==NULL) {//If the head of the queue is NULL, then there was no expression found.
		cout<<"Error: an expression is expected!"<<endl;
		return;
	}
	//Else, traverse the queue and output the value of the node->input, or the value of the node
	//until the node reaches the end or is equal to NULL.
	printf("\nPostfix Form: ");
	do {
		cout<<node->input<<" ";
		node = node->next;
	} while (node != NULL);
}

//A function to convert the infix expression to its equivalent postfix expression.
//Has the parameters string inp, or the input string from the user, struct queue* and
//struct list* or the stack.
void inf_post(string inp, struct queue* queue, struct list *stack, bool& flag){
	int ctr=0;
	string number;
	string op;
	string temp;
	while(ctr<inp.length()){//A while-loop to traverse each element of the string.
		if(inp[ctr]==' '){//If a character space is found, increment the counter, 'ctr',
						//and continue with the while-loop.
			ctr++;
			continue;
		}
		//If a digit is found, continue check the next character of the string and append it
		//to a string, 'number' to store the digits. Lastly, enqueue the string number, to
		//the queue.
		if(isdigit(inp[ctr])){
			while(isdigit(inp[ctr])){
				number+=inp[ctr];
				ctr++;
			}
			enqueue(queue,number);
			number = "";
		}
		//If an open parenthesis is found, push the parenthesis inside the stack, since the push
		//function accepts a string rather than a character value, append the parenthesis to a string
		//'temp', and push temp to the stack. Increment the counter, 'ctr' by 1.
		else if(inp[ctr] == '(') {
			temp.append(1, inp[ctr]);
			push(stack,temp); 
			temp="";
			ctr++;
		}
		//Else, if a close parenthesis is found, pop all the elements of the stack until an open
		//parenthesis is found, enqueue each popped element to the queue.
		else if(inp[ctr]==')'){
			while(top(stack)!="("){
				enqueue(queue,top(stack));
				pop(stack);
				if(stack->head==NULL)
					break;
			}
			if(stack->head == NULL){
				cout<<"Expected '(' not found!"<<endl;
				flag = false;
				return;
			}
			//If the head of the stack is NULL after popping all elements from the stack
			//then an open parenthesis, '(', was not found.
			//If an open parenthesis is found, pop it.
			if(top(stack)=="("){
				pop(stack);
			}
			//Increment the counter by 1.
			ctr++;
		}
		//If an operator is found, then continue evaluating the stack and the operator to
		//know which next step to do.
		else if(inp[ctr]=='*'||inp[ctr]=='/'||inp[ctr]=='+'||inp[ctr]=='-'||inp[ctr]=='%'){
			op = inp[ctr];
			//Check if two operators consecutively appears in the string input.
			if(inp[ctr-1]=='*'||inp[ctr-1]=='/'||inp[ctr-1]=='+'||inp[ctr-1]=='-'||inp[ctr-1]=='%'){
				cout<<"Error: Invalid expression, consecutive operators found."<<endl;
				flag = false;
				return;
			}
			if(stack->head==NULL) {
				push(stack,op);
			}
			//If the current value of the top of the stack is an open parenthesis
			//just push the operator to the stack.
			else if(stack->head->input[0] =='(') {
				push(stack,op);
			}
			else{
				//Else if another operator is in the top of the stack, use the function evalOperator to
				//check the precedence of the operators.
				int test = evalOperator(stack->head->input[0],op[0]);
				//If the returned value from the function evalOperator is 1, then pop the current top 
				//of the stack and enqueue it to the queue. Then, push the current operator to the stack.
				if(test==1){
					string temp_op="";
					temp_op+=pop(stack);
					enqueue(queue,temp_op);
					push(stack,op);
					}
				//Else, if the value returned is 0, then push the operator to the stack.
				else if(test==0){
					push(stack,op);
				}
			}
			//Increment the counter, 'ctr' by 1 to proceed to the next character.
			ctr++;
		}
		else{
			//If the character is not a parenthesis, digit nor an operator, then an invalid input is found.
			cout<<endl;
			cout<<"Error: Invalid input, please check the guidelines of the program."<<endl;
			flag = false;
			return;
		}
	}
	//Enqueue the remaining elements from the stack to the queue.
	while(stack->len!=0){
		string temp_op="";
		temp_op+=pop(stack);
		enqueue(queue,temp_op);
	}
	print_queue(queue);//Print the postfix expression which is the current elements of the queue.
	cout<<endl;
	flag = true;
}

//A function to evaluate the converted infix expression. Has the parameters
//struct list* or the stack, and struct queue*. Returns a value of either
//true or false. False if an error occured, else return true.
bool evaluateExpression(struct list *stack, struct queue *queue){
	//Traverse the queue using a while loop.
	bool flag=0;
	while(queue->head!=NULL){
		//If the value of the head of the queue is an operator,
		//get the operator by using the function dequeue(queue),
		//and assign the converted value of the top of the stack
		//to a variable of type float. Do this with another, float
		//variable. 
		if(queue->head->input[0]=='+'||queue->head->input[0]=='*'||
			queue->head->input[0]=='/'||queue->head->input[0]=='-'||
			queue->head->input[0]=='%'){
			string op = dequeue(queue);
			float number2 = stof(pop(stack));
			//If the stack is NULL, after popping a single element, then the
			//expression is invalid, probably too much operators or incomplete
			//expression is found.
			if(stack->head==NULL){
				cout<<endl;
				cout<<"Error: Invalid expression, check the program guidelines."<<endl;
				cout<<"Error: Too much operators or incomplete expression."<<endl;
				return 0;
			}
			float number1 = stof(pop(stack));
			float result;
			//Do the operation accordingly using a switch statement to evaluate
			//the operator dequeued from the queue.
			switch(op[0]){
				case '+':
					result=number1+number2;
					break;
				case '-':
					result=number1-number2;
					break;
				case '*':
					result=number1*number2;
					break;
				case '/':
					//If the denominator of the current expression is zero then an indeterminate
					//form of N/0 is found which is not allowed.
					if(number2==0){
						cout<<"Error:  Invalid result, an indeterminate form of n/0 is not allowed.";
						return 0;
					}
					result=number1/number2;
					break;
				case '%':
					result=fmod(number1,number2); //Use fmod to get the modulo of two float variables.
					break;
			}
			flag = 1;
			//Convert the result to a string format and push it to the stack.
			string str= to_string(result);
			push(stack,str);
		}
		else{
			//If the head of the queue is not an operator then it must be a number, dequeue from the 
			//queue and push it to the stack. These step would ideally occur twice in a row.
			string number = dequeue(queue);
			if(isdigit(number[0]))
				push(stack,number);
			else{
				//If the dequeued value is not starting with a digit, then an invalid or incomplete
				//exprsesion is found.
				cout<<endl;
				cout<<"Error: Invalid expression, check the program guidelines."<<endl;
				cout<<"Error: Incomplete or invalid expression found."<<endl;
				return 0;
			}
		}
	}
	//If the head of the queue is NULL or the queue is empty, and the next node of the current head
	//of the stack is not NULL then output the result. The current head of the stack is the last node
	//of the stack and is the result of the expression.
	if(queue->head==NULL&&stack->head->next==NULL&&flag){
		cout<<"Result: "<<pop(stack);
	}
	else{
		//Else, if the conditions are not met, then it is an invalid expression, probably, there are more
		//numbers in the expression than the operators found.
		cout<<"Error: Invalid expression, check the program guidelines."<<endl;
		return 0;
	}
	return 1;
}
