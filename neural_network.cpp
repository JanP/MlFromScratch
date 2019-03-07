#include "neural_network.hpp"

NeuralNetwork::NeuralNetwork(std::vector<Neuron> &h, Neuron &o) : hidden(h), output(o) {}

double
NeuralNetwork::feedForward(std::vector<double> &inputs) {
    std::vector<double> hidden_output(hidden.size());
    for (size_t i = 0; i < hidden.size(); i++) {
        hidden_output[i] = hidden[i].feedForward(inputs);
    }

    return output.feedForward(hidden_output);
}
