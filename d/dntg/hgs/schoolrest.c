// Room: /d/4world/schoolrest.c
inherit ROOM;

void create()
{
  set ("short", "�ͷ�");
  set ("long", @LONG

������һ�䲼�õ��൱���µ��᷿���Ӵ��ӿ��Կ������ߵ��쾮��
ͥ԰�и�ʽ�������滨��ݡ��᷿���м��Ŵ�ľ����������ס�ģ�
���߾ͻص��쾮��
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"schoolin",
]));
  set("no_fight", 1);
        set("sleep_room",1);
        set("if_bed",1);

  setup();
}
