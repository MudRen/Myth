#include <armor.h>

inherit HEAD;

void create()
{
  set_name("����", ({ "tie kui", "tiekui", "kui" }) );
  set_weight(2200);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long","һ�����صĴ�������������һ�����\n");
    set("value", 1000);
    set("material", "cloth");
    set("armor_prop/armor", 10);
    set("armor_prop/personality", 1);
	set("no_sell",1);
				set("no_drop","ȥ�����Ѷ��ɣ����ӻ���Ⱦ����!\n");
				set("no_give","�ܹܷ���װ�����ɲ���������Ӵ��\n");
				set("no_get","�����ܹ�һҶ֪�﷢��װ�������ΰ�!\n");
  }
  setup();
}

