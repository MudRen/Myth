// ��ڤ�� by Calvin

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIR"��ڤ"+HIW"��"NOR, ({ "guming sword", "guming", "sword","shenjian" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 200000);
                set("no_sell", "���ֺ���������ɲ���������������!\n");
                set("material", "steel");
                set("no_get", 1);
                set("no_give", 1);
                set("no_put", 1);
                set("no_drop", 1);
                set("long", "����һ�����Ծ����������,�����ں�,�����ޱȡ�\n");
                set("wield_msg", "һ���׹�������$N�����Ѷ��˰�$n��\n");
                set("unequip_msg", "$N�������е�$n��\n");
        }
 init_sword(200);
        setup();
}
