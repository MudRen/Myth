//Cracked by Roath
// Room: /d/nanhai/chaoyindong.c
inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

������Ϻ�����ɽ���������ȿ���Ѵ�ȴ󱯹�������������
��֮���ڡ�ֻ��������������������̨�ϣ�΢���ƿڣ����ݴ�
��������������������������䣬�������ϡ�����������Χ�ƣ�
�����ͷס����ǣ���������ǧ���£������庭�����졣
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"guangchang.c",
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/shizhe" : 1,
  __DIR__"npc/guanyin" : 1,
//zhang men������ˣ���û�޸�֮ǰ����cut. by seng@2005-1-26
// 22    "/obj/zhangmen/nanhai" : 1, 
]));
  set("light_up", 1);

  setup();
}
