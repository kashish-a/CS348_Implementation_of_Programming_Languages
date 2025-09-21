#ifndef _TRANSLATE_H
#define _TRANSLATE_H

#include <bits/stdc++.h>
using namespace std;

// Forward declarations
class sym;
class symboltype;
class symtable;
class quad;
class quadArray;

/**
 * Modern type aliases replacing traditional macros
 */
using ltsit = list<sym>::iterator;
using ltiit = list<int>::iterator;
using ltstit = list<symtable*>::iterator;
using qdit = vector<quad>::iterator;
using ltsym = list<sym>;
using ltst = list<symtable*>;
using stri = string;

/**
 * Symbol class - represents an entry in the symbol table
 */
class sym {
public:
    // Symbol attributes
    stri name;           // Symbol identifier
    symboltype* type;    // Type descriptor pointer
    int size;            // Memory size (bytes)
    int offset;          // Memory offset
    symtable* nested;    // Nested scope table
    stri val;            // Initial value if any

    // Constructor and methods
    sym(stri, stri t = "int", symboltype* ptr = nullptr, int width = 0);
    sym* update(symboltype*); // Updates type and recalculates size
};

/**
 * Type descriptor class - handles type information including arrays
 */
class symboltype {
public:
    stri type;           // Base type name
    int width;           // Element width
    symboltype* arrtype; // Type of array elements (for multi-dimensional)

    symboltype(stri, symboltype* ptr = nullptr, int width = 1);
};

/**
 * Symbol table class - maintains scope information
 */
class symtable {
public:
    // Table properties
    stri name;          // Scope name
    int count;          // Temp var counter
    ltsym table;        // Symbol list
    symtable* parent;   // Parent scope

    // Methods
    symtable(stri name = "NULL");
    sym* lookup(stri);  // Find/create symbol
    void print();       // Display table
    void update();      // Recalculate offsets
};

/**
 * Quad class - represents a 3-address code instruction
 */
class quad {
public:
    // Instruction components
    stri res;   // Result/destination
    stri op;    // Operation
    stri arg1;  // First argument
    stri arg2;  // Second argument (optional)

    // Constructors for different argument types
    quad(stri, stri, stri op = "=", stri arg2 = "");
    quad(stri, int, stri op = "=", stri arg2 = "");
    quad(stri, float, stri op = "=", stri arg2 = "");

    // Output methods
    void print();
    void print1();
    void print2();
};

/**
 * QuadArray class - container for all generated quads
 */
class quadArray {
public:
    vector<quad> Array;  // Quad storage
    void print();        // Output all quads
};

/**
 * BasicType class - registry for language's built-in types
 */
class basicType {
public:
    vector<stri> type;  // Type names
    vector<int> size;   // Corresponding sizes
    void addType(stri, int);
};

/**
 * Statement structure - used for control flow backpatching
 */
struct Statement {
    list<int> nextList;  // List of instructions to patch
};

/**
 * Array structure - helper for array addressing
 */
struct Array {
    stri atype;         // "arr" or "ptr"
    sym* location;      // Base address temp
    sym* Array;         // Symbol entry
    symboltype* type;   // Element/subarray type
};

/**
 * Expression structure - tracks expression attributes
 */
struct Expression {
    sym* location;       // Result location
    stri type;           // Type info
    list<int> trueList;  // True branch jumps
    list<int> falseList; // False branch jumps
    list<int> nextList;  // Fall-through instructions
};

// Convenience type aliases
using expr = Expression*;
using symtyp = symboltype;

// External declarations
extern char* yytext;
extern int yyparse();

// Global state variables
extern symtable* ST;            // Current symbol table
extern symtable* globalST;      // Global scope table
extern sym* currSymbolPtr;      // Current symbol pointer
extern quadArray Q;             // Quad collection
extern basicType bt;            // Type registry
extern long long instr_count;   // Instruction counter
extern bool debug_on;           // Debug flag

// Utility functions
void formatOutput(int);

// Temporary generation
sym* gentemp(symtyp*, stri init = "");

// Code generation functions
void emit(stri, stri, int, stri arg = "");
void emit(stri, stri, float, stri arg = "");
void emit(stri, stri, stri arg1 = "", stri arg2 = "");

// Control flow management
void backpatch(list<int>, int);             // Update jump targets
list<int> makelist(int);                    // Create single-item list
list<int> merge(list<int>&, list<int>&);    // Combine lists
int nextinstr();                            // Get next instruction index
void updateNextInstr();                     // Increment instruction counter

// Debug support
void debug();

// Type system utilities
sym* convertType(sym*, stri);                 // Type conversion
bool compareSymbolType(sym*&, sym*&);         // Type comparison (symbols)
bool compareSymbolType(symtyp*, symtyp*);     // Type comparison (descriptors)
int computeSize(symtyp*);                     // Calculate type size
stri printType(symtyp*);                      // String representation
void changeTable(symtable*);                  // Switch current table

// Expression conversion helpers
stri convertInt2String(int);                  // Int to string
stri convertFloat2String(float);              // Float to string  
expr convertInt2Bool(expr);                   // Int to boolean
expr convertBool2Int(expr);                   // Boolean to int

#endif // _TRANSLATE_H