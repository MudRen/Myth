// pao.c
#include <ansi.h>
inherit EQUIP;

void create()
{
        set_name(HIC"��ħ��"NOR, ({"xiangmo pao", "pao", "cloth"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("armor_type", "cloth");
      set("armor_prop/armor", 10);
      set("armor_prop/spells", 10);
   set("armor_prop/dodge", 10);
             }
}
