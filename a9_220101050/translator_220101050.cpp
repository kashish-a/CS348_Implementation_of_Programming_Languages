#include "translator_220101050.h"
#include<sstream>
#include<string>
#include<iostream>
using namespace std;

// Global symbols and structures as defined in header
symtable* globalST;                       // Global symbol-table reference
quadArray Q;                              // Quadruple storage for three-address code
string var_type;                          // Tracks current variable type being processed
symtable* ST;                             // Points to symbol table in current scope
sym* currSymbolPtr;                       // Current symbol being processed
basicType bt;                             // Storage for fundamental types
long long int instr_count;                // Instruction counter for verification
bool debug_mode;                          // Controls debug output visibility
void debug_print(){cout<<"";}             // Debug utility function (empty implementation)

// String to integer mapping for operator identification
int s2i(string s) {
	static map <string, int> m = {
		{"+", 0}, {"-", 1}, {"*", 2}, {"/", 3}, {"%", 4}, 
		{"|", 5}, {"^", 6}, {"&", 7}, {"==", 8}, {"!=", 9}, 
		{"<=", 10}, {"<", 11}, {">", 12}, {">=", 13}, {"goto", 14}, 
		{">>", 15}, {"<<", 16}, {"=", 17}, {"=&", 18}, {"=*", 19},
		{"*=", 20}, {"uminus", 21}, {"~", 22}, {"!", 23}, {"=[]", 24}, 
		{"[]=", 25}, {"return", 26}, {"param", 27}, {"call", 28}, {"label", 29}
	}; 
	return (m.find(s) != m.end()) ? m[s] : -1;
}

// Symbol constructor implementation
sym::sym(string name, string t, symboltype* arrtype, int width) {
	debug_print();
	this->name = name;
	debug_print();
	// Initialize symbol's type information
	type = new symboltype(t, arrtype, width);       
	debug_print();
	// Calculate memory requirements
	size = computeSize(type);                  
	debug_print();
	// Initialize remaining fields
	offset = 0;                                   
	debug_print();
	val = "-";                                    
	debug_print();
	nested = NULL;                                
	debug_print();
}

// Updates symbol properties for type changes
sym* sym::update(symboltype* t) {
	debug_print();
	// Apply new type
	type = t;                                     
	debug_print();
	// Recalculate size based on new type
	this->size = computeSize(t);                 
	debug_print();
	// Return modified symbol
	return this;                                 
}

// Symbol type constructor
symboltype::symboltype(string type, symboltype* arrtype, int w) {
	debug_print();
	// Set basic type properties
	this->type = type;
	debug_print();
	this->width = w;
	debug_print();
	this->arrtype = arrtype;
	debug_print();
}

// Symbol table constructor
symtable::symtable(string name) {
	this->name = name;
	debug_print();
	// No temporaries at creation
	count = 0;                           
	debug_print();
}

// Find or create symbol in table
sym* symtable::lookup(string name) {
	// Search through existing entries
	for(ltsit it = table.begin(); it != table.end(); ++it) {
		if(it->name == name) 
			return &(*it);
	}
	
	// Not found - create new entry
	sym* s = new sym(name);
	table.push_back(*s);
	return &table.back();
}

// Update offsets in symbol table
void symtable::update() {
	ltst tables_to_process;
	int running_offset = 0;
	
	// First pass: process symbols in current table
	for(ltsit it = table.begin(); it != table.end(); ++it) {
		if(it == table.begin()) {
			it->offset = 0;
			running_offset = it->size;
		} else {
			it->offset = running_offset;
			running_offset += it->size;
		}
		
		// Collect nested tables for later processing
		if(it->nested != NULL) 
			tables_to_process.push_back(it->nested);
	}
	
	// Second pass: recursively update nested tables
	for(ltstit nested_table = tables_to_process.begin(); 
		nested_table != tables_to_process.end(); 
		++nested_table) {
		(*nested_table)->update();
	}
}

