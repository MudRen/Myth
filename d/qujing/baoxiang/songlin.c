// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/dongwai.c

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

ɽ·��᫣����ִԴ����ʸ��ƣ�������һ�����𣬰ش����ࡣ��
���ڳ���Ұ��ɽ�������İ������������������·С����֪��ͨ
��δ���

LONG);

  set("exits", ([
        "north"      : __DIR__"shan5",
        "southeast"  : __DIR__"dongwai",
      ]));
  set("outdoors","/d/qujing/baoxiang");

  setup();
}

