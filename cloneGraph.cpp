//使用深度优先搜索
void creatNode(UndirectedGraphNode *oldGra, UndirectedGraphNode *newGra,
                map<int, UndirectedGraphNode*> &existNode)
{
    int i;
    for (i = 0; i < (oldGra->neighbors).size(); i++)
    {
        if (existNode.count((oldGra->neighbors[i])->label) == 0)
        {
            UndirectedGraphNode *nextNode = new UndirectedGraphNode((oldGra->neighbors[i])->label);
            (newGra->neighbors).push_back(nextNode);
            existNode[nextNode->label] = nextNode;
            creatNode(oldGra->neighbors[i], nextNode, existNode);
        }
        else
        {
            (newGra->neighbors).push_back(existNode[(oldGra->neighbors[i])->label]);
        }
    }
    return;
}

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
{
    if (node == NULL)
        return NULL;
    UndirectedGraphNode *ret;
    map<int, UndirectedGraphNode*> existNode;
    ret = new UndirectedGraphNode(node->label);
    existNode[node->label] = ret;
    creatNode(node, ret, existNode);
    return ret;
}
