function norma = normaFrobenius(A)
    N = size(A);
    X= 1:N(1);
    if N(1) ~= N(2) %Si la matriz no es cuadrada no se evalúa la norma
        disp("No es una matriz cuadrada")
    else
        suma = 0;
        for i = 1:N(1)
            for j = 1:N(1)
                suma = suma +(A(i,j))^2;
            end
        end
    end
    norma = suma;
end