// Display symbol table contents
void symtable::print() {
	// Print separator line
	for(int i = 0; i < 50; i++) cout << "__";
	cout << endl;
	
	// Print table header information
	cout << "Table Name: " << this->name << "\t\t\t Parent Name: ";
	cout << (this->parent == NULL ? "NULL" : this->parent->name) << endl;
	
	for(int i = 0; i < 50; i++) cout << "__";
	cout << endl;
	
	// Print column headers
	cout << "Name";              
	formatOutput(11);
	cout << "Type";             
	formatOutput(16);
	cout << "Initial Value";   
	formatOutput(7);
	cout << "Size";              
	formatOutput(11);
	cout << "Offset";            
	formatOutput(9);
	cout << "Nested" << endl;      
	formatOutput(100);
	cout << endl;
	
	// Print table entries
	ostringstream str1;
	ltst nested_tables;
	
	for(ltsit it = table.begin(); it != table.end(); ++it) {
		// Name column
		cout << it->name;
		formatOutput(15 - it->name.length());
		
		// Type column
		string type_str = printType(it->type);
		cout << type_str;
		formatOutput(20 - type_str.length());
		
		// Initial value column
		cout << it->val;
		formatOutput(20 - it->val.length());
		
		// Size column
		cout << it->size;
		str1 << it->size;
		formatOutput(15 - str1.str().length());
		str1.str("");
		str1.clear();
		
		// Offset column
		cout << it->offset;
		str1 << it->offset;
		formatOutput(15 - str1.str().length());
		str1.str("");
		str1.clear();
		
		// Nested column
		if(it->nested == NULL) {
			cout << "NULL" << endl;
		} else {
			cout << it->nested->name << endl;
			nested_tables.push_back(it->nested);
		}
	}
	
	// Print separator
	for(int i = 0; i < 100; i++) cout << "-";
	cout << "\n\n";
	
	// Print nested tables
	for(ltstit nt = nested_tables.begin(); nt != nested_tables.end(); ++nt) {
		(*nt)->print();
	}
}

// Switch to a different symbol table
void changeTable(symtable* newtable) {
	debug_print();
	ST = newtable;
	debug_print();
}

// Verify symbol type compatibility
bool compareSymbolType(sym*& s1, sym*& s2) {
	debug_print();
	symboltype* t1 = s1->type;
	debug_print();
	symboltype* t2 = s2->type;
	
	// Try different compatibility paths
	if(compareSymbolType(t1, t2)) 
		return true;
	else if(s1 = convertType(s1, t2->type)) 
		return true;
	else if(s2 = convertType(s2, t1->type)) 
		return true;
		
	return false;
}

// Check type equivalence
bool compareSymbolType(symboltype* t1, symboltype* t2) {
	debug_print();
	// Handle NULL cases
	if(t1 == NULL && t2 == NULL)
		return true;
	else if(t1 == NULL || t2 == NULL || t1->type != t2->type)
		return false;
	
	// Recursive check for array types
	return compareSymbolType(t1->arrtype, t2->arrtype);
}

// Quadruple constructor (string args)
quad::quad(string res, string arg1, string op, string arg2) {
	debug_print();
	this->res = res;
	debug_print();
	this->arg1 = arg1;
	debug_print();
	this->op = op;
	debug_print();
	this->arg2 = arg2;
	debug_print();
}

// Quadruple constructor (int arg1)
quad::quad(string res, int arg1, string op, string arg2) {
	debug_print();
	this->res = res;
	debug_print();
	this->arg2 = arg2;
	debug_print();
	this->op = op;
	debug_print();
	this->arg1 = convertInt2String(arg1);
	debug_print();
}

// Quadruple constructor (float arg1)
quad::quad(string res, float arg1, string op, string arg2) {
	debug_print();
	this->res = res;
	debug_print();
	this->arg2 = arg2;
	debug_print();
	this->op = op;
	debug_print();
	this->arg1 = convertFloat2String(arg1);
	debug_print();
}

