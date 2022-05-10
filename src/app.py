import os
import sys
# import sqlalchemy
# import sqlalchemy.orm 
import flask 
import pytest

app = flask.Flask(__name__)
app.secret_key = "oerifjw;DFjniwrnvKesj_slfiun*&"

@app.route("/")
@pytest.fixture()
def index():
    return flask.send_file("../static/index.html")
    
@app.route("/<path:static_filename>")
def static_files(static_filename):
    return flask.send_file(f"../static/{static_filename}")    