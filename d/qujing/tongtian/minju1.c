// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "���");
  set ("long", @LONG

����һ�������˼ң����������򵥣�����һľ����ľ�Σ���
����һ�Ŵ�������ı�������������롣������һ��ľ���ӣ�
���⴫�����С�

LONG);

  set("exits", ([
        "out"   : __DIR__"chen1",
      ]));
  set("objects", ([
        __DIR__"npc/people"  : random(2)+3,
        __DIR__"npc/kid"  : random(2),
      ]));

  setup();
}



