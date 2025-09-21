# MicroC Translator Assignment

## Overview

This submission implements a translator for the “microC” language, following the provided example grammar and reduction rules. All core language features specified in the assignment have been handled, and several extensions (not covered by the original rules) have been attempted as well.

---

## Implemented Features

1. **Basic Types**  
   - `integer`, `float`, `char`  
   - Variable declarations (scalars, pointers, 1D & 2D arrays)  
2. **Control Flow**  
   - `if / else`  
   - `while` loops  
   - `begin … end` blocks  
3. **Functions**  
   - Declarations, definitions, calls, recursion  
   - Parameter passing (by value and via pointers)  
4. **Expressions & Operators**  
   - Arithmetic (`+`, `-`, `*`, `/`, `%`)  
   - Bitwise (`&`, `|`, `<<`, `>>`)  
   - Relational and logical operators  
5. **Symbol Table**  
   - Creation, scoping, nesting  
   - Printing at the end of translation  
6. **Intermediate Code Generation**  
   - Three‑address code (quads)  
   - Backpatching for jumps and boolean expressions  
   - Grammar‑rule reduction display  

---

## Extensions & Disclaimer

- **Floating‑point support** (`float` constants and arithmetic) was _not_ fully covered by the original reduction rules—this implementation **attempts** to handle them in expressions, declarations, and function parameters.  
- **Begin/End** block delimiters have been integrated consistently across all statements and declarations.  
- **Additional operators** and constructs (pointer arithmetic, multi‑dimensional arrays) have been added beyond the provided specs.

> **Disclaimer:**  
> While every effort was made to remain faithful to the microC specification and the assignment’s reduction rules, some extended features (especially floating‑point handling) may exhibit inconsistencies or edge‑case bugs. Any such issues stem from augmenting the grammar beyond what was explicitly defined in the instructions.

---

## Building & Running

1. **Clean** any previous artifacts:  
   ```bash
   make clean
