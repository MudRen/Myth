// jinqiang.c


#include <weapon.h>
#include <ansi.h>

inherit SPEAR;
#include "/std/weapon/newwwd.c"; 

void create()
{
  set_weight(14000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("value", 100000);
    set("material", "gold");
    set("long", "ǹ�����΢΢�׵�����⣬��������֮֨֨����\n");
    set("wield_msg", "$N����һ��$n��˳�ֶ��˸�ǹ����\n");
				set("no_sell",1);
				set("no_drop","ȥ�����Ѷ��ɣ����ӻ���Ⱦ����!\n");
  }
        init_spear(105);
       updatename("spear"); 
  setup();
}

