function [a,b] = minimoExpo(x,y)
  y2 = log10(y)
  [a,m] = minimoCuadrado(x,y2)
  b = exp(m)
  disp('Respuesta a')
  disp(a)
  disp('Respuesta b')
  disp(b)
endfunction
