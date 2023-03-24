#include "sudoku.h"
#include "SudokuSolver.h"

int main()
{
    const auto sudoku_vector = std::vector<std::vector<int>>{
        /*{0,7,0,0,0,1,0,0,0},
        {0,3,5,0,0,0,0,7,9},
        {0,0,4,0,5,0,6,0,8},
        {0,4,0,6,7,0,0,0,0},
        {0,0,8,0,0,0,0,6,0},
        {0,0,0,1,0,4,7,0,3},
        {9,8,0,0,0,3,0,0,0},
        {6,2,0,5,1,8,0,4,7},
        {4,5,0,7,9,0,8,3,2}};*/
         {0,0,6,0,0,1,8,4,9},
         {0,3,0,0,0,0,0,0,0},
         {0,0,0,0,2,0,0,0,6},
         {0,0,0,4,0,0,3,2,0},
         {4,0,0,0,0,3,0,0,0},
         {6,0,0,0,0,8,0,0,0},
         {0,1,0,0,6,0,0,0,3},
         {0,0,0,0,0,5,0,0,4},
         {0,2,9,0,7,4,0,0,5}};


    sudoku temp{ sudoku_vector };
    solve_sudoku(sudoku_vector);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
