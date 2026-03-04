#pragma once

#include "QuantumRegister.hpp"
#include <cmath>
#include <cstddef>
#include <random>
#include <iostream>

class QuantumGate {
public:
	// ⁡⁢⁣⁣X-Gate⁡
	static void X(QuantumRegister& reg, std::size_t targetQubit);

	// ⁡⁢⁣⁣Hadamard-Gate⁡
	static void H(QuantumRegister& reg, std::size_t targetQubit);

	// ⁡⁢⁣⁣CNOT-Gate⁡
	static void CNOT(QuantumRegister& reg, std::size_t controlQubit, std::size_t targetQubit);

	// ⁡⁢⁣⁣Z-Gate⁡
	static void Z(QuantumRegister& reg, std::size_t targetQubit);

	// ⁡⁢⁣⁣Measure-Gate⁡
	static void Measure(QuantumRegister& reg);
};
