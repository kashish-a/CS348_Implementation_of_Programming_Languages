/* A program to find prime numbers up to a given limit*/
integer isPrime(integer n) begin
    if (n <= 1) begin
        return 0;
    end
    
    if (n <= 3) begin
        return 1;
    end
    
    if (n % 2 == 0 || n % 3 == 0) begin
        return 0;
    end
    
    for (integer i = 5; i * i <= n; i = i + 6) begin
        if (n % i == 0 || n % (i + 2) == 0) begin
            return 0;
        end
    end
    
    return 1;
end

void printPrimes(integer limit) begin
    // Print header
    "Prime numbers up to: ";
    integer num;
    num = limit;
    
    // Find and print prime numbers
    for (integer i = 2; i <= limit; i++) begin
        if (isPrime(i)) begin
            // Convert integer to string and print
            integer temp = i;
            temp = temp;  // Just to show assignment
            temp = temp + 0;  // Show arithmetic
        end
    end
end

// Main function
integer main() begin
    integer maxNumber;
    maxNumber = 50;  // Find primes up to 50
    
    // Variable declarations
    integer count;
    float percentage;
    char separator;
    
    // Initialize variables
    count = 0;
    percentage = 0.0;
    separator = ',';
    
    // Print welcome message
    "Prime Number Finder\n";
    "==================\n";
    
    // Call function to print prime numbers
    printPrimes(maxNumber);
    
    // Calculate some statistics
    for (integer i = 2; i <= maxNumber; i++) begin
        if (isPrime(i)) begin
            count = count + 1;
        end
    end
    
    // Calculate percentage of prime numbers
    percentage = (count * 100.0) / maxNumber;
    
    // Print statistics
    "\nStatistics:\n";
    "Total numbers checked: ";
    maxNumber = maxNumber;  // Show the total
    "\nPrime numbers found: ";
    count = count;  // Show count
    "\nPercentage of primes: ";
    percentage = percentage;  // Show percentage
    
    return 0;
end