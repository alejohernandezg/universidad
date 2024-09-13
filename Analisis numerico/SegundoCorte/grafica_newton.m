function grafica_newton(c, x, y)
  n = length(x);
  x1 = linspace(min(x)-0.5,max(x)+0.5, 300);
  for i=1:length(x1)
    x2(1) = 1;
    for j=2:n
      x2(j) = x2(j-1)*(x1(i)-x(j-1));
    endfor
    y1(i)=c*x2';
  endfor
endfunction
