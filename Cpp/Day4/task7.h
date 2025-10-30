//
// Created by PC on 10/30/2025.
//

#include <chrono>
#include <stdexcept>
#include <algorithm>
#include <numeric>

using namespace std::chrono;

template<typename T>
void benchmarkVector(const vector<T>& data, double& minTime, double& maxTime, double& avgTime) {
    if (data.empty())
        throw runtime_error("Vector is empty — cannot benchmark!");

    vector<double> times;

    for (int i = 0; i < 5; ++i) {
        auto start = high_resolution_clock::now();

        T sum{};
        for (const auto& val : data) {
            sum = sum + val;
        }

        auto end = high_resolution_clock::now();
        double duration = duration_cast<microseconds>(end - start).count();
        times.push_back(duration);
    }

    minTime = *min_element(times.begin(), times.end());
    maxTime = *max_element(times.begin(), times.end());
    avgTime = accumulate(times.begin(), times.end(), 0.0) / times.size();
}

template<>
void benchmarkVector<string>(
    const vector<string>& data,
    double& minTime,
    double& maxTime,
    double& avgTime
) {
    if (data.empty())
        throw runtime_error("Vector<string> is empty — cannot benchmark!");

    vector<double> times;

    for (int i = 0; i < 5; ++i) {
        auto start = high_resolution_clock::now();

        string combined;
        for (const auto& s : data) {
            combined += s;
        }

        auto end = high_resolution_clock::now();
        double duration = duration_cast<microseconds>(end - start).count();
        times.push_back(duration);
    }

    minTime = *min_element(times.begin(), times.end());
    maxTime = *max_element(times.begin(), times.end());
    avgTime = accumulate(times.begin(), times.end(), 0.0) / times.size();
}

void task7() {
    try {
        vector<int> v1(1000000, 5);
        vector<double> v2(100000, 3.14);
        vector<string> v3(10000, "Hello World");

        double minT, maxT, avgT;

        cout << "Int Vector:\n";
        benchmarkVector(v1, minT, maxT, avgT);
        cout << "Min: " << minT << " Max: " << maxT << " Avg: " << avgT << " \n";

        cout << "Double Vector:\n";
        benchmarkVector(v2, minT, maxT, avgT);
        cout << "Min: " << minT << " Max: " << maxT << " Avg: " << avgT << " \n";

        cout << "String Vector:\n";
        benchmarkVector(v3, minT, maxT, avgT);
        cout << "Min: " << minT << " Max: " << maxT << " Avg: " << avgT << " \n";

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

}



#ifndef DAY4_TASK7_H
#define DAY4_TASK7_H

#endif //DAY4_TASK7_H