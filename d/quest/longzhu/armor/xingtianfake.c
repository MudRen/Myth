// ����ս�� by Calvin

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIY"����ս��"NOR, ({"xingtian zhanyi","zhanyi","xingtian","yi","cloth"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
  set("fake", 1);
                set("no_give", 1);
                set("no_drop", 1);
                set("no_put", 1);
                
                set("unit", "��");
                set("armor_prop/armor", 30);
                set("spells", 30);
        }
        setup();
}
