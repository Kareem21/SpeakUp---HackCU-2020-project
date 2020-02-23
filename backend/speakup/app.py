from chalice import Chalice, Response
import json
from os import environ as env
import uuid
import pymongo


app = Chalice(app_name='speakup')

# MongoDB Atlas config
usr = env.get('MONGO_DB_USER')
pwd = env.get('MONGO_DB_PASS')
mongo_db_name = env.get('MONGO_DB_NAME')
mongo_collection_name = env.get('MONGO_COLLECTION_NAME')
url = env.get('MONGO_DB_URL')
# Connection string
client = pymongo.MongoClient("mongodb+srv://" + usr + ":" + pwd + "@" + url + "/test?retryWrites=true&w=majority")
db = client[mongo_db_name]
collection = db[mongo_collection_name]

@app.route('/incident/create', methods=['POST'])
def create():
    request_body = app.current_request.json_body
    if request_body:
        incident = {
                '_id': str(uuid.uuid1()),
                'incident': request_body
        }

        collection.insert_one(incident)
        try:
            return Response(status_code=200,
                           headers={'Content-Type':'application/json'},
                           body={'status':'success',
                                 'data':json.dumps(incident)
                           }
                          )
        except Exception as err:
            return Response(status_code=400,
                    headers={'Content-Type': 'application/json'},
                    body={'status':'failed',
                          'message': err.msg
                         }
                    )

