// ������˹ by Calvin

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIG "������˹" NOR, ({ "ake xiusi", "xiusi","ake" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ������Ů�Դ��������\n");
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 1);
                set("armor_prop/personality", 3);
                set("female_only", 1);
        }
        setup();
}


