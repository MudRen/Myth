// ������ǹ by Calvin

#include <weapon.h>
#include <ansi.h>

inherit SPEAR;

void create()
{
  set_name(HIW "������ǹ" NOR, ({ "gueixian spear","qiang","spear" }));
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("value", 1000);
    set("material", "gold");
    set("long", "��ǹ���ǹ��ɵ�����ר��,�Ǹ���ǹ��\n");
    set("wield_msg", "$N����һ��$n��˳�ֶ��˸�ǹ��,�����ض�Ϊ֮��ҡ��\n");
  }
  init_spear(120);
  setup();
}

