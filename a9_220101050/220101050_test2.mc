integer factorial(integer n);

void main()
begin
    integer res;
    res = factorial(5);
    return 0;
end

integer factorial(integer n)
begin
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
end
