#include "neuron.hpp"

#include <cmath>
#include <stdexcept>

double
Sigmoid::operator()(double x) {
    return (1.0 / (1.0 + exp(-x)));
}

static double
mean_squared_loss(std::vector<double> &expected, std::vector<double> &predicted) {
    double squared_error = 0.0;
    for (size_t i = 0; i < expected.size() && i < predicted.size(); i++) {
        squared_error += pow((expected[i] - predicted[i]), 2.0);
    }

    return (squared_error / expected.size());
}

static double
dot_product(std::vector<double> &inputs, std::vector<double> &weights, double bias) {
    double d_product = bias;
    for (size_t i = 0; i < inputs.size() && i < weights.size(); i++) {
        d_product += (inputs[i] * weights[i]);
    }

    return d_product;
}

template<typename T>
Neuron<T>::Neuron(std::vector<double> &w, double b) :
    weights(w), bias(b), activation(new T()) {}

template<typename T>
Neuron<T>::Neuron(const Neuron<T> &n) :
    weights(n.weights), bias(n.bias), activation(new T()) {}

template<typename T>
Neuron<T> & Neuron<T>::operator=(const Neuron<T> &rhs) {
    Neuron<T> tmp(rhs);
    weights = rhs.weights;
    bias = rhs.bias;
    activation = new T();

    return *this;
}

template<typename T>
Neuron<T>::~Neuron() {
    delete activation;
}

template<typename T> double
Neuron<T>::feedForward(std::vector<double> &inputs) {
    if (inputs.size() != weights.size()) {
        throw std::range_error("Different sizes!");
    }

    return (*activation)(dot_product(inputs, weights, bias));
}

template class Neuron<Sigmoid>;
