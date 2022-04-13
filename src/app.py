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
    
@app.route("/<static_filename>")
def static_files(static_filename):
    return flask.send_file(f"../static/{static_filename}")    