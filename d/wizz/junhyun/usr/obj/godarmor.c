//sea.c playerװ��
//by junhyun@SK

#include <armor.h>
#include <ansi.h>

inherit ARMOR;


void create()
{
        set_name(HIW"��֮��"NOR, ({ "godarmor", "armor" }) );
        set("long", "ɢ������֮��Ե����ס�\n");
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 20);
                set("armor_prop/spells", 50);
                set("armor_prop/dodge", 20);
                set("value", 50000);
        }
        setup();
}

