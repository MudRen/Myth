// rewritten by snowcat on 4/11/1997
// Room: wuming2

inherit ROOM;

void create ()
{
  set ("short", "����С·");
  set ("long", @LONG

����С·�������ۣ�ǰ��ɿ���һ��С��ͺͺ��ɽ�����ܲ���һ��
������ֻ�к�ɫ��ɰʯ��

LONG);

  set("objects", ([
    __DIR__"npc/bajiao" : 1,
    ]));

  set("exits", ([
        "northeast" : __DIR__"wuming1",
        "southup"   : __DIR__"wuming3",
      ]));
  set("outdoors", "firemount");

  setup();
}
