// tianyaojia.c ����ս��

#include <ansi.h>
#include <armor.h>

inherit ARMOR;

void create()
{
        set_name(RED"����ս��"NOR, ({"tianyao armor","zhanjia", "jia", "armor"}));
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", "��������ս�ף���������Ϊ���á�\n");
                set("material", "gold");
                set("value", 10000);
                set("armor_prop/armor", 70);
		set("armor_prop/dodge", 15);
        }
        setup();
}


