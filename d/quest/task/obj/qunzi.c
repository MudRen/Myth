//By waiwai@mszj 2000/12/02

inherit ITEM;

#include <ansi.h>
#include <task.h>

void create()
{
        set_name("��ȹ��", ({"hua qunzi", "qunzi"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ����Ư����ȹ�ӡ�\n");
                set("unit", "��");
                set("owner_name","÷ԧ��");
                set("owner_id","mei yuanyan");
        }
}

