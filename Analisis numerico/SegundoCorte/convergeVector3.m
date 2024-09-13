function XF = convergeVector3(T, C, X0, tol)
    %X0 es el vector columna
    %Matriz T
    %Vector C
   
    N = 20;
    X = X0;
    
    for i=2:N
        X(:,i) = T*X(:,i-1)+ C;
        if norma_p(X(:,i)-X(:,i-1),1)<tol
            XF = X(:,i);
            break;
%         else
%             disp("No converge con el numero de puntos o no converge")
%         end
    end
end