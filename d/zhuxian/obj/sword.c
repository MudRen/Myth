// changjian.c ����

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
    set_name(HIW "���˽�" NOR, ({"sword", "jian"}));
    set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        set("long", "����һ���������ĳ�����\n");
        set("value", 1);
                set("material", "purplegold");
                set("sheenness", 35);
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
        }
    init_sword(125);
        setup();
}

