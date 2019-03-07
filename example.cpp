#include <iostream>
#include <cstdlib>

#include "neuron.hpp"
#include "neural_network.hpp"

static double
output_neuron() {
    std::vector<double> weights = {0.0, 1.0};
    double bias = 4.0;

    Neuron n(weights, bias);

    std::vector<double> inputs = {2.0, 3.0};

    return n.feedForward(inputs);
}

static double
output_neural_network() {
    std::vector<double> weights {0.0, 1.0};
    double bias = 0;

    std::vector<Neuron> hidden = {
        Neuron(weights, bias),
        Neuron(weights, bias)
    };

    Neuron output(weights, bias);

    NeuralNetwork nn(hidden, output);

    std::vector<double> inputs = {2.0, 3.0};

    return nn.feedForward(inputs);
}

int
main() {
    std::cout << "Output neuron: " << output_neuron() << std::endl;
    std::cout << "Output neural network: " << output_neural_network();
    std::cout << std::endl;

    return EXIT_SUCCESS;
}
