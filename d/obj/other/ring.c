// goldring.c �����ָ

#include <armor.h>

inherit FINGER;

void create()
{
        set_name("�����ָ", ({ "tianjue jiezhi", "jiezhi", "ring" }));
        set("weight", 400);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 5000);
                set("material", "gold");
                set("armor_prop/armor", 15);
        }
        setup();
}       
