// sanjie shanlin8.c

inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
        
����һƬï�ܵ����֣����Ĵ����м���¥�ߣ�����Ҷ��ï�ܣ�
���ⶼ���ڱ��ˣ��������氵�����ա��������������أ���
�߹����������ߣ�����һ�㶼�����ˡ�ɽ���и�ɽ��(cave)��
LONG );
	set("item_desc", ([
  	"cave" : "����ʬ�ء���ʬ���صأ��������\n",
	]));
        set("outdoors", 1);
        set("exits", ([
              "north" : __DIR__"shanlin7",
              "enter" : __DIR__"cangshilang1",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
