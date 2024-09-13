function n = norma_Inf(V)
    N = length(V);
    for i=1:N
        n = abs(V(i));
    end
    n = max(n);
end