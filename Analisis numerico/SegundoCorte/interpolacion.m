function interpolacion()
  x = linspace(-1, 1, 100);
  y = 1./(1+(25*x.^2));
  
  x1 = linspace(-1, 1, 12)
  %y1 = (x1.^x1) + (log(abs((tan(exp(log10(1./x1)))).^2)));
  y1 = 1./(1+(25*x1.^2));
  hold on
  plot(x,y,'b')
  interpolDirecta(x1,y1,-1,1);
endfunction

function y =miFuncion(x)
  y = (x^x) + (log(abs((tan(exp(log10(1/x))))^2)));
endfunction
