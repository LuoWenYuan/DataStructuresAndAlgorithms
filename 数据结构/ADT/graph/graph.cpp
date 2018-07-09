/* 图的邻接矩阵表示法（C语言实现） */
#define  MaxVertexNum  100      /* 最大顶点数设为100 */
#define  INFINITY  65535     /* ∞设为双字节无符号整数的最大值65535*/
typedef  char  VertexType;      /* 顶点类型设为字符型 */
typedef  int  EdgeType;         /* 边的权值设为整型 */
enum GraphType { DG, UG, DN, UN };  
/* 有向图,无向图,有向网图,无向网图*/
  
typedef  struct {
    VertexType  Vertices[ MaxVertexNum ];  /* 顶点表 */
    EdgeType  Edges[ MaxVertexNum ][ MaxVertexNum ]; 
/* 邻接矩阵，即边表  */
    int  n, e;   /* 顶点数n和边数e */
    enum GraphType GType;   /* 图的类型分4种：UG、DG、UN、DN */
} MGraph;    /* MGragh是以邻接矩阵存储的图类型 */
  
void  CreateMGraph ( MGraph *G )
{  
    int  i, j, k, w;
    G-> GType = UN;    /* Undirected Network  无向网图  */
    printf( "请输入顶点数和边数(输入格式为:顶点数, 边数):\n" );
    scanf( "%d, %d",&(G->n), &(G->e) ); /* 输入顶点数和边数 */
    printf("请输入顶点信息(输入格式为:顶点号<CR>):\n");
    for ( i = 0; i < G->n; i++ ) 
       scanf( "%c",&(G-> Vertices[i]) ); /*  输入顶点信息，建立顶点表  */
    for ( i = 0; i < G->n; i++ )
       for ( j = 0; j < G->n; j++ )  
           G->Edges[i][j] = INFINITY; /* 初始化邻接矩阵 */
    printf( "请输入每条边对应的两个顶点的序号和权值，输入格式为:i, j, w:\n" );
    for ( k = 0; k < G->e; k++ ) {
       scanf("%d,%d,%d ",&i, &j, &w); /* 输入e条边上的权，建立邻接矩阵 */
       G->Edges[i][j] = w; 
       G->Edges[j][i] = w; /* 因为无向网图的邻接矩阵是对称的 */
    }
}


/* 图的邻接表表示法（C语言实现） */
#define  MaxVertexNum  100     /* 最大顶点数为100 */
enum GraphType { DG, UG, DN, UN }; 
/* 有向图,无向图,有向网图,无向网图*/
typedef  struct  node{   /* 边表结点 */
    int AdjV;            /* 邻接点域 */
    struct  node  *Next;  /* 指向下一个邻接点的指针域 */
    /* 若要表示边上的权值信息，则应增加一个数据域Weight */
} EdgeNode;
typedef  char  VertexType;   /* 顶点用字符表示 */
typedef  struct  Vnode{      /* 顶点表结点 */
    VertexType  Vertex;      /* 顶点域 */
    EdgeNode  *FirstEdge; /* 边表头指针 */
} VertexNode; 
typedef VertexNode AdjList[ MaxVertexNum ]; /* AdjList是邻接表类型 */
typedef  struct{  
    AdjList  adjlist;    /* 邻接表 */
    int  n, e;               /* 顶点数和边数 */
    enum GraphType GType;    /* 图的类型分4种：UG、DG、UN、DN */
} ALGraph;  /*ALGraph是以邻接表方式存储的图类型 */
  
void CreateALGraph( ALGraph *G )
{
    int i, j, k;
    EdgeNode *edge;
    G-> GType = DG;  /* Directed Graph  有向图  */
    printf( "请输入顶点数和边数(输入格式为:顶点数,边数)：\n" );
    scanf( "%d,%d", &(G->n), &(G->e) ); /* 读入顶点数和边数 */ 
    printf( "请输入顶点信息(输入格式为:顶点号<CR>)：\n" );
    for ( i=0; i < G->n; i++ ) {   /* 建立有n个顶点的顶点表 */
        scanf( " %c", &(G->adjlist[i].Vertex) );  /* 读入顶点信息 */
       G->adjlist[i].FirstEdge = NULL; /* 顶点的边表头指针设为空 */
    }
    printf( "请输入边的信息(输入格式为: i, j <CR>)：\n" );
    for ( k=0; k < G->e; k++ ){   /* 建立边表 */
       scanf( "\n%d,%d", &i, &j); /* 读入边<vi,vj>的顶点对应序号*/
       edge = (EdgeNode*)malloc(sizeof(EdgeNode)); /* 生成新边结点edge */
       edge->AdjV = j; /* 邻接点序号为j */
       edge->Next = G->adjlist[i].FirstEdge;
       /* 将新边表结点edge插入到顶点vi的边表头部 */
       G->adjlist[i].FirstEdge = edge;
       /* 若是无向图，还要生成一个结点，用来表示边< vj, vi>  */
    }
}
/* 邻接表存储的图 – DFS（C语言实现） */
/* Visited[]为全局变量，已经初始化为FALSE */
void  DFS( ALGraph *G,  int i )
{   /* 以Vi为出发点对邻接表存储的图G进行DFS搜索 */
    EdgeNode *W;
    printf( "visit vertex: %c\n", G->adjlist[i].Vertex );
    /* 相当于访问顶点Vi */
    Visited[i] = TRUE;   /* 标记Vi已访问 */
    for( W = G->adjlist[i].FirstEdge;  W;  W = W->Next ) 
       if ( !Visited[ W->AdjV ] )
           DFS( G, W->AdjV );
}
/* 邻接矩阵存储的图 – BFS（C语言实现） */
void  BFS ( MGraph G )
{   /* 按广度优先遍历图G。使用辅助队列Q和访问标志数组Visited */
    Queue  *Q;    
    VertexType  U, V, W;
    for ( U = 0; U < G.n; ++U )  
       Visited[U] = FALSE;
    Q = CreatQueue( MaxSize ); /* 创建空队列Q */
    for ( U = 0; U<G.n; ++U )
       if ( !Visited[U] ) { /* 若U尚未访问 */
           Visited[U] = TRUE; 
           printf( "visit vertex: %c\n", G.Vertices[U] );
           /* 相当于访问顶点U */
           AddQ (Q, U);    /* U入队列 */
           while ( ! IsEmptyQ(Q) ) {
              V = DeleteQ( Q );  /*  队头元素出队并置为V */
              for( W = FirstAdjV(G, V);  W;  W = NextAdjV(G, V, W) )
                  if ( !Visited[W] ) {
                     Visited[W] = TRUE;
                     printf( "visit vertex: %c\n", G.Vertices[W] );
                     /* 相当于访问顶点W */
                     AddQ (Q, W);
                  }
           } /* while结束*/
} /* 结束从U开始的BFS */
}
  
/* FirstAdjV(G, V)和NextAdjV(G, V, W)请自己练习实现。*/