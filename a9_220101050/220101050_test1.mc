// declaration of variables(integer, float, char), 1D array, 2D array, functions and arithmetic operations

// global declarations
float d = 2.3;			   // float declaration
integer s, w[10];				   // 1D array declaration
float z[2][2];				   // 2D array declaration
integer a = 4, *p, b;			   // pointegerer declaration
void quotient(integer i, float d); // function declaration
char c;

void main()
begin
	// Variable Declaration
	integer x = 120;
	integer y = 17, sum, diff, prod, div, rem, and, or ;
	// Character definitions
	char ch = 'c', d = 'a';

	// Arithmetic Operations
	sum = x + y;
	diff = x - y;
	prod = x * y;
	div = x / y;
	rem = x % y;
	and= x & y;
	or = x | y;

	y = y << 2;
	x = x >> 1;

	return 0;
end
