"""INTEGRANTES
    Alejandro Hernandez
    Danny Julian Murcia"""

from neo4jrestclient.client import GraphDatabase

 

db = GraphDatabase("http://localhost:7474", username="neo4j", password="1234")

 

'''In this example, users and things will be nodes in our database.

Each node can be associated with labels, used to describe the type of node.

The following code will create two nodes labelled as User and two nodes labelled as Beer'''

 

# Create some users
user = db.labels.create("User")

user_alejo = db.nodes.create(firtsName="Alejandro",
                                lastName="Hernandez", 
                                username="alejo9720",
                                password="1234",
                                fechaRegisto="15-07-2019")

user_danny = db.nodes.create(firtsName="Danny",
                                lastName="Murcia",
                                username="Danny1234",
                                password="1234",
                                fechaRegisto="15-07-2019")


user_daniel = db.nodes.create(firtsName="Daniel",
                                lastName="Mamian",
                                username="Daniel1234",
                                password="1234",
                                fechaRegisto="15-07-2019")

user.add(user_alejo)
user.add(user_daniel)
user.add(user_danny)

 
#Create some products
product = db.labels.create("Product")

dron_product = db.nodes.create(name="Dron X5B0",
                                description="Es un dron con camara")

mouse_product = db.nodes.create(name="Mouse Gamer",
                                description="Es un Mouse Gamer")

teclado_product = db.nodes.create(name="Teclado Gamer",
                                    description="Es un Teclado Gamer")

lavadora_product = db.nodes.create(name="Lavadora LG",
                                    description="Es una Lavadora LG")


product.add(dron_product, mouse_product, teclado_product, lavadora_product)

 
#Create some customer
customer = db.labels.create("Customer")

customer_andrea = db.nodes.create(firtsName="Andrea",
                                    lastName="Timaran",
                                    username="andrea1234",
                                    password="1234",
                                    fechaRegisto="15-07-2019")

customer_maria = db.nodes.create(firtsName="Maria",
                                    lastName="Carrero",
                                    username="maria1234",
                                    fechaRegisto="15-07-2019")

customer.add(customer_maria, customer_andrea)

 

'''The second step is all about connecting the dots, which in graph DB terminology means

creating the relationships. '''

 

# User-offer->Products relationships

user_alejo.offer(dron_product,  date="16-07-2019", cost="500000", stock="10")

user_alejo.offer(lavadora_product,  date="16-07-2019", cost="1000000", stock="5")

user_daniel.offer(mouse_product,  date="17-07-2019", cost="50000", stock="60")

user_danny.offer(teclado_product,  date="18-07-2019", cost="60000", stock="80")

customer_andrea.buy(teclado_product, date="19-07-2019")
customer_andrea.buy(dron_product, date="21-07-2019")
customer_andrea.buy(mouse_product, date="19-07-2019")

customer_maria.buy(teclado_product, date="21-07-2019")
customer_maria.buy(mouse_product, date="21-07-2019")
customer_maria.buy(lavadora_product, date="21-07-2019")

customer_maria.rate(user_danny, score=9)
customer_maria.rate(user_daniel, score=8)
customer_maria.rate(user_alejo, score=10)

customer_andrea.rate(user_danny, score=7)
customer_andrea.rate(user_daniel, score=6)


'''The query language for Neo4j is called Cypher.

It allows to describe patterns in graphs, in a declarative fashion, i.e. just like SQL,

you describe what you want, rather then how to retrieve it.

Cypher uses some sort of ASCII-art to describe nodes, relationships and their direction.'''
