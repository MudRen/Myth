// Room: /u/mimi/zhuziguo/zhengyangmen.c    snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

�����ǽ���ʹ������ţ������ܷһ�ۿ�ȥ�����ûʡ���ǰ������
���������������ݣ�����ɭ�ϡ����������������������������Ʈ��

LONG);

  set("exits", ([ /* sizeof() == 2 */
    "south" : __DIR__"nstreet2",
    "north" : __DIR__"palace.c",
    "west" : __DIR__"wall3",
  ]));

  setup();
}

int valid_leave (object who, string dir)
{
  if (dir != "south" && !interactive(who))
    return 0;
  if (dir == "north")
  {
    if (who->query_temp("obstacle/wuji_seen_weishi_gate")==0)
    {
      remove_call_out("weishis_out");
      call_out("weishis_out",1,this_object(),who);
      message_vision ("������������������Χס$N�ʹ�\n",who);
    }
    return notify_fail ("��¥��һƬߺ���������ʹ����أ��Ͻ����룡��\n");
  }
  return ::valid_leave(who, dir);
}

void weishis_out (object where, object who)
{
  object shi = present("wei shi 4",where);
  object shi1;
  object shi2;

  if (shi)
    return;
  shi1 = new (__DIR__"npc/weishi");
  shi2 = new (__DIR__"npc/weishi");
  shi1->move(where); 
  shi2->move(where); 
  who->set_temp("obstacle/wuji_seen_weishi_gate",1);
}
