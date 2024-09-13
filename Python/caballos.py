def caballos(n):
    i=0
    noHerrados=0
    masClavos=0
    porcentaje=0
    total=0
    masCostoso=0
    
    while i < n:
        nombreCaballo=str(input("Digite el nombre del caballo"))
        clavos = int(input("Digite el numero de clavos"))
        if clavos==0:
            noHerrados= noHerrados+1
        else:
            if(clavos>=1):
                precio = (2**(clavos-1))
                total = total + precio
            if(masCostoso < precio):
                masCostoso=precio
                caballoCostoso=nombreCaballo
            if(clavos<6 and clavos <=1):
                porcentaje+=1
        i+=1
            
    porcentaje = (porcentaje*(100/n))
    print("Pago total", total)
    print("Caballo costoso", caballoCostoso)
    print("Caballos no herrados",noHerrados)
    print("Porcentaje de caballos que requieren menos de 6 clavos",porcentaje,"%")

caballos(2)
