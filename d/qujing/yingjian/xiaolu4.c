//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.3
//  /d/qujing/yingjian/xiaolu4.c

inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG

������ʫ��̾ɽ��֮����

        ��������ɽ�¸ǣ�����÷����ɰ�������Խ���ٸɲ�
        û�˹֣������������ٻ��ƾ���磬��Ǯ�������Ŀ죬
        �߲���������ڣ�����������������޹Ұ�����������
        �����˼�����ܡ�
LONG);

  set("exits", ([
        "west" : __DIR__"lakeside1",
        "east" : __DIR__"xiaolu2",
      ]));
  set("outdoors","yj");
  setup();

}
