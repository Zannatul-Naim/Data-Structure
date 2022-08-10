import java.util.LinkedList;
import java.util.Scanner;
import java.util.Stack;
import java.util.Iterator;

class Graph {
    int vertex;
    LinkedList<Integer>[]adjList;

    Graph(int vertex) {
        this.vertex = vertex;
        adjList = new LinkedList[vertex];
        for(int i = 0; i < vertex; i++) {
            adjList[i] = new LinkedList<Integer>();
        }
    }
    void addEdge(int src, int dest) {
        adjList[src].add(dest);
        adjList[dest].add(src);
    }
}

public class DFS {

    public DFS(Graph graph, int start) {
        boolean[] visited = new boolean[graph.vertex];
        for(int i = 0; i< graph.vertex; i++) {
            visited[i] = false;
        }
        Stack<Integer> stack = new Stack<>();
        stack.push(start);
        while(!stack.isEmpty()) {
            int s = stack.peek();
            stack.pop();
            if(!visited[s]) {
                System.out.println(s + " ");
                visited[s] = true;
            }
            Iterator<Integer> it = graph.adjList[s].listIterator();
            while(it.hasNext()) {
                int x = it.next();
                if(!visited[x]) {
                    stack.push(x);
                }
            }
        }
    }
    public static void main(String[] args) {
        System.out.println("Enter number of Vertices : ");
        Scanner scan = new Scanner(System.in);
        int vertex = scan.nextInt();
        Graph graph = new Graph(vertex);
        System.out.println("Enter number of Edges : ");
        int edges = scan.nextInt();
        System.out.println("Enter Edges : ");
        for(int i = 0; i < edges; i++) {
            int src, dest;
            src = scan.nextInt();
            dest = scan.nextInt();
            graph.addEdge(src, dest);
        }
        scan.close();
        int start = 0;
        new DFS(graph, start);
    }
}
