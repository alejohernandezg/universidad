¡function trapecio = trapecioCompuesto(a,b,n)
    format long
    x = linspace(a,b,n);
    h = (b-a)/(n-1); 
    sum = 0;    
    
    for i = 1:n-1
        sum = sum + (h/2) * (funcionAux(x(i)) + funcionAux(x(i+1)));
    end 
    trapecio = sum;
    %Q = quad(@funcionAux,0,1) %Aproximación de matlab
end


function f = funcionAux(x)
    f = exp(-x.^2);
end