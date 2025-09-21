integer max(integer a, integer b);

void main()
begin
    integer m;
    m = max(10, 25);
    return 0;
end

integer max(integer a, integer b)
begin
    if (a > b)
        return a;
    else
        return b;
end
