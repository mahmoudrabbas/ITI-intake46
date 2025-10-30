//
// Created by PC on 10/30/2025.
//


template <typename T>
void analyze(int count, ...);

template <>
void analyze<string>(int count, ...);



void task2() {
    try {
        analyze<double>(0);
    }catch(exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    try {
        analyze<string>(0, "Hello", "World!");
    }catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}



template<typename  T>
void analyze(int count,...) {

    if (count == 0) {
        throw runtime_error("No args found");
    }
    va_list args;
    va_start(args, count);
    double arr [count];
    for (int i = 0; i < count; i++) {
        arr[i] = va_arg(args, double);
    }

    double sum = 0;
    for (int i = 0; i < count; i++) {
        sum += arr[i];
    }
    double avg = sum / count;

    double sum2 = 0;
    for (int i = 0; i < count; i++) {
        sum2 += pow(arr[i] - avg, 2);
    }


    double variance = sum2 / count;

    cout << "Average: "<<avg << endl;
    cout << "Variance: "<<variance<<endl;
    va_end(args);
}


template<>
void analyze<string>(int count, ...) {
    // cout << count << endl;
    if (count == 0)
        throw runtime_error("No words found!");

    va_list args;
    va_start(args, count);

    string result;
    for (int i = 0; i < count; i++) {
        string s = va_arg(args, char*);
        result += s + " ";
    }


    cout << result << endl;

    va_end(args);
}


#ifndef DAY4_TASK2_H
#define DAY4_TASK2_H

#endif //DAY4_TASK2_H