//By waiwai@mszj 2000/12/02

inherit ITEM;

#include <ansi.h>
#include <task.h>

void create()
{
        set_name("����", ({"tie shan"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�Ѵ����ȣ��������\n");
                set("unit", "��");
              set("owner_name","���ȹ���");
               set("owner_id","tieshan gongzhu");
        }
}

