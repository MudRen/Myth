//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.3
//  /d/qujing/yingjian/xiaolu1.c

inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG

��ʱ���Ѿ��߽���ɽ���ش���ɽ����ɽ��ˮ����ˮ��һ·��
�������������ͱڣ�ɽ�͵����𸡣����˾����ޱ�׳�ۡ�

LONG);

  set("exits", ([
        "west" : __DIR__"xiaolu2",
        "northeast": "/d/qujing/shuangcha/enter",
      ]));
  set("outdoors","yj");
  setup();

}
