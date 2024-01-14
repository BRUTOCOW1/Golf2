import sys
import pyodbc

connection_string = "DRIVER={ODBC Driver 17 for SQL Server};SERVER=localhost;DATABASE=golf_db;UID=sa;PWD=golfPass1029@"
connection = pyodbc.connect(connection_string)
cursor = connection.cursor()
#cursor.execute("CREATE TABLE Tadpoles (Froggy int)")

def list_tables(cursor):
    cursor.execute("SELECT TABLE_NAME FROM information_schema.tables WHERE table_type = 'BASE TABLE';")
    rows = cursor.fetchall()
    for row in rows:
        print(row.TABLE_NAME)

def list_tadpoles(cursor):
    cursor.execute("SELECT * FROM Tadpoles;")
    rows = cursor.fetchall()
    for row in rows:
        print(row)

tStrings = [
    "BEGIN TRANSACTION;",
    "CREATE TABLE Tadpoles ( ID INT PRIMARY KEY, Froggy INT );",
    "INSERT INTO Tadpoles (ID, Froggy) VALUES (1, 2), (2, 8), (3, 12);",
    "COMMIT;"
]
#for t in tStrings:
#    cursor.execute(t)

list_tables(cursor)
list_tadpoles(cursor)

connection.commit()
connection.close()


#cmdStr = "mssql -u sa -p golfPass1029"



