// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/zhaomen.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

����������֣���������һֻ���ӣ���������һ�����ģ����°�
���滨���ŭ�š�������͸�������ߣ��ŵ�����ɫ����ϸ��ʯ��
һ·��ƽ��

LONG);

  set("exits", ([
        "south"        : __DIR__"gongmen",
        "north"        : __DIR__"tan",
      ]));
  set("objects", ([
        __DIR__"npc/weishi"        : 2,
      ]));

  set("outdoors","/d/qujing/chechi");
  setup();
}


int valid_leave(object me, string dir)
{
  object shi = present ("wei shi", environment(me));
  if (dir == "north" && shi && living (shi))
    return notify_fail (shi->query("name")+"�ȵ������У�\n");
  return ::valid_leave(me, dir);
}
