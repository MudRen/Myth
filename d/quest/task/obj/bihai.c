//By waiwai@mszj 2000/12/02

inherit ITEM;
#include <ansi.h>
#include <task.h>

void create()
{
        set_name(HIG"�̺���"NOR, ({"aoguang seafork","seafork"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�ѵ�����ʥר�õ�������\n");
                set("unit", "��");
               set("owner_name","����");
               set("owner_id","ao guang");
        }
}

