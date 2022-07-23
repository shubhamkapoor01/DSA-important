class Solution {
    final int DRAW = 0, MOUSE_WIN = 1, CAT_WIN = 2, MOUSE_TURN = 1, CAT_TURN = 2;
    
    public int catMouseGame(int[][] graph) {
        int N = graph.length;

        //status[node] : who wins in the end if we start from this node
        int[][][] status = new int[50][50][3]; // status[mouse_location][cat_location][turn]
        
        //children_num[node] : the number of neutral children of this node
        int[][][] children_num = new int[50][50][3];// children_num[mouse_location][cat_location][turn]

        for (int m = 0; m < N; ++m)//mouse location
        {
            for (int c = 0; c < N; ++c)//cat location
            {
                children_num[m][c][MOUSE_TURN] = graph[m].length;
                children_num[m][c][CAT_TURN] = graph[c].length;
                for (int x: graph[c]) 
                {
                    if (x == 0) //The cat can not stay at the hole (position 0).
                    {
                        children_num[m][c][CAT_TURN]--;
                        break;
                    }
                }
            }
        }

        // enqueued : all nodes that we know who wins in the end. Nodes with DRAW status is not in this queue.
        Queue<int[]> queue = new LinkedList();
        for (int i = 0; i < N; ++i)
        {
            for (int t = 1; t <= 2; ++t) //turn
            {
                status[0][i][t] = MOUSE_WIN; //The mouse wins if it is at the hole (position 0).
                queue.add(new int[]{0, i, t, MOUSE_WIN});
                if (i > 0) 
                {
                    status[i][i][t] = CAT_WIN; //The cat wins if mouse and cat are at the same location.
                    queue.add(new int[]{i, i, t, CAT_WIN});
                }
            }
        }

        // percolate nodes that we know who wins in the end
        while (!queue.isEmpty()) 
        {
            int[] node = queue.remove();
            int m = node[0], c = node[1], t = node[2], s = node[3]; //mouse_location, cat_location, turn, status          
            for (int[] parent: parents(graph, m, c, t))  // for every parent of this node (m, c, t) :
            {
                int m2 = parent[0], c2 = parent[1], t2 = parent[2]; //mouse_location2, cat_location2, turn2                
                if (status[m2][c2][t2] == DRAW) // if we do not know who wins in this parent node
                { 
                    if (t2==MOUSE_TURN && s==MOUSE_WIN || t2==CAT_TURN && s==CAT_WIN) 
                    {
                        // if the parent can make a winning move (mouse to MOUSE_WIN, or cat to CAT_WIN)
                        status[m2][c2][t2] = s;
                        queue.add(new int[]{m2, c2, t2, s});
                    } else 
                    {
                        // else, this parent has neutral children_num[parent]--. 
                        // Enqueue if all children of this parent are colored as losing moves.
                        children_num[m2][c2][t2]--;
                        if (children_num[m2][c2][t2] == 0) 
                        {
                            status[m2][c2][t2] = t2==MOUSE_TURN ? CAT_WIN : MOUSE_WIN;
                            queue.add(new int[]{m2, c2, t2, status[m2][c2][t2]});
                        }
                    }
                }
            }
        }

        return status[1][2][MOUSE_TURN];//The mouse is at location 1. The cat is at location 2. The mouse moves first.
    }

    // What nodes could play their turn to arrive at node (m, c, t) ?
    public List<int[]> parents(int[][] graph, int m, int c, int t) {
        List<int[]> ans = new ArrayList();
        if (t == CAT_TURN) 
        {
            for (int m2: graph[m])
            {
                ans.add(new int[]{m2, c, MOUSE_TURN});
            }
        } else 
        {
            for (int c2: graph[c]) 
            {
                if (c2 > 0) //The cat can not stay at the hole (position 0).
                {
                    ans.add(new int[]{m, c2, CAT_TURN});
                }
            }
        }
        return ans;
    }
}