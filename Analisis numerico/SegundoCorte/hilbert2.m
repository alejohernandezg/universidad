function HIL = hilbert2(n)
HIL = []
    format long;
    for i = 1:n
        for j = 1:n
            HIL(i,j)=1/(i+j-1);
        end
    end
end