//									'Car rental system' in C++ & Object Oriented Programming
//											This system is made by "Mohamed Gamal"
//													All rights reserved
// 													    2019-2020

#include <iostream>
#include <bits/stdc++.h>  // for transform() and tolower() functions
#include <string>
#include <unistd.h>   // sleep() function
#include <conio.h>
using namespace std;

// Login class - for the login proccess
class Login
{
	public:
		
		// Login function for password purpose
		int login()
		{
			string password = " ";
			char ch;
		
			ifstream in("welcome.txt"); 	// Displaying welcome ASCII image text on the terminal screen from a txt file
	
			// sends a client message when the above file doesn't open
			if(!in)
			{
				cout << "Couldn't open input file!\n";
			}
		
			char str[700];
			
			while(in)
			{
		    	in.getline(str, 700);
		    	if(in) cout << str << endl;
			}
			
			// Closes the file
		  	in.close();
		  
			sleep(1); 		//function which waits for (n) seconds
			cout << "\nStarting the program please wait....." << endl;
			
			sleep(1);
			cout << "\nloading up files....." << endl;
			
			sleep(1); 
			system("cls"); 	// clears screen
			
			cout << "\t\t\t\t\t-----------------------------------\n";
			cout << "\t\t\t\t\t\t  Login Process!\n";
			cout << "\t\t\t\t\t-----------------------------------\n";

			cout << "\n\n\n\n\t\t\t\t\t Please, Enter the password: ";
			ch = getch();  // gets a character
		   
			while(ch != 13)    // "13" is the ASCII code for "Enter" button / Carriage Return (CR).
			{
		    	password.push_back(ch);   // adds a new character ch at the end of the string password.
		    	cout << '*';              // puts '*' instead of the password
		    	ch = getch();
			}
			if(password == " grand")
			{
		    	cout << "\n\n\n\t\t\t\t\t Access Granted! Welcome. \n\n\n\n";
		    	system("pause");  // is used to execute pause command and make the screen/terminal wait for a key press.
		     
			}
			else
		   	{
		    	cout << "\n\n\n\n\t\t\t\t\t Access Denied...Please Try Again!\n";
		    
				system("pause");
		    	system("cls");    
		    	system("cls");
		      
		    	login(); // function recurssion
			}
		}
		
};


// person class 
class person
{
	protected:
		
	    char Name[50];
	    string National_ID[14];
	    int Payment_acc[20];
	    int days;

	public:
		
		// User's personal info function
		void get_data(int Choice)
		{
		    system("cls");
		    int j = Choice - 1;
	        
			cout << "\t\t\t-----------------------------------------------\n";
		    cout << "\t\t\t Please provide us with your personal details: \n";
		    cout << "\t\t\t-----------------------------------------------\n\n";
		    
		    // User's Full Name
	        cout << "\t\t\t Full Name: ";
	        cin.getline(Name, 50); // gets a string from user, supported with blank spaces
			// cin >> Name[j]
			
			// Condition for national id, forces the user to enter 14 digits of integer numbers
			while(getline(cin, National_ID[j]) && National_ID[j].size() != 14)
			{
		        cout << "\n\t\t\t National ID (14 digits are required): ";
		    }
		    
		    // Renting days
	        cout << "\n\t\t\t Number of days for renting: ";
	        cin >> days;		    
	        
	        
	        // Balance in Bank account
			cout << "\n\t\t\t Bank account balance: ";
        	cin  >> Payment_acc[j];
        	
        	sleep(1);
        	system("cls");
        }
		
		// print function for printing out the proccess details
		void print(int Choice)
		{
			int j = Choice - 1;
			
			cout << "\n\n\tPrinting out the proccess details...." << "\n\n\tLoading....\n\n" << endl;
        	sleep(3);
        	system("cls");
        	
        	cout << "\t\t\t\t-----------------------------------------------" << endl;
        	cout << "\t\t\t\t\t    **Given Information**" << endl;
        	cout << "\t\t\t\t-----------------------------------------------\n" << endl;
        	
        	cout << "\t\tName: " << Name[j] <<
				    "\n\t\tRenting Days: " << days <<
					"\n\t\tBalance in Bank account: " << Payment_acc[j] << endl;
		}
		
};
	

// Car class
class Car : public person	// Single public inheritance, inherits the public functions and other suff as public 
{
	protected:
		// The available cars for renting with specifications and some other stuff
		
		string car_mark;
		
		string Mark[10] = {"Hyundai", "BMW", "Mercedes", "Audi", "Tesla", "Skoda", "Volkswagun", "Toyota", "Ford"};
	
	    string Model[10] = {"2016MD", "2018AS", "2018DS", "2017LA", "2018OW", "2005Ps", "2008PW", "2010QW", "2016SA"};
	
	    string Color[10] = {"Red", "black", "yellow", "Blue", "Red", "Brown", "Silver", "Black", "grey"};
	
	    string Max_speed[10] = {"100 Km/h", "150 Km/h", "150 Km/h", "170 Km/h", "130 Km/h", "140 Km/h", "130 Km/h", "120 Km/h", "150 Km/h"};
	
	    int Price[10] = {100, 200, 300, 500, 200, 250, 400, 600, 900};
	
	    int Date[10] = {2010, 2012, 2013, 2017, 2018, 2005, 2008, 2010, 2014};
	    
	public:
		
