//By waiwai@mszj 2000/12/02

inherit ITEM;

#include <ansi.h>
#include <task.h>

void create()
{
        set_name(HIC"����������"NOR, ({"aoguang ring","ring"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��������ǳ���һ�����ӡ�\n");
                set("unit", "��");
               set("owner_name","����");
               set("owner_id","ao guang");
        }
}

