function n = norma_p(V, p)
  
  N = length(V);
  sum = 0;
  for i=1:N
    sum = sum + (abs(V(i)).^p);
  endfor
  n = sum.^(1/p);
endfunction
