// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "С����");
  set ("long", @LONG

С������һ��ƽ����ľ¥�͵꣬�����ſڹ��м������Ƶ�����
����д�š���С���ꡱ���ſڷ���һЩЬ�������һ�Ŵ�ͨ
�̣���������ص��ű��졣

LONG);

  set("exits", ([
        "west"    : __DIR__"jiedao8",
      ]));
  set("objects", ([
        __DIR__"npc/xiaoer"    : 1,
      ]));
  set("valid_startroom",1);
  set("sleep_room",1);
  set("if_bed",1);
  setup();
}

