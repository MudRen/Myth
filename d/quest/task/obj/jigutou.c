//By waiwai@mszj 2000/12/02

#include <ansi.h>

inherit ITEM;
#include <task.h>

void create()
{
        set_name(HIC"����ͷ"NOR, ({"ji gutou"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�еþ���ļ���ͷ��\n");
                set("unit", "��");
                set("owner_name","����ͷ");
                set("owner_id","lao tou");
        }
}

