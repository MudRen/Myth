#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIW"ˮ����"NOR, ({ "huo lingzhu" }));
        set_weight(20000);
        set("long", "����һ�ű��顣\n" );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "stone");
                set("value", 2000);
                set("no_get", 1);
                set("amount",30);
        }
        setup();
}
