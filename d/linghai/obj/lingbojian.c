//by dewbaby@sk_sjsh
//lingbojian.c

#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;

inherit SWORD;

void create()
{
    set_name(HIG"�貨��"NOR,({"lingbo jian","lingbo","jian"}));
    set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","��");
                set("value",120000);
                set("no_drop","1");
                set("material","gold");
                set("long",HIG"��˵�����貨���ӵ��񽣣���������˸�ű��̵Ĺ�â��\n"NOR);
                set("wield_msg",HIG"ʱ�����󣬻��ݵ��㣬$N�ѽ�$n�������У�������һ����\n"NOR);
                set("unwield_msg",HIG"$N˫��΢�գ�գ�ۼ��ѽ�$n������䡣��ֻ�����������\n");
                      set("no_drop","1");
                      set("no_sell","1");         
     }
    init_sword(130);
    setup();
}


