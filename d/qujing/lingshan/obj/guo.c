//Cracked by Roath
// beans.c ����

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("�ɹ�", ({"xian guo", "guo", "fruit"}));
  set_weight(800);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һֻ��÷��ϵ���ɽ�ɹ���\n");
    set("unit", "ֻ");
    set("value", 2000);
    set("food_remaining", 20);
    set("food_supply", 40);
  }
  set("no_get", "�ɹ�����ɽ֮����������ߣ�\n");
}
