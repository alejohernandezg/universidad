% METOOD ABIERTO - METODO DE NEWTON 

% No es recomendabe usar cuando la derivada sea muy complicada.

function raiz = newton (x0, tol)
    N = 20000;
    [y1,y2] = funcion(x0);
    x(1) = x0 - (y1/y2);
    
    for i = 2:N
        [y1,y2]= funcion(x(i-1));
        x(i)=x(i-1)-(y1/y2);
        res = abs(x(i)-x(i-1));
        
        if (res < tol)
            raiz = x(i);
            disp("converge")
            break
        end
    end
end

function [y1,y2] = funcion(x)
    % y1 es el resultado de evaluar x en la funcion
    y1 = (x^2)-2; 
    % y2 es el resultado de evaluar x en la primera derivada de la funcion(Calular derivada a mano)
    y2 = 2*x;
end