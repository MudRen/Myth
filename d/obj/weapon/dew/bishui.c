  //��ˮ��
  //by dewbaby@sk


#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
    set_name(BLINK+HIG"��ˮ��"NOR,({"bishui jian","bishui","jian"}));
     set_weight(4000);
        if( clonep() )
                 set_default_object(__FILE__);
        else {
                set("unit","��");
                set("value",4000000);
                 set("no_drop","1");
                set("material","gold");
                set("long",HIG"��˵���Ǿ�����Ů���񽣣���������˸�ű��̵Ĺ�â��\n"NOR);
                set("wield_msg",HIG"ʱ�����󣬻��ݵ��㣬$N�ѽ�$n"HIG"�������У�������һ����\n"NOR);
                 set("unwield_msg",HIG"$N˫��΢�գ�գ�ۼ��ѽ�$n"HIG"������䡣��ֻ�����������\n"NOR);
                      set("no_drop","���ǲ�Ҫ���ɣ�С�ľ�����ŮҪ�����С����\n");
              }
    init_sword(2000);
     setup();
}
