//��������
//by junhyun@SK

#include <armor.h>
#include <ansi.h>

inherit SURCOAT;
inherit F_UNIQUE;

void create()
{
        set_name(HIW"����"HIC"����"NOR, ({"nishang yuyi", "cloth", "yuyi" }) );
        set("long", "һ�����߲���ϼ�ر�֯�͵����£������������\n");
        set_weight(0);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("unique", 1);
                set("armor_prop/armor", 140);
                set("armor_prop/dodge", 50);
                set("armor_prop/personality", 10);
                set("value", 50000);
                set("female_only", 1);

        }
        setup();
}

