#include <bits/stdc++.h>
using namespace std;
const int T_RECORD_MAX = 30; // Replacing the #define

// Struct to store the arguments of parsed instructions
struct instruction
{
    string label, mnemonic, operand, address;
};

// Struct to store info of text records
struct t_record
{
    string start, objectCode;
    int length;
};

map<string, string> symtab, optable;
string prog_length;
map<string, vector<string>> forward_reference_table;
map<string, string> preliminary_symbol_resolution;
vector<pair<string, string>> deferred_processing_queue;

// Typedefs for easier reference
typedef struct instruction instr;
typedef struct t_record tRec;

instruction parser()
{
    instruction code;
    string input;

    // Read a line of input
    if (!getline(cin, input))
    {
        return code; // Return empty instruction if no input
    }

    // Trim leading and trailing whitespace
    input.erase(0, input.find_first_not_of(" \t\n"));
    input.erase(input.find_last_not_of(" \t\n") + 1);

    // Handle comment lines
    if (!input.empty() && input[0] == '.')
    {
        cout << "     " << input << endl;
        return parser(); // Recursively get next instruction
    }

    // Split input into tokens
    vector<string> tokens;
    stringstream ss(input);
    string token;

    while (ss >> token)
    {
        if (!token.empty())
        {
            tokens.push_back(token);
        }
    }

    // Initialize empty instruction
    code.address = "";
    code.label = "";
    code.mnemonic = "";
    code.operand = "";

    // Parse based on number of tokens
    switch (tokens.size())
    {
    case 3: // Label + Mnemonic + Operand
        code.label = tokens[0];
        code.mnemonic = tokens[1];
        code.operand = tokens[2];
        break;

    case 2: // Mnemonic + Operand
        code.mnemonic = tokens[0];
        code.operand = tokens[1];
        break;

    case 1: // Mnemonic only
        code.mnemonic = tokens[0];
        break;

    default: // Empty line or invalid format
        break;
    }

    return code;
}

instruction inter_parser()
{
    instruction parsed_instruction;
    string input;

    // Initialize all fields to empty strings
    parsed_instruction.address = "";
    parsed_instruction.label = "";
    parsed_instruction.mnemonic = "";
    parsed_instruction.operand = "";

    // Read input until we get a non-comment line
    do
    {
        if (!getline(cin, input))
        {
            return parsed_instruction; // Return empty instruction if no input
        }

        // Trim leading whitespace
        size_t start = input.find_first_not_of(" \t\n");
        if (start == string::npos)
            continue; // Skip empty lines
        input = input.substr(start);

    } while (input[0] == '.'); // Skip comment lines

    // Split input into tokens using stringstream
    vector<string> tokens;
    stringstream ss(input);
    string token;

    // Collect all non-empty tokens
    while (ss >> token)
    {
        if (!token.empty())
        {
            tokens.push_back(token);
        }
    }

    // Parse tokens based on count
    if (!tokens.empty())
    {
        // First token is always address in intermediate format
        parsed_instruction.address = tokens[0];

        switch (tokens.size())
        {
        case 4: // Full instruction: address, label, mnemonic, operand
            parsed_instruction.label = tokens[1];
            parsed_instruction.mnemonic = tokens[2];
            parsed_instruction.operand = tokens[3];
            break;

        case 3: // No label: address, mnemonic, operand
            parsed_instruction.mnemonic = tokens[1];
            parsed_instruction.operand = tokens[2];
            break;

        case 2: // No label, no operand: address, mnemonic
            parsed_instruction.mnemonic = tokens[1];
            break;

        default:
            // Handle unexpected token count
            // Currently just returns with whatever tokens were parsed
            break;
        }
    }

    return parsed_instruction;
}
// Convert decimal to hexadecimal using bitwise operations and string building
void resolve_forward_references()
{
    // Resolving symbols that were not immediately resolvable
    for (const auto &ref : forward_reference_table)
    {
        if (symtab.find(ref.first) != symtab.end())
        {
            for (const auto &dependent : ref.second)
            {
                // Resolution process
                preliminary_symbol_resolution[dependent] = symtab[ref.first];
            }
        }
    }
}
string decToHex(int decimal, int padding = 0)
{
    if (decimal == 0)
    {
        return string(padding > 0 ? padding : 1, '0');
    }

    const char HEX_DIGITS[] = "0123456789ABCDEF";
    string result;

    while (decimal > 0)
    {
        // Use bitwise AND to get the last 4 bits (equivalent to modulo 16)
        result = HEX_DIGITS[decimal & 0xF] + result;
        // Use right shift to divide by 16
        decimal >>= 4;
    }

    // Add padding if needed
    if (padding > 0)
    {
        while (result.length() < padding)
        {
            result = "0" + result;
        }
    }

    return result;
}

