//�����
//ivy

#include <weapon.h>
#include <ansi.h>

inherit MACE;

void create()
{
  set_name("�����", ({"killgod mace", "mace"}));
  set_weight(8000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("value", 18000);
    set("material", "iron");
    set("long", "�������Ĵ���ޣ���˵�����ϴ������´�Ⱥ��\n");
    set("wield_msg", "$N���˸��䣬$n���Ƶķ����˰�գ�\n");
    set("unwield_msg", "$N�������˸�����$n�ɻ�$N�����䡣\n");
  }
  
  init_mace(100);
  setup();
}

