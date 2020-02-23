import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:http/http.dart' as http;
import 'dart:convert';
import 'dart:async';
import 'contact.dart';


void main() => runApp(new MyApp());
Contact newContact = new Contact();
class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return new MaterialApp(
      title: 'New Incident',
      theme: new ThemeData(
        primarySwatch: Colors.blue,
      ),
      home: new MyHomePage(title: 'New incident'),
    );
  }
}
class MyHomePage extends StatefulWidget {
  MyHomePage({Key key, this.title}) : super(key: key);
  final String title;
  @override
  _MyHomePageState createState() => new _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  final GlobalKey<FormState> _formKey = new GlobalKey<FormState>();

  List<String> _colors = <String>['', 'red', 'green', 'blue', 'orange'];
  String _color = '';

  @override
  Widget build(BuildContext context) {
    return new Scaffold(
      appBar: new AppBar(
        title: new Text(widget.title),
        centerTitle: true,
      ),
      body: new SafeArea(
          top: false,
          bottom: false,
          child: new Form(
              key: _formKey,
              autovalidate: true,
              child: new ListView(
                padding: const EdgeInsets.symmetric(horizontal: 16.0),
                children: <Widget>[
                  new TextFormField(
                    decoration: const InputDecoration(
                      icon: const Icon(Icons.person),
                      hintText: 'Enter your first and last name',
                      labelText: 'Name',
                    ),
                  ),
                  new TextFormField(
                    decoration: const InputDecoration(
                      icon: const Icon(Icons.adjust),
                      hintText: 'Type of incident',
                      labelText: 'Incident type',
                    ),
                  ),
                  new TextFormField(
                    decoration: const InputDecoration(
                      icon: const Icon(Icons.person),
                      hintText: 'Name of perp',
                      labelText: 'Who',
                    ),

                  ),
                  new TextFormField(
                    decoration: const InputDecoration(
                      icon: const Icon(Icons.youtube_searched_for),
                      hintText: 'What City did this occur in?',
                      labelText: 'Where',
                    ),
                  ),
                  new Container(
                      padding: const EdgeInsets.only(left: 40.0, top: 20.0),
                      child: new RaisedButton(
                        child: const Text('Submit'),
                        onPressed:   () async {
                  const _serviceUrl = 'https://5a4dirdsw7.execute-api.us-east-2.amazonaws.com/api/incident/create';
                  const _headers = {'Content-Type': 'application/json'};
                  var response = await http.post(
                  Uri.encodeFull(_serviceUrl), body: json.encode({
                  "Name" : "Migel",
                  "Type" : "Domestic abuse",
                  "Where" : "denver",
                  "Who" : "wife"
                  }), headers: _headers);
                  print(response.body);},
                      )),
                ],
              ))),
    );
  }
}



    /*
    * child: const Text('Submit'),
                        onPressed: () async {
                          const _serviceUrl = 'http://mockbin.org/echo';
                          const _headers = {'Content-Type': 'application/json'};
                          var response = await http.post(
                              Uri.encodeFull(_serviceUrl), body: json.encode({
                          "Name" : "kaareem",
                          "Type" : "d abuse",
                          "Where" : "location",
                          "Who" : "rwkglfsg"
                          }), headers: _headers);}
    *
    * */