#include <iostream>
#include <string>
#include "QuantumRegister.hpp"
#include "QuantumGate.hpp"

int main() {
	std::string command;
	QuantumRegister reg(0); // Initialize with 0 qubits, will be set by 'reg' command
	while (true)
	{
		std::cout << "QLEMU> ";
		std::getline(std::cin, command);

		// ⁡⁢⁣⁡⁢⁣⁡⁢⁣⁣Command processing⁡
		if (command == "exit"){
			break;
		} else if (command == "reg"){
			int num_qubits;
			std::cout << "Enter number of qubits: \n";
			std::cin >> num_qubits;
			reg = QuantumRegister(num_qubits); // Reinitialize register
			std::cin.ignore();

		} else if (command == "h") {
			int qubit;
			std::cout << "Enter qubit index: \n";
			std::cin >> qubit;
			QuantumGate::H(reg, qubit);
			std::cin.ignore();
		} else if (command == "cnot") {
			int control, target;
			std::cout << "Enter control qubit: \n";
			std::cin >> control;
			std::cout << "Enter target qubit: \n";
			std::cin >> target;
			QuantumGate::CNOT(reg, control, target);
			std::cin.ignore();
		} else if (command == "x") {
			int qubit;
			std::cout << "Enter qubit index: \n";
			std::cin >> qubit;
			QuantumGate::X(reg, qubit);
			std::cin.ignore();
		} else if (command == "z") {
			int qubit;
			std::cout << "Enter qubit index: \n";
			std::cin >> qubit;
			QuantumGate::Z(reg, qubit);
			std::cin.ignore();
		} else if (command == "measure") {
			QuantumGate::Measure(reg);
		} else if (command == "state") {
			for (size_t i = 0; i < reg.getStateCount(); ++i)
				std::cout << "|" << i << ">: " << reg[i] << std::endl;
		} else {
			std::cout << "Unkown command. Try 'x', 'h', 'cnot', 'z', 'measure', or 'exit'.\n";
		}
	}
	return 0;
}
