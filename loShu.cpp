#include <iostream>


using namespace std;

const int ROW = 3;
const int COL = 3;

void inputValidation(int matrix[][ROW]);


bool sqrCheck = true;

int main() {
    main :

    cout << "Creating Lo Shu Square..." << endl;
    int matrix[ROW][COL];
    int leftDiagSum = 0;
    int rowSum = 0;
    int colSum = 0;
    int rightDiagSum = 0;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            matrix[i][j] = 0;

    cout << "Enter Nine Numbers(1-9)" << endl;
    inputValidation(matrix);


    for (int i = 0; i < ROW; i++) {
        rowSum = 0;
        for (int j = 0; j < COL; j++) {
            rowSum += matrix[i][j];
        }

        if (rowSum != 15) {
            sqrCheck = false;
        }


    }


    for (int j = 0; j < COL; j++) {
        colSum = 0;
        for (int i = 0; i < ROW; i++) {
            colSum += matrix[i][j];

        }
        if (colSum != 15) {
            sqrCheck = false;
        }

    }


    for (int i = 0; i < 3; i++) {

        leftDiagSum += matrix[i][i];
    }
    if (leftDiagSum != 15) {
        sqrCheck = false;
    }


    for (int i = 0; i < 3; i++) {

        int j = (COL - 1) - i;

        rightDiagSum += matrix[i][j];

    }
    if (rightDiagSum != 15) {
        sqrCheck = false;
    }

    if (sqrCheck) {
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                cout << matrix[i][j] << "  ";


            }
            cout << endl;
        }
        cout << "This is a Lo Shu Magic Square!" << endl;
    } else {

        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                cout << matrix[i][j] << "  ";
            }
            cout << endl;
        }
        cout << "Sorry...This is not a Lo Shu Magic Square." << endl;
        cout << "Would you like to try again? (y/n)" << endl;
        string answer;
        cin >> answer;
        if (answer == "y") {
            goto main;
        } else {
            return 0;
        }
    }
    return 0;
}


void inputValidation(int matrix[][ROW]) {
    int count = 0;
    int num = 0;

    input:

    cout << "Number " << count + 1 << ":" << endl;
    cin >> num;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (num == matrix[i][j] || num > 9) {
                cout << "Error...Invalid Number. Try again." << endl;
                goto input;
            } else {
                if (matrix[i][j] == 0) {
                    matrix[i][j] = num;
                    count++;
                    if (count == 9) {
                        return;
                    }

                    goto input;
                }

            }

}

