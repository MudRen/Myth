// ������� by Calvin

#include <armor.h>
#include <ansi.h>

inherit ARMOR;

void create()
{
        set_name(HIW"�ۼ�"NOR, ({"dun armor","dunjia", "armor"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ������,������ô�����˸о�������ô��׾��\n");
                set("material", "steel");
set("value", 20000);
                set("no_sell", "���ֺ�����װ���ɲ���������������!\n");
                set("armor_prop/armor", 90);
               set("armor_prop/dodge", -20);
                set("no_get", 1);
                set("no_give", 1);
                set("no_put", 1);
                set("no_drop", 1);
                set("armor_prop/force", 100);
        }
        setup();
}
