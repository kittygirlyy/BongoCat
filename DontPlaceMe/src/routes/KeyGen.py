from flask            import Blueprint, jsonify, request
from itertools        import cycle
from Database         import miaou
import                       base64, hashlib

keyGen = Blueprint('KeyGen', __name__,)

def superXor(key,data):
    xored = ''.join(chr(ord(c)^ord(k)) for c,k in zip(data, cycle(key)))
    xored = xored.encode('ascii')
    return base64.b64encode(bytes(xored)).strip()

def addInDB(IP, KEY):
    cursor = miaou.connection.cursor()
    cursor.execute(''' INSERT INTO keygen VALUES(%s,%s)''',(IP,KEY))
    miaou.connection.commit()
    cursor.close()

@keyGen.route('/giveMyKey', methods = ['POST'])
def index():
    data = request.get_json()
    IP = request.environ['REMOTE_ADDR']
    KEY = hashlib.sha224(IP.encode("utf-8")).hexdigest()
    addInDB(IP, KEY)
    res = {'miaou': 'meow'}
    return jsonify(res)