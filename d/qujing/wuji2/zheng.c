//    snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "���۱���");
  set ("long", @LONG

���۵����й��ŵ����ǹ����ն��Ϻ�֮�࣬��̬�Ȱ���������ά��
άФ��������������һЩ�������񣬷���վ������̬���졣������
�����ƣ����վ��ס�

LONG);

  set("objects", ([ /* sizeof() == 1 */
    __DIR__"npc/monk1" : 1,
  ]));
  set("exits", ([ /* sizeof() == 3 */
    "east" : __DIR__"eastroom.c",
    "south" : __DIR__"piandian.c",
    "west" : __DIR__"westroom.c",
  ]));

  setup();
}

