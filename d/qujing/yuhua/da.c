// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "�����Ӹ�");
  set ("long", @LONG

�����Ӹ��̵�յյ��һ�������Ϸ���������֮��Ĺ������⡣
����һ�߱�̫ʦ�Σ���ǰ��ʨ�޵�š��ϴ���ɼ�һС������
������ˮ������

LONG);

  set("exits", ([
        "west"   : __DIR__"dayuan",
        "east"   : __DIR__"er",
      ]));
  set("objects", ([
        __DIR__"npc/dianguan"  : 2,
        __DIR__"npc/prince1"  : 1,
      ]));

  setup();
}



