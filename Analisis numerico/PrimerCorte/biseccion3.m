%METODO CERRADO - METODO DE LA BISECCION

% Metodo relativamente ineficiente por que aproxima por "fuerza bruta" haciendo mas iteraciones.

function raiz = biseccion3(xl,xu,tol)

    % xl es el valor inferior del intervalo.
    % xu es el valor superior del intervalo.
    % tol representa la tolerancia del error.

    % devuelve la raiz con 15 cifras.
    format long
    % N es el numero de iteraciones del algoritmo
    N = 2000;
    

    xl(1)=xl;
    xu(1)=xu;

    % xr es el valor medio 
    xr(1)=(xl(1)+xu(1))/2;
    
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
                xr(i) = (xl(i)+xu(i))/2;
            else
                xl(i) = xr(i-1);
                xu(i) = xu(i-1);
                xr(i) = (xl(i)+xu(i))/2;            
            end
            
            if abs(xr(i)-xr(i-1)) < tol
                disp("Resulttttt");
                raiz=xr(i);
                break
            end
        end
        
        end
end

function y = funcion(x)
     y= sin(10*x)+cos(3*x);
end