// Format and display quadruple
void quad::print() {
	int next_instr = 0;
	
	// Handle different operation types
	switch(s2i(op)) {
		// Binary arithmetic operations (0-7)
		case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
			debug_print();
			this->print1();
			break;
		
		// Relational operations (8-13)
		case 8: case 9: case 10: case 11: case 12: case 13:
			debug_print();
			this->print2();
			break;
			
		// Jump operation
		case 14:
			debug_print();
			cout << "goto " << res;
			break;
			
		// Shift operations (15-16)
		case 15: case 16:
			debug_print();
			this->print1();
			break;
			
		// Assignment
		case 17:
			debug_print();
			cout << res << " = " << arg1;
			break;
			
		// Address, dereferencing operators (18-23)
		case 18:
			debug_print();
			cout << res << " = &" << arg1;
			break;
		case 19:
			debug_print();
			cout << res << " = *" << arg1;
			break;
		case 20:
			debug_print();
			cout << "*" << res << " = " << arg1;
			break;
		case 21:
			debug_print();
			cout << res << " = -" << arg1;
			break;
		case 22:
			debug_print();
			cout << res << " = ~" << arg1;
			break;
		case 23:
			debug_print();
			cout << res << " = !" << arg1;
			break;
			
		// Array access and assignment
		case 24:
			debug_print();
			cout << res << " = " << arg1 << "[" << arg2 << "]";
			break;
		case 25:
			debug_print();
			cout << res << "[" << arg1 << "]" << " = " << arg2;
			break;
			
		// Function related (26-28)
		case 26:
			debug_print();
			cout << "return " << res;
			break;
		case 27:
			debug_print();
			cout << "param " << res;
			break;
		case 28:
			debug_print();
			cout << res << " = " << "call " << arg1 << ", " << arg2;
			break;
			
		// Label
		case 29:
			debug_print();
			cout << res << ": ";
			break;
			
		// Unknown operation
		default:
			cout << "Can't find " << op;
			break;
	}
	cout << endl;
}

// Helper for printing binary operations
void quad::print1() {
	debug_print();
	cout << res << " = " << arg1 << " " << op << " " << arg2;
	debug_print();
}

// Helper for printing conditional jumps
void quad::print2() {
	debug_print();
	cout << "if " << arg1 << " " << op << " " << arg2 << " goto " << res;
	debug_print();
}

// Register a basic data type
void basicType::addType(string t, int s) {
	debug_print();
	type.push_back(t);
	debug_print();
	size.push_back(s);
	debug_print();
}

// Display all generated three-address code
void quadArray::print() {
	// Print header
	for(int i = 0; i < 100; i++) cout << "_";
	cout << endl << "Three Address Code:" << endl;
	for(int i = 0; i < 100; i++) cout << "_";
	cout << endl;
	
	// Print each instruction with label
	int line_num = 0;
	for(qdit it = Array.begin(); it != Array.end(); ++it, ++line_num) {
		if(it->op == "label") {
			cout << endl << "L" << line_num << ": ";
			it->print();
		} else {
			cout << "L" << line_num << ": ";
			formatOutput(4);
			it->print();
		}
	}
	
	// Print footer
	for(int i = 0; i < 100; i++) cout << "_";
	cout << endl;
}

// Add spacing for output formatting
void formatOutput(int n) {
	debug_print();
	for(int i = 0; i < n; i++) cout << " ";
	debug_print();
}

// Integer to string conversion
string convertInt2String(int a) {
	stringstream ss;
	ss << a;
	return ss.str();
}

// Float to string conversion
string convertFloat2String(float x) {
	ostringstream buff;
	buff << x;
	return buff.str();
}

// Generate and add quadruple (string version)
void emit(string op, string res, string arg1, string arg2) {
	quad *q = new quad(res, arg1, op, arg2);
	debug_print();
	Q.Array.push_back(*q);
}

// Generate and add quadruple (int version)
void emit(string op, string res, int arg1, string arg2) {
	quad *q = new quad(res, arg1, op, arg2);
	debug_print();
	Q.Array.push_back(*q);
}

// Generate and add quadruple (float version)
void emit(string op, string res, float arg1, string arg2) {
	quad *q = new quad(res, arg1, op, arg2);
	Q.Array.push_back(*q);
}

// Convert symbol to different type
sym* convertType(sym* s, string return_type) {
	// Generate temporary for conversion result
	sym* new_s = gentemp(new symboltype(return_type));
	
	// Handle float conversions
	if(s->type->type == "float") {
		if(return_type == "int") {
			emit("=", new_s->name, "float2int(" + s->name + ")");
			return new_s;
		} else if(return_type == "char") {
			emit("=", new_s->name, "float2char(" + s->name + ")");
			return new_s;
		}
		return s;
	}
	
	// Handle int conversions
	else if(s->type->type == "int") {
		if(return_type == "float") {
			emit("=", new_s->name, "int2float(" + s->name + ")");
			return new_s;
		} else if(return_type == "char") {
			emit("=", new_s->name, "int2char(" + s->name + ")");
			return new_s;
		}
		return s;
	}
	
	// Handle char conversions
	else if(s->type->type == "char") {
		if(return_type == "int") {
			emit("=", new_s->name, "char2int(" + s->name + ")");
			return new_s;
		} else if(return_type == "double") {
			emit("=", new_s->name, "char2double(" + s->name + ")");
			return new_s;
		}
		return s;
	}
	
	// No conversion needed
	return s;
}

