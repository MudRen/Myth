// Room: /d/4world/cuixiang.c
inherit ROOM;

void create ()
{
  set ("short", "����¥");
  set ("long", @LONG

������ǰ������������ķ��ݣ�������һ�������ĸ�����������
�۵Ķ��ǳ�������ζ�ļ��ȡ���˵��ʱ���ೢ���޲����ڣ�����
������֡�����ɿ��������������ˣ�Ҳ�ɴ��������·����Ĵ�
�¡���¥�������������ϯ����֪���Ǽ�����ϲ�¡�
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"north1",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiaoer" : 1,

]));
  set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));

  setup();
call_other("/obj/board/aolai_b", "???");
}
