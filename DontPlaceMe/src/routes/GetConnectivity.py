from flask import Blueprint

getConnectivity = Blueprint('GetConnectivity', __name__,)

@getConnectivity.route('/w3bh00k')
def index():
    return "1"