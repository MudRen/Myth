// Room: /u/mimi/zhuziguo/huilang2.c  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "�������");
  set ("long", @LONG

��������ɰ���ʯ��ɣ�������㣬Ī��ά��άФ������֮�⻨
���ƽ������ⰻȻ�������Ƿ���������԰������ǰ����������ĵ�
��������԰����ʱ�����˻����ȥ������˼Ľ�ǵ��ˣ����������ͣ�
�����˽���԰�رա�������������޹���

LONG);

  set("outdoors", __DIR__"");                   
  set("exits", ([ /* sizeof() == 3 */
    "enter" : __DIR__"yuhua",
    "south" : __DIR__"huilang",
    "west" : __DIR__"ziyun.c",
  ]));
  set("objects", ([
     __DIR__"npc/girl" : 1,
  ]));

  setup();
}
