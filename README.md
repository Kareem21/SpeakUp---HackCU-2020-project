# Speak up

A platform to help victims speak out against abusers (domestic abuse,bullying,etc) and help keep track of abusers and make sure they are held accountable in their local vicinity.  

https://devpost.com/software/speakup-u8ylwf/joins/mWXfUx0Lvvh1f1jJ4U5jQg

## Contents

Forms.dart : The form that users use to file an incident
Contact.dart: Class representing an incident
main.dart: The main page (includes directory, map, profile tabs) 


## Missing

* Needs the "+" button to launch form.dart 
* need to send a POST request from the form.dart to a mongoDB / other database. 
* Get data back from the mongoDB database and store it in the "directory" tab in the Flutter app
* Map and profile tabs are incomplete.

## Set up

get intellij and android studio installed/setup
add 
add flutter plugin ,dart will be included
file open project -> speakUPupdated



# Demo 

curl --request POST --url http://5a4dirdsw7.execute-api.us-east-2.amazonaws.com/api/incident/create --header 'content-type: application/json' --data '{"type": "test"}'
