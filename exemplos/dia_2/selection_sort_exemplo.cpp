#include <bits/stdc++.h>
#include <cstdlib>
#include <stdlib.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

using namespace std;

vector<string> colors = {GREEN, MAGENTA};

void printChanges(vector<int> &before, vector<int> &after) {
    int a = -1, b = -1;

    for (int i = 0; i < before.size(); i++) {
        if (before[i] != after[i]) {
            if (a == -1) a = before[i];
            else b = before[i];
        }
    }

    cout << "Era:   ";
    for (int x : before) {
        if (x == a) cout << BOLD << GREEN << x << RESET << " ";
        else if (x == b) cout << BOLD << MAGENTA << x << RESET << " ";
        else cout << x << " ";
    }

    cout << endl << "Virou: ";
    for (int x : after) {
        if (x == a) cout << BOLD << GREEN << x << RESET << " ";
        else if (x == b) cout << BOLD << MAGENTA << x << RESET << " ";
        else cout << x << " ";
    }

    cout << endl;
}

void printArray(vector<int> &arr, int from) {
    for (int i = from; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    cout << RESET << endl;
}

void selectionSort(vector<int> &arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;

        cout << "Iteração número " << i+1 << endl;
        cin.get();

        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j; 
            }
        }

        cout << "Menor elemento encontrado: " << arr[min_idx] << endl;
        cout << "Está na posição: " << min_idx+1 << BOLD << RED << " (índice " << min_idx << ")" << RESET << endl;
        cin.get();

        cout << "Vou trocar " << arr[min_idx] << " de lugar com " << arr[i] << endl;
        cin.get();

        vector<int> before = arr;
        swap(arr[i], arr[min_idx]);

        printChanges(before, arr);

        cin.get();
        system("clear");
    }
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};

    cout << "Iniciando ordenação..." << endl;

    cout << "Estado do vetor: " << BOLD << RED; printArray(arr,0);

    cin.get();
    system("clear");

    selectionSort(arr);

    cout << "Acabou" << endl;;

    return 0;
}
