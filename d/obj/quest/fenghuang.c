//By waiwai@mszj 2000/12/02

#include <ansi.h>

inherit ITEM;
#include <task.h>
void create()
{
        set_name(HIY"�����"NOR, ({"fenghuang sword", "fenghuang"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�����̳ɵķ���١�\n");
                set("unit", "��");
                set("owner_name","��ȸ����");
                set("owner_id","kongque gongzhu");
        }
}

