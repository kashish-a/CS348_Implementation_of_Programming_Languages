// Function declarations and definitions with various return types
integer add(integer a, integer b) begin
    return a + b;
end

float calculateAverage(integer x, integer y) begin
    float result;
    result = (x + y) / 2.0;
    return result;
end

char getFirstChar(char c) begin
    return c;
end

void printMessage() begin
    // This is a void function
    return;
end

// Main function to test all features
integer main() begin
    // Variable declarations with different types
    integer a;
    integer b;
    integer result;
    float f1;
    float f2;
    char c;
    integer arr[10];
    
    // Simple assignments
    a = 10;
    b = 20;
    f1 = 3.14;
    f2 = 2.71;
    c = 'A';
    
    // Arithmetic operations
    result = a + b;
    result = a - b;
    result = a * b;
    result = a / b;
    result = a % b;
    
    // Unary operations
    result = -a;
    result = +a;
    
    // Increment/decrement (if supported)
    a = a + 1;
    b = b - 1;
    
    // Logical operations
    if (a > b) begin
        result = a;
    end else begin
        result = b;
    end
    
    if (a == 10 && b == 20) begin
        result = 1;
    end
    
    if (a == 5 || b == 5) begin
        result = 0;
    end
    
    // Conditional expression (ternary if supported)
    result = (a > b) ? a : b;
    
    // Loops
    integer i;
    for (i = 0; i < 10; i = i + 1) begin
        arr[i] = i * i;
    end
    
    i = 0;
    
    // Nested blocks
    begin
        integer localVar;
        localVar = 100;
        result = localVar * 2;
    end
    
    // Function calls
    result = add(a, b);
    f2 = calculateAverage(a, b);
    c = getFirstChar('X');
    printMessage();
    
    // Pointer operations (if supported)
    integer *ptr;
    ptr = &a;
    result = *ptr;
    
    // Return statement
    return result;
end