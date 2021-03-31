/*
	Program created by: 
		[2019-60019] Greg Norman C. Millora
		Bachelor of Science in Computer Science
		University of the Philippines - Mindanao
	Last Date Modified:
		March 21, 2021
	--------------------------------------------
	Program Description:
		The main purpose of the program is to convert a string
		in compressed form to its equivalent expanded form and.
		vice-versa. The program outputs the resulted string
		afterwards. Moreoever, the program specifications is
		displayed under the Program Guidelines, which outputs
		the limitations and recommendations of the program.
*/

#include<iostream>
#include<string>

using namespace std;

//Function prototypes of the printing functions.
void displayMenu();
void displayGuidelines();
void displayDescription();

//Function prototypes of the main solution for 
//the problem.
void stringExpand(string);
void stringCompress(string);


int main(){
	string input;
	char choice;
    string compress,expand;
    //A while-loop that runs until the user prompts the program
	//to terminate.
	while(1){
        system("cls");
		displayMenu();//Displays the menu section of the program.
		cout<<"Choice: ";
		cin>>choice;
		choice = toupper(choice);
        cin.sync();//cin.sync() discards all unread characters from the input buffer.
		switch(choice){//A switch statement to evaluate the choice inputted by the user.
			case 'P'://User chose to display the program description.
                system("cls");
				displayDescription();
                system("pause");
				break;
            case 'G'://User chose to display the program guidelines.
                system("cls");
                displayGuidelines();
                system("pause");
                break;
			case 'E'://User chose to proceed with the compressed-expanded format conversion.
				while(1){
					cin.sync();
					system("cls");
					cout<<"[String Expansion]"<<endl;
					cout<<"Please enter a string: ";
					getline(cin,expand);
					stringExpand(expand);
					cout<<"\n\nDo you want to enter another expression(Y/N)? ";
					cin>>choice;
					choice = toupper(choice);
					if(choice=='Y'){//Checks if the user wants to continue, if the input is 'Y' then continue
									//otherwise, go back to main menu.
						continue;
					}
					else if(choice =='N')
						break;
					else{
						cout<<endl;
						cout<<"Invalid input! Program is going back to menu."<<endl;
						break;
					}
				}
                system("pause");
				break;
            case 'C'://User chose to proceed with the expanded-compressed format conversion.
				while(1){
				cin.sync();
                system("cls");
                cout<<"[String Compression]"<<endl;
                cout<<"Please enter a string: ";
                getline(cin,compress);
                stringCompress(compress);
                cout<<"\n\nDo you want to enter another expression(Y/N)? ";
					cin>>choice;
					choice = toupper(choice);
					if(choice=='Y'){//Checks if the user wants to continue, if the input is 'Y' then continue
									//otherwise, go back to main menu.
						continue;
					}
					else if(choice =='N')
						break;
					else{
						cout<<endl;
						cout<<"Invalid input! Program is going back to menu."<<endl;
						break;
					}
				}
                system("pause");
                break;
			case 'X'://User chose to terminate the program.
				cout<<"Saynoara";
				return 0;
			default://User inputted a choice not found in the menu, loops again and prompts
					//the user to input a new choice.
				cout<<"Invalid input, please choose an appropriate action."<<endl;
                system("pause");
		}		
	}
}

//A function to display the menu section of the program.
void displayMenu(){
		cout<<"Welcome to this String Expansion/Compression program! Please choose an action to";
		cout<<endl<<"perform..."<<endl<<endl;
		cout<<"[P] Program Description"<<endl;
		cout<<"[G] Program Guidelines"<<endl;
		cout<<"[E] String Expansion"<<endl;
        cout<<"[C] String Compression"<<endl;
		cout<<"[X] Exit"<<endl;
}

