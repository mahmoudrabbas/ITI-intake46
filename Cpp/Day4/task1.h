

#include <vector>
using namespace std;


void tempReader(vector<double>&data, double& min, double& max , double& avg);



void task1() {
    vector<double> data = {1.0, -2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0};
    double min, max, avg;
    try {
        tempReader(data, min, max, avg);

        cout <<"Min:"<< min << " Max:" << max << " Avg:" << avg << endl;
    }catch(exception& e) {
        cout << "Error: " << e.what() << endl;
    }

}


void tempReader(vector<double> &data, double &min, double &max, double &avg) {
    min = data[0];
    max = data[0];
    double sum = 0;
    for (auto temp : data) {

        if (temp < 0) {
            throw runtime_error("temp is negative");
        }
        sum += temp;
        if (temp < min) {
            min = temp;
        }
        if (temp > max) {
            max = temp;
        }
    }

    avg = sum / data.size();
}


#ifndef DAY4_TASK1_H
#define DAY4_TASK1_H

#endif //DAY4_TASK1_H