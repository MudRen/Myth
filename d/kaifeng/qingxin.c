//Cracked by Roath
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "���Ĺ�");
  set ("long", @LONG

���Ĺ�����Ÿ����滨�����ɢ�������˵�ˮ�����㡣���������Һ�
ɫ�ĵ�̺������ǽ�Ϲ������С������ͭ����ǽ������д��һ����ɫ
���֡��塱��

LONG);

  set("exits", ([
        "east" : __DIR__"ningxin",
      ]));
  set("no_fight", 1);
  set("no_magic", 1);
  setup();
}

void init ()
{
  add_action ("do_qing","qing");
}

int do_qing ()
{
  object who = this_player();
//  int i = (60 - who->query_kar())*3;
//  int i = (45 - random(who->query_kar()))*2
  int i = (60 - who->query_kar())*2
          -who->query_temp("kaifeng_donate_silver");

  if (i<2) i=2;

  if (who->is_busy())
    return notify_fail("��Ķ�����û����ɣ����ܶ���\n");

  message_vision ("$N�����ص���һ�����塱�֣������������¡�\n",who);
  who->start_busy (i,i);

  call_out ("finishing",i,who);
  return 1;
}

void finishing (object who)
{
  who->interrupt_me();
  who->set_temp("kaifeng_qingxin",1);
  message_vision ("$N������³�һ����������վ��������\n",who);
}
