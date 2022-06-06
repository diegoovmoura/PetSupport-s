import os
import sys
# import sqlalchemy
# import sqlalchemy.orm 
import flask 

# INIT
app = flask.Flask(__name__)
app.secret_key = "oerifjw;DFjniwrnvKesj_slfiun*&"

# CONTROLLER
@app.route('/') 
def index():
    return flask.send_file("../static/index.html")

# CONTROLLER
@app.route("/<path:static_filename>")
def static_files(static_filename):
    return flask.send_file(f"../static/{static_filename}")

# MODELS
@app.route('/animais', methods = ['GET'])
def animais():
    dicionario = [
        {
            "descricao": "Gato"
        },
        {
            "descricao": "Cachorro"
        },
        {
            "descricao": "Peixe"
        },
        {
            "descricao": "Gato"
        },
        {
            "descricao": "Cachorro"
        },
        {
            "descricao": "Passáro"
        },
        {
            "descricao": "Gato"
        }
    ]
    return flask.jsonify(dicionario)

# MODELS
@app.route('/autenticar', methods = ['POST'])
def autenticar():
    obj = flask.request.get_json()
    email = obj['email']
    senha = obj['senha']
    emails_validos = [
        'dovm@cesar.school',
        'rjhxa@cesar.school'
    ]
    email_invalido = email not in emails_validos
    senha_invalida = senha != '12345'
    if email_invalido or senha_invalida:
        return flask.jsonify(False)
    return flask.jsonify(True) 