//malemace.c
//created 5-30-97 pickle
//please do not use, this weapon reserved for /d/jjf/npc/yuchigong.c

#include <weapon.h>
#include <ansi.h>

inherit MACE;
inherit F_UNIQUE;

void create()
{
  set_name(YEL "��β��" NOR, ({"tiger mace", "mace", "tigermace", "tiger"}));
  set_weight(10000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("value", 18000);
    set("material", "steel");
    set("long", "����һ���������ɵĻ�β�ޣ���˵��һ�Դ���˫���е��۱ޡ�\n");
    set("wield_msg", "$N�Ӽ���ȡ��һ�����������˿��������о�Ȼ��$n��\n");
    set("unwield_msg", "$N���𲼴����˲�$n���ְ���С������ذ���������\n");
	set("replace_file", "/d/obj/weapon/mace/ironmace");
  }
  
  init_mace(85);
  setup();
}

