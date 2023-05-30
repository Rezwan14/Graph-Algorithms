[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=11027909&assignment_repo_type=AssignmentRepo)
# Assignment-5-Code

To compile type:

 `make all`

To clean object files and executables type:

 `make clean`
 
To run the create and test graph routine, type:
`./CreateGraphAndTest <GRAPH_FILE> <ADJECENCY_QUERYFILE>`

where `<GRAPH_FILE>` is the file used to create the graph and
`<ADJECENCY_QUERYFILE>` is the file used to check if vertices
are adjacent

Example:
`./CreateGraphAndTest Graph1.txt AdjacencyQueries1.txt`

To run the find paths in graph routine, type:
`./FindPaths <GRAPH_FILE> <STARTING_VERTEX>`

where `<GRAPH_FILE>` is the file used to create the graph and 
`<STARTING_VERTEX>` is the vertex in the graph as the starting
point for the paths

Example:
`./FindPaths Graph2.txt 1`

Part1:
For this Project we were given both a graph and adjacentquerie txt files.
We had to set adjacent verticies, and weights for vertices that were adjacent in our 
graph file. Our output on our creategraphandtest file outputs our connected verticies
with weights, and not_connected for verticies that arent adjacent. 
compile keys:
g++ -g -std=c++14 -Wall -I -c -o CreateGraphAndTest CreateGraphAndTest.cc
test key:
./CreateGraphAndTest Graph1.txt AdjacentQueries1.txt

Part2:
Although I attempted this part, I was unsuccessful in completing it.
