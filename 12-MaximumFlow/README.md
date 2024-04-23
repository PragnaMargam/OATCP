This program implements the Ford-Fulkerson algorithm to calculate the maximum flow in a network. The maximum flow problem involves finding the largest possible flow from a source node to a sink node in a flow network. A flow network comprises nodes (vertices) and directed edges (arcs) with specified capacities, indicating the maximum flow they can handle. The objective is to determine the maximum flow that can be transported from the source to the sink without exceeding the capacities of the edges and while ensuring that the flow is conserved at intermediate nodes.

Overview of the Ford-Fulkerson Algorithm:
The Ford-Fulkerson algorithm is a well-known method for solving the maximum flow problem. It does this by repeatedly locating augmenting paths from the source to the sink and increasing the flow along these paths until no more augmenting paths are found. An augmenting path is a sequence of nodes connecting the source to the sink where additional flow can be added without exceeding edge capacities.

Here is the general procedure for the Ford-Fulkerson algorithm:

1. Initialization: Set the initial flow on all edges to zero.
2. Finding Augmenting Paths: While there is an augmenting path from the source to the sink:
   - Use a search algorithm, such as Breadth-First Search (BFS), to find an augmenting path.
   - Determine the maximum flow that can be pushed through this path.
   - Update the flow along the augmenting path, adjusting each edge's flow accordingly.
3. Return Maximum Flow: When no more augmenting paths can be found, return the total maximum flow.

Implementation Highlights:
The C++ implementation in this repository includes the following features:

- Reads a flow network from a file called `in.txt`, containing details about the number of nodes, the source and sink nodes, and the capacities of the edges.
- Uses the Ford-Fulkerson algorithm to compute the maximum flow in the given network.
- Outputs the maximum flow result to a file called `out.txt`.

This program serves as a practical implementation of the Ford-Fulkerson algorithm for solving maximum flow problems in network graphs.
