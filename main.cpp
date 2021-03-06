#include <iostream>
#include <math.h>
#include <string>
#include "main.h"

class QuadraticEquation
{
    private:
        double a;
        double b;
        double c;
        double result1;
        double result2;

        //Solve the quadratic equation represented by a, b, and c; the results are stored in result1 and result2
        int solve()
        {
            result1 = (b * -1) + sqrt((b * b) - (4 * a * c));
            result1 /= (2 * a);
            result2 = (b * -1) - sqrt((b * b) - (4 * a * c));
            result2 /= (2 * a);
            if(isnan(result1))
            {
                return 0;   //Indicates no real solutions can be found
            }
            else
            {
                return 1;   //Indicates at least one real solution was found
            }
        }
    
    public:
        //Constructor
        QuadraticEquation(double aInput, double bInput, double cInput)
        {
            a = aInput;
            b = bInput;
            c = cInput;
        }

        void printResults()
        {
            using namespace std;
            int realSolutionExists = solve();
            if(realSolutionExists == 1)
            {
                if(result1 == result2)
                {
                    cout << "The solution to the quadratic equation is " << result1 << "." << endl;
                }
                else
                {
                    cout << "The solutions to the quadratic equation are " << result1 << " and " << result2 << "." << endl;
                }
            }
            else
            {
                cout << "No real solutions to the quadratic equation were found." << endl;
            }
        }
};

int main()
{
    using namespace std;
    string version("Project IceForest Calculator C 1.2");
    string name("Version 1.2");
    cout << "\nWelcome to Project IceForest Calculator C!" << endl;
    int mainMenuChoice = 0; //Stores the user's choice of which option in the main menu to execute
    while(1)
    {
        //Display the menu, prompt the user for their choice, and save it in mainMenuChoice
        printMainMenu();
        cout << "Please enter your choice: ";
        cin >> mainMenuChoice;
        switch(mainMenuChoice)
        {
            case 1: //Add 2 Numbers
            {
                cout << "\nADDITION:\n";
                double num1, num2;
                cout << "Please enter the first number: ";
                cin >> num1;
                cout << "Please enter the second number: ";
                cin >> num2;
                cout << "The sum is: " << (num1 + num2) << endl;
                break;
            }
            case 2: //Subtract 2 Numbers
            {
                cout << "\nSUBTRACTION:\n";
                double num1, num2;
                cout << "Please enter the first number: ";
                cin >> num1;
                cout << "Please enter the second number: ";
                cin >> num2;
                cout << "The difference is: " << (num1 - num2) << endl;
                break;
            }
            case 3: //Multiply 2 Numbers
            {
                cout << "\nMULTIPLICATION:\n";
                double num1, num2;
                cout << "Please enter the first number: ";
                cin >> num1;
                cout << "Please enter the second number: ";
                cin >> num2;
                cout << "The product is: " << (num1 * num2) << endl;
                break;
            }
            case 4: //Divide 2 Numbers
            {
                cout << "\nDIVISION:\n";
                double num1, num2;
                cout << "Please enter the first number: ";
                cin >> num1;
                cout << "Please enter the second number: ";
                cin >> num2;
                cout << "The quotient is: " << (num1 / num2) << endl;
                break;
            }
            case 5: //Square & Cube Roots
            {
                cout << "\nSQUARE & CUBE ROOTS:\n";
                double input;
                cout << "Please enter the number: ";
                cin >> input;
                cout << "Square Root: " << sqrt(input) << endl;
                cout << "Cube Root: " << cbrt(input) << endl;
                break;
            }
            case 6: //Exponents
            {
                cout <<"\nEXPONENTS:\n";
                double base, power;
                cout << "Please enter the base: ";
                cin >> base;
                cout << "Please enter the number to raise " << base << " to: ";
                cin >> power;
                cout << "Result: " << pow(base, power) << endl;
                break;
            }
            case 7: //Logarithms
            {
                cout << "\nLOGARITHMS:\n";
                double input;
                cout << "Please enter the number: ";
                cin >> input;
                cout << "Log Base e: " << log(input) << endl;
                cout << "Log Base 10: " << log10(input) << endl;
                break;
            }
            case 8: //Quadratic Equation Solver
            {
                cout << "\nQUADRATIC EQUATION SOLVER:\n";
                double a, b, c;
                cout << "Please enter the quadratic equation in the form ax^2 + bx + c." << endl;
                cout << "a: ";
                cin >> a;
                cout << "b: ";
                cin >> b;
                cout << "c: ";
                cin >> c;
                QuadraticEquation input(a, b, c);
                input.printResults();
                break;
            }
            case 9: //Average Calculator
            {
                cout << "\nAVERAGE CALCULATOR:\n";
                int numNumbers;
                cout << "Please enter the number of numbers to find the average of: ";
                cin >> numNumbers;
                double sum = 0;
                int i;
                for(i = 0; i < numNumbers; i++)
                {
                    double temp;
                    cout << "Please enter Number #" << (i + 1) << ": ";
                    cin >> temp;
                    sum += temp;
                }
                cout << "Average: " << (sum / numNumbers) << endl;
                break;
            }
            case 10:    //Pythagorean Triple Finder
            {
                cout <<"\nPYTHAGOREAN TRIPLE FINDER:\n";
                int num1, num2;
                //Get the first number from the user and store it in num1
                cout << "Please enter the first number: ";
                cin >> num1;
                //If the first number is less than 1, print a message and exit
                if(num1 < 1)
                {
                    cout << "ERROR: The first number is less than 1!" << endl;
                    break;
                }
                //Get the second number from the user and store it in num2
                cout << "Please enter the second number: ";
                cin >> num2;
                //If the second number is less than 1, print a message and exit
                if(num2 < 1)
                {
                    cout << "ERROR: The second number is less than 1!" << endl;
                    break;
                }
                //If the second number is larger than the first number, then switch the first and second numbers
                if(num2 > num1)
                {
                    int temp = num1;
                    num1 = num2;
                    num2 = temp;
                }
                //Calculate and print the Pythagorean Triple
                int a, b, c;
                a = (int)(pow(num1, 2) - pow(num2, 2));
                b = 2 * num1 * num2;
                c = (int)(pow(num1, 2) + pow(num2, 2));
                cout << "The Pythaogrean Triple is: " << a << ", " << b << ", and " << c << endl;
                break;
            }
            case 0: default:    //Exit
            {
                return 0;
            }
            case -1:    //About
            {
                cout << "\nABOUT:\n";
                cout << version << endl;
                cout << name << endl;
                break;
            }
            case -2:    //Disclaimer
            {
                printDisclaimer();
                break;
            }
        }
    }
}

