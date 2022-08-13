#include<iostream>

using namespace std;

int adjMatrix[20][20];
int powMatrix[4][20][20];
int strongMatrix[20][20];

/*
0 0 0 1
1 0 1 1
1 0 0 1
0 0 1 0
*/

void createMatrix(int n) {
    cout << "Enter the adjacency matrix : \n";

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> adjMatrix[i][j];
        }
    }
}

void createPowMatrix(int n) {
    int tempMatrix[n][n];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            powMatrix[0][i][j] = adjMatrix[i][j];
        }
    }

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                int temp = 0;
                for(int l = 0; l < n; l++) {
                    temp += powMatrix[i-1][j][l] * powMatrix[0][l][k];
                }
                powMatrix[i][j][k] = temp;
            }
        }
    }
}

bool is_strongly_connected(int n) {
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            strongMatrix[i][j] = 0;
            strongMatrix[i][j] = powMatrix[0][i][j] + powMatrix[1][i][j] + powMatrix[2][i][j] + powMatrix[3][i][j];
            if(strongMatrix[i][j] == 0) cnt++; 
        }
    }
    if(cnt > 0) return true;
    else return false;
}

void printMatrix(int n) {
    cout << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                cout << powMatrix[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << endl << endl;
}

void detailedPrint(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(powMatrix[i][j][k] > 0) {
                    cout << "There are " << powMatrix[i][j][k] << " path of length " << i+1 << " from " << j << " to " << k << endl;
                }
            }
        }
        cout << "\n";
    }
}

int main() {
    int n;
    cout << "Enter number of Nodes : ";
    cin >> n;

    createMatrix(n);

    createPowMatrix(n);

    printMatrix(n);

    detailedPrint(n);

    cout << endl << endl;
    if(is_strongly_connected(n)) cout << "Strongly Connected!" << endl;
    else cout << "Not Strongly Connected!" << endl;
    
    return 0;
}
