import java.util.LinkedList;
import java.util.Scanner;

public class Graph {
    int vertex;
    LinkedList<Node>[]adjacencyList;
    class Node {
        int value, weight;
        Node(int value, int weight) {
            this.value = value;
            this.weight = weight;
        }
    }
    Graph(int vertex) {
        this.vertex = vertex;

        //@SuppressWarnings({"unchecked"});
        adjacencyList = new LinkedList[vertex];
        for(int i = 0; i < vertex; i++) {
            adjacencyList[i] = new LinkedList<>();
        }
    }
 
    void addEdge(int src, int dest, int weight) {
        adjacencyList[src].add(new Node(dest, weight));
        adjacencyList[dest].add(new Node(src, weight));
    }

    void printGraph() {
        for(int i = 0; i < vertex; i++) {
            System.out.print(i + " --> ");
            for(int j = 0; j < adjacencyList[i].size(); j++) {
                System.out.print(adjacencyList[i].get(j).value + "(" + adjacencyList[i].get(j).weight + "), ");
            }           
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int vertex;
        System.out.print("Enter Number of vertex : ");
        Scanner scan = new Scanner(System.in);
        vertex = scan.nextInt();
        Graph graph = new Graph(vertex);
        int edges;
        System.out.print("\nEnter number of edges : ");
        edges = scan.nextInt();
        System.out.println("\n");
        for(int i = 0; i < edges; i++) {
            int src, dest, weight;
            src = scan.nextInt();
            dest = scan.nextInt();
            weight = scan.nextInt();

            graph.addEdge(src, dest, weight);
        }

        graph.printGraph();
        System.out.println();
        scan.close();
    }
}

/*
input :

0 3 7
0 4 5
0 1 3
1 3 2
1 2 9
2 3 1
3 4 2

*/
