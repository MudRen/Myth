// Room: /u/mes/dong1.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

��������޵׶��ĵ����ˡ����ص������Ͽ���һ����߼�����Բ�ף�
�������ݷ���ˮ�������洫����������ʹ����״���������ǡ��ſ�վ
�����������Բ��С��ޣ������������λεĳ������粽����������
�ҡ�
LONG);

  set("exits", ([ /* sizeof() == 2 */
		 "north" : __DIR__"monk",
		 "south" : __DIR__"trap",
		 ]));
  set("outdoors", 0);
  set("objects", ([ /* sizeof() == 1 */
		   __DIR__"npc/ward" : 2,
		   ]));
  
  setup();
}
int valid_leave(object me, string dir)
{
  if(dir=="north" && objectp(present("ward", environment(me))))
    return notify_fail("���غ�����"+RANK_D->query_rude(me)+"�������ߣ�\n");
  return ::valid_leave(me, dir);
}
