// Room: /u/mimi/zhuziguo/prince_shufang.c  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "�鷿");
  set ("long", @LONG

�������涼����ܣ�����������飬��඼�Ǿ�������ѧ������顣
��������һ�ź�ľ�������������̫ʦ���Ϲ���һ�Ű׻�Ƥ��һ˿
��ëҲû�С����Ż�Ƥ��̫��ȥ����Զ��ã�̫��Ϊ����Ϊ�Ժ���

LONG);

  set("exits", ([ /* sizeof() == 2 */
    "south" : __DIR__"garden",
    "southwest" : __DIR__"house.c",
  ]));

  setup();
}
