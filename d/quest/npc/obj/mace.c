//ironmace.c
//created 5-30-97 pickle

#include <weapon.h>
#include <ansi.h>

inherit MACE;

void create()
{
  set_name(YEL"��ħ�"NOR, ({"chumo mace", "mace"}));
  set_weight(6000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("value", 0);
    set("no_put",1);
    set("no_zm",1);
    set("no_give",1);
    set("material", "iron");
    set("long", CYN"�Ϲ�ʮ�����֮һ����ħ�\n"NOR);
    set("wield_msg", "$N����һ��$n��һ��"+MAG"����"NOR+"������$N��������\n");
    set("unwield_msg", "$N��$n�������,��Χ��"+MAG"����"NOR+"��������������\n");
  }
  
        init_mace(85+random(20));
  setup();
}

