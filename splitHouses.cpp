// You live in a village. The village can be represented as a line that contains  grids. Each grid can be denoted as a house that is marked as H or a blank space that is marked as .

// A person lives in each house. A person can move to a grid if it is adjacent to that person. Therefore, the grid must be present on the left and right side of that person.

// Now, you are required to put some fences that can be marked as B on some blank spaces so that the village can be divided into several pieces. A person cannot walk past a fence but can walk through a house.

// You are required to divide the house based on the following rules:

// A person cannot reach a house that does not belong to that specific person.
// The number of grids each person can reach is the same and it includes the grid in which the house is situated.
// In order to show that you are enthusiastic and if there are many answers, then you are required to print the one where most fences are placed.
// Your task is to decide whether there is a possible solution. Print the possible solution.

#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    char str[n];

    for (int i = 0; i < n; i++){
        cin >> str[i];
    }

    int flag = 0;

    for (int i = 0; i < n; i++){
        if (str[i] == 'H' && str[i + 1] == 'H'){
            flag = 1;
            break;
        }
        else{
            if (str[i] == '.'){
                str[i] = 'B';
            }
        }
    }

    if (flag == 1){
        cout << "NO";
    }
    else{
        cout << "YES" << endl;
        for (int i = 0; i < n; i++){
            cout << str[i];
        }
    }
}