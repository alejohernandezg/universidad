

Lista tiempoMinimo(aeropuertoOrigen, aeropuertoDestino, Lista posibleRuta)
{
	new node = menorAristaTiempo(aeropuertoOrigen);
	if(node == aeropuertoDestino)
	{
		posibleRuta.addLast(node);
		return posibleRuta;
	}
	else{
		posibleRuta.addLast(node);
		tiempoMinimo(node, aeropuertoDestino, Lista posibleRuta);
	}
}

Lista escalasMinimas(aeropuertoOrigen, aeropuertoDestino, Lista posibleRuta)
{
	Lista posiblesCaminos;
	posiblesCaminos = aristasConectadas(aeropuertoOrigen);

	if(posiblesCaminos.contains(aeropuertoDestino)){
		cout << "Vuelo directo" << endl;
		posibleRuta.addLast(aeropuertoOrigen);
		posibleRuta.addLast(aeropuertoDestino);
		return posibleRuta;
	}
}

Lista distanciaMinima(aeropuertoOrigen, aeropuertoDestino, Lista posibleRuta)
{
	new node = menorAristaDistancia(aeropuertoOrigen);
	if(node == aeropuertoDestino)
	{
		posibleRuta.addLast(node);
		return posibleRuta;
	}
	else{
		posibleRuta.addLast(node);
		tiempoMinimo(node, aeropuertoDestino, Lista posibleRuta);
	}
}

Lista viajerosFrecuentes(string aerolinea, aeropuertoDestino,aeropuertoOrigen,Lista posibleRuta)
{
	if(!caminoAerolinea()){
		cout << "En el aeropuerto origen no hay rutas con la aerolinea deseada"
		return NULL;
	}else{
		new node = menorAristaTiempoAerolinea(aeropuertoOrigen,aerolinea);
		if(node == aeropuertoDestino)
		{
			posibleRuta.addLast(node);
			return posibleRuta;
		}else{
			posibleRuta = buscarRutaAerolinea(aeropuertoOrigen,aeropuertoDestino,aerolinea);
			return posibleRuta;
		}
	}
}

