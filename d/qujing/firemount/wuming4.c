// rewritten by snowcat on 4/11/1997
// Room: wuming4

inherit ROOM;

void create ()
{
  set ("short", "����С·");
  set ("long", @LONG

ǰ�����ɽ���ˣ���Լ�ɼ�ɽ�Ǳ���һ����ɽ��ɽ�ϰ������̣�����
һ����ء�

LONG);

  set("objects", ([
      __DIR__"npc/bajiaoq" : 1,
          ]));

  set("exits", ([
        "westup"    : __DIR__"wuming",
        "northdown" : __DIR__"wuming3",
      ]));
  set("outdoors", "firemount");

  setup();
}
