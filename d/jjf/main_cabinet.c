// Room: /d/jjf/main_cabinet.c

inherit ROOM;

void create ()
{
  set ("short", "��˽��");
  set ("long", @LONG
�ؽ����Ǹ�Т�ӣ����Լ���ĸ���չ˵���΢��������˽������
������Ȼ���أ�����Ȼ���������ѹ�һ����˼��ӭ�ŵ�һ��ɽˮ��
���ǲ��ף����������ֱʡ�
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"stone_road2",
  "west" : __DIR__"bingqi_room",
  "east" : __DIR__"main_shufang",
]));

  setup();
}
