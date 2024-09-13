function g = metodoGrafico()
    
    %Eje x
    plot([-4 8],[0 0]);
    
  
    %funcion
    x = linspace(-3,8,400);
    y= sin(10*x)+cos(3*x);
    
    hold on
    plot(x,y);
    grid on;
end