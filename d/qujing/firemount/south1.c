// rewritten by snowcat on 4/11/1997
// Room: wuming

inherit ROOM;

void create ()
{
  set ("short", "Сɽ����");
  set ("long", @LONG

ɽ������ʯ�������������ǵس���Щ�Ӳݣ���ʱ���м�ֻҰ�ô�ʯ
����Ծ����

LONG);

  set("objects", ([
       __DIR__"npc/bajiaoq" : 1,
      ]));

  set("exits", ([
        "southdown" : __DIR__"south2",
        "northup"   : __DIR__"wuming",
      ]));
  set("outdoors", "firemount");

  setup();
}
