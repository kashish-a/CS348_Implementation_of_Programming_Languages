integer sumArray(integer arr[5]);

void main()
begin
    integer A[5], i, total;
    // initialize A[ ]
    i = 0;
    while (i < 5) begin
        A[i] = i * 2;
        i = i + 1;
    end

    total = sumArray(A);
    return 0;
end

integer sumArray(integer arr[5])
begin
    integer sum, i;
    sum = 0;
    i   = 0;
    while (i < 5) begin
        sum = sum + arr[i];
        i   = i + 1;
    end
    return sum;
end
