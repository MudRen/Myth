//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.5
//  /d/qujing/heifeng/cave.c

inherit ROOM;

void create ()
{
  set ("short", "��̨");
  set ("long", @LONG

��������ɽ����ߵĵط�������С��������������һ������Լ�
���ϸ�̨������ʩ����Ǻεȵ����硣��̨�������Ȼ������
�����������ǲ���˼�⡣
LONG);

  set("exits", ([
        "northdown"  : __DIR__"in2",
      ]));
  setup();
}
