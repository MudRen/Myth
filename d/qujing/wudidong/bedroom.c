// Room: /d/qujing/wudidong/bedroom.c

inherit ROOM;

void create()
{
  set("short", "����");
  set("long", @LONG

����С���Ҳ�����ﻹ�ɾ�һЩ������Ҳ��©ˮ�������ʣ�ļ���
���оͶ�����������ﴦ��һ�ų������񴲣��͹��ŵļ�����ɮ��
֮�⣬ʲô��û�С�Ҳ��֪�⼸�����г�ʲô���ա�
LONG
      );
  set("objects", ([ /* sizeof() == 1 */
		   __DIR__"npc/fangzhang-temple" : 1,
		   ]));
  set("outdoors", 0);
  set("exits", ([ /* sizeof() == 2 */
		 "southeast" : __DIR__"houyuan",
		 "west" : __DIR__"temple-qiandian",
		 ]));
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
