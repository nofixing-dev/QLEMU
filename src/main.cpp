#include <iostream>
#include "QuantumRegister.hpp"
#include "QuantumGate.hpp"

int main() {
	QuantumRegister reg(3);

	std::cout << "Before H-gate:\n";
	for (size_t i = 0; i < reg.getStateCount(); ++i)
		std::cout << "|" << i << ">: " << reg[i] << std::endl; 

	QuantumGate::H(reg, 0);
	QuantumGate::CNOT(reg, 0, 1);
	QuantumGate::Measure(reg);

	std::cout << "\nAfter H-gate on qubit 0:\n";
	for (size_t i = 0; i < reg.getStateCount(); ++i)
		std::cout << "|" << i << ">: " << reg[i] << std::endl;

	return 0;
}
