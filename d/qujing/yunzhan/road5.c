//Cracked by Roath

//  ����֮�� ������
//  by happ@YSZZ 2000.4.6
//  /d/qujing/yunzhan/road5.c

inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG

һ·�ϣ��컨�̲��𽥶���������Ȫˮ�ڶ��˵ı����������
��վ���ĸ質������ǰ�ߣ����Ҫ�߽���һƬɽ�֡�
LONG);

  set("exits", ([
        "east"  : __DIR__"road4",
        "westup"  : __DIR__"shanlu1",
      ]));
  set("outdoors","yz");
  setup();
}
