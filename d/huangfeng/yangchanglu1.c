// created by angell 1/1/2001
// room: /d/qujing/huangfeng/yangchanglu1.c

inherit ROOM;

void create ()
{
  set ("short", "��С·");
  set ("long", @LONG

С·������У�ֻ���ּ����ѣ��ƺ����޾�ͷ��һ·�ϵ�����
ľ���죬�㻨������·��ûʲô���ˣ�������Ҳ����һֻ����
�����üӿ��˲��ӡ�

LONG);

  set("exits", ([
        "north" : __DIR__"huangfeng4",
        "southeast" : __DIR__"yangchanglu2",
		"southwest" : __DIR__"songshulin",
      ]));
        set("outdoors", __DIR__);
       
  setup();
}