//A function to display the program description of the program.
void displayDescription(){
	cout<<"[PROGRAM DESCRIPTION]\n"<<endl;
	cout<<"Program created by: "<<endl;
	cout<<"\t2019-60019 - Greg Norman Millora"<<endl;
	cout<<"Dates covered: "<<endl;
	cout<<"\tMarch 21, 2021"<<endl;
	cout<<"------------------------------------------------------------------------"<<endl;
	cout<<"Program Description: "<<endl;
	cout<<"\tThe main objective of the program is to either do string expansion or string compression\n"
		<<"and output the appropriate result."<<endl;
	cout<<"\tThe user can select from four choices or actions, specifically: "<<endl;
	cout<<"[P] : Shows the program description of the program. It includes who created the program, the duration\n"
		<<"\tof the development, and a brief description of the actions available by the program."<<endl;
	cout<<"[G] : Shows the program guidelines of the program. It includes the program specifications, in example,\n"
		<<"\tthe rules in regards to the input and output, limitations and extent of the program."<<endl;
	cout<<"[E] : Let the user to provide or input a string, expectedly in compressed format, and converts it to\n "
		<<"\tits equivalent expanded form."<<endl;
    cout<<"[C] : Let the user to provide or input a string, expectedly in expanded format, and converts it to\n "
		<<"\tits equivalent compressed format."<<endl;
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
	cout<<"1. For string compression, only characters from the alphabet are allowed, a-z, A-Z."<<endl;
	cout<<"2. For string expansion, only alphanumeric characters are allowed, 1-9, a-z and A-Z."<<endl;
    cout<<"3. Spaces are not allowed, it will result to an error."<<endl;
}

//A function to convert a string input from compressed form, to
//expanded form. Has a parameter of type string, the input from
//the user.
void stringExpand(string input){
	int ctr=0;
	string expand;
    string number;
	string count = "1";
	while(ctr<input.length()){//Traverse the string using a while-loop.
        if(isalnum(input[ctr])&&input[ctr]!='0'){//Check if the current character is alphanumeric and not equal to 0.
            //If the character is not a digit, and the current count is 1, then append it to the
            //resulting string, 'expand'.
            if(count=="1"&& !isdigit(input[ctr])){
                expand+=input[ctr];
                ctr++;
            }
            //Else if the character is a digit, append the digit to count until a non-digit is found.
            else if(isdigit(input[ctr])){
                count="";
                while(isdigit(input[ctr])){
                    count+=input[ctr];
                    ctr++;//Increment the index counter, 'ctr'
                }
                //If ctr is equal to length upon checking the digits, it means that a after a digit, no
                //letter is found.
                if(ctr==input.length()||!isalpha(input[ctr])){
                    cout<<"Error: Invalid input found, please check the program guidelines.";
                    return;
                }
                //Append the letter, 'count' times, after a number is read.
                //In example, 5a, append the letter 'a' 5 times to the resulting
                //string, 'expand'.
                for(int ctr2=0;ctr2<stoi(count);ctr2++){
                    expand+=input[ctr];
                }
                ctr++;//Increment the index counter.
                count="1";//Revert back the count to "1".
                }
        }
        else{
            cout<<"Error: Invalid character found, please check the program guidelines!";
            cout<<endl;
            return;
        }
    }
    cout<<"Expanded Form: "<<expand;	
    cout<<endl;
}

//A function to convert a string in expanded format to its
//equivalent compressed format.Has a parameter of type string,
//the input from the user.
void stringCompress(string input){
	int count = 1;
	string compressed ="";
	int ctr = 0;
	while(ctr<input.length()){//Traverse the string using a while-loop
        if(isalpha(input[ctr])){//Check if the character is from the alphabet, a-z, A-Z.
            //While the next character index is not equal to the current character index,
            //increment the count and index counter.
            while(input[ctr]==input[ctr+1]){
                count++;
                ctr++;
            }
            //If the count is equal to 1, meaning a letter only appeared once, that the
            //next character is already a different letter.
            if(count==1){
                compressed += input[ctr];//Append to the resulting string, 'compressed'
                ctr++;
                count = 1;
            }
            //If the count is not equal to 1, meaning a letter appeared multiple times before
            //a different letter is found.
            else{
                compressed += to_string(count)+input[ctr];//Append the count and the letter to the resulting string.
                ctr++;
                count = 1;//Reset the count to 1;
            }
	}
        else{
            cout<<"Error: Invalid character found, please check the program guidelines!";
            cout<<endl;
            return;
     }
    }
	cout<<"Compressed Form: "<<compressed;	
}