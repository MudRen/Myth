// tiejia.c ����
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("�����Ӽ�", ({"jin jia", "jia", "armor"}));
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", "һ������֯�͵ı��ף�\n");
                set("material", "steel");
                set("value", 10000);
                set("armor_prop/armor", 50);
        }
        setup();
}


