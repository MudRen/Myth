// ����С· by Calvin


inherit ROOM;

void create ()
{
  set ("short", "����С·");
  set ("long", @LONG

�����ɽ��Ǵ�˵�е��ɽ�,��������᫵�ɽ·��ôҲ
���˲��������ǵĵط����ж�ô��������

LONG);

  set("exits", ([
        "west"  : __DIR__"lu4",
        "east"  : __DIR__"lu8",
      ]));

  set("outdoors","1");

  setup();
}

int valid_leave (object who, string dir)
{
  if (who->query("combat_exp") < 200000 ||
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

