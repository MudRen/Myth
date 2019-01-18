// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

���Ķ����������ڣ������ϳ��Ŵֳ������٣���ͷ�Ϲ�������
���ڲ������ͻ�ѣ�֨֨��ð���̣����������������ĵ�����
��ƽƽ����������һ��һ��ʯ�塣

LONG);

  set("exits", ([
        "north"   : __DIR__"dongnei2",
        "northeast"   : __DIR__"dongnei3",
      ]));
  set("objects", ([
        __DIR__"npc/yao"   : 2,
        __DIR__"obj/rou"   : 3,
      ]));

  setup();
}

void init ()
{
  add_action ("do_dig","dig");
}

int do_dig (string arg)
{
  object who = this_player ();
  object where = this_object ();
  object sha;

  if (who->is_fighting())
    return notify_fail ("������ս��֮�У�����ھ��ɰ��\n");

  if (who->is_busy())
    return notify_fail ("������æ���ء�\n");

//  if (where->query("has_digged"))
//  {
//    message_vision ("$N�ڶ��ǵ����к��Ұ�����һ����ʲôҲû���ҵ���\n",who);  
//    return 1;
//  }

  if (random(10))
  {
    message_vision ("$N�ڶ��ǵ�������ϸ�ذ�����һ����û���ҵ�������\n",who);  
    who->start_busy(2);
  }
  else
  {
    sha = new (__DIR__"obj/jindan");
    message_vision ("$N�ڶ��ǵ�������˫��һ�ǣ�����һ��������\n",who);  
    message_vision ("$N��ֽ���ҿ���ȡ��$n���ڻ��\n",who,sha);
    sha->move(who);  
    where->set("has_digged",1);
  }
  return 1;
}

