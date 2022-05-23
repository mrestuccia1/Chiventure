# Graph validator algorithm
# example input: python src/graph_validator.py examples/wdl/npc_example.wdl
import sys
import json

def validate(graph):
    cyclical = check_cylicality(graph)

    return True


# Functions to check circularity of nodes
def check_node(graph, v, visited, recStack):
        visited[v] = True
        recStack[v] = True
 
        for neighbour in graph[v]:
            if visited[neighbour] == False:
                if check_node(graph, neighbour, visited, recStack) == True:
                    return True
            elif recStack[neighbour] == True:
                return True
        recStack[v] = False
        return False
 
# Returns true if graph is cyclic else false
def check_cylicality(graph):
    vertices = len(graph)
    visited = [False] * (vertices + 1)
    visited = dict(zip(graph.keys(), visited))
    recStack = [False] * (vertices + 1)
    recStack = dict(zip(graph.keys(), recStack))
    for node in visited.keys():
        if visited[node] == False:
            if check_node(graph, node, visited,recStack) == True:
                return True
    return False
    


# This function checks that every node can be reached
# in the graph
def check_all_nodes(graph):


# Given a start node, check if there is a closed loop
# keep track of visited 
def closed_loop(graph, start_node):

# Checks if a node is a singleton
# Count if nodes is 1
def singleton_node(graph, node):

# Returns 1 if a node has a connection with itself
def self_loop(graph, node):
    if node in graph[node]:
        return True
    return False

# Looks through graph to find number of connections
# with a specific node 
def num_times_visit_node(graph, node):


def main():
    return 0


if __name__ == "__main__":
    main()
