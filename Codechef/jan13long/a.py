class Vertex:
 def __init__(self,key,value):
     self.key = key
     self.value = value

 def __str__(self):
     return "Key: "+str(self.key)+" Value: "+str(self.value)

 def __hash__(self):
     return self.key

class Graph:

 def __init__(self):
     self.adjacencyList = {}

 def __str__(self):
     return str(self.adjacencyList)

 def addVetex(self,key,value):
     if Vertex(key,value) not in self.adjacencyList:
         self.adjacencyList[Vertex(key,value)] = []

G = Graph()
G.addVetex(1,None)
G.addVetex(2,None)
G.addVetex(1,3)
print G
