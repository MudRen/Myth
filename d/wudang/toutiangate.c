//Room: toutiangate.c ͷ����
//lpg 19991005

inherit ROOM;

void create()
{
      set("short","ͷ����");
      set("long",@LONG
ֻ����ʯ������ͨ��ɽ�ۣ�һ��ʯ����д�š�ͷ���š��������֣�������
���䵱�������������㡣
LONG);
      set("exits",([ /* sizeof() == 1 */
          "north"    : __DIR__"chaotiangong",
          "southup"  : __DIR__"ertiangate",
      ]));
      set("objects", ([
		__DIR__"npc/wulei": 1,
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
