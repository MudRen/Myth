// Room: /d/4world/schoolhall.c
inherit ROOM;

void create ()
{
  set ("short", "��ݴ���");
  set ("long", @LONG

������Ƕ�����ݵĴ��������Ҹ�������̴ľ̫ʦ�Σ���Ϊ����׼
���ġ������Ƕ�����������λ����������ͨ�����ң�����ס������
�ݵ��Ӻͼ��ˡ�
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"school2",
  "east" : __DIR__"schoolin.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/dongfang" : 1,
]));

  set("no_fight",1);
  set("no_magic",1);
  setup();
}
