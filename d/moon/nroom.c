//Cracked by Roath
// Room: /moon/nroom.c
//cglaem...12/13/96.

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

�������������һ����˼��������ӭ��Ϯ�����������ȴֻ�м�ֻ��
�Ӻ�һ�Ų輸��һɫ�������ƣ����ϵ���ɫ��ʯ��ש������һ������ĸ�
�������׵�ǽ�Ϲ�  ��һ��ˮī��������һյ��¯���������϶����̣���
֮�����Ĺǽ��塣
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/magu.c" : 1,
]));
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"xiaoyuan",
]));

  setup();
}






