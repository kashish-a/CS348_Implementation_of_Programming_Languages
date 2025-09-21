# MicroC Compiler

A compiler implementation for the MicroC programming language, built as part of CS348 coursework. The project demonstrates the compilation pipeline from source code to machine code.

## Features

### Lexical Analysis

- **Flex-based lexer** for tokenizing MicroC source code
- Symbol table construction and management
- Lookahead parsing support for complex grammar constructs
- Tested across 50+ MicroC programs

### Syntax Analysis

- **Bison-based parser** generating detailed parse trees
- Grammar reduction logging for debugging
- Nested scope management and validation
- Comprehensive error reporting

### Code Generation

- **Three-address code** generation with optimization
- Temporary variable management
- Label resolution and backpatching for control flow
- Support for conditionals, loops, and function calls

### Assembly Generation

- **Two-pass assembler** implemented in C++
- Symbol resolution and reference management
- Backpatch reference handling
- Final machine code emission

## Built With

- **Flex** - Lexical analysis
- **Bison** - Parser generation
- **C++** - Assembler and core implementation
- **Make** - Build system

---

_CS348 Course Project - Compiler Design_
