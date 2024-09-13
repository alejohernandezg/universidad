from franz.openrdf.sail.allegrographserver import AllegroGraphServer
from franz.openrdf.repository import Repository
from franz.miniclient import repository
from franz.openrdf.query.query import QueryLanguage

import os, urllib, datetime, time


def input():
    opcion = input('Deseas consultar algo? (Y/N)');
    while opcion == "Y":
        operacion = input('¿Que operacion realizamos? (1=A, 2=B, 3=Guardar)');
        if operacion == 1:
            consultarA();
        elif operacion == 2:
            consultarB();  
        elif operacion == 3:
            guardar();  

        opcion = input('Deseas consultar algo? (Y/N)');

def consultarB():
    cedula = input('Digite la cedula: ');
    mostrar(consultarDatos("Cliente", "SELECT ?Telefono WHERE { xs:" + cedula + " rdf:Telefono ?Telefono }. }"));

def consultarA():
    cedula = input('Digite la cedula: ');
    mostrar(consultarDatos("Cliente", "SELECT ?Nombre ?Direccion WHERE { xs:" + cedula + " rdf:Nombre ?Nombre OPTIONAL { xs:" + cedula + " rdf:Direccion  ?Direccion } . }. }"));

def guardar():
    namespace_ = "http://example.org/people/";

    juan = conn.createURI(namespace=namespace_, localname="Juan Sebastian");
    alejandro = conn.createURI(namespace=namespace_, localname="Alejandro Hernandez");
    
    relacion = conn.createURI(namespace=namespace_, localname="amigoDe");

    juanNodo = conn.createLiteral("Juan Sebastian");
    alejandroNodo = conn.createLiteral("Alejandro Hernandez");

    grafo = conn.createURI(namespace=namespace_, localname="Cliente"); 

    conn.add(juanNodo, relacion, alejandroNodo, grafo);
    conn.add(alejandroNodo, relacion, juanNodo, grafo);

def mostrar(resultado):
    for subLista in resultado:
        print("[S, P, O]: ", subLista[0], subLista[1], subLista[2]);

def obtenerRepositorio(repositorio):
    servidor = AllegroGraphServer("bd11@labsistemas.javerianacali.edu.co", port=9020, user="abcd1", password="abc1234");
    catalogo = servidor.openCatalog("system");
    miRepositorio = Repository(catalogo, repositorio, Repository.RENEW);
    miRepositorio.initialize();
    return miRepositorio;

def consultarDatos(repositorio, query):
    miRepositorio = obtenerRepositorio(repositorio);
    conexion = miRepositorio.getConnection();
    resultado = [];
    try:
        tupleQuery = conexion.prepareTupleQuery(QueryLanguage.SPARQL, query);
        resultado = tupleQuery.evaluate();
        try:
            for bindingSet in resultado:
                s = bingingSet.getValue("s");
                p = bingingSet.getValue("p");
                o = bingingSet.getValue("o");
                resultado.append([s, p, o]);

        resultado.close();

    conexion.close()

    return resultado;

input();