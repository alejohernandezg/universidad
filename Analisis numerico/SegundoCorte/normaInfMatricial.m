function norma = normaInfMatricial(A)
  x = linspace(-1,1,200);
  y = linspace(-1,1,200);
  N = [];
  for i = 1:length(x)
    for j = 1:length(y)
      N = [N, norma_Inf(A*[x(i);y(j)])];
    endfor
    norma = max(N);
  endfor
endfunction
