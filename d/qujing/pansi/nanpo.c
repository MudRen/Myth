// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

���б�գ�������Ұ�ݴ�����ʯ�����������������ѬѬȻȻ
����ͷ��Ŀѣ���紵���������е�����Ҳҡ�

LONG);

  set("exits", ([
        "northeast"    : __DIR__"qiaolin5",
      ]));
  set("objects", ([
        __DIR__"npc/woman"    : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

