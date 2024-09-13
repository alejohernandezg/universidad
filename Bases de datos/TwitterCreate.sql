-- Created by Vertabelo (http://vertabelo.com)
-- Last modification date: 2018-08-24 23:58:18.803

-- tables
-- Table: Ciudad
CREATE TABLE Ciudad (
    id_Ciudad smallint  NOT NULL,
    Nombre varchar2(20)  NOT NULL,
    id_Pais smallint  NOT NULL,
    CONSTRAINT Ciudad_pk PRIMARY KEY (id_Ciudad)
) ;

-- Table: Hashtag
CREATE TABLE Hashtag (
    id_Hashtag integer  NOT NULL,
    nombre varchar2(139)  NOT NULL,
    CONSTRAINT Hashtag_pk PRIMARY KEY (id_Hashtag)
) ;

-- Table: HashtagXTweet
CREATE TABLE HashtagXTweet (
    id_HashtagXTweet integer  NOT NULL,
    id_Tweet integer  NOT NULL,
    id_Hashtag integer  NOT NULL,
    CONSTRAINT HashtagXTweet_pk PRIMARY KEY (id_HashtagXTweet)
) ;

-- Table: Mensaje
CREATE TABLE Mensaje (
    id_Mensajes integer  NOT NULL,
    Mensaje varchar2(140)  NOT NULL,
    Fecha date  NOT NULL,
    Destinatario integer  NOT NULL,
    Remitente integer  NOT NULL,
    CONSTRAINT Mensaje_pk PRIMARY KEY (id_Mensajes)
) ;

-- Table: Pais
CREATE TABLE Pais (
    id_Pais smallint  NOT NULL,
    Nombre varchar2(15)  NOT NULL,
    CONSTRAINT Pais_pk PRIMARY KEY (id_Pais)
) ;

-- Table: Retweets
CREATE TABLE Retweets (
    id_Retweet integer  NOT NULL,
    id_Tweet integer  NOT NULL,
    id_Usuario integer  NOT NULL,
    CONSTRAINT Retweets_pk PRIMARY KEY (id_Retweet)
) ;

-- Table: Seguidores
CREATE TABLE Seguidores (
    id_Seguidores integer  NOT NULL,
    Estado char(3)  NOT NULL,
    seguidor integer  NOT NULL,
    seguido integer  NOT NULL,
    Usuario_id_Usuario integer  NOT NULL,
    CONSTRAINT Seguidores_pk PRIMARY KEY (id_Seguidores)
) ;

-- Table: Tweets
CREATE TABLE Tweets (
    id_Tweet integer  NOT NULL,
    Mensaje varchar2(140)  NOT NULL,
    Fecha date  NOT NULL,
    id_Usuario integer  NOT NULL,
    CONSTRAINT Tweets_pk PRIMARY KEY (id_Tweet)
) ;

-- Table: Usuario
CREATE TABLE Usuario (
    id_Usuario integer  NOT NULL,
    Nombre varchar2(15)  NOT NULL,
    Apellido varchar2(15)  NOT NULL,
    Correo varchar2(25)  NOT NULL,
    Numero number(10,0)  NOT NULL,
    Tipo_Perfil char(3)  NOT NULL CHECK (Tipo_Perdil == 'pub' OR Tipo_Perdil == 'prv'),
    Estado char(3)  NOT NULL CHECK (Estado == 'ina' OR Tipo_Estado == 'act'),
    id_Ciudad smallint  NOT NULL,
    Fecha date  NOT NULL,
    CONSTRAINT Usuario_pk PRIMARY KEY (id_Usuario)
) ;

-- foreign keys
-- Reference: Ciudad_Pais (table: Ciudad)
ALTER TABLE Ciudad ADD CONSTRAINT Ciudad_Pais
    FOREIGN KEY (id_Pais)
    REFERENCES Pais (id_Pais);

-- Reference: HashtagXTweet_Hashtag (table: HashtagXTweet)
ALTER TABLE HashtagXTweet ADD CONSTRAINT HashtagXTweet_Hashtag
    FOREIGN KEY (id_Hashtag)
    REFERENCES Hashtag (id_Hashtag);

-- Reference: HashtagXTweet_Tweets (table: HashtagXTweet)
ALTER TABLE HashtagXTweet ADD CONSTRAINT HashtagXTweet_Tweets
    FOREIGN KEY (id_Tweet)
    REFERENCES Tweets (id_Tweet);

-- Reference: Mensaje_Usuario1 (table: Mensaje)
ALTER TABLE Mensaje ADD CONSTRAINT Mensaje_Usuario1
    FOREIGN KEY (Destinatario)
    REFERENCES Usuario (id_Usuario);

-- Reference: Mensaje_Usuario2 (table: Mensaje)
ALTER TABLE Mensaje ADD CONSTRAINT Mensaje_Usuario2
    FOREIGN KEY (Remitente)
    REFERENCES Usuario (id_Usuario);

-- Reference: Retweets_Tweets (table: Retweets)
ALTER TABLE Retweets ADD CONSTRAINT Retweets_Tweets
    FOREIGN KEY (id_Tweet)
    REFERENCES Tweets (id_Tweet);

-- Reference: Retweets_Usuario (table: Retweets)
ALTER TABLE Retweets ADD CONSTRAINT Retweets_Usuario
    FOREIGN KEY (id_Usuario)
    REFERENCES Usuario (id_Usuario);

-- Reference: Seguidores_Usuario1 (table: Seguidores)
ALTER TABLE Seguidores ADD CONSTRAINT Seguidores_Usuario1
    FOREIGN KEY (seguidor)
    REFERENCES Usuario (id_Usuario);

-- Reference: Seguidores_Usuario2 (table: Seguidores)
ALTER TABLE Seguidores ADD CONSTRAINT Seguidores_Usuario2
    FOREIGN KEY (seguido)
    REFERENCES Usuario (id_Usuario);

-- Reference: Tweets_Usuario (table: Tweets)
ALTER TABLE Tweets ADD CONSTRAINT Tweets_Usuario
    FOREIGN KEY (id_Usuario)
    REFERENCES Usuario (id_Usuario);

-- Reference: Usuario_Ciudad (table: Usuario)
ALTER TABLE Usuario ADD CONSTRAINT Usuario_Ciudad
    FOREIGN KEY (id_Ciudad)
    REFERENCES Ciudad (id_Ciudad);

-- End of file.

