// Room: /u/mimi/zhuziguo/jinxiangting.c  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "����ͤ");
  set ("long", @LONG

ͤ������һ��ĵ�����������Ρ�ĵ��ԭ�������������ڼ�����֪��
�ʺ󰮻�����ĵ����Ϊ����֮�������Բ�ϧ���۲�����ֲ���ˣ���
��ν����������໶�����þ�����Ц���ˡ�

LONG);

  set("outdoors", __DIR__"");                   
  set("exits", ([ /* sizeof() == 3 */
    "west" : __DIR__"hzm.c",
    "north" : __DIR__"qiyutan.c",
    "east" : __DIR__"huilang.c",
  ]));
  set("objects", ([
      __DIR__"npc/queen" : 1,
      __DIR__"npc/girl" : 3,
  ]));

  setup();
}
