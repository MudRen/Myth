//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.5
//  /d/qujing/heifeng/road3.c

inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG

����ط�ȫ������һЩ�����������ĵ���ɫ���˷��䡣��һ������
����ӿ�����·��������������ơ�

LONG);

  set("exits", ([
        "south"  : __DIR__"road4",
        "northeast"  : __DIR__"road2",
      ]));
  set("outdoors","hf");
  setup();

}
