// 并查集是一种用来管理元素分组情况的数据结构。并查集可以搞笑地进行如下操作。
// 不过需要注意并查集虽然可以进行合并操作，但是无法进行分割操作。
// *查询元素a和元素b是否属于同一组。
// *合并元素a和元素b所在的组。

// 并查集也是使用树形结构实现的。不过不是二叉树。每个元素对应一个节点，每个组
// 对应一个树。在并查集中，哪个节点是哪个节点的父亲以及树的形状等信息无需多加
// 关注，整体组成一个树形结构才是重要的。

// (1)初始化：	准备n个节点来表示n个元素，最开始没有边。
// (2)合并：		从一个组的根向另一个组的根连边，这样两棵树就变成了一棵树，也就
//					把两个组合并为一个组了。
// (3)查询：		为了查询两个节点是否属于同一组，需要沿着树向上走，来查询包含这
//					个元素的书的根是谁，如果两个节点有同一根，则属于同一组。

// ======================================================

int par[MAX_N];				// 父亲
int rank[MAX_N];				// 树的高度

// 初始化n个元素
void init(int n) 
{
	for (int i = 0; i < n; i++) 
	{
		par[i] = i;
		rank[i] = 0;
	}
}

// 查询树的根
int find(int x)
{
	if (par[x] == x)
		return x;
	else
		return par[x] = find(par[x]);
}

// 合并x和y所属的集合
void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)	return;

	if (rank[x] < rank[y]) {
		par[x] = y;
	}
	else {
		par[y] = x;
		if (rank[x] == rank[y])
			rank[x]++;
	}
}

// 判断x和y是否属于同一个集合
bool same(int x, int y)
{
	return find(x) == find(y);
}