// ������� by Calvin

#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
  set_name(MAG"�ϱ���"NOR, ({ "zibing kui", "tou kui", "kui" }) );
  set_weight(2200);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long","��������ϲ������һ�����ص�ñ��,���Ӳ����Ǻ����ۡ�\n");
                set("no_get", 1);
                set("no_give", 1);
                set("no_put", 1);
                set("no_drop", 1);
set("value", 6000);
                set("no_sell", "���ֺ���������ɲ���������������!\n");
    set("material", "cloth");
                set("armor_prop/armor", 60);
    set("armor_prop/personality", 5);
  }
  setup();
}
