//Room: wulaofeng.c ���Ϸ�
//lpg 19991005

inherit ROOM;

void create()
{
      set("short","���Ϸ�");
      set("long",@LONG
ֻ���������ͻأ�������ޱȣ����˶಻�ҷŵ��ڴ����ͷ羰��
LONG);
      set("exits",([ /* sizeof() == 1 */
          "northwest": __DIR__"langmeiyuan",
          "south"    : __DIR__"chaotiangong",
      ]));
      set("outdoors", "wudang");
      set("objects", ([
		__DIR__"npc/wulei": 1,
      ]));
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
