// �����庮�� by Calvin

#include <ansi.h>
#include <weapon.h>

inherit FORK;

void create()
{
        set_name(HIC"���ɲ�"NOR, ({ "yixian cha", "yixian fork","fork","cha" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 200000);
                set("no_sell", "���ֺ���������ɲ���������������!\n");
                set("material", "iron");
                set("long", "����һ����������������������\n");
                set("no_get", 1);
                set("no_give", 1);
                set("no_put", 1);
                set("no_drop", 1);
                set("wield_msg", "$N����һ��$n�������·����˲���⡣\n");
        }
 init_fork(200);
        setup();
}

