function XF = ejemplo(T, C, X0, tol) 
  
  n = 20;
  x = X0;
  for i=2:n
    x(:, i) = T*x(:, i-1) + C;
    if norma_p(x(:, i)-x(:, i-1),1) < tol
      XF = x(:, i)
      Break
    endif
  endfor
  plot3(x(1,:),x(2,:),x(3,:),'+')
endfunction
