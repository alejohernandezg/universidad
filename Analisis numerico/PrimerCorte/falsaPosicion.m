function r = falsaPosicion(a,b,tol)
    %format long
    N = 50;
    
    if funcion(a)*funcion(b) > 0
        disp("error")
    end

    iter = 0;
    c = a;
    
    while(1)
        cAnt= c;
        c=b-funcion(b)*(a-b)/(funcion(a)-funcion(b));
        iter = iter + 1;

        if c ~= 0
            err=abs((c-cAnt)/c)* 100;
        end
        
        res = funcion(a)*funcion(c);
        
        if res < 0
            b = c;
        elseif res > 0
            a = c;
        else
            err = 0;
        end
        
        if err <= tol || iter >= N
            break
        end
    end
    r= c;
end


function y = funcion(x)
    %y=exp(-x^2);
    %y=exp(-x^2)*sin(x+2);
    %y= log(x^2)*sin(x)+x^3;
    %y=sin(x)-x;
    y= sin(10*x)+cos(3*x);
end