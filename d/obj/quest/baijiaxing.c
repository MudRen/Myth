//Cracked by Roath
// literate.c

inherit ITEM;
#include <task.h>

void create()
{
        set_name("���ټ��ա�", ({"baijiaxing", "book"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 100);
        set("long",
"һ��������С���ӣ�\n��Ǯ������������\n��������\n");
        set("material", "paper");
        set("owner_name", "������");
          set("owner_id", "kuang wenzheng");
                }
}

