//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.7
//  /d/qujing/village/road1.c

inherit ROOM;

void create ()
{
  set ("short", "���С·");
  set ("long", @LONG

һ·�Ϸ紵��Ҷ��·��ӡ��һЩ����Ľ�ӡ���������е��ر��
���ɣ���ȡ����������һ·Ͷ������������ɽ��ˮ����������Ұ��
�вݣ��㲻��̾Ϣ�����Ѹ�ٰ���

LONG);
  set("exits", ([
        "west"  : __DIR__"cunkou",
        "east"  : __DIR__"road2",
          ]));
  set("outdoors","cz");
  setup();
}
