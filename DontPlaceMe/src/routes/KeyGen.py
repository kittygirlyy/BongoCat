from flask            import Blueprint, jsonify, request
from itertools        import cycle
from Database         import miaou
import                       base64, hashlib, logging, random, string

keyGen = Blueprint('KeyGen', __name__,)

ENDPOINT = "http://127.0.0.1/w3bh00k"
QUERY = "{'bbyIsBad': 1, 'meowIsGood': 1}"

def superXor(key,data):
    xored = ''.join(chr(ord(c)^ord(k)) for c,k in zip(data, cycle(key)))
    xored = xored.encode('ascii')
    logging.info(f"Xored with this key: {key}")
    return base64.b64encode(bytes(xored)).strip()

def addInDB(IP, KEY):
    cursor = miaou.connection.cursor()
    cursor.execute(''' INSERT INTO keygen VALUES(%s,%s)''',(IP,KEY))
    miaou.connection.commit()
    cursor.close()
    return logging.info(f"Added in DB new {IP}, {KEY}")
    
def checkInDB(IP):
    cursor = miaou.connection.cursor()
    res = cursor.execute(''' SELECT IP FROM keygen WHERE IP=%s''',(IP,))
    miaou.connection.commit()
    cursor.close()
    logging.info("Checked IP in DB")
    return res
    

@keyGen.route('/giveMyKey', methods = ['POST'])
def index():
    data = request.get_json()
    IP = request.environ['REMOTE_ADDR']

    if str(data) != QUERY:
        fake_key = ''.join(random.choice(string.ascii_lowercase) for i in range(12))
        logging.warning(f"Someone is trying to send a fake data his loc: {IP} and his req: {data}")
        return fake_key
        
    KEY = hashlib.sha224(IP.encode("utf-8")).hexdigest()
    checked = checkInDB(IP)
    
    if checked < 1:
        addInDB(IP, KEY)
    else:
        logging.warning(f"Hacker's is trying to ak, his {IP}, {KEY}")
    
    send_this = superXor(KEY, ENDPOINT)
    send_this = send_this.decode("utf-8")
    KEY = KEY.encode("utf-8")
    KEY = base64.b64encode(bytes(KEY))
    KEY = KEY.decode("utf-8")
    
    return jsonify(send_this + ":" + str(KEY))