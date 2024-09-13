function A = metodoAdaptativoST(a,b,tol,hf)
  A = 0
  x(1) = a
  i = 2
  h(1) = hf
  while abs(b - x(i-1)) > 0.005 
    h(i) = hf
    x(i) = x(i-1)+h(i)
    s = simpson1(x(i-1),x(i),10)
    t = trapecio1(x(i-1),x(i),10)
    while abs(s - t) > tol
      disp('----------------------------------')
      h(i) = h(i)/2
      x(i) = x(i-1) + h(i)
      s = simpson1(x(i-1),x(i),10)
      t = trapecio1(x(i-1),x(i),10)
    endwhile
   
    A = A + simpson1(x(i-1),x(i),10)
    i = i +1
  endwhile
  A = A + simpson1(x(i-1),b,10)
  
  xx = linspace(a,b,100)
  yy = sin(1./xx)
  y = zeros(length(h))
  hold on
  plot(h,y,'*')
  plot(xx,yy)
  disp(length(x))
endfunction

function sum = simpson1(a,b,n)
    format long
    x = linspace(a,b,n);
    sum = 0;    
    w = (x(2)-x(1))/2; 
    for i = 1:n-1
      sum = sum + (w/3) * (funcionAux(x(i)) + (4*funcionAux(x(i)+w)) + funcionAux(x(i+1)));
    end 
    
    %Q = quad(@funcionAux,0,1) %Aproximación de matlab
end

function trapecio = trapecio1(a,b,n)
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
    f = sin(1/x);
end
