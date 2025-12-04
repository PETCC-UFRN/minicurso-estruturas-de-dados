#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

void printArray(vector<int> &arr, int from) {
    for (int i = from; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void selectionSort(vector<int> &arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;

        cout << "Iteração número " << i+1 << endl;
        cout << "Vou percorrer: "; printArray(arr,i);
        cin.get();

        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j; 
            }
        }

        cout << "Menor elemento encontrado: " << arr[min_idx] << endl;
        cout << "Está na posição: " << min_idx+1 << " (índice " << min_idx << ")" << endl;
        cin.get();

        cout << "Vou trocar " << arr[min_idx] << " de lugar com " << arr[i] << endl;
        swap(arr[i], arr[min_idx]);
        cin.get();

        cout << "A lista atualmente está assim: "; printArray(arr,0);
        cin.get();
        system("clear");
    }
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};

    cout << "Iniciando ordenação..." << endl;

    cout << "Estado do vetor: "; printArray(arr,0);

    cin.get();
    system("clear");

    selectionSort(arr);

    cout << "Acabou" << endl;;

    return 0;
}
