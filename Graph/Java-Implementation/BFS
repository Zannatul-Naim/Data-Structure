import java.util.LinkedList;
import java.util.Scanner;
import java.util.Queue;
import java.util.Iterator;

public class BFS { 

    static class Graph {
        int vertex;
        LinkedList<Integer>[] adjList;

        Graph(int vertex) {
            this.vertex = vertex;
            adjList = new LinkedList[vertex];
            for(int i = 0; i < vertex; i++) {
                adjList[i]  =new LinkedList<Integer>();
            }
        }
        void addEdges(int src, int dest) {
            adjList[src].add(dest);
            adjList[dest].add(src);
        }
    }
    BFS(Graph graph, int vertices, int start) {
        boolean[] visited = new boolean[vertices];
        Queue<Integer> queue = new LinkedList<Integer>();
        visited[start] = true;
        queue.add(start);
        while(!queue.isEmpty()) {
            start = queue.poll();
            System.out.print(start + " ");
            Iterator<Integer> i = graph.adjList[start].listIterator();
            while(i.hasNext()) {
                int temp = i.next();
                if(!visited[temp]) {
                    visited[temp] = true;
                    queue.add(temp);
                }
            }
        }

    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter number of vertices : ");
        int vertices = scan.nextInt();
        Graph graph = new Graph(vertices);
        System.out.print("\nEnter number of edges : ");
        int edges = scan.nextInt();
        System.out.println("\n");
        for(int i = 0; i < edges; i++) {
            int src, dest;
            src = scan.nextInt();
            dest = scan.nextInt();

            graph.addEdges(src, dest);
        }

        // Breadth First Traversing
        new BFS(graph, vertices, 4);

        scan.close();
    }
    
}


/*
input : 
0 1
0 3
0 4
1 3
1 2
2 3
3 4
 */
