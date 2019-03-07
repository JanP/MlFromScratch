#ifndef NEURON_H
#define NEURON_H

#include <vector>

class Neuron {
    public:
        Neuron(std::vector<double> &weights, double bias);
        double feedForward(std::vector<double> &inputs);
    private:
        std::vector<double> weights;
        double bias;
};

#endif
