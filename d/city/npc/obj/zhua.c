#include <weapon.h>

inherit DAGGER;

void create()
{
  set_name("����צ", ({ "tie zhua", "zhua", "dagger" }) );
  init_dagger(25);
  set("unit", "��");
  set_weight(300);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 280);
    set("material", "tron");

  }
  set("wield_msg","$N����$n�������\n");
  set("no_sell",1);
				set("no_drop","ȥ�����Ѷ��ɣ����ӻ���Ⱦ����!\n");
				set("no_give","�ܹܷ���װ�����ɲ���������Ӵ��\n");
				set("no_get","�����ܹ�һҶ֪�﷢��װ�������ΰ�!\n");
  setup();
}

