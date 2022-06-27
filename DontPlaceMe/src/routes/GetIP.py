from flask import Blueprint, request

getIP = Blueprint('GetIP', __name__,)

@getIP.route('/getIP')
def index():
    return request.environ['REMOTE_ADDR']