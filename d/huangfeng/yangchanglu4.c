// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/yangchanglu4.c

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
        "southwest" : __DIR__"yangchanglu3",
        "north" : __DIR__"yangchanglu5",
      ]));
        set("outdoors", __DIR__);
       
  setup();
}
