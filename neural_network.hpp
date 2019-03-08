#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include <vector>
#include "neuron.hpp"

template<typename T>
class NeuralNetwork {
    public:
        NeuralNetwork(std::vector<Neuron<T> > &h, Neuron<T> &o);
        double feedForward(std::vector<double> &inputs);
    private:
        std::vector<Neuron<T> > hidden;
        Neuron<T> output;
};

#endif