// Convert hexadecimal to decimal using place value method
int hexToDec(string hexStr)
{
    int result = 0;

    // Convert to uppercase for consistency
    for (char &c : hexStr)
    {
        c = toupper(c);
    }

    // Process each character from left to right
    for (char c : hexStr)
    {
        result <<= 4; // Multiply by 16
        if (c >= '0' && c <= '9')
        {
            result += (c - '0');
        }
        else if (c >= 'A' && c <= 'F')
        {
            result += (c - 'A' + 10);
        }
    }

    return result;
}

// Add numbers with type checking and conversion
string add(string num1, string num2, int isHex)
{
    int value1, value2;

    if (isHex)
    {
        // Both inputs are hexadecimal
        try
        {
            value1 = hexToDec(num1);
            value2 = hexToDec(num2);
        }
        catch (...)
        {
            return "0"; // Return 0 on invalid input
        }
    }
    else
    {
        // First number is hex, second is decimal
        try
        {
            value1 = hexToDec(num1);
            value2 = stoi(num2);
        }
        catch (...)
        {
            return "0"; // Return 0 on invalid input
        }
    }

    // Perform addition and convert result to hex
    int sum = value1 + value2;
    return decToHex(sum);
}
// Function to initialize the opcode table with mnemonics and their corresponding opcodes

void intelligent_symbol_table_insertion(const string &label, const string &location)
{
    // Simulates advanced symbol table management with forward reference tracking
    if (symtab.find(label) != symtab.end())
    {
        forward_reference_table[label].push_back(location);
    }
    else
    {
        symtab[label] = location;
    }
}

void init_optable()
{
    // Define a list of mnemonic-opcode pairs
    vector<pair<string, string>> op_pairs = {
        {"ADD", "18"}, {"SUB", "1C"}, {"MUL", "20"}, {"DIV", "24"}, {"COMP", "28"}, {"J", "3C"}, {"JEQ", "30"}, {"JLT", "38"}, {"JGT", "34"}, {"LDA", "00"}, {"LDX", "04"}, {"LDL", "08"}, {"RD", "D8"}, {"WD", "DC"}, {"LDCH", "50"}, {"STX", "10"}, {"TIX", "2C"}, {"TD", "E0"}, {"STCH", "54"}, {"STL", "14"}, {"RSUB", "4C"}, {"STA", "0C"}, {"JSUB", "48"}, {"OR", "44"}, {"STSW", "E8"}};

    // Loop over each pair in the vector and insert it into the opcode table map
    for (const auto &op_pair : op_pairs)
    {
        // Insert the mnemonic and its corresponding opcode into the table
        optable[op_pair.first] = op_pair.second;
    }
}

// Function to retrieve the opcode for a given mnemonic
string opcode(string mnemonic)
{
    // Look for the mnemonic in the opcode table
    auto found = optable.find(mnemonic);

    // If the mnemonic is not found in the table, return a "not found" marker
    if (found == optable.end())
    {
        return "-1"; // Return "-1" to indicate an unknown mnemonic
    }

    // Return the opcode associated with the found mnemonic
    return found->second;
}
string advanced_location_counter_management(const string &current_loc, const instruction &instr)
{
    // Simulates intelligent location counter adjustment
    string next_loc = current_loc;

    // Creating location tracking
    if (opcode(instr.mnemonic) != "-1")
    {
        next_loc = add(next_loc, "3", 0);
    }
    else if (instr.mnemonic == "RESB")
    {
        next_loc = add(next_loc, decToHex(stoi(instr.operand)), 1);
    }

    return next_loc;
}

