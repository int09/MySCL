// ���ڴ�ص�ʵ�֣�Node��һ���Զ���Ľṹ�壬��node�����д洢������Node�ṹ����queue��
// �洢���Ƕ�Ӧ���ڴ��ַ������ʼ��ʱ����node�������еĵ�ַ��push��queue�У�����ʹ��ʱ��
// ���ָ��Node��ָ�����¼���free���С�
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
	// ��������u�ĳ�ʼ��
	freenodes.pop();
	return u;
}

void deletenode(Node *u)
{
	freenodes.push(u);
}