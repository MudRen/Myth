#include <weapon.h>

inherit SWORD;

void create()
{
  set_name("����", ({"tie shan", "tieshan", "shan", "iron fan", "fan"}));
  set_weight(34000);
  if (clonep())
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", "һ�Ѵ����ȣ��������\n");
    set("value", 30000);
    set("material", "iron");
    set("wield_msg","$N��ৡ��ش�$n�������У�����һ�ȡ�\n");
    set("unwield_msg","$N�����е�$n����˳�ֲ��˲�����\n");
    set("weapon_prop/int", 2);
  }
  set("no_get", "���ȴ���������ڵ��ϣ����ò�������\n");
  set("no_drop", "ֻ��৵�һ�����������Զ��طɻ������ϡ�\n");
  set("no_give", "ֻ��৵�һ�����������Զ��طɻ������ϡ�\n");
  set("no_sell", "ֻ��৵�һ�����������Զ��طɻ������ϡ�\n");
  set("is_monitored",1);
  init_sword(25);
  //changed from 100 to 25...weiqi,970927. though it's a fabao, 
  //not necessarily has high damage. actually, as a sword, should not.
  setup();
}

