//
// Created by PC on 10/30/2025.
//



// task 5 functions
template <typename T>
T computeAverage(T arr[], int size);

template<>
string computeAverage(string arr[], int size);

void task5() {
    int size;
    cin >> size;
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        cin>>arr[i];
    }

    cout << "compute Average: "<<computeAverage(arr,size) << endl;

    cin >> size;
    string* strs = new string[size];
    for (int i = 0; i < size; i++) {
        cin>>strs[i];
    }
    cout<<computeAverage<string>(strs,size) << endl;
}



template<typename  T>
T computeAverage(T arr[], int size) {
    T sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    return sum / size;
}


template<>
string computeAverage<string>(string arr[], int size) {
    string longest = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > longest) {
            longest = arr[i];
        }
    }

    return longest;
}




#ifndef DAY4_TASK5_H
#define DAY4_TASK5_H

#endif //DAY4_TASK5_H