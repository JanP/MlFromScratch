#include "neuron.hpp"

#include <cmath>
#include <stdexcept>

static double
sigmoid(double x) {
    return (1.0 / (1.0 + exp(-x)));
}

static double
dot_product(std::vector<double> &inputs, std::vector<double> &weights, double bias) {
    double d_product = bias;
    for (size_t i = 0; i < inputs.size() && i < weights.size(); i++) {
        d_product += (inputs[i] * weights[i]);
    }

    return d_product;
}

Neuron::Neuron(std::vector<double> &w, double b) : weights(w), bias(b) {}

double
Neuron::feedForward(std::vector<double> &inputs) {
    if (inputs.size() != weights.size()) {
        throw std::range_error("Different sizes!");
    }

    return sigmoid(dot_product(inputs, weights, bias));
}
