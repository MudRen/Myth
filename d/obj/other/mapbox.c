#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIG"��ͼ��"NOR, ({ "map box", "map_box","box" }) );
        set_weight(5000);
        set_max_encumbrance(50);
        if( clonep() ) {
                object a,b;
                  seteuid(getuid());
                 if(a=new("/d/obj/misc/xueshan-map"))
                  a->move(this_object());
             if(b=new("/d/penglai/npc/obj/ditu"))
                  b->move(this_object());

                set_default_object(__FILE__);
        } else {
                set("unit", "ֻ");
                set("long", "����һֻר������װ��ͼ�ı���,�����(get map from box)������õ���ͼ��\n");
                set("value", 10000);
                set("no_sell", 1);
        }
}
