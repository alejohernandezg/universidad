function ans = producto_matriz(A,B)
    %%La funcion recibe dos matrices: A y B
    %%C es la matriz resultante del producto de la matrices A y B 
    [nA, mB] = size(A);
    [nB, mB] = size(B);
    %% Con la funcion size() de Matlab se obtienen la cantidad de filas y %%columnas de cada matriz
    %% Se valida con el siguiente “if” que el numero de columnas de A (cA) sea igual al %%numero de filas de B (fB)
    if nA == nB 
       for i=1:mB %% Este “for” recorre la columnas de la matriz B
         for j=1:nA % Este “for” recorre la filas de la matriz A
               suma=0; % En suma se guarda la sumatoria de los elementos                                               
               for k=1:nA
                   suma=suma+A(j,k)*B(k,i);
    %% en la linea anterior se hace el producto de elemento por %%elemento  de cada fila y columna  y se le añade de una vez  a la %%sumatoria      
               end
             ans(j,i)=suma;
     %% La sumatoria final se guarda en la matriz resultante
            end
       end
    else
            disp('No se puede hacer el producto de las dos matrices');
    end
