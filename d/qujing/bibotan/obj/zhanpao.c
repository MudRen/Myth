#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("����ս��", ({ "zhanpao" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "һ��˿֯���ۡ�\n");
                set("material", "cloth");
                set("unit", "��");
                set("armor_prop/armor", 20);
		set("armor_prop/dodge", 10);
		set("armor_prop/personality", 3);
                set("armor_prop/spirituality", 3);
        }
        setup();
}

