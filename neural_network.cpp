#include "neural_network.hpp"

template<typename T>
NeuralNetwork<T>::NeuralNetwork(std::vector<Neuron<T> > &h, Neuron<T> &o) :
    hidden(h), output(o) {}

template<typename T> double
NeuralNetwork<T>::feedForward(std::vector<double> &inputs) {
    std::vector<double> hidden_output(hidden.size());
    for (size_t i = 0; i < hidden.size(); i++) {
        hidden_output[i] = hidden[i].feedForward(inputs);
    }

    return output.feedForward(hidden_output);
}

template class NeuralNetwork<Sigmoid>;
