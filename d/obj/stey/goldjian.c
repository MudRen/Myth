// silverjian.c
// created 5-30-97 pickle

#include <weapon.h>
#include <ansi.h>

inherit MACE;

void create()
{
  set_name(HIW "��װ�" NOR, ({"gold mace", "mace", "goldmace", "jinjian", "jian"}));
  set_weight(8000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("value", 100000);
    set("material", "silver");
    set("long", "һ����������Ľ���ﵣ���Ȼ�Ǳ��˲����ֲ���\n");
    set("wield_msg", "ֻ��һ�����������$N�����Ѿ�����һ��$n��\n");
    set("unwield_msg", "$N������$n�����ܹ�âΪ֮һ����\n");
  }
  
  init_mace(115);
  setup();
}

