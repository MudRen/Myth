// ������� by Calvin

#include <ansi.h>
#include <armor.h>

inherit F_UNIQUE;
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
                set("is_monitored", 1);
                set("no_drop", 1);
set("replace_file", "/d/quest/longzhu/armor/guijiafake.c"); 
  set("unique", 1);
                set("no_put", 1);
                set("name_recognized", "��������");
                set("value", 10000);
                set("armor_prop/armor", 120);
                set("armor_prop/dodge", -60);
                set("armor_prop/parry", -60);
                set("armor_prop/force", 200);
                set("armor_prop/spells", 200);
        }
        setup();
}

