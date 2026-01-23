#pragma once

#include <vector>
#include <complex>
#include <cstddef>

class QuantumRegister {
public:
	using Complex = std::complex<double>;

	QuantumRegister(std::size_t qubits);

	std::size_t getQubitCount() const;
	std::size_t getStateCount() const;

	Complex& operator[](std::size_t index);
	const Complex& operator[](std::size_t index) const;

	std::vector<Complex> state;
private:
	std::size_t qubitCount;
};
