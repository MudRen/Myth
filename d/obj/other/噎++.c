#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("������", ({"puti cloth", "cloth"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","һ��˿����ۣ��ʵغͲü�������\n");
                set("material", "cloth");
                set("unit", "��");
                set("value", 2000);
                set("armor_prop/armor", 4);
                set("armor_prop/personality", 1);
        }
        setup();
}
