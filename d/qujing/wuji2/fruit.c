// Room: /d/changan/shuju  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "�ļ�ˮ����");
  set ("long", @LONG

���ˮ���������Ȼ���󣬵���ɫ�Ϲ���ȫ������ʱ��Ϲ�ÿ����
�����������������ʡ���ɫˮ���ʺ���̣�ʮ�����ˡ�

LONG);

  set("objects", ([ /* sizeof() == 1 */
    __DIR__"npc/vender.c" : 1,
  ]));
  set("exits", ([ /* sizeof() == 1 */
    "north" : __DIR__"estreet.c",
  ]));

  setup();
}

