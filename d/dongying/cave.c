//cave.c
inherit ROOM;

void create()
{
  set("short","�Ҷ�");
  set("long",
        "�������Ҷ��ڲ��������������Ž�׵�����ʯ��\n"
      );
  set("exits",([
      "out" : __DIR__"house",
     ]));
  set("no_clean_up", 0);
  set("objects",([
		__DIR__"npc/jianxin": 1,
       ]));
 setup();
 replace_program(ROOM);
}

