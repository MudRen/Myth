//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.7
//  /d/qujing/huangfeng/road1.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

���������Ǻܴ󣬼���С����������ʲô���Եĺܳ�����������
��Ĳ��Ǳ��ˣ����ǻƷ���ħ��
LONG);

  set("exits", ([
        "north"   : __DIR__"in2",
        "southup": __DIR__"dongkou",
      ]));
      set("objects",([
        __DIR__"npc/yaojing.c":2,
      ]));
  setup();
}
