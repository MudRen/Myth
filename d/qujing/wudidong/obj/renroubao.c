// ����� renroubao.c
// 9-16-97 pickle

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("�����", ({ "rou baozi","baozi","bao", "dumpling" }) );
  set_weight(80);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", 
"һ�������硢�����ڵĴ���ӡ�\n");
    set("unit", "��");
    set("value", 0);
    set("name_recognized", "�������");
    set("food_remaining", 4);
    set("food_supply", 100);
  }
}
