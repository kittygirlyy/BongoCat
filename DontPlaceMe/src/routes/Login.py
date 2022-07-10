from flask import Blueprint, request, render_template

login = Blueprint('Login', __name__,)

@login.route('/login', methods = ['GET', 'POST'])
def index():
    error = None
    if request.method == 'POST':
        if request.form['username'] != 'admin' or request.form['password'] != 'admin':
            error = 'Les creds sont invalides'
        else:
            return "GG connecter"
    return render_template('login.html', error=error)