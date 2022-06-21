#include <iostream>
using namespace std;

#define LIST_INIT_LEN 10

class List
{
private:
    int *nums;
    int curLen;
    int size;

public:
    List();
    ~List();

    void ClearList();                             //清空
    bool ListEmpty();                             //判断是否为空
    int ListLength();                             //返回长度
    bool GetItem(int i, int *);                   //得到第i个元素的值
    bool LocateElem();                            //
    bool PriorElem(int cur_e, int *pre_e);        //返回e的前驱元素
    bool NextElem(int cur_e, int *next_e);        //返回e的后继元素
    bool ListInsert(int i, int e);                //在第i个位置插入元素e
    bool ListDelete(int i, int *e);               //删除并返回第i个元素
    void ListTraverse(void (*visit)(int *, int)); //遍历线性表，对元素依次执行visit函数
};

List::List()
{
    this->nums = new int[LIST_INIT_LEN];
    if (this->nums == nullptr)
    {
        cout << "初始化失败" << endl;
    }
    this->curLen = 0;
    this->size = LIST_INIT_LEN;
}

List::~List()
{
    if (this->nums != nullptr)
    {
        delete (this->nums);
    }
    this->nums = nullptr;
    this->curLen = 0;
}

void List::ClearList()
{
    this->curLen = 0;
}

bool List::ListEmpty()
{
    return this->curLen == 0;
}

int List::ListLength()
{
    return this->curLen;
}

bool List::GetItem(int i, int *e)
{
    if (i < 1 || i > this->curLen + 1)
    {
        return false;
    }
    *e = this->nums[i - 1];
    return true;
}

bool List::PriorElem(int cur_e, int *pre_e)
{
    int index = -1;
    int left = 0;
    int right = this->curLen - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (cur_e == this->nums[mid])
        {
            index = mid;
        }
        else if (cur_e > this->nums[mid])
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    if (index == -1)
    {
        cout << "当前元素不存在" << endl;
        return false;
    }
    if (index == 0)
    {
        cout << "该元素无前驱元素" << endl;
        return false;
    }

    *pre_e = this->nums[index - 1];
    return true;
}

bool List::ListInsert(int i, int e)
{
    if (i < 1 || this->curLen > this->size - 1)
    {
        cout << "插入位置不合法" << endl;
        return false;
    }
    for (int j = this->curLen; j > i - 1; j--)
    {
        this->nums[j] = this->nums[j - 1];
    }
    this->nums[i - 1] = e;
    this->curLen++;
    return true;
}

bool List::ListDelete(int i, int *e)
{
    if (i < 1 || i > this->curLen)
    {
        cout << "删除位置不合法" << endl;
        return false;
    }
    *e = this->nums[i - 1];
    for (int j = i - 1; j < this->curLen - 1; j++)
    {
        this->nums[j] = this->nums[j + 1];
    }
    this->curLen--;
    return true;
}

void List::ListTraverse(void (*visit)(int *, int))
{
    visit(this->nums, this->curLen);
}
void visit(int *nums, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}