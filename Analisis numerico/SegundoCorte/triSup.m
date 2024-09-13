function x = triSup(A, b)
    N = size(A);
    
    x = zeros(N(1),1);
    
    for i=N(1):-1:1
        x(i)= (b(i)- A(i,i+1:N)*x(i+1:N))/A(i,i);
        
%A(i,i+1:n) contiene los elementos que están en la fila i,
%y en las columnas desde la i+1 hasta la n, es decir A(i,i+1), 
%A(i,i+2), A (i,i+3), ... A(i,n-1), A(i,n). 
% El vector columna x(i+1:n) contiene los elementos de x que van 
%desde el i+1 hasta el n, es decir x(i+1), x(i+2), ..., x(n-1), x(n).
    end
end