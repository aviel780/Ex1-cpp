#include "mat.hpp"
#include <iostream>
#include <string>

using namespace std;
namespace ariel {
    void validarguments(int col, int row, char firstch, char secondch) {
        if(col == 0 and row ==0){
            return;
        }
        if (col <= 0 || row <= 0 ||  col % 2 == 0 || row % 2 == 0) {
            throw invalid_argument("The cloom and the rows cant be odd or zero");
        }

    }

    string mat(int col, int row, char firstch, char secondch) {

        validarguments(col, row, firstch, secondch);
        return "hello world";
    }

}