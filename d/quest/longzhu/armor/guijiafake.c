// ������� by Calvin

#include <ansi.h>
#include <armor.h>

inherit ARMOR;

void create()
{
        set_name(HIW"��������"NOR, ({"guixian shenkai","shenkai","jia", "guixian", "armor"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�����Թ��ɵ�������,���ú��ױ����Ƴɵġ�\n");
                set("material", "steel");
                set("no_give", 1);
                set("no_drop", 1);
                set("no_put", 1);
                set("value", 10000);
               set("fake", 1);
                set("armor_prop/armor", 50);
                set("armor_prop/dodge", -50);
                set("armor_prop/parry", -50);
                set("armor_prop/force", 50);
                set("armor_prop/spells", 50);
        }
        setup();
}
