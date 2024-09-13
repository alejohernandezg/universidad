function sum = simpson(a,b,n)
    format long
    x = linspace(a,b,n);
    sum = 0;    
    w = (x(2)-x(1))/2; 
    for i = 1:n-1
      sum = sum + (w/3) * (funcionAux(x(i)) + (4*funcionAux(x(i)+w)) + funcionAux(x(i+1)));
    end 
    
    Q = quad(@funcionAux,0,1) %Aproximación de matlab
end


function f = funcionAux(x)
    f = exp(-x.^2);
end