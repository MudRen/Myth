#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIG"�̵�ƿ"NOR, ({ "lvdan ping", "ping" }) );
        set_weight(5000);
        set_max_encumbrance(50);
        if( clonep() ) {
                object a;
                  seteuid(getuid());
                if(a=new("/d/sea/obj/cool_dan"))
                  a->move(this_object());

                set_default_object(__FILE__);
        } else {
                set("unit", "��");
                set("long", "һ����ɫ��С��ƿ�������������صġ�\n");
                set("value", 4000);
		set("no_sell", 1);
        }
}

int is_container() { return 1; }

