function X = prueba(A,b)
%     [L U]=lu(A);
%     
%     Y = L\b;
%     X = U\Y;
%     
%     format short

    [L U P] = lu(A);
    
    b2 = P*b;
    Y = triInf(L,b2);
    X = triSup(U,Y);
end