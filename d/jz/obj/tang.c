//Cracked by Roath
 // �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("[1;31m���Ǻ�«[m", ({"bingtang hulu", "hulu"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "���ڵı��Ǻ�«��\n");
    set("unit", "��");
    set("value", 200);
    set("food_remaining", 5);
    set("food_supply", 35);
  }
}
