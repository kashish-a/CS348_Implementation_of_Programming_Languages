void swap(integer *x, integer *y);

void main()
begin
    integer a = 10, b = 20;
    swap(&a, &b);
    return 0;
end

void swap(integer *x, integer *y)
begin
    integer temp;
    temp = *x;
    *x   = *y;
    *y   = temp;
    return;
end
