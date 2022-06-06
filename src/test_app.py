from app import app

def test_base_path():
    app_test = app.test_client()
    url = '/'
    response = app_test.get(url)
    assert response.status_code == 200

def test_base_path_to_content():
    with app.test_client() as test_client:
        response = test_client.get('/')
        assert b"PETSUPPORT'S" in response.data