//By waiwai@mszj 2000/12/02

#include <ansi.h>
inherit ITEM;
#include <task.h>
void create()
{
        set_name(HIC"�滮ͼ"NOR, ({"guihua tu"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ���һ���Ĺ滮ͼ��\n");
                set("unit", "��");
                set("owner_name","����");
                set("owner_id","wu wen");
        }
}

