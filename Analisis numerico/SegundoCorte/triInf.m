function x = triInf(A,b)
  % A debe de ser triangular superior
  
  n = size(A);
  x(1) = b(1) / A(1,1);
  for i = 2:n(1)
    sum = 0;
    for j = 1: i-1
      sum = sum + A(i,j)*x(j);
    endfor  
    x(i)= (b(i) - sum ) / A(i,i);
  endfor
endfunction     