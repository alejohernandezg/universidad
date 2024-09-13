function convergeMatriz(A,b,x0,tol)
  D = diag(diag(A)); %Diagonal
  L = tril(A)-D; %Superior
  U = triu(A)-D; %Inferior
  
  %Metodo de jacobi
  Tj = -(inv(D)*(L + U))
  Cj = inv(D)*b;
  
  %Metodo de GaussSeidel
  Tg = -(inv(D+L))*U;
  Cg = inv((D+L))*b;
  
  if (matrizEDD(A)==1)
    %Ambos metodos convergen si la matriz es Estrictamente Diagonal Dominante
    disp("Metodo de jacobi");
    iterativo(Tj,Cj,tol);
    disp("Metodo de GaussSeidel");
    iterativo(Tg, Cg, tol);
  else  
    radioEj = max(abs(eig(Tj)));
    radioEg = max(abs(eig(Tg)));
    if radioEj > 1
      disp("El radio espectral es mayor a 1")
    else
      disp("Metodo de jacobi");
      iterativo(Tj,Cj,tol);
      disp("Radio espectral:");
      disp(radioEj);
    endif
    
    if radioEg > 1
      disp("El radio espectral es mayor a 1")
    else
      disp("Metodo de GaussSeidel");
      iterativo(Tg,Cg,tol);
      disp("Radio espectral:");
      disp(radioEg);
    endif
    
  endif
endfunction


function [xf, p] = iterativo(T,c,tol)
  x0 = ones(length(T),1);
  N = 1000;
  
  for i = 1:N
    x1 = T*x0 + c;
    if norma_p(x1-x0,1) < tol
      disp("Solucion:");
      disp(x1);
      disp("Iteracion:");
      disp(i);
      break
    endif
    x0 = x1;
  endfor
endfunction

function ans = matrizEDD(A)
  n = length(A);
  diagonal = [n];
  cond = 1;
  for i=1:n
    max = 0;
    for j = 1:n
      if max <= abs(A(i,j))
        max = A(i,j);
        mayor = j;

      endif
    endfor
    if find(mayor==diagonal)
      disp("A no es de diagonal estrictamente dominante");
      cond = 0;
      ans = 0;
      break;
    else
      diagonal(i) = mayor;
    endif
    
  endfor
  if cond == 1
    ans = 1;
    disp("A es de diagonal estrictamente dominante");
  endif
endfunction
