struct ListNode {
    int         val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *ha, struct ListNode *hb)
{
    int lena, lenb, diff;
    int i;
    struct ListNode *cura, *curb;
    if (!ha || !hb)
        return NULL;
    
    lena = 0;
    cura = ha;
    while (cura)
    {
        lena++;
        cura = cura->next;
    } 

    lenb = 0;
    curb = hb;
    while (curb)
    {
        lenb++;
        curb = curb->next;
    }
    //cura指向比较长的那个链表 
    //curb指向比较短的那个链表
    if (lena > lenb)
    {
        cura = ha;
        curb = hb;
        diff = lena - lenb;
    }
    else
    {
        cura = hb;
        curb = ha;
        diff = lenb - lena;
    }

    for (i = 0; i < diff; i++)
        cura = cura->next;

    lena = (lena < lenb) ? lena : lenb;
    for (i = 0; i < lena; i++)
    {
        if (cura == curb)
            break;
        cura = cura->next;
        curb = curb->next;
    }
    if (i == lena)
        return NULL;
    return cura;
}
