// rewritten by snowcat on 4/11/1997
// Room: wuming

inherit ROOM;

void create ()
{
  set ("short", "����Сɽ");
  set ("long", @LONG

ɽ����ʲôҲû�У�ɽ����´��һ����ʯ�������Լ�����ֻҰ�á�
������ȥ���Ǵ���ɽ�ˡ����汻��𿾵�һƬͨ�졣

LONG);

  set("objects", ([
       __DIR__"npc/bajiaoq" : 1,
     ]));

  set("exits", ([
        "southdown" : __DIR__"south1",
        "eastdown"  : __DIR__"wuming4",
    ]));
  set("outdoors", "firemount");

  setup();
}
