#include <iostream>
#include "List.h"
using namespace std;

int main()
{
    List *L = new List();
    if (L->ListEmpty())
    {
        cout << "当前线性表为空\n";
    }
    for (int i = 1; i <= 5; i++)
    {
        L->ListInsert(i, i);
    }
    L->ListTraverse(visit);
    cout << "当前元素个数：" << L->ListLength() << endl;

    L->ListInsert(3, 10000);
    L->ListTraverse(visit);
    cout << "当前元素个数：" << L->ListLength() << endl;

    int e;
    L->ListDelete(3, &e);
    L->ListTraverse(visit);
    cout << "当前元素个数：" << L->ListLength() << endl;

    delete (L);
    return 0;
}