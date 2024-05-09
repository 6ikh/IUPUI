from bottle import default_app, route, post, get, template

#@route('/')
#def menu():
    #return("Hi there")
    #return template("menu.html")

@route('/bmi')
def basicForm():
    return template("form.html")

@post('/convert')
def convert():
    return template("result.html")

#@route('/bmi_blackbelt')
#def basicForm():
    #return template("bbform.html")

#@post('/convert')
#def convert():
    #return template("bbresult.html")


#Used to display source code
@route('/showFile/<fileName>')
def showFile(fileName):
  return template("showFile.html", fileName = fileName)


application = default_app()
