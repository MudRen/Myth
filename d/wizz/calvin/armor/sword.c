// ��ԯ��.c

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(MAG"��ԯ��"NOR, ({ "xuanyuan sword", "jian", "sword" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 100000);
               set("no_sell", "��?����,���ֺ����Ķ�������������!\n");
                set("material", "steel");
                set("long", "����һ������Ψһ���Ͻ𱦽�������͸��,�����ޱȡ�\n");
                set("wield_msg", "һ���Ϲ�������$N�����Ѷ��˰�$n��\n");
                set("unequip_msg", "$N�������е�$n��\n");
        }
        init_sword(200);
        setup();
}
