// rewritten by snowcat on 4/11/1997
// Room: wuming3

inherit ROOM;

void create ()
{
  set ("short", "����С·");
  set ("long", @LONG

����С·�������ۣ�ǰ��ɿ���һ��С��ͺͺ��ɽ�����ܲ���һ��
������ֻ�к�ɫ��ɰʯ��

LONG);

  set("objects", ([
      __DIR__"npc/bajiaob" : 1,
     ]));

  set("exits", ([
         "northdown" : __DIR__"wuming2",
         "southup"   : __DIR__"wuming4",
      ]));
  set("outdoors", "firemount");

  setup();
}
