// created by angell 1/1/2001
// room: /d/qujing/huangfeng/yangchanglu6.c

inherit ROOM;

void create ()
{
  set ("short", "��С��");
  set ("long", @LONG

С·������У�һ·�ϵ�����ľ���죬�㻨������������һ��
��ɽ��ɽͷ���ƻ��ƣ������׷ף�ɽ������һ����Ժ��ֻ����
��������ּ���������翡�

LONG);

  set("exits", ([
        "south" : __DIR__"yangchanglu5",
        "northup" : __DIR__"shanmen",
      ]));
        set("outdoors", __DIR__);
       
  setup();
}
