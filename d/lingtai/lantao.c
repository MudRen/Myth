// Room: some place in ��ţ����
// forrest.c

inherit ROOM;

void create()
{
  set ("short", "������");
  set ("long", @LONG

����֮�зǳ��İ�������ȫ����ɡ��ǵ���֦��ס�����²�
����֦��ÿ��һ�����ᷢ���ܴ����������ʱ�ɿ���������
��ĵ�ʿ��
LONG);
set("exits", ([ /* sizeof() == 4 */
"northdown" : __DIR__"baixi2",
"south" : __DIR__"lantao1",
"westup" : __DIR__"lantao2",

]));
set("objects", ([ /* sizeof() == 2 */
"/d/lingtai/obj/shuzhi": 1,
"/d/lingtai/npc/kancai": 2
]));
        set("no_clean_up", 0);
	set("outdoors", 1);
        setup();
        replace_program(ROOM);
}


