function [r,teta] = complejo(z)
  
  
  r = abs(z)
  teta = rad2deg(asin(imag(z)/abs(z)))
  
  
  
  
  a= [-10 10]
  b = a - a
  hold on 
    plot(a,b);
    plot(b,a)
    plot(z,'+')
endfunction
