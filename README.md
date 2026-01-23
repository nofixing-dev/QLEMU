<div align="center">

<img src="docs/assets/banner.jpg" width="100%">

<h1>Quantum Logic Emulator</h1>

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](#license)
[![Version](https://img.shields.io/badge/version-0.1-blue.svg)](#)

**Simple quantum logic emulator in C++**
</div>

## **Overview**

**QLEMU** is a lightweight quantum logic emulator designed for learning and experimenting with basic quantum gates and qubit states.

It provides a minimal but accurate simulation of qubits, including superposition, measurement, and gate operations, making it ideal for students and hobbyists who want a hands-on introduction to quantum computing.

---

## **Key Features**

- **Minimal and lightweight**: Small codebase with clean architecture.
- **State-vector based simulation**: Accurate qubit representation using complex amplitudes.
- **Extensible design**: Easy to add new gates, registers, and measurement rules.
- **Educational focus**: Built for understanding quantum logic, not for production quantum computing.

---

## **Qubits**

A qubit in **QLEMU** is represented using a state vector with complex amplitudes:

```
|ψ⟩ = α|0⟩ + β|1⟩
|α|² + |β|² = 1
```

For multi-qubit systems, QLEMU uses a full state vector of size 2^n, where each basis state represents a classical bitstring.

Where α and β are complex numbers, and their squared magnitudes define the probabilities of measuring |0⟩ or |1⟩.

In the emulator, the state is stored as:

```
|0⟩: (α.real, α.imag) // std::complex<double>
|1⟩: (β.real, β.imag)
```

Example output:

```
|0⟩: (0.707107, 0)
|1⟩: (0.707107, 0)
```

This represents a 50/50 superposition of |0⟩ and |1⟩.

---

## **Gates**

**QLEMU** supports a set of basic quantum gates that can be applied to qubits and quantum registers.

**X (NOT)**

The X gate flips the state of a qubit:

```
|0⟩ → |1⟩
|1⟩ → |0⟩
```

It works like a classical NOT gate but on quantum states.

**H (Hadamard)**

The Hadamard gate creates a superposition from a basis state:

```
|0⟩ → (|0⟩ + |1⟩) / √2
|1⟩ → (|0⟩ - |1⟩) / √2
```

Applying H twice returns the qubit back to its original state.

**CNOT (Controlled-NOT)**

The CNOT gate operates on two qubits:

- The first qubit is the control.
- The second qubit is the target

If the control qubit is |1⟩, the target is flipped.

Example:

```
|10⟩ → |11⟩
|00⟩ → |00⟩
```

**Measure**

Measurement collapses the quantum register into a single classical basis state, selected randomly according to the squared magnitudes of the state amplitudes.

```
P(|0⟩) = |α|²
P(|1⟩) = |β|²
```

---

## **Installation**

**QLEMU** is written in C++ and requires a C++17-Compatible compiler.
No external libraries are needed.

### **Linux**

#### **Ubuntu / Debian**

Install **GCC** using apt:

```bash
sudo apt update
sudo apt install build-essential
```

#### **Arch Linux**

Install **GCC** using pacman:

```bash
sudo pacman -Syu
sudo pacman -S gcc
```

### **Windows**

On **Windows**, it is recommended to use **MinGW-w64**.

**MinGW-w64:**
 1. Download **MinGW-w64**
 2. Add **bin** directory to **PATH**
 3. Make sure **g++** is available in terminal

---

## **Build**

Compile the project using **g++**:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp QuantumRegister.cpp QuantumGate.cpp -o qlemu
```

Run:

```bash
./qlemu
```

> Tested on Linux. Other platforms are supported but not actively tested.

---

## **Usage**

**QLEMU** is a **logic-only** quantum emulator.
All quantum operations are defined directly in `main.cpp`.

A quantum register is created with a fixed number of qubits.
Quantum gates are then applied sequentially to the register.
After applying the gates, the register can be measured.

The execution flow is fully deterministic until measurement, which collapses the quantum state into a classical basis state.

> The goal of QLEMU is to make quantum logic simple, transparent, and understandable.

---

## **Examples**

Below is a simple example demonstrating how to use **QLEMU**.

```cpp
#include "QuantumRegister.hpp"
#include "QuantumGate.hpp"

int main() {
    // Create a quantum register with 3 qubits
    QuantumRegister reg(3);

    // Apply Hadamard gate to qubit 0
    QuantumGate::H(reg, 0);

    // Create entanglement between qubit 0 and qubit 1
    QuantumGate::CNOT(reg, 0, 1);

    // Measure the quantum register
    QuantumGate::Measure(reg);

    return 0;
}
```

> The output will be a classical bitstring representing the measured state of the quantum register.

---

## **Roadmap**

- [x] Implement basic quantum register
- [x] Support 3 qubits
- [x] Implement X, H, CNOT gates
- [x] Implement full-register measurement
- [ ] Add more single-qubit gates (Z, S, T)
- [ ] Add multi-qubit gates (SWAP, CZ)
- [ ] Support more qubits
- [ ] Implement basic quantum algorithms
- [ ] Optional visualization layer

---

## **License**

This project is licensed under the **MIT License**.  
See the [LICENSE](LICENSE) file for details.
