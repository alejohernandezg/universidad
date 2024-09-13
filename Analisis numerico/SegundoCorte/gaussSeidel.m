function [ans,p] = gaussSeidel(A,b,x0,tol)
  D = diag(diag(A)); %Diagonal
  L = tril(A)-D; %Superior
  U = triu(A)-D; %Inferior
  
  T = -(inv(D+L))*U;
  C = inv((D+L))*b;
  if (matrizEDD(A)==1)
    [ans,p1] = iterativo(T,C,tol);
  else  
    radioE = max(abs(eig(T)));
    
    if radioE > 1
      disp("El radio espectral es mayor a 1")
    else
      [ans,p] = iterativo(T,C,tol);
    endif
  endif
endfunction


function [xf, p] = iterativo(T,c,tol)
  x0 = ones(length(T),1);
  N = 1000;
  
  for i = 1:N
    x1 = T*x0 + c;
    if norma_p(x1-x0,1) < tol
      xf = x1;
      p = i;
      break
    endif
    x0 = x1;
  endfor
endfunction
