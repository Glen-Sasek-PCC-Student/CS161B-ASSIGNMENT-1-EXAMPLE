// ------------- FILE HEADER -------------
// Author ✅:
// Assignment ✅:
// Date ✅:
// Citations:


// ------------- ZYBOOKS SCORES -------------
// Chapter ✅:
// Participation ✅:
// Challenge ✅:
// Labs ✅:


// ------------- DISCORD POSTS -------------
// https://discord.com/invite/URYKKf8YHm
// Count ✅:
// Links (Optional):


// ------------- DESIGN DOCUMENT -------------
// A. INPUT ✅:
// B. OUTPUT ✅:
// C. CALCULATIONS ✅:
// D. LOGIC and ALGORITHMS ✅:
//    (Optional) flow chart link or file name:


// ------------- TESTING -------------
// PASS ALL GIVEN SAMPLE RUN TESTS ✅:
// (Optional) Additional tests count:


// ------------- CODE -------------
#include <iostream>
#include <limits>
#include <cctype>
#include <iomanip>

using namespace std;

// Function prototypes (if any)
void welcome();
void displayMenu();


// This function will read an option and return to the called function through the reference parameter.
// Call the readInt function to do this.
// You must catch all invalid data such as characters, negative numbers etc.
// You must also do validation to make sure that the number is 1 or 2 and nothing other than that.
// Use a while loop to do this.
void readOption(int &option);


// Use this function to read the menu option from the user.
// It takes a string prompt, outputs it, reads a number from the user, validates and returns the num by reference.
// See Samplea01.cpp for the function. You may use the function in the sample.
// You must catch all invalid data such as characters, negative numbers etc.
void readInt(string prompt, int &num);


// Like read int but a double
void readDouble(string prompt, double &num);

// Call this function if the user selects 1 from the menu.
// This function will go through a loop and ask the user to enter item names and their cost until the user answers ‘n’ to the question -
// Do you want another item? (y/n):
// You must validate to make sure the user enters y/n for this question (it should not be case sensitive - must accept both uppercase and lowercase).
// Use a while loop to do this.
// The total cost must be returned through the reference parameter and be printed in main().
// Call the readDouble function to do this.
// You must catch all invalid data such as characters, negative numbers etc.
// Do not print anything in this function.
// The tip, discount, and final total must be printed in main().
void placeOrder(double &cost);


// This function takes the cost by value, and the tip and discount by reference.
// The function prompts the user to enter a tip amount, and reads into the tip parameter. This will be used to calculate the total, and it will also go back to main() so it can be printed in main().
// Call the readDouble function to do this. You must catch all invalid data such as characters, negative numbers etc.
// It then calculates the discount based on the total (including the tip), and returns the final total to main(). The discount amount goes back by reference to be printed in main(). See sample run.
// Do not print anything inside the function.
double tipDiscount(double &tip, double &discount, double cost);


// Main function
// https://en.cppreference.com/w/cpp/language/main_function.html
int main(int argc, char* argv[]) {

    int menu_choice = 1;
    welcome();

    do {
        displayMenu();
        readOption(menu_choice);

        if(menu_choice == 1) {
            double order_USD = 0.0;
            placeOrder(order_USD);

            double tip_USD = 0.0;
            double discount_USD = 0.0;
            float total_USD = 0.0;

            cout << endl;
            cout << endl;
            cout << fixed << setprecision(2);
            total_USD = tipDiscount(tip_USD, discount_USD, order_USD);

            cout << "Total: $" << total_USD << endl;

        }
    } while (menu_choice == 1);

    return 0;
}

// Function implementations (if any)
void welcome() {
    string welcome = "🍇 🍈 🍉   🍋 🍌 🥭   🍎 🍏 🍑   🍒 🫐    \n"
                     "\n"
                     "Welcome to my Food Cart Program!\n";
    cout << welcome;
}

void displayMenu() {
    cout << "Pick an option:" << endl;
    cout << "    1. Place an order" << endl;
    cout << "    2. Quit" << endl;
}

void readOption(int &menu_choice) {
    bool valid_choice = false;

    do {
        readInt(">> ", menu_choice);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        valid_choice = menu_choice == 1 || menu_choice == 2;

        if(!valid_choice) {
            cout << "Invalid Option!" << endl;
        }
    } while (!valid_choice);
}

void readInt(string prompt, int &num) {
    bool next = true;

    while(next)
    {
        cout << prompt;
        cin >> num;
        // cout << "readInt(string prompt, int &num) " << num << endl;

        if(!cin) {
            cout << "Invalid input! Please try again!!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        } else {
            next = false;
        }
    }
}

void readDouble(string prompt, double &num) {
    bool next = true;

    while(next)
    {
        cout << prompt;
        cin >> num;
        // cout << "readDouble(string prompt, double &num) " << num << endl;

        if(!cin) {
            cout << "Invalid input! Please try again!!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        } else {
            next = false;
        }
    }
}

void placeOrder(double &order_USD) {
    char another_yn = 'y';
    double item_cost_USD;

    do {
        cout << endl;
        cout << endl;
        cout << "Enter the name of your item: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        readDouble("Enter the cost of your item $: ", item_cost_USD);
        order_USD = order_USD + item_cost_USD;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        bool next = true;

        while(next) {
            cout << "Do you want another item? (y/n): ";
            cin >> another_yn;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            another_yn = tolower(another_yn);

            switch(another_yn) {
                case 'y': // Fallthrough
                case 'n':
                    next = false;
                    break;

                default: {
                    cout << "Invalid input! Please try again!!" << endl;
                }
            }
        }

    } while (another_yn == 'y');
}

