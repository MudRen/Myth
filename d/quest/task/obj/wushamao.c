//By waiwai@mszj 2000/12/02

#include <ansi.h>

inherit ITEM;
#include <task.h>
void create()
{
        set_name("��ɴñ", ({"wusha mao", "mao"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�������ñ�ӡ�\n");
                set("unit", "��");
               set("owner_name","����");
               set("owner_id","fu ling");
        }
}

