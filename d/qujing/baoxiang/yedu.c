// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/yedu.c

inherit ROOM;

void create ()
{
  set ("short", "Ұ��");
  set ("long", @LONG

�����ǳ���������õ�Ұ�ɿڣ��ɿڳ���Ұ��ֲ��������
�����ź����Ƶ�������ɢ������ζ�ķ�һ��������Ѭ����ͷ��
���ᡣ

LONG);

  set("exits", ([
        "northwest"  : "/d/qujing/baigudong/yelu5",
        "southeast"  : __DIR__"bei1",
      ]));

  set("outdoors","/d/qujing/baoxiang");

  setup();
}

int valid_leave (object who, string dir)
{
  if (who->query("combat_exp") < 2000 ||
      random(2))
  {
    if (! who->query_temp("fainted_yedu"))
    {
      message_vision ("һ���ȷ紵����$N��ʱͷ�ؽ��ᡣ\n",who);
      who->set_temp("fainted_yedu",1);
      remove_call_out ("fall_down");
      call_out ("fall_down",1,who,environment(who));
      who->start_busy(1,1);
      return notify_fail("�����ס�����˼��£�����ͻȻһ��\n");
    }
  }
  who->set_temp("fainted_yedu",0);
  return 1;
}

void fall_down (object who, object where)
{
  who->move(where);
  who->unconcious();
}
