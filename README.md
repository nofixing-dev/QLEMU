<div align="center">

<img src="docs/assets/banner.jpg" width="100%">

<h1>Quantum Logic Emulator</h1>

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](#license)
[![Version](https://img.shields.io/badge/Version-0.2-blue.svg)](#)
[![CMake](https://img.shields.io/badge/Build-CMake-064F8C.svg)](#)

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

**Z (Pauli-Z)**

The Z gate changes the phase of a qubit if it is in the |1⟩ state. Its matrix representation is:

```
(1   0)
(0  -1)
```

- If the qubit is |0⟩, it remains unchanged.
- If the qubit is |1⟩, its amplitude is multiplied by -1.

**Measure**

Measurement collapses the quantum register into a single classical basis state, selected randomly according to the squared magnitudes of the state amplitudes.

```
P(|0⟩) = |α|²
P(|1⟩) = |β|²
```

---

### **Installation**

**QLEMU** is written in C++ and requires a C++17-Compatible compiler.
No external libraries are needed.


## **Build**

Compile the project using **CMake**:

```bash
mkdir build
cd build

cmake ..
cmake --build .
```

Run:

```bash
./build/QLEMU
```
or

```bash
./build/QLEMU.exe
```

> Tested on Linux & Windows.

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

```bash
QLEMU> reg
Enter number of qubits: 
3
QLEMU> h
Enter qubit index: 
0
QLEMU> z
Enter qubit index: 
0
QLEMU> h
Enter qubit index: 
0
QLEMU> state
|0>: (0,0)
|1>: (1,0)
|2>: (0,0)
|3>: (0,0)
|4>: (0,0)
|5>: (0,0)
|6>: (0,0)
|7>: (0,0)
QLEMU>
```

---

## **Roadmap**

- [x] Implement basic quantum register
- [x] Support 3 qubits
- [x] Implement X, H, CNOT gates
- [x] Implement full-register measurement
- [x] Terminal
- [ ] Add more single-qubit gates (Z, S, T)
- [ ] Add multi-qubit gates (SWAP, CZ)
- [x] Support more qubits
- [ ] Implement basic quantum algorithms
- [ ] Optional visualization layer
- [x] CMake

---

## **License**

This project is licensed under the **MIT License**.  
See the [LICENSE](LICENSE) file for details.
