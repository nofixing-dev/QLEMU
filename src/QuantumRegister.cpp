#include "QuantumRegister.hpp"

QuantumRegister::QuantumRegister(std::size_t qubits)
	: qubitCount(qubits)
{
	std::size_t states = 1ULL << qubits;
	state.resize(states);
	state[0] = {1.0, 0.0};
}

std::size_t QuantumRegister::getQubitCount()
const {
	return qubitCount;
}

std::size_t QuantumRegister::getStateCount()
const {
	return state.size();
}

QuantumRegister::Complex&
QuantumRegister::operator[](std::size_t index) {
	return state[index];
}

const QuantumRegister::Complex&
QuantumRegister::operator[](std::size_t index)
const {
	return state[index];
}