//Display the menu
void printMainMenu()
{
    using namespace std;
    cout << "\nMENU:" << endl;
    cout << "1: Add 2 Numbers" << endl;
    cout << "2: Subtract 2 Numbers" << endl;
    cout << "3: Multiply 2 Numbers" << endl;
    cout << "4: Divide 2 Numbers" << endl;
    cout << "5: Square & Cube Roots" << endl;
    cout << "6: Exponents" << endl;
    cout << "7: Logarithms" << endl;
    cout << "8: Quadratic Equation Solver" << endl;
    cout << "9: Average Calculator" << endl;
    cout << "10: Pythagorean Triple Finder" << endl;
    cout << "0: Exit" << endl;
    cout << "-1: About" << endl;
    cout << "-2: Disclaimer" << endl;
}

//Display the disclaimer
void printDisclaimer()
{
    using namespace std;
    cout << "\nDISCLIAMER:" << endl;
    cout << "1. Neither Project IceForest Calculator C, nor the programmer(s) and/or developer(s) of Project IceForest Calculator C, nor the distributor(s) of Project IceForest Calculator C, nor anyone or anything else that is involved with Project IceForest Calculator C, are responsible for any misinformation, any inaccuracy, any problems, any harm, or any other negative consequences, whether physical or otherwise, caused by Project IceForest Calculator C or as a result of using Project IceForest Calculator C." << endl;
    cout << "2. Calculations and conversions made in Project IceForest Calculator C are not guaranteed to be accurate and/or exact." << endl;
}