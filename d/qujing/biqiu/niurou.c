// created by snowcat 11/21/1997

inherit ROOM;

void create ()
{
  set ("short", "ţ���");
  set ("long", @LONG

ţ������������ڣ�һ��ţ����ζ�˱Ƕ����������������ź�
���Ű�������ÿ�������Ϸ���һ����ţ����������ʳ��������
���ܡ�

LONG);

  set("exits", ([
        "west"    : __DIR__"jie10",
      ]));
  set("objects", ([
        __DIR__"npc/kusikusi"    : 1,
      ]));
  setup();
}

