 // inside1.c

inherit ROOM;

void create ()
{
  set ("short", "�㳡");
  set ("long", @LONG

�ڹ���������֮����һ���޴�Ĺ㳡��һЩϺ��з�������������������
�����ա����м���������ź��ӽ����������ϱ���ƫ������̫�Ӻ͡�����
����ס�ĵط����򶫾͵������
LONG);

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/soldier1" : 1,
  __DIR__"npc/gonge" : 1,
//zhang men������ˣ���û�޸�֮ǰ����cut. by seng@2005-1-26
// 18    "/obj/zhangmen/sea": 1,
]));
  set("exits", ([ /* sizeof() == 4 */
  "eastup" : __DIR__"yujie1.c",
  "southeast" : __DIR__"girl1",
  "west" : __DIR__"gate",
  "northeast" : __DIR__"boy1",
]));
        set("water", 1);
        setup();
}