// function to find the address of a label in the symbol table
// Function to retrieve the address of a label from the symbol table
string get_addr(string label_x)
{
    string label = "";      // To store the label extracted from the input string
    string label_addr = ""; // To store the address of the label, if found
    bool isOffset = false;  // Flag to indicate if an offset is present (after a comma)

    // Extract the label part from the input string before the comma (if any)
    for (char c : label_x)
    {
        if (c == ',') // Check for the comma indicating an offset
        {
            isOffset = true;
            break;
        }
        label += c; // Accumulate characters to form the label
    }

    // Search for the label in the symbol table
    auto it = symtab.find(label); // Find the label in the symbol table
    if (it != symtab.end())       // If the label exists in the symbol table
    {
        label_addr = it->second; // Get the address of the label
        if (isOffset)            // If there's an offset (comma present)
        {
            // Add the offset (8000 in this case) to the label's address
            label_addr = add(label_addr, "8000", 1);
        }
        return label_addr; // Return the final address
    }
    else
    {
        return "-1"; // Return "-1" if the label is not found in the symbol table
    }
}
void constructingIncompleteInstructionTable(string infile)
{
    // Initialize streams
    ifstream input(infile);
    ofstream output("incompTable.txt");
    auto cin_backup = cin.rdbuf();
    auto cout_backup = cout.rdbuf();
    cin.rdbuf(input.rdbuf());
    cout.rdbuf(output.rdbuf());

    // Program variables
    string startAddress, currentLoc, currentLocation;
    instruction instr;

    // Handle START directive
    instr = parser();
    startAddress = (instr.mnemonic == "START") ? instr.operand : "0000";

    if (instr.mnemonic == "START")
    {
        cout << startAddress << ' ' << setw(8) << left << instr.label
             << setw(8) << left << instr.mnemonic << instr.operand << endl;
        instr = parser();
    }

    currentLoc = startAddress;

    // Main processing loop
    while (instr.mnemonic != "END")
    {
        currentLocation = currentLoc;

        // Symbol table handling
        if (!instr.label.empty())
        {
            if (symtab.find(instr.label) != symtab.end())
            {
                cin.rdbuf(cin_backup);
                cout.rdbuf(cout_backup);
                cout << "Duplicate Symbol definition used" << endl;
                return;
            }
            symtab[instr.label] = currentLoc;
        }

        // Location counter update
        try
        {
            if (opcode(instr.mnemonic) != "-1")
            {
                currentLoc = add(currentLoc, "3", 0);
            }
            else
                switch (instr.mnemonic[0])
                {
                case 'R': // RESB or RESW
                    if (instr.mnemonic == "RESB")
                    {
                        currentLoc = add(currentLoc, decToHex(stoi(instr.operand)), 1);
                    }
                    else if (instr.mnemonic == "RESW")
                    {
                        currentLoc = add(currentLoc, decToHex(3 * stoi(instr.operand)), 1);
                    }
                    break;

                case 'B': // BYTE
                    if (instr.operand[0] == 'X')
                    {
                        int size = (instr.operand.length() - 3 + 1) / 2;
                        currentLoc = add(currentLoc, to_string(size), 1);
                    }
                    else
                    {
                        currentLoc = add(currentLoc, to_string(instr.operand.length() - 3), 1);
                    }
                    break;

                case 'W': // WORD
                    currentLoc = add(currentLoc, "3", 0);
                    break;

                default:
                    throw runtime_error("Invalid opcode");
                }
        }
        catch (...)
        {
            cin.rdbuf(cin_backup);
            cout.rdbuf(cout_backup);
            cout << "Invalid opcode used" << endl;
            return;
        }

        // Output intermediate file record
        cout << currentLocation << ' ' << setw(8) << left << instr.label
             << setw(8) << left << instr.mnemonic << instr.operand << endl;

        instr = parser();
    }

    // Handle END directive
    cout << currentLoc << ' ' << setw(8) << left << instr.label
         << setw(8) << left << instr.mnemonic << instr.operand << endl;

    prog_length = decToHex(hexToDec(currentLoc) - hexToDec(startAddress), 4);

    // Restore streams
    cin.rdbuf(cin_backup);
    cout.rdbuf(cout_backup);
}
void print_T_record(const t_record &record)
{
    string output = "T" + string("00") + record.start +
                    decToHex(record.length, 2) + record.objectCode;
    cout << output << endl;
}

void handle_error(const string &msg)
{
    auto restore_streams = []()
    {
        streambuf *cin_original = cin.rdbuf();
        streambuf *cout_original = cout.rdbuf();
        cin.rdbuf(cin_original);
        cout.rdbuf(cout_original);
    };

    restore_streams();
    cout << msg << endl;
}

string handle_BYTE_opcode(const string &operand)
{
    if (operand.empty() || operand.size() < 3)
    {
        return "";
    }

    string result;
    const char type = operand[0];
    const string content = operand.substr(2, operand.size() - 3);

    if (type == 'C')
    {
        for (const char &c : content)
        {
            result += decToHex(static_cast<int>(c));
        }
    }
    else
    {
        result = (content.size() % 2 == 0) ? content : "0" + content;
    }

    return result;
}

string handle_WORD_opcode(const string &operand)
{
    try
    {
        const int value = stoi(operand);
        return decToHex(value, 6);
    }
    catch (...)
    {
        return string(6, '0'); // Return "000000" on error
    }
}

void print_symbol_table()
{
    ofstream out("symbol_table.txt");
    out << setw(10) << left << "SYMBOL"
        << "|  " << setw(5) << left << "ADDRESS" << endl;

    for (const auto &entry : symtab)
    {
        out << setw(10) << left << entry.first << "|  " << setw(5) << left << entry.second << endl;
    }
}

