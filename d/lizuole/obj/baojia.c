
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIY "��˿����" NOR, ({ "bao jia", "jia" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "\n����������Ϊѩ����������˿���ס�\n");
                set("unit", "��");
		set("no_drop","��������/�����˵ģ�Ҳ���ܸ����ˡ�");
                set("value", 5000);
                set("no_sell", "���������������\n");
                set("material", "gold");
                set("armor_prop/armor", 50);
        }
        setup();
}

