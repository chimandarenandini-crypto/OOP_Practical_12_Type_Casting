# OOP Practical 12 – Type Casting and Casting Operators

## 📌 About the Practical
This practical demonstrates type casting in C++. It covers implicit casting, explicit (C-style) casting, and the four C++ casting operators: `static_cast`, `const_cast`, `reinterpret_cast`, and `dynamic_cast`.

The program uses examples such as calculating average marks and checking whether a vehicle is a car or a bike.

## 🎯 Objectives
- Understand implicit and explicit type casting in C++.
- Learn how to use the four C++ casting operators.
- Observe decimal loss during type conversion.
- Understand integer division and floating-point division.
- Test boundary cases such as division by zero and failed `dynamic_cast`.

## 💻 Concepts Covered

### 1. Implicit Type Casting
Conversion performed automatically by the compiler, such as converting an integer to a double.

### 2. Explicit (C-style) Casting
Conversion performed manually by the programmer using syntax such as `(double)value`.

### 3. `static_cast`
Used for standard conversions, such as converting an integer to a double or a double to an integer.

### 4. `const_cast`
Used to add or remove `const` qualification from a pointer or reference.

### 5. `reinterpret_cast`
Used for low-level conversions between certain unrelated pointer and integer types. It must be used carefully.

### 6. `dynamic_cast`
Used for runtime type checking in polymorphic class hierarchies. A failed pointer cast returns `nullptr`.

## 🛠️ Technologies Used
- **Programming Language:** C++
- **IDE:** Visual Studio Code / Code::Blocks
- **Compiler:** g++
- **Header Files:** `<iostream>` and `<cstdint>`

## 🧪 Test Cases
The practical tests the following cases:

- Integer to double conversion.
- Character to integer conversion.
- Double to integer conversion and decimal loss.
- Integer division versus floating-point division.
- Average calculation and division-by-zero handling.
- Conversion of negative and fractional values.
- Integer-to-character and character-to-integer conversion.
- `const_cast` and `reinterpret_cast` examples.
- Successful and unsuccessful `dynamic_cast` operations.

## ▶️ How to Compile and Run

Save the source code as `type_casting.cpp`.

Compile using:
```bash
g++ type_casting.cpp -o type_casting
```

Run on Windows:
```bash
.\type_casting.exe
```

## 📚 Learning Outcomes