// Perform backpatching on instruction list
void backpatch(list<int> list1, int addr) {
	string addr_str = convertInt2String(addr);
	for(ltiit it = list1.begin(); it != list1.end(); ++it) {
		Q.Array[*it].res = addr_str;
	}
}

// Create new list with single element
list<int> makelist(int init) {
	list<int> new_list;
	new_list.push_back(init);
	debug_print();
	return new_list;
}

// Combine two lists
list<int> merge(list<int> &a, list<int> &b) {
	list<int> result = a;
	result.splice(result.end(), b);
	debug_print();
	return result;
}

// Convert integer expression to boolean
expr convertInt2Bool(expr e) {
	if(e->type != "bool") {
		e->falseList = makelist(nextinstr());
		emit("==", "", e->location->name, "0");
		e->trueList = makelist(nextinstr());
		emit("goto", "");
	}
	return e;
}

// Convert boolean expression to integer
expr convertBool2Int(expr e) {
	if(e->type == "bool") {
		debug_print();
		// Generate temporary for result
		e->location = gentemp(new symboltype("int"));
		
		// Patch true path
		debug_print();
		backpatch(e->trueList, nextinstr());
		debug_print();
		emit("=", e->location->name, "true");
		
		// Jump over false path
		debug_print();
		string next = convertInt2String(nextinstr() + 1);
		debug_print();
		emit("goto", next);
		
		// Patch false path
		debug_print();
		backpatch(e->falseList, nextinstr());
		debug_print();
		emit("=", e->location->name, "false");
	}
	return e;
}

// Track instruction count for debugging
void updateNextInstr() {
	instr_count++;
	if(debug_mode == 1) {
		cout << "Current Line Number:" << instr_count << endl;
		cout << "Press [ENTER] to continue:";
		cin.get();
	}
}

// Debug output function
void debug() {
	if(debug_mode == 1)
		cout << instr_count << endl;
}

// Get index for next instruction
int nextinstr() {
	debug_print();
	return Q.Array.size();
}

// Generate temporary variable with type
sym* gentemp(symboltype* t, string init) {
  string temp_name = "t" + convertInt2String(ST->count++);
  sym* temp = new sym(temp_name);
  temp->type = t;
  temp->size = computeSize(t);
  temp->val = init;
  ST->table.push_back(*temp);
  return &ST->table.back();
}

// Calculate memory size for data type
int computeSize(symboltype* t) {
	if(t->type == "void")
		return bt.size[1];
	else if(t->type == "char")
		return bt.size[2];
	else if(t->type == "int")
		return bt.size[3];
	else if(t->type == "float")
		return bt.size[4];
	else if(t->type == "arr")
		return t->width * computeSize(t->arrtype);
	else if(t->type == "ptr")
		return bt.size[5];
	else if(t->type == "func")
		return bt.size[6];
	else
		return -1;
}

// Generate string representation of type
string printType(symboltype* t) {
	if(t == NULL) 
		return bt.type[0];
		
	if(t->type == "void")
		return bt.type[1];
	else if(t->type == "char")
		return bt.type[2];
	else if(t->type == "int")
		return bt.type[3];
	else if(t->type == "float")
		return bt.type[4];
	else if(t->type == "ptr")
		return bt.type[5] + "(" + printType(t->arrtype) + ")";
	else if(t->type == "arr") {
		string width_str = convertInt2String(t->width);
		return bt.type[6] + "(" + width_str + "," + printType(t->arrtype) + ")";
	}
	else if(t->type == "func")
		return bt.type[7];
	else
		return "NA";
}

// Main function
int main() {
	// Initialize basic types with sizes
	bt.addType("null", 0);
	bt.addType("void", 0);
	bt.addType("char", 1);
	bt.addType("int", 4);
	bt.addType("float", 8);
	bt.addType("ptr", 4);
	bt.addType("arr", 0);
	bt.addType("func", 0);
	
	// Initialize global variables
	instr_count = 0;
	debug_mode = 0;
	
	// Create global symbol table
	globalST = new symtable("Global");
	ST = globalST;
	
	// Start parsing
	yyparse();
	
	// Process and display results
	globalST->update();
	cout << "\n";
	Q.print();
	globalST->print();
	
	return 0;
}
