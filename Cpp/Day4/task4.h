//
// Created by PC on 10/30/2025.
//



// Pointer Operations Simulator
void task4() {
    int size;
    cin >> size;
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        cin>>arr[i];
    }

    int* ptr = &arr[0]; // = arr


    for (int i = 0; i < size; i++) {
        cout << "Element " << i << " = " << *ptr << endl;
        ptr++;
    }


    // ---------------1----------

    int a = 5, b = 6;

    const int* myPtr = &a;
    // *myPtr = 8;

    cout << *myPtr << endl;

    myPtr = &b;
    // *myPtr = 10;
    cout << *myPtr << endl;


    // ---------------2----------------
    int* const constPtr = &a;

    cout << *constPtr << endl;
    *constPtr = 88;
    cout << *constPtr << endl;
    // constPtr = &b;

}

#ifndef DAY4_TASK4_H
#define DAY4_TASK4_H

#endif //DAY4_TASK4_H