// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "���");
  set ("long", @LONG

�˻��˼�Ҳ�ǳ��գ����������������������Ϊ������������
һ��������������ž�����ͭ��ߣ��ݱ��м��ѿ��Σ��м�
��һС�輸��

LONG);

  set("exits", ([
        "out"   : __DIR__"chen2",
      ]));
  set("objects", ([
        __DIR__"npc/people"  : random(3)+3,
        __DIR__"npc/kid"  : random(2),
      ]));

  setup();
}



