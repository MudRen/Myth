// created by angell 1/1/2001
// room: /d/qujing/huangfeng/yangchanglu5.c

inherit ROOM;

void create ()
{
  set ("short", "��С��");
  set ("long", @LONG

С·������У�ֻ���ּ����ѣ��ƺ����޾�ͷ��һ·�ϵ�����
ľ���죬�㻨������·��ûʲô���ˣ�������Ҳ����һֻ����
�����üӿ��˲��ӡ�

LONG);

  set("exits", ([
        "south" : __DIR__"yangchanglu4",
        "north" : __DIR__"yangchanglu6",
      ]));
        set("outdoors", __DIR__);
       
  setup();
}
