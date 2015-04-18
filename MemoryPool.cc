// 简单内存池的实现，Node是一个自定义的结构体，在node数组中存储真正的Node结构，而queue中
// 存储的是对应的内存地址。当初始化时，将node数组所有的地址都push到queue中，当不使用时候将
// 这个指向Node的指针重新加入free队列。
queue<Node *> freenodes;
Node node[maxn];


void init()
{
	for (int i = 0; i < maxn; ++i)
	{
		freenodes.push(&node[i]);
	}
}

Node *newnode()
{
	Node *u = freenodes.front();
	// 接下来做u的初始化
	freenodes.pop();
	return u;
}

void deletenode(Node *u)
{
	freenodes.push(u);
}