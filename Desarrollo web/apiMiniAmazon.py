"""INTEGRANTES
    Alejandro Hernandez
    Danny Julian Murcia """


from neo4jrestclient.client import GraphDatabase
from neo4jrestclient import client
from flask import Flask, request, Response
import json

db = GraphDatabase("http://localhost:7474", username="neo4j", password="1234")

app = Flask(__name__)

# API users----------------------------------------------------------------
@app.route("/mini-amazon/api/users", methods=["GET"])
def get_all_users():
    q = "MATCH (n:User) RETURN n"
    results = db.query(q, data_contents=True)
    users = []
    for r in results.graph:
        users.append((r['nodes'][0]['properties']))
    return json.dumps(users)

@app.route("/mini-amazon/api/users/<username>",methods=["GET"])
def get_one_user(username):
    q = "MATCH (n) WHERE n.username = "+"'" + username + "'"+" return n"
    print(type(q))
    results = db.query(q, data_contents=True)
    return results.graph[0]['nodes'][0]['properties']

@app.route("/mini-amazon/api/users", methods=["POST"])
def create_user():
    temp_firtsName = request.form['firstName']
    temp_lastName = request.form['lastName']
    temp_username = request.form['username']
    temp_password = request.form['password']
    temp_fechaRegistro = request.form['fecha'] 

    new_user = db.nodes.create(firstName=temp_firtsName, 
                                lastName=temp_lastName, 
                                username=temp_username, 
                                password=temp_password, 
                                fechaRegistro=temp_fechaRegistro)
    user = db.labels.get("User")
    user.add(new_user)
    
    return "User created!"

@app.route("/mini-amazon/api/users/<username>", methods=["PUT"])
def update_user(username):
    new_password = request.form['password']
    q = "MATCH (n { username:" + "'" + username + "'" + "}) SET n.password = "+ "'" +new_password +"'"
    db.query(q)
    return "User update!"

@app.route("/mini-amazon/api/users/<username>", methods=["DELETE"])
def delete_user(username):
    q = "MATCH (n { username:" + "'" + username + "'" + "}) DELETE n"
    db.query(q)
    return "User delete!"


# API products---------------------------------------------------------
@app.route("/mini-amazon/api/products", methods=["GET"])
def get_all_products():
    q = "MATCH (n:Product) RETURN n"
    results = db.query(q, data_contents=True)
    products = []
    for r in results.graph:
        products.append((r['nodes'][0]['properties']))
    return json.dumps(products)

@app.route("/mini-amazon/api/products/<product>",methods=["GET"])
def get_one_product(product):
    q = "MATCH (n) WHERE n.name = "+"'" + product + "'"+" return n"
    results = db.query(q, data_contents=True)
    return results.graph[0]['nodes'][0]['properties']

@app.route("/mini-amazon/api/products", methods=["POST"])
def create_product():
    temp_name = request.form['name']
    temp_description = request.form['description']

    new_product = db.nodes.create(name=temp_name, 
                                description=temp_description)
    product = db.labels.get("Product")
    product.add(new_product)
    
    return "Product created!"

@app.route("/mini-amazon/api/products/<product>", methods=["PUT"])
def update_product(product):
    new_description = request.form['description']
    q = "MATCH (n { name:" + "'" + product + "'" + "}) SET n.description = "+ "'" +new_description +"'"
    db.query(q)
    return "Product update!"

@app.route("/mini-amazon/api/products/<product>", methods=["DELETE"])
def delete_product(product):
    q = "MATCH (n { name:" + "'" + product + "'" + "}) DELETE n"
    db.query(q)
    return "Product delete!"

@app.route("/mini-amazon/api/customer/<usercustomer>/salesperson/<username>/star/<score>", methods=["PUT", "POST"])
def calificated(usercustomer, username, score):
    if request.method == 'POST':
        qcreater = "MATCH (n:Customer), (s:User) WHERE n.username = '" + usercustomer + "' AND s.username = '" + username +"'  CREATE (n)-[r:rate {score: "+score+"}]->(s)"
        db.query(qcreater)
        return "Calificated!"
    if request.method == 'PUT':
        qupdater = "MATCH (c:Customer {username:'" + usercustomer +"'})-[r]-(u:User {username:'"+username+"'}) SET r.score = "+score
        db.query(qupdater)
        return "Score update!"

    

if __name__ == "__main__":
    app.run(host='0.0.0.0', port=9090)



