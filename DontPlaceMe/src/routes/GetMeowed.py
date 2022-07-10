from flask import Blueprint

getMeowed = Blueprint('GetMeowed', __name__,)

@getMeowed.route('/aked', methods = ['POST'])
def index():
    return "Soon"