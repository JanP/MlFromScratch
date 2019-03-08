#ifndef NEURON_H
#define NEURON_H

#include <vector>

class IActivationFunction {
    public:
        virtual double operator()(double x) = 0;
        virtual ~IActivationFunction() {}
};

class Sigmoid: public IActivationFunction {
    public:
        double operator()(double x);
};

template<typename T>
class Neuron {
    public:
        explicit Neuron(std::vector<double> &weights, double bias);
        Neuron<T>(const Neuron<T> &n);
        Neuron<T>& operator=(const Neuron<T> &n);
        ~Neuron();
        double feedForward(std::vector<double> &inputs);
    private:
        std::vector<double> weights;
        double bias;
        IActivationFunction *activation;
};

#endif
