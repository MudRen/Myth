// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "�ֵ�");
  set ("long", @LONG

�ֵ�һ�������������䣬���̵��գ���������һЩ�޾����
�Ĺ��ˣ��Լ�����ɢɢ����Ƽ��ݵļ������������ڵ���ؤ��
�����е�Ҳ��̶á�

LONG);

  set("exits", ([
        "north"    : __DIR__"jiedao7",
        "west"    : __DIR__"jiedao13",
        "south"    : __DIR__"xiang",
      ]));
  set("objects", ([
        __DIR__"npc/people" : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

