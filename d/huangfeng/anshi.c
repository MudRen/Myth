// created by angell 1/1/2001
// room: /d/qujing/huangfeng/anshi.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�������ʣ����겻ͨ����ֻ���������ӿ죬�������͡����￴
�������ǻƷ�ɽ��С������Ϣ�ĵط���ֻ�ж�����С��ͨס��
�档

LONG);

  set("exits", ([
        "east"         : __DIR__"dong6",
      ]));

  set("objects", ([
      ]));
  set("sleep_room",1);
  set("if_bed",1);
  setup();
}

