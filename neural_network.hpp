#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include <vector>
#include "neuron.hpp"

class NeuralNetwork {
    public:
        NeuralNetwork(std::vector<Neuron> &h, Neuron &o);
        double feedForward(std::vector<double> &inputs);
    private:
        std::vector<Neuron> hidden;
        Neuron output;
};

#endif
