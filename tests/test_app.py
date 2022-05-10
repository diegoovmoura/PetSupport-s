import pytest
from src.app import index

class AppTest():

    @pytest.fixture()
    def app():
        app = index()
        app.config.update({
            "TESTING": False,
        })