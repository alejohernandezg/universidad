function funcion = cerosFun()
    x=linspace(0,2,400);
    x(1)=[];
    y = exp(-(x.^2)).*sin(1./x.^2) + sqrt(x);
    
    y1 = @(x)exp(-(x^2))*sin(1/(x^2)) + sqrt(x);
    
    plot(x,y);
    hold on
    grid on
    %plot([0,2],[-
    x1 = [0.4 0.5];
    
    funcion = fzero(y1,[0.44 0.5]);
    
    
end