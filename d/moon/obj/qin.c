// created 4/5/1997 by snowcat
#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit ITEM;

void create()
{
  set_name(HIB "������" NOR, ({ "wuxian qin"})); 
  set_weight(100000);
  set("long","һ�ܹ�ɫ����������١�\n");
  set("unit", "��");
  setup();
}

init ()
{
  add_action ("do_play", "play");
}

int do_play (string arg)
{
  object me = this_player();
  object qin = this_object();
  string *msgs = ({
    "$N�����ָ�������Ღ��һ�£��������������ˡ�\n",
    "$N�Ღ��һ�����ң���ɫ糺졣\n",
    "$N������˼��������һ������Ĭ������\n",
    "$N�����٣�����ס�������¡�\n",
    "$N����ص����٣���ɫ�����\n",
    "$NС�ĵص������ң��͵͵س���������\n",
    "$N�߳��ߵ���һ���������ĳ���\n",
  });

  if (arg != "wuxian qin")
  {
    tell_object (me,"�뵯ʲô�أ�\n");
    return 1;
  }

  message_vision (msgs[random(sizeof(msgs))],me);
  return 1;
}

