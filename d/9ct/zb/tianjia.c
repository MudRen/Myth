
#include <armor.h>
#include <ansi.h>

inherit ARMOR;

void create()
{
        set_name(CYN"��ľ��"NOR, ({"heimu armor","hei jia", "jia", "armor"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "ľ���ӵ�һ������,�˼�ͨ���ںڡ�\n");
                set("material", "steel");
              set("value", 12000); 
                set("armor_prop/armor", 80);
                set("armor_prop/dodge", -30);
                set("armor_prop/force", 40);
        }
        setup();
}
