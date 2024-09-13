function matriz = poliNewton(X)
  n = length(X);
  matriz = zeros(n,n);
  matriz(:,1) = 1;
  for j = 2 : n
    for i = j: n
      matriz(i,j) = (matriz(i,j-1))*(X(i)-X(j-1))
    endfor
  endfor
endfunction
