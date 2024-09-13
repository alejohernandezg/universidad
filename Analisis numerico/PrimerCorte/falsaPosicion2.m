% METODO CERRADO - METODO DE LA FALSA POSICION

% Metodo que busca la raiz de una funcion entre un intervalo, funciona casi de manera similar
% a biseccion pero cambia la forma de encontrar el xr y gracias a esto se miniza el error y hace la funcion 
% mas eficiente.

function raiz = falsaPosicion2(xl,xu,tol)

    % xl es el valor inferior del intervalo.
    % xu es el valor superior del intervalo.
    % tol representa la tolerancia del error.

    % devuelve la raiz con 15 cifras.
    format long
    % N es el numero de iteraciones del algoritmo
    N = 2000;
    
    xl(1)= xl;
    xu(1)=xu;
    
    % xr es el valor medio
    xr(1) = xu(1)-(((funcion(xu(1)))*(xl(1)-xu(1)))/(funcion(xl(1))-funcion(xu(1))));
    
    % Si el valor de la primera multiplicacion entre la funcion evaluada en ambos
    % extremos del intervalo entonces no se podra realizar el algoritmo de biseccion
    % debido a que no cambia los signos y no corta el eje x.

    if funcion(xu(1))*funcion(xl(1)) > 0
        disp("Error")
    else
    
    for i = 2:N

        if funcion(xl(i-1))*funcion(xr(i-1)) < 0
            xl(i) = xl(i-1);
            xu(i) = xr(i-1);
            xr(i) = xu(i)-(((funcion(xu(i)))*(xl(i)-xu(i)))/(funcion(xl(i))-funcion(xu(i))));
        else
            xl(i) = xr(i-1);
            xu(i) = xu(i-1);
            xr(i) = xu(i)-(((funcion(xu(i)))*(xl(i)-xu(i)))/(funcion(xl(i))-funcion(xu(i))));
        end
        
        if abs(xr(i)-xr(i-1)) < tol
            disp("Resultttt");
            raiz = xr(i);
            break
        end
         
    end

    end
    
    
end

function y = funcion(x)
    y = sin(x)-x.^2;
     
end