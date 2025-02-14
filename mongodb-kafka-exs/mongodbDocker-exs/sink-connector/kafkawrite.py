from kafka import KafkaProducer
import json
from json import dumps

p = KafkaProducer(bootstrap_servers = ['broker:29092'], value_serializer = lambda x:dumps(x).encode('utf-8'))

data = {'name': 'roscoe'}

p.send('Tutorial2.pets', value = data)

p.flush()

# These command are used in the docker interactive shell without the '$' symbol.
# $ python3 kafkawrite.py
# Commands to use mongo
# $ mongosh "mongodb://mongo1"
# Recall to use mongo commands with javascript instead of the shell you need to use mongoose in js file.
# $ use Tutorial2
# $ db.pets.find()