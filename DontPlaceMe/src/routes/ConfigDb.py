from flask_mysqldb import MySQL

app.config['MYSQL_HOST'] = 'localhost'
app.config['MYSQL_USER'] = 'root'
app.config['MYSQL_PASSWORD'] = 'admin'
app.config['MYSQL_DB'] = 'bongocat'

mysql = MySQL(app)

def juif(IP, KEY):
    cursor = mysql.connection.cursor()
    cursor.execute(''' INSERT INTO keygen VALUES(%s,%s)''',(IP,KEY))
    mysql.connection.commit()
    cursor.close()