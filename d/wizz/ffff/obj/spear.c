// ��ӧǹ by ffff
#include <weapon.h>
#include <ansi.h>

inherit SPEAR;

void create()
{
  set_name(HIY"��ӧǹ" NOR, ({ "huying spear","qiang","spear" }));
  set_weight(10);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("value", 1000);
    set("material", "gold");
    set("long", HIR"�Կ��Ϻ�ӧ���⹳˪ѩ���������հ�����������ǡ�
    ʮ��ɱһ�ˣ�ǧ�ﲻ���С����˷���ȥ�������������\n"NOR);
    set("wield_msg", "$N����һ��$n��˳�ֶ��˸�ǹ��,�����ض�Ϊ֮��ҡ��\n");
  }
  init_spear(500);
  setup();
}

