// ��Ҷ�� by Calvin

#include <ansi.h>
#include <armor.h>

inherit ARMOR;

void create()
{
        set_name(HIG"��Ҷ��"NOR, ({"xinye jia","jia", "xinye", "armor"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����Ҷ����Ҷ����������,�Ǵ�˵����Ҷͯ�ӵı��\n");
                set("material", "steel");
                set("value", 0);
  set("fake", 1);
                set("armor_prop/armor", 80);
                set("armor_prop/dodge", 60);
                set("armor_prop/parry", 50);
                set("armor_prop/force", 40);
                set("armor_prop/spells", 40);
        }
        setup();
}
