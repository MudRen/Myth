inherit ROOM;

void create ()
{
  set ("short", "����С��");
  set ("long", @LONG

������һ�����͵�С·�������Ǳ���ɽ���ϱ�һ��С�ţ�����
���˵������κ��š����������¹���ˮ����Ҳ������������С�
��������ʹ������Ƥ�ޣ���������һЩ��֡�
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"naiheqiao",
  "west" : __DIR__"new-wayout",
]));
  set("hell", 1);
  set("objects", ([ /* sizeof() == 1 */
//  __DIR__"npc/shizhe" : 2,
]));

  setup();
}
