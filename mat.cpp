//After a lot of trying and sitting for days on the task, I was helped by an answer from the site:
//https://www.geeksforgeeks.org/create-a-matrix-with-alternating-rectangles-of-0-and-x/amp/
//And with her help I was able to solve the problem 

#include "mat.hpp"
#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
using namespace ariel;


namespace ariel
{
    string mat(int column, int row, char symbol1, char symbol2){
        if (row<0 || column<0){
            throw "ERROR: mat size should be allways positive and they not";
        }
        if (row%2==0 || column%2==0){
            throw "ERROR: mat size should always be odd and they not";
        }
        //Set the iterators outside the loops to preserve values between each iteration
        int i = 0;
        int z = 0;
        int l = 0;
    
        int r = row;
        int c = column; // Initialize variables in the length of the matrix sizes
        vector<vector<char>> a(row, vector<char>(column, 1));// Setting up a 2-dimensional vactor
        char x = symbol1; // the first symbol we want to initialize in the matrix


        while (z < row && l < column){
            //Fill the last column
            for (i = z; i < row; ++i){
                a[i][column-1] = x;
            }
            //Fill the first row
            for (i = l; i < column; ++i){
                a[z][i] = x;
            }
            //We will advance the indexes to move on to work on the more inner layers of the matrix between iterations
            z++;
            column--;
            //Fill the last row
            if (z < row){
                for (i = column-1; i >= l; --i){
                    a[row-1][i] = x;
                }
                row--;
            }
            //Fill the first column
            if (l < column){
                for (i = row-1; i >= z; --i){
                    a[i][l] = x;
                }
                l++;
            }
            // switch the symbol between the iterations for the purpose of filling the matrix with 2 symbols - one for each shell
            x = (x == symbol2)? symbol1: symbol2;
        }

        string mat;
        for (i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                mat += a[i][j];
            }
            mat += "\n";
        }
        return mat;
    }
}
