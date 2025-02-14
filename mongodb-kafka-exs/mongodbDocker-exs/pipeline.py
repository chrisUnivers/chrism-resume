import pymongo
from bson.json_util import dumps
client = pymongo.MongoClient('mongodb://mongo1')
db = client.get_database(name='Tutorial1')
pipeline = [ { "$match": { "$and": [ { "fullDocument.type": "temp" }, { "fullDocument.value": { "$gte": 100 } } ] } } ]
with db.sensors.watch(pipeline=pipeline) as stream:
    print('\nChange Stream is opened on the Tutorial1.sensors namespace.  Currently watching for values > 100...\n\n')
    for change in stream:
        print(dumps(change, indent = 2))

# use Tutorial1 (assuming the shell is not using this database. If it is skip this step)
# db.sensors.insertOne( { 'type' : 'temp', 'value':101 } )
# db.sensors.insertOne( { 'type' : 'temp', 'value': 99 } )
# db.sensors.insertOne( { 'type' : 'pressure', 'value': 22 } )