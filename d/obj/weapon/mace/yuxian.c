
//Junhyun BY 2002.05.16
#include <weapon.h>
#include <ansi.h>

inherit MACE;

void create()
{
  set_name(YEL "����" NOR, ({"yu xian", "mace"}));
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("value", 18000);
    set("material", "steel");
    set("long", "�����������õ����ߣ���ô��������ͨ��ϸ��ûʲô����\n");
    set("wield_msg", "$N����˶���ȡ��$n����������˦��˦���ƺ��ǳ�˳�֡�\n");
    set("unwield_msg", "$N�����е�$n���˾�����Լ��Ļ��У���ϧ�ޱȡ�\n");
  }
  
  init_mace(95);
  setup();
}

