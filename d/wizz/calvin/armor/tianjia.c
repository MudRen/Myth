// tianjia.c �������
#include <armor.h>
#include <ansi.h>

inherit ARMOR;

void create()
{
        set_name(HIW"�������"NOR, ({"sichong armor","tianjia", "jia", "armor"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "������������ר�õ�վ�ף�\n");
                set("material", "steel");
                set("value", 0);
                set("armor_prop/armor", 130);
                set("armor_prop/dodge", 20);
        }
        setup();
}
