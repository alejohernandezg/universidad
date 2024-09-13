% METODO ABIERTO - METODO DE PUNTO FIJO

% Solo necesitan un solo valor para iniciar

% La convergencia de los metodos abiertos es mas rapido que la de los cerrados.

% El punto fijo converge cuando | f'(x) | < 1

%Previene la divergencia, pero tarda mas en converger que el metodo de la secante

function p = puntoFijo(x0,tol)
    N = 20000;
    x(1) = x0;
    for i=2:N
        x(i)=funcion(x(i-1));
        
        if abs(x(i)-x(i-1)) < tol
            p=x(i);
            break;
        end
    end
end

function y=funcion(x)
    y= sin(10*x)+cos(3*x);

end


