//����ɢѪ��
//by junhyun@SK
#include <ansi.h>

inherit ITEM;
int do_eat(string);
void create()
{
  set_name(HIC "����ɢѪ��" NOR, ({"qingxin wan", "wan"}));
  set_weight(50);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "ö");
    set("long", "һö����ɫ��Сҩ�衣\n");
    set("value",1000);
    set("no_sell", 1);
  }

  setup();
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
  object me = this_player();

  if (!id(arg))
    return notify_fail("��Ҫ��ʲô��\n");

        message_vision("$N����һö����ɢѪ��,��ʱ�о�һ������֮��͸�Ķ������泩�ޱȡ�\n", me);  

        me->set("bellicosity", 0);
        if ((int)me->query("bellicosity") < 0 ) { 
         me->set("bellicosity", 0);
                         }
  destruct(this_object());
  return 1;
}

