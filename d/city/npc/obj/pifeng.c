// by snowcat oct 15 1997
#include <armor.h>

inherit SURCOAT;

void create()
{
  set_name("��Ƥ����", ({"shoupi pifeng", "pifeng", "cloth"}));
  set_weight(4500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "һ����Ƥ���硣\n");
    set("material", "leather");
    set("unit", "��");
    set("value", 700);
    set("armor_prop/armor", 35);
	set("no_sell",1);
				set("no_drop","ȥ�����Ѷ��ɣ����ӻ���Ⱦ����!\n");
				set("no_give","�ܹܷ���װ�����ɲ���������Ӵ��\n");
				set("no_get","�����ܹ�һҶ֪�﷢��װ�������ΰ�!\n");
  }
  setup();
}


