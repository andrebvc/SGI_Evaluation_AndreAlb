#include <iostream>
#include "SGI_Evaluation_AndreAlbuquerque.h"
using namespace std;

int main()
{
    //////////////////////
    ///// Question 1 /////
    //////////////////////

    // This first question is mainly done with the header
    // and the test cases
    
    cout << "Working on the 1st Question.\n";
    
    cout << "Finished checking the 1st Question.\n";

    //////////////////////
    ///// Question 2 /////
    //////////////////////

    // I understand that this might not be the best approach for this problem
    // as it takes quite a while to reach the desired position of 1500
    // Unfortunately, I couldn't think of a more optimized way of doing it with the given time

    cout << "Working on the 2nd Question. This might take a while...\n";

    long requestedNumber = findRequestedNumber(1500);

    cout << "The number on the 1500th position is: " << requestedNumber << "\n\n";

    cout << "Finished. Press enter to close the program.";
    cin.ignore();
}