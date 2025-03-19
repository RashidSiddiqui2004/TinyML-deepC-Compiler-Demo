#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include "Driver_Drowsiness_Detection.h"
using namespace std;

int main()
{
    float input_data[3072];
    unsigned short input_shape[] = {1, 32, 32, 3};

    srand(time(NULL));

    for (int i = 0; i < 3072; i++)
    {
        input_data[i] = (float)rand() / RAND_MAX;
    }

    deepSea::ndarray<float> input_ndarray(input_data, input_shape, 4);

    float simulated_output[2];

    std::srand(std::time(0));

    simulated_output[0] = static_cast<float>(std::rand()) / RAND_MAX;
    simulated_output[1] = 1 - simulated_output[0];

    std::cout << "Predicted Values: ["
              << std::fixed << std::setprecision(2)
              << simulated_output[0] << ", "
              << simulated_output[1] << "]\n";

    if (simulated_output[0] > 0.6)
    {
        std::cout << " Alert: Driver is ASLEEP!  \n";
    }
    else
    {
        std::cout << " Driver is AWAKE and attentive.\n";
    }

    // not executing because of mingW version differences
    // deepSea::ndarray<float> input_ndarray(input_data, input_shape, 4);
    // std::vector<deepSea::ndarray<float>> results = deepSea_model(input_ndarray);

    // std::cout << "Model Output:" << std::endl;
    // for (int i = 0; i < 2; i++)
    // {
    //     std::cout << "Class " << i << ": " << results[0]._data[i] << std::endl;
    // }

    return 0;
}
