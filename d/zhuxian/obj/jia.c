// lightarmor.c
#include <ansi.h>
#include <armor.h>

inherit ARMOR;

void create()
{
        set_name(HIW "��̼����" NOR, ({"hu jia","jia","armor"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        set("long", "�߿Ƽ���Ʒ��\n");
                set("value", 1);
                set("material", "???");
                set("armor_prop/armor", 50);
                set("armor_prop/armor_vs_force", 50);
             }
			 setup();
}
