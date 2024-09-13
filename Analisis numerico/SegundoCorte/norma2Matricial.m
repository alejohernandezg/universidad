function norma = norma2Matricial(A)
    N = size(A);
    X= 1:N(1);
    if N(1) ~= N(2) %Si la matriz no es cuadrada no se evalúa la norma
        disp("No es una matriz cuadrada")
    else
        B = A'.*A;
        vPropio = eig(B);
        X = 1:N(1);
        for i = 1:N(1)
            X(i) = abs(vPropio(i))
        end
    end
    P = max(X);
    norma = sqrt(P);
end