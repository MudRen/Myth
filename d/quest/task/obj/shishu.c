//By waiwai@mszj 2000/12/02

#include <ansi.h>

inherit ITEM;
#include <task.h>

void create()
{
        set_name(CYN"ʹ��"NOR, ({"shi shu"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ������ʹ�����������š�\n");
                set("unit", "��");
                 set("owner_name","��ʹ");
               set("owner_id","da shi");
        }
}

