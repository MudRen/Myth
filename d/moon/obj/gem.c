//Cracked by Roath

#include <ansi.h>
inherit ITEM;

string *names = ({
HIW"��ʯ"NOR,
HIG"��ĸ��"NOR,
HIR"�챦ʯ"NOR,
HIB"����ʯ"NOR,
HIG"è����"NOR,
HIW"ˮ��"NOR,
HIG"���"NOR,
HIW"����"NOR,
HIG"���"NOR,
HIW"ɺ��"NOR,
HIW"����"NOR,
HIC"���"NOR,
YEL"����"NOR,
MAG"�Ͼ�"NOR,
HIR"��Ѫʯ"NOR,
HIW"������"NOR,
});

void create()
{
  set_name("��ɫ��ʯ", ({"bao shi", "gem",}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("value", 200000);
  }
}

void init()
{
  if (query("name")=="��ɫ��ʯ")
    set_name(names[random(sizeof(names))], ({"bao shi","gem"}));
//  ::init();
}
