#include <iostream>
using namespace std;

int n, W;
int wt[20], val[20];
int b[20][20];

void accept(){
    cout << "Enter number of items: ";
    cin >> n;

    for(int i = 0; i < n; i++){
        cout << "Enter weight: ";
        cin >> wt[i];
        cout << "\n";
    }

    for(int i = 0; i < n; i++){
        cout << "Enter profit: ";
        cin >> val[i];
        cout << "\n";
    }
    cout << "Enter capacity: ";
    cin >> W;
    cout << "\n";
}

void display() {
    cout << "DP Table:\n";
    for(int i = 0; i <= n; i++) {
        for(int w = 0; w <= W; w++) {
            cout << b[i][w] << " \t";
        }
        cout << endl;
    }

    cout << "Maximum Profit: " << b[n][W] << endl;
}


void knapsack() {
    for(int i = 0; i <= n; i++) {
        for(int w = 0; w <= W; w++) {
            if(i == 0 || w == 0) {
                b[i][w] = 0;
            }
            else if(wt[i-1] <= w) {
                b[i][w] = max(
                    val[i-1] + b[i-1][w - wt[i-1]],
                    b[i-1][w]
                );
            }
            else {
                b[i][w] = b[i-1][w];
            }
        }
    }
}

void trace(){
    int i = n;
    int k = W;

    while(i > 0 && k > 0){
        if(b[i][k] != b[i-1][k]){
            cout << i << " is included\n";
            i--, k-=wt[i];
        }
        else
            i--;
    }
}

int main(){
    accept();
    knapsack();
    display();
    trace();
}
