// created by snowcat.c 4/4/1997
// room: /d/nuerguo/changshi.c

inherit ROOM;

void create ()
{
  set ("short", "һ����");
  set ("long", @LONG

������һ��Ͽ�ȵף������Ǹ߸ߵ�ɽ�£��¶��������ƣ���
���ղ���������ǰ����һ����ߵ���ʯ���Ͽ����������֣�
��γʯ����ʯӫӫ�ط��ź�����ϼ�⡣

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"changbie",
  "northwest" : "/d/qujing/dudi/shanlu9",
]));

  setup();
}

int valid_leave (object me, string dir)
{
  object queen;

/*
  if (dir=="northwest" && 
      me->query("obstacle/nuerguo") != "done")
  {
    queen = new (__DIR__"npc/queen");
    queen->stop_access (me);
    //destruct (queen);
    return notify_fail("�����ӹ���ȥ��\n");
  }
*/
  return 1;
}
