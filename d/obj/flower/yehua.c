#include <ansi.h>

inherit F_SAVE;
inherit COMBINED_ITEM;

void create()
{
  set_name("Ұ��", ({ "flower","yehua","hua" }) );
  set("unit","��");
  set("base_weight",10);
  set("long","һ���������˵�СҰ����ɢ����һ˿���������㡣\n");
  set("base_unit","��");
  set("material", "flower");
  set_amount(1+random(3));
  setup();
}


