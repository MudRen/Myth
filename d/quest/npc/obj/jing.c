#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
        set_name(HIM"����"NOR, ({ "jin" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", "һ���ۺ��˿��������������\n");
                set("value", 0);
                set("no_zm",1);
                set("no_give",1);
                set("no_put",1);
                set("material", "cloth");
                set("armor_prop/armor", 30);
	    }
        setup();
}

