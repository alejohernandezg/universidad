function [c,d]=biseccion2(a,b,tol)
    format long
    res1=fun(a)*fun(b);
    x=linspace(a,b,1000);
    y=fun(x);
    plot(x,y)
    grid on
    hold on
    if res1 > 0
           disp("Ingrese otro intervalo")
    else
        a1=a;
        b1=b;
        res2=abs(b-a);
        while res2 > tol
            c=(a1+b1)/2;
            if (fun(c)*fun(a1)<0)
                b1=c;
            else
                a1=c;
            end
            res2=abs(b1-a1);
            %plot(c,fun(c),'o')
        end
        plot(c,fun(c),'x')
        d=fun(c);
    end
    
    
    
end

function y=fun (x)
    %y=exp(-x.^2).*sin(x+2);
    y= sin(10*x)+cos(3*x);
end