//By waiwai@mszj 2000/12/02

inherit ITEM;
#include <ansi.h>
#include <task.h>
void create()
{
        set_name(HIR "��ħ��" NOR, ({"fumodao", "fumo"}));
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�ѽ�����ħ�ı�����\n");
                set("unit", "��");
                 set("owner_name","����");
               set("owner_id","gong bing");
        }
}


