% METODO ABIERTO - METODO DE LA SECANTE

% requiere de dos valores iniciales


function raiz = secante(x0,x1,tol)
    iter = 0;
    N=2000;
    
    for i = 2:N
        xn = x0 - ((funcion(x0)*(x1-x0))/(funcion(x1)-funcion(x0)));
        iter = iter + 1;
        if xn ~=0
            err = abs((xn-x0)/xn)*100;
        end
        if err <= tol || iter >= N
            break
        end
        
        x0 = x1;
        x1 = xn;
    end
    
    raiz = xn;
end

function y = funcion(x)
        y = exp(-(x.^2)).*sin(1./x.^2) + sqrt(x);
end
