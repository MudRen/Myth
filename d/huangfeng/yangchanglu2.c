// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/yangchanglu2.c

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
        "northwest" : __DIR__"yangchanglu1",
        "northeast" : __DIR__"yangchanglu3",
      ]));
        set("outdoors", __DIR__);
       
  setup();
}
