// created by angell 1/1/2001
// room: /d/qujing/huangfeng/shanlu3.c

inherit ROOM;

void create ()
{
  set ("short", "ɽ·");
  set ("long", @LONG

ɽ·���࣬�ƺ�����ֹ����������������֮ʱ��ͻȻ����ǰ
��ɽͷ���д����������Ӧ���Ǿ�ɽ��ˮ������·��������
����һ���ˡ�

LONG);

  set("exits", ([
        "southeast" : __DIR__"shanlu2",
        "westup"      : __DIR__"tulu1",
      ]));
        set("outdoors", __DIR__);
  setup();
}
