// zhting.c

inherit ROOM;

void create ()
{
  set ("short", "˾��");
  set ("long", @LONG

���аڵ���һ���ŵļ��ӣ�������ű���İڷ���һ������
�顣����������ܵظ���˾��������ܿܿ������������������
��¼��ż������С�ٳ��룬����������ʲô��
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"roomout",
]));
  set("hell", 1);
  set("out_doors", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhutawei" : 1,
]));

  setup();
}
