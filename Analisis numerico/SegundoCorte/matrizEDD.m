function ans = matrizEDD(A)
  n = length(A);
  diagonal = [n];
  cond = 1;
  for i=1:n
    max = 0;
    for j = 1:n
      if max <= abs(A(i,j))
        max = A(i,j);
        mayor = j;

      endif
    endfor
    if find(mayor==diagonal)
      disp("No es de diagonal estrictamente dominante");
      cond = 0;
      ans = 0;
      break;
    else
      diagonal(i) = mayor;
    endif
    
  endfor
  if cond == 1
    ans = 1;
    disp("Es de diagonal estrictamente dominante");
  endif
endfunction
