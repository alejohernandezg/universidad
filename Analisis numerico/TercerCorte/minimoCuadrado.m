function [a,b] = minimoCuadrado(x,y)
  n = length(x)
  xi = 0
  yi = 0
  xiyi= 0
  xi2 = 0
  for i=1 :n
    xi = xi + x(i)
    yi = yi + y(i)
    xiyi = xiyi + x(i)*y(i)
    xi2 = xi2 + x(i)^2
  endfor
  
  a = ((n*(xiyi))-((xi)*(yi)))/((n*(xi2))-(xi))
  b = ((xi2*yi)-((xiyi)*(xi)))/((n*(xi2))-(xi)^2)
endfunction