		// User's input function (choice)
		void get()
		{
			int num = 1;
		 	
		 	cout << "\t\t\t  --------------------------------------------------------------\n";    
			cout << "\t\t\t\tWelcome to our company, choose from the below menu: " << endl;
			cout << "\t\t\t  --------------------------------------------------------------\n\n";
			cout << "\tAvailable cars for renting are listed below, stay tuned for the coming cars!\n" << endl;

		 	// for loop for showing a menu of car marks
			for(int i=0 ; i<9 ; ++i)
		 	{
		 		cout << "\t";
		    	cout << "Enter " << num << "\t- To Select  " << Mark[i] << endl;
		    	
		    	num++;
		    }		    
		}
		
		// function for printing out the user's chosen car information
		void car_info(int Choice)
		{
			system("cls");
			cout << "\n\n\n\t\t\t-----------------------------\n";
		    cout << "\n\n\t\t\tYou have chosen - " << Mark[Choice - 1]	   << endl;
		    
			cout << "\n\t\t\tModel: " 		   << Model[Choice - 1] 	   << endl;
		    cout << "\t\t\tColor: " 		   << Color[Choice - 1] 	   << endl;
		    cout << "\t\t\tMaximum Speed: "    << Max_speed[Choice - 1]    << endl;
		    cout << "\t\t\tPrice: " 		   << Price[Choice - 1] << "$ per day" << endl;
			cout << "\n\n\t\t\t-----------------------------\n";
		}
		
		// function for calculating the rental fee 
		void calculate(int Choice)
		{
			int j = Choice - 1;
			
	    	int rental_fee = days * Price[j];
	    	
	    	cout << "\t\tRental Amount: " << rental_fee << endl;
	    	cout << endl;
        	
        	system("pause");
        	system("cls");
		}
		
		//  Credit card balance availability check for renting any chosen car
		void Check(int Choice)
		{
			int j = Choice - 1;
        
        	do
        	{
        		cout << "\n\n\tChecking balance in your bank account...." << endl;
        		cout << "\tLoading.....\n\n" << endl;
        		
        		sleep(2);
        		
				if(Payment_acc[j] >= Price[j])
				{
					cout << "\n\t\t\t Available, Process has been done successfully!" << endl;
					break;
				}
			    else
			    {
			    	cout << "\n\t\t\t\t Error! Not Available." << endl;
					cout << "\n\t\t\t Payment Amount: ";
        			cin  >> Payment_acc[j];
        			
        			system("cls");
				}
			    	
			}while(Payment_acc[j] != Price[j] || Payment_acc[j] < Price[j]);
		}
};

// Welcome class
class welcome : public person, public Car  //multiple public inheritance "inherits the protected suff as protected
{										  //			& the public functions and other suff as public 
	protected:
		
		string decide = "yes";
		Car S2;		// An object "S2" of the class "Car"
	
	public:
		
		void process()
		{
			
			while(decide != "exit")
		    { 	
			    int Choice;
			    
				system("cls");
		
			    S2.get();  // Show Menu for user
			    
			    // User's choice
				cout << "\n\n\n\t\t\t Enter your choice: ";
			    cin >> Choice ;
			    
			    // Chosen car info
			    S2.car_info(Choice);
			    
			    // Operation check to continue the process
				cout << "\n\n\n\t\t\t Are you sure, you want to rent this car? [(y)es / (n)o / exit]: ";
			    cin >> decide;
				transform(decide.begin(), decide.end(), decide.begin(), ::tolower); // transforms the user's input into a lowercase
					
					if(decide == "yes" || decide == "y")
					{
						S2.get_data(Choice);  // Gets user's personal information
					    S2.Check(Choice);	 // Bank balance availability
					    S2.print(Choice);	// printing out the proccess details
					    S2.calculate(Choice);	// Calculating the rental fee
					    
				        cout << "\n\n\t\t\tDo you want to continue? [(y)es / (n)o)]: ";
				        cin >> decide;
				        
						transform(decide.begin(), decide.end(), decide.begin(), ::tolower);
						
						system("cls");
						sleep(1);
						
						ifstream inf("thanks.txt"); // Displaying thanks ASCII image text on the terminal screen from a txt file
				
						char str[300];
					
						while(inf)
						{
							inf.getline(str, 300);
							if(inf) cout << str << endl;
						}
					  	
						inf.close();
						
						cout << "\n\n";
			    		system("pause");
			    		system("cls");
		
						continue; // continues the loop
					}
					else if(decide == "no" || decide == "n")
			    	{
			    		system("cls");
						sleep(1);
			    		
			    		ifstream inf("thanks.txt");
				
						char str[300];
					
						while(inf)
						{
							inf.getline(str, 300);
							if(inf) cout << str << endl;
						}
					  	
						inf.close();
						
						cout << "\n\n";
			    		system("pause");
			    		system("cls");
			    		
						continue;
			    	}
			    	else if(decide == "exit")
			    	{
			    		system("cls");
			    		
		 				cout << "\t\t\t  --------------------------------------------------------------\n";    
				    	cout << "\t\t\t\t\t Thanks for using our service! \n";
		 				cout << "\t\t\t  --------------------------------------------------------------\n\n"; 
			    
				    	ifstream inf("thanks.txt");
				
						char str[300];
					
						while(inf)
						{
							inf.getline(str, 300);
							if(inf) cout << str << endl;
						}
					  	
						inf.close();
						
			        	break;
			    	}
			    	else
			    	{
						cout << "\n\n\n\t\t Error! Enter a valid option.\n\n" << endl;
				    	
				    	system("pause");
				    	system("cls");
				    	continue;
		    		}
			}
		}	
};

int main()
{
	Login S1;		// Creating an "S1" object of the class "Login"
	welcome S2;	   // Creating an "S2" object of the class "welcome" 
	
	S1.login();
	S2.process();
}