double tipDiscount(double &tip_USD, double &discount_USD, double order_USD) {
    cout << "Your order is: $" << order_USD << endl;
    readDouble("Enter tip $: ", tip_USD);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    double order_plus_tip_USD =  order_USD + tip_USD;

    cout << "Your order with tip is: $" << order_plus_tip_USD << endl;

    string discount_label = "0% discount: ";

    double discount_percent = 0.0;

    if(order_plus_tip_USD > 35 && order_plus_tip_USD < 50) {
        discount_percent = 0.05;
        discount_label = "5% discount: ";
    }

    if(order_plus_tip_USD > 50) {
        discount_percent = 0.10;
        discount_label = "10% discount: ";
    }

    discount_USD = order_plus_tip_USD * discount_percent;

    cout << discount_label << discount_USD << endl;

    return order_plus_tip_USD - discount_USD;
}


// ------------- DESIGN -------------
/*
Program Name:

Program Description:

Design:
A. INPUT
int menu_choice = 1;
char another_yn = 'y';
float item_cost_USD = 0.0;
float tip_USD = 0.0;


B. OUTPUT
float order_USD = 0.0;
float order_plus_tip_USD = 0.0;
float discount_percent = 0.0;
string discount_label = "0% discount: ";
float discount_USD = 0.0;
float total_USD = 0.0;

C. CALCULATIONS
order_plus_tip_USD discount_percent          discount_label
< 35               discount_percent = 0;     discount_label = "0% discount: ";
35 to 50           discount_percent = 0.05;  discount_label = "5% discount: ";
> 50               discount_percent = 0.10;  discount_label = "10% discount: ";

discount_USD = order_plus_tip_USD * discount_percent;

total_USD = order_plus_tip_USD - discount_USD;

D. LOGIC and ALGORITHMS
Design the logic of your program using pseudocode or flowcharts.
Use conditionals, loops, functions or array constructs.
List the steps in transforming inputs into outputs.
https://github.com/Glen-Sasek-PCC-Instructor/2025-06-22/blob/main/Pseudocode-Reference.txt

FUNCTION display_menu
    Pick an option:
    1. Place an order
    2. Quit
END FUNCTION

MESSAGE "Welcome to my Food Cart Program!"

REPEAT MAIN LOOP UNTIL QUIT
MAIN LOOP TO END:

CALL display_menu
INPUT menu_choice
Repeat until valid
EXIT ON QUIT

WHILE another_yn == 'y'
    PROMPT "Enter the name of your item: "
    ignore input to end of line

    PROMPT "Enter the cost of your item $: "
    INPUT item_cost_USD
    order_USD = order_USD + item_cost_USD;

    PROMPT "Do you want another item? "
    INPUT another_yn
END WHILE

LABEL "Your order is: "
DATA  order_USD

PROMPT "Enter tip $: "
INPUT tip_USD

order_plus_tip_USD = order_USD + tip_USD;

LABEL "Your order with tip is: $"
DATA  order_plus_tip_USD

CALC discount and total

LABEL discount_label
DATA  discount_USD

LABEL "Total: $"
DATA  total_USD






SAMPLE RUNS
🍇 🍈 🍉   🍋 🍌 🥭   🍎 🍏 🍑   🍒 🫐
🍅         🫒    🥥   🥑    🥔    🥕   🥓
🌽 🫑      🥬    🥦   🧄    🧅   🥜    🫘
🌰         🫚    🫛   🫜    🍞   🥐    🥖
🫓         🥨 🍗 🥩   🥯 🥞 🧇   🧀 🍖

Welcome to my Food Cart Program!

Pick an option:
    1. Place an order
    2. Quit
>> 9
Invalid Option!

Pick an option:
    1. Place an order
    2. Quit
>> 1

Enter the name of your item: Pasta
Enter the cost of your item $: 15.75
Do you want another item? (y/n): y

Enter the name of your item: Bowl
Enter the cost of your item $: 12.75
Do you want another item? (y/n): y

Enter the name of your item: Soda
Enter the cost of your item $: 3.50
Do you want another item? (y/n): x
Invalid Option!
Do you want another item? (y/n): x
>> n

Your order is: $32.00
Enter tip $: 3.50
Your order with tip is: $35.50
5% discount: $1.78
Total: $33.73

Pick an option:
    1. Place an order
    2. Quit
>> 1

Enter the name of your item: Fajita Bowl
Enter the cost of your item $: 20.75
Do you want another item? (y/n): y

Enter the name of your item: Vietnamese plate
Enter the cost of your item $: 22.75
Do you want another item? (y/n): y

Enter the name of your item: Soda
Enter the cost of your item $: 3.50
Do you want another item? (y/n): x
Invalid Option!
Do you want another item? (y/n): x
>> n

Your order is: $47.00
Enter tip $: 3.50
Your order with tip is: $35.50
10% discount: $5.70
Total: $51.30

Pick an option:
    1. Place an order
    2. Quit
>> 2

Thank you for using my program!

*/
