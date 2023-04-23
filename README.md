# Find-Best-locations-in-the-map

data_structure project for 3ed sem

An Algorithm is a sequence of unambiguous instructions for 
solving a problem, i.e., for obtaining a required output for 
any legitimate input in a finite amount of time.


Problem Statement : 
Consider that a road transport agency is in difficulty of travelling long distances and 
consuming more fuel. In order to save fuel, the agency has decided to find out the shortest 
path possible to travel between different cities and follow that shortest distance path to 
transport goods from a source city to a destination city.

Explanation :
We are using Dijkstra’s Algorithm to solve this issue. The user is asked to enter the 
number of cities that are involved in road transport of goods. Then the user is asked to 
enter the distance of all cities from one another.
The source and destination cities are entered by the user. Then by using Dijkstra’s 
Algorithm we will consider the adjacency matrix and the source and destination vertices and 
find the shortest path and the shortest distance possible.

Design technique used :
One algorithm for finding the shortest path from a starting node to a target node in a 
weighted graph is Dijkstra’s algorithm. The algorithm creates a tree of shortest paths from 
the starting vertex, the source, to all other points in the graph.
Dijkstra’s algorithm, published in 1959 and named after its creator Dutch computer 
scientist Edsger Dijkstra, can be applied on a weighted graph. The graph can either be 
directed or undirected. One stipulation to using the algorithm is that the graph needs to 
have a nonnegative weight on every edge.


Algorithm : 

function Dijkstra(Graph, source):
 dist[source] := 0 
 for each vertex v in Graph:
 if v ≠ source 
 dist[v] := infinity
 add v to Q
 whileQ is not empty:
 v := vertex in Q with min dist[v]
 remove v from Q 
 for each neighbor u of v:
 alt := dist[v] + length(v, u) 
 if alt < dist[u]:
 dist[u] := alt
return dist[] 
end function

Dijkstra's Algorithm Complexity:

Time Complexity: O(E Log V)
where, E is the number of edges and V is the number of vertices.
Space Complexity: O(V)
