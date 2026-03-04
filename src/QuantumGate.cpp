#include "QuantumGate.hpp"
#include <cstddef>

void QuantumGate::X(QuantumRegister& reg, std::size_t targetQubit) {
	std::size_t n = reg.getQubitCount();
	std::size_t N = 1ULL << n;

	// copying state
	std::vector<QuantumRegister::Complex> newState(N, {0.0, 0.0});

	for (std::size_t i = 0; i < N; ++i) {
		std::size_t flipped = i ^ (1ULL << targetQubit);
		newState[flipped] = reg[i];
	}

	reg = QuantumRegister(reg);
	for (std::size_t i = 0; i < N; ++i)
		reg[i] = newState[i];
}

void QuantumGate::H(QuantumRegister& reg, std::size_t targetQubit) {
	std::size_t n = reg.getQubitCount();
	std::size_t N = 1ULL << n;

	std::vector<QuantumRegister::Complex> newState(N, {0.0, 0.0});
	const QuantumRegister::Complex invSqrt2(1.0 / std::sqrt(2.0), 0.0);

	for (std::size_t i = 0; i < N; ++i) {
		std::size_t flipped = i ^ (1ULL << targetQubit);
		bool bit = (i >> targetQubit) & 1ULL;

		QuantumRegister::Complex value = reg[i] * invSqrt2;

		if (!bit) {
			newState[i] += value;
			newState[flipped] += value;
		} else {
			newState[flipped] += value;
			newState[i] -= value;
		}
	}

	reg.state = std::move(newState);
}

void QuantumGate::CNOT(QuantumRegister& reg, std::size_t controlQubit, std::size_t targetQubit) {
    std::size_t n = reg.getQubitCount();
    std::size_t N = 1ULL << n;

    std::vector<QuantumRegister::Complex> newState(N, {0.0, 0.0});

    for (std::size_t i = 0; i < N; ++i) {
        bool controlBit = (i >> controlQubit) & 1ULL;

        if (!controlBit) {
            newState[i] += reg[i];
        } else {
            std::size_t flipped = i ^ (1ULL << targetQubit);
            newState[flipped] += reg[i];
        }
    }

    reg.state = std::move(newState);
}

void QuantumGate::Z(QuantumRegister& reg, std::size_t targetQubit) {
	std::size_t n = reg.getQubitCount();
	std::size_t N = 1ULL << n;

	// copying state
	std::vector<QuantumRegister::Complex> newState(N, {0.0, 0.0});

	for (std::size_t i = 0; i < N; ++i) {
        newState[i] = reg.state[i];
		if (i & (1 << targetQubit)) {
            newState[i] *= -1;
        }
	}

    reg.state = std::move(newState);
}

void QuantumGate::Measure(QuantumRegister& reg) {
    std::size_t N = reg.getStateCount();

    // ⁡⁢⁣⁣Probabilities⁡
    std::vector<double> probs(N);
    double sum = 0.0;
    for (std::size_t i = 0; i < N; ++i) {
        probs[i] = std::norm(reg[i]); // |amp|^2
        sum += probs[i];
    }

    // ⁡⁢⁣⁣Normalization⁡
    for (auto &p : probs) p /= sum;

    // ⁡⁢⁣⁣Random selection⁡
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::discrete_distribution<> dist(probs.begin(), probs.end());

    std::size_t result = dist(gen);

    // ⁡⁢⁣⁣State collapse⁡
    for (std::size_t i = 0; i < N; ++i) {
        reg[i] = (i == result) ? QuantumRegister::Complex(1.0, 0.0)
                               : QuantumRegister::Complex(0.0, 0.0);
    }

    // ⁡⁢⁣⁣Output result⁡
    std::cout << "Measured: |" << result << ">" << std::endl;
}