from flask         import Flask
from routes        import KeyGen
from routes        import GetIP
from routes        import GetConnectivity
from Database      import miaou
import                    logging

"""
__author__ = "MiaouCorp"
__copyright__ = "Nothing"
__license__ = "Private"
__version__ = "1.2"
"""

logging.basicConfig(filename='miaou.log', level=logging.INFO)
app = Flask(__name__)

app.config['MYSQL_HOST'] = 'localhost'
app.config['MYSQL_USER'] = 'root'
app.config['MYSQL_PASSWORD'] = 'admin'
app.config['MYSQL_DB'] = 'bongocat'

miaou.init_app(app)

app.register_blueprint(KeyGen.keyGen)
app.register_blueprint(GetIP.getIP)
app.register_blueprint(GetConnectivity.getConnectivity)

if __name__ == "__main__":
    app.run()