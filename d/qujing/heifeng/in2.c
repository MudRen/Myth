//Cracked by Roath
//  by happ@YSZZ 2000.4.5
//  /d/qujing/heifeng/in2.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

����������Ѩ���м䣬������ֵ���·�����Ծ�Ȼ��һ��������
[33m
                 ��  ��  ��  ɽ  ��  ��  ��
                 ��  ��  ��  ��  ��  ��  ��
[m
LONG);

  set("exits", ([
        "southup"  : __DIR__"cave",
        "north"  : __DIR__"in1",
        "west"   : __DIR__"in5",
        ]));
   set("objects",([
        __DIR__"npc/yaojing":2,
        ]));
  setup();
}
