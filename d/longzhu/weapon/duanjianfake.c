// �ν� by Calvin

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name(HIB"�Ͻ�"NOR, ({ "duan sword", "jian", "sword" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 10000);
               set("no_sell", "��?����,���ֺ����Ķ�������������!\n");
                set("material", "steel");
                set("long", "����һ��ֻ��һ�뽣��ĶϽ���\n");
                set("wield_msg", "һ�����������$N�����Ѷ��˰�$n��\n");
                set("unequip_msg", "$N�������е�$n��\n");
        }
        init_sword(110);
        setup();
}
