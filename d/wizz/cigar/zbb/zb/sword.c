// ��ڤ�� by Calvin

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIW"��ڤ��"NOR, ({ "guming sword", "guming", "sword","shenjian" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
             set("value", 0);
                set("material", "steel");
                set("long", "����һ�����Ծ����������,�����ں�,�����ޱȡ�\n");
                set("wield_msg", "һ���׹�������$N�����Ѷ��˰�$n��\n");
                set("unequip_msg", "$N�������е�$n��\n");
        }
   init_sword(120);
        setup();
}