void print_opcode_table()
{
    ofstream out("optable.txt");
    out << setw(10) << left << "Mnemonic"
        << "|  " << setw(5) << left << "Binary" << endl;

    for (const auto &entry : optable)
    {
        out << setw(10) << left << entry.first << "|  " << setw(5) << left << entry.second << endl;
    }
}

// Function to print both tables
void print_tables()
{
    print_symbol_table(); // Print symbol table to file
    print_opcode_table(); // Print opcode table to file
}

int main(int argc, char **argv)
{
    const string USAGE_MSG = "Usage: ./a.out {source file}";
    const int REQUIRED_ARGS = 2;

    // Input validation
    bool valid_args = (argc == REQUIRED_ARGS);
    if (!valid_args)
    {
        cout << USAGE_MSG << endl;
        return 0;
    }

    // Store source file path
    const string input_path(argv[1]);

    // Initialize assembler tables
    init_optable();

    // First pass assembler processing
    bool compilation_success = true;
    constructingIncompleteInstructionTable(input_path);

    // Output intermediate results
    if (compilation_success)
    {
        print_tables();
    }

    // Generate final object code
    if (compilation_success)
    {
        ifstream in("incompTable.txt");
        streambuf *cinbuf = cin.rdbuf();
        cin.rdbuf(in.rdbuf());
        remove("incompTable.txt");
        ofstream out("output.txt");
        streambuf *coutbuf = cout.rdbuf();
        cout.rdbuf(out.rdbuf());

        instruction next_instr;
        string begin_addr, obj_str, prog_entry;
        next_instr = inter_parser();

        // Handle program header
        begin_addr = (next_instr.mnemonic == "START") ? next_instr.operand : "0000";
        cout << "H"
             << setw(6) << left
             << (next_instr.mnemonic == "START" ? next_instr.label : "PROG")
             << "00" << begin_addr << "00" << prog_length << endl;

        if (next_instr.mnemonic == "START")
            next_instr = inter_parser();

        // resolving all of the forward references which have not been properly handled
        resolve_forward_references();
        // Setup text record tracking
        t_record curr_text;
        curr_text.start = begin_addr;
        curr_text.length = 0;
        curr_text.objectCode.clear();
        remove("incompTable.txt");
        while (next_instr.mnemonic != "END")
        {
            obj_str.clear();

            if (next_instr.mnemonic == "RESW" || next_instr.mnemonic == "RESB")
            {
                // Handle reserved space
                if (curr_text.length)
                {
                    print_T_record(curr_text);
                    curr_text.start.clear();
                    curr_text.objectCode.clear();
                    curr_text.length = 0;
                }
            }
            else
            {
                // Generate object code
                string op_val = opcode(next_instr.mnemonic);

                if (op_val != "-1")
                {
                    // Regular instruction processing
                    obj_str = op_val;

                    if (next_instr.operand.empty())
                        obj_str += "0000";
                    else
                    {
                        string addr = get_addr(next_instr.operand);
                        if (addr == "-1")
                        {
                            handle_error("Unidentified Symbol usage encountered");
                            return 0;
                        }
                        obj_str += addr;
                    }
                }
                else if (next_instr.mnemonic == "BYTE")
                    obj_str = handle_BYTE_opcode(next_instr.operand);
                else if (next_instr.mnemonic == "WORD")
                    obj_str = handle_WORD_opcode(next_instr.operand);

                // Update text record
                int obj_len = obj_str.size() / 2;

                if ((curr_text.length + obj_len) > T_RECORD_MAX)
                {
                    print_T_record(curr_text);
                    curr_text.start.clear();
                    curr_text.objectCode.clear();
                    curr_text.length = 0;
                }

                if (!obj_str.empty())
                {
                    curr_text.length += obj_len;
                    curr_text.objectCode += obj_str;

                    if (curr_text.start.empty())
                        curr_text.start = next_instr.address;
                }
            }

            next_instr = inter_parser();
        }

        // Output final text record
        if (curr_text.length)
            print_T_record(curr_text);

        // Process program entry point
        if (!next_instr.operand.empty())
        {
            string entry = get_addr(next_instr.operand);
            if (entry != "-1")
                prog_entry = entry;
            else
            {
                handle_error("Unidentified Symbol usage encountered");
                return 0;
            }
        }
        else
            prog_entry = begin_addr;
        // Write end record
        cout << "E" << "00" << prog_entry << endl;

        cin.rdbuf(cinbuf);
        cout.rdbuf(coutbuf);

        print_symbol_table(); // Print symbol table to file
        print_opcode_table(); // Print opcode table to file
    }
    remove("incompTable.txt");
    return compilation_success ? 0 : 1;
}