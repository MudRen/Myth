// zhting.c

inherit ROOM;

void create ()
{
  set ("short", "���ƹ�");
  set ("long", @LONG

��������������ܵظ������¹��ĵز����������й������ϲ�û��
ʲô�����װ�Σ���ֵ������Ҹ����˰˸���ɫ��ʯ����ÿ�����а�
���Ű���ô������һ�����������ϰ����ľߣ�һ������СͲ��װ��
���������
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"walk6",
]));
  set("no_fight", 1);
  set("hell", 1);
  set("out_doors", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/dizhang" : 1,
]));

  setup();
}
