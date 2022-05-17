import os
import sys
# import sqlalchemy
# import sqlalchemy.orm 
import flask 

app = flask.Flask(__name__)
app.secret_key = "oerifjw;DFjniwrnvKesj_slfiun*&"

@app.route("/")
def index():
    return flask.send_file("../static/index.html")
    
@app.route("/<path:static_filename>")
def static_files(static_filename):
    return flask.send_file(f"../static/{static_filename}")   

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
            "descricao": "flavio"
        },
        {
            "descricao": "Gato"
        },
        {
            "descricao": "Cachorro"
        },
        {
            "descricao": "flavio"
        },
        {
            "descricao": "Gato"
        }
    ]
    return flask.jsonify(dicionario)

@app.route('/autenticar', methods = ['POST'])
def autenticar():
    obj = flask.request.get_json()
    email = obj['email']
    senha = obj['senha']
    emails_validos = [
        'dovm@cesar.school',
        'elgr@cesar.school',
        'ffcl@cesar.school',
        'jhcc2@cesar.school',
        'pevs@cesar.school',
        'csgg@cesar.school',
        'mk2@cesar.school',
        'mjwps@cesar.school'
    ]
    email_invalido = email not in emails_validos
    senha_invalida = senha != '12345'
    if email_invalido or senha_invalida:
        return flask.jsonify(False)
    return flask.jsonify(True) 

