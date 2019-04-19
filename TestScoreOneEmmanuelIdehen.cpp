//
//  main.cpp
//  TestScoreOneEmmanuelIdehen
//  due april 18, 2019
//  Created by Emmanuel Idehen on 4/18/19.
//  Copyright © 2019 Emmanuel Idehen. All rights reserved.
//  Submitted to Mr. Marcus Golden(CS204 Programming II)


/*
 problem:
 Test Scores
 Write a program that dynamically allocates an array large enough to hold a user-defined
 number of test scores. Once all the scores are entered, the array should be passed to a
 function that sorts them in ascending order. Another function should be called that
 calculates the average score. The program should display the sorted list of scores and
 averages with appropriate headings. Use pointer notation rather than array notation
 whenever possible.
 Input Validation: Do not accept negative numbers for test scores.
 
 design:
 
 declare variables
 and dynamically allocate memory to the user which is stored in the heap
 crate function to get the users information and score
 create a function to calculate the average of the test score
 sort the scores
 create a function to ouput the information to the screeen
 
 
 
 */

#include <iostream>
#include <iomanip>
using namespace std;
//===========================================

//function to get users information and validate the users input 

void Information(double *Test, int memory)
{
    cout << "Enter each of the scores.\n";
    for (int i = 0; i < memory; i++)
    {
        do
        {
            cout << "Score " << (i + 1) << ": ";
            cin  >> *(Test + i);
            
            if (*(Test + i) < 0)
            {
                cout << "Scores must be greater than 0.\n"<<endl;
            }
            
        } while (*(Test + i) < 0);
    }
}
//selection sort
void selectionSort(double *Test, int memory)
{
    int startscan, minIndex;
    double minValue;
    
    for (startscan = 0; startscan < (memory - 1); startscan++)
    {
        minIndex = startscan;
        minValue = *(Test + startscan);
        for (int i = startscan + 1; i < memory; i++)
        {
            if (*(Test + i) < minValue)
            {
                minValue = *(Test + i);
                minIndex = i;
            }
            
        }
        *(Test + minIndex) = *(Test + startscan);
        *(Test + startscan) = minValue;
    }
}
//get the average of the scores
double theAverage(double *Test, int memory)
{
    double Total;
    
    for (int i = 0; i < memory; i++)
    {
        Total += *(Test + i);
    }
    
    return (Total / memory);
}
//function to print users information
void printInformation(double *Test, int memory, double Avg, string name)
{
    
    cout << "\nHello "<< name <<" this are your results:";
    cout << "\n    Test scores\n";
    cout << "Number of scores: " << memory << endl;
    cout << "Scores in ascending order:\n";
    for (int i = 0; i < memory; i++)
    {
        cout << "For number " << (i + 1) << ": " << *(Test + i) << endl;
    }
   
    cout << "Average score: " << Avg << endl;
}








int main()
{
    //declare variables
    double *Test,
    Average;
    int memory;
    string name;
    //get users name
    cout << "Befor we begin enter your name: \n";
    cout <<"Enter your input:" <<endl;
    getline(cin,name);
    // Get number of scores
    cout << "How many test scores do you have to average? \n";
    cout <<"Enter your input:" <<endl;
    cin  >> memory;
    
  //using new to dynamically allocate memory to the user which is stored in the heap
    Test = new double[memory];    // Allocate memory
    //call functions
   Information(Test, memory);
    
    selectionSort(Test, memory);
    
    Average = theAverage(Test, memory);
    
    printInformation(Test, memory, Average, name);
    
    
    //free heap or deallocate memory
    delete [] Test;
    Test = nullptr;
    
    return 0;
}


/*
test case
 
 Befor we begin enter your name:
 Enter your input:
 Emmanuel Idehen
 How many test scores do you have to average?
 Enter your input:
 2
 Enter each of the scores.
 Score 1: 4
 Score 2: 6
 
 Hello Emmanuel Idehen this are your result
 Test scores
 Number of scores: 2
 Scores in ascending order:
 For number 1: 4
 For number 2: 6
 Average score: 5
 Program ended with exit code: 0
 
 
 test case 2
 
 Befor we begin enter your name:
 Enter your input:
 john
 How many test scores do you have to average?
 Enter your input:
 3
 Enter each of the scores.
 Score 1: 5
 Score 2: 4
 Score 3: 3
 
 Hello john  this are your results:
 Test scores
 Number of scores: 3
 Scores in ascending order:
 For number 1: 3
 For number 2: 4
 For number 3: 5
 Average score: 4
 Program ended with exit code: 0
 
 
 test case 3
 
 Befor we begin enter your name:
 Enter your input:
 sandra
 How many test scores do you have to average?
 Enter your input:
 2
 Enter each of the scores.
 Score 1: 8
 Score 2: 9
 
 Hello sandra  this are your results:
 Test scores
 Number of scores: 2
 Scores in ascending order:
 For number 1: 8
 For number 2: 9
 Average score: 8.5
 Program ended with exit code: 0
 
 
 */

